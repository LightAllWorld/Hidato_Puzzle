#pragma once
#include <iostream>
#include "Solver.h"

using namespace std;

Solver ::Solver()
{
	orderOfMat = 0;
	indexOfMiddle = 0;
	total = 0;
	finish = false;
}

Solver ::~Solver()
{
	for (int i = 0; i < sizeY; i++) 
		delete[] matrix[i];

	delete[] matrix;
}

void Solver ::input(ifstream &file)
{
	//매트릭스 파일을 읽어서 size값을 받아옴
	//size 값으로 matrix를 2차배열로 동적할당
	//값들을 matrix로 저장해줌
	//0 값이 아니면 total++ 해줌.
	//읽어오는 중 0, -1 값이 아닌 값이면 middle에 push해줌
	//middle값을 오름차순으로 정렬해줌

	file >> sizeX >> sizeY;
	matrix = new int*[sizeY];
	for (int i = 0; i < sizeY; i++) {
		matrix[i] = new int[sizeX];
	}
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			file >> matrix[i][j];
			if (matrix[i][j] != 0) {
				total++;
				if (matrix[i][j] != -1) {
					middle.push_back(matrix[i][j]);
					if (matrix[i][j] == 1) {
						startX = j;
						startY = i;
					}
				}
			}
		}
	}
	sort(middle.begin(), middle.end());
}

void Solver ::output(ofstream &file)
{
	//텍스트파일로 보기좋게 출력.
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (matrix[i][j] == 0) {
				file << "00 ";
				continue;
			}
			else if (matrix[i][j] < 10 && matrix[i][j] > 0) {
				file << " " << matrix[i][j] << " ";
				continue;
			}
			file << matrix[i][j] << " ";
		}
		file << endl;
	}

}

void Solver ::floodFill(int Y, int X)
{
	/*
	1.  finish가 1인지 검사.(끝났는지)
	2.  좌표가 0 미만인지 검사(안되는지)
	3-1 좌표값이 -1(벽)이 아닌지 검사( 벽이거나 중간값)
	3-2 현재 노드값이 0이 아니면(벽이아니면),
	orderOfMat+1 값이 현재순서의 middle값인지 검사
	middle값일경우 middle값이라는 표시
	5.  orderOfMat++, matrix[Y][X] = orderOfMat  (-1을 현재값으로 수정)
	6.  다시 floodFill 주르륵
	7.  finish가 1이면 리턴
	8.  orderOfMat--, matrix[Y][X] = -1( middle값이면 그값으로 다시)
	*/
	bool midf = false;
	int mid;

	if (finish) {					//1.  finish가 1인지 검사.(끝났는지)
		return;
	}

	if ( Y<0 || X <0 || Y == sizeY || X == sizeX) {           //2.  좌표가 0 미만인지 검사(안되는지)
		return;
	}
	if (matrix[Y][X] == 0) {       //3
		return;
	}


	if (matrix[Y][X] == -1) {
		if (orderOfMat == middle.at(indexOfMiddle) - 1) {
			return;
		}
	}
	else if (matrix[Y][X] == middle.at(indexOfMiddle)) {
		if (orderOfMat != middle.at(indexOfMiddle) - 1) {
			return;
		}
		midf = true;
		mid = middle.at(indexOfMiddle);
		indexOfMiddle++;
	}
	else {
		return;
	}



	orderOfMat++;
	if (!midf) {
		matrix[Y][X] = orderOfMat;
	}



	if (orderOfMat == total) {        //현재값이 최대숫자면 끝냄
		finish = true;
		return;
	}

	floodFill(Y - 1, X);              // 6
	floodFill(Y - 1, X + 1);
	floodFill(Y, X + 1);
	floodFill(Y + 1, X + 1);
	floodFill(Y + 1, X);
	floodFill(Y + 1, X - 1);
	floodFill(Y, X - 1);
	floodFill(Y - 1, X - 1);

	if (finish) {                     // 7
		return;
	}

	orderOfMat--;                     // 8
	if (midf) {
		indexOfMiddle--;
		matrix[Y][X] = mid;
		return;
	}

	matrix[Y][X] = -1;

}

void Solver ::solve()
{

	floodFill(startY, startX);
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (matrix[i][j] == 0) {
				cout << "00 ";
				continue;
			}
			else if (matrix[i][j] < 10 && matrix[i][j] > 0) {
				cout << " " << matrix[i][j] << " ";
				continue;
			}
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
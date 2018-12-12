#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Solver {
private:
	int startX, startY;   // ��������Ʈ
	vector<int> middle;   // �߰��� �迭
	int orderOfMat;		  // ������ǥ�� ��
	int indexOfMiddle;	  // ���� �߰��� ����
	int **matrix;		  // ����
	int sizeX, sizeY;	  // ������ ������
	int total;			  // ������ -1���� �ƴ� �� ������ ����(= ������ ����)
	bool finish;		  // floodfill���� finish�� true�� �Ǹ� ����

public:
	Solver() {
		orderOfMat = 0;
		indexOfMiddle = 0;
		total = 0;
		finish = false;
	}
	~Solver() {
		for (int i = 0; i < sizeY; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}


	void input(ifstream &file) {
		//��Ʈ���� ������ �о size���� �޾ƿ�
		//size ������ matrix�� 2���迭�� �����Ҵ�
		//������ matrix�� ��������
		//-1 ���� �ƴϸ� total++ ����.
		//�о����� �� 0, -1 ���� �ƴ� ���̸� middle�� push����
		//middle���� ������������ ��������

		file >> sizeY >> sizeX;
		matrix = new int*[sizeY];
		for (int i = 0; i < sizeY; i++) {
			matrix[i] = new int[sizeX];
		}
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				file >> matrix[i][j];
				if (matrix[i][j] != -1) {
					total++;
					if (matrix[i][j] != 0) {
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


	void output(ofstream &file) {
		//�ؽ�Ʈ���Ϸ� �������� ����.
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



	void floodFill(int Y, int X) {
		/*
		1.  finish�� 1���� �˻�.(��������)
		2.  ��ǥ�� 0 �̸����� �˻�(�ȵǴ���)
		3-1 ��ǥ���� 0�� �ƴ��� �˻�( ���̰ų� �߰���)
		3-2 ���� ���尪�� -1�� �ƴϸ�,
			orderOfMat+1 ���� ���������� middle������ �˻�
			middle���ϰ��� middle���̶��� ǥ��
		5.  orderOfMat++, matrix[Y][X] = orderOfMat  (0�� ���簪���� ����)
		6.  �ٽ� floodFill �ָ���
		7.  finish�� 1�̸� ����
		8.  orderOfMat--, matrix[Y][X] = 0( middle���̸� �װ����� �ٽ�)
		*/
		bool midf = false;
		int mid;

		if (finish) {					//1.  finish�� 1���� �˻�.(��������)
			return;
		}

		if (Y < 0 || X < 0 || Y == sizeY || X == sizeX) {           //2.  ��ǥ�� 0 �̸����� �˻�(�ȵǴ���)
			return;
		}
		if (matrix[Y][X] == -1) {       //3
			return;
		}


		if (matrix[Y][X] == 0) {
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



		if (orderOfMat == total) {        //���簪�� �ִ����ڸ� ����
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

		matrix[Y][X] = 0;

	}


	void solve() {

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

};

#pragma once
#include <vector>
#include <fstream>
using namespace std;

class Solver {
private:
	int startX, startY;   // 시작포인트
	vector<int> middle;   // 중간값 배열
	int orderOfMat;		  // 현재좌표의 값
	int indexOfMiddle;	  // 현재 중간값 순서
	int **matrix;		  // 퍼즐
	int sizeX, sizeY;	  // 퍼즐의 사이즈
	int total;			  // 퍼즐의 -1값이 아닌 총 숫자의 갯수(= 마지막 숫자)
	bool finish;		  // floodfill에서 finish가 true가 되면 리턴

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
	void input(fstream &file) {
		//매트릭스 파일을 읽어서 size값을 받아옴
		//size 값으로 matrix를 2차배열로 동적할당
		//값들을 matrix로 저장해줌
		//-1 값이 아니면 total++ 해줌.
		//읽어오는 중 0, -1 값이 아닌 값이면 middle에 push해줌
		//middle값을 오름차순으로 정렬해줌
	}
	void output(fstream &file) {
		//텍스트파일로 보기좋게 출력.
	}
	bool search(int Y, int X, int middle) {	
		// 주변에 현재 순서의 중간값이 있는지 검색
		// 있으면 true, 없으면 false 리턴
	}
	void floodFill(int Y, int X) {
		/*
		
		
		*/
	}
	void solve() {
		// main에서 사용해줄 함수.
		// floodFill을 사용해서 퍼즐을 품.
	}

	
		
};
#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
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
	Solver();
	~Solver();
	void input(ifstream &file);
	void output(ofstream &file);
	void floodFill(int Y, int X);
	void solve();

};
/*
4 6
-1 1 -1 -1
14 0 3 -1
0 -1 0 6
0 -1 5 0
0 0 0 -1
10 -1 -1 -1
4 6
0 1 0 0
14 -1 3 0
-1 0 -1 6
-1 0 5 -1
-1 -1 -1 0
10 0 0 0
*/
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

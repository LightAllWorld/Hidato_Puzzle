#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Generator
{
public:
	void run();
	Generator(int row, int col, std::fstream& fop):
	row(row),
	col(col),
	side {{ 0,-1 }, { 1,-1 }, { 1,0 }, { 1,1 },
				{ 0,1 }, { -1,1 }, { -1,0 }, { -1,-1 }}
	{
		this->map = new int*[row];
		for( int i =0; i < row; i++ )
			this->map[i] = new int[col];

		std::cout<<row<<' '<<col<<'\n';
		this->roomsize = 0;
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				fop>>this->map[i][j];
				if(this->map[i][j] == 1){
					roomsize++;
				}
			}
		}
		std::cout << "Before Delete Matrix" << std::endl;
		for(int i = 0; i < this->row; i++){
			for(int j = 0; j < this->col; j++){
				std::cout << map[i][j] << " ";
			}
			std::cout << std::endl;
		}
		this->order = 1;
		this->thirteen = 0;
		this->isSearch = 0;

		Setting();
	};
	int Search(int point_x, int point_y);
	void Save_matrix();
	~Generator()
	{
		for(int i = 0; i < this->row; i++)
			delete[] map[i];
		delete map;

		for(int i = 0; i < this->row; i++)
			delete[] marked[i];
		delete marked;
	};
private:
	void Setting();					// marked 배열 생성.
	std::vector<int> path;	// path를 저장해놓는 vector
	int row, col;
	int** map;
	int** marked;
	int start_x, start_y;
	int order;					// 순서를 매겨주는 변수.
	int side[8][2];
	int roomsize;			// 방의크기(=1의 개수)
	int thirteen;			// order사이에 13이상 차이가 안나도록 체크해주는 변수. 
	int isSearch;			// path를 찾았는지 알려주는 변수.
};

#endif

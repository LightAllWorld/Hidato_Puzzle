#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

class Generator
{
public:
	void run();
	bool Is_Marked(int x_pos, int y_pos, int side_idx);
	bool Is_Empty();
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
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				fop>>this->map[i][j];
			}
		}

		this->order = 1;
		this->roomsize = 0;
		Setting();
	};
	void Select_start();
	void get_RoomSize();
	int Search(int point_x, int point_y);
	void Print_path();
	void Delete_items();
	void Save_matrix();
	void Display();
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
	int roomsize;
};

#endif

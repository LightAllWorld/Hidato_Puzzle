#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H
#include <iostream>
#include <fstream>
#include <vector>

class Generator
{
public:
	void run();
	bool Is_Marked(int x_pos, int y_pos);
	bool Is_Empty();
	Generator(int row, int col, std::fstream& fop):
	row(row),
	col(col)
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
		Setting();
	};
	void Select_start();
	void Search();
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
	void Setting();
	std::vector<int> path;
	int row, col;
	int** map;
	int** marked;
	int start_row, start_col;
};

#endif
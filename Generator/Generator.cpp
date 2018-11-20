#include "Generator.h"
#include <iostream>

void Generator::run()
{
	Select_start();
	Search();
	Delete_items();
	Save_matrix();
	~Generator();
}


void Generator::Setting()
{
	this->marked = new int*[this->row];

	for( int i = 0; i < this->row; i++)
		this->marked[i] = new int[this->col];
}

bool Generator::Is_Marked(int x_pos, int y_pos)
{
	/*
		if coordinate is already marked:
			1) Push coordinate to stack.
			2) return true
		else:
			return false
	*/
}

// Set start x, y position
// start_row : start_row is a value about starting point's x value.
// start_col : start_col is a value about starting point's y value.
void Select_start();
{
	/*
		1. Set starting point.
		2. Push the point to stack.
	*/
}

// This function is a Searching functuon using back tracking.
void Search()
{

	/*
	1. Find adjacent position that has to unmakred.
	2. if unexist next position
		1) unmarked recent position.
		2) return lastest position. (back tracking)
	3. if exist next position.
		1) marking this position.
		2) Push position to path and change value from matrix.
		3) move next position
		4) call Search function.
	4. if all path is full fill,
		escape this function.
	*/

}

// Print path from stack's whole items.
void Print_path()
{
	for(int i = 0; i < this->path.size(); i++ )
		std::cout<<path[i]<<' ';
	std:;cout<<'\n';
}

// This function deletes the item of path.
void Delete_items()
{
	/*
		1. Selcet item that changes value to -1 from path and matrix.
		2. if a
	*/
}

// This function saves result matrix.
// file name is "input_data.txt"
void Save_matrix()
{
	/*
	write matrix line by line.
	*/
}

// Test function
/*
void Generator::Display()
{
	std::cout<<this->row<<' '<<this->col<<'\n';
	for(int i = 0; i < this->row; i++)
	{
		for(int j = 0 ; j < this->col; j++)
			std::cout<<this->map[i][j]<<' ';
		std::cout<<'\n';
	}
}
*/

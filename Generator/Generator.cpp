#include "Generator.h"

void Generator::run()
{
	Select_start();
	//get_RoomSize();
	//std::cout << this->roomsize << std::endl;
	if(Search(start_x, start_y) == 0)
	{
		std::cout<<"False Generator run.\n";
		std::exit(1);
	}
	Delete_items();
	Save_matrix();
	//~Generator();
}

void Generator::Setting()
{
	this->marked = new int*[this->row];

	for( int i = 0; i < this->row; i++)
		this->marked[i] = new int[this->col];

}

// Set start x, y position
// start_row : start_row is a value about starting point's x value.
// start_col : start_col is a value about starting point's y value.
void Generator::Select_start()
{
	/*
		1. Set starting point.
		2. Push the point to stack.
	*/
	int flag = 0;
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			if(map[i][j]==1){
				start_y = i;
				start_x = j;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	std::cout << start_y << " " << start_x;
	this->map[start_y][start_x] = 1;
	this->marked[start_y][start_x] = 1;
}

void Generator::get_RoomSize(){
	for(int i = 0; i < this->row; i++)
		for(int j = 0; j < this->col; j++)
			if(this->map[i][j] == 1)
				this->roomsize++;
}


// This function is a Searching functuon using back tracking.
int Generator::Search(int point_x, int point_y)
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
  // startingPointx = 0~n
  // startingPointy = 0~m
	int new_x, new_y;

  if ( this->order == this->roomsize )
    return 1;

  for(int side_idx = 0; side_idx < 8; side_idx++){
		//Is_Marked(new_x, new_y, side_idx);
		//new_x = this->row + this->side[side_idx][0];
		//new_y = this->col + this->side[side_idx][1];
		new_x = point_x + this->side[side_idx][0];
		new_y = point_y + this->side[side_idx][1];
		if ( new_x < 0 || new_x >= this->col ) continue;
		if ( new_y < 0 || new_y >= this->row ) continue;
		if ( this->marked[new_y][new_x] ) continue;		// 이미 방문한 경우 다른 방향으로
		if ( this->map[new_y][new_x] == 0 ) continue;	// 벽인 경우 다른 방향으로
		this->order += 1;
  	this->map[new_y][new_x] = this->order;
		//std::cout << "new_x :  " << new_x << std::endl;
		//std::cout << "new_y :  " << new_y << std::endl;
		//std::cout << this->order << std::endl;
		path.push_back(this->order);
    this->marked[new_y][new_x] = 1;
    if( Search(new_x, new_y) ) // 끝까지 도달한 경우.
      return 1;
		this->order--;
		this->map[new_y][new_x] = 1;
		path.pop_back();
    this->marked[new_y][new_x] = 0;
  }
  return 0;
}

// Print path from stack's whole items.
void Generator::Print_path()
{
	for(int i = 0; i < this->path.size(); i++ )
		std::cout<<path[i]<<' ';
	std::cout<<'\n';
}

// This function deletes the item of path.
void Generator::Delete_items()
{
	/*
		1. Selcet item that changes value to -1 from path and matrix.
		2. if a
	*/

	/* 숫자 1은 무조건 주어져야 함 (starting point)
		 답이 unique할 필요가 없으므로 적당히 답이 만들어지게끔 제거하면 됨.
		 숫자들의 간격이 13차이가 나면 안됨.
	*/
	// Path에서 2부터 +1(80%) or +2(20%) 하면서 delete 13이 넘으면 남기고
	// 시작지점에서 다시 Path를 쫓아가면서 Delete?
	int a, b, thirteen;


	// a : 2 ~ (마지막 번호-1) 중 하나.
	// a = rand()%(roomsize-2) + 2;

	a = 2;
	thirteen = 0;
	srand((unsigned int)time(0));
	while(a < roomsize){
		b = rand()%4;
		if(b != 0 && thirteen < 13){ // 3/4의 확률로 지움.
			// 딜리트 a
			thirteen++;
			for(int i = 0; i < this->row; i++)
				for(int j = 0; j < this->col; j++)
					if(map[i][j] == a)
						map[i][j] = -1;
		}
		a++;
		thirteen = 0;
	}
}

// This function saves result matrix.
// file name is "input_data.txt"
void Generator::Save_matrix()
{
	/*
	write matrix line by line.
	*/

	std::cout << "After Delete Matrix" << std::endl;
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::fstream fo("input.txt");

	fo << this->row << " " << this->col;
	fo << std::endl;
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			fo << map[i][j] << " ";
		}
		fo << std::endl;
	}
}


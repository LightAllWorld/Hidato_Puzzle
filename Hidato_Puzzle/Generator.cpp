#include "Generator.h"

void Generator::run()
{
	std::vector<int> random;
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            if(map[i][j] == 1){
                random.push_back(this->row*i+j);
            }
        }
    }
    
    for(int i = 0; i < roomsize; i++){
        int x = rand() % roomsize;
        int y = rand() % roomsize;
        if(x != y){
            int temp = random[x];
            random[x] = random[y];
            random[y] = temp;
        }
    }

    for(int i = 0; i < roomsize; i++){
        std::cout << random[i];
    }

    for(int i = 0; i < this->roomsize; i++){
        start_x = random[i] % (this->col);
        start_y = random[i] / (this->col);

        this->order = 1;
        this->marked[start_y][start_x] = 1;
        if(Search(start_x, start_y) == 1){
            isSearch = 1;
            break;
        }
        this->marked[start_y][start_x] = 0;
    }
	Save_matrix();
}

void Generator::Setting()
{
	this->marked = new int*[this->row];

	for( int i = 0; i < this->row; i++)
		this->marked[i] = new int[this->col];

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
	int new_x, new_y, b;

	if ( this->order == this->roomsize )
		return 1;

	for(int side_idx = 0; side_idx < 8; side_idx++){
		new_x = point_x + this->side[side_idx][0];
		new_y = point_y + this->side[side_idx][1];
		if ( new_x < 0 || new_x >= this->col ) continue; // x방향에서 맵밖으로 나간 경우
		if ( new_y < 0 || new_y >= this->row ) continue; // y방향에서 맵밖으로 나간 경우
		if ( this->marked[new_y][new_x] ) continue;		// 이미 방문한 경우
		if ( this->map[new_y][new_x] == 0 ) continue;	// 벽인 경우

		this->order += 1;
		b = rand()%4;

		if(b != 0 && thirteen < 13 && this->order < this->roomsize-1){
			this->map[new_y][new_x] = -1;
			thirteen++;
		}
		else{
			this->map[new_y][new_x] = this->order;
			this->thirteen = 0;
		}

		path.push_back(this->order);
		this->marked[new_y][new_x] = 1;

	    if( Search(new_x, new_y) ) // 끝까지 도달한 경우.
	    	return 1;

	    this->order--;
	    this->map[new_y][new_x] = 1;
	    path.pop_back();
	    this->marked[new_y][new_x] = 0;
	}

	std::cout << "return 0" << std::endl;
	return 0;
}

// This function saves result matrix.
// file name is "input_data.txt"
void Generator::Save_matrix()
{
	/*
	write matrix line by line.
	*/
	/* input.txt파일에 Puzzle을 저장해주는 함수 */
	std::cout << std::endl;
	std::cout << "After Delete Matrix" << std::endl;
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			if (map[i][j] == 0) {
				std::cout << "00 ";
				continue;
			}
			else if (map[i][j] < 10 && map[i][j] > 0) {
				std::cout << " " << map[i][j] << " ";
				continue;
			}
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
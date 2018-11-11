#include <iostream>
#include <fstream>

// 유니크 안해도댐. 앙 개꿀띠 

const int MAX = 100;
int M, N;
int order = 2;
int roomsize = 0;

int side[8][2] = { { 0,1 }, { 1,1 }, { 1,0 }, { 1,-1 }, { 0,-1 }, { -1,-1 }, { -1,0 }, { -1,1 } };

 int SearchPath(int input[][MAX+1], int visited[][MAX+1], int Pointx, int Pointy, int order){
  int n = input[0].size();
  // startingPointx = 0~n
  // startingPointy = 0~m
  int new_x, new_y;

  if ( order == roomsize )
    return 1;

  for(int side_idx = 0; side_idx < 8; side_idx++){
    new_x = row + side[side_idx][0];
    new_y = col + side[side_idx][1];
    if ( new_x < 0 || new_x >= N ) continue;
    if ( new_y < 0 || new_y >= M ) continue;
    if ( visited[new_x][new_y] ) continue;
    if ( input[new_x][new_y] == 0 ) continue;

    input[new_x][new_y] = order;
    is_visited[new_x][new_y] = 1;
    if( SearchPath(input, visited, new_x, new_y, order++) ) // 끝까지 도달한 경우.
      return 1;
    //SearchPath(input, visited, new_x, new_y, order++);
    is_visited[new_x][new_y] = 0;
  }
  return 0;
}

int main(){
  ifstream ifs("input.txt");
  ifs >> M >> N;
  // input 배열을 받음.
  int input[M][N];
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      ifs >> input[i][j];
    }
  }
  int visited[M][N] = {0,};
  // 방크기 구함.
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(input[i][j] == 1)
        roomsize++;
    }
  }
  // startX, startY 예원님이 구현.
  SearchPath(input, visited, startX, startY, 2);
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
}

// 문제점
// 시계방향으로 가는 방법으로 Path를 찾을 때 오른손 법칙으로 미로의 출구를 찾는 방식으로 밖에 Path가 나오지 않음.
// 아니다 recursive backtracking으로 구현하면 됨.
// 모든 공간을 다 거치는 Path를 찾는 방법....

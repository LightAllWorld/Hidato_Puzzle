#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
 
//------------------------------------------------------------------------------
using namespace std;
 
//------------------------------------------------------------------------------
struct node
{
	//Matrix의 노드값들을 위한 구조체
};
//------------------------------------------------------------------------------
class Solve // Hidato puzzle을 풀기 위한 객체
{
public:
    Solve()
    {
		// 초기 생성자
    }
 
    void solve( vector<string>& puzz, int max_wid )
    {
		/* puzzle을 채우는데 조건을 고려하면서 채움
		1. 현재 노드에서 다음 탐색할 노드의 값이 벽이거나 사이즈를 벗어나면 탐색을 계속 시도
		2. 다음 탐색할 노드의 값이 비어있으면 그 때 노드포인터를 옮기고 노드값 채우기
		3. 다음 탐색 지점 노드값이 그 지점 주변에 제너레이터에서 발생한 중간값 -1 일경우
		값을 더하지않고 포인터만 옮긴후 그 지점 노드부터 탐색 재개
		*/
    }
 
private:
    bool search( int x, int y, int w )
    {
		// 탐색지점을 재귀형태로 가능한지 판단하는 함수
    }
 
    unsigned char getNeighbors( int x, int y )
    {
		// 주변 노드 값들이 무엇인지 알아내는 함수
    }
 
    void initSolve()
    {
		// 초기 1을 찾은후 search를 돌리는 함수
    }
 
    void findStart( int& x, int& y )
    {
		// 초기 값 1을 찾는 함수
    }
 
    int wid, hei, max, dx[8], dy[8];
    node* arr;
    bool* weHave;
};
//------------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
	/* 제너레이터에서 받아온 input.txt를 읽어서 solve를 통해 최종 완성된 Matrix를 출력

	인풋
0 1 0 0
14 -1 3 0
-1 0 -1 6
-1 0 5 -1
-1 -1 -1 0
10 0 0 0


	아웃풋
0 1 0 0
14 2 3 0
13 0 4 6
12 0 5 7
11 9 8 0
10 0 0 0

	*/
}

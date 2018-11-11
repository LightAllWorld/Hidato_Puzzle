#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include "Generator.h"

int main(int argc, char const *argv[])
{
	int row, col;
	std::fstream fop("test.txt");
	fop>>row>>col;
	
	Generator gt(row, col, fop);
	gt.run();
	
	return 0;
}
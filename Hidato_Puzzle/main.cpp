#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#include "Generator.h"
#include "Solver.h"

int main(int argc, char const *argv[])
{
	// Generator
	int row, col;
	std::fstream fop("test.txt");
	fop>>row>>col;

	srand((unsigned int)time(0));
	Generator gt(row, col, fop);
	gt.run();

	// Solver
	ifstream in;
	in.open("input.txt");

	Solver solver;
	solver.input(in);
	solver.solve();

	ofstream out;
	out.open("output.txt");
	solver.output(out);

	in.close();
	out.close();

	return 0;
}

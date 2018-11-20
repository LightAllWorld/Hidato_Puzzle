#include <iostream>
#include "Solver.h"

int main() {
	fstream in;
	in.open("input.txt", ios::in);
	Solver solver;
	solver.input(in);
	solver.solve();

	fstream out;
	out.open("output.txt", ios::out);
	solver.output(out);

	return 0;
}
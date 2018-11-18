#include <iostream>
#include "Solver2.h"

int main() {
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
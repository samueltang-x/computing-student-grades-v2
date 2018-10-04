#include "student_info.h"
#include "median.h"
#include "grade.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::sort;
using std::domain_error;
using std::istream;

istream& read(istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
}
bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}
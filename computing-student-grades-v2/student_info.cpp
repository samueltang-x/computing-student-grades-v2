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

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(istream& is) { read(is); }

istream& Student_info::read(istream& is) {
	is >> n >> midterm >> final;
	read_hw(is, homework);
	return is;
}

/*
istream& read(istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);
	return is;
}
*/

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
	return x.name() < y.name();
}

double Student_info::grade() const {
	return ::grade(midterm, final, homework);
}
#include "student_info.h"
#include "median.h"
#include "grade.h"
#include "Grad.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::sort;
using std::domain_error;
using std::istream;

istream& Core::read_common(istream& is) {
	is >> n >> midterm >> final;
	//read_hw(is, homework);
	return is;
}


istream& Core::read(istream& is) {
	read_common(is);
	read_hw(is, homework);
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

bool compare(const Core& x, const Core& y) {
	return x.name() < y.name();
}

bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
	return compare(*cp1, *cp2);
}

double Core::grade() const {
	return ::grade(midterm, final, homework);
}

istream& Student_info::read(istream& is) {
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U') {
		cp = new Core(is);
	}
	else {
		cp = new Grad(is);
	}

	return is;
}

// copy constructor of class Student_info
Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

// assignment constructor of class Student_info
Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}
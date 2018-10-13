#include "student_info.h"
#include "median.h"
#include "grade.h"
#include "vector"
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <string>

using std::vector;
using std::domain_error;
using std::transform;
using std::string;
using std::ostream;
using std::endl;

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
double grade(double midterm, double final, double hw) {
	return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade_aux(const Student_info& s) {
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

bool did_all_hw(const Student_info& s) {
	return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

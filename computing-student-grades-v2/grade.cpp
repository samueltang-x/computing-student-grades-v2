#include "student_info.h"
#include "median.h"
#include "grade.h"
#include "vector"
#include <stdexcept>

using std::vector;
using std::domain_error;

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
#ifndef GUARD_grade_info_h
#define GUARD_grade_info_h

#include "student_info.h"
#include <string>
#include <vector>

double grade(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);

#endif

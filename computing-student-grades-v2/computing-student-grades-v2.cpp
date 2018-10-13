// computing-student-grades-v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "student_info.h"
#include "grade.h"
#include "median.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using std::sort;
using std::max;
using std::streamsize;
using std::setprecision;
using std::domain_error;
using std::remove_copy;

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did,
	const vector<Student_info>& didnt) {
	out << name << ": median(did) = " << analysis(did) <<
		", mesian(didnt) = " << analysis(didnt) << endl;
}

double average_grades(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grades);
	return median(grades);
}

double optimistic_median_grades(const Student_info& s) {
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median_grades);
	return median(grades);
}

int main()
{
	vector<Student_info> did, didnt;
	Student_info record;

	cout << "Please enter students info with format: " << endl
		<< "<name> <midterm> <final> [homework 1 | 2 | ...]" << endl;

	while (read(cin, record)) {
		if (did_all_hw(record))
			did.push_back(record);
		else
			didnt.push_back(record);
	}

	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
		optimistic_median_analysis, did, didnt);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// computing-student-grades-v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "student_info.h"
#include "Grad.h"
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

/*
double median_analysis(const vector<Core>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Core>&),
	const vector<Core>& did,
	const vector<Core>& didnt) {
	out << name << ": median(did) = " << analysis(did) <<
		", mesian(didnt) = " << analysis(didnt) << endl;
}

double average_grades(const Core& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Core>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grades);
	return median(grades);
}

double optimistic_median_grades(const Core& s) {
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Core>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median_grades);
	return median(grades);
}
*/



int main()
{
	vector<Handle<Core>> students;
	Handle<Core> record;
	char ch;
	// The max length of student name
	string::size_type maxlen = 0;

	cout << "Please enter students info with format: " << endl
		<< "<name> <midterm> <final> [homework 1 | 2 | ...]" << endl;

	// Read and store the date(input from console/terminal).
	while (cin >> ch) {
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;

		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	// Alphabetize the student records
	sort(students.begin(), students.end(), compare_Core_handles);

	// Write the names and grades
	for (vector<Handle<Core>>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i]->name()
			<< string(maxlen + 1 - students[i]->name().size(), ' ');

		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}

/**
* Test data:
*   U Samuel 86 92 89 95
*   G Jacob 79 84 93 84 95
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

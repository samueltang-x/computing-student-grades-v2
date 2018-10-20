#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <string>
#include <vector>

class Student_info
{
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;

public:
	Student_info();
	Student_info(std::istream&);
	std::istream& read(std::istream&);
	double grade() const;
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }
};

std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Student_info&, const Student_info&);

#endif
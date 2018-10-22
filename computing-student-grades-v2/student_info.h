#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <string>
#include <vector>

class Core {
	friend class Student_info;
protected:
	virtual Core* clone() const { return new Core(*this); }
	std::istream& read_common(std::istream&);
	
	double midterm, final;
	std::vector<double> homework;

private:
	std::string n;    // to avoid the same name as the member function name()

public:
	// default constructor
	Core() : midterm(0), final(0) {}

	// cosntructor for reading a stream
	Core(std::istream& is) { read(is); }

	virtual ~Core() {}

	virtual std::istream& read(std::istream&);
	
	virtual double grade() const;
	
	std::string name() const { return n; }
	
	bool valid() const { return !homework.empty(); }
};

//std::istream& read(std::istream&, Core&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

class Student_info {
public:
	Student_info() : cp(0) {}
	Student_info(std::istream& is) : cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	~Student_info() { delete cp; }

	std::istream& read(std::istream&);

	std::string name() const {
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}

	double grade() const {
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}

private:
	Core* cp;
};

#endif
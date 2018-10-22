#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include "student_info.h"
#include <istream>

class Grad : public Core {
protected:
	Grad* clone() const { return new Grad(*this); }

public:
	Grad() : thesis(0) {}    // default constructor
	Grad(std::istream& is) { read(is); }    // constructor for reading from stream
	//~Grad();

	double grade() const;

	std::istream& read(std::istream&);
private:
	double thesis;
};

#endif
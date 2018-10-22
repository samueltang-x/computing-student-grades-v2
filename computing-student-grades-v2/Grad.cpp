#include "Grad.h"
#include <istream>
#include <algorithm>

using std::istream;
using std::min;

istream& Grad::read(istream& in) {
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const {
	return min(Core::grade(), thesis);
}
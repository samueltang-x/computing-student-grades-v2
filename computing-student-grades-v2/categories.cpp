#include "student_info.h"
#include "grade.h"
#include <list>

using std::list;

bool fgrade(const Core& s) {
	return s.grade() < 60;
}

list<Core> extract_fails(list<Core>& students) {
	list<Core> fail, pass;

	list<Core>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}

	return fail;
}
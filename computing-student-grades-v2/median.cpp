#include "median.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

using std::vector;
using std::domain_error;
using std::sort;
using std::accumulate;

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_size;

	vec_size size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_size mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double average(const vector<double>& v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
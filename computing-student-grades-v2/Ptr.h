#ifndef GUARD_Prt_h
#define GUARD_Prt_h

#include <cstddef>      // std::size_t()
#include <stdexcept>    // std::runtime_error();

// 14.3: Handle that let you decide when to share data
template<class T> class Ptr {
public:
	void make_unique() {
		if (*refptr != 1) {
			--*refptr;
			refptr = new std::size_t(1);
			p = p ? p->clone() : 0;
		}
	}

	Ptr() : refptr(new std::size_t(1)), p(0) {}
	Ptr(T* t) : refptr(new size_t(1)), p(t) {}
	Ptr(const Ptr& h) : refptr(h.refptr), p(h.p) { ++*refptr }

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const { return 0; }
	T& operator*() const;
	T& operator->() const;

private:
	T* p;
	std::size_t refptr;
};

template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs) {
	++*rhs.refptr;
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}

	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template<class T>
Ptr<T> Ptr<T>::operator*() const {
	if (p)
		return *p;
	throw std::runtime_error("unbound Ptr");
}

template<class T>
Ptr<T> Ptr<T>::operator->() const {
	if (p)
		return p;
	throw std::runtime_error("unbound Ptr");
}

#endif
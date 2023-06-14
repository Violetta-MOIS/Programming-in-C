#include <iostream>
using namespace std;

template <typename Atype>
class Set {
	Atype* a;
	int len;
public:
	Set(int size);
	~Set() {
		delete[] a;
	};
	bool Is_Empty();
	bool Is_Full();
	bool Add(Atype T);
	bool In_Set(Atype T);
	Atype Get(Atype T);

};


template <typename Atype> Set<Atype>::Set(int size) {
	len = size;
	a = new Atype[len];
	for (int i = 0; i < len; i++) a[i] = 0;
}


template <typename Atype> bool Set<Atype>::Is_Empty() {
	return(len == 0);
}

template <typename Atype> bool Set<Atype>::Is_Full() {
	return len == sizeof(a) / sizeof(a[0]);
}

template <typename Atype> bool Set<Atype>::In_Set(Atype T) {
	for (int i = 0; i < len; i++) {
		if (a[i] == T) {
			return true;
		}
	}
	return false;
}


template <typename Atype> bool Set<Atype>::Add(Atype T) {
	if (In_Set(T)) {
		return false;
	}
	else {
		if (len == sizeof(a) / sizeof(a[0])) {
			return false;
		}
		else {
			a[len] = T;
			len++;
			return true;
		}
	}
}

template <typename Atype> Atype Set<Atype>::Get(Atype T) {
	for (int i = 0; i < len; i++) {
		if (a[i] == T) {
			return T;
		}
		
	}
	return Atype();
}
#include "rational.h"

rational::rational() {
};
rational::rational(int a1, int b1) {
	if (b1 != 0) {
		a = a1 % b1;
		b = b1;
		if (b % a1 == 0) {
			a = 1;
			b = b1 / a1;
		}
	}
}
void rational::set(int a1, int b1) {
	*this = rational(a1, b1);

};
void rational::show() {
	std::cout << a << "/" << b << std::endl;
};
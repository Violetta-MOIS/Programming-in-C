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
rational rational::operator + (rational& q) {
	int a1, b1, a2, b2;
	a1 = a;
	b1 = b;
	a2 = q.a;
	b2 = q.b;
	return rational(a1 * b2 + a2 * b1, b1 * b2);
}
rational operator - (rational& q, rational& x) {
	int a1, b1, a2, b2;
	a1 = x.a;
	b1 = x.b;
	a2 = q.a;
	b2 = q.b;
	return rational(a1 * b2 - a2 * b1, b1 * b2);
}
rational rational::operator ++ () {
	return rational(a + 1, b);
}
bool rational::operator == (rational& x) {
	double a1, b1, a2, b2;
	a1 = a;
	b1 = b;
	a2 = x.a;
	b2 = x.b;
	return ((a1 / b1) == (a2 / b2));
}
bool rational::operator > (rational& x) {
	double a1, b1, a2, b2;
	a1 = a;
	b1 = b;
	a2 = x.a;
	b2 = x.b;
	return ((a1 / b1) > (a2 / b2));
}
rational& rational::operator = (const rational& x) {
	a = x.a;
	b = x.b;
	return *this;
}
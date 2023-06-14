#include "eq2.h"
using namespace std;

eq2::eq2() {
	a = 0;
	b = 0;
	c = 0;
	D = 0;
};
eq2::eq2(double a1, double b1, double c1){
	a = a1;
	b = b1;
	c = c1;
	D = b * b - (4 * a * c);
}
void eq2::set(double a1, double b1, double c1) {
	a = a1;
	b = b1;
	c = c1;
	D = b * b - (4 * a * c);
}
double eq2::find_X() {
	if (D < 0) {
		cout << "Нет решения! ";
		return 0;
	}
	else if (D == 0) {
		return ((-b - sqrt(D)) / 2 * a);
	}
	else {
		double x1, x2;
			x1 = ((-b - sqrt(D)) / 2 * a);
			x2 = ((-b + sqrt(D)) / 2 * a);
			return x1 > x2 ? x1 : x2;
	}
}
double eq2::find_Y(double x1) {
	return (a * x1 * x1 + b * x1 + c);
}

eq2 operator +(eq2& x1, eq2& x2)
{
	eq2 new_eq2 = eq2(x1.a + x2.a, x1.b + x2.b, x1.c + x2.c);
	return new_eq2;
}
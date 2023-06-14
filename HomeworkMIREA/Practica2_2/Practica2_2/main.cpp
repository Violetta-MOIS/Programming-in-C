#include "Circle.h"
#include <iostream>
using namespace std;

int main() {
	Circle mas[3];
	float radius;
	float x_center;
	float y_center;

	for (int i = 0; i < 3; i++) {
		cout << " Radiys kryga ¹ " << i + 1 << " raven: " << endl;
		cin >> radius;

		cout << "x " << i + 1 << " raven: " << endl;
		cin >> x_center;

		cout << "y " << i + 1 << " raven: " << endl;
		cin >> y_center;

		mas[i].set_circle(radius, x_center, y_center);
	}

	for (int i = 0; i < 3; i++) {
		cout << " " << i + 1 << ": " << mas[i].square() << endl;
		cout << "Okryznost ¹ " << i + 1 << " mozno opisat:)? (1 - da, 0 - net)" << mas[i].triangle_around(radius, x_center, y_center) << endl;
		cout << "Okryznost ¹ " << i + 1 << " mozno vpisat:)? (1 - da, 0 - net)" << mas[i].triangle_in(radius, x_center, y_center) << endl;

	}
	float r2, x2, y2;
	cout << "Vvedite r2,x2,y2 " << endl;
	cin >> r2 >> x2 >> y2;
	for (int i = 0; i < 3; i++) {
		cout << "Peresekaytsa? (1 - da, 0 - net) " << mas[i].check_circle(r2, x2, y2) << endl;
	}
}
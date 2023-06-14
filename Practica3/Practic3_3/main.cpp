#include "rational.h"
using namespace std;
int main() {
	int size;
	cin >> size;
	rational* mas = new rational[size];
	for (int i = 0; i < size; i++) {
		int num_a, num_b;
		cin >> num_a >> num_b;
		mas[i].set(num_a, num_b);
	};
	for (int i = 0; i < size; i++) {
		mas[i].show();
	}
	rational X = mas[0];
	rational Y;
	if (size < 2)
	{
		Y = rational(1, 2);
	}
	else
	{
		Y = mas[1];
	}
	X.show();
	Y.show();
	(X + Y).show();
	(X - Y).show();
	rational Z = X;
	++Z;
	Z.show();
	cout << (X == Y);
	cout << (X > Y);

	mas = NULL;
	delete[] mas;
	return 0;
}
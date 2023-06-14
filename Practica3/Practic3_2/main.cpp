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
	return 0;
}
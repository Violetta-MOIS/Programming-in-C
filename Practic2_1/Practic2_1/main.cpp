#include <iostream>
#include <cmath>
#include "Triangle.h"
using namespace std;


int main()
{
    Triangle mas[3];
    double a, b, c;
    for (int i = 0; i < 3; i++) {
        cout << " Vvedite a,b,c treygolnika № "  << i + 1 << " cherez propel: " << endl;
            cin >> a >> b >> c;
        mas[i].set(a, b, c);
        if (!(mas[i].exst_tr())) {
            mas[i].show();
            cout << "  " << endl;
                i--;
        }
    }
    for (int i = 0; i < 3; i++) {
        mas[i].show();
        setlocale(LC_ALL, "");
        cout << "Perimetr = " << mas[i].perimetr() << endl;
        cout << "Ploshad = " << mas[i].square() << endl;
    }
    return 0;
}
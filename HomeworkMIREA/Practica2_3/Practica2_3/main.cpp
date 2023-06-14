#include "Figure.h"
#include <iostream>
using namespace std;

int main() {
    Figure mas[8];

    float x1, x2, x3, x4;
    float y1, y2, y3, y4;

    for (int i = 0; i < 3; i++) {
        cout << "Chetirexygol № " << i + 1 << " coordinati(1) = " << endl;
        cin >> x1 >> y1;

        cout << "Chetirexygol № " << i + 1 << " coordinati(2) = " << endl;
        cin >> x2 >> y2;

        cout << "Chetirexygol № " << i + 1 << " coordinati(3) = " << endl;
        cin >> x3 >> y3;

        cout << "Chetirexygol № " << i + 1 << " coordinati(4) = " << endl;
        cin >> x4 >> y4;

        mas[i].figure(x1, x2, x3, x4, y1, y2, y3, y4);

    }

    for (int i = 0; i < 3; i++) {
        cout << "Parametr " << 1 << ": ";
        mas[i].show();

        cout << "It's rectangle? (1 - yes, 0 - not) = " << mas[i].is_prug() << endl;
        cout << "It's square? (1 - yes, 0 - not) = " << mas[i].is_square() << endl;
        cout << "It's rhomb? (1 - yes, 0 - not) = " << mas[i].is_romb() << endl;

        cout << "Opisat mozno okryznost:)? (1 - yes, 0 - not) = " << mas[i].is_out_circle() << endl;
        cout << "Vpisat mozno okryznost:)? (1 - yes, 0 - not) = " << mas[i].is_in_circle() << endl;

    }

}
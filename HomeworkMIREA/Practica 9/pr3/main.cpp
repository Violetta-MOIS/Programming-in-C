#include <iostream>
#include "set.h"
using namespace std;


int main() {
    Set<int> s(5);
    cout << s.Is_Empty() << endl; 
    cout << s.Is_Full() << endl; 

    s.Add(1);
    s.Add(2);
    s.Add(3);
    cout << s.In_Set(2) << endl; 
    cout << s.In_Set(4) << endl; 

    cout << s.Get(2) << endl; 

    cout << s.Is_Empty() << endl; 
    cout << s.Is_Full() << endl; 
    return 0;
}
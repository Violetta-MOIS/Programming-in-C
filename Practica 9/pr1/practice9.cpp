#include <iostream>
#include "practice9.h"
using namespace std;

class My_class {
 int a;
 float b;
 public:
 My_class (int a, float b) {
 this->a = a;
 this->b = b;
 }
 void Out() {
 cout << a << " " << b << "\n";
 }
 My_class operator = (My_class &T) {
 a = T.a;
 b = T.b;
 return *this;
 }
}; 
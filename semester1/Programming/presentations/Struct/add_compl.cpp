//структури
//додавання комплексних чисел
#include <iostream>
using namespace std;

struct complex {
  float re, im;
};

complex add_complex (complex c1, complex c2){
 complex c3 = c1;
 c3.re += c2.re;
 c3.im += c2.im;
 return c3;
}

int main(){
 complex x, y, z;
 x.re = 1;
 x.im = 1;
 y.re = 2;
 y.im = 2;
 z = add_complex(x, y);

 cout << "z = x+y = " << z.re << " + " << z.im << "i" << endl;
 return 0;
}

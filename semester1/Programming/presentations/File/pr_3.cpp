#include <cstdio>
#include <iostream>
using namespace std;
int main() {
 FILE *fp = fopen("d:\\Tmp\\data1.dat", "wb");
 struct Point {
  int x, y;
 } point;
 point.x = 10;
 point.y = 20;
 int x = fwrite(&point, sizeof(Point), 1, fp);
 cout << x << endl;
 system("pause"); return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
 FILE *fp = 0;
 struct Point {
  int x, y;
 } point1, point2;
 int x;
 if ((fp = fopen("d:\\Tmp\\data1.dat", "wb")) == NULL){
   perror("Error");
   cin.get();
   return 1;
 }
 point1.x = 10;
 point1.y = 20;
 x = fwrite(&point1, sizeof(Point), 1, fp);
 cout << x << endl;
 fflush(fp);
 fclose(fp);
 if ((fp = fopen("d:\\Tmp\\data1.dat", "rb")) == NULL){
   perror("Error");
   cin.get();
   return 1;
 }
 x = fread(&point2, sizeof(Point), 1, fp);
 cout << point2.x << endl;
 cout << point2.y << endl;
 cout << x << endl;
 fclose(fp);
 cin.get();
 return 0;
}
//приклад роботи з потоками
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
 FILE *fi, fo;
 if ((fi = fopen("d:\\Tmp\\data4.txt", "r")) == NULL){
   cout << "Error open input file" << endl;
   return 1;}
 if ((fo = fopen("d:\\Tmp\\data4.dat", "w+b")) == NULL){
   cout << "Error open output file" << endl;
   return 1;}
 const int dl = 80;
 char s[80];
 struct {
   char type[20];
   float opt, rozn;
   char comm[30];
 } mon;
 int kol = 0;  //кількість записів у файлі
 while (fgets(s, dl, fi)){
   strncpy(mon.type, s, 19);
   mon.type[19] = '\0';
   mon.opt = atof(&s[20]);
   mon.rozn = atof(&s[30]);
   strncpy(mon.comm, &s[40], 30);
   fwrite(&mon, sizeof mon, 1, fo);
   kol++;
 }
 fclose(fi);
 int i;
 cin >> i;
 if (i >= kol){
   cout << "Not exist"; return 1;}
 fseek(fo, (sizeof mon)*i, SEEK_SET);
 fread(&mon, sizeof mon, 1, fo);
 cout << "mon.type " << mon.type << " opt " << mon.opt
      << " rozn " << mon.rozn << endl;

 fclose(fo);
 cin.get();
 return 0;
}

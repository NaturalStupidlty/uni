//посимвольне читання
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
 FILE *fp = 0;
 char ch = 0;
 if ((fp = fopen("d:\\Tmp\\data2.txt", "w+")) == NULL){
   perror("Error");
   cin.get();
   return 1;
 }
 fputs("String1\nstring2", fp);
 fflush(fp);
 rewind(fp);
 ch = fgetc(fp);
 while (!feof(fp)){
   if (ferror(fp)){
     perror("Error");
     cin.get();
     return 1;
   }
 cout << ch << "  (" << (int)ch << ")" << endl;
 ch = fgetc(fp);
}
 fclose(fp);
 cin.get();
 return 0;
}

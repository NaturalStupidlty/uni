//записування масиву у файл
//зчитування першої та передостанньої компонент
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
 FILE *fp = 0;
 int arr[] = {1, 2, 3, 4, 5}, x = 0, size = 0;
 long pos = 0;
 if ((fp = fopen("d:\\Tmp\\data3.dat", "w+b")) == NULL){
   perror("Error");
   cin.get();
   return 1;
 }
 size = sizeof(int);
 fwrite(arr, size, 5, fp); //запис масиву
 fflush(fp);
 
 fseek(fp, 0L, SEEK_SET); //переміщення у початок
 pos = ftell(fp);
 cout << pos << endl;
 fread(&x, size, 1, fp);
 cout << x << endl;
 
 fseek(fp, -2L*size, SEEK_END); //переміщення на передостанній
 pos = ftell(fp);
 cout << pos << endl;
 fread(&x, size, 1, fp);
 cout << x << endl;

 fclose(fp);
 cin.get();
 return 0;
}

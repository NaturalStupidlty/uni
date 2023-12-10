#include <iostream>
using namespace std;
int sum(const int*, const int);
const int n=10;

int main()
{
  int marks[n] = {3, 4, 5, 4, 4};
  cout << "Summa = " << sum(marks, n) << endl;
  system("pause"); return 0;
}

int sum(const int* arr, const int n)
//або int sum(int arr[], int n)
//або int sum(int arr[n], int n)
//n повинна бути константою
{
  int s = 0;
  for (int i=0; i<n; i++) s += arr[i];
  return s;
}
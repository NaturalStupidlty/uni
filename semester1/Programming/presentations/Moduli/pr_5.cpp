//узагальнене сортування
#include <iostream>
using namespace std;

void bubble(int *, const int, int (*)(int, int));
int ascending(const int, const int);
int descending(const int, const int);
void swap(int *, int *);

int main() {
  const int arrSize = 10;
  int order, a[arrSize] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
  cout << "1 - increase" << endl
       << "2 - decrease: " << endl;
  cin >> order;
  cout << endl << "Array:" << endl;
  for (int i = 0; i < arrSize; i++)
    cout << a[i] << "  ";
  if (order == 1){
    bubble(a, arrSize, ascending);
	cout << endl << "Array in increase order" << endl;
  }
  else {
  bubble(a, arrSize, descending);
  cout << endl << "Array in decrease order" << endl;
  }
  for (int i = 0; i < arrSize; i++)
    cout << a[i] << "  ";
  cout << endl;
  system("pause"); return 0;
}

void bubble(int *work, const int size, int (*compare)(int, int))
{
  for (int i = 1; i < size; i++)
    for (int j = 0; j < size-1; j++)
	  if ((*compare)(work[j],work[j+1]))
	      swap(&work[j], &work[j+1]);
}

void swap(int *el1, int *el2)
{
  int temp;
  temp = *el1;
  *el1 = *el2;
  *el2 = temp;
}

int ascending(const int a, const int b)
{
  return b < a;
}

int descending(const int a, const int b)
{
  return b > a;
}

#include <cstdio>
//простий калькулятор

int main() {
   double sum = 0, v;
   printf("Enter numbers.   Finish - <Enter+Ctrl+Z>\n");
   while (scanf("%lf", &v) != EOF)
    printf("\t%.3f\n", sum += v);
   system("pause"); return 0;
}


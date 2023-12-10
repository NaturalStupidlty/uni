#include <cstdio>
#include <cctype>

int main() {
   int c;
   while ((c=getchar()) != '\n')
    putchar(isupper(c) ? tolower(c) : c);
   system("pause"); return 0;
}


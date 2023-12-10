#include <iostream>
#include <cstring>
using namespace std;

void mergeStrings(char *res, unsigned int N1, unsigned int N2, char *S1, char *S2);

int main() {
    char S1[] = "Ame123";
    char S2[] = "12343643rica";
    char res[100];
    mergeStrings(res, 3, 4, S1, S2);
    cout << res << endl;
    return 0;
}

void mergeStrings(char *res, unsigned int N1, unsigned int N2, char *S1, char *S2){
    // res - посилання на рядок, куди треба записати результат
    int counter = 0;
    int lenOfS1 = strlen(S1);
    int lenOfS2 = strlen(S2);
    if(lenOfS1 < N1) N1 = lenOfS1;
    if(lenOfS2 < N2) N2 = lenOfS2;

    // записуємо на перші N1 місць нового рядка перші N1 символи першого даного рядка
    for (int i = 0; i < N1; ++i) {
        res[counter] = S1[i];
        counter++;
    }

    // записуємо на інші нового рядка останні N2 символи другого даного рядка
    for (int i = lenOfS2-N2; i < lenOfS2; ++i) {
        res[counter] = S2[i];
        counter++;
    }

    // останім символом робимо знак закінчення рядка
    res[counter] = '\0';
}
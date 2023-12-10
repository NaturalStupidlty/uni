#include <iostream>
#include <string.h>
using namespace std;

void toText(char res[], int n){
    int h = n/100;
    int t = (n-(h*100))/10;
    int u = n-(h*100)-(t*10);

    char hundreds[10][32] = {"", " сто", " двiстi", " триста", " чотириста", " п'ятсот", " шiстсот", " сiмсот", " вiсiмсот", " дев'ятсот"};
    char tens[10][32] = {"", "", " двадцять", " тридцять", " сорок", " п'ятдесят", " шiстдесят", " сiмдесят", " вiсiмдесят", " дев'яносто"};
    char units[10][32] = {"", " один", " два", " три", " чотири", " п'ять", " шiсть", " сiм", " вiсiм", " дев'ять"};
    char teens[10][32] = {" десять", " одинадцять", " дванадцять", " тринадцять", " чотирнадцять", " п'ятнадцять", " шiстнадцять", " сiмнадцять", " вiсiмнадцять", " дев'ятнадцять"};

    strncat(res, hundreds[h], 32);

    if(t == 1) strncat(res, teens[u], 32);
    else {
        strncat(res, tens[t], 32);
        strncat(res, units[u], 32);
    }
}

int main() {
    system("chcp 65001");
    char bruh[100];
    toText(bruh, 999);
    cout << bruh;
    return 0;
}



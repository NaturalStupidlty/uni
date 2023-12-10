#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void deleteLastLine(const char *path);

int main() {
    char path[] = "t2.txt";
    deleteLastLine(path);
}

void deleteLastLine(const char *path){
    FILE *inFile = fopen(path, "r");
    FILE *outFile = fopen("deleteLastLineOutput.txt", "w");
    if(inFile == NULL){
        cout << "Couldn't open the file.\n";
        return;
    }

    char line[2048];
    line[0] = '\0';
    while (feof(inFile) == 0){
        int len = strlen(line);
        if(len > 0){
            if(ftell(outFile) != 0) fputc('\n', outFile);
            for (int i = 0; i < len-1; ++i) {
                fputc(line[i], outFile);
            }
        }
        fgets(line, 2048, inFile);
    }

    fclose(inFile);
    fclose(outFile);
    remove(path);
    cout << rename("deleteLastLineOutput.txt", path);
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void deleteEmptyLines(const char *path);

int main() {
    char path[] = "t2.txt";
    deleteEmptyLines(path);
}

void deleteEmptyLines(const char *path){
    FILE *inFile = fopen(path, "r");
    FILE *outFile = fopen("deleteEmptyLines.txt", "w");
    if(inFile == NULL){
        cout << "Couldn't open the file.\n";
        return;
    }

    bool newLine = false;
    int c;
    while ((c=fgetc(inFile)) != EOF){
        if (c == '\n') {
            newLine = true;
            continue;
        }
        if(newLine) {
            fputc('\n', outFile);
            newLine = false;
        }
        fputc(c, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    remove(path);
    rename("deleteEmptyLines.txt", path);
}
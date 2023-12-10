#include <iostream>
#include <string.h>

using namespace std;

int countDifferentWords(char *s, int n){
    char words[n][n];
    int wordCount = 0;
    int charCount = 0;
    bool wordInProgress = false;


    for (int i = 0; i < n; ++i) {
        char c = (char) tolower(s[i]);
        if(isalpha((c))) {
            words[wordCount][charCount] = c;
            charCount++;
        }
        if(!isalpha(c) || i==n-1) {
            if(charCount != 0){
                words[wordCount][charCount] = '\0';
                charCount = 0;
                bool found = false;
                for (int j = 0; j < wordCount; ++j) {
                    if(strcmp(words[j], words[wordCount]) == 0) found = true;
                }
                if(!found){
                    wordCount++;
                }
            }
        }
    }

//    for (int i = 0; i < wordCount; ++i) {
//        cout << words[i] << endl;
//    }
    return wordCount;
}

int main() {
    char s[] = "This is the house that Jack built. This is the malt that lay in the house that Jack built. This is the rat that ate the malt. That lay in the house that Jack built.";
    std::cout << countDifferentWords(s, strlen(s)) << std::endl;
    return 0;
}

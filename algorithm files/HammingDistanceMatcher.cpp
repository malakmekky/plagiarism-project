/* example of hamming distance brute force approach from geeks for geeks
#include <iostream>
using namespace std;

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) 
            cout << "pattern is found at " << i << endl;
    }
}

int main() {
    char txt[] = "AAAAAAAAAAAAAAAAAA";
    char pat[] = "AAAAA";
    search(pat, txt);
    return 0;
}*/
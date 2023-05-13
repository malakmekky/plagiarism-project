//example rabin karp approach from geeks for geeks 
/*class RabinKarpMatcher : public PlagiarismDetector {
public:
    RabinKarpMatcher(string corpus_dir); //constructor
    set<string> match(string sentence); //matches sentence using Rabin Karp algorithm

private:
    string matcher;
};*/
#include <cstring>
#include <iostream>
#include <fstream>
//#include "RabinKarpMatcher.h"
//#include "Document.h"
using namespace std;

#define d 10


void rabinKarp(string pattern, string text, bool &found) {
    int q = text.length();
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
            {
                found = 1;
                cout << "pattern found at: " << i + 1 << endl;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}
// call variables
//to compare effeciency, make a counter that increments every time it compares 
void get_text(string pattern)
{
    string line;
    fstream text;
    bool found =0;
    text.open("document1.txt");
    while(getline(text,line))
    { 
        cout << line << endl;  
        rabinKarp(pattern, line, found);
        if(found)
            break;
    }
    if(!found)
        cout << "Not found" << endl;
}

int main() {
    // string text = "abaabdbebabc";
    string pattern = "khalil";
    get_text(pattern);
    // rabinKarp(pattern, text);
}
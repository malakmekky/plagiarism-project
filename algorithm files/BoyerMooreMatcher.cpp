/* an example of an implementation of boyer moore from geeks for geeks.
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1000005;
int n, m;
char T[MAX_N], P[MAX_N];
int b[MAX_N], f[MAX_N];

void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void boyerMoore() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = f[j];
        i++; j++;
        if (j == m) {
            cout << "Match found at index " << i - j << endl;
            j = f[j];
        }
    }
}

int main() {
    cin >> T >> P;
    n = strlen(T);
    m = strlen(P);
    reverse(P, P + m);
    kmpPreprocess();
    for (int i = 0; i <= m; i++) f[i] = m - b[m];
    for (int i = 1; i <= m; i++) {
        int j = b[i];
        if (j >= 0 && P[i] == P[j]) f[i] = f[j];
    }
    boyerMoore();
    return 0;
}
*/
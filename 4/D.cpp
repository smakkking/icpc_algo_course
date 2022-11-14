#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bin_search(int *b, int p, int r, int a) {
    int q = (p + r) / 2;

    if (r - p == 1)
        return b[r] - a < a - b[q]? b[r] : b[q];

    if (b[q] < a)
        return bin_search(b, q, r, a);
    else
        return bin_search(b, p, q, a);
}

int main() {
    int N, K;
    cin >> N >> K;
    int a[N], b[K];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < K; i++) 
    {
        cin >> b[i];
        cout << bin_search(a, 0, N - 1, b[i]) << endl;
    }
    
 }

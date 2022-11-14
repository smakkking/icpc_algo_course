#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int solve1(unsigned int *a, int n) {
    int min_xor = 0xffffffff;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] ^ a[j] < min_xor)
                min_xor = a[i] ^ a[j];
    return min_xor;
}

unsigned int solve2(vector<unsigned int> a, int n) {
    sort(a.begin(), a.end());

    unsigned int min_xor = 0xffffffff;
    unsigned int val = 0;
    for (int i = 0; i < n - 1; i++) {
        val = a[i] ^ a[i+1];
        min_xor = min(min_xor, val);
    }

    return min_xor;
}

int main() {
    int T; cin >> T;
    for (int j = 0; j < T; j++) {
        int n; cin >> n;
        vector<unsigned int> array; 
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            array.push_back(tmp);
        }
        cout << solve2(array, array.size()) << endl;
    }
    return 0;
}
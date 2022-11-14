#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> a;

long long calc_med(int i, int n, int k) {
    int j1 = i - 1, j2 = i + 1;
    long long sum = 0;
    for (int count = 0; count < k; count++) {
        int a1 = abs(a[j1] - a[i]), a2 = abs(a[i] - a[j2]);
        if (j2 >= n || (j1 >= 0 && a1 < a2)) {
            sum += a1;
            j1--;
        } else {
            sum += a2;
            j2++;
        }
    }
    return sum;
}

int bin_find_idx(int x, int l, int r) {
    int q = (l + r) / 2;
    
    if (a[q] == x)
        return q;
    
    if (a[q] < x) {
        return bin_find_idx(x, q + 1, r);
    } else {
        return bin_find_idx(x, l ,q - 1);
    }



}

int main() {

    //std::ifstream in("input.txt");
    //std::streambuf *cinbuf = std::cin.rdbuf(); 
    //std::cin.rdbuf(in.rdbuf());

    int n, k;
    cin >> n >> k;
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a.push_back(b[i]);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int idx = bin_find_idx(b[i], 0, n-1);
        cout << calc_med(idx, n ,k) << endl;
    }

    //in.close();   

    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    set<int> str, stolb;

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        str.insert(i);
        stolb.insert(j);
        cout << n * n - n * str.size() - (n - str.size()) * stolb.size() << endl;
    }
    return 0;
}
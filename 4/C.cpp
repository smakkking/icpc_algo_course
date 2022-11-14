#include <iostream>
#include <map>

using namespace std;

typedef int ull_t;
ull_t n;
map<ull_t, unsigned int> a = {};

ull_t func(ull_t k) {
    if (k > n)
        return 0;

    if (a[k] != 0) // map has a key?
        return a[k];

    ull_t tmp;

    if (k % 2 == 1) 
        tmp = 1 + func(2*k);
    else
        tmp = 1 + func(2*k) + func(k + 1);

    a[k] = tmp;
    return tmp;
}

void output_distr() {
    ull_t last_i = n;
    int last_k = 1;
    for (int k = 1; k <= n; k++) {
        int curr;
        for (int i = n; i >= 1; i--) {
            if (a[i] >= k) {
                //cout << "a(" << k << ") = " << i << endl;
                curr = i;
                break;
            }
        }
        if (curr != last_i) {
            cout << last_i << " at [" << last_k << "; " << k - 1 << "]\n";
            last_k = k;
            last_i = curr;
        }
    }
    cout << "1 at [" << n << "]\n";
}

int main() {
    //ull_t k;
    cin >> n; // >> k;
    a[n] = 1;
    //if (k == 1) {
    //    cout << n << endl;
    //    return 0;
    //}
    // нужно как-то оптимизировать память, замечено, что когда i < n / 2, 
    // то например a[n] уже никогда не понадобится,
    // поэтому его можно удалить


    for (ull_t i = n-1; i >= 1; i--) {
        if (i % 2 == 1) {
            a[i] = 1 + (2*i > n ? 0 : a[2*i]);
        } else {
            a[i] = 1 + (2*i > n ? 0 : a[2*i]) + a[i + 1];
        }

        //if (a[i] >= k) {
        //    cout << i << endl;
        //    break;
        //}
        //cout << "f(" << i << ") = " << a[i] << endl;
    }

    cout << "-----\n";

    output_distr();
    
   return 0;
}
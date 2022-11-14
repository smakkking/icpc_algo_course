#include <iostream>
#include <math.h>

using namespace std;

int get_height(long long int a, int k) {
    return int(ceil(log(a * (k - 1) + 1) / log(k)));
}

long long int get_parent(long long int a, int k) {
    if (k == 2) {
        return a / 2;
    }
    // a > 1
    long long int a1 = ((long long int) pow(k, get_height(a, k) - 2) ) / (k - 1) + 1;
    long long int a2 = (long long int) floor((a - ((long long int) pow(k, get_height(a, k) - 1)) / (k - 1) - 1) / k);
    return a1 + a2;
}

long long int get_distanse(long long int a, long long int b, int k) {
    // a > b

    if (k == 1)
        return abs(a - b);

    if (b == 1)
        return get_height(a, k) - 1;

    int i = 0;

    while (get_height(a, k) != get_height(b, k)) {
        i++;
        a = get_parent(a, k);

    }

    while (a != b) {
        i += 2;
        a = get_parent(a, k);
        b = get_parent(b, k);

    }

    return i;
}

void prog() {
    long long int n;
    int k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < q; i++) {
        long long int a, b;
        cin >> a >> b;

        if (a > b)
            cout << get_distanse(a, b, k) << endl;
        else 
            cout << get_distanse(b, a, k) << endl;
    }
}

int main() {
    //cout << get_parent(15, 3) << endl;
    prog();
}
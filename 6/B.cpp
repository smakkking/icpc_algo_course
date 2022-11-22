#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long long find_k_del(long long n, long long k) {
    vector<long long> count;

    for (long long i = 1; i <= sqrt(n); i++)
        if (n % i == 0) {
            count.push_back(i);
            if (i != sqrt(n))
                count.push_back(n / i);
        }
    

    if (count.size() < k)
        return -1;
    else {
        sort(count.begin(), count.end());
        return count[k-1];
    }

}

int main() {
    long long n, k; cin >> n >> k;

    cout << find_k_del(n ,k);
    return 0;
}
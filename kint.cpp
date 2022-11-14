#include <iostream>

using namespace std;

double triade_find(double a[], int l, int r) {
    if ((r-l) / 3 == 0)
        return a[l + 1];
	int m1 = l + (r-l) / 3, m2 = r - (r-l) / 3;
	if (a[m1] < a[m2])
		return triade_find(a, l, m2);
	else
		return triade_find(a, m1, r);
}

int main() {
    const int N = 6;
    double a[N] = {10, 5, 4, 3, 7, 15};
    cout << triade_find(a, 0, N-1);
}
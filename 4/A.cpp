#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int64_t collect_sum(int a[], int b[], int n, int m, int level) {
    int64_t sum = 0;    
    for (int i = 0; i < n; i++)
        if (a[i] < level)
            sum += level - a[i];
    for (int i = 0; i < m; i++)
        if (b[i] > level)
            sum += b[i] - level;
    return sum;
}

int64_t triade_find(vector<int> *s, int l, int r, int a[], int b[], int n, int m) {
    if ((r-l) / 3 == 0)
        return collect_sum(a, b, n, m, (*s)[l + 1]);
	int m1 = l + (r-l) / 3, m2 = r - (r-l) / 3;
	if (collect_sum(a, b, n, m, (*s)[m1]) < collect_sum(a, b, n, m, (*s)[m2]))
		return triade_find(s, l, m2, a, b, n, m);
	else
		return triade_find(s, m1, r, a, b, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    vector<int> u;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
        u.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        b[i] = tmp;
        u.push_back(tmp);
    }
    
    int a_min = INT32_MAX, b_max = 0;
    for (int i = 0; i < n; i++)
        a_min = min(a_min, a[i]);

    for (int i = 0; i < m; i++)
        b_max = max(b_max, b[i]);
           
    sort(u.begin(), u.end());
     cout << triade_find(&u, 0, u.size() - 1, a, b, n, m) << endl;

    return 0;
}


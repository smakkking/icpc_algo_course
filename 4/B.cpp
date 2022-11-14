#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
enum Mode {
    ABOVE, // >=
    UNDER // <=
};
 
int restriction;
int value;
Mode mode;
vector<int> ingridients;
 
int bin_search_near_idx(int l, int r) {
    int q = (l + r) / 2;
 
    //cout << "[" << b[l] << ':' << b[r] << "]" << endl;
 
    if (r - l == 1)
        switch (mode) {
            case ABOVE: {
                return value >= ingridients[r] ? r : (ingridients[l] < restriction ? -1 : l);
            }
            case UNDER: {
                
                return value <= ingridients[l] ? l: (ingridients[r] > restriction ? -1 : r) ;
            }
        }
 
    if (ingridients[q] <= value)
        return bin_search_near_idx(q, r);
    else
        return bin_search_near_idx(l, q);
}
 
 
void prog() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ingridients.push_back(tmp);
    }
 
    sort(ingridients.begin(), ingridients.end());
 
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
 
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }


        restriction = r;
        value = l;
        mode = UNDER;
        int x_idx = bin_search_near_idx(0, n - 1);
 
        restriction = l;
        value = r;
        mode = ABOVE;
        int y_idx = bin_search_near_idx(0, n - 1);
 
        if (x_idx == -1 || y_idx == -1)
            cout << 0 << endl;
        else 
            cout << ingridients[y_idx] - ingridients[x_idx] << endl;
    }
 
}
 
int main() {
    
    //vector<int> a = {1, 6, 10, 40, 51, 52, 80};
    //cout << bin_search_near_idx(a, 0, a.size() - 1, 0, UNDER, 7) << endl;
    //cout << bin_search_near_idx(a, 0, a.size() - 1, 7, ABOVE, 0)<< endl;
    
    prog();
    return 0;
}
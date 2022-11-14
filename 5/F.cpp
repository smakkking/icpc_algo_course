#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <queue>

using namespace std;


int main( ) {
    int N; cin >> N;
    queue<int> prices;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (!prices.empty()) {
            if (prices.front() == tmp / 4 * 3) {
                cout << prices.front() << endl;
                prices.pop();
            } else {
                prices.push(tmp);
            }
            
        } else {
                prices.push(tmp);
        }

    }
    
    return 0;
}
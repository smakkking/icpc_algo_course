#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n; cin >> n;

    stack<int> first;
    int counter = 1;
    vector<string> op;

    for (int i =0; i < n; i++) {
        int tmp;
        cin >> tmp;
        first.push(tmp);
        op.push_back("push");

        if (tmp == counter) {
            while (!first.empty() && first.top() == counter) {
                op.push_back("pop");
                counter++;
                first.pop();
            }
        }         
    }

    if (first.empty()){
        for (auto it = op.begin(); it != op.end(); it++) 
            cout << *it << endl;
    } else {
        cout << "impossible\n";
    }

    return 0;
}
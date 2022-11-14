#include <iostream>
#include <stack>


using namespace std;

const int N = 4 * 100000;

class Stack {
    stack<int> main;
    stack<int> max_sub;
    int st_max;
public:
    Stack() {
        st_max = -1;
    }
    void push(int v) {
        st_max = max(st_max, v);
        main.push(v);
        max_sub.push(st_max);
    }

    int get_max() {
        return max_sub.top();
    }
    void pop() {
        main.pop();
        max_sub.pop();
        if (max_sub.empty())
            st_max = -1;
        else
            st_max = max_sub.top();
    }

};

int main() {
    int q; cin >> q;

    string operation;
    int v;
    Stack st;

    for (int i = 0; i < q; i++) {
        cin >> operation;
        if (operation == "push") {
            cin >> v;
            st.push(v);
        } else if (operation == "max") {
            cout << st.get_max() << endl;
        } else {
            st.pop();
        }
    }
}
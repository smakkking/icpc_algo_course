#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool is_correct(string s) {
    // 1 - [], 2 - {}, 3 - ()
    map<char, char> bracket{
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.empty())
                return false;
            if (bracket[s[i]] != st.top())
                return false;
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    return st.empty();
}

int main() {
    string s; 
    getline(cin, s, '\n');
    map<int, int> idx;

    stack<int> type1, type2, type3;

    if (is_correct(s)) {
        for (int i = 0; i < s.length(); i++) {
        switch (s[i]){
            case '[':
                type1.push(i);
            break;
            case ']':
                idx[i] = type1.top();
                idx[type1.top()] = i;
                type1.pop();
            break;

            case '{':
                type2.push(i);
            break;
            case '}':
                idx[i] = type2.top();
                idx[type2.top()] = i;
                type2.pop();
            break;

            case '(':
                type3.push(i);
            break;
            case ')':
                idx[i] = type3.top();
                idx[type3.top()] = i;
                type3.pop();
            break;
        }  
    }
    for (int i = 0; i < s.length(); i++) {
            cout << idx[i] << " ";
        }
    } else 
        cout << -1 << endl;
}
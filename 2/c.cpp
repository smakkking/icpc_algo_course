#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isNumber(const string& s)
{
    for (char const ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

void read_reverse_polish_notation() {
    string lexeme;
    stack<int> numbers;

    while (cin >> lexeme)
        if (isNumber(lexeme)) {
            numbers.push(stoi(lexeme));
        } else {
            int a, b;
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();

            if (lexeme == "+")
                numbers.push(b + a);
            else if (lexeme == "-")
                numbers.push(b - a);
            else if (lexeme == "*")
                numbers.push(b * a);
            else if (lexeme == "/")
                numbers.push(b / a);
        }

    cout << numbers.top() << endl;
}

int main() {
    read_reverse_polish_notation();
    return 0;
    
}
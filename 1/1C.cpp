#include <iostream>
#include <string.h>
#include <map>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";


class CycledList {
    int idx;
    bool forward;
    map<const char, int> letter_count;
    
    void safe_usage(const char symb) {
        if (symb == '+') {
            idx++;
            if (idx == alphabet.length()) 
                idx = 0;
        } else if (symb == '-') {
            idx--;
            if (idx < 0) 
                idx = alphabet.length() - 1;
        }   
    }

public:
    CycledList() {
        idx = 0;
        forward = true;
        for (int i = 0; i < alphabet.length(); i++) {
            letter_count[alphabet[i]] = 0;
        }
    }
    void change_direction() {
        if (forward) {
            safe_usage('-');
            safe_usage('-');
        }
        else {
            safe_usage('+');
            safe_usage('+');
        }
            
        forward = !forward;
    }
    
    void next_step() {
        letter_count[alphabet[idx]]++;
        if (forward)
            safe_usage('+');    
        else
            safe_usage('-');
    }
    void do_n_steps(int n) {
        for (int i = 0; i < alphabet.length(); i++) {
            letter_count[alphabet[i]] += n / alphabet.length();
        }

        for (int i = 0; i < n % alphabet.length(); i++)
            next_step();
    }
    int give_letter_count(const char x) {
        return letter_count[x];
    }

};

void prog() {
    int q, n_new, n_old = 0;
    string s_in;
    CycledList machine;

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s_in >> n_new;
        machine.do_n_steps(n_new - n_old);
        n_old = n_new;

        if (s_in == "rev") {
            machine.change_direction();
        }
        if (s_in == "cnt") {
            char x;
            cin >> x;
            cout << machine.give_letter_count(x) << endl;
        }
    }
}

int main() {
    prog();
}
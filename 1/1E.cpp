#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

bool is_anagramma(const string *s, int root_a, int root_b, int idx2, int len) {
    int word_a = 0, word_b = 0;

    for (int i = idx2; i < idx2 + len; i++)
        if ((*s)[i] == 'a')
            word_a++;
        else
            word_b++;

    return root_a == word_a && root_b == word_b;
}

int alg(const string *s_in) {
    int n = (*s_in).length();
    int root_a = 0, root_b = 0;

    bool need_to_check[n];

    for (int k = 1; k <= n / 2; k++) {
        if (n % k == 0)
            need_to_check[k-1] = true;
    }

    for (int k = 1; k <= n / 2; k++) {
        if ((*s_in)[k-1] == 'a') 
                root_a++;
            else
                root_b++;
        if (need_to_check[k-1]) {
            bool flag = true;
            for (int i = 1; flag && i < n / k; i++)
                flag = flag && is_anagramma(s_in, root_a, root_b, i * k, k);
            
            if (flag)
                return k;
            else {
                for (int i = 2; i * k < n; i *= 2)
                    need_to_check[i * k - 1] = false;
            }
        }
    }
    return -1;
}

int main() {
    string s_in;

   /* 
    std::ifstream in("in.txt");
std::streambuf *cinbuf = std::cin.rdbuf(); 
std::cin.rdbuf(in.rdbuf());

*/
    cin >> s_in;
    cout << alg(&s_in) << endl;
    return 0;
    
}
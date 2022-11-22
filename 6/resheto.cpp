#include <iostream>

using namespace std;

const int N = 100;
bool is_prime[N];

void resheto() {
    for (int i = 2; i * i <= N; i++) {
        for (int k = 2; k * i <= N; k++)
            is_prime[k * i - 1] = true;
    }
}

int main() {
    resheto();
    for (int i = 0; i < N; i++)
        if (!is_prime[i] && i != 0)
            cout << i + 1 <<", ";
    return 0;
}
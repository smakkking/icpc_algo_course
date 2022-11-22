#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int current_color = 1;
    int arr[n];

    for (int k = 2; k < n + 1; k++) {
        for (int i = 1; k * i <= n + 1; i++)
            arr[k*i - 2] = current_color;
        current_color++;
    }
    for (int k = 0; k < n-1; k++)
        cout << 1 << " ";
    
    return 0; 
}
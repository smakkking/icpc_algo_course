#include <iostream>

using namespace std;

bool check(int arr[], int n) {
    for (int i = 2; i <= n+1; i++)
        for (int j = 2; j < i; j++)
            if (i % j == 0 && arr[i - 2] == arr[j-2]) {
                cout << i << "   " << j;
                return false; 
            }
    return true;
}

int main() {
    for (int n = 2; n < 100; n++) {

        int current_color = 1;
        int arr[n];

        for (int k = 0; k < n; k++)
            arr[k] = 0;

        for (int k = 2; k <= n + 1; k++) {
            int local_col = arr[k - 2] == 0 ? current_color : arr[k - 2];
            for (int i = 1; k * i <= n + 1; i++) {
                if (arr[k*i - 2] == 0)
                    arr[k*i - 2] = local_col++;
            }
            current_color = arr[k - 2];
        }
        //for (int k = 0; k < n; k++)
          //  cout << arr[k] << " ";
        
        if (!check(arr, n)) {
            cout << n; break;
        }
    }
    return 0; 
}
#include <iostream>

using namespace std;

const int N = 1000;

struct Apple {
    int growth;
    int disgrowth;
};

int argmax_apple(Apple *arr, int n, int s, bool *table_eated) {
    static bool mode = true;

    if (mode) {
        int max = -100000, i_max = -1;
        for (int i = 0; i < n; i++)
            if (arr[i].disgrowth + s > 0 && !table_eated[i])
                if (arr[i].disgrowth + arr[i].growth >= max) {
                    max = arr[i].disgrowth + arr[i].growth;
                    i_max = i;
                }
        if (max < 0) {
            mode = false;
            int min = 100000, i_min = -1;

            for (int i = 0; i < n; i++)
                if (arr[i].disgrowth + s > 0 && !table_eated[i])
                    if (arr[i].disgrowth < min) {
                        min = arr[i].disgrowth;
                        i_min = i;
                    }
            return i_min;
        }
        return i_max;
    } else {
        int min = 100000, i_min = -1;

        for (int i = 0; i < n; i++)
            if (arr[i].disgrowth + s > 0 && !table_eated[i])
                if (arr[i].disgrowth < min) {
                    min = arr[i].disgrowth;
                    i_min = i;
                }
        return i_min;
    }
    
}

int alg(Apple *arr, int n, int s, int *order) {
    bool table_eated[N];
    for (int i = 0; i < N; i++)
        table_eated[i] = false;

    int k = 0;
    while (k < n) {
        int i = argmax_apple(arr, n, s, table_eated);
        if (i == -1)
            return -1;
        order[k] = i + 1;
        s += arr[i].growth + arr[i].disgrowth;
        table_eated[i] = true;
        k++;
    }
    return 0;
}

int main() {
    Apple arr[N];

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].disgrowth >> arr[i].growth;
        arr[i].disgrowth = -arr[i].disgrowth;
    }

    int order[N];

    int res = alg(arr, n, s, order);
    if (res == -1)
        cout << -1;
    else {
        for (int i = 0; i < n; i++)
            cout << order[i] << " ";
    }

    return 0;
}
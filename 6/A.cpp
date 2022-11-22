#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;
typedef unsigned long long ull;

struct par {
    ull v1, v2;
};

ull NOD(ull a , ull b)
{
    while(a!=0 and b!=0)
    {
        if(a>b)
        {
            a=a%b;
        }
        else 
        {
            b=b%a;
        }
        
    }
    return (a+b);
}

int main() {
    int n; cin >> n;
    par data[n];

    ull prod[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i].v1;
        cin >> data[i].v2;
        prod[i] = data[i].v1 * data[i].v2;
    }

    ull res = prod[0];
    for (int i = 1; i < n; i++)
        res = NOD(prod[i], res);

    if (res == 1)
        cout << -1;
    else
    {
        bool flag = false;
        for (int i = 0; i < n && !flag; i++) {
            ull v1 = NOD(res, data[i].v1);
            ull v2 = NOD(res, data[i].v2);
            
            if (v1 != res && v1 != 1 && v2 != res && v2 != 1) {
                cout << min(v1, v2);
                flag = true;
                break;
            } else if (v1 != res && v1 != 1) {
                cout << v1;
                flag = true;
                break;
            } else if (v2 != res && v2 != 1) {
                cout << v2;
                flag = true;
                break;
            }
        }
        if (!flag) 
            cout << res;
    }
    

    return 0;
}
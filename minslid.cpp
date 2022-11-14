#include <iostream>
#include <stack>

using namespace std;

class StackMinSupport {
	virtual void push(int v) = 0;
	virtual int get_max() = 0;
	virtual void pop() = 0;
	virtual bool empty() = 0;
};

class StackMaxSupport {
    stack<int> main;
    stack<int> max_sub;
    int st_max;
public:
    StackMaxSupport() {
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
    bool empty() {
        return main.empty();
    }
};

class SlidingWindowMin {
	StackMaxSupport L;
	std::stack<int> R;
	int R_max;
public:
	SlidingWindowMin() {
		R_max = 0;
	}
	void push_back(int v) {
		R.push(v);
		R_max = max(R_max, v);
	}
	void pop_front() {
		if (L.empty()) {
			while (!R.empty()) {
				L.push(R.top());
				R.pop();
			}
			R_max = 0;
		} 
        L.pop();
	}
	int get_max() {
        if (L.empty()) {
            return R_max;
        } else 
		    return max(R_max, L.get_max());
	}
};


int main() {
    int n; cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int m; cin >> m;
    
    SlidingWindowMin st;
    for (int i = 0; i < m; i++)
        st.push_back(a[i]);
    cout << st.get_max() << " ";
    for (int i = m; i < n; i++) {
        st.pop_front();  
        st.push_back(a[i]);
        cout << st.get_max() << " ";
    }
    return 0;
}
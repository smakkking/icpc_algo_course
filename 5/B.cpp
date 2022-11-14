#include <iostream>
#include <map>
#include <list>
#include <set>

using namespace std;

struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
};

class List {
    public:
    Node *head;

    List() {
        head = new Node;
        head->next = head->prev = NULL;
    }
    void del_node(Node *cur) {
        if (cur->prev != NULL) {
            cur->prev->next = cur->next;
        }
        if (cur->next != NULL) {
            cur->next->prev = cur->prev;
        }
        //delete cur;
    }
    Node* add_node(int v) {
        Node *tmp = new Node;
        tmp->val = v;

        if (head->next != NULL) {
            tmp->next = head->next;
            head->next->prev = tmp;

        tmp->prev = head;
        head->next = tmp;

        } else {
            head->next = tmp;
            tmp->prev = head;
            tmp->next = NULL;
        }

        return tmp;
    }
    ~List() {
        delete head;
    }
};

int main( ) {
    // мапа, по значению в элементе списка, чтобы быстро искать максимум
    map<int, Node*> index;
    map<int, bool> steps;
    List base;
    
    int n, k;
    cin >> n >> k;
    int true_order[n];

    for (int i = 0; i < n; i++) {
        cin >> true_order[i];
        index[-true_order[i]] = base.add_node(true_order[i]);
        steps[i+1] = false;
    }

    bool s = true;
    while (!index.empty()) {
        auto max_elem = index.begin();
        
        Node *center = max_elem->second;
        Node *first_to_delete, *last_to_delete;
        first_to_delete = last_to_delete = center;

        for (int i = 0; i < k && first_to_delete->prev != base.head; i++) {
            first_to_delete = first_to_delete->prev;
        }
        for (int i = 0; i < k && last_to_delete->next != NULL; i++) {
            last_to_delete = last_to_delete->next;
        }

        for (Node *del_elem = first_to_delete; del_elem != last_to_delete->next; del_elem = del_elem->next) {
            steps[del_elem->val] = s;
            index.erase(index.find(-del_elem->val));
            base.del_node(del_elem);
        }
        s = !s;
    }

    for (int i = 0; i < n; i++) {
        cout << (steps[true_order[i]] ? "1" : "2");
    }
    cout << endl;


    return 0;
}
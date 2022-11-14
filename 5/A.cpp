#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    long long val;
    int group_count;
    int ord;
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
        delete cur;
    }
    Node* add_node(long long v) {
        Node *tmp = new Node;
        tmp->group_count = 1;
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


int main() {
    int n = 0; cin >> n;
    int tmp; cin >> tmp;
    List base;

    map<pair<int, int>, Node*> index;
    Node *cur = base.add_node(tmp);

    int ord = 0;
    
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (cur->val == tmp) {
            cur->group_count++;
        }
        else {
            cur->ord = ord;
            index[make_pair(-cur->group_count, ord++)] = cur;
            cur = base.add_node(tmp);
        }
    }
    cur->ord = ord;
    index[make_pair(-cur->group_count, ord++)] = cur;

    int steps = 0;
    while (!index.empty()) {
        auto it = index.begin(); // ищем итератор элемента в мапе, у кот самое большое количесвто и самая левая позиция

        Node *del_elem = it->second;
        // если рядом с элементом в списке есть элементы из одинаковых групп, то производим склеивание
        if (del_elem->prev != NULL && del_elem->next != NULL && del_elem->prev->val == del_elem->next->val) {
            // все данные переносим в элемент перед удаляемым
            // не забываем сделать перезапись в дереве и списке
            index.erase(index.find(make_pair(-del_elem->prev->group_count, del_elem->prev->ord)));
            del_elem->prev->group_count += del_elem->next->group_count;
            index[make_pair(-del_elem->prev->group_count, del_elem->prev->ord)] = del_elem->prev;


            // не забываем удалить след за "макс" из дерева и списка
            index.erase(index.find(make_pair(-del_elem->next->group_count, del_elem->next->ord)));
            base.del_node(del_elem->next);
        } 
        // удаляем "макс" элемент
        index.erase(it->first);
        base.del_node(del_elem);
        steps++;
    }

    cout << steps;
    return 0;
}
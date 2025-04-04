#include <iostream>

using namespace std;

struct queue {
    int data;
    queue *next;
};

void push_back(queue *&h, queue *&t, int x) {
    queue *r = new queue;
    r->data = x;
    r->next = nullptr;
    if (h == nullptr && t == nullptr) {
        t = r;
        h = r;
    } else {
        t->next = r;
        t = r;
    }
}

int pop_front(queue *&h, queue *&t) {
    queue *r = h;
    int i = r->data;
    h = h->next;
    if (h == nullptr) {
        t = nullptr;
    }
    delete r;
    return i;
}

int main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "Rus");
    queue *h = nullptr;
    queue *t = nullptr;
    queue *h1 = nullptr;
    queue *t1 = nullptr;
    int n, cur, minn = INT_MAX, l_odd;
    bool is_odd = false;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите числа (через пробел): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push_back(h, t, x);
    }
    while (h != nullptr) {
        cur = pop_front(h, t);
        push_back(h1, t1, cur);
        if (cur < minn) minn = cur;
        if (cur % 2 != 0) {
            l_odd = cur;
            is_odd = true;
        }
    }
    while (h1 != nullptr) push_back(h, t, pop_front(h1, t1));

    if (is_odd) {
        while (h != nullptr) {
            cur = pop_front(h, t);
            push_back(h1, t1, cur);
            if (cur == minn) {
                push_back(h1, t1, l_odd);
            }
        }
        while (h1 != nullptr) push_back(h, t, pop_front(h1, t1));
        
        while (h != nullptr) {
            cout << pop_front(h, t) << ' ';
        }
        cout << endl;
    }
    else {
        cout << "Нет отрицательных чисел" << endl;
    }
}
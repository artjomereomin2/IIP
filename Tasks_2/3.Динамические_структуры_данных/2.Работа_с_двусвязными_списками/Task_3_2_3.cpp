#include <iostream>
#include <cmath>

using namespace std;

struct list {
    int data;
    list *next;
    list *prev;
};

void push_back(list *&h, list *&t, int x) {
    list *r = new list;
    r->data = x;
    r->next = nullptr;
    if (h == nullptr and t == nullptr) {
        r->prev = nullptr;
        h = r;
    } else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list *h, list *t) {
    list *p = h;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

list *find(list *&h, list *&t, int x) {
    list *p = h;
    while (p != nullptr) {
        if (p->data == x) break;
        p = p->next;
    }
    return p;
}

void insert_after(list *&h, list *& t, list *&r, int x) {
    list *p = new list;
    p->data = x;
    if (r == t) {
        p->next = nullptr;
        p->prev = r;
        r->next = p;
        t = p;
    } else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void del_node(list *&h, list *&t, list *r) {
    if (r == h and r == t) {
        int x = r->data;
        h = nullptr;
        t = nullptr;
    } else if (r == h) {
        h = h->next;
        h->prev = nullptr;
    } else if (r == t) {
        t = t->prev;
        t->next = nullptr;
    } else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void delete_list(list *&h, list *&t) {
    while (h != nullptr) {
        list *p = h;
        h = h->next;
        h->prev = nullptr;
        delete p;
    }
}

void swap_list(list *&h, list *&t, list *r1, list *r2) {
    list *r1_p = r1->prev;
    list *r2_n = r2->next;
    r2->prev = r1_p;
    r2->next = r1;
    r1->prev = r2;
    r1->next = r2_n;
    if (r1 != h) r1_p->next = r2;
    if (r2 != t) r2_n->prev = r1;
    if (r1 == h) h = r2;
    if (r2 == t) t = r1;
}

void bubble_sort(list *&h, list *&t) {
    list *i = h;
    while (i != nullptr) {
        list *j = t;
        while (j != i) {
            if (j->prev->data > j->data) {
                swap_list(h, t, j->prev, j);
                j = j->next;
                if (j == i) i = i->prev;
            }
            j = j->prev;
        }
        i = i->next;
    }
}

bool is_prime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0 or n == 1) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "Rus");
    list *h = nullptr;
    list *t = nullptr;
    int n, x, d;
    cout << "¬ведите n: ";
    cin >> n;
    cout << "¬ведите числа (через пробел): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push_back(h, t, x);
    }

    bubble_sort(h, t);

    print(h, t);
}
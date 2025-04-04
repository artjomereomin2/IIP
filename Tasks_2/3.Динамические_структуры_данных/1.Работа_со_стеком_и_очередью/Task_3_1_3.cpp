#include <iostream>
#include <cmath>

using namespace std;

struct stack {
    int data;
    stack *next;
};

void push_front(stack *&h, int x) {
    stack *r = new stack;
    r->data = x;
    r->next = h;
    h = r;
}

int pop_front(stack *&h) {
    stack *r = h;
    int i = r->data;
    h = h->next;
    delete r;
    return i;
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
    stack *h = nullptr;
    stack *h1 = nullptr;
    int n, x, d;
    cout << "¬ведите n: ";
    cin >> n;
    cout << "¬ведите числа (через пробел): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push_front(h, x);
    }
    cout << "¬ведите d: ";
    cin >> d;

    int cur;
    while (h != nullptr) {
        cur = pop_front(h);
        if (is_prime(cur)) {
            push_front(h1, d);
            push_front(h1, cur);
        } else {
            push_front(h1, cur);
        }
    }
    /*while (h1 != nullptr) {
        cur = pop_front(h1);
        push_front(h, cur);
    }
    
    while (h != nullptr) {
        push_front(h1, pop_front(h));
    }*/
    while (h1 != nullptr) {
        cout << pop_front(h1) << ' ';
    }
    cout << endl;
    
}
#include <iostream>
#include <string>

using namespace std;

struct stack {
    char data;
    stack *next;
};

void push_front(stack *&h, char x) {
    stack *r = new stack;
    r->data = x;
    r->next = h;
    h = r;
}

char pop_front(stack *&h) {
    stack *r = h;
    char i = r->data;
    h = h->next;
    delete r;
    return i;
}

int main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "Rus");
    stack *h = nullptr;
    stack *h1 = nullptr;
    string consonant = "bcdfghjklmnpqrstvwxz";
    int n;
    char x;
    cout << "¬ведите n: ";
    cin >> n;
    cout << "¬ведите буквы (через пробел): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push_front(h, x);
    }
    
    while (h != nullptr) {
        push_front(h1, pop_front(h));
    }
    char cur = pop_front(h1);
    while (consonant.find(cur) == string::npos) {
        push_front(h, cur);
        cur = pop_front(h1);
    }
    push_front(h, cur);
    push_front(h, '!');
    

    while (h != nullptr) {
        push_front(h1, pop_front(h));
    }
    while (h1 != nullptr) {
        cout << pop_front(h1) << ' ';
    }
    cout << endl;
}
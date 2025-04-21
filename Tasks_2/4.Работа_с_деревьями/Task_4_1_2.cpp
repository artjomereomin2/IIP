#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;

HANDLE outp = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbInfo;

struct tree {
    int data;
    tree *left;
    tree *right;
    tree *parent;
};

void max_height(tree *x, short &max, short deepness = 1) { // требует проверки на существование корн€
    if (deepness > max) max = deepness;
    if (x->left) max_height(x->left, max, deepness + 1);
    if (x->right) max_height(x->right, max, deepness + 1);
}
bool isSizeOfConsoleCorrect(const short &width, const short &height) {
    GetConsoleScreenBufferInfo(outp, &csbInfo);
    COORD szOfConsole = csbInfo.dwSize;
    if (szOfConsole.X < width && szOfConsole.Y < height) cout << "Please increase the height and width of the terminal. ";
    else if (szOfConsole.X < width) cout << "Please increase the width of the terminal. ";
    else if (szOfConsole.Y < height) cout << "Please increase the height of the terminal. ";
    if (szOfConsole.X < width || szOfConsole.Y < height) {
        cout << "Size of your terminal now: " << szOfConsole.X << ' ' << szOfConsole.Y
             << ". Minimum required: " << width << ' ' << height << ".\n";
        return false;
    }
    return true;
}

void print_helper(tree *x, const COORD pos, const short offset) {
    SetConsoleCursorPosition(outp, pos);
    cout << setw(offset + 1) << x->data;
    if (x->left) print_helper(x->left, {pos.X, short(pos.Y + 1)}, offset >> 1);
    if (x->right) print_helper(x->right, {short(pos.X + offset), short(pos.Y + 1)}, offset >> 1);
}
void print(tree *root) {
    if (root) {
        short max = 1;
        max_height(root, max);
        short width = 1 << max + 1, max_w = 128; // вычисл€ем ширину вывода
        if (width > max_w) width = max_w;
        while (!isSizeOfConsoleCorrect(width, max)) system("pause");
        for (short i = 0; i < max; ++i) cout << '\n'; // резервируем место дл€ вывода
        GetConsoleScreenBufferInfo(outp, &csbInfo); // получаем данные
        COORD endPos = csbInfo.dwCursorPosition;
        print_helper(root, {0, short(endPos.Y - max)}, width >> 1);
        SetConsoleCursorPosition(outp, endPos);
    }
}

tree *node(int x) {
    tree *r = new tree;
    r->data = x;
    r->left = nullptr;
    r->right = nullptr;
    r->parent = nullptr;
    return r;
}

bool insert(tree *&tr, int x) {
    tree *n = node(x);
    if (tr == nullptr) {
        tr = n;
        return true;
    }
    tree *y = tr;
    while (true) {
        if (n->data > y->data) {
            if (y->right != nullptr) {
                y = y->right;
            } else {
                n->parent = y;
                y->right = n;
                return true;
            }
        } else if (n->data < y->data) {
            if (y->left != nullptr) {
                y = y->left;
            } else {
                n->parent = y;
                y->left = n;
                return true;
            }
        } else return false;
    }
}

tree *find (tree *tr, int x) {
    if (tr == nullptr or tr->data == x) return tr;
    if (x > tr->data) {
        return find(tr->right, x);
    } else {
        return find(tr->left, x);
    }
}

void result (tree *tr, bool &iss) {
    if (tr->left) result(tr->left, iss);
    if (tr->right) result(tr->right, iss);
    if (!tr->left and !tr->right and tr->data % 2 != 0) {
        cout << tr->data << ' ';
        iss = false;
    }
}

int main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "Rus");
    int n, x;
    tree *root = nullptr;
    cout << "¬ведите n: ";
    cin >> n;

    cout << "¬ведите данные дл€ дерева (через пробел): ";
    cin >> x;
    root = node(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        insert(root, x);
    }
    print(root);

    /*int check = 1;
    srand(time(NULL));
    while (check) {
        x = rand() % 10;
        root = node(x);
        for (int i = 1; i < n; i++) {
            x = rand() % 10;
            while (!insert(root, x)) x = rand() % 10;
        }
        print(root);
        cout << "≈сли вас устраивает дерево, введите 0, иначе введите любое число: ";
        cin >> check;
        if (check != 1 && check != 0) check = 1;
    }*/

    bool iss = true;
    result(root, iss);
    if (iss) cout << "Ќет нечетных листьев";
    cout << endl;
    return 0;
}
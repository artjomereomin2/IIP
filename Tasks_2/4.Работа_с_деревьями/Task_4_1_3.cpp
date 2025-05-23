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

void max_height(tree *x, short &max, short deepness = 1) { // ������� �������� �� ������������� �����
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
        short width = 1 << max + 1, max_w = 128; // ��������� ������ ������
        if (width > max_w) width = max_w;
        while (!isSizeOfConsoleCorrect(width, max)) system("pause");
        for (short i = 0; i < max; ++i) cout << '\n'; // ����������� ����� ��� ������
        GetConsoleScreenBufferInfo(outp, &csbInfo); // �������� ������
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

tree *Min(tree *tr){//����� min
    if (! tr->left) return tr;//��� ������ �������
    else return Min(tr->left);//���� �� ����� ����� �� �����
}

tree *Max(tree *tr){//����� max
    if (! tr->right) return tr;//��� ������� �������
    else return Max(tr->right);//���� �� ������ ����� �� �����
}

tree *Next(tree*tr, int x){//����� ����������
    tree* n = find( tr , x);
    if (n->right)//���� ���� ������ �������
        return Min(n->right);//min �� ������ �����
    tree *y = n->parent; //��������
    while (y && n == y->right){//���� �� ����� �� ����� ��� ���� - ������ �������
        n = y;//���� ����� �� ������
        y = y->parent;
    }
    return y;//���������� ��������
}

void Delete(tree *&tr, tree *v){//�������� ����
    tree *p = v->parent;
    if (!p && !v->left && !v->right) tr = NULL; //������ �������� ���� ����
    else if (!v->left && !v->right) {//���� ��� �����
        if (p->left == v) //��������� � �������� ������ �� NULL
            p->left = NULL;
        if (p->right == v)
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right){//���� ������ ���� �������
        if (!p) { //���� ������� ������, � �������� 1 �������
            if (!v->left){ //���� ���� ������ �������
                tr = v->right; //�� ���������� ������
                v->parent = NULL;
            }
            else { //���������� ��� ������
                tr = v->left;
                v->parent = NULL;
            }
        }
        else {
            if (!v->left){//���� ���� ������ �������
                if (p->left == v) //���� ��������� ���� ���. ����� ��������
                    p->left = v->right; //������� ���������� ���� ���������� ����� �������� ������ "����"
                else
                    p->right = v->right; ////������� ���������� ���� ���������� ������ �������� ������ "����"
                v->right->parent = p; //��������� ������� ���������� ��� "���"
            }
            else{//���������� ��� ������ �������
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
            delete v;
        }
    }
    else{//���� ��� �������
        tree *succ = Next(tr, v->data);//��������� �� ��������� �����
        v->data = succ->data; //����������� ��������
        if (succ->parent->left ==succ){//���� succ ����� �������
            succ->parent->left = succ->right; //��� ������ ������� ���������� ����� �������� ������ "����"
            if (succ->right) //���� ���� ������� ����������
                succ->right->parent = succ->parent; //��� ��������� ���������� "���"
        }
        else {//���������� ���� succ - ����sq �������
            succ->parent->right = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        delete succ;
    }
}

int main()
{
	//system("chcp 1251");
	setlocale(LC_ALL, "Rus");
    int n, x, check = 1;
    tree *root;
    cout << "������� n (< 10): ";
    cin >> n;
    
    cout << "������� ������ ��� ������ (����� ������): ";
    cin >> x;
    root = node(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        insert(root, x);
    }
    print(root);

    /*cout << "������� ������ ��� ������ (����� ������): ";
    srand(time(NULL));
    while (check) {
        x = rand() % 10;
        //cin >> x;
        root = node(x);
        for (int i = 1; i < n; i++) {
            //cin >> x;
            x = rand() % 10;
            while (!insert(root, x)) x = rand() % 10;
        }
        print(root);
        cout << "���� ��� ���������� ������, ������� 0, ����� ������� ����� �����: ";
        cin >> check;
    }*/

    cout << "������� ��������� ����: ";
    cin >> x;
    tree *cur = find(root, x);
    if (!cur) cout << "��-�� ��� � ������\n";
    else if (!cur->parent) cout << "��� ��������\n";
    else {
        tree *p = cur->parent;
        if (!p->parent) cout << "��� ����\n";
        else {
            Delete(root, p->parent);
        }
    }
    print(root);
    return 0;
}
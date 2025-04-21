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

void max_height(tree *x, short &max, short deepness = 1) { // требует проверки на существование корня
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
        short width = 1 << max + 1, max_w = 128; // вычисляем ширину вывода
        if (width > max_w) width = max_w;
        while (!isSizeOfConsoleCorrect(width, max)) system("pause");
        for (short i = 0; i < max; ++i) cout << '\n'; // резервируем место для вывода
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

tree *Min(tree *tr){//поиск min
    if (! tr->left) return tr;//нет левого ребенка
    else return Min(tr->left);//идем по левой ветке до конца
}

tree *Max(tree *tr){//поиск max
    if (! tr->right) return tr;//нет правого ребенка
    else return Max(tr->right);//идем по правой ветке до конца
}

tree *Next(tree*tr, int x){//поиск следующего
    tree* n = find( tr , x);
    if (n->right)//если есть правый ребенок
        return Min(n->right);//min по правой ветке
    tree *y = n->parent; //родитель
    while (y && n == y->right){//пока не дошли до корня или узел - правый ребенок
        n = y;//идем вверх по дереву
        y = y->parent;
    }
    return y;//возвращаем родителя
}

void Delete(tree *&tr, tree *v){//удаление узла
    tree *p = v->parent;
    if (!p && !v->left && !v->right) tr = NULL; //дерево содержит один узел
    else if (!v->left && !v->right) {//если нет детей
        if (p->left == v) //указатель у родителя меняем на NULL
            p->left = NULL;
        if (p->right == v)
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right){//если только один ребенок
        if (!p) { //если удаляем корень, у которого 1 ребенок
            if (!v->left){ //если есть правый ребенок
                tr = v->right; //он становится корнем
                v->parent = NULL;
            }
            else { //аналогично для левого
                tr = v->left;
                v->parent = NULL;
            }
        }
        else {
            if (!v->left){//если есть правый ребенок
                if (p->left == v) //если удаляемый узел явл. левым ребенком
                    p->left = v->right; //ребенок удаляемого узла становится левым ребенком своего "деда"
                else
                    p->right = v->right; ////ребенок удаляемого узла становится правым ребенком своего "деда"
                v->right->parent = p; //родителем ребенка становится его "дед"
            }
            else{//аналогично для левого ребенка
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
            delete v;
        }
    }
    else{//есть оба ребенка
        tree *succ = Next(tr, v->data);//следующий за удаляемым узлом
        v->data = succ->data; //присваиваем значение
        if (succ->parent->left ==succ){//если succ левый ребенок
            succ->parent->left = succ->right; //его правый ребенок становится левым ребенком своего "деда"
            if (succ->right) //если этот ребенок существует
                succ->right->parent = succ->parent; //его родителем становится "дед"
        }
        else {//аналогично если succ - правsq ребенок
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
    cout << "Введите n (< 10): ";
    cin >> n;
    
    cout << "Введите данные для дерева (через пробел): ";
    cin >> x;
    root = node(x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        insert(root, x);
    }
    print(root);

    /*cout << "Введите данные для дерева (через пробел): ";
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
        cout << "Если вас устраивает дерево, введите 0, иначе введите любое число: ";
        cin >> check;
    }*/

    cout << "Введите поисковый узел: ";
    cin >> x;
    tree *cur = find(root, x);
    if (!cur) cout << "Эл-та нет в дереве\n";
    else if (!cur->parent) cout << "Нет родителя\n";
    else {
        tree *p = cur->parent;
        if (!p->parent) cout << "Нет деда\n";
        else {
            Delete(root, p->parent);
        }
    }
    print(root);
    return 0;
}
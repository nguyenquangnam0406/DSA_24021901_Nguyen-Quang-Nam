#define main main_cu
#include "List.cpp"
#undef main

struct Stack {
    List L;
};

void khoiTaoStack(Stack &S) { khoiTao(S.L); }

bool isEmpty(Stack S) { return S.L.n == 0; }

void push(Stack &S, int x) { chenCuoi(S.L, x); }

void pop(Stack &S) { xoaCuoi(S.L); }

int top(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    return S.L.a[S.L.n - 1];
}

int main() {
    Stack S;
    khoiTaoStack(S);

    push(S, 10);
    push(S, 20);
    push(S, 30);
    cout << "Top: " << top(S) << endl;   // 30
    pop(S);
    cout << "Top: " << top(S) << endl;   // 20

    duyetXuoi(S.L);                      // 10 20
    return 0;
}

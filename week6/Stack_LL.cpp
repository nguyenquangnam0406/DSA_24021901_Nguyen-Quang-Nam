#define main main_cu
#include "Linked_List.cpp"
#undef main

//Stack bọc lại một con trỏ head của danh sách liên kết
struct Stack {
    Node* head;
};

void khoiTaoStack(Stack &S) { S.head = NULL; }

bool isEmpty(Stack S) { return S.head == NULL; }

void push(Stack &S, int x) { chenDau(S.head, x); }

void pop(Stack &S) { xoaDau(S.head); }

int top(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack rong!" << endl;
        return -1;
    }
    return S.head->data;
}

int main() {
    Stack S;
    khoiTaoStack(S);

    int chon, x;

    do {
        cout << "\n===== MENU STACK (LinkedList) =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Hien thi stack\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                cout << "Nhap gia tri: ";
                cin >> x;
                push(S, x);
                break;

            case 2:
                pop(S);
                break;

            case 3:
                if (!isEmpty(S))
                    cout << "Top: " << top(S) << endl;
                else
                    cout << "Stack rong!" << endl;
                break;

            case 4:
                duyetXuoi(S.head);
                break;

            case 0:
                cout << "Ket thuc!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (chon != 0);

    xoaDanhSach(S.head);
    return 0;
}

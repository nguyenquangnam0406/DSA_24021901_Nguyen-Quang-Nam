#define main main_cu
#include "List.cpp"
#undef main

struct Queue {
    List L;
};

void khoiTaoQueue(Queue &Q) { khoiTao(Q.L); }

bool isEmpty(Queue Q) { return Q.L.n == 0; }

void enqueue(Queue &Q, int x) { chenCuoi(Q.L, x); }

void dequeue(Queue &Q) { xoaDau(Q.L); }

void front(Queue Q) {
    if (isEmpty(Q)) { cout << "Queue rong!" << endl; return; }
    truyCap(Q.L, 0);
}

void rear(Queue Q) {
    if (isEmpty(Q)) { cout << "Queue rong!" << endl; return; }
    truyCap(Q.L, Q.L.n - 1);
}

int main() {
    Queue Q;
    khoiTaoQueue(Q);

    int chon, x;

    do {
        cout << "\n===== MENU QUEUE (List) =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Rear\n";
        cout << "5. Hien thi queue\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                cout << "Nhap gia tri: ";
                cin >> x;
                enqueue(Q, x);
                break;
            case 2:
                dequeue(Q);
                break;
            case 3:
                front(Q);
                break;
            case 4:
                rear(Q);
                break;
            case 5:
                duyetXuoi(Q.L);
                break;
            case 0:
                cout << "Ket thuc!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (chon != 0);

    return 0;
}

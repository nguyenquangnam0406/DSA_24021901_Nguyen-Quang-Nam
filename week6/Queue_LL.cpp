#define main main_cu
#include "Linked_List.cpp"
#undef main

struct Queue {
    Node* head;
    Node* tail;
};

void khoiTaoQueue(Queue &Q) { Q.head = Q.tail = NULL; }

bool isEmpty(Queue Q) { return Q.head == NULL; }

void enqueue(Queue &Q, int x) {
    Node* p = taoNode(x);
    if (Q.tail == NULL) {          // queue đang rỗng
        Q.head = Q.tail = p;
    } else {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void dequeue(Queue &Q) {
    xoaDau(Q.head);
    if (Q.head == NULL)            // xóa hết thì tail cũng phải về NULL
        Q.tail = NULL;
}

void front(Queue Q) {
    if (isEmpty(Q)) { cout << "Queue rong!" << endl; return; }
    truyCap(Q.head, 0);
}

void rear(Queue Q) {
    if (isEmpty(Q)) { cout << "Queue rong!" << endl; return; }
    cout << "Phan tu cuoi (rear) la: " << Q.tail->data << endl;
}

int main() {
    Queue Q;
    khoiTaoQueue(Q);

    int chon, x;

    do {
        cout << "\n===== MENU QUEUE (LinkedList) =====\n";
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
                duyetXuoi(Q.head);        // hàm cũ: từ front đến rear
                break;
            case 0:
                cout << "Ket thuc!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (chon != 0);

    xoaDanhSach(Q.head);
    Q.tail = NULL;
    return 0;
}

#include <iostream>
using namespace std;

// Tao Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Tao Node moi
Node* createNode(int x) {
    Node* p = new Node;

    p->data = x;
    p->prev = NULL;
    p->next = NULL;

    return p;
}

// 1. Truy cap phan tu tai vi tri i
void truyCap(Node* head, int i) {
    if (head == NULL || i < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    Node* p = head;
    int dem = 0;

    while (p != NULL && dem < i) {
        p = p->next;
        dem++;
    }

    if (p == NULL) {
        cout << "Vi tri khong hop le!" << endl;
    }
    else {
        cout << "Phan tu tai vi tri " << i
             << " la: " << p->data << endl;
    }
}

// 2. Chen phan tu vao dau
void chenDau(Node*& head, int x) {
    Node* p = createNode(x);

    // Neu danh sach dang rong
    if (head == NULL) {
        head = p;
        return;
    }

    p->next = head;
    head->prev = p;
    head = p;
}

// 3. Chen phan tu vao cuoi
void chenCuoi(Node*& head, int x) {
    Node* p = createNode(x);

    // Neu danh sach rong
    if (head == NULL) {
        head = p;
        return;
    }

    Node* q = head;

    // Tim Node cuoi
    while (q->next != NULL) {
        q = q->next;
    }

    q->next = p;
    p->prev = q;
}

// 4. Chen phan tu vao vi tri i
void chenViTri(Node*& head, int i, int x) {

    if (i < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    // Chen vao dau
    if (i == 0) {
        chenDau(head, x);
        return;
    }

    Node* q = head;
    int dem = 0;

    // Tim Node tai vi tri i
    while (q != NULL && dem < i) {
        q = q->next;
        dem++;
    }

    // Neu i vuot qua vi tri cho phep
    if (q == NULL) {
        // Neu i bang vi tri cuoi + 1
        // thi chen vao cuoi
        if (dem == i) {
            chenCuoi(head, x);
        }
        else {
            cout << "Vi tri khong hop le!" << endl;
        }

        return;
    }

    Node* p = createNode(x);

    // Noi p voi q
    p->next = q;
    p->prev = q->prev;

    // Noi Node truoc q voi p
    if (q->prev != NULL) {
        q->prev->next = p;
    }

    // Noi q voi p
    q->prev = p;
}

// 5. Xoa phan tu dau
void xoaDau(Node*& head) {
    if (head == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* p = head;

    head = head->next;

    // Neu sau khi xoa van con Node
    if (head != NULL) {
        head->prev = NULL;
    }

    delete p;
}

// 6. Xoa phan tu cuoi
void xoaCuoi(Node*& head) {
    if (head == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* p = head;

    // Tim Node cuoi
    while (p->next != NULL) {
        p = p->next;
    }

    // Neu p la Node dau tien
    if (p->prev == NULL) {
        head = NULL;
    }
    else {
        p->prev->next = NULL;
    }

    delete p;
}

// 7. Xoa phan tu tai vi tri i
void xoaViTri(Node*& head, int i) {

    if (head == NULL || i < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    Node* p = head;
    int dem = 0;

    // Tim Node tai vi tri i
    while (p != NULL && dem < i) {
        p = p->next;
        dem++;
    }

    if (p == NULL) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    // Neu xoa Node dau
    if (p->prev == NULL) {
        xoaDau(head);
        return;
    }

    // Neu xoa Node cuoi
    if (p->next == NULL) {
        xoaCuoi(head);
        return;
    }

    // Noi Node truoc p voi Node sau p
    p->prev->next = p->next;
    p->next->prev = p->prev;

    delete p;
}

// 8. Duyet xuoi
void duyetXuoi(Node* head) {
    cout << "Duyet xuoi: ";

    Node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// 9. Duyet nguoc
void duyetNguoc(Node* head) {

    if (head == NULL) {
        return;
    }

    Node* p = head;

    // Tim Node cuoi
    while (p->next != NULL) {
        p = p->next;
    }

    // Di nguoc bang prev
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }
}

// Xoa toan bo danh sach
void xoaDanhSach(Node*& head) {
    while (head != NULL) {
        xoaDau(head);
    }
}

int main() {

    Node* head = NULL;

    int n;
    int x;
    int i;
    int chon;

    // Nhap danh sach ban dau
    cout << "Nhap so phan tu: ";
    cin >> n;

    for (int j = 0; j < n; j++) {
        cout << "Nhap phan tu thu " << j << ": ";
        cin >> x;

        chenCuoi(head, x);
    }

    do {

        cout << "\n========== MENU ==========\n";
        cout << "1. Truy cap\n";
        cout << "2. Chen vao dau\n";
        cout << "3. Chen vao cuoi\n";
        cout << "4. Chen vao vi tri i\n";
        cout << "5. Xoa phan tu dau\n";
        cout << "6. Xoa phan tu cuoi\n";
        cout << "7. Xoa vi tri i\n";
        cout << "8. Duyet xuoi\n";
        cout << "9. Duyet nguoc\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {

        case 1:
            cout << "Nhap vi tri i: ";
            cin >> i;

            truyCap(head, i);
            break;

        case 2:
            cout << "Nhap gia tri: ";
            cin >> x;

            chenDau(head, x);
            break;

        case 3:
            cout << "Nhap gia tri: ";
            cin >> x;

            chenCuoi(head, x);
            break;

        case 4:
            cout << "Nhap vi tri i: ";
            cin >> i;

            cout << "Nhap gia tri: ";
            cin >> x;

            chenViTri(head, i, x);
            break;

        case 5:
            xoaDau(head);
            break;

        case 6:
            xoaCuoi(head);
            break;

        case 7:
            cout << "Nhap vi tri i: ";
            cin >> i;

            xoaViTri(head, i);
            break;

        case 8:
            duyetXuoi(head);
            break;

        case 9:
            cout << "Duyet nguoc: ";
            duyetNguoc(head);
            cout << endl;
            break;

        case 0:
            cout << "Ket thuc!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (chon != 0);

    // Giai phong bo nho
    xoaDanhSach(head);

    return 0;
}

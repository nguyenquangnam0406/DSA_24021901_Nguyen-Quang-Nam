#include <iostream>
#include <string>
using namespace std;

// Tao Node cho Symbol Table
struct Node {
    string name;
    string type;
    string value;
    Node* next;
};

// Tao Node moi
Node* taoNode(string name, string type, string value) {
    Node* p = new Node;
    p->name = name;
    p->type = type;
    p->value = value;
    p->next = NULL;
    return p;
}

// 1. Tim kiem Symbol theo ten
Node* timKiem(Node* head, string name) {
    Node* p = head;

    while (p != NULL) {
        if (p->name == name)
            return p;

        p = p->next;
    }

    return NULL;
}

// 2. Them Symbol vao cuoi danh sach
void themSymbol(Node*& head, string name,
                string type, string value) {
    // Kiem tra Symbol da ton tai
    if (timKiem(head, name) != NULL) {
        cout << "Symbol da ton tai!\n";
        return;
    }

    Node* p = taoNode(name, type, value);

    if (head == NULL) {
        head = p;
        cout << "Them Symbol thanh cong!\n";
        return;
    }

    Node* q = head;

    while (q->next != NULL) {
        q = q->next;
    }

    q->next = p;

    cout << "Them Symbol thanh cong!\n";
}

// 3. Cap nhat Symbol
void capNhat(Node* head, string name,
             string type, string value) {
    Node* p = timKiem(head, name);

    if (p == NULL) {
        cout << "Khong tim thay Symbol!\n";
        return;
    }

    p->type = type;
    p->value = value;

    cout << "Cap nhat Symbol thanh cong!\n";
}

// 4. Xoa Symbol theo ten
void xoaSymbol(Node*& head, string name) {
    if (head == NULL) {
        cout << "Symbol Table rong!\n";
        return;
    }

    // Xoa Node dau
    if (head->name == name) {
        Node* p = head;
        head = head->next;
        delete p;

        cout << "Xoa Symbol thanh cong!\n";
        return;
    }

    Node* q = head;

    // Tim Node dung truoc Node can xoa
    while (q->next != NULL &&
           q->next->name != name) {
        q = q->next;
    }

    if (q->next == NULL) {
        cout << "Khong tim thay Symbol!\n";
        return;
    }

    Node* p = q->next;
    q->next = p->next;

    delete p;

    cout << "Xoa Symbol thanh cong!\n";
}

// 5. Hien thi thong tin mot Symbol
void hienThiMotSymbol(Node* p) {
    if (p == NULL) {
        cout << "Khong tim thay Symbol!\n";
        return;
    }

    cout << "Ten: " << p->name << endl;
    cout << "Kieu du lieu: " << p->type << endl;
    cout << "Gia tri: " << p->value << endl;
}

// 6. Hien thi toan bo Symbol Table
void hienThi(Node* head) {
    if (head == NULL) {
        cout << "Symbol Table rong!\n";
        return;
    }

    Node* p = head;

    cout << "\n========== SYMBOL TABLE ==========\n";
    cout << "Ten\tKieu du lieu\tGia tri\n";

    while (p != NULL) {
        cout << p->name << "\t"
             << p->type << "\t\t"
             << p->value << endl;

        p = p->next;
    }

    cout << "==================================\n";
}

// 7. Kiem tra Symbol co ton tai hay khong
void kiemTra(Node* head, string name) {
    if (timKiem(head, name) != NULL)
        cout << "Symbol ton tai!\n";
    else
        cout << "Symbol khong ton tai!\n";
}

// 8. Giai phong toan bo Symbol Table
void xoaDanhSach(Node*& head) {
    while (head != NULL) {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

int main() {
    Node* head = NULL;

    int chon;
    string name, type, value;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Them Symbol\n";
        cout << "2. Tim kiem Symbol\n";
        cout << "3. Cap nhat Symbol\n";
        cout << "4. Xoa Symbol\n";
        cout << "5. Hien thi mot Symbol\n";
        cout << "6. Hien thi toan bo Symbol Table\n";
        cout << "7. Kiem tra Symbol ton tai\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            cout << "Nhap ten Symbol: ";
            cin >> name;
            cout << "Nhap kieu du lieu: ";
            cin >> type;
            cout << "Nhap gia tri: ";
            cin >> value;

            themSymbol(head, name, type, value);
            break;

        case 2:
            cout << "Nhap ten Symbol can tim: ";
            cin >> name;

            hienThiMotSymbol(timKiem(head, name));
            break;

        case 3:
            cout << "Nhap ten Symbol can cap nhat: ";
            cin >> name;
            cout << "Nhap kieu du lieu moi: ";
            cin >> type;
            cout << "Nhap gia tri moi: ";
            cin >> value;

            capNhat(head, name, type, value);
            break;

        case 4:
            cout << "Nhap ten Symbol can xoa: ";
            cin >> name;

            xoaSymbol(head, name);
            break;

        case 5:
            cout << "Nhap ten Symbol can hien thi: ";
            cin >> name;

            hienThiMotSymbol(timKiem(head, name));
            break;

        case 6:
            hienThi(head);
            break;

        case 7:
            cout << "Nhap ten Symbol can kiem tra: ";
            cin >> name;

            kiemTra(head, name);
            break;

        case 0:
            cout << "Ket thuc!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    // Giai phong bo nho
    xoaDanhSach(head);

    return 0;
}

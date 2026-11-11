#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

// Khai bao cau truc Symbol
struct Symbol {
    char key[50];
    int value;
};

// Khai bao cau truc Symbol Table bang mang
struct SymbolTable {
    Symbol a[MAX];
    int n;
};

// Khoi tao Symbol Table
void khoiTao(SymbolTable &ST) {
    ST.n = 0;
}

// 1. Kiem tra Symbol Table rong
bool isEmpty(SymbolTable ST) {
    return ST.n == 0;
}

// 2. Kiem tra Symbol Table day
bool isFull(SymbolTable ST) {
    return ST.n == MAX;
}

// 3. Tim kiem Key trong Symbol Table
int search(SymbolTable ST, char key[]) {
    for (int i = 0; i < ST.n; i++) {
        if (strcmp(ST.a[i].key, key) == 0) {
            return i;
        }
    }

    return -1;
}

// 4. Chen mot cap Key - Value
void insert(SymbolTable &ST, char key[], int value) {
    if (isFull(ST)) {
        cout << "Symbol Table da day!" << endl;
        return;
    }

    if (search(ST, key) != -1) {
        cout << "Key da ton tai!" << endl;
        return;
    }

    strcpy(ST.a[ST.n].key, key);
    ST.a[ST.n].value = value;
    ST.n++;

    cout << "Chen thanh cong!" << endl;
}

// 5. Cap nhat Value cua mot Key
void update(SymbolTable &ST, char key[], int value) {
    int i = search(ST, key);

    if (i == -1) {
        cout << "Khong tim thay Key!" << endl;
        return;
    }

    ST.a[i].value = value;

    cout << "Cap nhat thanh cong!" << endl;
}

// 6. Xoa mot phan tu theo Key
void deleteSymbol(SymbolTable &ST, char key[]) {
    int i = search(ST, key);

    if (i == -1) {
        cout << "Khong tim thay Key!" << endl;
        return;
    }

    for (int j = i; j < ST.n - 1; j++) {
        ST.a[j] = ST.a[j + 1];
    }

    ST.n--;

    cout << "Xoa thanh cong!" << endl;
}

// 7. Duyet va hien thi Symbol Table
void traverse(SymbolTable ST) {
    if (isEmpty(ST)) {
        cout << "Symbol Table rong!" << endl;
        return;
    }

    cout << "\n===== SYMBOL TABLE =====\n";
    cout << "Key\tValue\n";

    for (int i = 0; i < ST.n; i++) {
        cout << ST.a[i].key << "\t"
             << ST.a[i].value << endl;
    }
}

// 8. Truy cap Value thong qua Key
void getValue(SymbolTable ST, char key[]) {
    int i = search(ST, key);

    if (i == -1) {
        cout << "Khong tim thay Key!" << endl;
        return;
    }

    cout << "Key: " << ST.a[i].key
         << " - Value: " << ST.a[i].value << endl;
}

int main() {
    SymbolTable ST;
    khoiTao(ST);

    char key[50];
    int value, chon;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Kiem tra Symbol Table rong\n";
        cout << "2. Kiem tra Symbol Table day\n";
        cout << "3. Insert (Chen Key - Value)\n";
        cout << "4. Search (Tim kiem Key)\n";
        cout << "5. Update (Cap nhat Value)\n";
        cout << "6. Delete (Xoa Key)\n";
        cout << "7. Traverse (Duyet Symbol Table)\n";
        cout << "8. Get Value (Truy cap Value)\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                if (isEmpty(ST))
                    cout << "Symbol Table rong!" << endl;
                else
                    cout << "Symbol Table khong rong!" << endl;
                break;

            case 2:
                if (isFull(ST))
                    cout << "Symbol Table da day!" << endl;
                else
                    cout << "Symbol Table chua day!" << endl;
                break;

            case 3:
                cout << "Nhap Key: ";
                cin >> key;
                cout << "Nhap Value: ";
                cin >> value;
                insert(ST, key, value);
                break;

            case 4:
                cout << "Nhap Key can tim: ";
                cin >> key;
                value = search(ST, key);

                if (value == -1)
                    cout << "Khong tim thay Key!" << endl;
                else
                    cout << "Tim thay tai vi tri: " << value << endl;
                break;

            case 5:
                cout << "Nhap Key can cap nhat: ";
                cin >> key;
                cout << "Nhap Value moi: ";
                cin >> value;
                update(ST, key, value);
                break;

            case 6:
                cout << "Nhap Key can xoa: ";
                cin >> key;
                deleteSymbol(ST, key);
                break;

            case 7:
                traverse(ST);
                break;

            case 8:
                cout << "Nhap Key: ";
                cin >> key;
                getValue(ST, key);
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

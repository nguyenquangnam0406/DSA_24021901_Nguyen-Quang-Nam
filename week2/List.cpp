#include <iostream>
using namespace std;

const int MAX = 1000;

// Khai bao cau truc List bang mang
struct List {
    int a[MAX];
    int n;
};

// Khoi tao danh sach
void khoiTao(List &L) {
    L.n = 0;
}

// 1. Truy cap phan tu tai vi tri i
void truyCap(List L, int i) {
    if (i < 0 || i >= L.n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    cout << "Phan tu tai vi tri " << i
         << " la: " << L.a[i] << endl;
}

// 2. Chen phan tu vao dau
void chenDau(List &L, int x) {
    if (L.n == MAX) {
        cout << "Danh sach da day!" << endl;
        return;
    }

    for (int i = L.n; i > 0; i--) {
        L.a[i] = L.a[i - 1];
    }

    L.a[0] = x;
    L.n++;
}

// 3. Chen phan tu vao cuoi
void chenCuoi(List &L, int x) {
    if (L.n == MAX) {
        cout << "Danh sach da day!" << endl;
        return;
    }

    L.a[L.n] = x;
    L.n++;
}

// 4. Chen phan tu vao vi tri i
void chenViTri(List &L, int i, int x) {
    if (i < 0 || i > L.n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    if (L.n == MAX) {
        cout << "Danh sach da day!" << endl;
        return;
    }

    for (int j = L.n; j > i; j--) {
        L.a[j] = L.a[j - 1];
    }

    L.a[i] = x;
    L.n++;
}

// 5. Xoa phan tu dau
void xoaDau(List &L) {
    if (L.n == 0) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    for (int i = 0; i < L.n - 1; i++) {
        L.a[i] = L.a[i + 1];
    }

    L.n--;
}

// 6. Xoa phan tu cuoi
void xoaCuoi(List &L) {
    if (L.n == 0) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    L.n--;
}

// 7. Xoa phan tu tai vi tri i
void xoaViTri(List &L, int i) {
    if (i < 0 || i >= L.n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    for (int j = i; j < L.n - 1; j++) {
        L.a[j] = L.a[j + 1];
    }

    L.n--;
}

// 8. Duyet xuoi
void duyetXuoi(List L) {
    cout << "Duyet xuoi: ";

    for (int i = 0; i < L.n; i++) {
        cout << L.a[i] << " ";
    }

    cout << endl;
}

// 9. Duyet nguoc
void duyetNguoc(List L) {
    cout << "Duyet nguoc: ";

    for (int i = L.n - 1; i >= 0; i--) {
        cout << L.a[i] << " ";
    }

    cout << endl;
}

int main() {
    List L;
    khoiTao(L);

    int n, x, i, chon;

    // Nhap danh sach ban dau
    cout << "Nhap so phan tu: ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "So phan tu khong hop le!" << endl;
        return 0;
    }

    for (int j = 0; j < n; j++) {
        cout << "Nhap phan tu thu " << j << ": ";
        cin >> x;
        chenCuoi(L, x);
    }

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Truy cap phan tu tai vi tri i\n";
        cout << "2. Chen phan tu vao dau\n";
        cout << "3. Chen phan tu vao cuoi\n";
        cout << "4. Chen phan tu vao vi tri i\n";
        cout << "5. Xoa phan tu dau\n";
        cout << "6. Xoa phan tu cuoi\n";
        cout << "7. Xoa phan tu tai vi tri i\n";
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
                truyCap(L, i);
                break;

            case 2:
                cout << "Nhap gia tri can chen: ";
                cin >> x;
                chenDau(L, x);
                break;

            case 3:
                cout << "Nhap gia tri can chen: ";
                cin >> x;
                chenCuoi(L, x);
                break;

            case 4:
                cout << "Nhap vi tri i: ";
                cin >> i;
                cout << "Nhap gia tri can chen: ";
                cin >> x;
                chenViTri(L, i, x);
                break;

            case 5:
                xoaDau(L);
                break;

            case 6:
                xoaCuoi(L);
                break;

            case 7:
                cout << "Nhap vi tri i: ";
                cin >> i;
                xoaViTri(L, i);
                break;

            case 8:
                duyetXuoi(L);
                break;

            case 9:
                duyetNguoc(L);
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

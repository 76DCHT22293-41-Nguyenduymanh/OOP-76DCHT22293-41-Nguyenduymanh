#include <iostream>
#include <cmath>

using namespace std;

// Cau 1: Lop SP1 bieu dien so phuc
class SP1 {
protected:
    double thuc;
    double ao;

public:
    // Ham tao (Constructor)
    SP1(double t = 0, double a = 0) : thuc(t), ao(a) {}

    // Phuong thuc nhap so phuc
    void nhap() {
        cout << "  Nhap phan thuc: ";
        cin >> thuc;
        cout << "  Nhap phan ao: ";
        cin >> ao;
    }

    // Phuong thuc in so phuc
    void xuat() const {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << -ao << "i";
    }

    // Phuong thuc tinh module so phuc
    double module() const {
        return sqrt(thuc * thuc + ao * ao);
    }
};

// Cau 2: Lop SP2 ke thua tu SP1
class SP2 : public SP1 {
public:
    // Ham tao cua SP2 goi ham tao cua SP1
    SP2(double t = 0, double a = 0) : SP1(t, a) {}

    // Nap chong toan tu gan =
    SP2& operator=(const SP2& sp) {
        if (this != &sp) {
            thuc = sp.thuc;
            ao = sp.ao;
        }
        return *this;
    }

    // Nap chong toan tu > (so sanh lon hon theo module)
    bool operator>(const SP2& sp) const {
        return this->module() > sp.module();
    }
};

// Cau 3: Chuong trinh chinh
int main() {
    int n;
    SP2 ds[10];

    // Nhap so luong phan tu (toi da 10)
    do {
        cout << "Nhap so luong so phuc (1 <= n <= 10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    // Nhap danh sach so phuc
    cout << "\n=== NHAP DANH SACH SO PHUC ===\n";
    for (int i = 0; i < n; i++) {
        cout << "So phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep danh sach giam dan theo module bang toan tu >
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) {
                SP2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // In ket qua
    cout << "\n=== DANH SACH SO PHUC GIAM DAN THEO MODULE ===\n";
    for (int i = 0; i < n; i++) {
        cout << "So " << i + 1 << ": ";
        ds[i].xuat();
        cout << " | Module = " << ds[i].module() << endl;
    }

    return 0;
}

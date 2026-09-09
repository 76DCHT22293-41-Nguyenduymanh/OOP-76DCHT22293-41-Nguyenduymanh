#include <iostream>
#include <cmath>
using namespace std;

int timUCLN(int a, int b) {
    a = abs(a); 
    b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Cau 1: Ham tao, ham huy
    PhanSo() { tuSo = 0; mauSo = 1; }
    PhanSo(int tu, int mau) {
        tuSo = tu;
        mauSo = (mau == 0) ? 1 : mau;
    }
    ~PhanSo() {}

    // Cau 2: Rut gon
    void rutGon() {
        if (tuSo == 0) {
            mauSo = 1;
            return;
        }
        int ucln = timUCLN(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Cau 2: Nap chong toan tu nhap (>>) va xuat (<<)
    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu so: "; is >> ps.tuSo;
        do {
            cout << "Nhap mau so (khac 0): "; is >> ps.mauSo;
            if (ps.mauSo == 0) cout << "Mau so phai khac 0!\n";
        } while (ps.mauSo == 0);
        return is;
    }

    friend ostream& operator<<(ostream& os, PhanSo ps) {
        if (ps.tuSo == 0) {
            os << "0";
        } else if (ps.mauSo == 1) {
            os << ps.tuSo;
        } else {
            os << ps.tuSo << "/" << ps.mauSo;
        }
        return os;
    }

    // Cau 3: Nap chong cac toan tu +, -, *, /
    PhanSo operator+(PhanSo ps2) {
        PhanSo kq(tuSo * ps2.mauSo + ps2.tuSo * mauSo, mauSo * ps2.mauSo);
        kq.rutGon();
        return kq;
    }

    PhanSo operator-(PhanSo ps2) {
        PhanSo kq(tuSo * ps2.mauSo - ps2.tuSo * mauSo, mauSo * ps2.mauSo);
        kq.rutGon();
        return kq;
    }

    PhanSo operator*(PhanSo ps2) {
        PhanSo kq(tuSo * ps2.tuSo, mauSo * ps2.mauSo);
        kq.rutGon();
        return kq;
    }

    PhanSo operator/(PhanSo ps2) {
        PhanSo kq(tuSo * ps2.mauSo, mauSo * ps2.tuSo);
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "--- Nhap phan so thu 1 ---\n";
    cin >> ps1;
    
    cout << "--- Nhap phan so thu 2 ---\n";
    cin >> ps2;

    ps1.rutGon();
    ps2.rutGon();
    
    cout << "\nHai phan so vua nhap: " << ps1 << " va " << ps2 << "\n";

    cout << "\n--- Ket qua toan tu ---\n";
    cout << "Tong   (" << ps1 << " + " << ps2 << ") = " << (ps1 + ps2) << endl;
    cout << "Hieu   (" << ps1 << " - " << ps2 << ") = " << (ps1 - ps2) << endl;
    cout << "Tich   (" << ps1 << " * " << ps2 << ") = " << (ps1 * ps2) << endl;
    cout << "Thuong (" << ps1 << " / " << ps2 << ") = " << (ps1 / ps2) << endl;

    return 0;
}

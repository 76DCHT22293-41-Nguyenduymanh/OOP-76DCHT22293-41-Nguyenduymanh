#include <iostream>
#include <cmath>
using namespace std;

// Ham tim uoc chung lon nhat de rut gon phan so
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
    // Cau 1: Ham tao khong doi, co doi va ham huy
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }

    PhanSo(int tu, int mau) {
        tuSo = tu;
        if (mau == 0) mauSo = 1; // Tranh loi chia 0
        else mauSo = mau;
    }

    ~PhanSo() {} // Ham huy

    // Cau 2: Phuong thuc nhap, xuat, rut gon
    void nhap() {
        cout << "Nhap tu so: "; cin >> tuSo;
        do {
            cout << "Nhap mau so (khac 0): "; cin >> mauSo;
            if (mauSo == 0) cout << "Mau so phai khac 0. Vui long nhap lai!\n";
        } while (mauSo == 0);
    }

    void xuat() {
        if (tuSo == 0) {
            cout << "0";
        } else if (mauSo == 1) {
            cout << tuSo;
        } else {
            cout << tuSo << "/" << mauSo;
        }
    }

    void rutGon() {
        if (tuSo == 0) {
            mauSo = 1;
            return;
        }
        int ucln = timUCLN(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
        // Xu ly dau am o mau so
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Cau 2 & 3: Phuong thuc cong, tru, nhan, chia
    PhanSo cong(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo + ps2.tuSo * mauSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo tru(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo - ps2.tuSo * mauSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo nhan(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.tuSo;
        kq.mauSo = mauSo * ps2.mauSo;
        kq.rutGon();
        return kq;
    }

    PhanSo chia(PhanSo ps2) {
        PhanSo kq;
        kq.tuSo = tuSo * ps2.mauSo;
        kq.mauSo = mauSo * ps2.tuSo;
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "--- Nhap phan so thu 1 ---\n";
    ps1.nhap();
    
    cout << "--- Nhap phan so thu 2 ---\n";
    ps2.nhap();

    cout << "\nHai phan so vua nhap (da rut gon):\n";
    ps1.rutGon();
    ps2.rutGon();
    cout << "PS1 = "; ps1.xuat(); cout << "\n";
    cout << "PS2 = "; ps2.xuat(); cout << "\n";

    cout << "\n--- Ket qua cac phep tinh ---\n";
    PhanSo tong = ps1.cong(ps2);
    PhanSo hieu = ps1.tru(ps2);
    PhanSo tich = ps1.nhan(ps2);
    PhanSo thuong = ps1.chia(ps2);

    cout << "Tong  : "; tong.xuat(); cout << endl;
    cout << "Hieu  : "; hieu.xuat(); cout << endl;
    cout << "Tich  : "; tich.xuat(); cout << endl;
    cout << "Thuong: "; thuong.xuat(); cout << endl;

    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

class PS1 {
protected:
    int tu;
    int mau;

public:
    PS1(int t = 0, int m = 1) {
        tu = t;
        mau = m != 0 ? m : 1;
    }

    void nhap() {
        cout << "Nhap tu so: "; 
        cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): "; 
            cin >> mau;
            if (mau == 0) {
                cout << "Loi: Mau so phai khac 0. Vui long nhap lai!\n";
            }
        } while (mau == 0);
    }

    void rutGon() {
        if (tu == 0) {
            mau = 1;
            return;
        }
        int uc = UCLN(tu, mau);
        tu /= uc;
        mau /= uc;
        
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void in() const {
        if (mau == 1 || tu == 0) {
            cout << tu;
        } else {
            cout << tu << "/" << mau;
        }
    }
};

class PS2 : public PS1 {
public:
    PS2(int t = 0, int m = 1) : PS1(t, m) {}

    PS2& operator=(const PS2& other) {
        if (this != &other) {
            this->tu = other.tu;
            this->mau = other.mau;
        }
        return *this;
    }

    bool operator>(const PS2& other) const {
        return (this->tu * other.mau) > (other.tu * this->mau);
    }
};

int main() {
    int n;
    
    do {
        cout << "Nhap so luong phan so : ";
        cin >> n;
        if (n < 1 || n > 10) {
            cout << "So luong khong hop le. Vui long nhap lai!\n";
        }
    } while (n < 1 || n > 10);

    PS2 ds[10];

    cout << "\n--- NHAP DANH SACH PHAN SO ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ":\n";
        ds[i].nhap();
        ds[i].rutGon();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) {
                PS2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n--- DANH SACH PHAN SO GIAM DAN ---\n";
    for (int i = 0; i < n; i++) {
        ds[i].in();
        cout << "  ";
    }
    cout << endl;

    return 0;
}

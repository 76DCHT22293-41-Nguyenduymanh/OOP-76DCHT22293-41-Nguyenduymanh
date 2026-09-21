#include <iostream>
#include <cmath>
using namespace std;

class SP1 {
protected:
    float thuc;
    float ao;

public:
    SP1(float t = 0, float a = 0) {
        thuc = t;
        ao = a;
    }

    void nhap() {
        cout << "  + Nhap phan thuc: "; 
        cin >> thuc;
        cout << "  + Nhap phan ao: "; 
        cin >> ao;
    }

    void in() const {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << abs(ao) << "i";
    }

    float tinhModule() const {
        return sqrt(thuc * thuc + ao * ao);
    }
};

class SP2 : public SP1 {
public:
    SP2(float t = 0, float a = 0) : SP1(t, a) {}

    SP2& operator=(const SP2& right) {
        if (this != &right) {
            this->thuc = right.thuc;
            this->ao = right.ao;
        }
        return *this;
    }

    bool operator>(const SP2& right) const {
        return this->tinhModule() > right.tinhModule();
    }
};

int main() {
    int n;
    
    do {
        cout << "Nhap so luong so phuc (0 < n <= 10): ";
        cin >> n;
        if (n <= 0 || n > 10) {
            cout << "So luong khong hop le. Vui long nhap lai!\n";
        }
    } while (n <= 0 || n > 10);

    SP2 ds[10];

    cout << "\n--- NHAP DANH SACH SO PHUC ---\n";
    for (int i = 0; i < n; i++) {
        cout << "So phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[j] > ds[i]) { 
                SP2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n--- DANH SACH SO PHUC GIAM DAN THEO MODULE ---\n";
    for (int i = 0; i < n; i++) {
        cout << "SP " << i + 1 << ": ";
        ds[i].in();
        cout << " | Module = " << ds[i].tinhModule() << "\n";
    }

    return 0;
}

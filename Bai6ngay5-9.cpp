#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Cau 1: Khai bao lop sinh vien voi cac thuoc tinh ho ten, nam sinh, diem 5 mon hoc
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    // Cau 2: Xay dung phuong thuc nhap
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        for (int i = 0; i < 5; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    // Cau 2: Xay dung phuong thuc tinh diem trung binh
    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }
        return tong / 5.0;
    }

    // Cau 2: Xay dung phuong thuc xuat
    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | DTB: " << tinhDTB() << endl;
    }

    // Kiem tra sinh vien co mon thi lai hay khong
    bool coMonThiLai() {
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) return true;
        }
        return false;
    }

    // In thong tin cac mon thi lai va diem tuong ung
    void inThongTinThiLai() {
        xuat();
        cout << "  Cac mon thi lai (diem < 5):" << endl;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                cout << "   - Mon " << i + 1 << ": " << diem[i] << " diem" << endl;
            }
        }
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;

    vector<SinhVien> ds(n);

    // Cau 3: Nhap vao n sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien " << i + 1 << " ---" << endl;
        ds[i].nhap();
    }

    // Cau 3: In ra man hinh thong tin cac sinh vien phai thi lai
    cout << "\n================ DANH SACH SINH VIEN PHAI THI LAI ================" << endl;
    bool coThiLai = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].coMonThiLai()) {
            ds[i].inThongTinThiLai();
            coThiLai = true;
        }
    }

    if (!coThiLai) {
        cout << "Khong co sinh vien nao phai thi lai." << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Cau 1: Khai bao lop sinh vien voi cac thuoc tinh ho ten, nam sinh, diem 4 mon hoc
class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    // Cau 2: Xay dung phuong thuc nhap
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        for (int i = 0; i < 4; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    // Cau 2: Xay dung phuong thuc tinh diem trung binh
    float tinhDTB() {
        float tong = 0;
        for (int i = 0; i < 4; i++) {
            tong += diem[i];
        }
        return tong / 4.0;
    }

    // Cau 2: Xay dung phuong thuc xuat
    void xuat() {
        cout << "Ho ten: " << hoTen << " | Nam sinh: " << namSinh << " | DTB: " << tinhDTB() << endl;
    }

    // Kiem tra tieu chuan thi tot nghiep: DTB < 7 va khong co mon nao duoi 5
    bool duDieuKienThiTotNghiep() {
        if (tinhDTB() >= 7) return false;
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5) return false;
        }
        return true;
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

    // Cau 3: In ra man hinh thong tin cac sinh vien phai thi tot nghiep
    cout << "\n================ DANH SACH SINH VIEN THI TOT NGHIEP ================" << endl;
    bool coThiTotNghiep = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].duDieuKienThiTotNghiep()) {
            ds[i].xuat();
            coThiTotNghiep = true;
        }
    }

    if (!coThiTotNghiep) {
        cout << "Khong co sinh vien nao du dieu kien thi tot nghiep." << endl;
    }

    return 0;
}

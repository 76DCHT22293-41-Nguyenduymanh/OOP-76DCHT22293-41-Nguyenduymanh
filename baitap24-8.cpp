#include <iostream>
#include <string>
#include <iomanip> // Thu vien dung de can chinh cot (setw, left)

using namespace std;

// 1. Khai bao lop NhanVien
class NhanVien {
private:
    string maNV;
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    // 2. Constructor khong doi (Mac dinh)
    NhanVien() {
        maNV = "";
        hoTen = "";
        ngaySinh = "";
        diaChi = "";
    }

    // 2. Constructor co doi so
    NhanVien(string ma, string ten, string ngay, string dchi) {
        maNV = ma;
        hoTen = ten;
        ngaySinh = ngay;
        diaChi = dchi;
    }

    // Phuong thuc xuat du lieu cua 1 nhan vien
    void xuat() {
        // Can trai (left) va thiet lap do rong cot (setw)
        cout << left << setw(15) << maNV
             << setw(25) << hoTen
             << setw(15) << ngaySinh
             << setw(20) << diaChi << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    
    // Xoa bo dem ban phim sau khi nhap so nguyen de tranh troi lenh getline()
    cin.ignore(); 

    // Khoi tao mang dong chua n nhan vien
    NhanVien* ds = new NhanVien[n]; 

    // 3. Nhap du lieu va dua vao mang bang constructor co doi
    for (int i = 0; i < n; i++) {
        string ma, ten, ngay, dchi;
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        
        cout << "Ma NV: "; 
        getline(cin, ma);
        
        cout << "Ho ten: "; 
        getline(cin, ten);
        
        cout << "Ngay sinh (dd/mm/yyyy): "; 
        getline(cin, ngay);
        
        cout << "Dia chi: "; 
        getline(cin, dchi);

        // YEU CAU QUAN TRONG: Goi constructor co doi de gan vao mang
        ds[i] = NhanVien(ma, ten, ngay, dchi);
    }

    // 4. Xuat du lieu nhan vien theo cot
    cout << "\n========================= DANH SACH NHAN VIEN =========================\n";
    cout << left << setw(15) << "Ma NV"
         << setw(25) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(20) << "Dia Chi" << endl;
    cout << "-----------------------------------------------------------------------\n";
    
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }

    // Giai phong bo nho mang dong
    delete[] ds; 

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Khai bao lop 
class NhanVien
{
private:
    string manv;
    string hoten;
    string ngaysinh;
    string diachi;

public:
    // Phuong thuc nhap 
    void nhap()
    {
        cout << "Nhap ma nhan vien: ";
        getline(cin, manv);

        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);

        cout << "Nhap dia chi: ";
        getline(cin, diachi);
    }

    // Phuong thuc xuat 
    void xuat()
    {
        cout << "Ma nhan vien: " << manv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Ngay sinh: " << ngaysinh << endl;
        cout << "Dia chi: " << diachi << endl;
    }
};

// Khai bao ham main 
int main()
{
    // Khai bao 1 doi tuong la Minh thuoc lop Nhanvien 
    NhanVien Minh;

    // Nhap thong tin cho Minh
    Minh.nhap();

    // Xuat thong tin cua Minh 
    Minh.xuat();

    return 0;
}

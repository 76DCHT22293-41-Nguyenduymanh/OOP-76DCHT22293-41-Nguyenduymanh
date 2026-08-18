#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct NhanVien {
    string maNV;        
    string tenNV;       
    double luongCoBan;  
    float heSo;         
};


void nhap(NhanVien ds[], int &n) {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---\n";
        cout << "Nhap ma NV: ";
        getline(cin, ds[i].maNV);
        cout << "Nhap ten NV: ";
        getline(cin, ds[i].tenNV);
        cout << "Nhap luong co ban: ";
        cin >> ds[i].luongCoBan;
        cout << "Nhap he so luong: ";
        cin >> ds[i].heSo;
        cin.ignore();
    }
}
void xuat(NhanVien ds[], int n) {
    cout << "\n==================== DANH SACH NHAN VIEN ====================\n";
    cout << left 
         << setw(15) << "Ma NV" 
         << setw(25) << "Ten NV" 
         << setw(15) << "Luong CB" 
         << setw(10) << "He So" 
         << setw(15) << "Luong" << "\n";
    cout << string(80, '-') << "\n";
    
    for (int i = 0; i < n; i++) {
    	double luong = ds[i].luongCoBan * ds[i].heSo;
        
        cout << left 
             << setw(15) << ds[i].maNV 
             << setw(25) << ds[i].tenNV 
             << setw(15) << fixed << setprecision(0) << ds[i].luongCoBan 
             << setw(10) << setprecision(2) << ds[i].heSo 
             << setw(15) << setprecision(0) << luong << "\n";
    }
    cout << string(80, '-') << "\n";
}
int main() {
    int n;
    NhanVien dsNV[100];
    nhap(dsNV, n);
    xuat(dsNV, n);
    return 0;
}

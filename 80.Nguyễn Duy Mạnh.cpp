#include <vector>
#include<iostream>
#include <string> 
using namespace std;
struct NhanVien{
  string maNV;
  string hoTen;
  int tuoi; 
}; 
int main() {
   
    vector<NhanVien> ds(10); 

    cout << "--- NHAP THONG TIN CHO 10 NHAN VIEN  ---\n";
    for (int i = 0; i < 10; i++) {
        cout << "Nhap thong tin nhan vien thu  " << i + 1 << ":\n";
        cout << "MA NV: ";
        cin >> ds[i].maNV;
        cout << "Ho va ten: ";
        cin.ignore();
        getline(cin, ds[i].hoTen);
        cout << "Tuoi: ";
        cin >> ds[i].tuoi;
    }
    
    return 0;
}

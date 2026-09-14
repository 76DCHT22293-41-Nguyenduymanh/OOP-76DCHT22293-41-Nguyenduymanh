#include<iostream>

using namespace std;

class nguoi{
	protected:
		string hoten;
		int namsinh;
	public:
		void nhap(){
			cout<<"nhap hoten";
			cin.ignore();
			getline(cin,hoten);
			cout<<"nhap namsinh";cin>>namsinh;
			
}
void xuat(){
	cout<<"hoten"<<hoten<<"namsinh"<<namsinh;
}
};
class sinhvien: public nguoi{
	private:
	string msv;
	float diemtb;
	public:
		void nhap(){
			nguoi::nhap();
			cout<<"nhap msv";
			cin.ignore();
			getline(cin,msv);
			cout<<"nhap diemtb";cin>>diemtb;
		}
		void xuat(){
			nguoi::xuat();
			cout<<"msv"<<msv<<"diemtb"<<diemtb<<endl;
		}
		float getdiemtb(){
			return diemtb; 
		} 
};
void hoanvi(sinhvien &a, sinhvien &b){
	sinhvien temp = a;
	a = b;
	b = temp; 
} 
int main(){
	int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    
    sinhvien* ds = new sinhvien[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin sinh vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getdiemtb() < ds[j].getdiemtb()) {
                hoanvi(ds[i], ds[j]);
            }
        }
    }

   
    cout << "\n=== DANH SACH SINH VIEN GIAM DAN THEO DIEM TRUNG BINH ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
    delete[] ds;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int PhanLoai=1;
	cout << "Loai Nhan Vien(1.Loi,2.CongNhat,3.SanPham): "<<(PhanLoai==1?"NV Loi":(PhanLoai==2?"NV Cong Nhat":(PhanLoai==3?"NV San Phan":"???")))<<endl;
    system("pause");
}

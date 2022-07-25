#include <iostream>
#include <string>
using namespace std;

// tạo cấu trúc dnah
// a. Định nghĩa danh sách liên kết
struct MatHang
{
    string TenMatHang;
    int Gia;
    int SoLuong;
};
struct NODE
{
    MatHang info; // Dữ Liệu
    NODE *pnext;  // Con trỏ trỏ tới địa chỉ tiếp theo
};
struct LIST
{
    NODE *phead = NULL;
    NODE *ptail = NULL;
};
//b.hàm nhập

NODE *TaoNode(MatHang x) // tạo một node đơn
{
    NODE *p = new NODE; // xin cấp phát bộ nhớ
    if (p == NULL)
        return NULL; // trả về địa chỉ con trỏ
    p->info = x;     //  gán dữ liệu cái gì đó
    p->pnext = NULL;
    return p;
}

void AddTail(LIST &l, NODE *p)
{
    if (l.phead == NULL) //
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->pnext = p;
        l.ptail = p;
    }
}
void AddHead(LIST &l, NODE *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p;
    }

    else
    {
        p->pnext = l.phead;
        l.phead = p;
    }
}
void Nhap(MatHang &a)
{   cin.ignore();
    // char :  cin.getline(char,soluongkitu);
    cout << " Nhap ten : ";
    getline(cin, a.TenMatHang);
    cout << " Gia : ";
    cin >> a.Gia;
    cout << " So luong: ";
    cin >> a.SoLuong;
}

void NhapDanhSachMatHang(LIST &l)
{
    cout << "Nhap so luong can nahp la 50 ";
    for (int i = 0; i < 3; i++)
    {
        MatHang x;
        Nhap(x);
        AddTail(l, TaoNode(x));
    }
}

void XuatDanhSachXY(LIST l, int &x, int &y)
{
    do
    {
        cout << " nahp x";
        cin >> x;
        cout << " nhap y";
        cin >> y;
    } while (x < 0 || y < 0 || x >= y);

    for (NODE *p = l.phead; p != NULL; p = p->pnext)
    {
        if (p->info.SoLuong > x && p->info.SoLuong < y) {
            cout <<"Ten  :"<< p->info.TenMatHang<<endl; 
            cout << "Gia ca "<<p->info.Gia<<endl;
            cout << "SOluong "<<p->info.SoLuong<<endl;
        }
    }
}


int main()
{
    LIST l;
    NhapDanhSachMatHang(l);
    int x,y;
    XuatDanhSachXY(l,x,y);
    system("pause");
    // return 0;
}
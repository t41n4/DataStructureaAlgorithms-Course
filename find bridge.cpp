
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MANG
{
private:
    int n;
    int* mang;
    bool flagg=false;
public:
    MANG();
    MANG(int);
    MANG(const MANG&);
    ~MANG();
    friend istream& operator >>(istream& is, MANG& A);
    friend ostream& operator<<(ostream& os, MANG A);
    MANG ShowSNT();
    int DemSoChinhPhuong();
    int SumOfSoHoanThien();
    double TrungBinhSoDoiXung();
    bool isToanLe();
    int FindChanBeNhat();
    void SapXepTangDan();
    void SapXepGiamDan();
    void XoaPhanTu(int);
    void ThemPhanTu(int,int);
    int find(int);
};




int MANG::find(int x)
{
    for (int i = 0; i < n; i++) if (mang[i] == x) return i;
        
    return -1;
}

MANG::MANG()
{
    n = 0;
    mang = new int[n];
}

MANG::MANG(int nn)
{
    n = nn;
    mang = new int[n];
}

MANG::MANG(const MANG& A)
{
    n = A.n;
    mang = A.mang;
}
 istream& operator>>(istream& is, MANG& A)
{
     if (A.n == 0)
     {
         cout << "Nhap so Phan tu trong mang : "; is >> A.n;
         A.mang = new int[A.n];
     }
    cout << "Nhap Mang : ";
    for (int i = 0; i < A.n; i++)
    {
        is >> A.mang[i];
    }
    return is;
}
ostream& operator<<(ostream& os, MANG A)
{
    
    os << "[";
    for (int i = 0; i < A.n; i++)
    {
        if (i == A.n - 1) os<< A.mang[i];
        else os << A.mang[i] << ", ";
    }
    os << "]";
    A.flagg = true;
    return os;
     
}
MANG::~MANG()
{
    if (!flagg) delete[]mang;
    flagg = false;
    
}

MANG MANG::ShowSNT()
{
    int a=0;
    MANG res(a);
    for (int i = 0; i < n; i++)
    {
        
        if (mang[i]==1) {continue;}
        if (mang[i]==2) {res.ThemPhanTu(res.n, mang[i]);continue;}
        if (mang[i]==3) {res.ThemPhanTu(res.n, mang[i]);continue;}
        int tag = 0;
        for (int j = 2; j <= sqrt(mang[i]); j++) 
            if (mang[i] % j == 0) 
            {tag = -1; break;}    
        if (tag == 0) {res.ThemPhanTu(res.n, mang[i]);}
    }
    return res;
}
 int MANG::DemSoChinhPhuong()
{
    int res = 0;
    for (int i = 0; i < n; i++) if ((int)sqrt(i) * (int)sqrt(i) == i) res++;
    return res;
}

 int MANG::SumOfSoHoanThien()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int test = 0;
        for (int j = 1; j <= mang[i] / 2; j++) 
            if (mang[i] % j == 0)
                test += j;
        if (test == mang[i])
                res += mang[i];
    }
    return res;
}

 double MANG::TrungBinhSoDoiXung()
{
    int res = 0, tag = 0;
    for (int i = 0; i < n; i++)
    {
        int  sum = 0, temp = 0,test=mang[i];
        for (temp = test; test != 0; test /= 10) sum = sum * 10 + test % 10;
        if (temp == sum) { res += sum; tag++; }
    }
    return res / (double)tag;
}

 bool MANG::isToanLe()
{
    for (int i = 0; i < n; i++) if (mang[i] % 2 == 0) return false;
    return true;
}

 int MANG::FindChanBeNhat()
{
    int res = INT_MAX, tag = 0;
    for (int i = 0; i < n; i++) if (mang[i] % 2 == 0) if (mang[i] < res)
    {
        res = mang[i];
        tag = -1;
    }
    if (tag == 0) {cout << "Mang Khong co so chan!!"; return -1;}
    return res;
}

 void MANG::SapXepTangDan()
{
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] > mang[j]) {
                temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}

 void MANG::SapXepGiamDan()
{
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] < mang[j]) {
                temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}

 void MANG::XoaPhanTu(int pos)
{
    if (n <= 0) return;
    if (pos < 0) pos = 0;
    else if (pos >= n)     pos = n - 1;
    for (int i = pos; i < n - 1; i++) mang[i] = mang[i + 1];
    --n;
}
void MANG::ThemPhanTu(int pos, int val)
{
    if (pos <= 0)  pos = 0;
    else if (pos > this->n) pos = this->n;
    for (int i = this->n; i > pos; i--) this->mang[i] = this->mang[i - 1];
    mang[pos] = val;
    ++this->n;
}
int main() 
{
     MANG A;
    cin >> A;
    cout << A<<endl;
    cout << "So Chinh Phuong "<<A.DemSoChinhPhuong()<<endl;
    cout << "Show SNT :" << A.ShowSNT()<<endl;
     cout << A<<endl;
    cout << "Tong So hoan thien :"<< A.SumOfSoHoanThien()<<endl;
     cout << A<<endl;
    cout << "Trung Binh So Doi Xung :" << A.TrungBinhSoDoiXung()<<endl;
    cout << A<<endl;
    cout << "isToanLe :" << A.isToanLe()<<endl;
    cout << "Chan be nhat :"<< A.FindChanBeNhat()<<endl;
    cout << "Sap Xep Tang Dan: "; A.SapXepTangDan();cout << A <<endl;
    cout << "Sap Xep Giam Dan: "; A.SapXepGiamDan();cout << A <<endl;
    A.ThemPhanTu(5,999);
    cout << A<< endl;
    A.XoaPhanTu(5);
     cout << A<< endl;
    system("pause");
}

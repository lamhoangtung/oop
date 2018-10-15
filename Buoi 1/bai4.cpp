#include <iostream>

using namespace std;

class PhanSo
{
    int tu, mau;
    public:
        void nhap();
        void xuat();
        friend bool operator> (PhanSo &a, PhanSo &b){
            if (a.tu/a.mau>b.tu/b.mau) return true;
            else return false;
        }
};

void PhanSo::nhap()
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}

void PhanSo::xuat()
{
    cout << tu << "/" << mau;
}

int main()
{
    PhanSo a,b;
    a.nhap();
    b.nhap();
    if (a>b){
        a.xuat();
        cout << " lon hon phan so ";
        b.xuat();
        cout << endl;
    }
    else{
        b.xuat();
        cout << " lon hon phan so ";
        a.xuat();
        cout << endl;
    }
    return 0;
}
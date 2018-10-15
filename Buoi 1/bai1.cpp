#include <iostream>

using namespace std;

class PhanSo{
    int tu,mau;
    public:
        void nhap();
        void xuat();
        void kiemtra();
};

void PhanSo::nhap(){
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}

void PhanSo::xuat(){
    cout << tu << " / " << mau;
}

void PhanSo::kiemtra(){
    if (tu*mau>0){
        xuat();
        cout << " la phan so duong." << endl;
    }
    else if(tu*mau<0){
        xuat();
        cout << " la phan so am." << endl;
    }
    else if (mau!=0){
        xuat();
        cout << " bang 0." << endl;
    }
    else{
        cout << "Phan so tren khong ton tai." << endl;
    }
}

int main(){
    PhanSo a;
    a.nhap();
    a.kiemtra();
    return 0;
}
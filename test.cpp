#include <iostream>
#include <stdlib.h>

using namespace std;

int gcd(int a, int b){
    while (b!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class PhanSo {
    public:
        int tu,mau;
        PhanSo(int x, int y){
            PhanSo::tu = x;
            PhanSo::mau = y;
        }

        PhanSo minimize(){
            int gcd_val = gcd(this->tu, this->mau);
            this->tu /= gcd_val;
            this->mau /= gcd_val;
            return PhanSo(this->tu, this->mau);
        }

        friend PhanSo operator+ (PhanSo &a, PhanSo &b){
            return PhanSo(a.tu * b.mau + a.mau * b.tu, a.mau * b.mau).minimize();
        }

        friend PhanSo operator- (PhanSo &a, PhanSo &b){
            return PhanSo(a.tu * b.mau - a.mau * b.tu, a.mau * b.mau).minimize();
        }

        friend PhanSo operator* (PhanSo &a, PhanSo &b){
            return PhanSo(a.tu * b.tu, a.mau * b.mau).minimize();
        }

        friend PhanSo operator/ (PhanSo &a, PhanSo &b){
            return PhanSo(a.tu * b.mau, a.mau * b.tu).minimize();
        }
};

int main(){
    int tu,mau;
    cout << "Nhap tu a:";
    cin >> tu;
    cout << "Nhap mau a:";
    cin >> mau;
    PhanSo a(tu,mau);
    cout << "Nhap tu b:";
    cin >> tu;
    cout << "Nhap mau b:";
    cin >> mau;
    PhanSo b(tu, mau);
    PhanSo c = a + b;
    cout << "Tong: "<< c.tu << "/" << c.mau << "\n";
    c = a - b;
    cout << "Hieu: " << c.tu << "/" << c.mau << "\n";
    c = a * b;
    cout << "Tich: " << c.tu << "/" << c.mau << "\n";
    c = a / b;
    cout << "Thuong: " << c.tu << "/" << c.mau << "\n";
    return 0;
}
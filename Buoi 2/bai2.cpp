#include <iostream>
#include <string>

using namespace std;

class MayIn{
    protected:
        int TrongLuong,NamSanXuat;
        string HangSanXuat;
    public:
        void nhap()
        {
            cout << "Nhap trong luong: ";
            cin >> TrongLuong;
            cout << "Nhap nam san xuat: ";
            cin >> NamSanXuat;
            cout << "Nhap hang san xuat: ";
            cin >> HangSanXuat;
        }
        void xuat()
        {
            cout << "Trong luong: " << TrongLuong << endl;
            cout << "Nam san xuat: " << NamSanXuat << endl;
            cout << "Hang san xuat: " << HangSanXuat << endl;
        }
};

class MayInKim: public MayIn{
    private:
        int SoKim,TocDoIn;
    public:
        void nhap()
        {
            MayIn::nhap();
            cout << "Nhap so kim: ";
            cin >> SoKim;
            cout << "Nhap toc do in: ";
            cin >> TocDoIn;
        }
        void xuat()
        {
            MayIn::xuat();
            cout << "So kim: " << SoKim << endl;
            cout << "Toc do in: " << TocDoIn << endl;
        }
};

class MayInLaser: public MayIn{
    private:
        int DoPhanGiai,TocDoIn;
    public:
        void nhap()
        {
            MayIn::nhap();
            cout << "Nhap do phan giai: ";
            cin >> DoPhanGiai;
            cout << "Nhap toc do in: ";
            cin >> TocDoIn;
        }
        void xuat()
        {
            MayIn::xuat();
            cout << "Do phan giai: " << DoPhanGiai << endl;
            cout << "Toc do in: " << TocDoIn << endl;
        }
};

int main(){
    int n,m;
    cout << "Nhap so luong may in kim: ";
    cin >> n;
    MayInKim MayKim[n];
    for (int i=0;i<n;i++){
        cout << "May in kim so " << i+1 << ":" << endl;
        MayKim[i].nhap();
    }
    cout << "Nhap so luong may in laser: ";
    cin >> m;
    MayInLaser MayLaser[m];
    for (int i = 0; i < m; i++)
    {
        cout << "May in laser so " << i + 1 << ":" << endl;
        MayLaser[i].nhap();
    }
    cout << "Co " << n << " may in kim:" << endl;
    for (int i = 0; i < n; i++){
        MayKim[i].xuat();
        cout << "----------------------------" << endl;
    }
    cout << "Co " << m << " may in laser:" << endl;
    for (int i = 0; i < m; i++)
    {
        MayLaser[i].xuat();
        cout << "----------------------------" << endl;
    }
    return 0;
}
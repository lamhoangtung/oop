#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int NgayTrongThang[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class NGAY
{
  public:
    int ngay, thang, nam;
    NGAY()
    {
        ngay = 1;
        thang = 1;
        nam = 0;
    }

    NGAY(int ngay, int thang, int nam)
    {
        ngay = ngay;
        thang = thang;
        nam = nam;
    }

    bool NamNhuan()
    {
        return ((nam % 4 == 0 && nam % 100 == 0) || (nam % 400 == 0));
    }

    bool HopLe()
    {
        if (nam < 0)
            return false;
        if (thang <= 0 || thang > 12)
            return false;
        if (ngay <= 0 || ngay > NgayTrongThang[thang - 1])
            return false;
        if (NamNhuan() == false && thang == 2 && ngay > 28)
            return false;
        return true;
    }

    void nhap()
    {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        fflush(stdin);
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
        while (!HopLe())
        {
            cout << "Ngay thang nam vua nhap khong hop le! Vui long nhap lai: " << endl;
            cout << "Nhap ngay: ";
            cin >> ngay;
            cout << "Nhap thang: ";
            cin >> thang;
            cout << "Nhap nam: ";
            cin >> nam;
        }
    }

    void xuat()
    {
        cout << ngay << "/" << thang << "/" << nam;
    }
};

class NGUOI : public NGAY
{
  private:
    char HoTen[100], CMND[100], NoiSinh[100];

  public:
    NGUOI()
    {
        strcpy(HoTen, "");
        strcpy(CMND, "");
        strcpy(NoiSinh, "");
        NGAY();
    }
    NGUOI(char HoTen[], char CMND[], char NoiSinh[], int ngay, int thang, int nam)
    {
        strcpy(HoTen, HoTen);
        strcpy(CMND, CMND);
        strcpy(NoiSinh, NoiSinh);
        NGAY(ngay, thang, nam);
    }
    void nhap()
    {
        cout << "Nhap ho va ten: ";
        cin.ignore(1);
        cin.getline(HoTen, 100);
        cout << "Nhap so CMND: ";
        cin >> CMND;
        cout << "Nhap noi sinh: ";
        cin.ignore(1);
        cin.getline(NoiSinh, 100);
        cout << "Nhap ngay sinh: " << endl;
        NGAY::nhap();
    }
    void xuat()
    {
        cout << setw(30) << HoTen << setw(30) << CMND << setw(30) << NoiSinh << setw(30);
        NGAY::xuat();
        cout << endl;
    }
    NGUOI& operator= (const NGUOI &a)
    {
        strcpy(HoTen, a.HoTen);
        strcpy(CMND, a.CMND);
        strcpy(NoiSinh, a.NoiSinh);
        ngay = a.ngay;
        thang = a.thang;
        nam = a.nam;
        return *this;
    }
    int tinhTuoi(){
        return (2018 - NGAY::nam);
    }
};

int main(){
    int n;
    cout << "Nhap vao so nguoi: ";
    cin >> n;
    NGUOI a[n];
    for (int i=0;i<n;i++){
        a[i].nhap();
    }
    cout << "Danh sach nguoi vua nhap la: " << endl;
    cout << setw(30) << "Ho va ten" << setw(30) << "CMND" << setw(30) << "Noi Sinh" << setw(30) << "Ngay Sinh" << endl;
    for (int i=0; i<n;i++){
        a[i].xuat();
    }
    NGUOI TrungGian;
    for (int j=n-1; j>=1; j--){
        for (int i=0;i<=j-1;i++){
            if (a[i].tinhTuoi() < a[i+1].tinhTuoi()) {
                TrungGian = a[i];
                a[i] = a[i+1];
                a[i+1] = TrungGian;
            }
        }
    }
    cout << "Danh sach nguoi vua nhap sau khi sap xep giam dan theo tuoi la: " << endl;
    cout << setw(30) << "Ho va ten" << setw(30) << "CMND" << setw(30) << "Noi Sinh" << setw(30) << "Ngay Sinh" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    return 0;
}
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Person{
    public:
        char HoTen[50], NgaySinh[12], QueQuan[100];
        Person()
        {
            strcpy(Person::HoTen, "");
            strcpy(Person::NgaySinh, "");
            strcpy(Person::QueQuan, "");
        }
        void nhap(){
            cout << "Nhap ho va ten: ";
            cin.ignore(1);
            cin.getline(HoTen,50);
            cout << "Nhap ngay sinh: ";
            cin >> NgaySinh;
            cout << "Nhap que quan: ";
            cin.ignore(1);
            cin.getline(QueQuan,100);
        }
        void xuat(){
            cout << "Ho va ten: " << HoTen << endl;
            cout << "Nhap ngay sinh: " << NgaySinh << endl;
            cout << "Nhap que quan: " << QueQuan << endl;
        }
};

class Diem{
    public:
        int toan,ly,hoa;
        Diem(){
            toan = ly = hoa = 0;
        }
        void nhap(){
            cout << "Nhap diem toan: ";
            cin >> toan;
            cout << "Nhap diem ly: ";
            cin >> ly;
            cout << "Nhap diem hoa: ";
            cin >> hoa;
        }
        void xuat(){
            cout << "Diem toan: " << toan << endl;
            cout << "Diem ly: " << ly << endl;
            cout << "Diem hoa: " << hoa << endl;
        }
};

class HocSinh: public Person, public Diem{
    private:
        char Lop[30];
        int TongDiem;
    public:
        HocSinh(){
            Person();
            Diem();
            strcpy(HocSinh::Lop, "");
        }
        void nhap(){
            Person::nhap();
            cout << "Nhap lop: ";
            cin >> Lop;
            Diem::nhap();
            TongDiem = Diem::toan + Diem::ly + Diem::hoa;
        }
        int TinhTongDiem(){
            TongDiem = Diem::toan + Diem::ly + Diem::hoa;
            return TongDiem;
        }
        void xuat(){
            Person::xuat();
            cout << "Lop: " << Lop << endl;
            Diem::xuat();
            cout << "Tong diem: " << TinhTongDiem() << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so hoc sinh: ";
    cin >> n;
    HocSinh hs[n];
    for (int i=0;i<n;i++){
        cout << "Nhap hoc sinh thu " << i+1 << ":" << endl;
        hs[i].nhap();
    }
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << "Hoc sinh thu " << i + 1 << ":" << endl;
        hs[i].xuat();
        cout << "----------------------------------------------" << endl;
    }
    return 0;
}
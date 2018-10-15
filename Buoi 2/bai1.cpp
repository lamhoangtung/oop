#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
        string HoTen, NgaySinh, QueQuan;
        void nhap()
        {
          cout << "Nhap ho va ten: ";
          getline(cin, HoTen);
          cout << "Nhap ngay sinh: ";
          getline(cin, NgaySinh);
          cout << "Nhap que quan: ";
          getline(cin, QueQuan);
        }
        void xuat()
        {
            cout << "Ho va ten: " << HoTen << endl;
            cout << "Ngay sinh: " << NgaySinh << endl;
            cout << "Que quan: " << QueQuan << endl;
        }
};

class KySu: public Person{
    public:
        string NganhHoc;
        int NamTotNghiep;
        void nhap()
        {
          Person::nhap();
          cout << "Nhap nganh hoc: ";
          getline(cin, NganhHoc);
          cout << "Nhap nam tot nghiep: ";
          cin >> NamTotNghiep;
        }
        void xuat(){
            Person::xuat();
            cout << "Nganh hoc: " << NganhHoc << endl;
            cout << "Nam tot nghiep: " << NamTotNghiep << endl;
        }
};

int main(){
    int n;
    cout << "Nhap so luong ki su trong danh sach: ";
    cin >> n;
    cin.ignore(256, '\n');
    KySu engineer[n];
    for (int i=0;i<n;i++){
        cout << "Ki su so " << i+1 << ":" << endl;
        engineer[i].nhap();
        cin.ignore(256, '\n');
    }
    cout << "Danh sach cac ki su la: " << endl;
    int ganNhat=0;
    for (int i=0;i<n;i++){
        cout << "\t- " << engineer[i].HoTen << endl;
        if (engineer[i].NamTotNghiep >= ganNhat){
            ganNhat = engineer[i].NamTotNghiep;
        }
    }
    cout << "Thong tin cua cac ki su tot nghiep gan nhat la: " << endl;
    for (int i=0;i<n;i++){
        if (engineer[i].NamTotNghiep==ganNhat){
            engineer[i].xuat();
            cout << "--------------------------" << endl;
        }
    }
    return 0;
}
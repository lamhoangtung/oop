#include <iostream>
#include <string>

using namespace std;

class HocSinh {
    public:
        string name;
        float diem_toan,diem_van,diem_tienganh,diem_trung_binh;
        
        HocSinh (string s, float a, float b, float c){
            HocSinh::name = s;
            HocSinh::diem_toan = a;
            HocSinh::diem_van = b;
            HocSinh::diem_tienganh = c;
            HocSinh::diem_trung_binh = (a+b+c)/3.0;
        }

        friend bool operator> (HocSinh &a, HocSinh &b){
            if (a.diem_trung_binh>b.diem_trung_binh) 
                return true;
            else 
                return false;
        }

        friend bool operator>= (HocSinh &a, HocSinh &b)
        {
            if (a.diem_trung_binh >= b.diem_trung_binh)
                return true;
            else
                return false;
        }
        
        friend bool operator<= (HocSinh &a, HocSinh &b)
        {
            if (a.diem_trung_binh <= b.diem_trung_binh)
                return true;
            else
                return false;
        }
        
        friend bool operator< (HocSinh &a, HocSinh &b)
        {
            if (a.diem_trung_binh < b.diem_trung_binh)
                return true;
            else
                return false;
        }

        friend bool operator== (HocSinh &a, HocSinh &b)
        {
            if (a.diem_trung_binh == b.diem_trung_binh)
                return true;
            else
                return false;
        }
};

int main(){
    HocSinh a("Hoang Tung Lam",5.2,3.4,7.2);
    HocSinh b("Nguyen Huu Nghia", 5.2, 3.4, 7.2);
    cout << "Lam:" << a.diem_trung_binh << endl;
    cout << "Nghia suc vat: " << b.diem_trung_binh << endl;
    cout << (a == b);
    return 0;
}
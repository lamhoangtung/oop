#include <iostream>

using namespace std;

class Complex
{
    private:
        float PhanThuc;
        float PhanAo;
    public:
        Complex()
        {
            PhanThuc = 0;
            PhanAo = 0;
        }
        Complex(float thuc, float ao)
        {
            PhanThuc = thuc;
            PhanAo = ao;
        }

        friend ostream &operator<<(ostream &out, const Complex &c){
            if (c.PhanAo > 0)
            {
                out << c.PhanThuc << " + " << c.PhanAo << "*i";
            }
            else
            {
                out << c.PhanThuc << " - " << -(c.PhanAo) << "*i";
            }
            return out;
        }
        friend istream &operator>>(istream &in, Complex &c){
            cout << "Nhap phan thuc: ";
            in >> c.PhanThuc;
            cout << "Nhap phan ao: ";
            in >> c.PhanAo;
            return in;
        }

        friend Complex operator+(Complex a, Complex b)
        {
            return Complex(a.PhanThuc + b.PhanThuc, a.PhanAo + b.PhanAo);
        }
};

int main(){
    int n;
    cout << "Nhap so luong so phuc trong mang: ";
    cin >> n;
    Complex a[n],sum;
    for (int i=0;i<n;i++){
        cout << "Nhap so phuc thu " << i+1 << ":" << endl;
        cin >> a[i];
        sum = sum + a[i];
    }
    cout << "Mang cac so phuc vua nhap la: " << endl;
    for (int i=0;i<n;i++){
        cout << "* " << a[i] << endl;
    }
    cout << "Tong cua cac so phuc la: " << sum << endl;
    return 0;
}
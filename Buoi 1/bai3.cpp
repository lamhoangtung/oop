#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Points{
    string name;
    float x,y;
    friend float distance(Points &a, Points &b){
        return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
    }
    public:
        void input();
        void output();
};

void Points::input(){
    cout << "Nhap ten diem: ";
    cin >> name;
    cout << "Nhap toa do x cua " << name << ": ";
    cin >> x;
    cout << "Nhap toa do y cua " << name << ": ";
    cin >> y;
}

void Points::output(){
    cout << name << "(" << x << ", " << y << ")";
}

int main(){
    Points a,b;
    a.input();
    b.input();
    cout << "Khoang cach giua 2 diem ";
    a.output();
    cout << " va ";
    b.output();
    cout << " la " << distance(a,b) << endl;
    return 0;
}
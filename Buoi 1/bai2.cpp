#include <iostream>

using namespace std;

int DayOfMonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

class Time
{
    int day, month, year;
    public:
        void input();
        void output();
        void nextday();
        bool oddyear();
        bool validtime();
};

void Time::input()
{
    cout << "Input Day: ";
    cin >> day;
    cout << "Input Month: ";
    cin >> month;
    cout << "Input Year: ";
    cin >> year;
    while (validtime()==false){
        cout << "Date and time invalid. Please type another one!" << endl;
        cout << "Input Day: ";
        cin >> day;
        cout << "Input Month: ";
        cin >> month;
        cout << "Input Year: ";
        cin >> year;
    }
}

void Time::output()
{
    cout << day << "/" << month << "/" << year << endl;
}

bool Time::oddyear(){
    return ((year%4==0 && year%100==0)||(year%400==0));
}

bool Time::validtime(){
    if (year<0) return false;
    if (month<=0 || month>12) return false;
    if (day<=0 || day>DayOfMonth[month-1]) return false;
    if (oddyear()==false && month==2 && day>28) return false;
    return true;
}

void Time::nextday()
{
    if (month==12 && day==DayOfMonth[month-1]){
        day=1;
        month=1;
        year++;
    }
    else if (oddyear()==true && month==2 && day==28){
        day++;
    }
    else if (oddyear()==false && month==2 && day ==28){
        month++;
        day=1;
    }
    else if (day == DayOfMonth[month-1]){
        month++;
        day=1;
    }
    else{
        day++;
    }
    cout << "Increased one day!" << endl;
}

int main()
{
    Time dateandtime;
    dateandtime.input();
    dateandtime.nextday();
    dateandtime.output();
    return 0;
}
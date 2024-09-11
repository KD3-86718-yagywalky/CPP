#include<iostream>
using namespace std;

class Date {
    public:
    int date;
    int month;
    int Year;

    
};

void acceptDateFromConsole(struct Date *ptrDate)
{
    cout<<"Enter of day,month and year :- ";
    cin>>ptrDate->date>>ptrDate->month>>ptrDate->Year;
}

void printDateFromConsole(struct Date *ptrDate){
    cout<<"The date you have entered "<<ptrDate->date<<"/"<<ptrDate->month<<"/"<<ptrDate->Year;
}

void initDate(struct Date *ptrDate)
{
   ptrDate->date =1;
   ptrDate->month =1;
   ptrDate->Year =1990;
   cout<<"Default date \n"<<ptrDate->date<<"/"<<ptrDate->month<<"/"<<ptrDate->Year;
}

bool IsLeapYear(struct Date *ptrYear)
{
    if (ptrYear->Year%4==0 && ptrYear->Year%400==0)
    {
        cout<<"It is a leap year"<<endl;
        return true;
    }
    else
    {
        cout<<"It is not a leap year"<<endl;
        return 0;
    }
    
}

int menu()
{
    int choice;
    cout << "0. EXIT" << endl;
    cout << "1. ADD TIME" << endl;
    cout << "2. DISPLAY TIME" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Date t1;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            acceptDateFromConsole(&t1);
            cout<<endl;
            break;
        case 2:
            printDateFromConsole(&t1);
            cout<<endl;
            IsLeapYear(&t1);
            cout<<endl;
            break;
        default:
            initDate(&t1);
            break;
        }
        IsLeapYear(&t1);
    }
    return 0;
}
#include<iostream>
using namespace std;

class Date{
    int date;
    int month;
    int year;

    public:

    Date():date(0),month(0),year(0){}

    Date(int date,int month,int year){
        this->date=date;
        this->month=month;
        this->year=year;
    }

    void AcceptValues(){
        cout<<"Enter date :-  ";
        cin>>date;
        cout<<"Enter Month :-  ";
        cin>>month;
        cout<<"Enter year :-  ";
        cin>>year;
    }

    void displayValues(){
        cout<<date<<":"<<month<<":"<<year<<endl;
    }
      void setDay(int date)
    {
        this->date = date;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

};

class Person{
    string name;
    string address;
    Date Birthdate;

    public:

    Person():name(" NA"),address("NA"){}

    Person(string name,string address, int date, int month, int year){

        this->address=address;
        this->name=name;
        this->Birthdate.setDay(date);
        this->Birthdate.setMonth(month);
        this->Birthdate.setYear(year);
    }
    
    void Acceptdetails(){
        cout<<"Enter name :- ";
        cin>>name;
        cout<<"Enter address :- ";
        cin>>address;
        cout<<"Birthdate Details :- "<<endl;

        Birthdate.AcceptValues();
    }

    void displaydetails(){
        cout<<"Name :- "<<name<<endl;
        cout<<"Address:- "<<address<<endl;
        
        Birthdate.displayValues();

    }
};

int main(){
    Person p1;
    p1.Acceptdetails();
    p1.displaydetails();

    Person p2("saksham","Near sector 76, noida",06,12,2001);
    p2.displaydetails();
    return 0;
}
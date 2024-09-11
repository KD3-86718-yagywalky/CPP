#include<iostream>
using namespace std;

class Address {
    string building;
    string state;
    string city;
    int PinCode;
    public:
    //constructor
    Address(string building,string state,string city,int pincode){

        this->building=building;
        this->state= state;
        this->city = city;
        this->PinCode = pincode;

    }

    //getters
    int Getters(){
        return PinCode;
    }

    void Setters(int n)
    {
        this->PinCode =n;
    }
    void accept(){
        cout<<"Enter Full Address :- ";
        cin>>building>>state>>city>>PinCode;
    }

    void Display(){
        cout<<"Building name :- "<<building<<endl;
        cout<<"State :- "<<state<<endl;
        cout<<"city :- "<<city<<endl;
        cout<<"pincode :- "<<PinCode<<endl;
    }
};

int main(){

    Address A1("Apna","Madhya pradesh","Katni",483501);
    A1.Display();
    cout<<endl;
    A1.Setters(482001);
    cout<<endl;
    cout<<"Changed Pin Code :- "<<A1.Getters()<<endl;
    cout<<endl;
    A1.Display();

    return 0;
}
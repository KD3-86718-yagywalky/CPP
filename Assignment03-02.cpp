#include<iostream>
using namespace std;

class tollbooth{
    unsigned int payingCars;
    unsigned int nopayCars;
    double amount=0.5 ;
    unsigned int TotalCars;
    

    public:

    tollbooth(): payingCars(0),nopayCars(0),amount(0.0),TotalCars(0){}
    
    void payingCar(){
        payingCars++;
        amount+=0.5;
        TotalCars++;

    }

    void nopayCar(){
        nopayCars++;
        TotalCars++;

    }
    void printOnConsole(){
        cout<<"total number of cars passed :- "<<TotalCars<<endl;
        cout<<"total number of paying Cars :- "<<payingCars<<endl;
        cout<<"total number of nopaying Cars :- "<<nopayCars<<endl;
        cout<<"total amount collected :- Rs."<<amount<<endl;

    }


};


int main(){
   tollbooth t1;

   t1.payingCar();
   t1.nopayCar();
   t1.payingCar();
   t1.payingCar();
   t1.payingCar();
   t1.nopayCar();

    t1.printOnConsole();

    return 0;
}
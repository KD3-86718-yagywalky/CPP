#include<iostream>
using namespace std;

class Time{
    int hrs;
    int mins;
    int sec;
public:
    Time()
    {
        hrs = 00;
        mins = 00;
        sec = 00;

    }
    Time(int h, int m, int s){
        this->hrs=h;
        this->mins=m;
        this->sec=s;
    }
    int getHours(){
        return hrs;
    }

    int getMinute(){
        return mins;
    }

    int getSeconds(){
        return sec;
    }

    void setHours(int H){
        this->hrs=H;
    }

    void setMinutes(int M){
        this->mins=M;
    }

    void setSecond(int S){
        this->sec=S;
    }
    
    void printTime()
    {
        cout<<"Time enter by you in Hours:minutes:seconds "<<hrs<<":"<<mins<<":"<<sec<<endl;
    }
};

int main(){
    Time **T1= new Time *[5];
    T1[0]= new Time();
    T1[1]=new Time(12,44,56);
    T1[2]= new Time(05,04,56);
    T1[3]->setHours(07);
    T1[3]->setMinutes(50);
    T1[3]->setSecond(59);
    T1[3]->printTime();
    T1[4]->setHours(01);
    T1[4]->setMinutes(32);
    T1[4]->setSecond(60);
    

    for(int i=0;i<6;i++){
        T1[i]->printTime();
        cout<<endl;
    }
    cout<<"Time by getters and setters : "<<T1[4]->getHours()<<":"<<T1[4]->getMinute()<<":"<<T1[4]->getSeconds()<<endl;

    for (int i=0;i<6;i++){
        delete T1[i];
        T1[i]= NULL;
    }
    delete[] T1;
    T1=NULL;

    return 0;
}
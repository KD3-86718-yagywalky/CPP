#include<iostream>
using namespace std;

class Volumn
{
private: int length;
        int width;
        int height;
            
public:

        int vol;
    Volumn(){
        length = 9;
        width = 8;
        height= 8;

        this->vol =length*width*height;

    }
    Volumn(int value){
        length = value;
        width = value;
        height = value;

        this->vol = length*width*height;
    
    }

    Volumn(int n,int m, int o)
    {
        length = n;
        width = m;
        height = o;
        this->vol = length*width*height;
        

    }

    void display(){
            cout<<"Area :- "<<vol<<endl;
    }


};

int menu(){
    
    int choice;
    cout << "1. Default" << endl;
    cout << "2. For same Parameters" << endl;
    cout << "3. For Different Parameters" << endl;
        cout << "Enter your choice - ";
    cin >> choice;
    return choice;

}

int main(){
        
        int choice;

        choice = menu();
         
         if (choice==1)
         {
            Volumn v1;
            v1.display();
            cout<<endl;

         }
         else if (choice ==2)
         {
            int x;
            cout<<"Enter Value :- ";
            cin>>x;
           Volumn v2(x);
            v2.display();
            cout<<endl;


         }

          else if (choice ==3)
         {
            int a,b,c;
            cout<<"Enter Length :- ";
            cin>>a;
             cout<<"Enter Width :- ";
            cin>>b;
             cout<<"Enter Height :- ";
            cin>>c;
           Volumn v3(a,b,c);
            v3.display();
            cout<<endl;
         }
         else {
            cout<<"Input wrong value "<<endl;
         }  
         cout<<"Thank You"<<endl;
      return 0;   
}

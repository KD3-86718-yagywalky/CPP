#include<iostream>
using namespace std;

class InSufficientFundException
{
    int accno;
    double currentBalance;
    double withdrawAmount;

    public : 

    InSufficientFundException(int accno, double currentBalance, double withdrawAmount)
    {
        this->accno=accno;
        this->currentBalance=currentBalance;
        this->withdrawAmount = withdrawAmount;
    }

    void display()
    {
        cout<<" For Account Number :- "<<accno<<endl;
         cout<<" You try to Withdraw Balance :- "<<withdrawAmount;
        cout<<" But your Current Balance is :- "<<currentBalance<<endl;
       

    }

};

enum EAccountType{
    SAVING,
    CURRENT,
    DMAT

};

class Account
{
    int accno;
    EAccountType Account_type;
    double balance;

    public :

    Account():accno(0),Account_type(SAVING),balance(0.0){}

    Account(int accno, EAccountType type, double balance ): accno(accno),Account_type(type),balance(balance){}

    int getAccno()
    {
        return accno;
    }

    void accept()
    {   
        int x;
        cout<<"Enter Account Number :- ";
        cin>>accno;
        cout<<endl;

        cout<<"Enter type of Account "<<endl;
        cout<<"(0. SAVING , 1.CURRENT , 2.DMAT)  :- ";
        cin>>x;
        if(x<0 && x>2)
        {
            throw invalid_argument ("Wrong Input");
        }

        Account_type=static_cast<EAccountType>(x);

        cout<<"Enter balance :- ";
        cin>>balance;

        if(balance<0)
        {
            throw invalid_argument ("Cannot input negetive Balance ");
        }
    }

        void display()
        {
            cout<<"Account Number :- "<<accno<<endl;
            cout<<"Account Number :- "<<(Account_type == SAVING ? "SAVING" : Account_type == CURRENT ? "CURRENT " : "DMAT")<<endl;
            cout<<"Your balance :- "<<balance<<endl;
        }


        void deposit(double amount)
        {
            if(amount <0){
                throw invalid_argument("Cannot enter negative value ");
            }
            balance = balance + amount;
            cout<<"Successfully submitted! Now your balance :- "<<balance<<endl;
        }

        void withdraw(double amount)
        {
            if(amount <=0){
            throw invalid_argument("Cannot Enter 0 or negaltive values ");
            }

            if(amount>balance)
            {
                throw InSufficientFundException(accno,balance,amount);
            }

            balance = balance - amount;
            cout<<"Successfully Withdrawal ! Your present amount :- "<<balance<<endl;
        }

};

int menu(int choice)
{
    cout<<"0.Exit "<<endl;
    cout<<"1. Deposit"<<endl;
    cout<<"2. withdrawel"<<endl;
    cout<<"3. Display Account"<<endl;
    cout<<"Enter your choice :- ";
    cin>>choice;
    return choice;
}

int main()
{
    Account arr[5];
    int choice;
    int amount;
    int Index;

    try{
        for(int i=0;i<5;i++)
        {
            arr[i].accept();
        }
    }

    catch(invalid_argument& e)
    {
        cout<<" Error :"<<e.what()<<endl;
    }

    while((choice=menu(choice))!=0)
    {
        switch(choice)
        {
            case 1: 
                
                cout<<"Enter account Index for deposit (0-4) ";
                cin>>Index;

                if(Index<0 || Index>4)
                {
                    cout<<"Wrong Index ......"<<endl;
                    break;
                }
                cout<<"Enter deposit Amount :- ";
                cin>>amount;

                try{
                arr[Index].deposit(amount);
                }

                catch(invalid_argument& e)
                {
                    cout<<"Error :"<<e.what()<<endl;
                }
                break;

            case 2: 
                   cout<<"Enter account Index for Withdrawel ";
                cin>>Index;

                if(Index<0 || Index>4)
                {
                    cout<<"Wrong Index ......"<<endl;
                    break;
                }   
                cout<<"Enter amount for withdrawel : - ";
                cin>>amount;

                try
                {
                    arr[Index].withdraw(amount);
                }
                catch(InSufficientFundException& e)
                {
                    e.display();
                }
                catch(invalid_argument& e)
                {
                    cout<<"Error : "<< e.what() << '\n';
                }
                break;

            case 3: 
               cout<<"Enter account Index for display ";
                cin>>Index;

                if(Index<0 || Index>4)
                {
                    cout<<"Wrong Index ......"<<endl;
                    break;
                }

                arr[Index].display();
                break;    
            
            default:
                    cout<<"Enter wrong Number ......"<<endl;
                    break;
                          
               
        }
    }
    
    return 0;
}




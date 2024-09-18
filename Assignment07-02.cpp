#include<iostream>
using namespace std;

class Employee
{
    int empID;
    double salary;

    public:
    Employee():empID(0),salary(0.0){}

    Employee(int empID, double salary):empID(empID),salary(salary){}

    void setID(int empID)
    {
        this->empID=empID;
    }

    void setSalary(double salary)
    {
        this->salary=salary;
    }

    int getempID()
    {
        return empID;
    }

    double getSalary()
    {
        return salary;
    }

virtual void accept()
{
    cout<<"Enter employee ID :- ";
    cin>>empID;
    cout<<endl;
    cout<<"Enter employee salary :- ";
    cin>>salary;
    cout<<endl;
}

virtual void display()
{
    cout<<"EmpID :- "<<empID<<endl;
    cout<<"Salary :- "<<salary<<endl;

}
};

class Manager : virtual public Employee
{
 double bonus;

protected:

void acceptManager()
{
    cout<<"Bonus get by manager :- ";
    cin>>bonus;
    cout<<endl;
}

void displayManager()
{
    cout<<" Bonus :- "<<bonus<<endl;
}
 public :

 Manager():bonus(0){}

 Manager(int empID, double salary, double bonus):Employee(empID,salary)
 {
    this->bonus= bonus;
 }

void setManager(double bonus)
{
    this->bonus=bonus;

}

double getManager()
{
    return bonus;
}

virtual void accept()
{
    Employee::accept();
    cout<<"Bonus get by manager :- ";
    cin>>bonus;   
}

virtual void display()
{
    Employee::display();
    cout<<"Bonus :- "<<bonus<<endl;

}

};

class Salesman : virtual public Employee
{
        int comm;

    protected:

    void acceptSalesman()
    {
        cout<<"Total Commission received by Salesman :- ";
        cin>>comm;
        cout<<endl;
    }

    void displaySalesman()
    {
        cout<<" Commission :- "<<comm<<endl;
    }

    public:

    Salesman():comm(0){}

    Salesman(int empID, double salary, double comm):Employee(empID,salary)
    {
        this->comm= comm;
    }

    void setCommission(double comm)
    {
        this->comm = comm;
    }

    double getCommission()
    {
        return comm;
    }

    virtual void accept()
    {
        Employee::accept();

        cout<<"Total Commission received by Salesman :- ";
        cin>>comm;
        
    }

    virtual void display()
    {
        Employee::display();

        cout<<" Commission :- "<<comm<<endl;
    }

};

class Salesmanager : public Manager, public Salesman
{
    public:

    Salesmanager(){}

    Salesmanager(int empID, double salary , double bonus , double comm)
    {

    }

    void accept()
    {
        Manager::accept();
        acceptSalesman();
    }

    void display()
    {
        Manager::display();
        displaySalesman();
    }
};

void countManager(Employee **arr, int index)
{
    int countE=0;
    int countS=0;
    int countSM=0;
    for(int i=0; i<index; i++)
    {
        if(typeid(*arr[i])==typeid(Manager))
        {
            countE++;
            
        }
        else if((typeid(*arr[i])==typeid(Salesman)))
        {
            countS++;
        }
        else
        {
            countSM++;
        }

        
    }
    cout<<"Total Manager :- "<<countE<<endl;
    cout<<"Total salesman :- "<<countS<<endl;
    cout<<"Total salesManager :- "<<countSM<<endl;
}


int main()
{
    Employee *arr[5];
    int index=0;
    // cout<<"size of array :- ";
    // cin>>index;
    int choice;

    do
    {
    cout<<"0.Exit "<<endl;
    cout<<"1. Accept Employee "<<endl;
    cout <<"2.Display the count of all employees with respect to designation  "<<endl;
    cout<<"3.Display all manager "<<endl;
    cout<<"4.Display all salesman"<<endl;
    cout<<"5. Display all salesmanager "<<endl;
    cout<<"Enter Your choice "<< endl;
    cin>>choice;
        switch(choice)
        {
            case 1: char ch;
                    do{
                            cout<<"a.Accept Manager "<<endl;
                            cout<<"b. Accept Salesman"<<endl;
                            cout<<"c.Accept Salesmanager "<<endl;
                            cout<<"e. Exit"<<endl;
                            cout<<"Enter your choice ";
                            cin>>ch;

                    switch(ch)
                    {
                        case 'a': if(index<5){

                            arr[index] = new Manager;
                            arr[index]->accept();
                            index++;
                            
                            }
                            else {
                                cout << "Array is full.....";
                            }
                            break;

                         case 'b': if (index<5)
                         {
                            arr[index] = new Salesman;
                            arr[index]->accept();
                            index++;
                         }
                         break;

                         case 'c': if(index<5)
                         {
                            arr[index] = new Salesmanager;
                            arr[index]->accept();
                            index++;
                         }
                         break;

                         case 'e': cout<<"Thank You ....";
                         break;

                         default : cout<<"Wrong Input ......";
                         break;
                            
                    }
                    } while(ch!='e');

                    break;

             case 2: 
             
                    countManager(arr , index); 
                    break;

             case 3:
                 
                  for(int i=0; i<index; i++)
                 {
                    if(typeid(*arr[i])==typeid(Manager))
                    {
                        arr[i]->display();
                    }
                 } 
                 break;
    
             case 4:  
             
                     for( int i= 0; i<index; i++)
                    {
                        if(typeid(*arr[i])==typeid(Salesman))
                        {
                            arr[i]->display();

                        }
                    }  
                    break;
            
            case 5: 

                    for(int i=0 ; i<index; i++)
                    {
                        if(typeid(*arr[i])==typeid(Salesmanager))
                        {
                            arr[i]->display();
                        }
                    }
                    break;

            default : 
            
                    cout<<"Wrong Input ......."; 
                    break;     
        }

    } while(choice !=0);

    return 0;
    
}
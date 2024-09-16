#include<iostream>
using namespace std;

class Employee{
    int empID;
    double sal;
    public:
    Employee():empID(0),sal(0){}

    Employee(int empId, int sal)
    {
        this->empID=empID;
        this->sal=sal;
    } 

     void setempID(int ID)
    {
        this->empID = ID;      
    }

    int getID()
    {
        return empID;
    }

     void setSalary(int sal)
    {
        this->sal=sal;
    }

     double getSalary()
    {
        return sal;
    }

    virtual void accept()
    {
        cout<<"Enter employee ID :- ";
        cin>>empID;
        cout <<endl;
        cout<<"Enter Salary of employee :- ";
        cin>>sal;
        cout<<endl;
    }

    virtual void display()
    {
        cout<<" Employee ID :- "<<empID<<endl;
        cout<<"Salary :- "<<sal<<endl;
    }
};

class Manager:public Employee
{
private:
    double bonus;


public:
    Manager():bonus(0){};

    Manager(int empID, double sal, double bonus)
    {
        setempID(empID);
        setSalary(sal);
        this->bonus=bonus;
        
    }

    void setBonus(double bonus)
    {
        this->bonus=bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        Employee::accept();
        cout<<"Enter employee Bonus :- ";
        cin>>bonus;
    }

    void display()
    {
        Employee::display();
        cout<<"Bonus :- "<<bonus<<endl;
    }

         void acceptManager()
     {  
        cout<<"Enter Bonus :- ";
        cin>>bonus;
        cout<<endl;
     }

     void displayManager()
     {
        cout<<"Bonus :- "<<bonus<<endl;
     }


};

class Salesman : public Employee{
    private: 

    double comm;

    public:
    
     Salesman():comm(0){}

     Salesman(int ID, double sal, double comm)
     {
        setempID(ID);
        setSalary(sal);
        this->comm = comm;
     }
     void setCommission(double comm)
     {
        this->comm=comm;
     }

     double setCommission()
     {
        return comm;
     }

     virtual void accept()
     {
        Employee::accept();
        cout<<"Commission ";
        cin>>comm;
        cout<<endl;

     }

    virtual void display()
     {
        Employee::display();
        cout<<"Commission :- "<<comm<<endl;

     }

     void acceptSalesman()
     {
        cout<<"Enter Commission :- ";
        cin>>comm;
        cout<<endl;
     }

     void displaySalesman()
     {
        cout<<"Commission :- "<<comm<<endl;
     }

};

class SalesManager : public Manager,public Salesman

{   public:

    SalesManager(){}

    SalesManager(int empID, double sal, double bonus, double comm)
    {
        
        Manager(empID,sal,bonus);
        Salesman(empID,sal,comm);
    }

    void accept()
    {
        Manager::accept();
        Salesman::acceptSalesman();
    }

    void display()
    {
        Manager::display();
        Salesman::displaySalesman();
    }


};

int main()
{
    SalesManager s1;

    s1.accept();
    s1.display();
    return 0;
}



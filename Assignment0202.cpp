#include<iostream>
using namespace std;


class Student {
public:
    int roll_no;
    string name;
    int marks;

    void initStudent(){
          int roll = 0;
          char name =' ';
          int marks = 0;
          cout<<"Default student values:-"<<roll<<name<<marks; 

    }
    void acceptStudentFromConsole(){
        cout<<"Enter student details:- ";
        cin>>roll_no>>name>>marks;
    }

    void printStudentOnConsole(){
        cout<<"roll number of student :- "<<roll_no<<endl;
        cout<<"roll name of student :- "<<name<<endl;
        cout<<"roll marks of student :- "<<marks<<endl;
    }
};

int menu(){
    
    int choice;
    cout << "0. EXIT" << endl;
    cout << "1. Student Details" << endl;
    cout << "2. DISPLAY Student Details" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    return choice;

}

int main(){
    int choice;
    struct Student s1;

    while ((choice = menu())!=0)
    {
        switch (choice)
        {
        case 1:
            s1.acceptStudentFromConsole();
            cout<<endl;
            break;
        case 2:
            s1.printStudentOnConsole();
            cout<<endl;
            break;

        default:
            s1.initStudent();
            cout<<endl;

            break;
        }
        
    }
    cout<<"thanks"<<endl;

    return 0;
}



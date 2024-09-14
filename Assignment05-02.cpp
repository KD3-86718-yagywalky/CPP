#include<iostream>
using namespace std;

class Student {

     public:
    string name;
    string gender;
    int arr[3];
    double average;
    int rollNumber;
    static int auto_generation;

   

    Student():rollNumber(++auto_generation)
    {
        name = " ";
        gender = " ";
        arr[0]=0;
        arr[1]=0;
        arr[2]=0;

    }

    Student(string name, string gender, int marks1,int marks2,int marks3):rollNumber(++auto_generation)
    {
        this->name = name;
        this->gender=gender;
        arr[0]=marks1;
        arr[1]=marks2;
        arr[2]=marks3;
        average = (arr[0]+arr[1]+arr[2])/3;
    }

    void AcceptDetails(){
        cout<<"Enter name :- ";
        cin>>name;
        cout<<endl;
         cout<<"Enter gender :- ";
        cin>>gender;
        cout<<endl;
         cout<<"Enter 1st subject marks :- ";
        cin>>arr[0];
        cout<<endl;
         cout<<"Enter 2st subject marks :- ";
        cin>>arr[1];
        cout<<endl;
         cout<<"Enter 3st subject marks :- ";
        cin>>arr[2];
        cout<<endl;
        
    }

    void displayDetails()
    {
        cout<<"Name :- "<<name<<endl;
        cout<<"RollNumber :- "<<rollNumber<<endl;

        cout<<"Gender :- "<<gender<<endl;
        cout<<"Percentage :- "<<((arr[0]+arr[1]+arr[2])/3)<<endl;
        cout<<endl;
    }
    
   

};

int searchDetails(Student* arr[], int n, int rollNumber) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] != nullptr && arr[i]->rollNumber == rollNumber) {
                return i;
            }
        }
        return -1;
    }

int menu(int choice){
        cout << "Student details :- ";
        cout << "1. Exit"<<endl;
        cout << "2. Add Student"<<endl;
        cout << "3. Print All Students"<<endl;
        cout << "4. Search Student by Roll Number"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        return choice;
}


int Student::auto_generation = 2000;



int main()
{
    Student *arr[5];
    int choice;
    
    
    while((choice =menu(choice)) !=1){

    switch (choice)
    {
    case 1: cout<<"Thank you "<<endl;
        break;
    case 2:
     arr[0]=new Student();
     arr[0]->AcceptDetails();
    
     arr[1]=new Student("Aditya","male",75,65,55);
    
     arr[2]=new Student("Deependra","male",66,77,55);
     
     arr[3]=new Student("Anirudh","male",42,64,56);

    arr[4]=new Student("Shreya","Fwmale",35,45,48);
       
        break;

     case 3:    
            for(int i=0; i<5;i++)
            {
              arr[i]->displayDetails();

            }
            break;

     case 4: 
                int rollNumber;
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                int i;
                i = searchDetails(arr,5,rollNumber);
                if (i >=0) {
                    arr[i]->displayDetails();
                } else {
                    cout << "Student with roll number " << rollNumber << " not found." << endl;
                }
                break;

     default:cout<<"Entered a wrong value"<<endl;
            break;
         }

    }
   
      for(int i=0; i<5;i++)
      {
        delete arr[i];
        arr[i]=NULL;
      }
      cout<<"Thank You"<<endl;

    return 0;    
}
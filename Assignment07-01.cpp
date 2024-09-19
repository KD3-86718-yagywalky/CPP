#include<iostream>
using namespace std;

class Product{

    int ID;
    string title;

    public :
    double price;

    Product():ID(0),title(" "){}

    Product(int ID, string title,double price):ID(ID),title(title),price(price){ }

    virtual void accept()
    {
        cout<<" ID of the product :- ";
        cin>>ID;
        cout<<endl;

        cout<<"Title of the product :- ";
        cin>>title;
        cout <<endl;

         cout<<"Price of the product :- ";
        cin>>price;
        cout <<endl;
                
    }

    virtual void display()
    {
        cout<<"ID :- "<<ID<<endl;
        cout<<"title :- "<<title<<endl;
        cout<<"price :- "<<price<<endl;
    }

    void getID(int id)
    {
        this->ID = id;
    }

    void getTitle(string title)
    {
        this->title = title;
    }

    int setId()
    {
        return ID;
    }

    string setTilte()
    {
        return title;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    double getPrice()
    {
        return price;
    }


};

class Book : public Product
{
    string author;

    public :

    Book():author(" "){}

    Book(int ID , string title, string author, double price): Product(ID,title,price),author(author){}

    void accept()
    {   
        Product::accept();
        this->author = author;
        cout<<"Enter author name :- ";
        cin>>author;
    }

    void display()
    {
        Product::display();
        cout<<" Author :- "<<author<<endl;
        cout <<" Real price of the Book :- "<<price<<endl;
    

    }

    
};

class tapes: public Product
    {
        string artist;

        public:

        tapes():artist(""){}

        tapes(int ID, string title, string artist, double price)
        {
            this->getID(ID);
            this->getTitle(title);
            this->artist=artist;
            this->price = price;
        }

        void accept()
        {
            Product::accept();
            cout<<" Enter name of the artist :- ";
            cin>>artist;
            cout<<endl;

        }

        void display()
        {
            Product::display();
            cout<<"Artist :- "<<artist<<endl;
            cout<<" Actual price of tape :- "<<price<<endl;

        }
        
    };

    int menu(int choice)
    {
          cout << "*******************" << endl;
        cout<<"0. For not buying anything "<<endl;
        cout<<"1. For buy Books "<<endl;
        cout<<"2. For buy tape "<<endl;
        cout<<"3.display all purchase order bill "<<endl;
        cout<<"Enter your choice :- ";
        cin>>choice ;
        return choice;
          cout << "*******************" << endl;
    }

    int main()
    {   
        int many;
        cout<<"How much product you want to buy :- ";
        cin>>many;
        Product *arr[many];
        int index=0;
        
        int choice ;
        while((choice = menu(choice))!=0)
        {
            switch(choice)
            {
                case 1: 
                if(index<many)
                {
                     arr[index] = new Book;
                     arr[index]->accept();
                    index++;
                }
                else {
                    cout << "Array is full .....";
                }
                break;

                case 2:
                         if(index<many)
                         {
                             arr[index]=new tapes;
                             arr[index]->accept();
                             index++;
                         }
                         else {
                             cout<<"Array is full.....";
                         }

                        break;


                
                case 3:
                    {

                        double Total = 0;

                        for(int i=0; i<index;i++){
                        if(typeid(*arr[i])==typeid(Book)){

                            arr[i]->display();
                            Total = Total + (arr[i]->getPrice()*0.90);
                        }

                        else if(typeid(*arr[i])==typeid(tapes))
                        {   
                            arr[i]->display();
                            Total = Total + (arr[i]->getPrice()*0.95);
                        }
                        else{
                            cout<<endl;
                        }
                        }

                        cout<<"Total amount :- "<<Total<<endl;
                    }
                       break;
                
                default :
                       cout<<"Wrong Input ......";
                       break;

        }
        }

        for(int i=0; i<index; i++)
        {
            delete arr[i];
            arr[i]=NULL;
        }

        return 0;
    }   



    
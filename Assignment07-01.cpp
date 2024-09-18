#include<iostream>
using namespace std;

class Product
{
    public:
    int id;
    string title;
    double price;

Product()
{
    id=0;
    title="xyz";
    price=10;
}
Product(int x,string y,int p)
{
    this->id=x;
    this->title=y;
    this->price=p;
}
virtual void accept()
{
    cout<<"Enter product Id :";
    cin>>id;
    cout<<"Enter product Title :";
    cin>>title;
    cout<<"Enter product Price :";
    cin>>price;
}
virtual void display()
{
    cout<<"product Id :"<<id<<endl;
    cout<<"product Title :"<<title<<endl;
    cout<<"product Price :"<<price<<endl;
}
};

class Book :public Product
{
    string auther;
public:
Book()
{
    auther="aaaah";
}
Book(int id,string title,double price,string auther):Product(id,title,price)
{
   this->auther;
}
void accept()
{
    cout<<"Enter the detail of Book product :"<<endl;
    Product::accept();
    cout<<"Enter Auther name :";
    cin>>auther;
}
double calculatediscountPrice(double price)
{ 
    return price-price*.9;
}
void display()
{
     Product::display();
     cout<<"Auther name :"<<auther<<endl;
}
};
class Tape:public Product
{
    string artist;

public:
Tape()
{
    artist="ZZ";

}
Tape(int id,string title,double price,string artist):Product(id,title,price)
{
    this->artist=artist;
}
void accept()
{
    cout<<"Enter the detail of Tape product :"<<endl;
    Product::accept();
    
    cout<<"Enter Artist name :";
    cin>>artist;
}

void display()
{
    cout<<"Display the detail of Book product :"<<endl;
     Product::display();
     cout<<"Artist name :"<<artist<<endl;
}
};

int main()
{

    Product * arr[3];
    int choice;
    for(int i = 0; i<3;i++)
    { 
        cout<<"0. for buy Book"<<endl;
        cout<<"1. for buy tape"<<endl;
        cin>>choice;
        if(choice==0)
        {
        arr[i]=new Book();
        arr[i]->accept();
        }
        else if(choice==1)
        {
            arr[i]=new Tape();
            arr[i]->accept();
        }
        else
        {
            cout<<"wrong choice......."<<endl;
        }
    }

    for(int i=0;i<3;i++)
    {
        arr[i]->display();
    }

    double total=0;
    double totaldiscount=0;
    double x;
    for(int i=0;i<3;i++)
    {
        if(typeid(arr[i])==typeid(Book))
        {
        x= arr[i]->price;
        total+=x;
        totaldiscount+=x*.90;
        }
        else{
        x= arr[i]->price;
        total+=x;
        totaldiscount+=x*.95;
        }

    }
    cout<<"Total Price :"<<total<<endl;
    cout<<"Discounted Price :"<<totaldiscount;
    return 0;

}
  
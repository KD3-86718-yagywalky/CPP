#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
   int size;
   int top;
   int *array;

   public:

   Stack(int size =5){
      this->size=size;
      top = -1;
      array=new int [size];
   }
   ~Stack(){
         delete[]array;
   }

   void push(int value){
      
      
      if(top<size){
      top++;
      cout<<"value is push by you at :- "<<top<<" place in array"<<endl;
      this->array[top]=value;
   
      }
      else{
         isFull();
      }
   }
   void pop(){
     if(top<0){
      isEmpty();
     }
     else {
      cout<<"You pop the value :- "<<array[top]<<endl;
      top--;
      array[top];
     }
   }
   void peek(){
      cout<<"Peek value : "<<array[--top]<<endl;
   }
   void isEmpty(){
      cout<<"array is Empty now"<<endl;
   }
   void isFull(){
      cout<<"Array is full Can not input more values"<<endl;
   }
   void print(){

      for (int i=0; i<=top;i++){
         cout<<"value of array at  "<<i<<" point is :- "<<array[i]<<endl;
      }
   }
   

};

int main(){
   Stack s1(3);
   s1.push(18);
   s1.push(25);
   s1.push(10);
   s1.push(10);
   s1.peek();
   s1.print();
   s1.pop();
   s1.pop();
   s1.pop();
   s1.pop();
   s1.pop();
   s1.print();
   cout<<"successfully done"<<endl;
return 0;
}
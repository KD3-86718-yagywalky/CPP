#include<stdio.h>

struct Date {
    int date;
    int month;
    int Year;
};

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter of day,month and year :- ");
    scanf("%d%d%d", &ptrDate->date,&ptrDate->month,&ptrDate->Year);
}

void printDateFromConsole(struct Date *ptrDate){
    printf("The date you have entered:- %d/%d/%d \n", ptrDate->date,ptrDate->month,ptrDate->Year);
}

void initDate(struct Date *ptrDate)
{
   int date =1;
   int month =1;
   int Year =1990;
   printf("Default date :- %d/%d/%d \n",date,month,Year);
}
int menu(){
    int choice;
    printf("0. default \n");
    printf("1. ADD TIME \n");
    printf("Enter your choice - ");
    scanf("%d",&choice);
    return choice;
}

int main(){
    int choice;
    struct Date d1;
    choice=menu();

    if(choice==1)
    {
    acceptDateFromConsole(&d1);
    printDateFromConsole(&d1);
    }
    else{
    initDate(&d1);
    }

    return 0;
}
#include<iostream>
#include<string>
using namespace std;

struct customer{
    string name;
    int account_no;
    int balance=0;
};


void addcustomer(customer &c){
    cout<<"Enter customer ID:";
    cin>>c.name;
    cout<<"Enter Account number:";
    cin>>c.account_no; 
    cout<<"Enter Balance:";
    cin>>c.balance;   
}

void print(customer c){
   cout<<"Name="<<c.name<<"  Account Number="<<c.account_no<<"   Balance="<<c.balance<<endl; 
}

void deposit(int account,int amount,customer cu[]){
for(int i=0;i<100;i++){
if(account==cu[i].account_no)
{cu[i].balance+=amount;
cout<< cu[i].balance;}
}
}


void withdraw(int account,int amount,customer cu[]){
for(int i=0;i<100;i++){
if(account==cu[i].account_no)
{cu[i].balance-=amount;
cout<< cu[i].balance;}
}
}
 

customer search(int account,customer cu[]){
for(int i=0;i<100;i++){
if(account==cu[i].account_no)
return cu[i];
}
}


int main(){
customer cu[100];


int i=0,num;
cout <<"how many customer to enter:";
cin>>num;
while(i<num)
{
    int option;
cout<<"\n1. Deposit\n2. withdraw\n3. check balance";
cin>>option;


switch(option)
{
case(1):
{
addcustomer(cu[i]);
int money;
cout<<"Enter your amount:";
cin>>money;
deposit(cu[i].account_no, money, cu);
}break;

case(2):
{
addcustomer(cu[i]);
int money;
cout<<"Enter your amount:";
cin>>money;
withdraw(cu[i].account_no, money,cu);
}break;

case(3):
{
    int ac;
    cout<<"Enter account no. to search"<<endl;
  cin >>ac;

customer c1;
c1= search(ac,cu);
print(c1);}
break;

}
i++;
}
}

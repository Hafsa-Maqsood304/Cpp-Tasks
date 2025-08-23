/*// Project: Mini Calculator (with functions) → add, subtract, multiply, divide, power, factorial.
#include <iostream>
using namespace std;
int add(int num1,int num2){
    return num1+num2;
}
int sub(int num1,int num2){
    return num1-num2;
}
int mul(int num1,int num2){
    return num1*num2;
}
int divi(int num1,int num2){
    return num1/num2;
}
int factor(int num1){
      int mul=1;
    for(int i=num1;i>=1;i--)
        mul=mul*i;
       return mul; 
}
int main() {
    int a,b;
    cout<<"Enter a number:";
    cin>>a;
    cout<<"Enter a number:";
    cin>>b;
    cout<<"Add="<<add(a,b)<<endl;
    cout<<"Subtraction="<<sub(a,b)<<endl;
    cout<<"Multiplication="<<mul(a,b)<<endl;
    cout<<"division="<<divi(a,b)<<endl;
    cout<<"factorial of 1st no.="<<factor(a)<<endl;
    cout<<"factorial of 2nd no.="<<factor(b)<<endl;
    return 0;
}





//Make a function that takes a number and tells if it’s prime or not
#include <iostream>
using namespace std;
string check(int num){
   if (num <= 1) {
        return "not prime"; 
    } else {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                return "not prime";
            }
        }
    }
    return "prime";
}

int main(){
    int a;
    cout <<"Enter a number:";
    cin >>a;
    cout <<check(a);
}


*/


/*
 Write a function to calculate the square of a number.
#include <iostream>
using namespace std;
int square(int a){
    int b;
    b=a*a;
    return b;
}
int main() {
    int num1;
    cout <<"Enter a number:";
    cin >>num1;
    cout <<"The square of given number:"<<square(num1);

    return 0;
}*/
/*
Make a function that returns the maximum of two numbers.
#include <iostream>
using namespace std;
int max(int num1,int num2){
    if(num1>num2)
    return num1;
    else
    return num2;
}
int main(){
     int a;
    cout <<"Enter a number:";
    cin >>a;
     int b;
    cout <<"Enter 2nd number:";
    cin >>b;
    cout <<max(a,b)<<" is the maximum number.";
}



for (int i = 1; i <= 5; i++) {
        sum = sum + i;

//Write a function to calculate factorial of a number.
#include <iostream>
using namespace std;

int factor(int num1){
    int mul=1;
    for(int i=num1;i>=1;i--){
   mul=mul*i;}
    return mul ;
}
int main(){
     int a;
    cout <<"Enter a number:";
    cin >>a;
     cout <<factor(a)<<" is the factorial.";
}*/


// 5. Basic Banking System

// Features:

// Deposit, withdraw, check balance

// Functions:

// deposit(), withdraw(), checkBalance() 




#include<iostream>
#include<string>
using namespace std;



int deposit(int &balance,int amount){
        balance += amount;
        return balance;
    }
int withdraw (int &balance,int amount){
        balance -= amount;
        return balance;
    }
    
void check(int balance){
        cout<<balance<<endl;
    }
int main(){

int option;
int balance=2000;
int amount;




while(true){
    
    cout << "1. To Deposit"<<endl;
    cout << "2. To Withdraw"<<endl;
    cout << "3. To Check Balance"<<endl;

    cin>>option;

    switch (option)
    {
    case 1:
            {
            cout<<"enter the amount"<<endl;
            cin>>amount;
            int remaining=deposit(balance,amount);
            cout<<"your remaining balance is " <<remaining<<endl;


            }
    break;
    case 2:
    { cout<<"enter the amount"<<endl;
            cin>>amount;
            int remaining=withdraw(balance,amount);
            cout<<"your remaining balance is " <<remaining<<endl;    }
    break;
    case 3:
            check(balance);
    default:
        break;
    }

}
return 0;
}





































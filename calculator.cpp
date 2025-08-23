#include <iostream>
#include <string>
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
int divide(int num1,int num2){
    if (num2 == 0) {
  cout << "Division by zero is not allowed." << endl;
   return 0;}
 return num1/num2;
}



int main(){

    
int a,b,option;

do {

cout <<"1. Addition"<<endl;
cout <<"2. Subtraction"<<endl;
cout <<"3. Multiplication"<<endl;
cout <<"4. Division"<<endl;
cout <<"5. Exit" <<endl;
cout <<"Enter your choice:"<<endl;
cin >>option;


if(option>=1 && option<=4){
cout <<"Enter 1st num:";
cin >>a;
cout <<"Enter 2nd num:";
cin >>b;  }

switch(option){
case 1:
cout<<"Adition="<<add(a,b)<<endl;
break;

case 2:
cout<<"Subtraction="<<sub(a,b)<<endl;
break;

case 3:
cout<<"Multiplication="<<mul(a,b)<<endl;
break;

case 4:
cout<<"Division="<<divide(a,b)<<endl;
break;

 case 5:
cout << "Exiting program..." << endl;
break;

default:
 cout <<"Invalid number";
}


}
while(option!=5);

return 0;
}
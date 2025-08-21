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
if(num%2==0)

return "not prime";
else 
return "prime";
}

int main(){
    int a;
    cout <<"Enter a number:";
    cin >>a;
    cout <<check(a);
}






#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "hello";
    cout << "Enter your name:";
    string name;
    cin >> name;
    cout << "Enter your age:";
    int age;
    cin>> age;
   cout<<"Your name is "<<name<<"and you are"<<age<<"years old";
   return 0;
}


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

//Make a function that returns the maximum of two numbers.
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



/* for (int i = 1; i <= 5; i++) {
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











































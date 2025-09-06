/*
//Input elements in an array and find the largest/smallest.
#include <iostream>
#include <string>
using namespace std;
int main(){
    int num[4];

   cout <<"Enter a num:";
   cin>>num[0];
   cout <<"Enter 2nd num:";
   cin>>num[1];
   cout <<"Enter 3rd num:";
   cin>>num[2];
   cout <<"Enter 4th num:";
   cin>>num[3];

   int a=num[0],option;
    
   cout<<"1.Find Largest number\n2.Find smallest number";
   cin>>option;


   switch(option)

   {
   case 1:{
    for(int i=0;i<4;i++){
     if(a<num[i])
    {
    a=num[i];
    cout <<"Largest number="<<a;
}}
    break;}
    case 2:{
        for(int i=0;i<4;i++){
   if(a>num[i])
    {
    a=num[i];
    cout <<"Smallest number="<<a;
}}
    break;}

   default:
    break;
}
   

}


//Create an array and access its elements using pointer arithmetic
#include <iostream>
#include <string>
using namespace std;
int main (){
    int arr[5]={1,2,3,4,5};
    int* p=arr; //=1
    cout <<*p<<endl;
    p++;
    cout <<*(p=2)<<endl; //=4
}
*/


//Swap two numbers using a function and pointers.
#include <iostream>
#include <string>
using namespace std;
int swap(int num1,int num2){
  int c;
  c=num1;
  num1=num2;
  num2=c;
  return num1;
}

int main (){
int a,b;
cout<<"enter two number";
cin>>a,b;
cout <<"Given number are now switch:"<<swap(a,b);
}

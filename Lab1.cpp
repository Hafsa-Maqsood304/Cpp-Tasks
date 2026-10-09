#include<iostream>
using namespace std;
//Task#1
void swap(int a,int b){
int s;
s=b;
b=a;
a=s;
cout<<"Numbers after being swapped are:"<<a<<" and "<<b;
}

int main(){
int a,b;
cout<<"Enter number 1 to swap:";
cin>>a;
cout<<"Enter number 2 to swap:";
cin>>b;
swap(a,b);
return 0;
}


//Task#2
/*
int main(){
    int sum=0;
    int num[3][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120}};
//printing elements
//1st row
    for(int i=0;i<4;i++){
    cout<<*(*num+i)<<"\t";
    sum+=*(*num+i);
    }
    cout<<endl;
    //2nd row
    for(int i=0;i<4;i++){
    cout<<*(*(num+1)+i)<<"\t";
    sum+=*(*(num+1)+i);
    }
    cout<<endl;
    //3rd row
    for(int i=0;i<4;i++){
    cout<<*(*(num+2)+i)<<"\t";
    sum+=*(*(num+2)+i);
    }
    cout<<endl;
//printing addresses
    //1st row
    for(int i=0;i<4;i++)
    cout<<(*num+i)<<"\t";
    cout<<endl;
        //2nd row
    for(int i=0;i<4;i++)
    cout<<(*(num+1)+i)<<"\t";
    cout<<endl;
    //3rd row
    for(int i=0;i<4;i++)
    cout<<(*(num+2)+i)<<"\t";
    cout<<endl;

    //sum
    cout<<"The sum is:"<<sum<<endl;
    
    //Reverse printing
    
    //1st row
    for(int i=3;i>=0;i--){
    cout<<*(*num+i)<<"\t";
    sum+=*(*num+i);
    }
    cout<<endl;
    //2nd row
    for(int i=3;i>=0;i--){
    cout<<*(*(num+1)+i)<<"\t";
    sum+=*(*(num+1)+i);
    }
    cout<<endl;
    //3rd row
    for(int i=3;i>=0;i--){
    cout<<*(*(num+2)+i)<<"\t";
    sum+=*(*(num+2)+i);
    }

        return 0;
}
*/


//Task#3
/*
int power(int base,int exponent,int result){
    if(exponent==0){
        return result;
    }
    else{
        result*=base;
        power(base,exponent-1,result);
    }
}

int main(){
    int b,e;
    int ans=1;
    cout<<"Enter base and exponent:";
    cin>>b>>e;
    if(b>0||e>0)
    cout<<"Result:"<<power(b,e,ans);
    else{
    cout<<"Enter non-negative number:";
    cout<<"Enter base and exponent:";
    cin>>b>>e;
}
    return 0;
}
*/


//Task#4
/*
void Copy(char tocopy[],char copied[], int i){
    if(tocopy[i]=='\0'){
        copied[i]=='\0';
        return;
    }
    else{
        copied[i]=tocopy[i];
        Copy(tocopy,copied,i+1);
    }
}

int main(){
    char toCopy[100],copied[100];
    cout<<"Enter string to be copied:";
    cin.getline(toCopy,100);

    Copy(toCopy,copied,0);

    cout<<"To copy:"<<toCopy<<endl;
    cout<<"copied:"<<copied<<endl;
    


    return 0;
}*/
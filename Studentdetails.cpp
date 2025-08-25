//Classroom Management System

#include <iostream>
#include <string>
using namespace std;
//struct students
struct students{
    string name;
    int rollno;
    int marks[3];
    string address;
};

//functions
void inputstudents(students &s){
    
    cout <<"\nEnter your name:";
    cin>>s.name;

    
     cout <<"\nEnter your Roll no:";
      cin>>s.rollno;

  cout <<"\nEnter your English marks:";
  while(true)
  {
    cin>>s.marks[0];
    if(s.marks[0]<= 100)
    break;
    else
      cout<<"try again "<<endl;
  }


     cout <<"\nEnter your Math marks:";
    do{
    cin>>s.marks[1];
    if(s.marks[1]>100)
    cout <<"try again ";
    }
    while(s.marks[1] > 100);


     
   cout <<"\nEnter your Urdu marks:";
  while(true)
{
   cin>>s.marks[2];
   if(s.marks[2]<=100)
   break;
   else
   cout <<"try again";
}




 cin.ignore();
     cout <<"\nEnter your Address:"<<endl;
 getline(cin, s.address);

// cin>>s.address; stores only one word answer
   }
   
   
   
void printstudent(students s){
    cout<<s.name<<"   Roll no="<<s.rollno<<"   Eng="<<s.marks[0]<<"  Math="<<s.marks[1]<<"  Urdu="<<s.marks[2]<<"   Address="<<s.address<<endl;
}

   
 void highestinsubjec(students s){
    if(s.marks[0]>s.marks[1])
  cout <<s.marks[0]<<" is highest"<<endl;
   else if(s.marks[1]>s.marks[2])
    cout <<s.marks[1]<<" is highest"<<endl;
   else if(s.marks[2]>s.marks[1])
  cout <<s.marks[2]<<" is highest"<<endl;
    else
  cout <<s.marks[2]<<" is highest"<<endl;
}
   
   
   
   void averageofall(students s){
    int sum= s.marks[0]+s.marks[1]+s.marks[2];
    cout <<"Your average="<<sum/3;
    
}
 
   
   
   
   
   
   
   int main(){
    
    students s[10];
       

    int i=0;
    while(i < 10 ){
       inputstudents(s[i]);
       printstudent(s[i]);
       highestinsubjec(s[i]);
       averageofall(s[i]);
      i++;
    }
      
   }




















//learning struct
/*
struct address{
    string city;
    string country;
};


struct student{
    string name;
    int age;
    float marks;
    address addr;
};


void printstudent(student s){
    cout<<s.name<<" "<<s.age<<" "<<s.marks<<endl;
}



int main(){
    student s1;
    s1.name ="Hafsa";
    s1.age = 19;
    s1.marks =85;
    cout<<s1.name<<" "<<s1.age<<" "<<s1.marks<<endl;
    
    student s2;
    s2.name ="Ayesha";
    s2.age=20;
    s2.marks=90;
    cout<<s2.name<<" "<<s2.age<<" "<<s2.marks<<endl;
    
    
    
    //initializing in a line
    student s3={"Saad",22,89.5};
    cout <<s3.name<<" "<<s3.age<<" "<<s3.marks<<endl;
    
    
    //using array
    student s[2]={{"Rukha",23,90},{"Maryam",33,50}};
   cout <<s[0].name<<" "<<s[1].age<<endl;
   
   
   //using function
   student s4;
   s4.name ="Jamal";
    s4.age=20;
    s4.marks=90;
    printstudent(s4);
    
    
    
    //using pointers
    student s5 = {"Ali", 20, 85.5};
student* ptr = &s5;

cout << ptr->name<<" "; 
cout << ptr->age<<" ";
cout << ptr->marks<<endl;
    
    
    
    //by nested structure
    student s6={"Haram",18,67,{"Grw","Pakistan"}};
    cout << s6.addr.city;
    }*/
    
    
    
    
    
    
   

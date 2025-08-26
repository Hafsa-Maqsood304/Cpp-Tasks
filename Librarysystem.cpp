//Library System
#include <iostream>
#include <string>
using namespace std;

struct book{
   string title;
   string author;
   int year;
   string isbn;
};

static book books[30];


void addbook(book &b){

    cout <<"Enter the Title:"<<endl;
    cin>>b.title;
    cout <<"Enter Author's Name:"<<endl;
    cin>>b.author;
    cout <<"Publishing year:"<<endl;
    while(true){
    cin>>b.year;
    if(b.year<=2025)
    break;
    else
    cout <<"Invalid/: Try again:"<<endl;
    }
    cout <<"Enter the ISBN:"<<endl;
    cin>>b.isbn;
}


void printbook(book b){
    cout <<"Title:"<<b.title<<endl;
    cout <<"Author:"<<b.author<<endl;
    cout <<"Publishing year:"<<b.year<<endl;
    cout <<"ISBN:"<<b.isbn<<endl;
}

book search(string title){
 for(int i=0;i<30;i++)
    if(title==books[i].title)
          return books[i];
}

int main(){

int num;
cout << "how many books you wanna enter " <<endl ;
cin>>num;


for (int i=0 ; i<num ; i++){
  addbook(books[i]);
  printbook(books[i]);
}
book b;
b = search("urdu");
printbook(b);

}

#include<iostream>
#include<string>
using namespace std;
struct node{
    int tabID;
    string url;
    node* next;
    node* prev;
};

class CircularDoublyLinkedList{
    public:
    node *head;
    node *current_tab;
    CircularDoublyLinkedList(){
        head=NULL;
        current_tab=NULL;
    }
    
    void Open_tab(string URL){
        node *temp=new node;
        temp->url = URL;

        if(head == NULL){
            head = temp;
            temp->tabID=1;
            temp->next = head;
            temp->prev = head;
            current_tab=temp;
            cout<<"\nOpened: " <<temp->url<<" (tab "<<temp->tabID<<")\n";       
            return;
        }
        node* ptr = head->prev;
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = head; 
        head->prev = temp;  
        current_tab = temp;
        temp->tabID = ptr->tabID + 1; 
        cout<<"\nOpened: " <<temp->url<<" (tab "<<temp->tabID<<")\n";       
    }

    void Close_current_tab(){
        if(head==NULL || current_tab==NULL){
            cout<<"\nNo tabs are open.\n";
            return; 
        }

        node* temp = current_tab;

        if(head->next == head){
            cout << "\nClosing Tab "<<temp->tabID<<": "<<temp->url<<endl;
            delete temp;
            head = NULL;
            current_tab = NULL;
            return;
        }

        if(temp == head){
            head = temp->next; 
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        current_tab = temp->prev;

        cout << "\nClosing Tab "<<temp->tabID<<": "<<temp->url<<endl;
        delete temp;
    }

    void MoveToPrev(){
        if(current_tab==NULL){
            cout<<"No tabs open.\n"; return;
        }
        current_tab = current_tab->prev;
        cout<<"Switched to Previous Tab: "<<current_tab->url<<" (Tab "<<current_tab->tabID<<")\n";
    }
    
    void MoveToNext(){
        if(current_tab==NULL){
            cout<<"No tabs open.\n"; return;
        }
        current_tab = current_tab->next;
        cout<<"Switched to Next Tab: "<<current_tab->url<<" (Tab "<<current_tab->tabID<<")\n";
    }

    void display(){
        if(head==NULL){
            cout<<"No Tabs are open.\n";
            return;
        }
        cout<<"--- Opened Tabs ---\n";
        node *temp=head;
        do{
            cout<<"Tab "<<temp->tabID<<": "<<temp->url;
            if(temp == current_tab) cout << "  <-- Current";
            cout << endl;
            temp = temp->next; 
        }while(temp!=head);
        cout<<endl;
    }
};

int main(){
    CircularDoublyLinkedList c1;
    cout<<"\n===== Browser Tabs Manager =====\n";
    cout<<"1. Open New Tab\n2. Close Current Tab\n3. Move to Next Tab\n";
    cout<<"4. Move to Previous Tab\n5. Show All Tabs\n0. Exit\n";
    int choice=0;
    cout<<"Enter your Choice: ";
    cin>>choice;
    while(choice!=0){
        if(choice==1){
            string url;
            cout<<"Enter your url: ";
            cin.ignore();
            getline(cin,url);
            c1.Open_tab(url);
        }
        else if(choice==2){
            c1.Close_current_tab();
        }
        else if(choice==3){
            c1.MoveToNext();
        }
        else if(choice==4){
            c1.MoveToPrev();
        }
        else if(choice==5){
            c1.display();
        }else{
            cout<<"\ninvalid choice!\n";
        }
        cout<<"Enter your Choice: ";
        cin>>choice;
    }
    return 0;
}
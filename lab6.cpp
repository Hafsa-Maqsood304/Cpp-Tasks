#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
class DoublyLinkedList{
    public:
    node *head;
    DoublyLinkedList(){
        head=NULL;
    }
    
    int ListLength(){
        int length=0;
        node* P =head;
        while(P!=NULL){
            length++;
            P= P->next;
        }
        return length;
    }
    
    void insert_at_head(int value){
        
        node *temp=new node;
        temp->data=value;
    
        if(head==NULL){
            head=temp;
            temp->next=NULL;
            temp->prev=NULL;
            cout<<"\nNode inserted\n";
        }
        else{
            temp->next=head;
            temp->prev=NULL;
            head=temp;
            cout<<"\nNode Inserted\n";
        }
    }
    void insert_at_end(int value){
        
        node *temp=new node;//data + next address + prev address
        temp->data=value;

           if(head == NULL){
            head = temp;
            temp->next = NULL;
            temp->prev = NULL;
            cout<<"\nList was empty. so, a head node is inserted\n";
            return;
        }
           node* ptr=head;// pointer contains head address
           while(ptr->next!=NULL){
            ptr=ptr->next;
           }
           ptr->next=temp;
           temp->prev=ptr;
           temp->next=NULL; 
           cout<<"\nNode inserted\n" ;       
    }

void random_insert(int value){
    int position;
    cout << "Position where you wanna insert: ";
    cin >> position;

    int count = ListLength();

    if(position < 0 || position > count){
        cout << "\nInvalid position!\n";
        return;
    }

    if(position == 0){
        insert_at_head(value);
        return;
    }

    node* ptr = head;
    int i = 0;

    while(i < position - 1){
        ptr = ptr->next;
        i++;
    }

    node* temp = new node;
    temp->data = value;
    temp->next = ptr->next;
    ptr->prev = temp;
    ptr->next = temp;

    cout << "\nNode inserted\n";
}


    int Delete_from_head(){
        int DeletedValue;
        struct node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\nList is empty\n";  
        return -1;
    }  
    else   
    {  
        ptr = head; 
		DeletedValue=ptr->data;
 
        ptr = ptr->next;
        head = ptr;  
        ptr->prev=NULL;

        delete ptr;  
        cout<<"\nNode deleted from the begining ...\n";  
    }  
	return DeletedValue;
    }

    
int Delete_from_end(){
    if(head == NULL){
        cout << "\nList is empty\n";
        return -1;
    }

    node* ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    int DeletedValue = ptr->data;

    ptr=ptr->prev;
    delete ptr->next;

    if(ptr == NULL){
        head = NULL;
    }
    else{
        ptr->next = NULL;
    }


    cout << "\nNode deleted from the end\n";
    return DeletedValue;
}


    int Random_delete(){
    int position;
    cout << "Position to delete: ";
    cin >> position;

    int count = ListLength();

    if(position < 0 || position >= count){
        cout << "\nInvalid position!\n";
        return -1;
    }

    if(position == 0){
        return Delete_from_head();
    }

    node* ptr = head;
    int i = 0;

    while(i < position - 1){
        ptr = ptr->next;
        i++;
    }

    node* nextnode = ptr->next;
    int DeletedValue = nextnode->data;

    ptr->next = nextnode->next;
    nextnode=nextnode->next;
    delete nextnode->prev;
    nextnode->prev=ptr;

    cout << "\nNode deleted successfully!\n";
    return DeletedValue;
}


    void search(int d){
        node *temp = head;
        while(temp!=NULL){
            if(temp->data==d){
                cout<<"\nData "<<d<<" found!\n";
                return;
            }else{
                temp=temp->next;
            }
        }
        cout<<"\nData not found\n";
    }
    

    void display(){
        node *temp=head;
        if(temp==NULL){
            cout<<"List is empty\n";
        }
        else{
            cout<<"Printing values...\n";

        while(temp!=NULL){
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
    }
};
int main(){
    DoublyLinkedList L1;
    L1.insert_at_head(33);
    L1.insert_at_end(32);
    L1.search(33);
    L1.display();
    L1.Delete_from_head();
    L1.search(33);
    L1.display();
    L1.Delete_from_end();
    L1.Random_delete();

}
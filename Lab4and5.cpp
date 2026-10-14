#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
class SingleLinkedList{
    public:
    node *head;
    SingleLinkedList(){
        head=NULL;
    }
    
    int ListLength(){
        int length;
        node* P =head;
        while(P->next!=NULL){
            length++;
            P= P->next;
        }
        return length;
    }
    
    void insert_at_head(int value){
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        if(head==NULL){
            head=temp;
            temp->next=NULL;
            cout<<"\nNode inserted\n";
        }
        else{
            temp->next=head;
            head=temp;
            cout<<"\nNode Inserted\n";
        }
    }
    void insert_at_end(int value){
        
        node *temp=new node;//data + next address
        temp->data=value;
           node* ptr=head;// pointer contains head address
           while(ptr->next!=NULL){
            ptr=ptr->next;
           }
           ptr->next=temp;
           temp->next=NULL; 
           cout<<"\nNode inserted\n" ;       
    }
    void random_insert(int value){
        int position;
        cout<<"Position where you wanna insert: ";
        cin>>position;
        int count=ListLength();
        if(!(position<=count)){
            cout<<"\nInvalid position!\n";
        }
        else{
        node* ptr=head;
        int i=0;
        while(i<position){
            ptr= ptr->next;
        }
        node* temp=new node;
        temp->data=value;
        temp->next=ptr->next;
        ptr->next=temp;
    }
    }

    int Delete_from_head(){
        int DeletedValue;
        struct node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\nList is empty\n";  
    }  
    else   
    {  
        ptr = head;  
		DeletedValue=ptr->data;
        head = ptr->next;  
        delete ptr;  
        cout<<"\nNode deleted from the begining ...\n";  
    }  
	return DeletedValue;
    }

    int Delete_from_end(){
        int DeletedValue;
        node* ptr1;
        node* ptr;
        ptr=ptr1=head;
        int count=0;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
            count++;
        }
       
        ptr1->next=NULL;
   		DeletedValue=ptr->data;
        delete ptr;
        cout<<"\nNode deleted from the end ...\n";
        return DeletedValue;
    }

    int Random_delete(){
        int DeletedValue;
        int position;
        cout<<"Position where you wanna insert: ";
        cin>>position;
        int count=ListLength();

        if(!(position<=count)){
            cout<<"\nInvalid position!\n";
        }
        else{
            node* ptr=head;
            int i=0;
            while(i<position){
                ptr= ptr->next;
            }
            node* nextnode=ptr->next;
            ptr->next=nextnode->next;
            DeletedValue= nextnode->data;
            delete nextnode;
            cout<<"\nNode deleted successfully!\n";
            }
            return DeletedValue;
    }


    void search(int d){
        node *temp=head;
        while(temp!=NULL){
            if(temp->data==d){
                cout<<"\nData "<<d<<" found!\n";
                break;
            }else{
                temp=temp->next;
            }
        }
        cout<<"\nData not found\n";
    }
    //Lab 5
    //Task 1
    int CountNodes(){
        int count=0;
        node *temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    //Task 2
    SingleLinkedList ConcatenateList(SingleLinkedList L1, SingleLinkedList L2){
        
        SingleLinkedList NewList;
        if(L1.head == NULL && L2.head == NULL){
            return NewList;
        }
        node* tmp=L1.head;
        node* newnode=new node;
        newnode->data=tmp->data;
        NewList.head=newnode;
        tmp=tmp->next;
        while(tmp->next != NULL){
            NewList.insert_at_end(tmp->data);
            tmp=tmp->next;
        }
        node* tmp1=L2.head;
        node* newnode1=new node;
        newnode1->data=tmp1->data;
        NewList.head=newnode1;
        tmp1=tmp1->next;

        while(tmp1->next != NULL){
            NewList.insert_at_end(tmp1->data);
            tmp1=tmp1->next;
        }
        return NewList;
    }
    //task3
    SingleLinkedList MergeListsAlternatively(SingleLinkedList L1, SingleLinkedList L2){
        SingleLinkedList NewList;
        if(L1.head == NULL && L2.head == NULL){
            return NewList;
        }
        node* tmp=L1.head;
        NewList.insert_at_head(tmp->data);
        tmp=tmp->next;
        node* tmp1=L2.head;
        NewList.insert_at_end(tmp1->data);
        tmp1=tmp1->next;
        while(tmp!=NULL || tmp1!=NULL){
            if(tmp!=NULL){
            NewList.insert_at_end(tmp->data);
            }
            if(tmp1!=NULL){
            NewList.insert_at_end(tmp1->data);
            }
            tmp=tmp->next;
            tmp1=tmp1->next;
        }
        return NewList;
    }

    void SortedInsert(int value){
        if(head==NULL){
            insert_at_head(value);
        }
        else{
        node* tmp=head;
        node* prev=head;
        while(tmp!=NULL){
            if(value<tmp->data){
                if(tmp==head){
                    insert_at_head(value);
                }
                else{
                    node* newnode=new node;
                    newnode->data=value;
                    prev->next= newnode;
                    newnode->next=tmp;                  
                }
            }
            prev=tmp;
            tmp=tmp->next;
        }
    }
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
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Total node are "<<CountNodes();
    }
    }
};
int main(){
    /*SingleLinkedList L1;
    L1.insert_at_head(33);
    L1.insert_at_end(32);
    L1.search(33);
    L1.display();
    L1.Delete_from_head();
    L1.search(33);
    L1.display();
    L1.Delete_from_end();
    L1.Random_delete();*/

        SingleLinkedList L2;
        SingleLinkedList L3;
        L2.insert_at_end(44);
        L2.insert_at_end(4);
        L2.insert_at_end(2);
        L3.insert_at_end(5);
        L3.insert_at_end(6);
        L2.display();
        L3.display();
        SingleLinkedList l4;
        l4=l4.ConcatenateList(L2,L3);
        l4.display();


}
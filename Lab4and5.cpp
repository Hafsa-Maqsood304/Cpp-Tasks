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

           if(head == NULL){
            head = temp;
            temp->next = NULL;
            cout<<"\nList was empty. so, a head node is inserted\n";
            return;
        }
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
        head = ptr->next;  
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
    node* ptr1 = NULL;

    while(ptr->next != NULL){
        ptr1 = ptr;
        ptr = ptr->next;
    }

    int DeletedValue = ptr->data;

    if(ptr1 == NULL){
        head = NULL;
    }
    else{
        ptr1->next = NULL;
    }

    delete ptr;

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
    delete nextnode;

    cout << "\nNode deleted successfully!\n";
    return DeletedValue;
}


    void search(int d){
        node *temp=head;
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

    node* tmp = L1.head;

    while(tmp != NULL){
        NewList.insert_at_end(tmp->data);
        tmp = tmp->next;
    }

    node* tmp1 = L2.head;

    while(tmp1 != NULL){
        NewList.insert_at_end(tmp1->data);
        tmp1 = tmp1->next;
    }

    return NewList;
}
    //task3
    SingleLinkedList MergeListsAlternatively(
    SingleLinkedList L1, SingleLinkedList L2){

    SingleLinkedList NewList;

    node* tmp = L1.head;
    node* tmp1 = L2.head;

    while(tmp != NULL || tmp1 != NULL){

        if(tmp != NULL){
            NewList.insert_at_end(tmp->data);
            tmp = tmp->next;
        }

        if(tmp1 != NULL){
            NewList.insert_at_end(tmp1->data);
            tmp1 = tmp1->next;
        }
    }

    return NewList;
}

//task4    
void SortedInsert(int value){
    if(head == NULL || value < head->data){
        insert_at_head(value);
        return;
    }

    node* tmp = head;
    node* prev = head;

    while(tmp != NULL){
        if(value < tmp->data){
            node* newnode = new node;
            newnode->data = value;

            prev->next = newnode;
            newnode->next = tmp;

            return;
        }

        prev = tmp;
        tmp = tmp->next;
    }

    insert_at_end(value);
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
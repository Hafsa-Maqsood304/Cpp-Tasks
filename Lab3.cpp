#include <iostream>
using namespace std;
//Task no. 2
class Queue{
    public:
    int back;
    int queue[10];
    Queue(){
        back=-1;
        queue[10]=0;
    }
    bool isEmpty(){
        if(back==-1){
            return true;
        }
        else 
        return false;
    }
    bool isFull(){
        if(back==9){
            return true;
        }
        return false;
    }
    int peek(){
        if(isEmpty()){
            cout<<"\nqueue is empty!"<<endl;
            return 0;
        }
        else{
        return queue[0];     
        }   
    }
    void Enqueue(int value){
        if(isFull()){
            cout<<"The queue is full!"<<endl;
        }
        else{
            back++;
            queue[back]=value;
        }
    }
    void Dequeue(){
        if(isEmpty()){
            cout<<"queue is empty!"<<endl;
        }
        else{
            int num=queue[0];
            for(int i=0;i<=back;i++){
                queue[i]=queue[i+1];
            }
            back--;
            cout<<"\n"<<num<<" is removed from queue.";
        }
    }
};
int main(){
    Queue Q;
    int toEnter;
    cout<<"Enter a value in your queue: ";
    cin>>toEnter;
    Q.Enqueue(toEnter);
    cout<<"The value entered: "<<Q.peek();
    Q.Dequeue();
    Q.peek();
}

//Task no. 1
/*
class Stack{
    public:
    int Top;
    int stack[10];
    Stack(){
        Top=-1;
        stack[10]=0;    
    }

    bool isEmpty(){
        if(Top==-1){
            return true;
        }
        else
        return false;
    }
    
    bool isFull(){
        if(Top==9){
            return true;
        }
        else 
        return false;
    }
    
    void push(int value){
        if(isFull()){
            cout<<"Stack is full, cannot push!"<<endl;
        }
        else{
            Top++;
            stack[Top]=value;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
        }
        else{
            int value=stack[Top];
            Top--;        
        }
    }
    int Peek(){
        if(isEmpty()){
            cout<<"\nyour stack is empty!"<<endl;
            return 0;
        }
        else
        return stack[Top];
    }
    void display(){
        cout<<"The last value pushed= "<<Peek();
    }

};
int main(){
    Stack s;
    int toPush;
    cout<<"Enter a value to push: ";
    cin>>toPush;
    s.push(toPush);
    s.display();
    s.pop();
    s.display();
}
    */
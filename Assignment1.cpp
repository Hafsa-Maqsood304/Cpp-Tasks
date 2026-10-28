#include<iostream>
#include<list>
#include<string>
using namespace std;
class Queue{
    public:
    list<int> queue;
    Queue(){
        queue.clear(); // Initialize the queue as empty
    }
    int peek(){
        if(queue.empty()){
            cout<<"\nqueue is empty!"<<endl;
            return 0;
        }
        else{
        return queue.front(); // Return the front element of the queue     
        }   
    }
    void Enqueue(int value){
        queue.push_back(value);
    }
    void Dequeue(){
        if(queue.empty()){
            cout<<"queue is empty!"<<endl;
        }
        else{
            int num=queue.front();// Get the front element before removing it
            queue.pop_front();
            cout<<"\n"<<num<<" is removed from queue.";
        }
    }
    void PrintJobScheduling(int n){
        cout<<"\nJob Scheduling: ";
        for(int i=0; i<n; i++){
            if(queue.empty()){
                cout<<"\nqueue is empty!"<<endl;
                return;
            }
            int num=queue.front(); 
            queue.pop_front();
            cout<<num<<" ";
        }
    }
    void BankCounterSimulation(int n){
        cout<<"\nBank Counter Simulation: ";
        for(int i=0; i<n; i++){
            if(queue.empty()){
                cout<<"\nqueue is empty!"<<endl;
                return;
            }
            int num=queue.front(); 
            queue.pop_front();
            cout<<num<<" ";
        }
    }
};
class Stack{
    public:
    list<char> stack;
    Stack(){
        stack.clear();
    }
   
    void push(char value){
            stack.push_back(value);  
    }
    void pop(){
        if(stack.empty()){
            cout<<"Stack is empty!"<<endl;
        }
        else{
            char value=stack.back();
            stack.pop_back();        }
    }
    char Peek(){
        if(stack.empty()){
            cout<<"\nyour stack is empty!"<<endl;
            return 0;
        }
        else
        return stack.back();
    }
    void display(){
        cout<<"The last value pushed= "<<Peek();
    }
    bool empty(){
        return stack.empty();
    }
    char top(){
        if(stack.empty()){
            cout<<"\nyour stack is empty!"<<endl;
            return 0;
        }
        else
        return stack.back();
    }

    void IsValid(string s){
    if(s.length()%2!=0){
        cout << "\nUnbalanced expression..." << endl;
        return;
    }

    Stack st;

    for(int i=0; i<s.length(); i++){
        char ch=s[i];

        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty()){
                cout << "\nUnbalanced expression..." << endl;
                return;
            }

            char top=st.top();

            if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                st.pop();
            }
            else{
                cout << "\nUnbalanced expression..." << endl;
                return;
            }
        }
    }

    if(st.empty())
        cout << "\nBalanced expression..." << endl;
    else
        cout << "\nUnbalanced expression..." << endl;
}
    void ReverseString(string str){
        Stack st;
        for(int i=0; i<str.length(); i++){
            st.push(str[i]);
        }
        cout<<"\nReversed string: ";
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
    }

    //Lab Quiz Question no. 1
    void DecimalToBinary(int value){
        Stack S;
        if(value==0){
            cout<<0;
            return;
        }
        while(value>0){
            S.push(value%2);
            value=value/2;
        }

        while(!S.empty()){
            cout<<S.Peek();
            S.pop();
            
        }
    }
};

int main(){
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Queue front: " << q.peek() << endl;
    q.Dequeue();

    Stack s;

    s.push('a');
    s.push('b');
    s.push('c');

    cout << "\nStack top: " << s.Peek() << endl;
    s.pop();

    s.IsValid("()");
    s.IsValid("()[]{}");
    s.IsValid("(]");
    s.IsValid("([)]");
    s.IsValid("{[]}");
    s.ReverseString("Hello");
    s.DecimalToBinary(13);

    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.PrintJobScheduling(3);

    Queue q2;
    q2.Enqueue(4);
    q2.Enqueue(5);
    q2.Enqueue(6);
    q2.BankCounterSimulation(3);



    return 0;
}
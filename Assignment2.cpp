#include <iostream>
#include <string>
using namespace std;
//Task # 5
struct Student {
    int id;
    string name;
    float cgpa;

    Student() {
        id = 0;
        name = "";
        cgpa = 0;
    }

    Student(int studentId, string studentName, float studentCgpa) {
        id = studentId;
        name = studentName;
        cgpa = studentCgpa;
    }

    void display() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | CGPA: " << cgpa << '\n';
    }
};

template <typename T>
class Stack {
private:
    T* items;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
        items = new T[capacity];
    }

    ~Stack() {
        delete[] items;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Recently viewed stack is full.\n";
            return;
        }

        top++;
        items[top] = value;
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    T peek() {
        return items[top];
    }
};

template <typename T>
class Queue {
private:
    T* items;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
        items = new T[capacity];
    }

    ~Queue() {
        delete[] items;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Registration queue is full.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        items[rearIndex] = value;
        count++;
    }

    T dequeue() {
        T value = items[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return value;
    }
};

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) {
            data = value;
            next = NULL;
        }
    };

    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    ~SinglyLinkedList() {
        while (head != NULL) {
            Node* temporary = head;
            head = head->next;
            delete temporary;
        }
    }

    void insertAtEnd(T value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;

            while (current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
        }
    }

    Student* findById(int studentId) {
        Node* current = head;

        while (current != NULL) {
            if (current->data.id == studentId) {
                return &current->data;
            }

            current = current->next;
        }

        return NULL;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* previous;
        Node* next;

        Node(T value) {
            data = value;
            previous = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~DoublyLinkedList() {
        while (head != NULL) {
            Node* temporary = head;
            head = head->next;
            delete temporary;
        }
    }

    void insertAtEnd(T value) {
        Node* newNode = new Node(value);

        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* current = head;

        while (current != NULL) {
            current->data.display();
            current = current->next;
        }
    }

    void displayBackward() {
        Node* current = tail;

        while (current != NULL) {
            current->data.display();
            current = current->previous;
        }
    }
};

int main() {
    Stack<Student> recentlyViewed(100);
    Queue<Student> registrationQueue(100);
    SinglyLinkedList<Student> studentRecords;
    DoublyLinkedList<Student> navigationRecords;

    int choice;

    do {
        cout << "\n1. Add student record\n";
        cout << "2. View student record\n";
        cout << "3. Add student to registration queue\n";
        cout << "4. Register next student and navigate records\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float cgpa;

            cout << "Enter student ID: ";
            cin >> id;

            if (studentRecords.findById(id) != NULL) {
                cout << "This ID already exists.\n";
            } else {
                cout << "Enter student name: ";
                getline(cin >> ws, name);

                cout << "Enter CGPA: ";
                cin >> cgpa;

                Student student(id, name, cgpa);
                studentRecords.insertAtEnd(student);
                navigationRecords.insertAtEnd(student);

                cout << "Student record added.\n";
            }
        } else if (choice == 2) {
            int id;

            cout << "Enter student ID: ";
            cin >> id;

            Student* student = studentRecords.findById(id);

            if (student == NULL) {
                cout << "Student not found.\n";
            } else {
                student->display();

                if (recentlyViewed.isFull()) {
                    recentlyViewed.pop();
                }

                recentlyViewed.push(*student);
                cout << "Recently viewed student:\n";
                recentlyViewed.peek().display();
            }
        } else if (choice == 3) {
            int id;
            string name;
            float cgpa;

            cout << "Enter student ID: ";
            cin >> id;

            cout << "Enter student name: ";
            getline(cin >> ws, name);

            cout << "Enter CGPA: ";
            cin >> cgpa;

            Student student(id, name, cgpa);
            registrationQueue.enqueue(student);

            cout << "Student added to the registration queue.\n";
        } else if (choice == 4) {
            if (registrationQueue.isEmpty()) {
                cout << "Registration queue is empty.\n";
            } else {
                Student student = registrationQueue.dequeue();

                if (studentRecords.findById(student.id) != NULL) {
                    cout << "This student ID already exists.\n";
                } else {
                    studentRecords.insertAtEnd(student);
                    navigationRecords.insertAtEnd(student);
                    cout << "Student registered:\n";
                    student.display();
                }
            }

            cout << "Records from beginning to end:\n";
            navigationRecords.displayForward();

            cout << "Records from end to beginning:\n";
            navigationRecords.displayBackward();
        }

    } while (choice != 0);

    return 0;
}

//Task # 4
/*
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value)
            : data(value), prev(NULL), next(NULL) {}
    };
    Node* head;
    Node* tail;
    int count;
public:
    DoublyLinkedList() : head(NULL), tail(NULL), count(0) {}
    ~DoublyLinkedList() {
        while (head != NULL) {
            Node* temporary = head;
            head = head->next;
            delete temporary;
        }
    }
    void insertAtBeginning(const T& value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++count;
    }

    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++count;
    }

    bool insertAtPosition(int position, const T& value) {
        if (position < 1 || position > count + 1) {
            return false;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return true;
        }
        if (position == count + 1) {
            insertAtEnd(value);
            return true;
        }
        Node* current = head;
        for (int i = 1; i < position; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        ++count;
        return true;
    }

    bool deleteFromBeginning() {
        if (head == NULL) {
            return false;
        }
        Node* temporary = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temporary;
        --count;
        return true;
    }

    bool deleteFromEnd() {
        if (tail == NULL) {
            return false;
        }
        Node* temporary = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temporary;
        --count;
        return true;
    }

    bool deleteByValue(const T& value) {
        Node* current = head;

        while (current != NULL && !(current->data == value)) {
            current = current->next;
        }
        if (current == NULL) {
            return false;
        }
        if (current == head) {
            return deleteFromBeginning();
        }
        if (current == tail) {
            return deleteFromEnd();
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        --count;
        return true;
    }

    void displayForward() const {
        if (head == NULL) {
            cout << "List is empty"<<endl;
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << current->data;

            if (current->next != NULL) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout <<endl;
    }

    void displayBackward() const {
        if (tail == NULL) {
            cout << "List is empty"<<endl;
            return;
        }
        Node* current = tail;
        while (current != NULL) {
            cout << current->data;
            if (current->prev != NULL) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout <<endl;
    }

    bool search(const T& value) const {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int countNodes() const {
        return count;
    }
};

int main() {
    DoublyLinkedList<int> numbers;

    numbers.insertAtBeginning(54);
    numbers.insertAtBeginning(17);
    numbers.insertAtEnd(46);
    numbers.insertAtPosition(3, 30);
    cout << "Forward Display: ";
    numbers.displayForward();
    cout << "Backward Display: ";
    numbers.displayBackward();
    cout << "Total nodes: " << numbers.countNodes() <<endl;
    cout << "Is 30 in the list? "
         << (numbers.search(30) ? "Yes" : "No") <<endl;
    numbers.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    numbers.displayForward();
    numbers.deleteFromEnd();
    cout << "After deleting from end: ";
    numbers.displayForward();
    numbers.deleteByValue(30);
    cout << "After deleting value 30: ";
    numbers.displayForward();

    DoublyLinkedList<string> names;
    names.insertAtEnd("HaFsa");
    names.insertAtEnd("Rukha");
    cout << "Forward Name list: ";
    names.displayForward();
    cout << "Backward Name list: ";
    names.displayBackward();

    return 0;
}

//Task # 3
template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(NULL) {}
    };

    Node* head;
    int count;

public:
    SinglyLinkedList() : head(NULL), count(0) {}

    ~SinglyLinkedList() {
        while (head != NULL) {
            Node* temporary = head;
            head = head->next;
            delete temporary;
        }
    }
    void insertatHead(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++count;
    }

    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++count;
    }

    bool RandomInsert(int pos, const T& value) {
        if (pos < 1 || pos > count + 1) {
            return false;
        }
        if (pos == 1) {
            insertatHead(value);
            return true;
        }
        Node* current = head;
        for (int i = 1; i < pos - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        ++count;
        return true;
    }

    bool deleteFromHead() {
        if (head == NULL) {
            return false;
        }
        Node* temporary = head;
        head = head->next;
        delete temporary;
        --count;
        return true;
    }

    bool deleteFromEnd() {
        if (head == NULL) {
            return false;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
        --count;
        return true;
    }

    bool deleteByValue(const T& value) {
        if (head == NULL) {
            return false;
        }
        if (head->data == value) {
            return deleteFromHead();
        }
        Node* current = head;
        while (current->next != NULL &&
               !(current->next->data == value)) {
            current = current->next;
        }
        if (current->next == NULL) {
            return false;
        }
        Node* temporary = current->next;
        current->next = temporary->next;
        delete temporary;
        --count;
        return true;
    }

    bool search(const T& value) const {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() const {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << current->data;
            if (current->next != NULL) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << '\n';
    }

    int countNodes() const {
        return count;
    }
};

int main() {
    SinglyLinkedList<int> numbers;

    numbers.insertatHead(12);
    numbers.insertatHead(32);
    numbers.insertAtEnd(44);
    numbers.RandomInsert(6, 23);

    cout << "Number List: ";
    numbers.display();

    cout << "Total nodes: " << numbers.countNodes() << '\n';

    cout << "Is 30 in the list? "
         << (numbers.search(30) ? "Yes" : "No") << '\n';

    numbers.deleteFromHead();
    cout << "After deleting from head: ";
    numbers.display();

    numbers.deleteFromEnd();
    cout << "After deleting from end: ";
    numbers.display();

    numbers.deleteByValue(30);
    cout << "After deleting value 30: ";
    numbers.display();

    SinglyLinkedList<string> names;
    names.insertAtEnd("Hafsa");
    names.insertAtEnd("Rukha");

    cout << "List of names: ";
    names.display();

    return 0;
}

//Task # 2
template<typename T>
     class Queue{
     	private:
     		T*items;
     		int frontindex;
     		int rearindex;
     		int count;
     		int capacity;
     		
     		public:
     			Queue(int size):frontindex(0),rearindex(-1),count(0),capacity(size){
     				if(size<=0){
     					cout<<"queue must be greater than zero";
					 }
					 items=new T[capacity];
				 }
				 Queue(){
				 	delete[] items;
				 }
				 bool isempty(){
				 	return count==0;
				 }
				 bool isfull(){
				 	return count==capacity;
				 }
				 void enqueue(const T& value)
				 {
				 	if(isfull())
					 {
				 		cout<<" queue is full cannot add another"<<endl;
				 		return;
					 }
					 rearindex=(rearindex+1)%capacity;
					 items[rearindex]=value;
					 ++count;
				 }
				 void dequeue(){
				 	if (isempty()) {
                   cout << "Queue is empty. There is nothing to remove.\n";
                   return;
                  }
                  frontindex=(frontindex+1)%capacity;
                  --count;
				 }
				 T front(){
			     if (isempty()) {
                   cout << "Queue is empty. There is nothing to remove.\n";
                   return T();
				 }
				 return items[frontindex];
			}
			T rear(){
				if (isempty()) {
                   cout << "Queue is empty. There is nothing to remove.\n";
                   return T();
				 }
				 return items[rearindex];
			}
		void display(){
        if (isempty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Elements from front to rear:"<<endl;
        for (int i = 0; i < count; ++i) {
            int index = (frontindex + i) % capacity;
            cout << items[index] <<endl;
        }
    }
	 };
	 int main()
	 {
	 	Queue<int> number(5);

    number.enqueue(34);
    number.enqueue(22);

    cout << "INTEGER QUEUE"<<endl;
    number.display();

    cout << "Front element:"<<number.front() <<endl;
    cout << "Rear element: "<<number.rear() <<endl;
    number.dequeue();

    cout << "Queue after dequeue():"<<endl;
    number.display();

    cout << "Is the queue empty? "<<(number.isempty()?"Yes":"No") << '\n';

    cout << "Is the queue full? "<< (number.isfull()?"Yes":"No") << "\n\n";

    Queue<string> nameQueue(3);
    nameQueue.enqueue("Hafsa");
    nameQueue.enqueue("Javeria");
    nameQueue.enqueue("Sadiqa");

    cout << "STRING QUEUE"<<endl;
    nameQueue.display();

    return 0;
}

//Task # 1

template <typename T>
class Stack{
	private:
		T* items;
		int TOP;
		int capacity;
		
	public:
	Stack(int size):TOP(-1),capacity(size)
	{
		items=new T[capacity];
	}	
	Stack()
	{
		delete[] items;
	}
	bool isempty(){
    return TOP==-1;
     }

    bool isfull(){
    return TOP==capacity-1;
    }
	void push(T value){
		if(isfull()){
			cout<<"stack is full"<<endl;
			return;
		}
		items[++TOP]=value;
	}
	void pop(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return;
		}
		--TOP;
	}
	T peek(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			
		}
		return items[TOP];
	}
	void display(){
		if(isempty()){
			cout<<"stack is empty"<<endl;
			return;
		}
		for(int i=TOP;i>=0;--i){
			cout<<items[i]<<" ";
		}
	}
};

int main(int argc, char** argv) {
	Stack<int> intStack(6);
	intStack.push(44);
	intStack.push(12);
	cout<<" stack of integers"<<endl;
	intStack.display();
	cout<<"top element:"<<intStack.peek()<<" "<<endl; 
	
	Stack<float> f_Stack(5);
    f_Stack.push(2.4f);
    f_Stack.push(2.1f);
    cout << "stack of floats"<<endl;;
    f_Stack.display();
    cout << "Top element: " <<f_Stack.peek()<< " "<<endl;

    Stack<char> charStack(5);
    charStack.push('A');
    charStack.push('Z');
    cout << "stack of characters"<<endl;
    charStack.display();
    cout << "Top element: " <<charStack.peek()<< " "<<endl;

    Stack<string> stringStack(5);
    stringStack.push("Dog");
    stringStack.push("Horse");
    cout << "stack of strings"<<endl;
    stringStack.display();
    cout << "Top element: " << stringStack.peek() << " "<<endl;

    Stack<double> doubleStack(5);
    doubleStack.push(3.14159);
    doubleStack.push(2.71828);
    cout << "double stacks"<<endl;
    doubleStack.display();
    cout << "Top element: " <<doubleStack.peek()<<" "<<endl;

    intStack.pop();
	return 0;
}
    */
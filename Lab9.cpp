#include <iostream>
using namespace std;
struct Node 
{ 
    int data; 
    Node* left; 
    Node* right; 

}; 

Node* create(int item)  
{  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  

Node* iterative_insert(Node* root, int item) {
    Node* newNode = create(item);

    // If tree is empty, new node becomes root
    if (root == nullptr)
	{
        return newNode;
	}

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;

        if (item < current->data)
            current = current->left;      
        else if (item > current->data)
            current = current->right;     
        else
            return root;  
    }

    if (item < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}
int main() 
{
 Node* root = NULL;  
   int keys[4];  
   for(int i=0;i<4;i++)  
    {  
    cout << "Enter value to be inserted";  
    cin>>keys[i];  
        root = iterative_insert(root, keys[i]);  
    }   	
  return 0;
}
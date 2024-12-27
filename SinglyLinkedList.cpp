// This section will be the implementation of singly linked list 
#include <iostream>
using namespace std;

struct  Node
{
    int data;
    Node* next;
};

Node *temp=nullptr,*head=nullptr; // temp is temporary pointer that will help us to iterate over our linked list and the head pointer is the used to indicate the start of the linked list 

// declaration of functions
void createLinkedList();
void display();
void insertAtBeginning();
void insertAtEnd();
int count();
void insertAtNthPosition();
void deletingTheFirstNode();
void deletingTheLastNode();
void deletingTheNthNode();
void reverseList();
void displayFromEnd(Node* current);

int main(){

    while(true){
        int choice;
        cout << "\n1. Create a linked list.\n";
        cout << "2. Display linked list.\n";
        cout << "3. Insert at the beginning.\n";
        cout << "4. Insert at the end.\n";
        cout << "5. Insert at nth position.\n";
        cout << "6. Delete from the beginning.\n";
        cout << "7. Delete from the end.\n";
        cout << "8. Delete at nth position.\n";
        cout << "9. Reverse a linked list.\n";
        cout << "10. Display from the last.\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

            switch(choice){
                case 1:
                    createLinkedList();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    insertAtBeginning();
                    break;
                case 4:
                    insertAtEnd();
                    break;
                case 5:
                    insertAtNthPosition();
                    break;
                case 6:
                    deletingTheFirstNode();
                    break;
                case 7:
                    deletingTheLastNode();
                    break;
                case 8:
                    deletingTheNthNode();
                    break;
                case 9:
                    reverseList();
                    break;
                case 10:
                    cout << "Displaying from the last to start: ";
                    displayFromEnd(head);
                    break;
                case 0:
                    exit(0);
                default:
                    cout << "Invalid Input.";
            }
    }

    return 0;
}

// create a node and link it to the list of the node that are created before they exist
// NB: in the next creating of a linked list we will ad the node at the last by iteration using the temp pointer we can add the node from the start which is very simple
void createLinkedList(){
    int n;
    cout << "Enter the number of elements you want to insert: ";
    cin>>n;
    for(int i=0;i<n;++i){
        Node *newNode=new Node(); // creating new Node using dynamic memory allocation
        cout<<"Enter number " << i+1<<": ";
        cin>>newNode->data;
        newNode->next=nullptr; // we initialize it as nullptr by considering the last node in which it's value must be nullptr
        if(head==nullptr){ // check if the created node is the first node to our list
            head=temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
}

// display function to display the data in the linked list just iterate over the list using the temp pointer we created till it becomes nullptr
void display(){
    temp=head;
    cout << "Here is your list: ";
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

// function to insert a node at the beginning of the linked list
void insertAtBeginning(){
    Node* newNode=new Node();
    cout << "Enter the number you want to insert at the beginning: ";
    cin>>newNode->data;
    if(head==nullptr){
        head=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
}

// function to insert a node at the end of the linked list
void insertAtEnd(){
    Node *newNode=new Node();
    cout << "Enter the number you want to insert at the end: ";
    cin>>newNode->data;
    newNode->next=nullptr;
    temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

// function to return the number fo nodes in a linked list
int count(){
    int count=0;
    temp=head;
    while (temp!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

// function to insert at the nth position this one the challenging one to implement the target is to find the to find the position of the Node before the given position
void insertAtNthPosition(){
    Node *newNode=new Node();
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    if(pos < 1 || pos > count()+1){
        cout <<"Invalid position.\n";
    }else{
        if(pos==1){ // if pos = 1 then we want to insert at the beginning 
            insertAtBeginning();
        }else if(pos==count()+1){ // if pos = count()+1 then we want to insert at the end 
            insertAtEnd();
        }else{
        cout << "Enter the number you want to insert at " << pos << ": ";
        cin>>newNode->data;
        newNode->next=nullptr;
            temp=head;
            for(int i=1; i<pos-1; ++i){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}

// function to delete the first node in the linked list 
void deletingTheFirstNode(){
    if(head==nullptr){
        cout << "The list is empty!\n";
    }else{
        temp=head;
        head=head->next;
        delete temp;
        cout << "First node delete successfully\n";
    }
}

// function to delete the last node in the linked list
void deletingTheLastNode(){
    if (head==nullptr){
        cout << "The list is empty!\n";
    }else{
        temp=head;
        if (temp->next->next!=nullptr){
            temp=temp->next;
        }
        Node *lastNode=temp;
        temp->next=nullptr;
        delete lastNode;
        cout << "Last node delete successfully\n";
    }
}

// function to delete the nth node in the linked list
void deletingTheNthNode(){
    int pos;
    cout << "Enter the position you want to delete: ";
    cin>> pos;
    if (pos < 1 || pos > count()+1){
        cout << "Invalid position.\n";
    }else{
        if(head==nullptr){
            cout << "The list is empty.\n";
        }else {
            if(pos == 1){
                deletingTheFirstNode();
            }else if (pos == count())
            {
                deletingTheLastNode();
            }else{
                temp=head;
                Node *prevNode=nullptr;
                for(int i=1;i<pos-1;++i){
                    prevNode=temp;
                    temp=temp->next;
                }
                prevNode->next=temp->next;
                delete temp;
                cout << "The " <<pos << "th Node deleted successfully.\n";
            }
        } 
        
    }
}

// reversing a linked list => it is changing the direction of our linked list the end becomes the start and the start becomes the end
void reverseList(){
    Node *prevNode=nullptr;
    Node *nextNode=head;
    Node *currentNode=head;
    if(head==nullptr){
        cout << "The list is empty." << endl;
        return;
    }else{
        while (nextNode!=nullptr)
        {
            nextNode=currentNode->next;
            currentNode->next=prevNode;
            prevNode=currentNode;
            currentNode=nextNode;
        }
    }
    head=prevNode;
    cout << "Linked list reversed successfully.\n";
}

// challenging question displaying nodes from the end to start with our reversing it first or using any tail pointer
void displayFromEnd(Node* current) {
    if (current == nullptr) {
        return; // Base case: Reached the end of the list
    }

    // Recursive call
    displayFromEnd(current->next);

    // Print the current node's data (unwinding phase)
    cout << current->data << " ";
}
// Implementation of singly circular linked list
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head=nullptr, *temp=nullptr;

// declaration of functions
void createCircularLinkedList();
void display();
void insertAtBeginning();
void insertAtEnd();
int count();
void insertAtNthPosition();
void deletingTheFirstNode();
void deletingTheLastNode();
void deletingTheNthNode();
void reverseList();
void displayFromEnd(Node* , Node* );

int main(){

    while(true){
        int choice;
        cout << "\n1. Create Circular linked list with n elements\n";
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
                    createCircularLinkedList();
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
                    if (head == nullptr) {
                        cout << "The list is empty." << endl;
                    } else {
                        displayFromEnd(head,nullptr);
                    }
                    break;
                case 0:
                    exit(0);
                default:
                    cout << "Invalid Input.";
            }
    }

    return 0;
}

// definition of functions
// function to create a circular linked list
void createCircularLinkedList(){
    int n;
    cout << "How many elements do you want? ";
    cin >> n;

    for(int i=0;i<n;++i){
        Node *newNode=new Node();
        cout << "Element " << i + 1 << ": ";
        cin>>newNode->data;
        newNode->next=head; // instead of nullptr the last node's next will be head pointer and it will point to the first or start Node
        if(head==nullptr){
            head=temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }
}

// function to display circular singly linked list
void display(){
    if (head==nullptr){
        cout <<"The list is Empty.\n";
        return;
    }
    temp=head;
    cout << "Here is your list: ";
    do{
        cout << temp->data << "->";
        temp=temp->next;
    }while (temp!=head);
    cout<<"HEAD\n";
}

// function to find the the number of nodes in the linked list
int count(){
    if (head==nullptr){
        cout << "The list is empty.\n";
    }
    int count=0;
    temp=head;
    do{
        count++;
        temp=temp->next;
    }while (temp!=head);

    return count;
}

// function to inset a node at the beginning
void insertAtBeginning(){
    Node *newNode=new Node();
    cout << "Enter the element to insert at the beginning: ";
    cin >> newNode->data;
    newNode->next=head;
    if(head==nullptr){
        head=newNode;
    }else{
        temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        head=newNode;
        temp->next=head;
    }
}

// function to insert a Node at the end
void insertAtEnd(){
    Node *newNode=new Node();
    cout << "Enter the element to insert at the end: ";
    cin >> newNode->data;
    newNode->next=head;
    if(head==nullptr){
        head=newNode;
    }else{
        temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

// function to insert a Node at the nth position
void insertAtNthPosition() {
    int pos,data;
    cout << "Enter the position to insert: ";
    cin >> pos;
    if(pos < 1 || pos > count()+1){
        cout <<"Invalid position.\n";
    }else{
        Node *newNode=new Node();
        if(pos==1){ // if pos = 1 then we want to insert at the beginning 
            insertAtBeginning();
            return;
        }else if(pos==count()+1){ // if pos = count()+1 then we want to insert at the end 
            insertAtEnd();
            return;
        }else{
            cout << "Enter the number you want to insert at " << pos << ": ";
            cin>>newNode->data;
                temp=head;
                for (int i = 1; i < pos-1 && temp->next!=head; i++)
                {
                    temp=temp->next;
                }
                newNode->next=temp->next;
                temp->next=newNode;
        }
    }
}

// function to delete the first Node 
void deletingTheFirstNode(){
    if(head==nullptr){
        cout << "The list is empty.\n";
        return;
    }
    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }
    temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    Node *firstNode=head;
    head=head->next;
    temp->next=head;
    delete firstNode;
}

// function to delete the last Node in the 
void deletingTheLastNode(){
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }

    temp=head;
    while (temp->next->next!=head)
    {
        temp=temp->next;
    }
    Node *lastNode=temp->next;
    delete lastNode;
    temp->next=head;
}

// function delete the nth Node
void deletingTheNthNode() {
    int pos;
    cout << "Enter the position you want to delete: ";
    cin >> pos;

    if (pos < 1 || pos > count()) {
        cout << "Invalid position.\n";
        return;
    }

    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (pos == 1) {
        deletingTheFirstNode();
        return;
    }

    if (pos == count()) {
        deletingTheLastNode();
        return;
    }

    // General case: delete node at position 'pos'
    temp = head;
    Node* prevNode = nullptr;

    // Traverse to the (pos - 1)-th node
    for (int i = 1; i < pos; ++i) {
        prevNode = temp;
        temp = temp->next;
    }

    if (prevNode != nullptr) {
        prevNode->next = temp->next;
    }

    delete temp; // Free the memory of the node to delete
    cout << "The " << pos << "th Node deleted successfully.\n";
}

// function to reverse a circular singly linked list
void reverseList(){
    if(head==nullptr || head==head->next){
        cout << "Nothing to reverse here";
        return;
    }
    Node *prevNode=nullptr;
    Node *currentNode=head;
    Node *nextNode=nullptr;

    do{
        nextNode=currentNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }while (currentNode!=head);
    head->next=prevNode;
    head=prevNode;
}

// function to display the items from the end to start
void displayFromEnd(Node* current, Node* start = nullptr) {
    // Initialize the start node during the first call
    if (start == nullptr) {
        start = current;
    }

    // Base case: Stop recursion after visiting all nodes once
    if (current->next == start) {
        cout << current->data << " "; // Print the last node in reverse order
        return;
    }

    // Recursive call to move to the next node
    displayFromEnd(current->next, start);

    // Print the current node's data during the unwinding phase
    cout << current->data << " ";
}

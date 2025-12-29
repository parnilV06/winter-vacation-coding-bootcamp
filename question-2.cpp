//Sort a Linked List of 0's 1's and 2's by changing links
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* insertValues(Node* head , int value){
    Node* newNode = new Node(value);
    if(head==nullptr){
        return newNode;
    }
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
    temp->next=newNode;
    return head;
    }
}
void priintList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
    int len;
    cin>>len;
    Node* head = nullptr;
    for(int i=0;i<len;i++){
        int value;
        cin>>value;
        head = insertValues(head , value);
    }
    Node* zeroD = new Node(-1);
    Node* oneD = new Node(-1);
    Node* twoD = new Node(-1);
    Node* zero = zeroD;
    Node* one = oneD;
    Node* two = twoD;
    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
        }
        else if(curr->data == 1){
            one->next = curr;
            one = one->next;
        }
        else{
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    two->next = nullptr;
    one->next = twoD->next;
    zero->next = oneD->next;
    head = zeroD->next;
    priintList(head);
    return 0;
    
}
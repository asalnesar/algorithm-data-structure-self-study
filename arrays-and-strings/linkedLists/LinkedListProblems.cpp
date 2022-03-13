#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

class Node {
    public:
        Node *next;
        int data;
        Node(int d){
            next= NULL;
            data=d;
        }
        void appendToTail(int d){
            Node *end=  new Node(d);
            Node *n = this;
            while(n->next != NULL){
                n=n->next;
            }
            n->next=end;
        }
        void printLinkedList(){
            Node *n = this;
            while(n->next != NULL){
                cout<< n->data << "->";
                n=n->next;
            }
            cout<<n->data<<endl;
        }
        Node deleteNode(int d)
        {
            Node *head = this;
            Node *n = this;
            if(n->data==d)  return *n->next;
            while(n->next != NULL)
            {
                if(n->next->data == d)
                {
                    n->next=n->next->next;
                    return *head;
                }
                n=n->next;
            }
            return *head;

        }

};

void removeDups(Node *head){
    unordered_set <int> hashTable;
    Node *previous = NULL;
    while(head != NULL){
        if(hashTable.count(head->data)){
            previous->next=head->next;
        } else {
            hashTable.insert(head->data);
            previous = head;
        }
        head = head-> next;
    }
}

void removeDupsWithoutBuffer(Node *head){
    Node *current = head;
    while(current != NULL){
        Node *runner = current;
        while(runner->next != NULL){
            if(runner->next->data == current->data){
                runner->next=runner->next->next;
            } else{
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

Node* nthToLast(Node *head, int k, int &i){
    if(head== NULL){
        return NULL;
    }
    Node *nd=nthToLast(head->next, k, i);
    i++;
    if(i==k){
        return head;
    }
    return nd;
}

Node* nthToLast(Node *head, int k){
    int i=0;
    return nthToLast(head, k , i);
}


void testRemoveDups(){
    Node *head= new Node(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(5);
    head->printLinkedList();
    removeDupsWithoutBuffer(head);
    head->printLinkedList();
}

void testKthElement(){
    Node *head= new Node(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(5);
    head->printLinkedList();
    Node *newLinkedList= nthToLast(head, 2);
    newLinkedList->printLinkedList();
}

int main(){
    testKthElement();
    return 0;
}
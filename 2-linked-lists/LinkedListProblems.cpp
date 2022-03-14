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

bool  deleteMiddleNode(Node *middle){
    if(middle==NULL || middle->next == NULL) return false;
    Node *next = middle->next;
    middle->data = next->data;
    middle->next=next->next;
    return true;
}

Node* partition(Node *n, int x){
    Node *head = n;
    Node *tail = n;
    while(n != NULL){
        Node *next = n->next;
        if(n->data < x){
            n->next = head;
            head=n;
        } else {
            tail->next = n;
            tail = n;
        }
        n = next;
    }
    tail->next = NULL;
    return head;
}

Node* sumList(Node *n, Node *m){
    Node *result = NULL;
    int carry = 0;

    while(n!= NULL || m!=NULL){
        int nData = n!= NULL ? n->data : 0;
        int mData = m!= NULL ? m->data : 0;
        int sum = nData + mData + carry;
        cout <<"sum: "<<sum<<endl;
        if(result==NULL){
            result = new Node(sum%10);
        } else {
            result->appendToTail(sum%10);
        }
        carry = (sum - (sum%10))/10;
        cout << "carry: "<<carry<<endl;
        if(n!= NULL){
            n = n->next;
        }
        if(m!=NULL){
            m=m->next;
        }
    }
    if(carry!=0){
        result->appendToTail(carry);
    }
    return result;
}

int length(Node *n){
    int count = 0;
    while(n!=NULL){
        count++;
        n=n->next;
    }
    return count;
}

Node* insertBefore(Node *n, int data){
    Node *head = new Node(data);
    if(n != NULL){
        head->next = n;
    }
    return head;
}

Node* padNode(Node *n, int padding){
    Node *head = n;
    for(int i = 0;i<padding;i++){
        head = insertBefore(head, 0);
    }
    return head;
}
Node* addHelper(Node *n, Node *m, int &carry){
    if(n == NULL && m == NULL) return NULL;
    Node *sum = addHelper(n->next, m->next, carry);
    int val = n->data  + m->data + carry;
    Node *fullResult = insertBefore(sum, val%10);
    carry = (val - val%10)/10;
    return fullResult;
}
Node* sumListForward(Node *n, Node*m){
    int len1 = length(n);
    int len2 = length(m);
    int carry = 0;
    if(len1 > len2){
        m= padNode(m, len1-len2);
    } 
    else if(len2 > len1){
        n = padNode(n, len2-len1);
    }
    Node *result = addHelper(n,m,carry);
    if(carry != 0){
        result = insertBefore(result, carry);
    }
    return result;
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

void testDeleteMiddle(){
    Node *head= new Node(1);
    head->appendToTail(2);
    head->appendToTail(3);
    head->appendToTail(4);
    head->appendToTail(5);
    head->appendToTail(6);
    head->appendToTail(7);
    head->printLinkedList();
    Node *middle= nthToLast(head, 3);
    middle->printLinkedList();
    bool result = deleteMiddleNode(middle);
    if(result){
        cout <<"Middle node removed."<<endl;
    } else {
        cout <<"Middle node cannot be removed."<<endl;
        
    }
    cout<<"New linked list:"<<endl;
    head->printLinkedList();
}

void testPartition(){
    Node *head= new Node(1);
    head->appendToTail(6);
    head->appendToTail(3);
    head->appendToTail(7);
    head->appendToTail(8);
    head->appendToTail(2);
    head->appendToTail(4);
    head->printLinkedList();
    head = partition(head, 4);
    head->printLinkedList();
}

void testSumList(){
    Node *n = new Node(9);
    n->appendToTail(7);
    n->appendToTail(8);
    n->printLinkedList();
    Node *m = new Node(6);
    m->appendToTail(8);
    m->appendToTail(5);
    m->printLinkedList();
    Node *result = sumList(n,m);
    result->printLinkedList();
}
void testSumListForward(){
    Node *n = new Node(6);
    n->appendToTail(1);
    n->appendToTail(7);
    n->printLinkedList();
    Node *m = new Node(2);
    m->appendToTail(9);
    m->appendToTail(5);
    m->printLinkedList();
    Node *result = sumListForward(n,m);
    result->printLinkedList();
}
int main(){
    testSumListForward();
    return 0;
}
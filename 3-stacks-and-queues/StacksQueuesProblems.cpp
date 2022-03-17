#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
struct StackNode{
    int data;
    StackNode *next;
};
class myStack{      
    private:
        StackNode *top = NULL;
    public:
        bool isEmpty(){
            return top==NULL;
        }
        void push(int d){
            StackNode *newNode = new StackNode();
            newNode->data = d;
            newNode->next = top;
            top = newNode;
        }
        void pop(){
            if(isEmpty()){
                cout << "Stack is empty"<<endl;
                return;
            }
            StackNode *popped = top;
            top = top->next;
            delete(popped);
        }

        int peak(){
            if(isEmpty()){
                cout << "Stack is empty"<<endl;
                return NAN;
            }
            return top->data;
        }

        void printLinkedList(){
            StackNode *s = top;
            while(s->next != NULL){
                cout<< s->data << "->";
                s=s->next;
            }
            cout<<s->data<<endl;
        }


};

void  testStack(){
    myStack *s = new myStack();
    int top = s->peak();
    cout<<"Peak: "<<top<<endl;
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->printLinkedList();
    top = s->peak();
    cout<<"Peak: "<<top<<endl;
    s->pop();
    s->printLinkedList();
    top = s->peak();
    cout<<"Peak: "<<top<<endl;
}

int main(){
    testStack();
    return 0;
}
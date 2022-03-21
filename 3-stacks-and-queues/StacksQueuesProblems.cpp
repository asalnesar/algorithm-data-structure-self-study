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

class multistack{
    private:
        int values[90];
        int sizes[3]={0};
        const int stackCapacity = 30;
    public:
        void push(int stackIndex, int value){
            if(sizes[stackIndex]>=stackCapacity){
                cout <<"Stack overflow"<<endl;
                return;
            }
            int position = (stackIndex * stackCapacity) + sizes[stackIndex];
            values[position] = value;
            sizes[stackIndex]++;
        }
        void pop(int stackIndex){
            if(sizes[stackIndex] <= 0){
                cout <<"Stack underflow"<<endl;
                return;
            }
            sizes[stackIndex]--;
        }
        int peak(int stackIndex){
            if(sizes[stackIndex]<=0 || sizes[stackIndex]>=stackCapacity){
                cout<<"Stack underflow/overflow problem"<<endl;
                return NAN;
            }
            int position = (stackIndex * stackCapacity) + sizes[stackIndex];
            return values[position];
        }
        void printStack(int stackIndex){
            int  start = stackIndex * stackCapacity;
            int end = start + sizes[stackIndex];
            for(int i = start; i< end; i++){
                if(i!= end-1){
                    cout<<values[i]<<"->";
                } else {
                    cout<<values[i]<<endl;
                }
                
            }
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

void testMultiStack(){
    multistack *s = new multistack();
    s->push(0,1);
    s->push(0,2);
    s->push(0,3);
    s->push(1,4);
    s->push(1,5);
    s->push(1,6);
    s->push(2,7);
    s->push(2,8);
    s->printStack(0);
    s->printStack(1);
    s->printStack(2);
    s->pop(1);
    s->printStack(1);

}

int main(){
    testMultiStack();
    return 0;
}
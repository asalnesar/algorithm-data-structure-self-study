#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>

using namespace std;
struct StackNode{
    int data;
    StackNode *next;
    int minOfSubstack;
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
            if(top == NULL){
                newNode->minOfSubstack = d;
            } else{
                newNode->minOfSubstack = d < top->minOfSubstack  ? d : top->minOfSubstack;
            }
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

        int min(){
            return top->minOfSubstack;
        }

        void printStack(){
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

class setOfStacks{
    private:
        vector<myStack*> stacks;
        int stackCapacity;
        int capacityCounter;
    public:
        setOfStacks(){
            stackCapacity = 3;
            capacityCounter=0;
        }
        void push(int value){
            if(stacks.size() == 0 || capacityCounter>= stackCapacity){
                capacityCounter = 0;
                myStack *s = new myStack();
                s->push(value);
                stacks.push_back(s);
                capacityCounter++;
            }
            else {
                stacks.at(stacks.size()-1)->push(value);
                capacityCounter++;
            }
        }
        void pop(){
            if(stacks.size() == 0){
                cout << "stack underflow"<<endl;
                return;
            }
            stacks.at(stacks.size()-1)->pop();
            capacityCounter--;
            if(capacityCounter==0)//means the last stack is empty now
            {
                stacks.pop_back();
                capacityCounter = stackCapacity;
            }
        }

        void printStacks(){
            for(int i =0; i<stacks.size();i++){
                cout << "Stack #" <<i+1 <<": ";
                stacks.at(i)->printStack();
            }
        }

        int peak(){
            if(stacks.size() == 0){
                cout << "stack underflow"<<endl;
                return NAN;
            }
            return stacks.at(stacks.size()-1)->peak();
        }
        void popAt(int index){
            if(index >= stacks.size()){
                cout << "stack underflow"<<endl;
                return;
            }
            stacks.at(index)->pop();
        }
};

class myQueue{
    private:
        myStack *in = new myStack();
        myStack *out = new myStack();
        int inSize =  0;
        int outSize = 0;
    public: 
        void push(int value){
            in->push(value);
            inSize ++;
        }
        int pop(){
            if(outSize == 0 && inSize ==0){
                cout<<"Queue underflow"<<endl;
                return -1;
            }
            else if(outSize == 0){
                while(!in->isEmpty()){
                    int d = in->peak();
                    in->pop();
                    inSize--;
                    out->push(d);
                    outSize++;
                }
                
            }
            int top =  out->peak();
            out->pop();
            outSize--;
            return top;
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
    s->printStack();
    top = s->peak();
    cout<<"Peak: "<<top<<endl;
    s->pop();
    s->printStack();
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

void testMin(){
    myStack *s = new myStack();
    s->push(3);
    s->push(2);
    s->push(4);
    s->push(1);
    s->printStack();
    cout << "MIN: " << s->min() <<endl;
    s->pop();
    s->printStack();
    cout << "MIN: " << s->min() <<endl;
}

void testSetOfStacks(){
    setOfStacks *s = new setOfStacks();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(6);
    s->push(7);
    s->push(8);
    s->push(9);
    s->push(10);
    s->printStacks();
    s->pop();
    s->pop();
    s->printStacks();
    s->push(10);
    s->push(11);
    s->push(12);
    s->push(13);
    cout<< "PEAK: " << s->peak()<<endl;
    s->printStacks();
    s->popAt(1);
    s->printStacks();

}

void testQueue(){
    myQueue *q = new myQueue();
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    cout <<"POP: " << q->pop() << endl;
    q->push(5);
    q->push(6);
    cout <<"POP: " << q->pop() << endl;
    cout <<"POP: " << q->pop() << endl;
    cout <<"POP: " << q->pop() << endl;
    cout <<"POP: " << q->pop() << endl;
    cout <<"POP: " << q->pop() << endl;
    cout <<"POP: " << q->pop() << endl;
}
int main(){
    testQueue();
    return 0;
}
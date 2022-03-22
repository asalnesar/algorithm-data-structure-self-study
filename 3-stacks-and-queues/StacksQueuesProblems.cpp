#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;
struct StackNode{
    int data;
    StackNode *next;
    int minOfSubstack;
};
enum Animal{
    Cat,
    Dog
};

class shelterQueue{
    private:
        queue<int> catsQueue;
        queue<int> dogsQueue;
        int rank = 0;
    public:
        void enqueue(Animal a){
            rank++;
            if(a==Animal::Cat){
                catsQueue.push(rank);
            }
            else{
                dogsQueue.push(rank);
            }
        }
        int dequeueDog(){
            int poppedRank;
            if(dogsQueue.empty()){
                printf("There are no more dogs");
                getchar();
                exit(0);
            }
            poppedRank = dogsQueue.front();
            dogsQueue.pop();
        }
        int dequeueCat(){
            int poppedRank;
            if(catsQueue.empty()){
                printf("There are no more cats");
                getchar();
                exit(0);
            }
            poppedRank = catsQueue.front();
            catsQueue.pop();
        }
        int dequeueAny(){
            if(catsQueue.front() < dogsQueue.front()){//cat is older
                return dequeueCat();
            }
            else{//dog is older
                return dequeueDog();
            }
        }
        void printQueues(){
            cout << "CATS:"<<endl;
            queue<int> cats = catsQueue;
            while(!cats.empty()){
                cout<< "Cat #" << cats.front()<< "->";
                cats.pop();
            }
            cout << endl;
            cout << "DOGS:"<<endl;
            queue<int> dogs = dogsQueue;
            while(!dogs.empty()){
                cout<< "Dog #" <<dogs.front() << "->";
                dogs.pop();
            }
            cout << endl;
        }
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
        int pop(){
            if(isEmpty()){
                cout << "Stack is empty"<<endl;
                return -1;
            }
            StackNode *popped = top;
            int data = popped->data;
            top = top->next;
            delete(popped);
            return data;
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

class sortedStack{
    private:
        myStack *sorted = new myStack();
        myStack *helper = new myStack();
    public:
        void push(int value){
            if(sorted->isEmpty()){
                sorted->push(value);
                return;
            }
            while(!sorted->isEmpty() && sorted->peak() < value){
                helper->push(sorted->pop());
            }
            sorted->push(value);
            while(!helper->isEmpty()){
                sorted->push(helper->pop());
            }
        }
        int pop(){
            if(sorted->isEmpty()){
                cout <<"stack underflow"<<endl;
                return -1;
            }
            return sorted->pop();
        }
        int print(){
            sorted->printStack();
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

void testSortedStack(){
    sortedStack *s = new sortedStack();
    s->push(6);
    s->print();
    s->push(3);
    s->print();
    s->push(9);
    s->print();
    s->push(7);
    s->print();
    s->push(1);
    s->print();
    s->push(2);
    s->print();
}

void testAnimalShelter(){
    Animal cat = Animal::Cat;
    Animal dog = Animal::Dog;
    shelterQueue *q = new shelterQueue();
    q->enqueue(cat);
    q->enqueue(dog);
    q->enqueue(cat);
    q->enqueue(cat);
    q->enqueue(dog);
    q->enqueue(dog);
    q->enqueue(cat);
    q->enqueue(dog);
    q->enqueue(cat);
    q->enqueue(dog);
    q->printQueues();
    q->dequeueAny();
    q->printQueues();
    q->dequeueCat();
    q->dequeueAny();
    q->printQueues();
}
int main(){
    testAnimalShelter();
    return 0;
}
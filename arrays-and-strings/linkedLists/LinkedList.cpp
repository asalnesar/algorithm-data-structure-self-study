#include <iostream>
#include <cstddef>

using namespace std;

class Node {
    private:
        Node *next;
        int data;
    public:
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

};

int main(){
    Node head(1);
    head.appendToTail(2);
    head.appendToTail(3);
    head.appendToTail(4);
    head.appendToTail(5);
    head.printLinkedList();

}
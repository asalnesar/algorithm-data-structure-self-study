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

int main(){
    Node head(1);
    head.appendToTail(2);
    head.appendToTail(3);
    head.appendToTail(4);
    head.appendToTail(5);
    head.printLinkedList();
    head=head.deleteNode(1);
    head.printLinkedList();

}
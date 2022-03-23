#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;
#define COUNT 10


enum State{
    visited,
    unvisited,
    visiting
};
struct Node{
    int value;
    vector<Node*> adjecents;
    State state;
};


class bstNode{
    public:
        bstNode *left;
        bstNode *right;
        int value;
        bstNode(int data){
            value= data;
            left = NULL;
            right = NULL;
        }
        void addLeft(bstNode *l){
            left= l;
        }
        void addRight(bstNode *r){
            right= r;
        }
        // Function to print binary tree in 2D
        // It does reverse inorder traversal
        void print2DUtil(bstNode *root, int space)
        {
            // Base case
            if (root == NULL)
                return;
        
            // Increase distance between levels
            space += COUNT;
        
            // Process right child first
            print2DUtil(root->right, space);
            // Print current node after space
            // count
            cout<<endl;
            for (int i = COUNT; i < space; i++)
                cout<<" ";
            cout<<root->value<<"\n";
    
            // Process left child
            print2DUtil(root->left, space);
    }
    void print(){
        print2DUtil(this, 0);
    }
};

class BinaryTreeLinkedList {
    public:
        BinaryTreeLinkedList *next;
        bstNode *treeNode;

        BinaryTreeLinkedList(){
            next= NULL;
            treeNode = NULL;
        }
        BinaryTreeLinkedList(bstNode *root){
            next= NULL;
            treeNode = root;
        }
        void appendToTail(bstNode *root){
            BinaryTreeLinkedList *end=  new BinaryTreeLinkedList(root);
            BinaryTreeLinkedList *n = this;
            if(n->treeNode == NULL){
                this->next = end->next;
                this->treeNode = end->treeNode;
                return;
            }
            while(n->next != NULL){
                n=n->next;
            }
            n->next=end;
        }
        void printLinkedList(){
            BinaryTreeLinkedList *n = this;
            while(n->next != NULL){
                cout<< n->treeNode->value << "->";
                n=n->next;
            }
            cout<<n->treeNode->value<<endl;
        }

};
class Graph{
    public:
        vector<Node*> nodes;
        Node* addNode(int value){
            Node *n = new Node();
            n->value = value;
            nodes.push_back(n);
            return n;
        }
        void connectNodes(int source, int destination)
        {
            int sourceIndex = -1;
            int destinationIndex  = -1;
            for(int i = 0; i<nodes.size(); i++){
                if(nodes[i]->value == source){
                    sourceIndex = i;
                }
                else if(nodes[i]->value == destination){
                    destinationIndex = i;
                }
                if(sourceIndex != -1 && destinationIndex != -1){
                    break;
                }
            }
            if(sourceIndex == -1){
                printf("Source node is not added to graph");
                return;
            }
            if (destinationIndex == -1){
                printf("destination node is not added to graph");
                return;
            }
            nodes[sourceIndex]->adjecents.push_back(nodes[destinationIndex]);
        }
        void printNodes(){
            for(Node *n : nodes){
                cout << n->value << ": ";
                for(Node *v : n->adjecents){
                    cout << v->value << ",";
                }
                cout <<endl;
            }
        }
};

bool hasrouteBetweenNodes(Graph g, Node *s, Node *d){
    queue<Node*> nodesQueue;
    if(s == d){
        return true;
    }
    for(Node *n: g.nodes){
        n->state = State::unvisited;
    }
    s->state = State::visiting;
    nodesQueue.push(s);
    Node *current;
    while(!nodesQueue.empty()){
        current = nodesQueue.front();
        nodesQueue.pop();
        if(current != NULL){
            for(Node *v : current->adjecents){
                if(v->state == State::unvisited){
                    if(v == d){
                        return true;
                    } else {
                        v->state=State::visiting;
                        nodesQueue.push(v);
                    }
                }
            }
            current->state = State::visited;
        }
        
    }
    return false;
}



bstNode* makeTree(vector<int> sorted, int startIndex, int endIndex){
    if(startIndex >= sorted.size() || endIndex < 0){
        return NULL;
    }
    else if(startIndex == endIndex){//only one element
        return new bstNode(sorted[startIndex]);
    } 
    else if(startIndex == endIndex - 1){//two elements
        bstNode *result = new bstNode(sorted[endIndex]);
        result->addLeft(new bstNode(sorted[startIndex]));
        return result;
    }
    else {
        int middleIndex = round((startIndex + endIndex)/2);
        cout << "middle index is: "<<middleIndex<<endl;
        bstNode *result = new bstNode(sorted[middleIndex]);
        bstNode *left = makeTree(sorted, startIndex, middleIndex-1);
        bstNode *right = makeTree(sorted, middleIndex  + 1, endIndex);
        result->addLeft(left);
        result->addRight(right);
        return result;
    }
}

bstNode* minimalTree(vector<int> sorted){
    if(sorted.size() == 0){
        cout<<"Array empty"<<endl;
        return NULL;
    }
    return makeTree(sorted, 0, sorted.size()-1);
}

vector<BinaryTreeLinkedList*> listDepths(bstNode *root){
    vector<BinaryTreeLinkedList*> results;
    BinaryTreeLinkedList* current;
    if(root != NULL){
        current= new BinaryTreeLinkedList(root);
    }
    while(current != NULL){
        results.push_back(current);
        current->printLinkedList();
        BinaryTreeLinkedList *parents = current;
        current = new BinaryTreeLinkedList();
        while(parents != NULL){
            if(parents->treeNode->left != NULL){
                current->appendToTail(parents->treeNode->left);
            }
            if(parents->treeNode->right != NULL){
                current->appendToTail(parents->treeNode->right);
            }
            parents = parents->next;
        }
    }
    return results;

}
//-----------------------------test methods------------------------------
void testRouteBetweenNodes(){
    Graph g;
    Node *s = g.addNode(1);
    Node *s2 = g.addNode(2);
    g.addNode(3);
    Node *d2 = g.addNode(4);
    g.addNode(5);
    Node *d = g.addNode(6);
    g.connectNodes(1,2);
    g.connectNodes(1,4);
    g.connectNodes(2,5);
    g.connectNodes(3,2);
    g.connectNodes(4,3);
    g.connectNodes(4,5);
    g.connectNodes(4,6);
    g.connectNodes(5,6);
    g.printNodes();
    bool result = hasrouteBetweenNodes(g, s,d);
    bool result2 = hasrouteBetweenNodes(g,s2,d2);
    cout << "Path between "<<s->value << " and " << d->value << " result: " <<result <<endl;
    cout << "Path between "<<s2->value << " and " << d2->value << " result: " <<result2 <<endl;
}
void testBst(){
    bstNode *root= new bstNode(5);
    bstNode *left= new bstNode(2);
    bstNode *right = new bstNode(7);
    root->addLeft(left);
    root->addRight(right);
    root->print();
}

void testMinimalTree(){
    vector<int> sorted;
    sorted.push_back(1);
    sorted.push_back(2);
    sorted.push_back(3);
    sorted.push_back(4);
    sorted.push_back(5);
    sorted.push_back(6);
    sorted.push_back(7);
    sorted.push_back(8);
    sorted.push_back(9);
    sorted.push_back(10);
    bstNode *result = minimalTree(sorted);
    result->print();
}

void testListDepths(){
    vector<int> sorted;
    sorted.push_back(1);
    sorted.push_back(2);
    sorted.push_back(3);
    sorted.push_back(4);
    sorted.push_back(5);
    sorted.push_back(6);
    sorted.push_back(7);
    sorted.push_back(8);
    sorted.push_back(9);
    sorted.push_back(10);
    bstNode *result = minimalTree(sorted);
    result->print();
    vector<BinaryTreeLinkedList*> depths = listDepths(result);
    cout <<"Depths: "<<endl;
    for(BinaryTreeLinkedList *l : depths){
        l->printLinkedList();
    }
}
int main(){
    testListDepths();
    return 0;
}
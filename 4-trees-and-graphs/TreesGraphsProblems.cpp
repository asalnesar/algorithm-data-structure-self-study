#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
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

bool checkHeight(bstNode *root, int &height){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    int leftHeight = root->left != NULL ? height + 1 : height;
    int rightHeight = root->right != NULL ? height + 1 : height;
    height++;
    bool leftIsBalanced = checkHeight(root->left, leftHeight);
    bool rightIsBalanced = checkHeight(root->right, rightHeight);
    bool rootIsBalanced = abs(leftHeight - rightHeight)<=1;
    return rootIsBalanced && leftIsBalanced && rightIsBalanced;
}

bool checkBalanced(bstNode *root){
    int height = 0;
    return checkHeight(root, height);
}

bool validateBst(bstNode *root, int min, int max){
    if(root==NULL) return true;
    if(!(root->value > min) || !(root->value <= max)) return false;
    if(!validateBst(root->left, min, root->value) || !validateBst(root->right, root->value, max)) return false;
    return true;
}

bool validateBst(bstNode *root){
    return validateBst(root, INT_MIN, INT_MAX);
}
bstNode* commonAncestorHelper(bstNode *root, bstNode *p, bstNode *q, bool &foundAncestor){
    if(root == NULL){
        foundAncestor = false;
        return NULL;
    }
    if(root == p && root == q){
        foundAncestor = true;
        return root;
    }

    bstNode* x = commonAncestorHelper(root->left, p,q,foundAncestor);
    if(foundAncestor){
        return x;
    }
    bstNode* y = commonAncestorHelper(root->right, p,q,foundAncestor);
    if(foundAncestor){
        return y;
    }
    if(x!=NULL && y!=NULL){
        foundAncestor = true;
        return root;
    }
    else if(root == p || root == q){
        foundAncestor = x!=NULL || y!=NULL;
        return root;
    }
    else{
        foundAncestor = false;
        return x!= NULL ? x : y;
    }
}

bstNode* commonAncestor(bstNode *root, bstNode *p, bstNode *q){
    bool foundAncestor = false;
    bstNode *result = commonAncestorHelper(root,p,q, foundAncestor);
    if(foundAncestor){
        return result;
    }
    return NULL;
}

void print_map(std::unordered_map<int, int> &m)
{
    for (auto &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
void incrementHashTable(unordered_map<int, int> &pathsCount, int key, int delta){
    int  newCount = pathsCount[key] + delta;
    if(newCount == 0){
        pathsCount.erase(key);
    } else {
        pathsCount[key] = newCount;
    }
}
int countPathsWithSum(bstNode *root, int targetSum, int runningSum, unordered_map<int, int> &pathsCount){
    if(root==NULL) return  0;
    runningSum += root->value;
    int sum = runningSum - targetSum;
    int totalPaths = pathsCount[sum];

    if(runningSum==targetSum){
        totalPaths++;
    }
    cout << "Node:" <<root->value<< " /runningSum: " << runningSum << endl;
    print_map(pathsCount);
    cout  <<"--------NODE:"<<root->value<<endl;
    incrementHashTable(pathsCount, runningSum, 1);
    totalPaths += countPathsWithSum(root->left, targetSum, runningSum, pathsCount);
    totalPaths += countPathsWithSum(root->right, targetSum, runningSum, pathsCount);
    incrementHashTable(pathsCount, runningSum, -1);
    print_map(pathsCount);
    cout  <<"--------NODE:"<<root->value<<endl;
    cout<<"TOTAL PATH:"<<totalPaths<<endl;
    return totalPaths;
}
int countPathsWithSum(bstNode *root, int targetSum){
    unordered_map<int, int> pathsCount;
    return countPathsWithSum(root, targetSum, 0 , pathsCount);
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

void testBalanced(){
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
    bool isBalanced = checkBalanced(result);
    cout <<"tree balanced: " << isBalanced <<endl;

    bstNode *i = new bstNode(1);
    i->addLeft(result);
    i->print();
    bool isBalanced2 = checkBalanced(i);
    cout <<"tree balanced: " << isBalanced2 <<endl;
}

void testValidateBst(){
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
    bool isBst = validateBst(result);
    cout <<"tree BST: " << isBst <<endl;

    bstNode *i = new bstNode(1);
    i->addLeft(result);
    i->print();
    bool isBst2 = validateBst(i);
    cout <<"tree BST: " << isBst2 <<endl;
}

void testCommonAncestor(){
    bstNode *root= new bstNode(5);
    bstNode *left= new bstNode(2);
    bstNode *right = new bstNode(7);
    root->addLeft(left);
    root->addRight(right);

    bstNode *root2= new bstNode(15);
    bstNode *left2= new bstNode(11);
    bstNode *right2 = new bstNode(17);
    bstNode *left22= new bstNode(16);
    bstNode *right22 = new bstNode(18);
    right2->addLeft(left22);
    right2->addRight(right22);
    root2->addLeft(left2);
    root2->addRight(right2);

    bstNode *main = new bstNode(10);
    main->addLeft(root);
    main->addRight(root2);

    main->print();
    bstNode  *common = commonAncestor(main, left2, left22);//11 and  16
    cout <<"Common ancestor: " <<common->value <<endl;
    

}

void testCountPath(){
    bstNode *root= new bstNode(5);
    bstNode *left= new bstNode(2);
    bstNode *right = new bstNode(7);
    root->addLeft(left);
    root->addRight(right);

    bstNode *root2= new bstNode(15);
    bstNode *left2= new bstNode(11);
    bstNode *right2 = new bstNode(-15);
    bstNode *left22= new bstNode(5);
    bstNode *right22 = new bstNode(18);
    right2->addLeft(left22);
    right2->addRight(right22);
    root2->addLeft(left2);
    root2->addRight(right2);

    bstNode *main = new bstNode(10);
    main->addLeft(root);
    main->addRight(root2);

    main->print();
    cout << "Count path for 15: "<<countPathsWithSum(main, 15)<<endl;
}
int main(){
    testCountPath();
    return 0;
}
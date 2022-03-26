#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;
#define COUNT 10

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

bool hasSubtree(bstNode *t1, bstNode *t2){
    if(t1 == NULL ){
        return false;
    }
    if(t1== t2){
        return true;
    }
    return hasSubtree(t1->left, t2) || hasSubtree(t1->right, t2);
}

void testSubtree(){
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

    bstNode *right3 = new bstNode(17);
    bstNode *left23= new bstNode(16);
    bstNode *right23 = new bstNode(18);
    right3->addLeft(left23);
    right3->addRight(right23);
    main->print();
    right2->print();
    cout <<"Has subtree:"<< hasSubtree(main, right3)<<endl;
}

int main(){
    testSubtree();
    return 0;
}
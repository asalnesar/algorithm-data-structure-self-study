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

vector<vector<int> > weaveLists(vector<int> first, vector<int> second, vector<int> prefix){
    vector<vector<int> > results;

    if(first.size()==0 || second.size()==0){
        vector<int> result;
        result.insert(result.end(),prefix.begin(),prefix.end());
        result.insert(result.end(),first.begin(),first.end());
        result.insert(result.end(),second.begin(),second.end());
        results.push_back(result);
        return results;
    }
    int headFirst = first.at(0);
    prefix.push_back(headFirst);
    vector<int> remainingFirst(first.begin()+1, first.end());
    vector<vector<int> > childResults = weaveLists(remainingFirst, second, prefix);
    prefix.pop_back();
    results.insert(results.end(),childResults.begin(),childResults.end());

    headFirst = second.at(0);
    prefix.push_back(headFirst);
    vector<int> remainingSecond(second.begin()+1, second.end());
    childResults = weaveLists(first, remainingSecond, prefix);
    prefix.pop_back();
    results.insert(results.end(),childResults.begin(),childResults.end());
    
    return results;
}

vector<vector<int> > findSequence(bstNode *root){
    vector<vector<int> > result;

    if(root == NULL){
        vector<int> tmp;
        result.push_back(tmp);
        return result;
    }
    if(root->left==NULL && root->right==NULL){
        vector<int> tmp;
        tmp.push_back(root->value);
        result.push_back(tmp);
        return result;
    }
    vector<int> prefix;
    prefix.push_back(root->value);

    vector<vector<int> > tempResult, left, right;
    left= findSequence(root->left);
    right = findSequence(root->right);
    for(vector<int> leftArr : left){
        for(vector<int> rightArr : right){
            tempResult = weaveLists(leftArr, rightArr, prefix);
            result.insert(result.end(), tempResult.begin(), tempResult.end());
        }
    }
    return result;
}

void testBstSequence(){
    bstNode *root= new bstNode(2);
    bstNode *left= new bstNode(1);
    bstNode *right = new bstNode(3);
    root->addLeft(left);
    root->addRight(right);
    root->print();
    vector<vector<int> > results = findSequence(root);
    for(vector<int> arr: results){
        for(int num : arr){
            cout<<num << ", ";
        }
        cout<<endl;
    }
}


int main(){
    testBstSequence();
    
    return 0;
}
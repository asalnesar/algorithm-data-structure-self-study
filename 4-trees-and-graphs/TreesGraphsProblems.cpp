#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

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
int main(){
    testRouteBetweenNodes();
    return 0;
}
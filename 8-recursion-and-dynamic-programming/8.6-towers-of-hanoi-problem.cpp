#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

class Tower{
    public:
        stack<int> disks;
        void add(int d){
            if(!disks.empty() && disks.top()<d){
                cout<<"ERROR"<<endl;
            }
            else{
                disks.push(d);
            }
        }
        void showDisks(string name){
            auto copy = disks;
            cout<<"TOWER DISKS:"<<name<<endl;
            while(!copy.empty()){
                cout<< copy.top()<< endl;
                copy.pop();
            }
            cout<<"-------------"<<endl;
        }
};
void moveTop(Tower source, Tower destination){
    if(source.disks.empty()) return;
    int d = source.disks.top();
    source.disks.pop();
    destination.add(d);
}
void moveDisks(int n, Tower source, Tower destination, Tower buffer){
    if(n<=0) return;
    moveDisks(n-1, source, buffer, destination);
    buffer.showDisks("buffer");
    moveTop(source, destination);
    moveDisks(n-1, buffer, destination, source);
}

int main(){
    Tower tower1,tower2,tower3;
    tower1.add(5);
    tower1.add(4);
    tower1.add(3);
    tower1.add(2);
    tower1.add(1);
    tower1.showDisks("tower 1");
    tower2.showDisks("tower 2");
    tower3.showDisks("tower 3");
    moveDisks(5,tower1,tower3,tower2);
    tower1.showDisks("tower 1");
    tower2.showDisks("tower 2");
    tower3.showDisks("tower 3");
    return 0;

}

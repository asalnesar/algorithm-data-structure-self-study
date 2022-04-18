#include <iostream>
#include <string>

using namespace std;

void printParens(int count, int opened, int closed, string arrangement){
    cout <<"***"<< arrangement << endl;
    if(closed > opened){
        return;
    }
    else if(opened > count){
        return;
    }
    else if(arrangement.length() == count * 2){
        cout << arrangement << endl;
    }
    printParens(count , opened + 1 , closed, arrangement + "(");
    printParens(count, opened, closed + 1, arrangement + ")");
}

void printParens(int count){
    printParens(count , 0 , 0, "");
}

int main(){
    printParens(3);
    return 0;
}
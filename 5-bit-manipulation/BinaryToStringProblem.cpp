#include <cstdint>
#include <iostream>
#include <bitset>
#include <sstream>
#include <string>

using namespace std;

string binaryToString(double d){
    if(d>=1 || d<=0){
        return "Error!";
    }
    stringstream s;
    s<<".";
    while(d>0){
        if(s.str().length()>=32){
            return "Error";
        }
        double r = d*2;
        if(r>=1){
            s<<"1";
            d = r-1;
        } else {
            s<<"0";
            d=r;
        }
    }
    return s.str();
}

int main(){
    cout << binaryToString(0.25)<<endl;
    return 0;
}
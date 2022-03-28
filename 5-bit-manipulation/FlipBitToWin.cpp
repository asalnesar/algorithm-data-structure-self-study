#include <cstdint>
#include <iostream>
#include <bitset>
#include <sstream>
#include <string>

using namespace std;

int flipBitToWin(int num){
    unsigned long binary = bitset<32>(num).to_ulong();
    int previous1s = 0;
    int current1s = 0;
    int maxLength = 0;
    while(binary!=0){
        if((binary&1)==1){//bit is 1
            current1s++;
        } else {//bit is 0
            previous1s = (binary&2)==0 ? 0 : current1s;
            current1s=0;
        }
        maxLength = max(previous1s + current1s + 1 , maxLength);
        cout<< bitset<16>(binary) << endl;
        binary>>=1;

    }
    return maxLength;
}

int main(){
    cout << "flip to win: \n"<< flipBitToWin(1775)<<endl;
    return 0;
}
#include <cstdint>
#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>


using namespace std;

int getNext(unsigned long binary){
    int tailZeros = 0;
    int rightMost1s = 0;
    int zeroPos = 0;
    unsigned long tmp = binary;
    while(tmp!=0 && !(tmp&1)){//tail zeros
        tailZeros++;
        tmp >>=1;
    }
    while(tmp!=0 && (tmp&1)){//sequence of right most 1s
        rightMost1s++;
        tmp >>= 1;
    }
    zeroPos = rightMost1s + tailZeros;
    if(zeroPos == 0 || zeroPos>= 31){
        return -1;
    }
    binary |= 1<<zeroPos;//flip first not-tail zero to 1
    binary &= ~((1<<zeroPos)-1);//clear all tail zeros and right most 1s from 0 through zeroPos
    //now we want rightMost1s-1 1s in the least significant bits
    binary |= (1<<(rightMost1s-1))-1;
    return binary & INT32_MAX;
}

int getPrev(unsigned long binary){
    int tailOnes = 0;
    int rightMost0s =0;
    int onePos=0;
    unsigned long tmp = binary;
    while(tmp>0 && (tmp&1)){
        tailOnes++;
        tmp>>=1;
    }
    if(tmp==0){
        return -1;
    }
    while(tmp>0 && !(tmp&1)){
        rightMost0s++;
        tmp>>=1;
    }
    onePos = tailOnes+rightMost0s;
    binary &= ((~0) << (onePos+1));//clears from p to 0
    binary |= (1<<(tailOnes+1)) -1;//sequence of 1s at least significant
    return binary & INT32_MAX;
}

vector<int> getNextNumbers(int num){
    vector<int> result;
    if(num<0){
        return result;
    }
    unsigned long binary = bitset<32>(num).to_ulong();
    result.push_back(getNext(binary));
    result.push_back(getPrev(binary));
    return result;

}

int main(){
    vector<int> result = getNextNumbers(13948);
    cout <<"Main number: "<< bitset<32>(13948) << endl;
    cout <<"Next number: "<< bitset<32>(result[0]) << endl;
    cout <<"Prev number: "<< bitset<32>(result[1]) << endl;
    return 0;
}
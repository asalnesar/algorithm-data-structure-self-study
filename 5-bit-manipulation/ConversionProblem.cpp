#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std;

int countBitsToConvert(int a, int b){
    int counter=0;
    auto aBits= bitset<32>(a).to_ulong();
    auto bBits = bitset<32>(b).to_ulong();
    auto c = aBits ^ bBits;
    while(c!=0){
        counter += c&1;
        c >>= 1;
    }
    return counter;
}

int countBitsToConvert2(int a, int b){
    int counter=0;
    auto aBits= bitset<32>(a).to_ulong();
    auto bBits = bitset<32>(b).to_ulong();
    while(aBits!=0 || bBits!=0){
        if((aBits ^ bBits)&1){
            counter++;
        }
        aBits>>=1;
        bBits>>=1;
    }
    return counter;
}

int main(){
    auto count = countBitsToConvert2(29,15);
    cout<< "29 ->" << bitset<8>(29) << endl;
    cout<< "15 ->" << bitset<8>(15) << endl;
    cout << "Bit flips to convert = " << count <<endl;
    return 0;
}
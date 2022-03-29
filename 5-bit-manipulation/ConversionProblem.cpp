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

int main(){
    auto count = countBitsToConvert(36,8);
    cout<< "36 ->" << bitset<8>(36) << endl;
    cout<< "8 ->" << bitset<8>(8) << endl;
    cout << "Bit flips to convert = " << count <<endl;
    return 0;
}
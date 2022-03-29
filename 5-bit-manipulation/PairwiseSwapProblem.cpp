#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std;

int swapPairwise(int n){
    //1010101010 = 0xaaaaaaaa  for odd ->shift to right
    //0101010101 = 0x55555555 for even -> shift to left
    return ((n & 0xaaaaaaaa)>>1 |  (n & 0x55555555)<<1);
}

int main(){
    int n = 5225;
    int result = swapPairwise(5225);
    cout<<bitset<16>(n)<<endl;
    cout<<bitset<16>(result)<<endl;
}
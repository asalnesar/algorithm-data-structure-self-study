#include <cstdint>
#include <iostream>
#include <bitset>



using namespace std;

int32_t insertion(int32_t N, int32_t M, int i, int j){
    int w = j - i;
    if(w<= 0){
        return N;
    }
    int32_t mask = (~0 << (j+1)) | ((1 << i) - 1);
    return (N & mask) | (M << i);
}

int main(){
    auto result = insertion(0b10000000000, 0b10011, 2, 6);
    std::cout << bitset<11>(result) << endl;
    return 0;
}
#include <cstdint>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

void drawLine(vector<int8_t> screen, int width, int x1, int x2, int y){
    vector<int8_t> tmp = screen;
    if(width%8 != 0){
        cout<<"ERROR: Width should be divisible to 8."<<endl;
        return;
    }
    int bytesInRow = width/8;
    int yStartIndex = y*bytesInRow;  //in screen vector
    int startPixelRow = yStartIndex + (x1/8);
    int endPixelRow = yStartIndex + (x2/8);
    if(startPixelRow  == endPixelRow){
        int mask = (1 << (x2-x1+1))-1 << (7-(x2%8));
        tmp[startPixelRow] |= mask;
    }
    else{
        //first row
        tmp[startPixelRow] |= (1<<(7-(x1%8)+1))-1; 
        //last row
        tmp[endPixelRow] |= ~((1<<(7-(x2%8)))-1);
        for(int  i = startPixelRow+1; i<endPixelRow; i++){
            tmp[i]  |= (1<<8)-1;
        }
    }
    for(int8_t pixelByte : tmp){
        cout <<bitset<8>(pixelByte)<<endl;
    }

}

int main(){
    vector<int8_t> screen;
    for(int i=0; i<21; i++){
        screen.push_back(0);
    }
    drawLine(screen, 24, 3, 21, 4);
    return 0;
}
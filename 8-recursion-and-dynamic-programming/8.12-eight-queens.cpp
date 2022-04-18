#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int GRID_SIZE = 8;

bool checkValidity(vector<int> columns,int row, int column){
    for(int row2=0; row2<row;row2++){
        int column2 = columns[row2];
        if(column2==column){
            return false;
        }

        int colDiff = abs(column2-column);
        int rowDiff = row - row2;
        if(colDiff == rowDiff){
            return false;
        }
    }
    return true;
}

vector<vector<int> > placeQueens(int row, vector<int> columns){
    vector<vector<int> > results;
    if(row == GRID_SIZE){
        results.push_back(columns);
        return results;
    }
    for(int column =0 ; column < GRID_SIZE; column++){
        if(checkValidity(columns,row,column)){
            columns[row]=column;
            auto someResults = placeQueens(row+1, columns);
            results.insert(results.end(), someResults.begin(), someResults.end());
        }
    }
    return results;
}

vector<vector<int> > placeQueens(){
    vector<int> columns;
    for(int i=0; i<8;i++){
        columns.push_back(0);
    }
    return placeQueens(0,columns);
}

void printMaps(vector<vector<int> > results){
    for(auto cols : results){
        cout<<endl;
        cout << "********"<<endl;
        cout<<endl;
        for(int row =0; row < GRID_SIZE; row++){
            for(int col=0; col<GRID_SIZE;col++){
                if(cols[row]==col){
                    cout << "1";
                }
                else{
                    cout<<"0";
                }
            }
            cout<<endl;
        }
    }
}
int main(){
    auto results = placeQueens();
    printMaps(results);
    return 0;
}
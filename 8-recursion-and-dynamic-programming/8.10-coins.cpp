#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int makeChangeHelper(int total, vector<int> coins, int index, vector<vector<int> > map){
    if(map[total][index]>0){
        return map[total][index];
    }
    int coin = coins[index];
    if(index == coins.size()-1){
        int remaining = total % coin;
        return remaining==0 ? 1 :  0;
    }
    int ways =0;
    for(int amount =0; amount <= total; amount += coin){
        ways +=makeChangeHelper(total-amount, coins, index+1, map);
    }
    map[total][index]=ways;
    return ways;
}

int makeChange(int total, vector<int> coins){
    vector<vector<int> > map;
    for(int i=0; i<=total+1; i++){
        vector<int> row;
        for(int j=0; j<= coins.size(); j++){
            row.push_back(0);
        }
        map.push_back(row);
    }
    return makeChangeHelper(total, coins, 0, map);
}

int main(){
    int amount = 77;
    vector<int> coins;
    coins.push_back(25);
    coins.push_back(10);
    coins.push_back(5);
    coins.push_back(1);
    cout<< "Make change for " << amount << ": " << makeChange(amount, coins)<< endl;
    return 0;

}
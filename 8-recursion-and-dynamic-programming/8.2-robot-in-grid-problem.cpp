#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>


using namespace std;

struct Point{
    int row;
    int column;
};

bool hasPath(vector<vector<bool> > maze, int row, int col, vector<Point> &path){
    if(col< 0 || row< 0 || !maze[row][col]) return false;
    bool isAtOrigin = row == 0 && col == 0;
    if(isAtOrigin || hasPath(maze, row-1, col, path) || hasPath(maze, row, col-1, path)){
        Point p;
        p.row = row;
        p.column = col;
        path.push_back(p);
        return true;
    }
    return false;
}
vector<Point> getPath(vector<vector<bool> > maze){
    vector<Point> path;
    if(maze.size()==0) return path;
    if(hasPath(maze, maze.size()-1, maze[0].size()-1, path)){
        return path;
    }
    path.clear();
    return path;
}

vector<vector<bool> >  createMaze(int row, int col){
    vector<vector<bool> > maze;
    for(int r=0; r< row; r++){
        vector<bool> mazeRow;
        for(int c=0;c<col;c++){
            mazeRow.push_back(true);
        }
        maze.push_back(mazeRow);
    }
    return maze;
}

int main(){
    vector<vector<bool> > maze = createMaze(11, 9);
    for(vector<bool> r : maze){
        for(bool b : r){
            cout<< b << "-";
        }
        cout<<endl;
    }
    auto path = getPath(maze);
    for(Point  p : path){
        cout<<"("<< p.row <<", " <<p.column <<")"<<endl;
    }
    return 0;
}
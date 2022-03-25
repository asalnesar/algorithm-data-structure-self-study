#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Project{
    private:
        vector<Project*> children;
        unordered_map<string, Project*> map;
        string name;
        int dependencies = 0;
    public:
        Project(){}
        Project(string n){
            name = n;
        }
        string getName(){
            return name;
        }
        void incrementDependencies(){
            dependencies++;
        }
        void decrementDependencies(){
            dependencies--;
        }
        void addNeighbour(Project *p){
            if(map.find(p->getName())==map.end()){
                children.push_back(p);
                map[p->getName()] = p;
                p->incrementDependencies();
            }
        }
        vector<Project*> getChildren(){
            return children;
        }
        int getDependencies(){
            return dependencies;
        }

};

class Graph{
    private:
        vector<Project*> projects;
        unordered_map<string, Project*> map;
    public:
        Project* getOrCreateProject(string name){
            if(map.find(name)==map.end()){
                Project *p=  new Project(name);
                projects.push_back(p);
                map[name]=p;
            }
            return map[name];
        }
        void addEdge(string s, string e){
            Project *start = getOrCreateProject(s);
            Project *end = getOrCreateProject(e);
            start->addNeighbour(end);
        }
        vector<Project*> getProjects(){
            return projects;
        }
        void printNodes(){
            for(Project *n : projects){
                cout << n->getName() << ": ";
                for(Project *v : n->getChildren()){
                    cout << v->getName() << ",";
                }
                cout <<endl;
            }
        }
};

Graph buildGraph(vector<string> projects, vector<vector<string> > dependencies){
    Graph g;
    for(string proj : projects){
        g.getOrCreateProject(proj);
    }
    for(vector<string> dependencyPair: dependencies){
        string first = dependencyPair[0];
        string second = dependencyPair[1];
        g.addEdge(first, second);

    }
    return g;
}

void addNonDependent(vector<Project*> &orders, vector<Project*> projects){
    for(Project *proj: projects){
        if(proj->getDependencies()==0){
            orders.push_back(proj);
        }
    }
}

vector<Project*> orderProjects(vector<Project*> projects){
    vector<Project*> orders;
    addNonDependent(orders, projects);
    int processed = 0;
    while(processed < projects.size()){
        Project *current = orders[processed];

        if(current == NULL){
            cout<< "ERROR: loop dependencies"<<endl;
            getchar();
            exit(0);
        }
        vector<Project*> children = current->getChildren();
        for(Project *child : children){
            child->decrementDependencies();
        }
        addNonDependent(orders,children);
        processed++;

    }
    return orders;
}

vector<Project*>  findBuildOrder(vector<string> projects, vector<vector<string> > dependencies){
        Graph g = buildGraph(projects, dependencies);
        g.printNodes();
        return orderProjects(g.getProjects());
}

void testBuildOrder(){
    vector<string> projects;
    projects.push_back("a");
    projects.push_back("b");
    projects.push_back("c");
    projects.push_back("d");
    projects.push_back("e");
    projects.push_back("f");

    vector<vector<string> > dependencies;

    vector<string> dep;
    dep.push_back("a");
    dep.push_back("d");    
    dependencies.push_back(dep);

    dep.clear();
    dep.push_back("f");
    dep.push_back("b");    
    dependencies.push_back(dep);

    dep.clear();
    dep.push_back("b");
    dep.push_back("d");    
    dependencies.push_back(dep);

    dep.clear();
    dep.push_back("f");
    dep.push_back("a");    
    dependencies.push_back(dep);

    dep.clear();
    dep.push_back("d");
    dep.push_back("c");    
    dependencies.push_back(dep);

    vector<Project*> result = findBuildOrder(projects, dependencies);

    for(Project *proj: result){
        cout<<proj->getName()<<", ";
    }
    cout<<endl;

}


int main(){
    testBuildOrder();
    return 0;
}

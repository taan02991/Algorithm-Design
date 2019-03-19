#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n , p, visited[5005], group[5005], Rank[5005] = {0}, Count[5005] = {0};
vector<vector<int>> g(5005), gT(5005);
stack<int> firstToLast, lastToFirst;

void dfsFTL(int s){
    if(visited[s]) return;
    visited[s] = 1;
    for(int adj: g[s]){
        if(visited[adj]) continue;
        dfsFTL(adj);
    }
    firstToLast.push(s);
}

void dfsLTF(int s){
    if(visited[s]) return;
    visited[s] = 1;
    for(int adj: gT[s]){
        if(visited[adj]) continue;
        dfsLTF(adj);
    }
    lastToFirst.push(s);
}

void dfsGroup(int s, int groupNumber){
    if(visited[s]) return;
    visited[s] = 1;
    group[s] = groupNumber;
    for(int adj: g[s]){
        if(visited[adj]) continue;
        dfsGroup(adj, groupNumber);
    }
}

void dfsLevel(int s, int p, int level){
    if(group[p] != group[s]) level++;
    if(visited[s] && level <= Rank[s]) return;
    visited[s] = 1;
    Rank[s] = max(Rank[s], level);
    for(int adj: g[s]){
        dfsLevel(adj, s, level);
    }
}

void SCC(){
    int groupNumber = -1;
    while(!lastToFirst.empty()){
        int u = lastToFirst.top(); lastToFirst.pop();
        if(visited[u]) continue;
        visited[u] = 1;
        groupNumber++;
        group[u] = groupNumber;
        for(int adj: g[u]){
            if(visited[adj]) continue;
            dfsGroup(adj, groupNumber);
        }
    }
}

int main()
{
    cin>>n>>p;
    for(int i = 0; i < p; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        gT[b].push_back(a);
    }
    for(int i = 0; i < n; i++) visited[i] = 0;
    for(int i = 0; i < n; i++) dfsFTL(i);
    for(int i = 0; i < n; i++) visited[i] = 0;
    for(int i = 0; i < n; i++) dfsLTF(i);
    for(int i = 0; i < n; i++) visited[i] = 0;
    SCC();
    for(int i = 0; i < n; i++) visited[i] = 0;
    for(int i = 0; i < n; i++) Rank[i] = -1;
    while(!firstToLast.empty()){
        int s = firstToLast.top(); firstToLast.pop();
        if(Rank[s] != -1) continue;
        dfsLevel(s, s, 0);
    }
    for(int i = 0; i < n; i++) Count[Rank[i]]++;
    int index = 0;
    while(Count[index] != 0) cout<<Count[index++]<<" ";
    return 0;
}

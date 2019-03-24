#include <iostream>
#include <vector>

using namespace std;

int t, n, e, visited[1005];
vector<vector<int>> g(1005);

bool dfs(int s, int p){
    visited[s] = 1;
    for(int adj: g[s]){
        if(adj == p) continue;
        if(visited[adj]){
            return false;
        }
        if(!dfs(adj, s)) return false;
    }
    return true;
}

void clearVisited(){
    for(int i = 0; i < n; i++) visited[i] = 0;
}

void clearG(){
    for(int i = 0; i < n; i++) g[i].clear();
}

int main()
{
    cin>>t;
    for(int k = 0; k < t; k++){
        cin>>n>>e;
        clearG();
        clearVisited();
        for(int i = 0; i < e; i++){
            int a, b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int check = 0;
        for(int s = 0; s < n; s++){
            if(visited[s]) continue;
            if(!dfs(s, -1)){
                cout<<"YES\n";
                check = 1;
                break;
            }
        }
        if(!check) cout<<"NO\n";
    }
    return 0;
}

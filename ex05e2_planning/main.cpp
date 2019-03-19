#include <iostream>
#include <vector>

using namespace std;

void dfs(int &s, vector<vector<int>> &e, vector<int> &visited){
    if(visited[s]) return;
    if(e[s].size() == 0){
        visited[s] = 1;
        cout<<s<<" ";
        return;
    }
    for(int i = 0; i < e[s].size(); i++){
        dfs(e[s][i], e, visited);
    }
    visited[s] = 1;
    cout<<s<<" ";
    return;
}

int main()
{
    int n, m;
    cin>>n;
    vector<vector<int>> e(n);
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        cin>>m;
        for(int j = 0; j < m; j++){
            int t;
            cin>>t;
            e[i].push_back(t);
        }
    }
    for(int i = 0; i < n; i++){
        dfs(i, e, visited);
    }
    return 0;
}

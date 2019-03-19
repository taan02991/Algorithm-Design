#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, k;
vector<vector<int>> g(1005);

int BFS(int s){
    int friends = 0;
    int visited[n] = {0};
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty()){
        pair<int ,int> t = q.front(); q.pop();
        if(t.second < k){
            for(auto adj: g[t.first]){
                if(!visited[adj]){
                    visited[adj] = 1;
                    q.push({adj, t.second+1});
                }
            }
        }
        if(t.second <= k) friends++;
    }
    return friends;
}

int main()
{
    cin>>n>>e>>k;
    for(int i = 0; i < e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int MAX = 0;
    for(int i = 0; i < n; i++){
        MAX = max(MAX, BFS(i));
    }
    cout<<MAX;
    return 0;
}

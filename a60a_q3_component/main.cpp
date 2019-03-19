#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> node(10005);
int used[10005] = {0};

void BFS(int s){
    used[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int temp = q.front(); q.pop();
        for(auto n: node[temp]){
            if(!used[n]){
                used[n] = 1;
                q.push(n);
            }
        }
    }
}

int main()
{
    int V, E, count = 0;
    cin>>V>>E;
    for(int i = 0; i < E; i++){
        int a, b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i = 1; i <= V; i++){
        if(!used[i]){
            count++;
            BFS(i);
        }
    }
    cout<<count;
}

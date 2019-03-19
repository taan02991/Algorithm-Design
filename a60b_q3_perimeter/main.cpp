#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, k, count = 0;
vector<vector<int>> g(1005);
queue<pair<int ,int>> q;
int used[1005] = {0};

void BFS(){
    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> t = q.front(); q.pop();
        used[t.first] = 1;
        if(t.second < k){
            for(auto i : g[t.first]){
                if(!used[i]){
                    used[i] = 1;
                    q.push({i, t.second + 1});
                }
            }
        }
        if(t.second == k) count++;
    }
}

int main()
{
    scanf("%d %d %d", &n, &e, &k);
    for(int i = 0; i < e; i++){
        int a, b;
        scanf("%d %d", &a , &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS();
    cout<<count;
    return 0;
}

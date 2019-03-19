#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> g(1005);
vector<vector<int>> gT(1005);
int used[1005] = {0};
stack<int> lastOut;

void dfsB(int s){
    used[s] = 1;
    for(int i = 0; i < gT[s].size(); i++){
        if(used[gT[s][i]]) continue;
        dfsB(gT[s][i]);
    }
    lastOut.push(s);
}

int dfsF(int s){
    used[s] = 1;
    int count = 1;
    for(int i = 0; i < g[s].size(); i++){
        if(used[g[s][i]]) continue;
        count += dfsF(g[s][i]);
    }
    return count;
}

int main()
{
    int n,m,t;
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &t);
            g[i].push_back(t);
            gT[t].push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(!used[i]) dfsB(i);
    }
    for(int i = 0; i < n; i++) used[i] = 0;
    vector<int> ans;
    while(!lastOut.empty()){
        int i = lastOut.top(); lastOut.pop();
        if(!used[i]){
            ans.push_back(dfsF(i));
        }
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans) cout<<i<<" ";

    return 0;
}

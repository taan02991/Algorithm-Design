#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, temp, MAX = 0;

void Prim(vector<int> &d, vector<vector<int>> &g, vector<int> fa, vector<int> c){
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int used[g.size()] = {0};
    for(auto firstAtack: fa) d[firstAtack] = c[firstAtack];
    for(int i = 0; i < n; i++) pq.push({d[i], i});
    while(!pq.empty()){
        pair<int, int> t = pq.top(); pq.pop();
        if(used[t.second]) continue;
        used[t.second] = 1;
        d[t.second] = t.first;
        for(auto adj: g[t.second]){
            if(d[t.second] + c[adj] < d[adj]){
                pq.push({d[t.second] + c[adj], adj});
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    vector<int> d(n, 2000000000);
    vector<vector<int>> g(n);
    vector<int> fa, c;
    for(int i = 0; i < k; i++){
        scanf("%d", &temp);
        fa.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        c.push_back(temp);
    }
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    Prim(d, g, fa, c);
    for(int i = 0; i < n; i++) MAX = max(MAX, d[i]);
    cout<<MAX;
    return 0;
}

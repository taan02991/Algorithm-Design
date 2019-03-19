#include <iostream>
#include <vector>

using namespace std;

int n;
long long ans[100005];
vector<vector<int>> g(100005);

long long C2(long long n){
    return n*(n-1)/2;
}

int dfs(int s, int p){
    int child = 1;
    ans[s] = C2(n);
    for(int adj: g[s]){
        if(adj == p) continue;
        int temp = dfs(adj, s);
        ans[s] -= C2(temp);
        child += temp;
    }
    ans[s] -= C2(n-child);
    return child;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}

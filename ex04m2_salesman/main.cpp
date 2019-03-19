#include <iostream>

using namespace std;

int n, m, order[1005] = {0}, qs[1005] = {0}, total = 0, w1, w2;

int shorter(int u, int v){
    if(v > u) return min(qs[v] - qs[u], total - (qs[v] - qs[u]));
    return min(qs[u] - qs[v], total - (qs[u] - qs[v]));
}

int shortest(int u, int v){
    int t1 = shorter(u, v);
    int t2 = shorter(u, w1) + shorter(w2, v);
    int t3 = shorter(u, w2) + shorter(w1, v);
    return min(t1, min(t2, t3));
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < m; i++) cin>>order[i];
    order[m] = order[0];
    for(int i = 1; i <= m; i++){
        int t;
        cin>>t;
        total += t;
        qs[i] = qs[i-1] + t;
    }
    for(int i = 0; i < n; i++){
        int ans = 0;
        cin>>w1>>w2;
        for(int i = 1; i <= m; i++){
            ans += shortest(order[i-1], order[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

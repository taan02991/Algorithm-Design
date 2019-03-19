#include <iostream>
#include <vector>
#define ull unsigned long long

using namespace std;

int maxIndex(vector<ull> &d, vector<int> &inMST){
    int MAX = 0;
    for(int i = 1; i < d.size(); i++){
        if(!inMST[i] && d[MAX] < d[i]) MAX = i;
    }
    return MAX==0?1:MAX;
}

void Prim(int &n, vector<int> &g, vector<ull> &d, vector<int> &inMST){
    for(int i = 1; i <= n; i++){
        int u = maxIndex(d, inMST);
        inMST[u] = 1;
        for(int v = 1; v <= n; v++){
            if(!inMST[v] && (g[u]^g[v]) > d[v]) d[v] = g[u]^g[v];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> g(n+1), inMST(n+1);
    vector<ull> d(n+1);
    for(int i = 1; i <= n; i++){
        cin>>g[i];
    }
    Prim(n, g, d, inMST);
    ull ans = 0;
    for(auto i: d) ans += i;
    cout<<ans;
    return 0;
}

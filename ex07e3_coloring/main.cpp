#include <iostream>
#include <vector>

using namespace std;

int n, e;
vector<vector<int>> g(55);

bool color(int s, int k, vector<int> result){
    if(s == n) return true;
    int unavailable[k] = {0};
    for(int adj: g[s]){
        if(result[adj] != -1){
            unavailable[result[adj]] = 1;
        }
    }
    for(int cr = 0; cr < k; cr++){
        if(!unavailable[cr]){
            result[s] = cr;
            if(color(s+1, k, result)) return true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> result(n, -1);
    for(int k = 1; k <= n; k++){
        if(color(0, k, result)){
            cout<<k;
            break;
        }
    }
    return 0;
}

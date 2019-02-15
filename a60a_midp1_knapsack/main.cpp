#include <iostream>
#include <vector>

using namespace std;

int v[501] = {}, w[501] = {}, arr[501][501] = {};

void path(int a, int b, vector<int> &v){
    if(a < 1 || b < 1) return;
    if(arr[a-1][b] != arr[a][b]){
        v.push_back(a);
        path(a-1, b - w[a], v);
    }
    else path(a-1, b, v);
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>v[i];
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cin>>arr[i][j];
        }
    }
    vector<int> ans;
    path(n, m, ans);
    cout<<ans.size()<<endl;
    for(int i: ans) cout<<i<<" ";
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<vector<int>> v, vector<int> d, int s, int p, int k){
    d[s] = k;
    for(int i: v[s]){
        if(i == p) continue;
        if(d[i] < 2000000000) return d[i]-d[s]+1;
        d[i] = k+1;
        int t = DFS(v, d, i, s, k+1);
        if(t < 2000000000) return t;
    }
    return 2000000000;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int N, E;
        cin>>N>>E;
        vector<vector<int>> v(N);
        vector<int> d(N, 2000000000);
        for(int i = 0; i < E; i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int check = 0;
        for(int i = 0; i < N; i++){
            int t = DFS(v, d, i, i, 0);
            if(t < 2000000000){
                cout<<"YES\n";
                check = 1;
                break;
            }
        }
        if(!check) cout<<"NO\n";
    }
    return 0;
}

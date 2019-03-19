#include <iostream>
#include <vector>

using namespace std;

int n, e, s, w[105][105], d[105];
vector<pair<int, int>> edge;

int main()
{
    cin>>n>>e>>s;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge.push_back({a,b});
        w[a][b] = c;
    }
    for(int i = 0; i < n; i++) d[i] = 2000000000;
    d[s] = 0;
    for(int u = 1; u < n; u++){
        for(auto p: edge){
            if(d[p.first] + w[p.first][p.second] < d[p.second]){
                d[p.second] = d[p.first] + w[p.first][p.second];
            }
        }
    }
    int check = 0;
    for(auto p: edge){
        if(d[p.first] + w[p.first][p.second] < d[p.second]){
            cout<<"-1";
            check = 1;
            break;
        }
    }
    if(!check){
        for(int i = 0; i < n; i++) cout<<d[i]<<" ";
    }
    return 0;
}

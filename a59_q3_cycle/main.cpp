#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> node(100005);
int d[100005];

int DFS(int s, int p, int k){
    d[s] = k;
    for(int i: node[s]){
        if(i == p) continue;
        if(d[i] < 2000000000) return d[s]-d[i]+1;
        d[i] = d[s] + 1;
        int temp = DFS(i, s, k+1);
        if(temp < 2000000000) return temp;
    }
    return 2000000000;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i = 0; i < n; i++) d[i] = 2000000000;
    for(int i = 0; i < n; i++){
        int t = DFS(i, i, 0);
        if(t < 2000000000){
            cout<<t;
            break;
        }
    }
}

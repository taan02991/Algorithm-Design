#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r,c, X[] = {-1, 0, 1, 0}, Y[] = {0, -1, 0, 1};

class node{
public:
    int x, y, d;
    node(int x, int y, int d): x(x), y(y), d(d){}
    bool operator<(const node &n)const{
        return d > n.d;
    }
    void print(){
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
};

void Prim(vector<vector<int>> &g, vector<vector<int>> &inMST, priority_queue<node> &d, vector<vector<int>> &ans){
    while(!d.empty()){
        node u = d.top(); d.pop();
        while(inMST[u.x][u.y] && !d.empty()){
            node u = d.top(); d.pop();
        }
        if(ans[u.x][u.y] > u.d)ans[u.x][u.y] = u.d;
        inMST[u.x][u.y] = 1;
        for(int k = 0; k < 4; k++){
            int x = u.x + X[k], y = u.y + Y[k];
            if(x < 0 || x >= r || y < 0 || y >= c) continue;
            if(!inMST[x][y] && ans[u.x][u.y] + g[x][y] < ans[x][y]){
                ans[x][y] = ans[u.x][u.y] + g[x][y];
                d.push({x, y, ans[x][y]});
            }
        }
    }
}

int main(){
    cin>>r>>c;
    vector<vector<int>> g(r), inMST(r), ans(r);
    priority_queue<node> d;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int t;
            scanf("%d", &t);
            g[i].push_back(t);
            inMST[i].push_back(0);
            ans[i].push_back(2000000000);
            if(i == 0 && j == 0) d.push({i, j, 0});
            else d.push({i, j, 2000000000});
        }
    }
    Prim(g, inMST, d, ans);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

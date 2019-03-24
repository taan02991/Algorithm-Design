#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int r,c, X[] = {1, -1, 0 , 0}, Y[] = {0, 0, 1, -1};
    cin>>r>>c;
    vector<vector<int>> w(r);
    int d[r][c], visited[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int t;
            cin>>t;
            w[i].push_back(t);
            d[i][j] = 2000000000;
        }
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        int x = pq.top().second.first, y = pq.top().second.second, dis = -pq.top().first;
        pq.pop();
        if(d[x][y] < 2000000000) continue;
        d[x][y] = dis;
        for(int i = 0; i < 4; i++){
            int x2 = x + X[i], y2 = y + Y[i];
            if(x2 < 0 || x2 >= r || y2 < 0 || y2 >= c) continue;
            if(d[x2][y2] < 2000000000) continue;
            pq.push({-(dis + w[x2][y2]), {x2, y2}});
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}

#include <iostream>
#include <queue>

using namespace std;

int r,c;
int d[105][105], X[] = {0,1,0,-1}, Y[] = {-1,0,1,0};
char Map[105][105];

void BFS(){
    queue<pair<int, int>> q;
    d[0][0] = 0;
    q.push({0,0});
    while(!q.empty()){
        pair<int, int> t = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int x = t.first + X[i], y = t.second + Y[i];
            if(x < 0 || x >= r || y < 0 || y >= c) continue;
            if(d[x][y] < 2000000000 || Map[x][y] == '#') continue;
            d[x][y] = d[t.first][t.second] + 1;
            q.push({x, y});
        }
    }
}

int main()
{
    cin>>r>>c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %c", &Map[i][j]);
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            d[i][j] = 2000000000;
        }
    }
    BFS();
    cout<<(d[r-1][c-1]<2000000000?d[r-1][c-1]:-1)<<endl;
    return 0;
}

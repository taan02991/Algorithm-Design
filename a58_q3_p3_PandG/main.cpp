#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, n, T, r, c, board[105][105], X[] = {-1, 0, 1, 0}, Y[] = {0, -1, 0, 1};

void BFS(vector<vector<int>> &Time, vector<pair<int, pair<int, int>>> start){
    for(int i = 0; i < start.size(); i++){
        queue<pair<int, pair<int, int>>> q;
        int visited[R][C];
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++) visited[i][j] = 0;
        }
        int t = start[i].first, x = start[i].second.first, y = start[i].second.second;
        q.push({t, {x, y}});
        visited[x][y] = 1;
        while(!q.empty()){
            int t2 = q.front().first , x2 = q.front().second.first, y2 = q.front().second.second;
            q.pop();
            Time[x2][y2] = min(Time[x2][y2], t2);
            for(int k = 0; k < 5; k++){
                int t3 = t2 + 1, x3 = x2 + X[k], y3 = y2 + Y[k];
                if(x3 < 0 || x3 >= R || y3 < 0 || y3 >= C) continue;
                if(Time[x3][y3] <= t3 || board[x3][y3] == '#' || visited[x3][y3] == 1) continue;
                visited[x3][y3] = 1;
                q.push({t3, {x3, y3}});
            }
        }
    }
}

void Prim(vector<vector<int>> &Time){
    priority_queue<pair<int, pair<int, int>>> pq;
    int visited[R][C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) visited[i][j] = 0;
    }
    pq.push({0, {r, c}});
    while(!pq.empty()){
        int t = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        if(visited[x][y]) continue;
        visited[x][y] = 1;
        Time[x][y] = t;
        for(int k = 0; k < 4; k++){
            int t2 = t+1, x2 = x + X[k], y2 = y + Y[k];
            if(x2 < 0 || x2 >= R || y2 < 0 || y2 >= C) continue;
            if(visited[x2][y2] == 1 || board[x2][y2] == '#') continue;
            pq.push({-t2, {x2, y2}});
        }
    }
}

int main()
{
    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        cin>>R>>C>>n>>T>>r>>c;
        vector<vector<int>> gTime(R), pTime(R);
        vector<pair<int, pair<int, int>>> ghost(n);
        for(int i = 0; i < n; i++){
            int t, x, y;
            scanf("%d %d %d", &t, &x, &y);
            ghost[i] = make_pair(t, make_pair(x, y));
        }
        sort(ghost.begin(), ghost.end());
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                scanf(" %c", &board[i][j]);
                gTime[i].push_back(2000000000);
                pTime[i].push_back(2000000000);
            }
        }
        BFS(gTime, ghost);
        Prim(pTime);
        bool check = false;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(gTime[i][j] > T){
                    if(pTime[i][j] < gTime[i][j]) check = true;
                }
            }
        }
        if(check) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

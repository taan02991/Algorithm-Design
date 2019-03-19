#include <iostream>
#include <queue>

using namespace std;

int w[1005][1005] = {0}, inMST[1005][1005] = {0}, dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

int main()
{
    int n, a, b;
    cin>>n>>a>>b;
    for(int i = 0; i < n; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        w[t1][t2] = 1;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {a, b}});
    while(!pq.empty()){
        int x = pq.top().second.first, y = pq.top().second.second, d = -pq.top().first;
        pq.pop();
        if(inMST[x][y]) continue;
        inMST[x][y] = 1;
        if(x == 1 || x == 1000 || y == 1 || y == 1000){
            cout<<d;
            break;
        }
        for(int i = 0; i < 4; i++){
            int tempX = x + dx[i], tempY = y + dy[i], tempD = d + w[tempX][tempY];
            if(inMST[tempX][tempY]) continue;
            pq.push({-tempD, {tempX, tempY}});
        }
    }
    return 0;
}

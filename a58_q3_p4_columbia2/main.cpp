#include <iostream>
#include <queue>

using namespace std;

class node{
public:
    int x, y, d, q;
    node(int x, int y, int d, int q): x(x), y(y), d(d), q(q){}
    bool operator<(const node other)const{
        return d > other.d;
    }
};

int main() {
    int R, C;
    cin>>R>>C;
    int g[R][C], d[R][C][3], X[] = {1, -1, 0, 0, -1, 1, 1, -1, 2, -2, 0, 0}, Y[] = {0, 0, 1, -1, -1, -1, 1, 1, 0 ,0 , 2, -2};
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>g[i][j];
            for(int k = 0; k < 3; k++){
                d[i][j][k] = -1;
            }
        }
    }
    priority_queue<node> pq;
    pq.push(node(0 ,0 ,0, 2));
    while(!pq.empty()){
        node t = pq.top(); pq.pop();
        if(d[t.x][t.y][t.q] != -1) continue;
        d[t.x][t.y][t.q] = t.d;
        for(int i = 0; i < 4; i++){
            int x = t.x + X[i], y = t.y + Y[i];
            if(x < 0 || x >= R || y < 0 || y >= C) continue;
            if(d[x][y][t.q] != -1) continue;
            pq.push(node(x, y, t.d + g[x][y], t.q));
        }
        if(t.q > 0){
            for(int i = 0; i < 12; i++){
                int x = t.x + X[i], y = t.y + Y[i], q = t.q-1;
                if(x < 0 || x >= R || y < 0 || y >= C) continue;
                if(d[x][y][t.q] != -1) continue;
                pq.push(node(x, y, t.d, q));
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<min(d[i][j][2], min(d[i][j][1], d[i][j][0]))<<" ";
        }
        cout<<endl;
    }
}

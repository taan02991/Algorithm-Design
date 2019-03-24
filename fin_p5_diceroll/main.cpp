#include <iostream>
#include <vector>

using namespace std;

int R, C, p, q, c[6], X[] = {-1, 1, 0, 0}, Y[] = {0, 0, -1, 1}, state[15][15], d[15][15];

pair<int, int> getW(int state, int moveX, int moveY){
    vector<int> seq(4);
    if(state == -1) return {2000000000, -1};
    if(state == 0){
        seq = {4, 5, 3, 2};
    }
    else if(state == 1){
        seq = {2, 3, 5, 4};
    }
    else if(state == 2){
        seq = {4, 5, 0, 1};
    }
    else if(state == 3){
        seq = {5, 4, 0, 1};
    }
    else if(state == 4){
        seq = {3, 2, 0, 1};
    }
    else if(state == 5){
        seq = {2, 3, 0, 1};
    }
    for(int i = 0; i < 4; i++){
        //return (w, nextState)
        if(X[i] == moveX && Y[i] == moveY) return {c[seq[i]], seq[i]};
    }
}

int main()
{
    cin>>R>>C>>p>>q;
    for(int i = 0; i < 6; i++) cin>>c[i];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            d[i][j] = 2000000000;
            state[i][j] = -1;
        }
    }
    d[0][0] = 0;
    state[0][0] = 0;
    for(int k = 0; k < R*C; k++){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                for(int k2 = 0; k2 < 4; k2++){
                    int x = i + X[k2], y = j + Y[k2];
                    if(x < 0 || x >= R || y < 0 || y >= C) continue;
                    cout<<i<<" "<<j<<endl;
                    cout<<x<<" "<<y<<endl;
                    cout<<state[i][j]<<" "<<X[k2]<<" "<<Y[k2]<<endl;
                    pair<int, int> t = getW(state[i][j], X[k2], Y[k2]);
                    cout<<t.first<<" "<<t.second<<endl;
                    cout<<"****************"<<endl;
                    if(t.first == -1) continue;
                    if(d[x][y] > d[i][j] + t.first){
                        d[x][y] = d[i][j] + t.first;
                        state[x][y] = t.second;
                    }
                }
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<d[p][q]<<endl;
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int n, k, p, g[30][5], used[30] = {0}, X[] = {-1, 1, -1, 0, 1}, Y[] = {0, 0, 1, 1, 1}, visited[30][31];

class node{
public:
    int rNumber, floor, sumD;
    node(int rNumber, int floor, int sumD): rNumber(rNumber), floor(floor), sumD(sumD){}
    bool operator<(const node other)const{
//        if(rNumber == 0 && floor == 0) return true;
//        double r1 = (double)sumD/floor;
//        double r2 = (double)other.sumD/other.floor;
        return  sumD > other.sumD;
    }
};
node dp[30][31];

double dfs(node s, node p){
    double MIN; node start, node last;
    visited[s.rNumber][s.floor] = 1;
    for(int i = 0; i < 5; i++){
        int x = s.rNumber + X[i], y = s.floor + Y[i];
        if(visited[x][y] == 1){
            start = dp[x][y];
            last = dp[s.rNumber][s.floor];

        }
        dfs({x, y, s.sumD + g[i]});
    }
}


int main(){
    cin>>n>>k>>p;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 5; j++){
            cin>>g[i][j];
        }
    }
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 31; j++) visited[i][j] = 0;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k+1; j++) cout<<visited[i][j]<<" ";
        cout<<endl;
    }
}

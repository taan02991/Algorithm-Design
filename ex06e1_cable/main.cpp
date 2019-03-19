#include <iostream>

using namespace std;

int n, G[1005][1005], d[1005], inMST[1005], minCost = 0;

int minIndex(){
    int MIN = 1;
    for(int i = 2; i <= n; i++){
        if(d[i] < d[MIN]) MIN = i;
    }
    return MIN;
}

void Prim(){
    for(int i = 1; i <= n; i++){
        d[i] = 2000000000;
        inMST[i] = 0;
    }
    d[1] = 0;
    for(int i = 1; i <= n; i++){
        int u = minIndex();
        minCost += d[u];
        d[u] = 2000000000;
        inMST[u] = 1;
        for(int j = 1; j <= n; j++){
            if(!inMST[j] && G[u][j] < d[j]){
                d[j] = G[u][j];
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            scanf("%d", &G[i][j]);
            G[j][i] = G[i][j];
        }
    }
    Prim();
    cout<<minCost;
    return 0;
}

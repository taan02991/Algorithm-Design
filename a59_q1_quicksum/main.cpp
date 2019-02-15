#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int A[n][m], P[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>A[i][j];
        }
    }
    P[0][0] = A[0][0];
    for(int j = 1; j < m; j++){
        P[0][j] = P[0][j-1] + A[0][j];
    }
    for(int i = 1; i < n; i++){
        P[i][0] = P[i-1][0] + A[i][0];
        for(int j = 1; j < m; j++){
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + A[i][j];
        }
    }
    int r1, c1, r2, c2;
    for(int i = 0; i < k; i++){
        cin>>r1>>c1>>r2>>c2;
        int a = 0,b = 0,c = 0,d = 0;
        a = P[r2][c2];
        if(r1-1 >= 0) b = P[r1-1][c2];
        if(c1-1 >= 0) c = P[r2][c1-1];
        if(r1-1 >= 0 && c1-1 >= 0) d = P[r1-1][c1-1];
        cout<< a - b - c + d<<"\n";
    }
    return 0;
}

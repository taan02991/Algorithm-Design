#include <iostream>

using namespace std;


int main()
{
    int n, m, r;
    cin>>n>>m>>r;
    int arr[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int r1,c1,r2,c2;
    for(int k = 0; k < r; k++){
        cin>>r1>>c1>>r2>>c2;
        if(r1 > r2 || c1 > c2) cout<<"INVALID\n";
        else if(r1 > n || c1 > m) cout<<"OUTSIDE\n";
        else{
            r1 = max(r1, 1);
            c1 = max(c1, 1);
            int MAX = arr[r1][c1];
            for(int i = r1; i <= r2 && i <= n; i++){
                for(int j = c1; j <= c2 && j <= m; j++){
                    MAX = max(MAX, arr[i][j]);
                }
            }
            cout<<MAX<<endl;
        }
    }
    return 0;
}

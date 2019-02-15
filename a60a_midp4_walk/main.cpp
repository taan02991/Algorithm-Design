#include <iostream>

using namespace std;

int n, m;
int arr[501][501] = {};
int mem[501][501] = {};

int step(int i, int j){
    if(i == n && j == m) return 0;
    if(mem[i][j] != 0) return mem[i][j];
    int s1 = 0, s2 = 0, s3 = 0;
    if(i < n) s1 = arr[i+1][j] + step(i + 1, j);
    if(j < m) s2 = arr[i][j+1] + step(i, j + 1);
    if(i < n && j < m) s3 = 2*arr[i + 1][j + 1] + step(i + 1, j + 1);
    return mem[i][j] = max(max(s1, s2), s3);
}

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>arr[i][j];
        }
    }
    cout<<arr[1][1] + step(1, 1);

    return 0;
}

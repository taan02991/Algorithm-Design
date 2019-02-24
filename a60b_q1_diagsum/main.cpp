#include <iostream>

using namespace std;

int n, arr[1000][1000], mem[1001][1001] = {}, sum[1001][1001] = {};

int S(int i, int j){
    if(i == 1) return arr[0][j-1];
    if(j == 1) return arr[i-1][0];
    if(sum[i][j] != 0) return sum[i][j];
    return sum[i][j] = max(S(i-1, j-1) + arr[i-1][j-1], arr[i-1][j-1]);
}

int DS(int i, int j){
    if(i == 1) return arr[0][j-1];
    if(j == 1) return arr[i-1][0];
    if(mem[i][j] != 0) return mem[i][j];
    return mem[i][j] = max(max(DS(i-1, j), DS(i, j-1)), max(S(i, j), DS(i-1, j-1)));
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<DS(n, n)<<endl;
}

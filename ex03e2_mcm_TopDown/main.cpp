#include <iostream>

using namespace std;

int mem[101][101] = {};

int MCM(int M[], int i, int j){
    if(i == j) return 0;
    if(mem[i][j] != 0) return mem[i][j];
    mem[i][j] = 2000000000;
    for(int k = i; k < j; k++){
        mem[i][j] = min(mem[i][j], MCM(M, i, k) + MCM(M, k+1, j) + M[i-1] * M[k] * M[j]);
    }
    return mem[i][j];
}

int main()
{
    int n;
    cin>>n;
    int M[n+1];
    for(int i = 0; i < n+1; i++) cin>>M[i];
    cout<<MCM(M, 1, n);
    return 0;
}

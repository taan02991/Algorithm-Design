#include <iostream>

using namespace std;

int n, M[105], mem[105][105] = {};

int MCM(int i, int j){
    if(j-i < 2) return 0;
    if(mem[i][j] != 0) return mem[i][j];
    int MIN = 200000000;
    for(int k = i+1; k < j; k++){
        MIN = min(MIN, MCM(i, k) + MCM(k, j) + M[i] * M[k] * M[j]);
    }
    return mem[i][j] = MIN;
}

int main(){
    cin>>n;
    for(int i = 0; i < n + 1; i++) scanf("%d", &M[i]);
    cout<<MCM(0, n)<<endl;
}

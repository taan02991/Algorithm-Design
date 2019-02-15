#include <iostream>

using namespace std;

int mem[501][501] = {};

int solve(int n, int k){
    if(mem[n][k] != 0) return mem[n][k];
    if(k > n) return 0;
    if(n == k || k == 1) return 1;
    return mem[n][k] = ((solve(n-1, k)*k) + solve(n-1, k-1))%1997;
}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<solve(n, k);
    return 0;
}

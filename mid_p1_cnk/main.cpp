#include <iostream>

using namespace std;

int mem[31][31] = {};

int C(int n, int k){
    if(n == k || k == 0) return 1;
    if(mem[n][k] != 0) return mem[n][k];
    return mem[n][k] = C(n-1, k-1) + C(n-1, k);
}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<C(n, k);
    return 0;
}

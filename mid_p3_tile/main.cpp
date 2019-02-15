#include <iostream>
#include <math.h>

using namespace std;

int n, m;
int arr[101] = {};
int mem[11][100001] = {};

int minPrice(int i, int remainArea){
    if(i > n || remainArea < 0) return 999999999;
    if(i == n && remainArea == 0) return 0;
    if(mem[i][remainArea] != 0) return mem[i][remainArea];
    mem[i][remainArea] = 2000000000;
    for(int b = 1; b <= sqrt(m); b++){
        int exchange = (arr[i] - b)*(arr[i] - b);
        int area = b*b;
        mem[i][remainArea] = min(mem[i][remainArea], exchange + minPrice(i+1, remainArea - area));
    }
    return mem[i][remainArea];
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>arr[i];
    int ans = minPrice(0, m);
    cout<< (ans>=999999999?-1:ans);
    return 0;
}

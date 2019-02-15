#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001] = {};
int mem[1001][1001] = {};

int solve(int prev, int now){
    if(now == n + 1) return 0;
    int k1 = 0, k2 = 0;
    if(arr[prev] <= arr[now]) k1 = 1 + (mem[now][now+1]==0?solve(now, now + 1):mem[now][now+1]);
    k2 = (mem[prev][now+1]==0?solve(prev, now + 1):mem[prev][now+1]);
    return mem[prev][now] = max(k1, k2);
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i + 1];
    }
    cout<< solve(0, 1);
}

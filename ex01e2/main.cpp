#include <iostream>

using namespace std;

int mem[10005] = {};
int MAX = -2000000000;

int S(int i, int arr[]){
    if(i == 0) return arr[0];
    int si = max(S(i-1, arr) + arr[i], arr[i]);
    MAX = max(MAX, si);
    return si;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    S(n-1, arr);
    cout<<MAX;
    return 0;
}

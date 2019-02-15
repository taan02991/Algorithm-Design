#include <iostream>

using namespace std;

int n, w, MAX = -2000000000;

void solve(int arr[],int index){
    int maxnow = 0;
    for(int i = 0; i < w; i++){
        if(index + i >= n) break;
        maxnow += arr[index + i];
        if(maxnow > MAX) MAX = maxnow;
        if(maxnow < 0) break;
    }
    if(index + 1 < n) solve(arr, index + 1);
}

int main()
{
    cin>>n>>w;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    solve(arr, 0);
    cout<<MAX;
}

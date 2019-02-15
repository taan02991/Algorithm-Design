#include <iostream>
#include <algorithm>

using namespace std;

void mergeCount(int arr[],int l, int r, int &k){
    if(k <= 0 || l >= r - 1) return;
    int mid = (r + l)/2;
    int temp = arr[mid];
    arr[mid] = arr[mid-1];
    arr[mid-1] = temp;
    k -= 2;
    if(k <= 0) return;
    mergeCount(arr, l, mid, k);
    mergeCount(arr, mid, r, k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = i+1;
    k--;
    mergeCount(arr, 0, n, k);
    if(k == 0){
        for(auto i: arr) cout<<i<<" ";
    }
    else{
        cout<<"-1";
    }
}

#include <iostream>

using namespace std;

int n, k;
int p[10000];
int arr[10000];

int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>p[i];
    for(int i = 0; i <= k; i++) arr[i] = p[i];
    for(int i = k + 1; i < n; i++){
        int minP = 2000000000;
        for(int j = 0; j <= 2*k; j++){
            if(i-j-1 >= 0) minP = min(minP, arr[i-j-1]);
        }
        arr[i] = minP + p[i];
    }
    int minP = 2000000000;
    for(int i = n-1; i >= n-1-k && i >= 0; i--){
        minP = min(minP, arr[i]);
    }
    cout<<minP<<endl;
    return 0;
}

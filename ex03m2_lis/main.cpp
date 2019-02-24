#include <iostream>

using namespace std;

int main()
{
    int n, arr[1000], lis[1000];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    lis[0] = 1;
    int MAX = 1;
    for(int i = 1; i < n; i++){
        lis[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        if(lis[i] > MAX) MAX = lis[i];
    }
    cout<<MAX<<endl;
    return 0;
}

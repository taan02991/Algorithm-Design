#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int f, w, n;
    cin>>f>>w>>n;
    int arr[f];
    for(int i = 0; i < f; i++) scanf("%d", &arr[i]);
    sort(arr, arr+f);
    int i = 0, j = 0, c = 1;
    while(j < f){
        if(arr[j] - arr[i] <= 2*w) j++;
        else{
            c++;
            i = j;
        }
    }
    cout<<c<<endl;
    return 0;
}

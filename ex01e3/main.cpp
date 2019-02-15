#include <iostream>

using namespace std;

int bsearch(int arr[], int q, int first, int last){
    if(first > last) return -1;
    int mid = (first + last)/2;
    if(arr[mid] <= q && arr[mid+1] > q) return arr[mid];
    if(arr[mid] > q) bsearch(arr, q, first, mid-1);
    else bsearch(arr, q, mid+1, last);
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    arr[n] = 2147483647;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < m; i++){
        int q;
        scanf("%d", &q);
        printf("%d\n", bsearch(arr, q, 0, n-1));
    }
    return 0;
}

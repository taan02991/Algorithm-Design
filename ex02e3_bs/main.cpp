#include <iostream>

using namespace std;

int bsearch(int arr[], const int &q, int first, int last){
    if(first>last) return -1;
    int mid = (first + last)/2;
    if(q >= arr[mid] && q < arr[mid + 1]) return mid;
    if(q >= arr[mid]) bsearch(arr, q, mid + 1, last);
    else bsearch(arr, q, first, mid - 1);
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
}

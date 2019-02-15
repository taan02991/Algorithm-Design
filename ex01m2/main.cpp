#include <iostream>

using namespace std;

int count = 0;

void merge(int arr[], int l, int mid, int r){
    int temp[r-l], k = 0, i = l, j = mid;
    while(i < mid && j < r){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }
    while(i < mid) temp[k++] = arr[i++];
    while(j < r) temp[k++] = arr[j++];
    for(int i = 0; i < k; i++){
        arr[l + i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l >= r - 1) return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid, r);
    merge(arr, l, mid, r);

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n);
    cout<<count;
    return 0;
}

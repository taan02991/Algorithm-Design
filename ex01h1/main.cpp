#include <iostream>

using namespace std;

int arr[1000000] = {0,1,3};
int last = 2;

int getValue(int k, int start, int end){
    if(start <= end){
        int mid = (start + end)/2;
        if(arr[mid-1] < k && k <= arr[mid]) return mid;
        if(k < arr[mid]) return getValue(k, 1, mid-1);
        return getValue(k, mid+1, end);
    }
    cout<<"Not found"<<endl;
    return -1;
}

void fillUpTo(int k){
    while(k > arr[last]){
        last++;
        arr[last] = arr[last-1] + getValue(last, 1, last - 1);
    }
}

int main()
{
    int n,k;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>k;
        fillUpTo(k);
        cout<<getValue(k, 1, last)<<endl;
    }
}

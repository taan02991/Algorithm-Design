#include <iostream>

using namespace std;

int arr[100000] = {};

void getC(int n, int index){
    if(index < 0 || n <= 0) return;
    if(n <= arr[index-1]) getC(n, index-1);
    else if(n > arr[index-1] + 1 + index + 2) getC(n - (arr[index-1] + 1 + index + 2), index-1);
    else{
        if(n - arr[index-1] == 1) cout<<'g';
        else cout<<'a';
    }

}

int main()
{
    int n;
    cin>>n;
    int index = 0;
    arr[0] = 3;
    while(arr[index] < n){
        arr[index+1] = 2*arr[index] + (1 + index + 1 + 2);
        index++;
    }
    getC(n, index);
    return 0;
}

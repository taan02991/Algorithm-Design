#include <iostream>

using namespace std;

int arr[1000][1000];

int Celebrity(int left, int right){
    if(left == right) return left;
    if(arr[left][right] == 1) return Celebrity(left+1, right);
    else return Celebrity(left, right-1);
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    int c = Celebrity(0, n-1);
    for(int i = 0; i < n; i++){
        if(arr[c][i] != 0) c = -1;
        if(i != c && arr[i][c] != 1) c = -1;
        if(c == -1) break;
    }
    cout<<c+1;
    return 0;
}

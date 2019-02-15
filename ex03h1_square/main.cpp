#include <iostream>

using namespace std;

int r, c;
string arr[1010] = {};

int findMaxSize(int i, int j){
    if(i >= r || j >= c) return 0;
    if(arr[i][j] == 0) return 0;
    int currentSize = 0;
    bool check = true;
    while(check){
        for(int s = 0; s <= currentSize; s++){
            if(arr[i+s][j+currentSize] != '1'){
                check = false;
                break;
            }
            if(arr[i+currentSize][j+s] != '1'){
                check = false;
                break;
            }
        }
        if(check) currentSize++;
    }
    return currentSize;
}

int main()
{
    cin>>r>>c;
    for(int i = 0; i < r; i++){
        cin>>arr[i];
    }
    int MAX = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            MAX = max(MAX, findMaxSize(i, j));
        }
    }
    cout<<MAX;
    return 0;
}

#include <iostream>

using namespace std;

int n, celeb = 0,arr[1005][1005] = {};

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        int r = 0, c = 0;
        for(int j = 1; j <= n; j++){
            r += arr[i][j];
            c += arr[j][i];
        }
        if(r == 0 && c == n-1){
            celeb = i;
            break;
        }
    }
    cout<<celeb;
    return 0;
}

#include <iostream>

using namespace std;

int arr[1001][1001];
int M[1001][1001] = {};
int r, c, MAX = 0;

int main()
{
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++){
        string s;
        cin>>s;
        for(int j = 1; j <= c; j++){
            arr[i][j] = s[j-1] - '0';
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(arr[i][j] == 0) M[i][j] = 0;
            else{
                M[i][j] = 1 + min( min(M[i-1][j], M[i][j-1]) , M[i-1][j-1]);
                if(M[i][j] > MAX) MAX = M[i][j];
            }
        }
    }
    cout<<MAX;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int S[n+1], M[n+1][n+1] = {};
    for(int i = 0; i < n + 1; i++) cin>>S[i];
    for(int j = 2; j < n+1; j++){
        for(int i = j-1; i >= 1; i--){
            M[i][j] = 2000000000;
            for(int k = i; k < j; k++){
                M[i][j] = min(M[i][j], M[i][k] + M[k+1][j] + S[i-1] * S[k] * S[j]);
            }
        }
    }
    cout<<M[1][n];

}

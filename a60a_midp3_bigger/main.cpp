#include <iostream>

using namespace std;

int n, c[10005], dp[10005] = {0};

int main()
{
    cin>>n;
    for(int i = 3; i <= n+2; i++){
        cin>>c[i];
    }
    for(int i = 3; i <= n+2; i++){
        dp[i] = max(dp[i-1], dp[i-3] + c[i]);
    }
    cout<<dp[n+2];
    return 0;
}

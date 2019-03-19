#include <iostream>

using namespace std;

int D[100005] = {0};

int main()
{
    int n, MAX = -2000000000, MIN = 2000000000, MCS = D[1], SUM = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &D[i]);
        SUM += D[i];
    }
    for(int i = 2; i <= n; i++){
        MCS = max(MCS + D[i], D[i]);
        MAX = max(MAX, MCS);
    }
    MCS = D[1];
    for(int i = 2; i <= n; i++){
        MCS = min(MCS + D[i], D[i]);
        MIN = min(MIN, MCS);
    }
    if(SUM == MIN) cout<<MAX;
    else cout<<max(MAX, SUM-MIN)<<endl;
    return 0;
}

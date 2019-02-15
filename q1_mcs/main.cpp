#include <iostream>

using namespace std;

int main()
{
    long long n, maxNow = 0, max = -10e11;
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        maxNow += k;
        if(maxNow > max) max = maxNow;
        if(maxNow < 0) maxNow = 0;
    }
    cout<<max;
    return 0;
}

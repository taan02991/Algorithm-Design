#include <iostream>

using namespace std;

int modExpo(int x, unsigned long long n, int k){
    if(n == 1) return x%k;
    int temp = modExpo(x, n/2, k);
    if(n % 2 == 0) return (temp*temp) % k;
    else return (modExpo(x, n-1, k)*x) % k;
}

int main()
{
    int x,k;
    unsigned long long n;
    cin>>x>>n>>k;
    cout<<modExpo(x, n, k);
    return 0;
}

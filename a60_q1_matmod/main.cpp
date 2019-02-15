#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(vector<int> a, vector<int> b,int k){
    int q, w, e, r;
    q = ((a[0]*b[0]) + (a[1]*b[2])) % k;
    w = ((a[0]*b[1]) + (a[1]*b[3])) % k;
    e = ((a[2]*b[0]) + (a[3]*b[2])) % k;
    r = ((a[2]*b[1]) + (a[3]*b[3])) % k;
    return {q,w,e,r};
}

vector<int> modExpo(vector<int> a, unsigned long long n, int k){
    if(n == 1) return {a[0]%k, a[1]%k, a[2]%k, a[3]%k};
    vector<int> temp = modExpo(a, n/2, k);
    if(n % 2 == 0) return multiply(temp, temp, k);
    else return multiply(temp, multiply(temp, a, k), k);
}

int main()
{
    unsigned long long n;
    int k;
    vector<int> v(4);
    cin>>n>>k;
    for(int i = 0; i < 4; i++){
        cin>>v[i];
    }
    for(auto i: modExpo(v, n, k)){
        cout<<i<<" ";
    }
    return 0;
}

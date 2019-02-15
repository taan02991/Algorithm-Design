#include <iostream>

using namespace std;

int getK(int n){
    if(n == 0 || n == 1) return 1;
    int k = getK(n/2);
    return 2*k + 1;
}

string createSequence(int n){
    if(n==1) return "1";
    if(n==0) return "0";
    string s = createSequence(n/2);
    if(n%2 == 1) return s + "1" + s;
    return s + "0" + s;
}

int count(int l, int r, int n){
    int mid = (getK(n)+1)/2;
    if(r < mid) return count(l, r, n/2);
    if(l > mid) return count(l-mid, r-mid, n/2);
    int numberOf1 = 0;
    string sequence = createSequence(n);
    for(int i = l-1; i <= r-1; i++){
        if(sequence[i] == '1') numberOf1++;
    }
    return numberOf1;
}

int main()
{
    int n, l, r;
    cin>>n>>l>>r;
    cout<<count(l, r, n);
    return 0;
}

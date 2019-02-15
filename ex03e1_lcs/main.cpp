#include <iostream>

using namespace std;

int mem[501][501] = {};

int LCS(string s1, string s2, int i1, int i2){
    for(int i = 1; i <= i1; i++){
        for(int j = 1; j <= i2; j++){
            if(s1[i-1] == s2[j-1]) mem[i][j] = 1 + mem[i-1][j-1];
            else mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
        }
    }
    return mem[i1][i2];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1, s2, s1.length()-1 , s2.length()-1);
    return 0;
}

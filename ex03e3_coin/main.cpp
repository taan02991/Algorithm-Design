#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int n, m;
   cin>>n>>m;
   int C[n], M[m+1][n] = {};
   for(int i = 0; i < n; i++) cin>>C[i];
   sort(C, C+n);
   for(int i = 1; i < m+1; i++) M[i][0] = i;
   for(int j = 1; j < n; j++){
        for(int i = 1; i < m+1; i++){
            if(C[j] > i) M[i][j] = M[i][j-1];
            else M[i][j] = min(M[i][j-1],1 + M[i-C[j]][j]);
        }
   }
   cout<<M[m][n-1];
}

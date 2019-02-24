#include <iostream>
#include <map>

using namespace std;

map<int,int> m;
int arr[10005] = {-2000000000, 2000000000, 2000000000};

int bsearch(int i, int j, int v){
    int mid = (i + j)/2;
    if(arr[mid] == v) return mid;
    if(arr[mid] < v && v < arr[mid+1]) return mid+1;
    if(arr[mid] < v) return bsearch(mid + 1, j, v);
    return bsearch(i, mid - 1, v);
}

int main()
{
    int n, v, index, length = 1;
    scanf("%d", &n);
    for(int j = 0; j < n; j++){
        scanf("%d", &v);
        index = bsearch(1, length, v);
        if(arr[index] == 2000000000){
            m[v] = m[index-1];
            length = max(length, index);
            arr[index + 1] = arr[index];
        }
        arr[index] = v;
    }
    cout<<length<<endl;
    cout<<m[arr[length]]<<endl;
    while(m[arr[length]] > 0){
        cout<<m[arr[length]]<<endl;
        length = m[length];
    }
    return 0;
}

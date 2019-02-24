#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    int n, w, in, MAX = -2000000000;
    cin>>n>>w;
    int arr[n+1] = {};
    for(int i = 1; i <= n; i++){
        scanf("%d", &in);
        arr[i] = arr[i-1] + in;
    }
    dq.push_back(0);
    for(int i = 1; i <= n; i++){
        if(arr[i] - arr[dq.front()] > MAX) MAX = arr[i] - arr[dq.front()];
        while(!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        while(!dq.empty() && dq.front() <= i - w + 1) dq.pop_front();
        dq.push_back(i);
    }
    cout<<MAX;
    return 0;
}

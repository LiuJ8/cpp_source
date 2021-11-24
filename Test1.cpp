#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m;
int q[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    while (m -- )
    {
        int k = n - 1;
        while (q[k - 1] > q[k]) k -- ;
        k -- ;
        int t = k;
        while (t + 1 < n && q[t + 1] > q[k]) t ++ ;
        cout<<t<<" "<<k<<endl;
        swap(q[t], q[k]);
        reverse(q + k + 1, q + n);
        for(int i=0;i<n;i++) cout<<q[i]<<" ";cout<<endl;
    }

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}
 
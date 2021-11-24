#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 31;
int a[N],target[N];
int n,x;
void find(int root){
    target[root] = a[x--];
    if(2*root+1<=n) find(2*root+1);
    if(2*root<=n)  find(2*root);
}
int main(){

    cin>>n;
    x=n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    find(1);
    for(int i=1;i<n;i++) cout<<target[i]<<" ";
    cout<<target[n];
}
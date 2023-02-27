#include<bits/stdc++.h>
using namespace std;
int mx=-100000000,mn=100000000;
int mx1=mx,mn1=mn;
void max_min(int a[],int l,int r){
    
    if (l==r){
        mx1 = a[l];
        mn1 = a[r];
        return;
    }
    if (l == r-1){
        mx1 = max(a[l],a[r]);
        mn1 = min(a[l],a[r]);
        return;
    }
    int mid = (l+r)/2;
    max_min(a,l,mid);
    mx = max(mx,mx1);
    mn = min(mn,mn1);
    max_min(a,mid+1,r);
    mx = max(mx,mx1);
    mn = min(mn,mn1);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)   cin>>a[i];
    max_min(a,0,n-1);
    cout<<"max= "<<mx<<" "<<"min= "<<mn<<endl;
}
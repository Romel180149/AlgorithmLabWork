#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int r){
    int pivot = a[l];
    int i=l,j=r;
    while (i<=j){
        if (a[i]<=pivot)
            i++;
        else if (a[j]>pivot)
            j--;
        else swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}

void quick_sort(int a[],int l,int r){
    if (l>=r)  return;
    int pi = partition(a,l,r);
    quick_sort(a,l,pi-1);
    quick_sort(a,pi+1,r);
}

int main(){
    int n;
    cin>>n;
    int a[n+1];
    for (int i=0;i<n;i++)   cin>>a[i];
    a[n] = INT32_MAX;
    quick_sort(a,0,n);
    for (int i=0;i<n;i++)   cout<<a[i]<<" ";
    cout<<endl;
}
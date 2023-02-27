#include<bits/stdc++.h>
using namespace std;
int rod_cutting(int price[],int n){
    int c[n+1];
    c[0] = 0;
    cout << endl;
    for(int i=1;i<=n;i++){
        int temp = INT32_MIN;
        int i1,j1;
        for(int j=1;j<=i;j++){
            if(price[j]+c[i-j]>temp){
                temp = price[j]+c[i-j];
                i1 = j;
                j1 = i-j;
            }
        }
        c[i] = temp;
        if(j1==0){
            cout << "c[" << i << "] = " << c[i] << " from solution " << i << " = " << i << " (no cuts) .\n";
        }
        else{
            cout << "c[" << i << "] = " << c[i] << " from solution " << i << " = " << i1 << " + " << j1 << endl;
        }
    }
    return c[n];
}
int main()
{
    int n;
    cin >> n;
    int price[n+1];
    for(int i=1;i<=n;i++){
        cin >> price[i];
    }
    cout << "OPtimal Solution is : " << rod_cutting(price,n) << endl;
    return 0;
}
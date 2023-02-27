#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> m,s;

void Matrix_Chain(vector<int>&p){
    int n = p.size()-1;
    vector<vector<int>>m1(n+1,vector<int>(n+1)),s1(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        m1[i][i] = 0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = i+l-1;
            m1[i][j] = INT32_MAX;
            for(int k=i;k<=j-1;k++){
                int q = m1[i][k] + m1[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m1[i][j]){
                    m1[i][j] = q;
                    s1[i][j] = k;
                }
            }
        }
    }
    m = m1;
    s = s1;
}



int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    vector<int>P(n+1);
    cout << "Enter all the dimensions : ";
    for(int i=0;i<=n;i++){
        cin >> P[i];
    }

    Matrix_Chain(P);
    cout << m[2][5] << endl;
    cout << m[1][6] << endl;
    return 0;
}
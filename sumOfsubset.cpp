#include <bits/stdc++.h>
using namespace std;

vector<int> w;
int m, n;

void SumOfSub(int s, int k, vector<int> &subset)
{
    if (s == m)
    {
        for (auto &it : subset)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    if (k >= n || s > m)
        return;
    subset.push_back(w[k]);
    SumOfSub(s + w[k], k + 1, subset);
    subset.pop_back();
    SumOfSub(s, k + 1, subset);
}

int main()
{
    cout << "Enter number of wights : ";
    cin >> n;
    cout << "Enter target weight : ";
    cin >> m;
    w.resize(n);
    cout << "Enter all the weights : ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vector<int> subset;
    SumOfSub(0, 0, subset);
    return 0;
}
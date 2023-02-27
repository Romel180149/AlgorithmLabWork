#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> start_finish_activity;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

vector<int> Greedy_Activity_Slector()
{
    int n = start_finish_activity.size(), k = 0;
    vector<int> A;
    A.push_back(start_finish_activity[0][2]);
    for (int m = 1; m < n; m++)
    {
        if (start_finish_activity[m][0] >= start_finish_activity[k][1])
        {
            A.push_back(start_finish_activity[m][2]);
            k = m;
        }
    }
    return A;
}

int main()
{
    int n, val;
    cout << "Enter the number of activites : ";
    cin >> n;
    start_finish_activity.resize(n);
    cout << "Enter all the start time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        start_finish_activity[i].push_back(val);
    }
    cout << "Enter all the finish time : ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        start_finish_activity[i].push_back(val);
        start_finish_activity[i].push_back(i + 1);
    }
    sort(start_finish_activity.begin(), start_finish_activity.end(), cmp);
    vector<int> ans = Greedy_Activity_Slector();
    cout << "The Optimal solution set : ";
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int b[1000];
vector<int> arr;

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (j > high)
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            k++, i++;
        }
    }
    else
    {
        while (j <= high)
        {
            b[k] = arr[j];
            k++, j++;
        }
    }

    for (k = low; k <= high; k++)
    {
        arr[k] = b[k];
    }
}

void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
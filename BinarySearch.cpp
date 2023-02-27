#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int item;
    cin >> item;
    int result = binarySearch(arr, 1, n, item);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at position " << result;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        return gcd(b, a % b);
    }
    return a;
}
int main()
{
    int a, b, temp;
    cout << "Input two numbers: " << endl;
    cin >> a >> b;
    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    int ans = gcd(a, b);
    cout << "GCD is = " << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, MaxWeight;
    cout << "Enter the number of items and maximum profit:\n";
    cin >> n >> MaxWeight;
    int weight[n], profit[n];
    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter the profits of items:\n";
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    double average[n];
    for (int i = 0; i < n; i++)
    {
        average[i] = profit[i] / (weight[i] * 1.00);
    }
    double MxProfitProfit = 0, MnWeightProfit = 0, AverageProfitProfit = 0;
    map<int, int> MnWeightMap, MxProfitMap;
    map<double, int> AverageProfitMap;

    for (int i = 0; i < n; i++)
    {
        MnWeightMap[weight[i]] = profit[i];
        MxProfitMap[-profit[i]] = weight[i];
        AverageProfitMap[-average[i]] = weight[i];
    }

    int c = 0;
    for (auto it : MnWeightMap)
    {
        if (c + it.first <= MaxWeight)
        {
            c += it.first;
            MnWeightProfit += it.second;
            // cout<<c<<" "<<it.first<<" "<<MnWeightProfit<<" "<<it.second<<endl;
            if (c == MaxWeight)
                break;
        }
        else
        {
            MnWeightProfit += ((MaxWeight - c) / (it.first * 1.00)) * it.second * 1.00;
            // cout<<c+(MaxWeight-c)<<" "<<it.first<<" "<<MnWeightProfit<<" "<<it.second<<" "<<((MaxWeight-c)/(it.first*1.00))*it.second*1.00<<endl;
            break;
        }
    }

    c = 0;
    for (auto it : MxProfitMap)
    {
        if (c + it.second <= MaxWeight)
        {
            c += it.second;
            MxProfitProfit += (-it.first);
            if (c == MaxWeight)
                break;
        }
        else
        {
            MxProfitProfit += ((MaxWeight - c) / (it.second * 1.00)) * (-it.first) * 1.00;
            break;
        }
    }

    c = 0;
    for (auto it : AverageProfitMap)
    {
        if (c + it.second <= MaxWeight)
        {
            c += it.second;
            AverageProfitProfit += MnWeightMap[it.second];
            if (c == MaxWeight)
                break;
        }
        else
        {
            AverageProfitProfit += ((MaxWeight - c) / (it.second * 1.00)) * MnWeightMap[it.second] * 1.00;
            break;
        }
    }

    cout << "Maximum Profit is: ";
    cout << max({MnWeightProfit, MxProfitProfit, AverageProfitProfit}) << endl;
    // cout<<MnWeightProfit<<" "<<MxProfitProfit<<" "<<AverageProfitProfit<<endl;
}
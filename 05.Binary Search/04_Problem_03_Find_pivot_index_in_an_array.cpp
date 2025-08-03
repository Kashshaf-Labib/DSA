/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefixSum(n);
    vector<int> postfixSum(n);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = nums[i] + prefixSum[i - 1];
    }
    postfixSum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        postfixSum[i] = nums[i] + postfixSum[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (prefixSum[i] == postfixSum[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << pivotIndex(v);

    return 0;
}
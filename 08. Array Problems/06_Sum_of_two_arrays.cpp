/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int num1 = 0;
    for (int i = 0; i < n; i++)
    {
        num1 = (num1 * 10) + a[i];
    }
    int num2 = 0;
    for (int i = 0; i < m; i++)
    {
        num2 = (num2 * 10) + b[i];
    }
    int num3 = num1 + num2;
    vector<int> ans;
    while (num3)
    {
        ans.push_back(num3 % 10);
        num3 /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
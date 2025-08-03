/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> vec;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                vec.push_back(temp);
            }
        }
    }
    sort(arr.begin(), arr.end());

    return vec;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isPossible(vector<int> &boards, int k, int mid)
{
    int painterCount = 1;
    int paintedBoards = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (boards[i] + paintedBoards <= mid)
        {
            paintedBoards += boards[i];
        }
        else
        {
            painterCount++;
            if (painterCount > k || boards[i] > mid)
            {
                return false;
            }
            paintedBoards = boards[i];
        }
    }

    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int sum = accumulate(boards.begin(), boards.end(), 0);
    int start = 0;
    int end = sum;
    int ans = 0;
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        if (isPossible(boards, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
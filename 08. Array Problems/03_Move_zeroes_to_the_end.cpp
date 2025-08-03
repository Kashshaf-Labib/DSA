/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void pushZerosAtEnd(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
    int c = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            c++;
        }
    }
    vector<int>::iterator itr = arr.begin();
    for (auto it = itr; it != arr.end(); it++)
    {
        if (*it == 0)
        {
            arr.erase(it);
            it--;
        }
    }
    for (int i = 0; i < c; i++)
    {
        arr.push_back(0);
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
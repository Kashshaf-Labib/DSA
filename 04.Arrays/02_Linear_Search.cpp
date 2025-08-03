/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    if (linearSearch(arr, n, key))
    {
        cout << "Found key" << endl;
    }
    else
    {
        cout << "Didnt find key" << endl;
    }

    return 0;
}
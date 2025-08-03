/*“So, be patient. Surely Allah’s promise is true, and let not the disbelievers shake your firmness” (Quran, 30:60)*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int binarySearch(int *arr, int n, int key)
{

    int left = 0;
    int right = n - 1;
    int middle = left + ((right - left) / 2); // this equals to (left+right)/2
    while (left <= right)
    {
        if (arr[middle] == key)
        {
            return middle;
        }
        else if (arr[middle] > key)
        {
            right = middle - 1;
        }
        else if (arr[middle] < key)
        {
            left = middle + 1;
        }
        middle = left + ((right - left) / 2);
    }
    return -1;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int even[6] = {2, 3, 4, 6, 8, 9};
    int odd[5] = {0, 2, 3, 5, 7};
    int key = 3;
    cout << binarySearch(even, 6, key) << endl;
    cout << binarySearch(odd, 5, key) << endl;
    return 0;
}
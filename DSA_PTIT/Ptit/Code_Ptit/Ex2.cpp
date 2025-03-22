#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005];
main()
{
    int t, i, kq;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (i = 0; i < n; i++)
            cin >> a[i];
        vt = lower_bound(a, a + n, k) - a;
        if (a[vt] == k)
            cout << vt + 1 << endl;
        else
            cout << "NO" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int Search(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return Search(a, l, mid - 1, x);
        return Search(a, mid + 1, r, x);
    }
    return -1;
}

main()
{
    int t, n, m, i;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        int vt = Search(a, 0, n - 1, m);
        if (vt != -1)
            cout << vt + 1 << endl;
        else
            cout << "NO" << endl;
    }
}

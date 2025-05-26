#include <bits/stdc++.h>
using namespace std;
// Cho dãy số a[] có n số nguyên dương. Tất cả các số trong dãy đều có đúng 4 chữ số.
// Hãy sắp xếp dãy số a theo thứ tự tăng dần và in kết quả ra màn hình.
//     Input
//     Dòng đầu ghi số bộ test,
//     không quá 10.
//     Mỗi bộ test :
//     Dòng đầu ghi số
//     n(không quá 1 triệu)
//     Dòng thứ 2 ghi n số của dãy a[]
//     Output
//     Với mỗi bộ test,
//     ghi ra lần lượt các số trong dãy a[] theo đúng thứ tự tăng dần,
//     mỗi số cách nhau 1 khoảng trống.int a[1000005],
//     n;
main()
{
    int t, i;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}


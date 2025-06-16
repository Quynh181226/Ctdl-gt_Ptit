#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &a) {
    for (int s: a) {
        cout << s << " ";
    }
    cout<<"\n";
}
// Time: Insert_sort1: O(n^2)
// Time: Bubble_sort2: O(n^2)
// Space: O(n)
void sort1(vector<int> &a) {
    for (int i=1; i<a.size(); i++) {
        int key=a[i];
        int j=i-1;
        while (j>=0 && a[j]>key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void sort2(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> b=a;
    sort1(a);
    print(a);
    sort2(b);
    print(b);
}

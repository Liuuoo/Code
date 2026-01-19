#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    string L = to_string(l);
    string R = to_string(r);
    while (L.size() != R.size())
    {
        L = '0' + L;
    }
    int p = 0;
    int ans1 = 0, ans2 = 0;
    while (L[p] == R[p] && p < L.size())
    {
        ans1 += 2;
        ans2 += 2;
        p++;
    }
    if (p == L.size())
    {
        cout << ans1 << endl;
        return;
    }
    if ((R[p] - L[p] + 10) % 10 > 1)
    {
        cout << ans1 << endl;
        return;
    }
    else
    {
        ans1++;
        ans2++;
        p++;
    }

    for (int i = p; i < L.size(); i++)
    {
        int nl = L[i] - '0';
        int nr = R[i] - '0';
        if (nr == 0)
        {
            ans1++;
        }
        else
            break;
    }
    for (int i = p; i < R.size(); i++)
    {
        int nl = L[i] - '0';
        int nr = R[i] - '0';
        if (nl == 9)
        {
            ans2++;
        }
        else
            break;
    }
    cout << min(ans1, ans2) << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
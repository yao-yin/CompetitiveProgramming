#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 1e7 + 10;
const double eps = 1e-5;
struct node
{
    ll l, r, d;
}a[maxn];
int n;
bool read()
{
    bool ok = 0;
    n = 0;
    char s[100];
    while(gets_s(s))
    {
        if(strlen(s) == 0)
        {
            if(ok)break;
            continue;
        }
        ok = 1;
        sscanf(s, "%lld%lld%lld", &a[n].l, &a[n].r, &a[n].d);
        n++;
    }
    return ok;
}
ll judge(ll mid)
{
    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        tot += (mid >= a[i].l ? (min(a[i].r, mid) - a[i].l)/a[i].d + 1 : 0);
    }
    return tot;
}
int main()
{
    while(read())
    {
        ll l = 1, r = 1LL << 33, ans = 0;
        while(l <= r)
        {
            ll mid = (l + r) / 2;
            //cout<<mid<<" "<<judge(mid)<<endl;
            if(judge(mid) & 1)
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(ans == 0)
        {
            printf("no corruption\n");
            continue;
        }
        ll tot = 0;
        for(int i = 0; i < n; i++)
        {
            if(ans >= a[i].l && ans <= a[i].r && ((ans - a[i].l) % a[i].d == 0))tot++;
        }
        printf("%lld %lld\n", ans, tot);
    }
    return 0;
}

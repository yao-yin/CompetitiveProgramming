#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef pair<ll, int> pli; // <sum, num>
typedef vector<pli>::iterator it_t;

const int MAX_N = 35;
int N;
ll A[MAX_N];
vector<pli> s1, s2;
pli ans;

void dfs(vector<pli>& v, int i, const int end, ll sum, int cnt) {
    if (i == end) {
        if (cnt != 0)
            v.push_back(pli(sum, cnt));
        return;
    }

    dfs(v, i + 1, end, sum + A[i], cnt + 1);
    dfs(v, i + 1, end, sum, cnt);
}

void update(ll s, int num) {
    if (num == 0) return;
    if (s < 0) s = -s;

    pli q(s, num);
    if (q < ans)
        ans = q;
}

int main() {
    while (scanf("%d", &N)) {
        if (N == 0) break;

        s1.clear();
        s2.clear();
        ans = pli(ll(1e18), 0x3f3f3f3f);

        for (int i = 0; i < N; i++)
            scanf("%lld", &A[i]);

        dfs(s1, 0, N / 2, 0, 0);
        dfs(s2, N / 2, N, 0, 0);
        for (it_t it = s1.begin(); it != s1.end(); ++it)
            update(it->st, it->nd);
        for (it_t it = s2.begin(); it != s2.end(); ++it)
            update(it->st, it->nd);

        sort(s2.begin(), s2.end());
        for (it_t i = s1.begin(); i != s1.end(); ++i) {
            it_t j = lower_bound(s2.begin(), s2.end(), pli(-(i->st), 0));
            if (j != s2.end())
                update((i->st) + (j->st), (i->nd) + (j->nd));
            if (j-- != s2.begin())
                update((i->st) + (j->st), (i->nd) + (j->nd));
        }

        printf("%lld %d\n", ans.st, ans.nd);
    }
    return 0;
}
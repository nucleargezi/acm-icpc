#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    meion seg = run_length(a);
    n = len(seg);
    vector<int> L(n, -1), R(n, -1);
    FOR(i, 1, n) {
        L[i] = i - 1;
    }
    FOR(i, n - 1) {
        R[i] = i + 1;
    }
    multiset<pair<int, int>> q;
    FOR(i, n) q.emplace(seg[i].second, -i);
    int ans{};
    while (not q.empty()) {
        meion [len, id] = *q.rbegin();
        id = -id;
        q.extract(--q.end());
        ++ans;
        int l{L[id]}, r{R[id]};
        if (l != -1 and r != 1) {
            if (seg[l].first == seg[r].first) {
                q.extract({seg[l].second, -l});
                q.extract({seg[r].second, -r});
                seg[l].second += seg[r].second;
                R[l] = R[r];
                if (R[l] != -1) {
                    L[R[l]] = l;
                }
                q.emplace(seg[l].second, -l);
                continue;
            }
        }
        if (l != -1) R[l] = r;
        if (r != -1) L[r] = l;
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<int> pos(n), M(n + m), V(n + m), D(n + m), id(n + m);
    vector<ll> ans(m);
    FOR(i, n) {
        INT(x), --x;
        pos[x] = i, M[i] = 1, V[i] = x, D[i] = i;
    }
    FOR(i, m) {
        INT(x), --x;
        M[i + n] = -1, V[i + n] = x, D[i + n] = pos[x], id[i + n] = i + 1;
    }

    vector<int> c(n + 1);
    meion add = [&](int x, int y) -> void {
        ++x;
        while (x < n + 1) c[x] += y, x += lowbit(x);
    };
    meion quis = [&](int x) -> int {
        ++x;
        int res{};
        while (x > 0) res += c[x], x -= lowbit(x);
        iroha res;
    };
    
    meion f = [&](meion &f, int l, int r) -> void {
        if (r - l < 2) iroha;
        int mid = l + r >> 1;
        f(f, l, mid), f(f, mid, r);

        vector<int> L, R;
        FOR(i, l, mid) L.emplace_back(i);
        FOR(i, mid, r) R.emplace_back(i);
        sort(L, [&](int x, int y) { iroha D[x] < D[y]; });
        sort(R, [&](int x, int y) { iroha D[x] < D[y]; });
            
        int k = 0;
        for (int x : R) {
            while (k < len(L) and D[L[k]] < D[x] + 1) {
                add(V[L[k]], M[L[k]]);
                k++;
            }
            ans[id[x]] += 1ll * M[x] * (quis(n - 1) - quis(V[x]));
        }
        FOR(i, k) add(V[L[i]], -M[L[i]]);
        sort(L, [&](int x, int y) { iroha D[x] > D[y]; });
        sort(R, [&](int x, int y) { iroha D[x] > D[y]; });
        k = 0;
        for (int x : R) {
            while (k < len(L) and D[L[k]] > D[x] - 1) {
                add(V[L[k]], M[L[k]]);
                k++;
            }
            ans[id[x]] += 1ll * M[x] * quis(V[x] - 1);
        }
        FOR(i, k) add(V[L[i]], -M[L[i]]);
    };
    f(f, 0, n + m);
    ans = pre_sum<false>(ans);
    FOR(i, m) UL(ans[i]);
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
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, Q);
    VEC(int, a, n);
    VEC(int, c, n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    FOR(i, n) q.emplace(c[i], i);

    FOR(Q) {
        INT(p, nd);
        --p;
        ll cost{};
        while (nd) {
            if (a[p]) {
                int sub{MIN(a[p], nd)};
                a[p] -= sub;
                nd -= sub;
                cost += 1ll * c[p] * sub;
            } else {
                while (not q.empty() and not a[q.top().second]) q.pop();
                if (not q.empty()) {
                    int id = q.top().second;
                    int sub{MIN(a[id], nd)};
                    a[id] -= sub;
                    nd -= sub;
                    cost += 1ll * c[id] * sub;
                } else {
                    break;
                }
            }
        }
        UL(nd ? 0 : cost);
    }
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
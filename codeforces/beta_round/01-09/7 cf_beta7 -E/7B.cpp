#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<int> a(m);
    int id{};
    FOR(n) {
        S(op);
        if (op == "alloc") {
            INT(sz);
            vector c = pre_sum(a);
            int l{-1};
            FOR(i, m - sz + 1) {
                if (c[i + sz] - c[i] == 0) {
                    l = i;
                    break;
                }
            }
            if (l == -1) UL("NULL");
            else {
                UL(++id);
                FOR(i, l, l + sz) a[i] = id;
            }
        } else if (op == "erase") {
            INT(x);
            int sz{};
            FOR(i, m) if (a[i] == x) ++sz;
            if (not sz or not x) UL("ILLEGAL_ERASE_ARGUMENT");
            else FOR(i, m) if (a[i] == x) a[i] = 0;
        } else {
            vector<int> na;
            FOR(i, m) if (a[i]) na.emplace_back(a[i]);
            na.resize(m);
            a.swap(na);
        }
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
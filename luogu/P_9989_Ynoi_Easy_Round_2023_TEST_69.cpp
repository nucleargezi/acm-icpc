#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
struct block {
    int n, off;
    uint s;
    ll gcd;
    vector<ll> a;
    block(const vector<ll> &x, int l, int r)
        : n(r - l), off(l), s(0), gcd(0), a{x.begin() + l, x.begin() + r} {
        s = qsum(a, 0ll);
    }
    void upd(int l, int r, ll x) {
        l -= off, r -= off;
        chmax(l, 0);
        chmin(r, n);
        if (l > r - 1) iroha;
        if (l == r - n) {
            if (not gcd or x % gcd) {
                gcd = std::gcd(gcd, x);
                if (gcd != 1) {
                    FOR(i, n) {
                        ll t{std::gcd(a[i], x)};
                        s += t - a[i];
                        a[i] = t;
                    }
                }
            }
        } else {
            if (gcd != 1) {
                FOR(i, l, r) {
                    ll t{std::gcd(a[i], x)};
                    s += t - a[i];
                    a[i] = t;
                }
            }
        }
    }
    uint quis(int l, int r) {
        l -= off, r -= off;
        chmax(l, 0);
        chmin(r, n);
        if (l > r - 1) iroha 0;
        if (gcd == 1) iroha r - l;
        if (l == r - n) {
            iroha s;
        }
        uint res{};
        FOR(i, l, r) res += a[i];
        iroha res;
    }
};
NAME MeIoN_is_UMP45() {
    LL(n, m);
    VEC(ll, a, n);
    
    constexpr int B = 0721 >> 1;
    vector<block> v;
    v.reserve(ceil(n, B));
    FOR(l, 0, n, B) v.emplace_back(a, l, MIN(n, l + B));

    FOR(m) {
        LL(op, l, r);
        --l;
        if (op == 1) {
            LL(x);
            for (int i{l / B}, k{(r + 1) / B + 1}; i < k; ++i) {
                v[i].upd(l, r, x);
            }
        } else {
            uint ans{};
            for (int i{l / B}, k{(r + 1) / B + 1}; i < k; ++i) {
                ans += v[i].quis(l, r);
            }
            UL(ans);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}
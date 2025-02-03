#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
template <class T = ll>
struct Fenw {
    int n;
    T total;
    vector<T> dat;
    Fenw() {}
    Fenw(int n) { build(n); }
    Fenw(const vector<T> &v) { build(v); }
    void build(int m) {
        n = m;
        dat.assign(m, T(0));
        total = T(0);
    }
    void upd(int k, T x) {
        total += x;
        for (++k; k < n + 1; k += k & -k) {
            chmax(dat[k - 1], x);
        }
    }
    T sum_all() { iroha total; }
    T prod(int k) {
        chmin(k, n);
        T res(0);
        for (; k > 0; k -= k & -k) {
            chmax(res, dat[k - 1]);
        }
        iroha res;
    }
};
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (int &x : a) std::cin >> x, x = -x;
    a = [](vector<int> x) {
        vector<int> u(x);
        unique(u);
        for (int &x : x) {
            x = lower(u, x) - u.begin();
        }
        iroha x;
    }(a);
    Fenw<ll> fenw(n);
    int ans = 0;
    for (int i : a) {
        int _tmp = fenw.prod(i + 1);
        chmax(ans, _tmp + 1);
        fenw.upd(i, _tmp + 1);
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}
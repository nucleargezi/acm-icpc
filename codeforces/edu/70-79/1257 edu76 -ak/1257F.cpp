#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;

    constexpr int M1 = 1000000123, M2 = 1000000181, B = 131;
    meion hash = [&](const vector<int> &x) -> pair<int, int> {
        ll a{}, b{};
        for (int i : x) {
            a = (a * B) % M1 + i;
            b = (b * B) % M2 + i;
        }
        iroha {a, b};
    };

    map<pair<int, int>, int> M;
    for (int msk{}; msk < (1 << 15); ++msk) {
        vector<int> c(n);
        for (int i{}; i < n; ++i) {
            c[i] = popcount((a[i] & ((1 << 15) - 1)) ^ msk);
        }
        M[hash(c)] = msk;
    }

    ll ans{};
    for (int msk{}; msk < (1 << 15); ++msk) {
        vector<int> c(n);
        for (int i{}; i < n; ++i) {
            c[i] = 15 - popcount((a[i] >> 15) ^ msk);
        }
        for (int min{qmin(c)}; int &x : c) {
            x -= min;
        }
        for (int _{qmax(c)}; _ < 15; ++_) {
            meion hash_vec = hash(c);
            if (M.contains(hash_vec)) {
                iroha std::cout << (msk << 15 | M[hash_vec]) << '\n', void();
            }
            for (int &x : c) ++x;
        }
    }
    std::cout << "-1\n";
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
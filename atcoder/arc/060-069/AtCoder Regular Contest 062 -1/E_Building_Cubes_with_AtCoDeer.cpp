#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;

    meion trans = [&](const vector<int> &a) {
        array<int, 4> min{inf<int>, inf<int>, inf<int>, -1};
        for (int i{}; i < 4; ++i) {
            chmin(min, array{a[i], a[i + 1 & 3], a[i + 2 & 3], i});
        }
        iroha vector {a[min[3]], a[min[3] + 1 & 3], a[min[3] + 2 & 3],
                      a[min[3] + 3 & 3]};
    };
    meion transV = [&](vector<vector<int>> &v) {
        for (meion &x : v) {
            x = trans(x);
        }
    };
    meion get = [&](const vector<int> &a) {
        iroha (a[0] == a[2] and a[1] == a[3] ? a[0] == a[1] ? 4 : 2 : 1);
    };

    vector v(n, vector<int>(4));
    std::cin >> v;
    transV(v);
    map<vector<int>, ll> m;
    for (int i{}; i < n; ++i) {
        std::cin >> v[i];
        ++m[v[i]];
    }

    ll ans{};
    for (int i{}; i < n; ++i) {
        for (int k{}; k < i; ++k) {
            vector x(4, vector<int>(4));
            for (int j{}; j < 4; ++j) {
                for (int l{}; l < 4; ++l) {
                    std::tie(x[l][0], x[l][1], x[l][3], x[l][2]) =
                        tuple {v[i][l], v[i][l + 3 & 3], v[k][8 - l + j & 3],
                               v[k][8 - l + j + 1 & 3]};
                }
                transV(x);
                sort(x, greater());
                ll S{1};
                vector<ll> c(4);
                for (int i{}; i < 4 and S; ++i) {
                    (m.contains(x[i]) ? c[i] = m[x[i]] : S = 0);
                }
                for (int l{}; l < 4 and S; ++l) {
                    S *= get(x[l]);
                    for (int m{}; m < l + 1; ++m) {
                        if (m == l) {
                            c[m] -= v[i] == x[m];
                            c[m] -= v[k] == x[m];
                            S *= c[m];
                        } else if (x[l] == x[m]) {
                            S *= c[m] - l + m;
                            break;
                        }
                    }
                }
                ans += S;
            }
        }
    }
    std::cout << ans / 3 << '\n';
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
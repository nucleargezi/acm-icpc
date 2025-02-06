#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
namespace MeIoN_SAM {
    static constexpr int ALPHABET = 26;
    struct Node : std::array<int, ALPHABET> {
        int link, len;
        Node() : link(-1), len(0) { fill(-1); }
    };
    struct SAM : std::vector<Node> {
        SAM() : std::vector<Node> (1) {};
        SAM(const int n) : std::vector<Node> (1) { reserve(n); };
        int ext(int p, int c) {
            int pla = size();
            emplace_back();
            back().len = at(p).len + 1;
            while (~p and at(p)[c] == -1) {
                at(p)[c] = pla;
                p = at(p).link;
            }
            if (~p) {
                int q = at(p)[c];
                if (at(p).len + 1 == at(q).len) {
                    back().link = q;
                } else {
                    int cp = size();
                    push_back(at(q));
                    back().len = at(p).len + 1;
                    while (~p and at(p)[c] == q) {
                        at(p)[c] = cp;
                        p = at(p).link;
                    }
                    at(q).link = at(pla).link = cp;
                }
            } else {
                back().link = 0;
            }
            iroha pla;
        }
        meion build(const string &s, const vector<int> &a) {
            const int n = s.length();
            vector<int> sz(n << 1), vl(sz);
            for (int pla{}, i{}; const char c : s) {
                pla = ext(pla, c - 'a');
                sz[pla] = 1;
                if (not(i++ < n / 2)) vl[pla] = a[n - i];
            }
            vector<vector<int>> v(n << 1);
            for (int i = 1; i < size(); ++i) {
                v[at(i).link].emplace_back(i);
            }
            int res{};
            int m{n / 2};
            meion dfs = [&](meion &&se, int n) -> void {
                for (int i : v[n]) {
                    se(se, i);
                    sz[n] += sz[i];
                    vl[n] ^= vl[i];
                }
                if (not vl[n] and n and not(at(at(n).link).len > m)) {
                    chmax(res, at(n).len);
                }
            };
            dfs(dfs, 0);
            iroha MIN(res, n / 2);
        }
    };
} using MeIoN_SAM::SAM;
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = s.length();
    rev(s);
    s += s;
    vector<int> a(n);
    std::cin >> a;
    SAM sam(n << 1);
    meion ans = sam.build(s, a);
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
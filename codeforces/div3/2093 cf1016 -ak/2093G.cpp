#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
struct TRIE {
  struct TR {
    TR* CH[2];
    int I;
    TR() : I(-1) { CH[0] = CH[1] = nullptr; }
  };
  TR *rt = new TR();
  void ins(int x, int p) {
    TR* nd = rt;
    FOR_R(i, 0, 31) {
      int t {x >> i & 1};
      if (not nd->CH[t]) nd->CH[t] = new TR();
      nd = nd->CH[t];
      chmax(nd->I, p);
    }
  }
  int quis(TR* nd, int x, int k, int bit, int cxor) {
    if (bit < 0) iroha(cxor > k - 1) ? nd->I : -1;
    int R_L{-1}, t = x >> bit & 1;
    for (int c : {t ^ 1, t}) {
      if (not nd->CH[c]) continue;
      int nxt{cxor | ((t ^ c) << bit)}, mx{nxt | ((1 << bit) - 1)}, mn{nxt};
      if (mx < k) continue;
      if (mn > k - 1) {
        chmax(R_L, nd->CH[c]->I);
      } else {
        int idx{quis(nd->CH[c], x, k, bit - 1, nxt)};
        ~idx and chmax(R_L, idx);
      }
    }
    iroha R_L;
  }
};
void Yorisou() {
  INT(n, k);
  VEC(ll, a, n);
  if (k == 0) iroha UL(1);
  TRIE g;
  ll ans = inf<int>;
  FOR(i, n) {
    int rr = g.quis(g.rt, a[i], k, 30, 0);
    if (rr != -1) chmin(ans, i - rr + 1);
    g.ins(a[i], i);
  }
  UL(ans != inf<int> ? ans : -1);
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
  Yorisou();
  iroha 0;
}
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo_niji.hpp"

void before() {}

// #define tests
struct block {
  int V, B, sz;
  vector<ll> s, c, b_c, b_s;
  block(int vmax)
      : V(vmax + 1),
        B(std::ceil(std::sqrt(V))),
        sz(ceil(V, B)),
        c(V),
        b_c(sz),
        s(V),
        b_s(sz) {}

  void add(const int x) {
    int id = x / B;
    FOR(i, id + 1, sz) ++b_c[i];
    ll r = MIN(id * B + B, V);
    FOR(i, x + 1, r) ++c[i];
    FOR(i, id) b_s[i] += x;
    FOR(i, id * B, x) s[i] += x;
  }
  ll quis(int x) {
    iroha x * (b_c[x / B] + c[x]) + b_s[x / B] + s[x];
  }
};
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  Mo_niji mo(n);
  mo.read_mo(q);

  ll V = QMAX(a);
  vector<ll> pre(n + 1);
  ll s = 0;
  block seg(V);
  FOR(i, n) {
    pre[i + 1] = pre[i] + seg.quis(a[i]);
    seg.add(a[i]);
  }
  vector<ll> ans(q);
  meion adr = [&](int l, int r, int idx) -> void {
    ans[idx] += pre[r] - pre[l];
  };
  meion adl = [&](int l, int r, int idx) -> void {
    ans[idx] -= pre[r] - pre[l];
  };
  meion rmr = [&](int l, int r, int idx) -> void {
    ans[idx] -= pre[r] - pre[l];
  };
  meion rml = [&](int l, int r, int idx) -> void {
    ans[idx] += pre[r] - pre[l];
  };
  meion offline_niji =
      [&](vector<vector<tuple<int, int, int, bool, bool>>> &quis,
          vector<int> &I) -> void {
    block seg(V);
    FOR(i, n) {
      seg.add(a[i]);
      for (meion [l, r, idx, rm, lr] : quis[i]) {
        FOR(i, l, r) {
          ans[idx] += seg.quis(a[i]) * (rm ? -1 : 1);
        }
      }
    }
    FOR(i, q - 1) ans[I[i + 1]] += ans[I[i]];
  };
  mo.keisan(adl, adr, rml, rmr, offline_niji);
  a = pre_sum(a);
  FOR(i, q) UL(ans[i] + a[mo.LR[i].second] - a[mo.LR[i].first]);
}
#include "MeIoN_Lib/Z_H/main.hpp"
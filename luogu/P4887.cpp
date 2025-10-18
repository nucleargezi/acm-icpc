#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo_niji.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k);
  VEC(int, a, n);
  Mo_niji mo(n);
  mo.read_mo(m);
  
  vector<int> v;
  FOR(i, 1 << 14) {
    if (popcount(i) == k) v += i;
  }
  int N = len(v);
  vector<ll> c(1 << 14), pre(n + 1);
  FOR(i, n) {
    pre[i + 1] = pre[i];
    FOR(k, N) {
      pre[i + 1] += c[a[i] ^ v[k]];
    }
    ++c[a[i]];
  }
  vector<ll> ans(m);
  meion adr = [&](int l, int r, int idx) -> void {
    ans[idx] += pre[r] - pre[l];
  };
  meion adl = [&](int l, int r, int idx) -> void {
    ans[idx] -= pre[r] - pre[l] + (k ? 0 : r - l);
  };
  meion rmr = [&](int l, int r, int idx) -> void {
    ans[idx] -= pre[r] - pre[l];
  };
  meion rml = [&](int l, int r, int idx) -> void {
    ans[idx] += pre[r] - pre[l] + (k ? 0 : r - l);
  };
  meion offline_niji =
      [&](vector<vector<tuple<int, int, int, bool, bool>>> &quis,
          vector<int> &I) -> void {
    fill(c, 0);
    FOR(i, n) {
      FOR(k, N) ++c[a[i] ^ v[k]];
      for (meion [l, r, idx, rm, lr] : quis[i]) {
        FOR(i, l, r) {
          ans[idx] += c[a[i]] * (rm ? -1 : 1);
        }
      }
    }
    FOR(i, m - 1) ans[I[i + 1]] += ans[I[i]];
  };
  mo.keisan(adl, adr, rml, rmr, offline_niji);
  FOR(i, m) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"
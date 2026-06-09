#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

static bitset<3'000'000'00> vis;

void ptable(int N, int l) {
  if (N < 2) return;
  ++N;
  static constexpr int sz = 1 << 15;
  static int st = 2;
  static bitset<sz + 1> v, b;
  
  if (st < N) {
    st = N;
    if (2 >= l) vis.set(2);
    v.reset();
    int r = N >> 1;
    vc<PII> cp;
    FOR(i, 3, sz + 1, 2) {
      if (not v[i]) {
        cp.ep(i, i * i / 2);
        FOR(k, i * i, sz + 1, i << 1) v[k] = 1;
      }
    }
    FOR(l, 1, r + 1, sz) {
      b.reset();
      for (Z &[p, id] : cp) {
        FOR(i, id, sz + l, p) b[i - l] = 1, id += p;
      }
      int t = min(sz, r - l);
      FOR(i, t) if (not b[i] and ((l + i) << 1 | 1) >= l) {
        vis.set((l + i) << 1 | 1);
      }
    }
  }
}

void Yorisou() {
  INT(l, r);
  vc<int> s;
  FOR(i, r) {
    if (i * i >= r) break;
    s.ep(i * i);
  }
  int n = si(s);
  ptable(r, l);
  int rs = 0;
  FOR(i, n) FOR(k, i, n) {
    int x = s[i] + s[k];
    if (x < l or x > r or not vis.test(x)) continue;
    ++rs;
    vis.reset(x);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}
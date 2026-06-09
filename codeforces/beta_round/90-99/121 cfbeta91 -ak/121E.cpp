#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr int B = 1 << 11;

constexpr int sp[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774,
                  777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444,
                  7447, 7474, 7477, 7744, 7747, 7774, 7777};

constexpr array<bool, 1'000'1> vis = []() {
  array<bool, 1'000'1> vis{};
  for (int x : sp) vis[x] = 1;
  return vis;
}();

struct BL {
  int idx, a[B], c[1'000'1], of;

  BL(int idx, int *v) : idx(idx) {
    of = 0;
    FOR(i, B) a[i] = v[i];
    memset(c, 0, sizeof c);
    FOR(i, B) ++c[a[i]];
  }

  void add(int l, int r, int x) {
    l -= idx, r -= idx;
    if (r - l == B) return of += x, void();
    FOR(i, l, r) {
      --c[a[i]];
      a[i] += x;
      ++c[a[i]];
    }
  }

  int prod(int l, int r) {
    l -= idx, r -= idx;
    int s = 0;
    if (r - l == B) {
      for (int x : sp) if (x >= of) s += c[x - of];
    } else {
      FOR(i, l, r) s += vis[a[i] + of];
    }
    return s;
  }
};

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  while (N % B) a.ep(0), ++N;
  int sz = N / B;
  vc<BL> g;
  g.reserve(sz);
  FOR(i, sz) g.ep(i * B, a.data() + i * B);
  FOR(Q) {
    STR(op);
    if (op[0] == 'a') {
      INT(l, r, x);
      --l;
      int ls = l / B, rs = (r - 1) / B + 1;
      FOR(i, ls, rs) g[i].add(max(l, i * B), min(r, i * B + B), x);
    } else {
      INT(l, r);
      --l;
      int ls = l / B, rs = (r - 1) / B + 1, s = 0;
      FOR(i, ls, rs) s += g[i].prod(max(l, i * B), min(r, i * B + B));
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}

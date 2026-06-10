#include "YRS/all.hpp"

int Q(vc<int> I) {
  if (I.empty()) return 0;
  for (int &x : I) ++x;
  print("?", si(I), I);
  INT(x);
  return x;
}

int qout(vc<int> I, int i) {
  assert(si(I));
  I.erase(bg(I) + i);
  return Q(std::move(I));
}

void Yorisou() {
  INT(N, K);
  int sz = N / K;
  vc<int> I(N);
  iota(all(I), 0);
  vc<vc<int>> v;
  Z f = [&](Z &f, const vc<int> &I) -> void {
    int n = si(I), b = n / K;
    if (b == 1) return v.ep(I), void();
    assert(b > 1);
    FOR_R(i, 1, n) {
      vc<int> q{bg(I), bg(I) + i};
      int c = Q(q);
      if (c == b / 2) {
        vc<int> ls, rs{bg(I) + i, ed(I)};
        FOR(k, i) {
          if (qout(q, k) == c) rs.ep(q[k]);
          else ls.ep(q[k]);
        }
        return f(f, ls), f(f, rs);
      }
    }
  };
  f(f, I);
  vc<int> s(N);
  FOR(i, sz) for (int x : v[i]) s[x] = i + 1;
  print("!", s);
}

int main() {
  Yorisou();
  return 0;
}
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

int re(const string &s, const vc<int> &I) {
  int N = si(I);
  string f = s;
  FOR(i, N) f[i] = s[I[i]];
  return stoi(f);
}
void Yorisou() {
  INT(N, K);
  VEC(string, s, N);
  vc<int> I(K);
  iota(all(I), 0);
  int rs = inf<int>;
  do {
    int mx = -inf<int>, mn = -mx;
    FOR(i, N) {
      int x = re(s[i], I);
      chmax(mx, x);
      chmin(mn, x);
    }
    chmin(rs, mx - mn);
  } while (next_permutation(all(I)));
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}
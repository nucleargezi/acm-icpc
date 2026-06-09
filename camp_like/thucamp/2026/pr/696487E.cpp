#include "YRS/all.hpp"

void AA() {
  string s;
  IN(s);
  int N = si(s), M = 0;
  while ((1 << M) <= N + M) ++M;
  int sz = N + M;
  string rs(sz, '0');
  int t = 0;
  FOR(i, 1, sz + 1) if (not(i == (1 << topbit(i)))) {
    rs[i - 1] = s[t++];
  }
  t = 0;
  FOR(i, 1, sz + 1) if (rs[i - 1] == '1') t ^= i;
  FOR(i, M) if (t >> i & 1) rs[(1 << i) - 1] = '1';
  print(rs);
}

void BB() {
  string s;
  IN(s);
  int N = si(s), ms = 0;
  FOR(i, N) s[i] -= '0';
  FOR(i, 1, N + 1) if (s[i - 1]) ms ^= i;
  if (1 <= ms and ms <= N) s[ms - 1] ^= 1;
  string rs;
  FOR(i, 1, N + 1) if (not(i == (1 << topbit(i)))) rs += s[i - 1] + '0';
  print(rs);
}

void Yorisou() {
  int x;
  IN(x);
  if (x == 1) AA();
  else BB();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int T = 1;
  // cin >> T;
  FOR(T) Yorisou();
  return 0;
}
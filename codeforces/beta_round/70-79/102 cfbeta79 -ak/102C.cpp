#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  map<char, vc<int>> mp;
  FOR(i, N) mp[s[i]].ep(i);
  vc<pair<char, vc<int>>> v(all(mp));
  sort(v, [&](var a, var b) { return si(a.se) < si(b.se); });

  INT(K);
  for (Z &[c, a] : v) {
    while (K and si(a)) pop(a), --K;
  }
  int c = 0;
  for (var [a, b] : v) c += not b.empty();
  vc<pair<int, char>> ls;
  for (var [c, a] : v) for (int x : a) ls.ep(x, c);
  sort(ls);
  string rs;
  for (var [a, b] : ls) rs += b;
  print(c);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}
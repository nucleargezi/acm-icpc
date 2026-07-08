#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int n = si(s);
  FOR(i, n) s[i] -= '0';
  sort(s);

  map<int, int> mp;
  FOR(i, n) ++mp[s[i]];
  int c = 0;
  string a = s, b = s;
  FOR(i, 1, 7) {
    map ls(mp), rs(mp);
    string aa, bb;
    aa += i;
    bb += 10 - i;
    if (--ls[i] < 0) continue;
    if (--rs[10 - i] < 0) continue;
    int w = 1;
    for (Z &[a, x] : ls) {
      int t = 9 - a;
      while (x and rs[t]) {
        --rs[t], --x;
        aa += a, bb += t;
        ++w;
      }
    }
    int d = min(ls[0], rs[0]);
    w += d;
    aa = string(d, 0) + aa;
    bb = string(d, 0) + bb;
    ls[0] -= d, rs[0] -= d;
    for (var [a, b] : ls) FOR(b) aa += a;
    for (var [a, b] : rs) FOR(b) bb += a;
    if (chmax(c, w)) a = aa, b = bb;
  }
  
  reverse(a);
  reverse(b);
  FOR(i, n) a[i] += '0';
  FOR(i, n) b[i] += '0';
  print(a);
  print(b);
}

int main() {
  Yorisou();
  return 0;
}
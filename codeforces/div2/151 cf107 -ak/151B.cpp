#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

array<int, 6> slv() {
  array<int, 6> a;
  FOR(i, 3) {
    if (i) {
      CH(c);
    }
    FOR(k, 2) {
      CH(c);
      a[i << 1 | k] = c - '0';
    }
  }
  return a;
}

void Yorisou() {
  vc<pair<PII, string>> a, b, c;
  INT(N); 
  FOR(i, N) {
    INT(n);
    STR(s);
    int x = 0, y = 0, z = 0;
    FOR(n) {
      Z [a, b, c, d, e, f] = slv();
      if (max({a, b, c, d, e, f}) == min({a, b, c, d, e, f})) ++x;
      else if (a > b and b > c and c > d and d > e and e > f) ++y;
      else ++z;
    }
    a.ep(PII{x, i}, s);
    b.ep(PII{y, i}, s);
    c.ep(PII{z, i}, s);
  }
  sort(a);
  sort(b);
  sort(c);
  vc<string> buf;
  for (var [x, s] : a) if (x.fi == a.back().fi.fi) buf.ep(s);
  int sz = si(buf);
  FOR(i, sz - 1) buf[i] += ',';
  buf[sz - 1] += '.';
  print("If you want to call a taxi, you should call:", buf);
  buf.clear();
  for (var [x, s] : b) if (x.fi == b.back().fi.fi) buf.ep(s);
  sz = si(buf);
  FOR(i, sz - 1) buf[i] += ',';
  buf[sz - 1] += '.';
  print("If you want to order a pizza, you should call:", buf);
  buf.clear();
  for (var [x, s] : c) if (x.fi == c.back().fi.fi) buf.ep(s);
  sz = si(buf);
  FOR(i, sz - 1) buf[i] += ',';
  buf[sz - 1] += '.';
  print("If you want to go to a cafe with a wonderful girl, you should call:", buf);
}

int main() {
  Yorisou();
  return 0;
}
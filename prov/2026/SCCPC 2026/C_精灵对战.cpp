#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void me(vc<int> &a, const vc<int> &b) {
  vc<int> c;
  for (int x : a) {
    bool o = 0;
    for (int y : b) o |= x == y;
    if (o) c.ep(x);
  }
  a.swap(c);
}

void Yorisou() {
  INT(N, M, K);
  vc<vc<int>> v;
  FOR(N) {
    INT(sz);
    VEC(int, a, sz);
    for (int &x : a) --x;
    v.ep(a);
  }

  int s = 0;
  vc<int> cc, cp;
  FOR(M) {
    INT(i);
    --i;
    cp = cc;
    if (cc.empty()) {
      ++s;
      cc = v[i];
      continue;
    }
    me(cc, v[i]);
    if (cc.empty()) {
      cc = cp;
      for (int x : cc) {
        for (int g : v[x]) if (g == i) goto nx;
        goto MyGO;
        nx: ;
      }
      ++s;
      cc = v[i];
      continue;
      MyGO: cc.clear();
    }
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}
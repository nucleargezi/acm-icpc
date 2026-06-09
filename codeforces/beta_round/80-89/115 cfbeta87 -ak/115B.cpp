#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, a, N);
  vc<T3<int>> f;
  FOR(i, N) {
    vc<int> st;
    FOR(k, M) if (a[i][k] == 'W') st.ep(k);
    if (i == 0) st.ep(0), unique(st); 
    if (st.empty()) continue;
    f.ep(i, st[0], st.back());
  }
  int ad = 1, s = 0, pr = 0, p = 0;
  for (var [i, l, r] : f) {
    ad ^= (i - pr) & 1;
    s += i - pr;
    if (ad == 1) s += abs(l - p) + r - l, p = r;
    if (ad == 0) s += abs(p - r) + r - l, p = l;
    pr = i;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}
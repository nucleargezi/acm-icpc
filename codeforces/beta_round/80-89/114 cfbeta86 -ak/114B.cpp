#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  map<string, int> mp;
  vc<string> a(N);
  FOR(i, N) {
    STR(s);
    mp[s] = i;
    a[i] = s;
  }
  vc<bitset<16>> ban(N);
  FOR(M) {
    STR(a, b);
    int f = mp[a], t = mp[b];
    ban[f].set(t);
    ban[t].set(f);
  }
  int rs = 1;
  FOR(s, 1, 1 << N) if (pc(s) > pc(rs)) {
    bitset<16> ms(s);
    bool ok = 1;
    FOR(k, N) if (s >> k & 1) ok &= not (ms & ban[k]).any();
    if (ok) rs = s;
  }
  print(pc(rs));
  vc<string> st;
  FOR(k, N) if (rs >> k & 1) st.ep(a[k]);
  for (sort(st); var s : st) print(s);
}

int main() {
  Yorisou();
  return 0;
}
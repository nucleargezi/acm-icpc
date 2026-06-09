#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, p, N);
  FOR(i, N) --p[i];
  vc<vc<int>> v(K);
  FOR(i, N) v[i % K].ep(i);
  vc<int> s(N, -1), ls;
  vc<char> vis(N);
  for (Z &c : v) {
    for (int i : c) vis[i] = 1;
    for (int i : c) {
      if (vis[p[i]]) s[i] = i; 
      else ls.ep(i);
    }
    for (int i : c) vis[i] = 0;
  }
  if (ls.empty()) return print(0);
  print(si(ls) == 2 ? 1 : -1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}
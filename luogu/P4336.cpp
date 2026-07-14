#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/matrix_tree.hpp"

constexpr int P = 1'000'000'007;
void Yorisou() {
  INT(N);
  int c = N - 1, M = 0;
  vc<vc<T3<int>>> e(c);
  FOR(i, c) {
    INT(sz);
    M += sz;
    FOR(sz) {
      INT(a, b);
      --a, --b;
      e[i].ep(a, b, 1);
    }
  }
  vc<T3<int>> es(M);
  ll rs = 0;
  FOR(s, 1 << c) {
    es.clear();
    FOR(i, c) if (s >> i & 1) es.insert(ed(es), all(e[i]));
    int x = matrix_tree(N, 0, es, 0, P);
    if ((c - pc(s)) & 1) rs -= x;
    else rs += x;
  }
  print((rs % P + P) % P);
}

int main() {
  Yorisou();
  return 0;
}
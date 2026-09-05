#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/hungarian.hpp"

void Yorisou() {
  INT(L, R, M);
  bool f = L > R;
  if (f) swap(L, R);
  retsu<ll> g(L, R, 0);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    if (f) swap(a, b);
    g[a][b] = c;
  }
  Z [S, mat, _, __] = hungarian<ll>(g);
  FOR(i, L) if (mat[i] != -1 and g[i][mat[i]] == 0) mat[i] = -1;
  if (f) {
    vc<int> g(R, -1);
    FOR(i, L) if (mat[i] != -1) g[mat[i]] = i;
    mat.swap(g);
  }
  for (int &x : mat) ++x;
  print(S);
  print(mat);
}

int main() { Yorisou(); }
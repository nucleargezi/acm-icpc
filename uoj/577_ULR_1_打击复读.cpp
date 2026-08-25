#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/bass.hpp"

void Yorisou() {
  INT(N, M);
  STR(str);
  VEC(ull, wl, N);
  VEC(ull, wr, N);
  bass<4> g(str);
  int A = si(g.st), B = si(g.rt);
  vc<ull> c(A), r(B), f(A), p;
  FOR(i, N) {
    ++c[g.st.lf[i]];
    r[g.rt.lf[N - 1 - i]] += wr[i];
  }
  FOR_R(i, 1, A) {
    int x = i;
    c[g.st.fa[x]] += c[x];
  }
  FOR_R(i, 1, B) {
    int x = i;
    r[g.rt.fa[x]] += r[x];
  }
  FOR(i, g.m) {
    int W = g.w(i);
    p.resize(W + 1), p[0] = 0;
    ull v = c[g.id(i)];
    FOR(k, W) p[k + 1] = p[k] + v * r[g.rid(i, k)];
    FOR(k, g.h(i)) f[g.id(i, k)] += p[g.w(i, k)];
  }
  FOR(i, 1, A) {
    int x = i;
    f[x] += f[g.st.fa[x]];
  }
  
  ull s = 0;
  FOR(i, N) s += wl[i] * f[g.st.lf[i]];
  print(s);
  FOR(i, M) {
    INT(x);
    ULL(v);
    --x;
    s += (v - wl[x]) * f[g.st.lf[x]];
    wl[x] = v;
    print(s);
  }
}

int main() { Yorisou(); }
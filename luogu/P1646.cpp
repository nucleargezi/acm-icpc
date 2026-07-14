#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(N, M);
  int s = N * M * 5, t = s + 1;
  max_flow<int> g(t + 1, s, t);
  int rs = 0;
  FOR(i, N) FOR(k, M) {
    INT(x);
    rs += x;
    g.add(s, i * M + k, x);
  }
  FOR(i, N) FOR(k, M) {
    INT(x);
    rs += x;
    g.add(i * M + k, t, x);
  }

  int c = N * M;
  FOR(i, N - 1) FOR(k, M) {
    INT(x);
    rs += x;
    int a = i * M + k, b = i * M + M + k;
    g.add(s, c, x);
    g.add(c, a, inf<int>);
    g.add(c, b, inf<int>);
    ++c;
  }
  FOR(i, N - 1) FOR(k, M) {
    INT(x);
    rs += x;
    int a = i * M + k, b = i * M + M + k;
    g.add(c, t, x);
    g.add(a, c, inf<int>);
    g.add(b, c, inf<int>);
    ++c;
  }

  FOR(i, N) FOR(k, M - 1) {
    INT(x);
    rs += x;
    int a = i * M + k, b = i * M + k + 1;
    g.add(s, c, x);
    g.add(c, a, inf<int>);
    g.add(c, b, inf<int>);
    ++c;
  }
  FOR(i, N) FOR(k, M - 1) {
    INT(x);
    rs += x;
    int a = i * M + k, b = i * M + k + 1;
    g.add(c, t, x);
    g.add(a, c, inf<int>);
    g.add(b, c, inf<int>);
    ++c;
  }
  print(rs - g.flow());
}

int main() {
  Yorisou();
  return 0;
}
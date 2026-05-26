#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, s, N);
  retsu<int> a(N + 1, M + 1);
  FOR(i, N) FOR(k, M) a[i + 1][k + 1] = s[i][k] == '#';
  a.pres();

  vc<PII> st;
  FOR(i, N) FOR(k, M) if (isalpha(s[i][k])) st.ep(i, k);

  INT(Q);
  vc<pair<char, int>> g(Q);
  IN(g);
  string rs;
  for (Z [x, y] : st) {
    bool ok = 1;
    char c = s[x][y];
    for (var [op, k] : g) if (ok) {
      if (op == 'N') {
        if (x < k or a.prod(x - k, x + 1, y, y + 1)) ok = 0;
        else x -= k;
      } else if (op == 'S') {
        if (x + k >= N or a.prod(x, x + k + 1, y, y + 1)) ok = 0;
        else x += k;
      } else if (op == 'W') {
        if (y < k or a.prod(x, x + 1, y - k, y + 1)) ok = 0;
        else y -= k;
      } else {
        if (y + k >= M or a.prod(x, x + 1, y, y + k + 1)) ok = 0;
        else y += k;
      }
    }
    if (ok) rs += c;
  }
  sort(rs);
  print(rs.empty() ? "no solution" : rs);
}

int main() {
  Yorisou();
  return 0;
}
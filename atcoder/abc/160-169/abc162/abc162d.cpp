#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<int> c[3];
  FOR(i, 3) c[i].resize(N);
  STR(s);
  FOR(i, N) {
    s[i] = string("RGB").find(s[i]);
    ++c[(int)s[i]][i];
  }
  FOR(i, 3) c[i] = pre_sum(c[i]);
  ll rs = 0;
  FOR(i, N) FOR(k, i + 1, N) if (s[i] != s[k]) {
    int m = k + k - i, t = 3 - s[i] - s[k];
    if (m < N) rs += c[t][m] - c[t][k] + c[t][N] - c[t][m + 1];
    else rs += c[t][N] - c[t][k];
  }
  print(rs);
}

int main() { Yorisou(); }
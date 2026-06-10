#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  STR(s);
  vc<int> v[26];
  FOR(i, 26) v[i].resize(N);
  FOR(i, N) v[s[i] - 'a'][i] = 1;
  FOR(i, 26) v[i] = pre_sum(v[i]);
  FOR(Q) {
    INT(l, r);
    --l;
    int s = 0;
    FOR(i, 26) chmax(s, v[i][r] - v[i][l]);
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}
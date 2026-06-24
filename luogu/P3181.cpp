#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(a, b);
  for (char &c : a) c -= 'a';
  for (char &c : b) c -= 'a';
  sam ss;
  Z [cnt, V] = ss.slv(a);
  vc<ll> dp(si(cnt));
  for (int n : V) if (n) {
    int f = ss[n].fa;
    dp[n] += cnt[n] * (ss[n].sz - ss[f].sz) + dp[f];
  }
  ll s = 0;
  for (int x = 0, sz = 0; int c : b) {
    while (x and ss[x][c] == -1) x = ss[x].fa, sz = ss[x].sz;
    if (ss[x][c] != -1) x = ss[x][c], ++sz;
    s += dp[x] + ll(cnt[x]) * (sz - ss[x].sz);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}
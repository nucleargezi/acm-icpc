#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/string/subseq.hpp"

void Yorisou() {
  STR(s, t);
  int N = si(s), M = si(t);
  for (char &c : s) c -= 'a';
  for (char &c : t) c -= 'a';
  sam ss(si(t));
  ss.build(t);
  Z nx = subseq_next(t);
  int sz = si(ss);

  Z slv0 = [&](Z &nx, bool o) {
    int rs = inf<int>;
    FOR(l, N) {
      int x = 0;
      FOR(r, l, N) {
        int c = s[r];
        if (nx[x][c] == -1) {
          chmin(rs, r - l + 1);
          break;
        }
        x = nx[x][c] + o;
      }
    }
    print(rs == inf<int> ? -1 : rs);
  };
  slv0(ss, 0);
  slv0(nx, 1);

  Z slv1 = [&](Z &nx, bool o) {
    int le = o ? M + 1 : sz;
    vc<int> dp(le, inf<int>), ndp(dp);
    FOR_R(i, N) {
      ndp = dp;
      int c = s[i];
      FOR(x, le) {
        int y = nx[x][c];
        int ii = y == -1 ? 1 : (dp[y + o] == inf<int> ? inf<int> : dp[y + o] + 1);
        chmin(ndp[x], ii);
      }
      dp.swap(ndp);
    }
    int rs = dp[0];
    print(rs == inf<int> ? -1 : rs);
  };
  slv1(ss, 0);
  slv1(nx, 1);
}

int main() {
  Yorisou();
  return 0;
}
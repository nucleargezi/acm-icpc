#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct dat {
  int x, y, c;
  string s;
  bool operator<(const dat &p) const {
    return len(s) == len(p.s) ? s < p.s : len(s) < len(p.s);
  }
  bool operator>(const dat &p) const {
    return len(s) == len(p.s) ? s > p.s : len(s) > len(p.s);
  }
};
constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
void Yorisou() {
  INT(N, M, K);
  int x = 0, y = 0;
  VEC(string, s, N);
  FOR(i, N) FOR(k, M) if (s[i][k] == 'S') x = i, y = k;
  min_heap<dat> q;
  q.push(dat{x, y, 0, ""});
  static set<int> se[50][50];
  static int ls[50][50];
  while (not q.empty()) {
    Z [i, k, c, str] = pop(q);
    FOR(d, 4) {
      int x = i + dx[d], y = k + dy[d];
      if (min(x, y) < 0 or x >= N or y >= M or s[x][y] == 'S') continue;
      if (s[x][y] == 'T') return print(str);
      int cc = c | 1 << (s[x][y] - 'a');
      if (pc(cc) > K or se[x][y].contains(cc)) continue;
      if (ls[x][y] and (ls[x][y] & cc) == ls[x][y]) continue;
      se[x][y].eb(ls[x][y] = cc);
      q.push(dat{x, y, cc, str + s[x][y]});
    }
  }
  print(-1);
}
#include "YRS/Z_H/main.hpp"
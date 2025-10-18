#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/flow/max_flow.hpp"
#include "YRS/flow/HLPP.hpp"

// #define tests
void Yorisou() {
  INT(K, N, M);
  VEC(PII, f, K);
  VEC(PII, t, K);
  for (Z &[x, y] : f) --x, --y;
  for (Z &[x, y] : t) --x, --y;

  Z id = [&](int i, int x, int y) -> int { return i * (N * M) + x * M + y; };

  Z check = [&](ll c) -> bool {
    int al = N * M * (c + 1);
    int S = al * 2, T = S + 1;
    HLPP<int, 2'200'000> FL(T + 1);
    FOR(i, c) {
      FOR(x, N) FOR(y, M) {
        static constexpr int dx[]{1, -1, 0, 0, 0}, dy[]{0, 0, 1, -1, 0};
        FOR(d, 5) {
          int xx = x + dx[d], yy = y + dy[d];
          if (xx < 0 or yy < 0 or xx >= N or yy >= M) continue;
          FL.add(id(i, x, y) + al, id(i + 1, xx, yy), 1);
        }
      }
    }
    FOR(i, c + 1) FOR(x, N) FOR(y, M) {
      FL.add(id(i, x, y), id(i, x, y) + al, 1);
    }
    for (Z [x, y] : t) FL.add(id(c, x, y) + al, T, 1);
    for (Z [x, y] : f) FL.add(S, id(0, x, y), 1);
    FL.build();
    return FL.flow(S, T) == K;
  };

  int c = binary_search(check, N * M * K, 0);
  print(c);

  int al = N * M * (c + 1);
  int S = al * 2, T = S + 1;
  max_flow<int> FL(T + 1, S, T);
  FOR(i, c) {
    FOR(x, N) FOR(y, M) {
      FL.add(id(i, x, y) + al, id(i + 1, x, y), 1);
      static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
      FOR(d, 4) {
        int xx = x + dx[d], yy = y + dy[d];
        if (xx < 0 or yy < 0 or xx >= N or yy >= M) continue;
        FL.add(id(i, x, y) + al, id(i + 1, xx, yy), 1);
      }
    }
  }
  FOR(i, c + 1) FOR(x, N) FOR(y, M) {
    FL.add(id(i, x, y), id(i, x, y) + al, 1);
  }
  for (Z [x, y] : f) FL.add(S, id(0, x, y), 1);
  for (Z [x, y] : t) FL.add(id(c, x, y) + al, T, 1);
  Z op = [&](int x, int y, int xx, int yy) -> char {
    if (x == xx and y == yy) return 'S';
    if (x > xx) return 'U';
    if (x < xx) return 'D';
    if (y > yy) return 'L';
    if (y < yy) return 'R';
    return 'P';
  };
  map<T3<int>, int> mp;
  FOR(i, K) mp[{0, f[i].fi, f[i].se}] = i;
  FL.flow();
  vector<string> pa(K);
  for (Z [fr, to, w] : sorted(FL.get_flow_edges())) {
    if (fr >= al and to != T and fr != S) {
      int d = (fr - al) / (N * M);
      fr %= N * M, to %= N * M;
      int x = fr / M, y = fr % M;
      int xx = to / M, yy = to % M;
      int id = mp[{d, x, y}];
      pa[id] += op(x, y, xx, yy);
      mp[{d + 1, xx, yy}] = id;
      t[id] = {xx, yy};
    }
  }
  FOR(i, K) {
    while (len(pa[i]) < c) pa[i] += 'P';
    f[i].fi++, f[i].se++;
    t[i].fi++, t[i].se++;
    print(f[i], t[i], pa[i]);
  }
}
#include "YRS/Z_H/main.hpp"
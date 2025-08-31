#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  LL(n, m, k);
  VEC(string, a, n);
  FOR(i, n) FOR(k, m) a[i][k] -= '0';
  const int N = n * m;
  vector<int> id(N, -1), st(m + 1);
  st[0] = 0;
  int cnt = 0;
  FOR(k, m) {
    FOR(i, n) {
      int I = i * m + k;
      if (not a[i][k] and id[I] == -1) {
        queue<int> q;
        q.emplace_back(I);
        id[I] = cnt;
        while (not q.empty()) {
          int f = q.pop();
          int x = f / m, y = f % m;
          if (x > 0 and not a[x - 1][y] and id[(x - 1) * m + y] == -1) {
            id[(x - 1) * m + y] = cnt;
            q.emplace_back((x - 1) * m + y);
          }
          if (x + 1 < n and not a[x + 1][y] and id[(x + 1) * m + y] == -1) {
            id[(x + 1) * m + y] = cnt;
            q.emplace_back((x + 1) * m + y);
          }
        }
        ++cnt;
      }
    }
    st[k + 1] = cnt;
  }
  vector<int> mxc(cnt);
  FOR_R(k, m) {
    FOR(i, st[k], st[k + 1]) mxc[i] = k;
    if (k + 1 < m) FOR(i, n) {
      if (not a[i][k] and not a[i][k + 1]) {
        chmax(mxc[id[i * m + k]], mxc[id[i * m + k + 1]]);
      }
    }
  }
  vector<u8> vs(N), vv(N);
  queue<int> q;
  q.emplace_back(0);
  vs[0] = 1;
  while (not q.empty()) {
    int f = q.pop();
    int x = f / m, y = f % m;
    if (x > 0) {
      int I = (x - 1) * m + y;
      if (not vs[I] and not a[x - 1][y]) {
        vs[I] = 1;
        q.emplace_back(I);
      }
    }
    if (x + 1 < n) {
      int I = (x + 1) * m + y;
      if (not vs[I] and not a[x + 1][y]) {
        vs[I] = 1;
        q.emplace_back(I);
      }
    }
    if (y + 1 < m) {
      int I = x * m + y + 1;
      if (not vs[I] and not a[x][y + 1]) {
        vs[I] = 1;
        q.emplace_back(I);
      }
    }
  }
  q.clear();
  q.emplace_back(m - 1);
  vv[m - 1] = 1;
  while (not q.empty()) {
    int f = q.pop();
    int x = f / m, y = f % m;
    if (x > 0) {
      int I = (x - 1) * m + y;
      if (not vv[I] and not a[x - 1][y]) {
        vv[I] = 1;
        q.emplace_back(I);
      }
    }
    if (x + 1 < n) {
      int I = (x + 1) * m + y;
      if (not vv[I] and not a[x + 1][y]) {
        vv[I] = 1;
        q.emplace_back(I);
      }
    }
    if (y) {
      int I = x * m + y - 1;
      if (not vv[I] and not a[x][y - 1]) {
        vv[I] = 1;
        q.emplace_back(I);
      }
    }
  }
  FOR(i, N) {
    int x = i / m, y = i % m;
    if (not a[x][y] and vs[i] and not vv[i]) {
      int mx = mxc[id[i]];
      if (y < m - k - 1 and mx >= y + k) iroha Yes();
      if (y > 0 and y < m - k and mx >= y + k - 1) iroha Yes();
    }
  }
  No();
}
#include "MeIoN_Lib/Z_H/main.hpp"
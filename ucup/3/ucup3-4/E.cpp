#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  if (~M & 1) {
    vector a(N, vector<int>(M));
    FOR(i, 0, N) {
      FOR(k, 0, M / 2) a[i][k] = i * M + k + 1;
      FOR(k, M / 2, M) a[i][k] = (N - i - 1) * M + k + 1;
    }
    Yes();
    FOR(i, 0, N) FOR(k, 0, M) cout << a[i][k] << " \n"[k + 1 == M];
    return;
  }
  if (N > 1 and M == 1) return No();
  if ((N & 1) and (M & 1)) {
    vector a(N, vector<int>(M));
    FOR(i, 0, N) a[i][0] = i + 1;
    vector<ll> s(N);
    iota(all(s), 1);
    FOR(i, 1, M - 1) {
      vector I = argsort(s);
      int l = i * N;
      FOR(k, 0, N) {
        int x = (l + N / 2 + k) % N;
        s[I[k]] += x;
        a[I[k]][i] = l + x + 1;
      }
    }
    vector I = argsort(s);
    FOR(i, 0, N) a[I[i]][M - 1] = N * M - i;
    Yes();
    FOR(i, 0, N) FOR(k, 0, M) cout << a[i][k] << " \n"[k + 1 == M];
    return;
  }
  No();
}
#include "YRS/Z_H/main.hpp"
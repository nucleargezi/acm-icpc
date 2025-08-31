#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  vector res(n, vector<int>(n, -1));
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < a[i]; ++k) 
      for (int j = 0; j < n; ++j) {
        if (res[i][j] == -1 and a[j] != k) {
          res[i][j] = k;
          break;
        }
      }
  for (int i = 0; i < n; ++i) {
    vector<u8> b(a[i]);
    for (int k = 0; k < n; ++k) {
      if (-1 < res[k][i] and res[k][i] < a[i]) b[res[k][i]] = 1;
    }
    for (int k = 0; k < a[i]; ++k) {
      if (not b[k]) {
        bool f = 0;
        for (int j = 0; j < n and not f; ++j) {
          if (res[j][i] == -1 and a[j] != k) {
            res[j][i] = k;
            f = 1;
          }
        }
        for (int j = 0; j < n and not f; ++j) {
          if (a[j] != k and not(-1 < res[j][i] and res[j][i] < a[j])) {
            res[j][i] = k;
            f = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      if (res[i][k] == -1) res[i][k] = 0;
      std::cout << res[i][k] << " \n"[k + 1 == n];
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"
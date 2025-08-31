#include <iostream>
#include <algorithm>
#include <numeric>

#include <vector>
#include <map>
#include <set>

#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::set, std::map;

using ll = long long;

int Q(int x, int y) {
  ++x, ++y;
  cout << "? " << x << ' ' << y << std::endl;
  int dis;
  cin >> dis;
  return dis;
}

void A(int x, int y) {
  ++x, ++y;
  cout << "! " << x << ' ' << y << std::endl;
  int r;
  cin >> r;
}

void yorisou() {
  int n;
  cin >> n;
  int a = 0, b = n / 2;
  int x = Q(a, b);
  if (n & 1) {
    while (x == n / 2) {
      if ((b - a + n) % n > n / 2)
        a = (a + 1) % n;
      else
        b = (b + 1) % n;
      x = Q(a, b);
    }
  } else {
    while (x == n / 2) {
      a = (a + 1) % n;
      b = (b + 1) % n;
      x = Q(a, b);
    }
  }
  int add = Q((a + 1) % n, b), sub = Q((a - 1 + n) % n, b);
  int s, t;
  if (add >= x and sub >= x) {
    s = a, t = x - 1;
  } else {
    bool f = sub < x;
    int l = 1, r = x;
    while (std::abs(r - l) > 1) {
      int m = (l + r) >> 1;
      if (Q(f ? (a + n - m) % n : (a + m) % n, b) == x - m) {
        l = m;
      } else {
        r = m;
      }
    }
    t = x - l - 1;
    s = f ? (a + n - l) % n : (a + l) % n;
  }
  if (Q(s, (b + t) % n) == 1) return A(s, (b + t) % n);
  A(s, (b + n - t) % n);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
}
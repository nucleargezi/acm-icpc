#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
constexpr string et[] {"-", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na",
    "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
    "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In",
    "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm",
    "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re",
    "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr",
    "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
    "Fm"};

void Yorisou() {
  INT(N, K);
  std::unordered_map<string, char> id;
  FOR(i, 1, 101) id[et[i]] = i;
  vector<int> a(N), b(K);
  FOR(i, N) {
    STR(s);
    a[i] = id[s];
  }
  FOR(i, K) {
    STR(s);
    b[i] = id[s];
  }
  vector sb = pre_sum(b);
  vector<int> v(1 << N);
  FOR(s, 1, 1 << N) {
    int x = lowbit(s);
    v[s] = v[s ^ (1 << x)] + a[x];
  }
  vector<int> dp(1 << N, -1);
  dp[0] = 0;
  Z check = [&](int s, int t) -> bool {
    s = v[s], t = v[t];
    if (t > sb[K]) return false;
    FOR(i, K + 1) if (s < sb[i] and sb[i] < t) return false;
    return true;
  };
  FOR(s, 1 << N) if (dp[s] != -1) {
    FOR(i, N) if (~s >> i & 1) {
      int t = 1 << i | s;
      if (check(s, t)) dp[t] = i;
    }
  }
  int x = -1;
  FOR(s, 1 << N) {
    if (dp[s] != -1 and v[s] == sb.back()) {
      x = s;
      break;
    }
  }
  if (x == -1) return NO();
  YES();
  vector<int> pa;
  while (x) {
    int i = dp[x];
    pa.ep(i);
    x -= 1 << i;
  }
  FOR(i, K) {
    int x = 0;
    vector<int> go;
    while (x != b[i]) {
      int i = pop(pa);
      go.ep(i);
      x += a[i];
    }
    string s;
    for (int i : go) s += et[a[i]] + '+';
    pop(s);
    s += "->" + et[b[i]];
    print(s);
  }
}
#include "YRS/Z_H/main.hpp"
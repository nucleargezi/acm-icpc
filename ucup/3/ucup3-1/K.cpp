#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define Z auto
#define all(x) (x).begin(), (x).end()

void yorisou() {
  string s;
  map<int, vector<int>> mp;
  while (std::getline(cin, s)) {
    s += ' ';
    bool f = 1;
    string t, F;
    for (char c : s) {
      if (c == ' ') {
        if (f) {
          f = 0;
          F = t;
        } else {
          mp[stoi(t)].emplace_back(stoi(F));
        }
        t.clear();
      } else {
        if (isdigit(c)) t += c;
      }
    }
  }
  for (Z &[s, v] : mp) {
    cout << "CS-" << s << ":";
    sort(all(v));
    for (bool f = 0; Z &s : v) {
      if (f) cout << ",";
      else f = 1;
      cout << " CS-" << s;
    }
    cout << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    yorisou();
  }
}
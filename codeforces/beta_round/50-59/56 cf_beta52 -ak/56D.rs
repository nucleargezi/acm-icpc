use std::io::{self, Read};
use std::str::FromStr;

fn yorisou() {
  let mut sc = Scanner::new();
  
  let s = sc.get_line().chars().collect::<Vec<_>>();
  let t = sc.get_line().chars().collect::<Vec<_>>();
  let n = s.len();
  let m = t.len();

  let mut dp = vec![vec![0usize; m + 1]; n + 1];
  let mut fa = vec![vec![0u8; m + 1]; n + 1];

  for i in 0..n + 1 {
    for k in 0..m + 1 {
      if i == 0 && k > 0 {
        dp[i][k] = dp[i][k - 1] + 1;
        fa[i][k] = 1;
      } else if i > 0 && k == 0 {
        dp[i][k] = dp[i - 1][k] + 1;
        fa[i][k] = 2;
      } else if i > 0 && k > 0 {
        dp[i][k] = dp[i - 1][k - 1] + (s[i - 1] != t[k - 1]) as usize;
        fa[i][k] = 0;
        if dp[i][k - 1] + 1 < dp[i][k] {
          dp[i][k] = dp[i][k - 1] + 1;
          fa[i][k] = 1;
        }
        if dp[i - 1][k] + 1 < dp[i][k] {
          dp[i][k] = dp[i - 1][k] + 1;
          fa[i][k] = 2;
        }
      }
    }
  }

  let mut os = Vec::new();
  let mut ot = Vec::new();
  let mut es = Vec::new();
  let mut et = Vec::new();
  let (mut i, mut k) = (n, m);
  while i > 0 || k > 0 {
    match fa[i][k] {
      0 => {
        i -= 1;
        k -= 1;
        os.push(i);
        ot.push(k);
      }
      1 => {
        k -= 1;
        et.push(k);
      }
      2 => {
        i -= 1;
        es.push(i);
      }
      _ => {}
    }
  }

  println!("{}", dp[n][m]);
  for x in &es {
    println!("DELETE {}", x + 1);
  }
  et.reverse();
  for x in &et {
    println!("INSERT {} {}", x + 1, t[*x]);
  }
  for i in 0..os.len() {
    if s[os[i]] != t[ot[i]] {
      println!("REPLACE {} {}", ot[i] + 1, t[ot[i]]);
    }
  }
}
fn main() {
  yorisou();
}

#[allow(warnings)]
type int = i32;
#[allow(warnings)]
type uint = u32;
#[allow(warnings)]
type ll = i64;
#[allow(warnings)]
type ull = u64;

struct Scanner {
  buffer: Vec<String>,
}
#[allow(dead_code)]
impl Scanner {
  fn new() -> Self {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let buffer = input
      .split_whitespace()
      .map(str::to_string)
      .collect::<Vec<_>>();
    Self { buffer }
  }

  fn next<T: FromStr>(&mut self) -> T {
    self
      .buffer
      .remove(0)
      .parse::<T>()
      .ok()
      .expect("Failed parse")
  }

  fn get_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
    (0..n).map(|_| self.next()).collect()
  }

  fn get_line(&mut self) -> String {
    self.buffer.remove(0).to_string()
  }

  fn get_char(&mut self) -> char {
    self.next::<String>().chars().next().unwrap()
  }

  fn get_pair<T: FromStr, U: FromStr>(&mut self) -> (T, U) {
    (self.next(), self.next())
  }
}

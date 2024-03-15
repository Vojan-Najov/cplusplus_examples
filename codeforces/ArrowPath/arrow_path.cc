#include <iostream>
#include <vector>
#include <set>

struct grid {
  grid(int n) : n(n), row1(n, 0), row2(n, 0)  {
    for (int i = 0; i < n; ++i) {
      std::cin >> row1[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> row2[i];
    }
  }
  void print(void) {
    for (int i = 0; i < n; ++i) {
      std::cout << row1[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < n; ++i) {
      std::cout << row2[i] << ' ';
    }
    std::cout << '\n';
  }
  bool sol(int row, int col, char c) {
    if (row < 0 || row > 1 || col < 0 || col >= n) {
      return false;
    }
    if (row == 1 && col == n -1) {
      return true;
    }
    if (c != 0) {
      if (row == 0) {
        c = row1[col];
      } else {
        c = row2[col];
      }
      switch (c) {
        case '>': col += 1; break;
        case '<': col -= 1; break;
      }
    }
    if (row == 1 && col == n -1) {
      return true;
    }
    if (visited.find(std::pair<int, int>{row, col}) != visited.end()) {
      return false;
    }
    visited.insert(std::pair<int, int>{row, col});

    if (sol(row, col-1, 1)) {
      return true;
    }
    if (sol(row, col+1, 1)) {
      return true;
    }
    if (sol(row+1, col, 1)) {
      return true;
    }
    if (sol(row-1, col, 1)) {
      return true;
    }
    
    return false;
  }
  int n;
  std::vector<char> row1;
  std::vector<char> row2;
  std::set<std::pair<int, int>> visited;
};

int main(void) {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n = 0;
    std::cin >> n;
    grid g(n);
    if (g.sol(0, 0, 0)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}

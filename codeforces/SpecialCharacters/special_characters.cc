#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n = 0;
    std::cin >> n;
    if (n % 2 != 0) {
      std::cout << "NO\n";
    } else {
      char c = 'A';
      std::cout << "YES\n";
      std::cout << c << c;
      ++c;
      n -= 2;
      while (n > 0) {
        std::cout << c << c;
        n -= 2;
         ++c;
      }
      std::cout << '\n';
    }
  }
}

#include <array>
#include <iostream>
#include <vector>

std::vector<std::vector<double>> multiplyMatrix(
    std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& B) {
  std::vector<std::vector<double>> C(A.size(),
                                     std::vector<double>(B[0].size()));
  for (size_t i = 0; i < A.size(); ++i) {
    for (size_t j = 0; j != A[i].size(); ++j) {
      C[i][j] = 0;
      for (size_t k = 0; k != B[0].size(); k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}
int main() {
  std::vector<std::vector<double>> A{
      {5, 2, 0, 10}, 
      {3, 4, 2, 5}, 
      {20, 0, 0, 0}};
  std::vector<std::vector<double>> B{
      {1.2, 0.5}, 
      {2.8, 0.4}, 
      {5.0, 1.0}, 
      {2.0, 1.5}};

  for (auto& i : multiplyMatrix(A, B)) {
    for (auto& j : i) std::cout << j << ' ';
    std::cout << '\n';
  }
}

#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
bool matrixIsNormal(std::vector<std::vector<T>> M) {
  if (M.size() == 0) return 0;
  for (auto& row : M) {
    if (row.size() != M[0].size()) {
      return 0;
    }
  }
  return 1;
}

template <typename T>
std::vector<std::vector<T>> multiplyMatrix(std::vector<std::vector<T>>& A,
                                           std::vector<std::vector<T>>& B) {
  std::vector<std::vector<T>> C(A.size(), std::vector<T>(B[0].size()));

  if (!matrixIsNormal(A) || !matrixIsNormal(B)) {
    throw std::invalid_argument("Одна из матриц некорректна\n");
  }

  if (A[0].size() != B.size()) {
    throw std::invalid_argument(
        "Число столбцов в первом множителе не равно числу строк во втором\n");
  }

  for (size_t i = 0; i != A.size(); ++i) {
    for (size_t k = 0; k != B[0].size(); ++k) {
      for (size_t j = 0; j != A[i].size(); ++j) {
        C[i][k] += A[i][j] * B[j][k];
      }
    }
  }
  return C;
}

int main() {
  std::vector<std::vector<double>> A{
      {5, 2, 0, 10}, 
      {3, 5, 2, 5}, 
      {20, 0, 0, 0}};
  std::vector<std::vector<double>> B{
      {1.2, 0.5}, 
      {2.8, 0.4}, 
      {5.0, 1.0}, 
      {2.0, 1.5}};

  try {
    std::vector<std::vector<double>> C = multiplyMatrix(A, B);
    for (auto& i : C) {
      for (auto& j : i) std::cout << j << '\t';
      std::cout << '\n';
    }

  } catch (std::exception& e) {
    std::cout << e.what();
  }
}

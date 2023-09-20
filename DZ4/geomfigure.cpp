#include <iostream>
#include <string>

double triangle() {
  double a, h;
  std::cout << "Введите высоту: ";
  std::cin >> h;
  std::cout << "Введите основание, к которому проведена высота: ";
  std::cin >> a;
  return (a <= 0 || h <= 0) ? -1 : (0.5 * a * h);
}
double rectangle() {
  double a, b;
  std::cout << "Введите длину: ";
  std::cin >> a;
  std::cout << "Введите ширину: ";
  std::cin >> b;
  return (a <= 0 || b <= 0) ? -1 : (a * b);
}
double circle() {
  double R;
  std::cout << "Введите радиус: ";
  std::cin >> R;
  return (R <= 0) ? -1 : (R * 3.14);
}

int SquareFigure() {
  int t;
  double S;
  std::string name;
  std::cout << "1.Прямоугольник\n2.Треугольник\n3.Круг\nВведите номер: ";
  std::cin >> t;
  switch (t) {
    case 2:
      S = triangle();
      name = "Треугольника = ";
      break;
    case 3:
      S = circle();
      name = "Круга = ";
      break;
    default:
      S = rectangle();
      name = "Прямоугольника = ";
      break;
  }

  if (S == -1) {
    std::cout << name << "не существует\n\n";
    return 0;
  }
  std::cout << "Площадь " << name << S << "\n\n";
  return 0;
}

int main() {
  while (true) SquareFigure();
}
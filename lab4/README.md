# Лабораторная работа №4

## Задание

Реализовать структуры данных Разреженный вектор и Разреженная матрица и операции над ними.

## Решение

### Разреженный вектор

Вектор представляется в виде отображения {индекс -> значение} для всех ненулевых значений.

Сложность алгоритмов следующая:
- Сложение и умножение со скаляром: `O(X)`, где X - кол-во ненулевых значений, X
- Сложение с вектором: `O(X + Y)`, где X и Y - кол-ва ненулевых значений первого и второго векторов соответственно
- Скалярное произведение с вектором: `O(X)`, где X - кол-во ненулевых значений первого вектора

Представлен в файле [SparseVector.hpp](SparseVector.hpp)

### Разреженная матрица

Матрица представляется в виде отображения {(строка, столбец) -> значение} для всех ненулевых ячеек.

Сложность алгоритмов следующая:
- Сложение и умножение со скаляром: `O(X)`, где X - кол-во ненулевых значений, X
- Сложение с матрицей: `O(X + Y)`, где X и Y - кол-ва ненулевых значений первой и второй матриц соответственно
- Произведение с матрицей: `O(A * B * C)`, где AxB и BxC - размеры матриц

Представлена в файле [SparseMatrix.hpp](SparseMatrix.hpp)

## Выводы

- Разреженный вектор работает эффективнее обычного вектора при работе со скалярами и скалярным произведением, однако может быть медленнее в случае сложения двух разреженных векторов
- Разреженная матрица эффективно работает со скалярами и сложением с разреженной матрицей, но при умножении ничем не выигрывает у обычной. Для более эффективной реалзации понадобилось бы хранить больше данных о строках и столбцах, чтобы можно было использовать преимущества разреженных векторов для матричных вычислений
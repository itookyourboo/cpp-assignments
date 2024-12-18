#include <unordered_map>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <iostream>

#include <utility>
#include <functional>


struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ (hash2 << 1);
    }
};


template <typename T>
class SparseMatrix {
public:
    std::unordered_map<std::pair<int, int>, T, PairHash> data;
    int rows, cols;

    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    void set(int row, int col, T value) {
        auto pair = std::make_pair(row, col);
        if (value != 0) {
            data[pair] = value;
        } else {
            data.erase(pair);
        }
    }

    T get(int row, int col) const {
        auto it = data.find(std::make_pair(row, col));
        return (it != data.end()) ? it->second : 0;
    }

    SparseMatrix<T> operator+(SparseMatrix<T>& other) {
        SparseMatrix<T> result(rows, cols);
        for (const auto& [position, value] : data) {
            result.set(position.first, position.second, value + other.get(position.first, position.second));
        }
        for (const auto& [position, value] : other.data) {
            result.set(position.first, position.second, value + get(position.first, position.second));
        }
        return result;
    }

    SparseMatrix<T> operator*(SparseMatrix<T>& other) {
        SparseMatrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int res = 0;
                for (int k = 0; k < cols; k++) {
                    res += get(i, k) * other.get(k, j);
                }
                result.set(i, j, res);
            }
        }
        return result;
    }

    SparseMatrix<T> operator+(const T& scalar) {
        SparseMatrix<T> result(rows, cols);
        for (const auto& [position, value] : data) {
            result.set(position.first, position.second, value + scalar);
        }
        return result;
    }

    SparseMatrix<T> operator*(const T& scalar) {
        SparseMatrix<T> result(rows, cols);
        for (const auto& [position, value] : data) {
            result.set(position.first, position.second, value * scalar);
        }
        return result;
    }

    SparseMatrix<T> operator^(const T& scalar) {
        SparseMatrix<T> result(rows, cols);
        for (const auto& [position, value] : data) {
            result.set(position.first, position.second, pow(value, scalar));
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<T>& matrix) {
      for (size_t i = 0; i < matrix.rows; i++) {
        for (size_t j = 0; j < matrix.cols; j++) {
          os << matrix.get(i, j) << " ";
        }
        os << std::endl;
      }

      return os;
    }

    SparseMatrix<T> transpose() {
        SparseMatrix<T> result(cols, rows);
        for (const auto& [position, value] : data) {
            result.set(position.second, position.first, value);
        }
        return result;
    }

    SparseMatrix<T> power(const T& scalar) {
        SparseMatrix<T> result = *this;
        for (int i = 1; i < scalar; i++) {
            result = result * *this;
        }
        return result;
    }
};
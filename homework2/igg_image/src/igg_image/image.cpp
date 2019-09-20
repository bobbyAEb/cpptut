#include "image.h"

using namespace igg;

Image::Image() {}
Image::Image(int rows, int cols) : rows_{rows}, cols_{cols} {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      data_.push_back(0)
    }
  }
}
int Image::rows() const { return rows_ }
int Image::cols() const { return cols_ }
int Image::at(const int row, const int col) const {
  return data_.at(row * cols_ + col)
}
int Image::at(const int row, const int col) {
  return data_.at(row * cols_ + col)
}

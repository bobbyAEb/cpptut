#pragma once

#include <vector>

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
  Image();
  Image(int rows, int cols);
  int rows() const;
  int cols() const;
  int at(const int row, const int col) const;
  int at(const int row, const int col);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg

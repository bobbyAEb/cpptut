#include "mat.h"

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::stringstream;

template <typename T>
ostream& operator<<(ostream& os, const Mat<T>& m) {
  m.CoutMat(os);
  return os;
}

template <typename T>
istream& operator>>(istream& is, Mat<T>& m) {
  m.CinMat(is);
  return is;
}

// +
template <typename T>
const Mat<T> operator+(const Mat<T>& m1, const Mat<T>& m2) {
  Mat<T> t(m1);
  t += m2;
  return t;
}

// -
template <typename T>
const Mat<T> operator-(const Mat<T>& m1, const Mat<T>& m2) {
  Mat<T> t(m1);
  t -= m2;
  return t;
}

// print mat
template <typename T>
void Mat<T>::CoutMat(std::ostream& os) const {
  if (vdata.empty()) return;
  for (size_t i = 0; i < vdata.size(); i++) {
    for (size_t j = 0; j < vdata[0].size(); j++) {
      os << vdata[i][j] << " ";
    }
    os << std::endl;
  }
  os << std::endl;
}

template <typename T>
void Mat<T>::CinMat(std::istream& is) {
  if (vdata.empty()) return;
  for (size_t i = 0; i < vdata.size(); i++) {
    for (size_t j = 0; j < vdata[0].size(); j++) {
      is >> vdata[i][j];
    }
  }
}

// construct
template <typename T>
Mat<T>::Mat() {
  cout << "default constructor" << endl;
  vdata.clear();
}

template <typename T>
Mat<T>::Mat(size_t i, size_t j) {
  std::vector<std::vector<T>> tdata(i, std::vector<T>(j, 0));
  vdata = std::move(tdata);
}

// copy constructor
template <typename T>
Mat<T>::Mat(const Mat<T>& m) {
  cout << "copy constructor" << endl;
  vdata.assign(m.vdata.cbegin(), m.vdata.cend());
}

// copy assignment
template <typename T>
Mat<T>& Mat<T>::operator=(const Mat<T>& m) {
  cout << "copy assignment" << endl;
  if (this != &m) {
    vdata.assign(m.vdata.cbegin(), m.vdata.cend());
  }
  return *this;
}

// move constructor
template <typename T>
Mat<T>::Mat(Mat<T>&& m) {
  cout << "move constructor" << endl;
  vdata = std::move(m.vdata);
}

// move assignment
template <typename T>
Mat<T>& Mat<T>::operator=(Mat<T>&& m) {
  cout << "move assignment" << endl;
  if (this != &m) {
    vdata.clear();
    vdata = std::move(m.vdata);
  }
  return *this;
}

// destructor
template <typename T>
Mat<T>::~Mat() {
  vdata.clear();
}

// access element value
template <typename T>
inline T& Mat<T>::operator()(size_t i, size_t j) {
  assert(!vdata.empty());
  assert(i >= 0 && j >= 0 && i < vdata.size() && j < vdata[0].size());
  return vdata[i][j];
}
template <typename T>
inline const T& Mat<T>::operator()(size_t i, size_t j) const {
  assert(!vdata.empty());
  assert(i >= 0 && j >= 0 && i < vdata.size() && j < vdata[0].size());
  return vdata[i][j];
}

// +=
template <typename T>
Mat<T>& Mat<T>::operator+=(const Mat<T>& m) {
  if (vdata.empty() || m.vdata.empty()) return *this;

  const size_t row = vdata.size();
  const size_t col = vdata[0].size();
  const size_t mrow = m.vdata.size();
  const size_t mcol = m.vdata[0].size();

  if (row == mrow && col == mcol) {
    for (size_t i = 0; i < row; i++)
      for (size_t j = 0; j < col; j++) vdata[i][j] += m.vdata[i][j];
  } else {
    std::cerr << "mat must be the same size." << std::endl;
  }

  return *this;
}

// -=
template <typename T>
Mat<T>& Mat<T>::operator-=(const Mat<T>& m) {
  if (vdata.empty() || m.vdata.empty()) return *this;

  const size_t row = vdata.size();
  const size_t col = vdata[0].size();
  const size_t mrow = m.vdata.size();
  const size_t mcol = m.vdata[0].size();

  if (row == mrow && col == mcol) {
    for (size_t i = 0; i < row; i++)
      for (size_t j = 0; j < col; j++) vdata[i][j] -= m.vdata[i][j];
  } else {
    std::cerr << "mat must be the same size." << std::endl;
  }

  return *this;
}

// resize
template <typename T>
void Mat<T>::resize(size_t nr, size_t nc) {
  vdata.resize(nr);
  for (size_t i = 0; i < nr; i++) {
    vdata[i].resize(nc);
  }
}

// test Mat class
typedef double Type;
int main() {
  Mat<Type> mat1(3, 4);
  Mat<Type> mat2(3, 4);

  for (size_t i = 0; i < mat1.rows(); i++) {
    for (size_t j = 0; j < mat1.cols(); j++) {
      mat1(i, j) = i * mat1.cols() + j;
      mat2(i, j) = 2 * i * mat1.cols() + 2 * j;
    }
  }

  std::cout << "mat1: " << std::endl << mat1;
  std::cout << "mat2: " << std::endl << mat2;

  Mat<Type> mat3 = (mat2 + mat1);
  std::cout << "mat3 = mat2 + mat1: " << std::endl << mat3;

  Mat<Type> mat4 = (mat3 + mat2 - mat1);
  std::cout << "mat4 = mat3 + mat2 - mat1: " << std::endl << mat4;

  stringstream ss;
  ss << mat1;
  ss >> mat4;
  std::cout << "mat4:" << std::endl << mat4;

  const Mat<Type> mat6(mat4);
  std::cout << "const mat6:" << std::endl << mat6;
  cout << mat6(0, 0) << " " << mat6.rows() << " " << mat6.cols() << endl;

  Mat<Type> mat7;
  mat7 = std::move(mat1);
  std::cout << "mat1: " << std::endl << mat1;
  std::cout << "mat7: " << std::endl << mat7;

  mat7.resize(2, 3);
  std::cout << "mat7.resize(2, 3): " << std::endl << mat7;

  mat7.resize(4, 6);
  std::cout << "mat7.resize(4, 6): " << std::endl << mat7;

  Mat<Type> mat8;
  cout << " " << mat8.rows() << " " << mat8.cols() << endl;
  // this will cause assertion error since mat8 is empty
  // cout<<mat8(0,0)<<endl;
  return 1;
}

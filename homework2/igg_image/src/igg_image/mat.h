// 刚开始的时候，我是用 int* 来存储的数据，用int*
// 不方便的一个地方就是需要自己来管理内存，在实现一些
// 复制赋值和移动操作时都需要很小心处理，来管理内存，稍有不慎就会出问题。所以我后来改用C++标准容器
// vector 了。这样就不用自己来管理内存了。 另外，像 + 、-
// 这样两边的数可以互换位置的操作符，重载时最好用非成员函数来重载，而且像 +=、
// -= 这样的复合操作符，必须要用成员函数来重载。另外，可以用 +=、-=
// 来实现非成员函数的 + 、-
// 操作。最后要强调的是，非成员的运算符重载函数（+，-，，/）之类，返回类型应该是
// const 类型，避免类似 a b = c 这样的语句通过编译。
// 像输出(<<)、输入(>>)运算符，需要用非成员函数来重载，一般还要声明为友元函数。不过可以通过成员函数完成输入输出操作，非成员函数来重载、调用成员函数输入输出来避免声明友元函数，后面一个例子就是这样实现的。
// 最后要强调的一点就是针对const对象，需要有对应的const版本的函数，具体说来，就是对一些不改变类类型的变量成员函数，尽量声明为const类型，这样const对象也能调用这些函数。在返回矩阵数据时，需要针对const
// 和 非const的对象，实现两个函数。
// 需要说明的是，当把数据存储从指针改为vector之后，也就不需要单独记录矩阵的行和列了，这些信息都蕴含在vector之中了。要注意的是，在使用取元素下标
// [ ] 的时候，需要确保vector不为空。否则就会出现 vector out of range 的错误

#ifndef _MAT_H_
#define _MAT_H_

#include <cassert>
#include <cstring>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

// implement Mat class in c++

template <typename T>
class Mat {
 public:
  typedef T value_type;

  // construct
  Mat();
  Mat(size_t i, size_t j);

  ////copy constructor
  Mat(const Mat& m);

  ////copy assignment
  Mat& operator=(const Mat& m);

  // +=
  Mat& operator+=(const Mat& m);

  // -=
  Mat& operator-=(const Mat& m);

  // move constructor
  Mat(Mat&& m);

  // move assignment
  Mat& operator=(Mat&& m);

  // destructor
  ~Mat();

  // access element value
  T& operator()(size_t i, size_t j);
  const T& operator()(size_t i, size_t j) const;

  // get row and col number
  const size_t rows() const { return vdata.size(); }
  const size_t cols() const {
    if (vdata.empty())
      return 0;
    else
      return vdata[0].size();
  }

  // resize
  void resize(size_t nr, size_t nc);

  // print mat
  void CoutMat(std::ostream& os) const;
  void CinMat(std::istream& is);

 private:
  std::vector<std::vector<T>> vdata;
};

#endif

// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <string>

namespace dumb {

class Writer {
 public:
  Writer() {}
  Writer(int number_to_write) : number_to_write_{number_to_write} {}

  void InitWithRandomNumber();

  bool InitNumberFromFile(const std::string& path);
  bool WriteStoredNumberToFile(const std::string& path) const;

  int number_to_write() const { return number_to_write_; }

 private:
  int number_to_write_ = 0;
};

}  // namespace dumb

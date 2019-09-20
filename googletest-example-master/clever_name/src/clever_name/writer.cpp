// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include "clever_name/writer.h"

#include <fstream>
#include <iostream>

#include "clever_name/randomization.h"

namespace dumb {

void Writer::InitWithRandomNumber() {
  number_to_write_ = clever::GetXkcdRandomNumber();
}

bool Writer::InitNumberFromFile(const std::string& path) {
  std::ifstream input(path);
  if (!input) {
    std::cerr << "Failed to read from file '" << path << "'.\n";
    return false;
  }
  input >> number_to_write_;
  return true;
}

bool Writer::WriteStoredNumberToFile(const std::string& path) const {
  std::ofstream output(path);
  if (!output) {
    std::cerr << "Failed to write to file '" << path << "'.\n";
    return false;
  }
  output << number_to_write_;
  return true;
}

}  // namespace dumb

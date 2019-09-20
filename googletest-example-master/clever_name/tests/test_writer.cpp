#include <gtest/gtest.h>
#include "clever_name/writer.h"

using namespace dumb;

TEST(TestWriter, InitEmpty) {
  Writer writer;
  EXPECT_EQ(0, writer.number_to_write());
}

TEST(TestWriter, InitFromNumber) {
  Writer writer(10);
  EXPECT_EQ(10, writer.number_to_write());

  Writer writer_2(-42);
  EXPECT_EQ(-42, writer_2.number_to_write());
}

TEST(TestWriter, InitFromFile) {
  Writer writer;
  EXPECT_EQ(0, writer.number_to_write());
  writer.InitNumberFromFile("../../tests/data/meaning_of_life.txt");
  EXPECT_EQ(42, writer.number_to_write());
}

TEST(TestWriter, InitFromFileFail) {
  Writer writer;
  EXPECT_EQ(0, writer.number_to_write());
  writer.InitNumberFromFile("non_existing");
  EXPECT_EQ(0, writer.number_to_write());
}

TEST(TestWriter, ReadWrite) {
  Writer writer(42);
  EXPECT_EQ(42, writer.number_to_write());
  writer.WriteStoredNumberToFile("42.txt");
  Writer other;
  EXPECT_EQ(0, other.number_to_write());
  other.InitNumberFromFile("42.txt");
  EXPECT_EQ(42, other.number_to_write());
}

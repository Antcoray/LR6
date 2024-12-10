#include <gtest/gtest.h>

#include <iostream>

bool checkForEquality(char c, int h = 13) {
  char PossibleValues[13] = {'0', '1', '2', '3', '4', '5', '6',
                             '7', '8', '9', '.', '+', '-'};
  for (int i = 0; i < h; ++i) {
    if (PossibleValues[i] == c) {
      return true;
    }
  }
  return false;
}

bool findNumber(char* Number, char* input, int index, int& counterForNumber,
                int& last_i) {
  bool NumberFound = false;
  bool dotFound = false;

  for (int i = last_i; i <= index; ++i) {
    last_i = i;
    // если символ это +-. 0...9 то присваиваем число эл массива и (*)
    // проверяем следующее на 0...9 или '.'
    if (checkForEquality(input[i])) {
      // если '.' это первый символ то скипаем итерацию
      if (input[i] == '.' && counterForNumber == 0) {
        NumberFound = false;
        continue;
      }
      // если '0' это первый символ и за ним не следует '.' то скипаем
      // итерацию (чтобы избежать чисел вида 0234)
      if (input[i] == '0' && counterForNumber == 0 && input[i + 1] != '.') {
        NumberFound = false;
        continue;
      }
      // если '+' или '-' это первый символ и за ним следует число то скипаем
      // итерацию (чтобы избежать чисел вида +.2)
      if ((input[i] == '+' || input[i] == '-') && counterForNumber == 0 &&
          !checkForEquality(input[i + 1], 10)) {
        NumberFound = false;
        continue;
      }
      // проверка что в числе всего одна '.'
      if (input[i] == '.' && dotFound) {
        ++last_i;
        // NumberFound = false;
        break;
      }
      // проверка что после первой '.' идет число, если нет то прекращаем цикл
      // и обнуляем массив
      if (input[i] == '.' && !checkForEquality(input[i + 1], 10)) {
        for (int k = 0; k < counterForNumber; ++k) {
          Number[k] = '\0';
        }
        ++last_i;
        NumberFound = false;
        break;
      }
      // проверка что + - . встретились в числе
      if (input[i] == '.') {
        dotFound = true;
      }
      // присваиваем эл массива число
      Number[counterForNumber] = input[i];
      ++counterForNumber;
      NumberFound = true;
      // если в числе нет '.' то обнуляем массив
      if (!checkForEquality(input[i + 1], 11) && dotFound == false) {
        for (int k = 0; k < counterForNumber; ++k) {
          Number[k] = '\0';
        }
        NumberFound = false;
      }
      // если следующее число не является 0...9 или '.' то прекращаем цикл (*)
      if (checkForEquality(input[i + 1], 11)) {
        continue;
      } else {
        ++last_i;
        --counterForNumber;
        break;
      }
    }
  }
  return NumberFound;
}

// 1) input: "6.7" output: "6.7"
TEST(Tests, OneNumberInput) {
  bool NumberFound = false;
  int index = 2;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  //
  input[0] = '6';
  input[1] = '.';
  input[2] = '7';
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == index) {
      ASSERT_EQ(Number[0], '6');
      ASSERT_EQ(Number[1], '.');
      ASSERT_EQ(Number[2], '7');
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 2) input: "6.7, 7.8" output: "6.7" \n "7.8"
TEST(Tests, a_comma_b) {
  bool NumberFound = false;
  int index = 7;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  //
  input[0] = '6';
  input[1] = '.';
  input[2] = '7';
  input[3] = ',';
  input[4] = ' ';
  input[5] = '7';
  input[6] = '.';
  input[7] = '8';
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 2) {
      EXPECT_TRUE(Number[0] == '6');
      EXPECT_TRUE(Number[1] == '.');
      EXPECT_TRUE(Number[2] == '7');
    }
    if (last_i == 7) {
      EXPECT_TRUE(Number[0] == '7');
      EXPECT_TRUE(Number[1] == '.');
      EXPECT_TRUE(Number[2] == '8');
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 3) input: "r55a89.90N00000d82..2o64444.1mT3XT" output: "89.90" \n "64444.1"
TEST(Tests, RandomText) {
  bool NumberFound = false;
  int index = 32;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = 'r';
  input[1] = '5';
  input[2] = '5';
  input[3] = 'a';
  input[4] = '8';
  input[5] = '9';
  input[6] = '.';
  input[7] = '9';
  input[8] = '0';
  input[9] = 'N';
  input[10] = '0';
  input[11] = '0';
  input[12] = '0';
  input[13] = '0';
  input[14] = '0';
  input[15] = 'd';
  input[16] = '8';
  input[16] = '2';
  input[17] = '.';
  input[18] = '.';
  input[19] = '2';
  input[20] = 'o';
  input[21] = '6';
  input[22] = '4';
  input[23] = '4';
  input[24] = '4';
  input[25] = '4';
  input[26] = '.';
  input[27] = '1';
  input[28] = 'm';
  input[29] = 'T';
  input[30] = '3';
  input[31] = 'X';
  input[32] = 'T';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 8) {
      EXPECT_TRUE(Number[0] == '8');
      EXPECT_TRUE(Number[1] == '9');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '9');
      EXPECT_TRUE(Number[4] == '0');
    }
    if (last_i == 27) {
      ASSERT_EQ(Number[0], '6');
      ASSERT_EQ(Number[1], '4');
      ASSERT_EQ(Number[2], '4');
      ASSERT_EQ(Number[3], '4');
      ASSERT_EQ(Number[4], '4');
      ASSERT_EQ(Number[5], '.');
      ASSERT_EQ(Number[6], '1');
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 4) input: "r55a89.90N00000d82..2o64444.1mT3XT" cycled for 80 symbols output:
// "89.90" \n "64444.1"
TEST(Tests, RandomTextOf80Symbols) {
  bool NumberFound = false;
  int index = 80;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = 'r';
  input[1] = '5';
  input[2] = '5';
  input[3] = 'a';
  input[4] = '8';
  input[5] = '9';
  input[6] = '.';
  input[7] = '9';
  input[8] = '0';  // 8
  input[9] = 'N';
  input[10] = '0';
  input[11] = '0';
  input[12] = '0';
  input[13] = '0';
  input[14] = '0';
  input[15] = 'd';
  input[16] = '8';
  input[16] = '2';
  input[17] = '.';
  input[18] = '.';
  input[19] = '2';
  input[20] = 'o';
  input[21] = '6';
  input[22] = '4';
  input[23] = '4';
  input[24] = '4';
  input[25] = '4';
  input[26] = '.';
  input[27] = '1';  // 27
  input[28] = 'm';
  input[29] = 'T';
  input[30] = '3';
  input[31] = 'X';
  input[32] = 'T';
  input[33] = 'r';
  input[34] = '5';
  input[35] = '5';
  input[36] = 'a';
  input[37] = '8';
  input[38] = '9';
  input[39] = '.';
  input[40] = '9';
  input[41] = '0';  // 41
  input[42] = 'N';
  input[43] = '0';
  input[44] = '0';
  input[45] = '0';
  input[46] = '0';
  input[47] = '0';
  input[48] = 'd';
  input[49] = '8';
  input[50] = '2';
  input[51] = '.';
  input[52] = '.';
  input[53] = '2';
  input[54] = 'o';
  input[55] = '6';
  input[56] = '4';
  input[57] = '4';
  input[58] = '4';
  input[59] = '4';
  input[60] = '.';
  input[61] = '1';  // 61
  input[62] = 'm';
  input[63] = 'T';
  input[64] = '3';
  input[65] = 'X';
  input[66] = 'T';
  input[67] = 'r';
  input[68] = '5';
  input[69] = '5';
  input[70] = 'a';
  input[71] = '8';
  input[72] = '9';
  input[73] = '.';
  input[74] = '9';
  input[75] = '0';  // 75
  input[76] = 'N';
  input[77] = '0';
  input[78] = '1';
  input[79] = '.';
  input[80] = '0';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 8) {
      EXPECT_TRUE(Number[0] == '8');
      EXPECT_TRUE(Number[1] == '9');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '9');
      EXPECT_TRUE(Number[4] == '0');
    }
    if (last_i == 27) {
      ASSERT_EQ(Number[0], '6');
      ASSERT_EQ(Number[1], '4');
      ASSERT_EQ(Number[2], '4');
      ASSERT_EQ(Number[3], '4');
      ASSERT_EQ(Number[4], '4');
      ASSERT_EQ(Number[5], '.');
      ASSERT_EQ(Number[6], '1');
    }
    if (last_i == 41) {
      EXPECT_TRUE(Number[0] == '8');
      EXPECT_TRUE(Number[1] == '9');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '9');
      EXPECT_TRUE(Number[4] == '0');
    }
    if (last_i == 61) {
      ASSERT_EQ(Number[0], '6');
      ASSERT_EQ(Number[1], '4');
      ASSERT_EQ(Number[2], '4');
      ASSERT_EQ(Number[3], '4');
      ASSERT_EQ(Number[4], '4');
      ASSERT_EQ(Number[5], '.');
      ASSERT_EQ(Number[6], '1');
    }
    if (last_i == 75) {
      EXPECT_TRUE(Number[0] == '8');
      EXPECT_TRUE(Number[1] == '9');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '9');
      EXPECT_TRUE(Number[4] == '0');
    }
    if (last_i == 80) {
      ASSERT_EQ(Number[0], '1');
      ASSERT_EQ(Number[1], '.');
      ASSERT_EQ(Number[2], '0');
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 5) input: "\n" output: no output
TEST(Tests, EmptyInput) {
  bool NumberFound = false;
  int index = 0;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = '\n';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 0) {
      ASSERT_FALSE(checkForEquality(input[0]));
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 6) input: "+6.7, -7.8" output: "6.7" \n "7.8"
TEST(Tests, plusA_comma_minusB) {
  bool NumberFound = false;
  int index = 11;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  //
  input[1] = '+';
  input[2] = '6';
  input[3] = '.';
  input[4] = '7';
  input[5] = ',';
  input[6] = ',';
  input[7] = ' ';
  input[8] = '+';
  input[9] = '7';
  input[10] = '.';
  input[11] = '8';
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 3) {
      EXPECT_TRUE(Number[0] == '+');
      EXPECT_TRUE(Number[1] == '6');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '7');
    }
    if (last_i == 8) {
      EXPECT_TRUE(Number[0] == '-');
      EXPECT_TRUE(Number[1] == '7');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '8');
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 7) input: "r55a-9.90N00000d82..2o++444.1mT3XT" output: "-9.90" \n "+444.1"
TEST(Tests, RandomTextWithPlusesAndminuses) {
  bool NumberFound = false;
  int index = 32;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = 'r';
  input[1] = '5';
  input[2] = '5';
  input[3] = 'a';
  input[4] = '-';
  input[5] = '9';
  input[6] = '.';
  input[7] = '9';
  input[8] = '0';
  input[9] = 'N';
  input[10] = '+';
  input[11] = '+';
  input[12] = '0';
  input[13] = '0';
  input[14] = '0';
  input[15] = 'd';
  input[16] = '8';
  input[16] = '2';
  input[17] = '.';
  input[18] = '.';
  input[19] = '2';
  input[20] = 'o';
  input[21] = '+';
  input[22] = '+';
  input[23] = '4';
  input[24] = '4';
  input[25] = '4';
  input[26] = '.';
  input[27] = '1';
  input[28] = 'm';
  input[29] = '-';
  input[30] = '3';
  input[31] = 'X';
  input[32] = 'T';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 8) {
      EXPECT_TRUE(Number[0] == '-');
      EXPECT_TRUE(Number[1] == '9');
      EXPECT_TRUE(Number[2] == '.');
      EXPECT_TRUE(Number[3] == '9');
      EXPECT_TRUE(Number[4] == '0');
    }
    if (last_i == 27) {
      ASSERT_EQ(Number[0], '+');
      ASSERT_EQ(Number[1], '4');
      ASSERT_EQ(Number[2], '4');
      ASSERT_EQ(Number[3], '4');
      ASSERT_EQ(Number[4], '.');
      ASSERT_EQ(Number[5], '1');
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 8)
TEST(Tests, NumDotMinus) {
  bool NumberFound = false;
  int index = 4;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = '1';
  input[1] = '1';
  input[2] = '1';
  input[3] = '.';
  input[4] = '-';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 4) {
      ASSERT_FALSE(NumberFound);
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 9)
TEST(Tests, ZeroNum) {
  bool NumberFound = false;
  int index = 4;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = '0';
  input[1] = '1';
  input[2] = '1';
  input[3] = '2';
  input[4] = '3';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 4) {
      ASSERT_FALSE(NumberFound);
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

// 10)
TEST(Tests, SignedInt) {
  bool NumberFound = false;
  int index = 4;
  int counterForNumber = 0;
  int last_i = 0;
  char* input = new char[81];
  // input
  input[0] = '+';
  input[1] = '1';
  input[2] = '1';
  input[3] = '2';
  input[4] = '3';
  //
  char* Number = new char[81];
  do {
    NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
    counterForNumber = 0;
    if (last_i == 4) {
      ASSERT_FALSE(NumberFound);
    }
  } while (last_i < index);
  delete[] input;
  delete[] Number;
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
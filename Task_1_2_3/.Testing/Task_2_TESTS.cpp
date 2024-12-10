#include <gtest/gtest.h>

#include <iostream>
bool checkForEquality(char c, int h = 53) {
  const char PossibleValues[53] = {
      ' ', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd',
      'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q',
      'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G',
      'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
  for (int i = 0; i < h; ++i) {
    if (PossibleValues[i] == c) {
      return true;
    }
  }
  return false;
}

char* DeleteNonText(char* input, int index, int& CounterforNewText) {
  char* NewText = new char[index + 1];
  for (int i = 0; i <= index; ++i) {
    if (checkForEquality(input[i])) {
      NewText[CounterforNewText] = input[i];
      ++CounterforNewText;
    }
  }
  --CounterforNewText;
  return NewText;
}

// 1) no changes
TEST(Tests, sameSymbol) {
  int index = 3;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = 'q';
  input[1] = 'w';
  input[2] = 'e';
  input[3] = 'r';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'q');
  ASSERT_EQ(NewText[1], 'w');
  ASSERT_EQ(NewText[2], 'e');
  ASSERT_EQ(NewText[3], 'r');
  delete[] NewText;
  delete[] input;
}

// 2) no changes caps
TEST(Tests, caps) {
  int index = 3;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = 'Q';
  input[1] = 'Q';
  input[2] = 'Q';
  input[3] = 'Q';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'Q');
  ASSERT_EQ(NewText[1], 'Q');
  ASSERT_EQ(NewText[2], 'Q');
  ASSERT_EQ(NewText[3], 'Q');
  delete[] NewText;
  delete[] input;
}

// 3) no changes mixed
TEST(Tests, mixed) {
  int index = 3;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = 'Q';
  input[1] = 'q';
  input[2] = 'Q';
  input[3] = 'q';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'Q');
  ASSERT_EQ(NewText[1], 'q');
  ASSERT_EQ(NewText[2], 'Q');
  ASSERT_EQ(NewText[3], 'q');
  delete[] NewText;
  delete[] input;
}

// 4) no changes mixed2
TEST(Tests, mixed2) {
  int index = 3;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = 'Q';
  input[1] = 'q';
  input[2] = 'q';
  input[3] = 'Q';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'Q');
  ASSERT_EQ(NewText[1], 'q');
  ASSERT_EQ(NewText[2], 'q');
  ASSERT_EQ(NewText[3], 'Q');
  delete[] NewText;
  delete[] input;
}

// 5) one change %
TEST(Tests, OneOddSymbol) {
  int index = 3;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = 'l';
  input[1] = '%';
  input[2] = 'h';
  input[3] = 'Q';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'l');
  ASSERT_EQ(NewText[1], 'h');
  ASSERT_EQ(NewText[2], 'Q');
  delete[] NewText;
  delete[] input;
}

// 6) two changes ]
TEST(Tests, TwoOddSymbols) {
  int index = 3;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = ']';
  input[1] = '-';
  input[2] = 'h';
  input[3] = '=';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'h');
  delete[] NewText;
  delete[] input;
}

// 7)
TEST(Tests, ManySymbolsWithNums) {
  int index = 7;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = ']';
  input[1] = '-';
  input[2] = 'm';
  input[3] = '1';
  input[4] = '2';
  input[5] = '3';
  input[6] = 'O';
  input[7] = '=';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'm');
  ASSERT_EQ(NewText[1], 'O');
  delete[] NewText;
  delete[] input;
}

// 8)
TEST(Tests, LongTextWithSpaces1) {
  int index = 15;
  int CounterforNewText = 0;
  char* input = new char[20];
  input[0] = ']';
  input[1] = '-';
  input[2] = 'r';  //
  input[3] = '1';
  input[4] = 'n';  //
  input[5] = '3';
  input[6] = 'O';  //
  input[7] = '=';
  input[8] = ' ';  //
  input[9] = '-';
  input[10] = 'm';  //
  input[11] = '1';
  input[12] = '2';
  input[13] = 'x';  //
  input[14] = 'O';  //
  input[15] = '=';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'r');
  ASSERT_EQ(NewText[1], 'n');
  ASSERT_EQ(NewText[2], 'O');
  ASSERT_EQ(NewText[3], ' ');
  ASSERT_EQ(NewText[4], 'm');
  ASSERT_EQ(NewText[5], 'x');
  ASSERT_EQ(NewText[6], 'O');
  delete[] NewText;
  delete[] input;
}

// 9)
TEST(Tests, AllAlphabet) {
  int index = 25;
  int CounterforNewText = 0;
  char* input = new char[25];
  input[0] = 'a';
  input[1] = 'b';
  input[2] = 'c';
  input[3] = 'd';
  input[4] = 'e';
  input[5] = 'f';
  input[6] = 'g';
  input[7] = 'h';
  input[8] = 'i';
  input[9] = 'j';
  input[10] = 'k';
  input[11] = 'l';
  input[12] = 'm';
  input[13] = 'n';
  input[14] = 'o';
  input[15] = 'p';
  input[16] = 'q';
  input[17] = 'r';
  input[18] = 's';
  input[19] = 't';
  input[20] = 'u';
  input[21] = 'v';
  input[22] = 'w';
  input[23] = 'x';
  input[24] = 'y';
  input[25] = 'z';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'a');
  ASSERT_EQ(NewText[1], 'b');
  ASSERT_EQ(NewText[2], 'c');
  ASSERT_EQ(NewText[3], 'd');
  ASSERT_EQ(NewText[4], 'e');
  ASSERT_EQ(NewText[5], 'f');
  ASSERT_EQ(NewText[6], 'g');
  ASSERT_EQ(NewText[7], 'h');
  ASSERT_EQ(NewText[8], 'i');
  ASSERT_EQ(NewText[9], 'j');
  ASSERT_EQ(NewText[10], 'k');
  ASSERT_EQ(NewText[11], 'l');
  ASSERT_EQ(NewText[12], 'm');
  ASSERT_EQ(NewText[13], 'n');
  ASSERT_EQ(NewText[14], 'o');
  ASSERT_EQ(NewText[15], 'p');
  ASSERT_EQ(NewText[16], 'q');
  ASSERT_EQ(NewText[17], 'r');
  ASSERT_EQ(NewText[18], 's');
  ASSERT_EQ(NewText[19], 't');
  ASSERT_EQ(NewText[20], 'u');
  ASSERT_EQ(NewText[21], 'v');
  ASSERT_EQ(NewText[22], 'w');
  ASSERT_EQ(NewText[23], 'x');
  ASSERT_EQ(NewText[24], 'y');
  ASSERT_EQ(NewText[25], 'z');
  delete[] NewText;
  delete[] input;
}

// 10)
TEST(Tests, AllAlphabetCaps) {
  int index = 25;
  int CounterforNewText = 0;
  char* input = new char[25];
  input[0] = 'A';
  input[1] = 'B';
  input[2] = 'C';
  input[3] = 'D';
  input[4] = 'E';
  input[5] = 'F';
  input[6] = 'G';
  input[7] = 'H';
  input[8] = 'I';
  input[9] = 'J';
  input[10] = 'K';
  input[11] = 'L';
  input[12] = 'M';
  input[13] = 'N';
  input[14] = 'O';
  input[15] = 'P';
  input[16] = 'Q';
  input[17] = 'R';
  input[18] = 'S';
  input[19] = 'T';
  input[20] = 'U';
  input[21] = 'V';
  input[22] = 'W';
  input[23] = 'X';
  input[24] = 'Y';
  input[25] = 'Z';
  char* NewText = DeleteNonText(input, index, CounterforNewText);
  ASSERT_EQ(NewText[0], 'A');
  ASSERT_EQ(NewText[1], 'B');
  ASSERT_EQ(NewText[2], 'C');
  ASSERT_EQ(NewText[3], 'D');
  ASSERT_EQ(NewText[4], 'E');
  ASSERT_EQ(NewText[5], 'F');
  ASSERT_EQ(NewText[6], 'G');
  ASSERT_EQ(NewText[7], 'H');
  ASSERT_EQ(NewText[8], 'I');
  ASSERT_EQ(NewText[9], 'J');
  ASSERT_EQ(NewText[10], 'K');
  ASSERT_EQ(NewText[11], 'L');
  ASSERT_EQ(NewText[12], 'M');
  ASSERT_EQ(NewText[13], 'N');
  ASSERT_EQ(NewText[14], 'O');
  ASSERT_EQ(NewText[15], 'P');
  ASSERT_EQ(NewText[16], 'Q');
  ASSERT_EQ(NewText[17], 'R');
  ASSERT_EQ(NewText[18], 'S');
  ASSERT_EQ(NewText[19], 'T');
  ASSERT_EQ(NewText[20], 'U');
  ASSERT_EQ(NewText[21], 'V');
  ASSERT_EQ(NewText[22], 'W');
  ASSERT_EQ(NewText[23], 'X');
  ASSERT_EQ(NewText[24], 'Y');
  ASSERT_EQ(NewText[25], 'Z');
  delete[] NewText;
  delete[] input;
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
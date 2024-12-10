#include <gtest/gtest.h>

#include <iostream>

// копирование строки
char* Copy(char* input, int index) {
  char* NewText = new char[index + 1];
  for (int i = 0; i <= index; ++i) {
    NewText[i] = input[i];
  }
  return NewText;
}
// сравнение строки
bool compare(char* input, int index, char* anotherInput, int anotherIndex,
             int& K) {
  if (index > anotherIndex) {
    K = index - anotherIndex;
  }
  if (index < anotherIndex) {
    K = anotherIndex - index;
  }
  for (int i = 0; i <= std::min(index, anotherIndex); ++i) {
    if (anotherInput[i] != input[i]) {
      ++K;
    }
  }
  if (K == 0) {
    return true;
  } else {
    return false;
  }
}
// объединение строк
char* unify(char* input, int index, char* anotherInput, int anotherIndex) {
  char* NewText = new char[index + anotherIndex + 2];
  for (int i = 0; i <= index; ++i) {
    NewText[i] = input[i];
  }
  int k = 0;
  for (int i = index + 1; i < index + anotherIndex + 2; ++i) {
    NewText[i] = anotherInput[k];
    ++k;
  }
  return NewText;
}

TEST(Tests, TestOfCopying1) {
  int index = 25;
  char* input = new char[26];
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
  char* NewText = nullptr;

  NewText = Copy(input, index);
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

TEST(Tests, TestOfCopying2) {
  int index = 25;
  char* input = new char[26];
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
  char* NewText = nullptr;

  NewText = Copy(input, index);
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

TEST(Tests, TestOfCopying3) {
  int index = 19;
  char* input = new char[20];
  input[0] = '0';
  input[1] = '1';
  input[2] = '2';
  input[3] = '3';
  input[4] = '4';
  input[5] = '5';
  input[6] = '6';
  input[7] = '7';
  input[8] = '8';
  input[9] = '9';
  input[10] = '!';
  input[11] = '@';
  input[12] = '#';
  input[13] = '$';
  input[14] = '%';
  input[15] = '^';
  input[16] = '&';
  input[17] = '*';
  input[18] = '(';
  input[19] = ')';
  char* NewText = nullptr;

  NewText = Copy(input, index);
  ASSERT_EQ(NewText[0], '0');
  ASSERT_EQ(NewText[1], '1');
  ASSERT_EQ(NewText[2], '2');
  ASSERT_EQ(NewText[3], '3');
  ASSERT_EQ(NewText[4], '4');
  ASSERT_EQ(NewText[5], '5');
  ASSERT_EQ(NewText[6], '6');
  ASSERT_EQ(NewText[7], '7');
  ASSERT_EQ(NewText[8], '8');
  ASSERT_EQ(NewText[9], '9');
  ASSERT_EQ(NewText[10], '!');
  ASSERT_EQ(NewText[11], '@');
  ASSERT_EQ(NewText[12], '#');
  ASSERT_EQ(NewText[13], '$');
  ASSERT_EQ(NewText[14], '%');
  ASSERT_EQ(NewText[15], '^');
  ASSERT_EQ(NewText[16], '&');
  ASSERT_EQ(NewText[17], '*');
  ASSERT_EQ(NewText[18], '(');
  ASSERT_EQ(NewText[19], ')');

  delete[] NewText;
  delete[] input;
}

TEST(Tests, TestOfComparison1) {
  int index = 19;
  char* input = new char[19];
  input[0] = 'a';
  input[1] = '7';
  input[2] = '*';
  input[3] = '!';
  input[4] = 'M';
  input[5] = 'r';
  input[6] = '3';
  input[7] = 'z';
  input[8] = 'W';
  input[9] = '#';
  input[10] = 'q';
  input[11] = '@';
  input[12] = 'L';
  input[13] = '%';
  input[14] = '9';
  input[15] = 'e';
  input[16] = 'T';
  input[17] = '$';
  input[18] = 'k';
  input[19] = 'Y';

  int anotherIndex = 19;
  char* anotherInput = new char[19];
  anotherInput[0] = 'a';
  anotherInput[1] = '8';
  anotherInput[2] = '*';
  anotherInput[3] = '?';
  anotherInput[4] = 'M';
  anotherInput[5] = 'r';
  anotherInput[6] = '4';
  anotherInput[7] = 'y';
  anotherInput[8] = 'X';
  anotherInput[9] = '&';
  anotherInput[10] = 'q';
  anotherInput[11] = '@';
  anotherInput[12] = 'L';
  anotherInput[13] = '%';
  anotherInput[14] = '9';
  anotherInput[15] = 'f';
  anotherInput[16] = 'T';
  anotherInput[17] = '^';
  anotherInput[18] = 'k';
  anotherInput[19] = 'Z';
  int K = 0;
  compare(input, index, anotherInput, anotherIndex, K);
  ASSERT_EQ(K, 9);
  delete[] anotherInput;

  delete[] input;
}

TEST(Tests, TestOfComparison2) {
  int index = 19;
  char* input = new char[19];
  input[0] = 'a';
  input[1] = '7';
  input[2] = '*';
  input[3] = '!';
  input[4] = 'M';
  input[5] = 'r';
  input[6] = '3';
  input[7] = 'z';
  input[8] = 'W';
  input[9] = '#';
  input[10] = 'q';
  input[11] = '@';
  input[12] = 'L';
  input[13] = '%';
  input[14] = '9';
  input[15] = 'e';
  input[16] = 'T';
  input[17] = '$';
  input[18] = 'k';
  input[19] = 'Y';

  int anotherIndex = 9;
  char* anotherInput = new char[10];
  anotherInput[0] = 'a';
  anotherInput[1] = '8';
  anotherInput[2] = '*';
  anotherInput[3] = '?';
  anotherInput[4] = 'M';
  anotherInput[5] = 'r';
  anotherInput[6] = '4';
  anotherInput[7] = 'y';
  anotherInput[8] = 'X';
  anotherInput[9] = '&';
  int K = 0;
  compare(input, index, anotherInput, anotherIndex, K);
  ASSERT_EQ(K, 16);
  delete[] anotherInput;

  delete[] input;
}

TEST(Tests, TestOfComparison3) {
  int index = 14;
  char* input = new char[15];
  input[0] = 'a';
  input[1] = '7';
  input[2] = '*';
  input[3] = '!';
  input[4] = 'M';
  input[5] = 'r';
  input[6] = '3';
  input[7] = 'z';
  input[8] = 'W';
  input[9] = '#';
  input[10] = 'q';
  input[11] = '@';
  input[12] = 'L';
  input[13] = '%';
  input[14] = '9';

  int anotherIndex = 19;
  char* anotherInput = new char[20];
  anotherInput[0] = 'a';
  anotherInput[1] = '8';
  anotherInput[2] = '*';
  anotherInput[3] = '?';
  anotherInput[4] = 'M';
  anotherInput[5] = 'r';
  anotherInput[6] = '4';
  anotherInput[7] = 'y';
  anotherInput[8] = 'X';
  anotherInput[9] = '&';
  anotherInput[10] = 'q';
  anotherInput[11] = '@';
  anotherInput[12] = 'K';
  anotherInput[13] = '^';
  anotherInput[14] = '9';
  anotherInput[15] = 'e';
  anotherInput[16] = 'T';
  anotherInput[17] = '$';
  anotherInput[18] = 'k';
  anotherInput[19] = 'Y';
  int K = 0;
  compare(input, index, anotherInput, anotherIndex, K);
  ASSERT_EQ(K, 13);
  delete[] anotherInput;

  delete[] input;
}

TEST(Tests, TestOfUnifying1) {
  int index = 19;
  char* input = new char[20];
  input[0] = 'a';
  input[1] = '1';
  input[2] = 'b';
  input[3] = '2';
  input[4] = 'c';
  input[5] = '3';
  input[6] = 'd';
  input[7] = '4';
  input[8] = 'e';
  input[9] = '5';
  input[10] = 'f';
  input[11] = '6';
  input[12] = 'g';
  input[13] = '7';
  input[14] = 'h';
  input[15] = '8';
  input[16] = 'i';
  input[17] = '9';
  input[18] = 'j';
  input[19] = '0';
  char* NewText = nullptr;

  int anotherIndex = 19;
  char* anotherInput = new char[20];
  anotherInput[0] = 'A';
  anotherInput[1] = 'B';
  anotherInput[2] = 'C';
  anotherInput[3] = 'D';
  anotherInput[4] = 'E';
  anotherInput[5] = 'F';
  anotherInput[6] = 'G';
  anotherInput[7] = 'H';
  anotherInput[8] = 'I';
  anotherInput[9] = 'J';
  anotherInput[10] = 'K';
  anotherInput[11] = 'L';
  anotherInput[12] = 'M';
  anotherInput[13] = 'N';
  anotherInput[14] = 'O';
  anotherInput[15] = 'P';
  anotherInput[16] = 'Q';
  anotherInput[17] = 'R';
  anotherInput[18] = 'S';
  anotherInput[19] = 'T';
  NewText = unify(input, index, anotherInput, anotherIndex);
  ASSERT_EQ(NewText[0], 'a');
  ASSERT_EQ(NewText[1], '1');
  ASSERT_EQ(NewText[2], 'b');
  ASSERT_EQ(NewText[3], '2');
  ASSERT_EQ(NewText[4], 'c');
  ASSERT_EQ(NewText[5], '3');
  ASSERT_EQ(NewText[6], 'd');
  ASSERT_EQ(NewText[7], '4');
  ASSERT_EQ(NewText[8], 'e');
  ASSERT_EQ(NewText[9], '5');
  ASSERT_EQ(NewText[10], 'f');
  ASSERT_EQ(NewText[11], '6');
  ASSERT_EQ(NewText[12], 'g');
  ASSERT_EQ(NewText[13], '7');
  ASSERT_EQ(NewText[14], 'h');
  ASSERT_EQ(NewText[15], '8');
  ASSERT_EQ(NewText[16], 'i');
  ASSERT_EQ(NewText[17], '9');
  ASSERT_EQ(NewText[18], 'j');
  ASSERT_EQ(NewText[19], '0');
  ASSERT_EQ(NewText[20], 'A');
  ASSERT_EQ(NewText[21], 'B');
  ASSERT_EQ(NewText[22], 'C');
  ASSERT_EQ(NewText[23], 'D');
  ASSERT_EQ(NewText[24], 'E');
  ASSERT_EQ(NewText[25], 'F');
  ASSERT_EQ(NewText[26], 'G');
  ASSERT_EQ(NewText[27], 'H');
  ASSERT_EQ(NewText[28], 'I');
  ASSERT_EQ(NewText[29], 'J');
  ASSERT_EQ(NewText[30], 'K');
  ASSERT_EQ(NewText[31], 'L');
  ASSERT_EQ(NewText[32], 'M');
  ASSERT_EQ(NewText[33], 'N');
  ASSERT_EQ(NewText[34], 'O');
  ASSERT_EQ(NewText[35], 'P');
  ASSERT_EQ(NewText[36], 'Q');
  ASSERT_EQ(NewText[37], 'R');
  ASSERT_EQ(NewText[38], 'S');
  ASSERT_EQ(NewText[39], 'T');

  delete[] anotherInput;
  delete[] NewText;
  delete[] input;
}

TEST(Tests, TestOfUnifying2) {
  int index = 19;
  char* input = new char[20];
  input[0] = 'x';
  input[1] = '1';
  input[2] = 'y';
  input[3] = '2';
  input[4] = 'z';
  input[5] = '3';
  input[6] = 'w';
  input[7] = '4';
  input[8] = 'v';
  input[9] = '5';
  input[10] = 'u';
  input[11] = '6';
  input[12] = 't';
  input[13] = '7';
  input[14] = 's';
  input[15] = '8';
  input[16] = 'r';
  input[17] = '9';
  input[18] = 'q';
  input[19] = '0';
  char* NewText = nullptr;

  int anotherIndex = 19;
  char* anotherInput = new char[20];
  anotherInput[0] = 'P';
  anotherInput[1] = 'Q';
  anotherInput[2] = 'R';
  anotherInput[3] = 'S';
  anotherInput[4] = 'T';
  anotherInput[5] = 'U';
  anotherInput[6] = 'V';
  anotherInput[7] = 'W';
  anotherInput[8] = 'X';
  anotherInput[9] = 'Y';
  anotherInput[10] = 'Z';
  anotherInput[11] = 'A';
  anotherInput[12] = 'B';
  anotherInput[13] = 'C';
  anotherInput[14] = 'D';
  anotherInput[15] = 'E';
  anotherInput[16] = 'F';
  anotherInput[17] = 'G';
  anotherInput[18] = 'H';
  anotherInput[19] = 'I';
  NewText = unify(input, index, anotherInput, anotherIndex);
  ASSERT_EQ(NewText[0], 'x');
  ASSERT_EQ(NewText[1], '1');
  ASSERT_EQ(NewText[2], 'y');
  ASSERT_EQ(NewText[3], '2');
  ASSERT_EQ(NewText[4], 'z');
  ASSERT_EQ(NewText[5], '3');
  ASSERT_EQ(NewText[6], 'w');
  ASSERT_EQ(NewText[7], '4');
  ASSERT_EQ(NewText[8], 'v');
  ASSERT_EQ(NewText[9], '5');
  ASSERT_EQ(NewText[10], 'u');
  ASSERT_EQ(NewText[11], '6');
  ASSERT_EQ(NewText[12], 't');
  ASSERT_EQ(NewText[13], '7');
  ASSERT_EQ(NewText[14], 's');
  ASSERT_EQ(NewText[15], '8');
  ASSERT_EQ(NewText[16], 'r');
  ASSERT_EQ(NewText[17], '9');
  ASSERT_EQ(NewText[18], 'q');
  ASSERT_EQ(NewText[19], '0');
  ASSERT_EQ(NewText[20], 'P');
  ASSERT_EQ(NewText[21], 'Q');
  ASSERT_EQ(NewText[22], 'R');
  ASSERT_EQ(NewText[23], 'S');
  ASSERT_EQ(NewText[24], 'T');
  ASSERT_EQ(NewText[25], 'U');
  ASSERT_EQ(NewText[26], 'V');
  ASSERT_EQ(NewText[27], 'W');
  ASSERT_EQ(NewText[28], 'X');
  ASSERT_EQ(NewText[29], 'Y');
  ASSERT_EQ(NewText[30], 'Z');
  ASSERT_EQ(NewText[31], 'A');
  ASSERT_EQ(NewText[32], 'B');
  ASSERT_EQ(NewText[33], 'C');
  ASSERT_EQ(NewText[34], 'D');
  ASSERT_EQ(NewText[35], 'E');
  ASSERT_EQ(NewText[36], 'F');
  ASSERT_EQ(NewText[37], 'G');
  ASSERT_EQ(NewText[38], 'H');
  ASSERT_EQ(NewText[39], 'I');

  delete[] anotherInput;
  delete[] NewText;
  delete[] input;
}

TEST(Tests, TestOfUnifying3) {
  int index = 19;
  char* input = new char[20];
  input[0] = 'm';
  input[1] = 'n';
  input[2] = 'o';
  input[3] = 'p';
  input[4] = 'q';
  input[5] = 'r';
  input[6] = 's';
  input[7] = 't';
  input[8] = 'u';
  input[9] = 'v';
  input[10] = 'w';
  input[11] = 'x';
  input[12] = 'y';
  input[13] = 'z';
  input[14] = '0';
  input[15] = '1';
  input[16] = '2';
  input[17] = '3';
  input[18] = '4';
  input[19] = '5';
  char* NewText = nullptr;

  int anotherIndex = 19;
  char* anotherInput = new char[20];
  anotherInput[0] = 'A';
  anotherInput[1] = 'B';
  anotherInput[2] = 'C';
  anotherInput[3] = 'D';
  anotherInput[4] = 'E';
  anotherInput[5] = 'F';
  anotherInput[6] = 'G';
  anotherInput[7] = 'H';
  anotherInput[8] = 'I';
  anotherInput[9] = 'J';
  anotherInput[10] = 'K';
  anotherInput[11] = 'L';
  anotherInput[12] = 'M';
  anotherInput[13] = 'N';
  anotherInput[14] = 'O';
  anotherInput[15] = 'P';
  anotherInput[16] = 'Q';
  anotherInput[17] = 'R';
  anotherInput[18] = 'S';
  anotherInput[19] = 'T';
  NewText = unify(input, index, anotherInput, anotherIndex);
  ASSERT_EQ(NewText[0], 'm');
  ASSERT_EQ(NewText[1], 'n');
  ASSERT_EQ(NewText[2], 'o');
  ASSERT_EQ(NewText[3], 'p');
  ASSERT_EQ(NewText[4], 'q');
  ASSERT_EQ(NewText[5], 'r');
  ASSERT_EQ(NewText[6], 's');
  ASSERT_EQ(NewText[7], 't');
  ASSERT_EQ(NewText[8], 'u');
  ASSERT_EQ(NewText[9], 'v');
  ASSERT_EQ(NewText[10], 'w');
  ASSERT_EQ(NewText[11], 'x');
  ASSERT_EQ(NewText[12], 'y');
  ASSERT_EQ(NewText[13], 'z');
  ASSERT_EQ(NewText[14], '0');
  ASSERT_EQ(NewText[15], '1');
  ASSERT_EQ(NewText[16], '2');
  ASSERT_EQ(NewText[17], '3');
  ASSERT_EQ(NewText[18], '4');
  ASSERT_EQ(NewText[19], '5');
  ASSERT_EQ(NewText[20], 'A');
  ASSERT_EQ(NewText[21], 'B');
  ASSERT_EQ(NewText[22], 'C');
  ASSERT_EQ(NewText[23], 'D');
  ASSERT_EQ(NewText[24], 'E');
  ASSERT_EQ(NewText[25], 'F');
  ASSERT_EQ(NewText[26], 'G');
  ASSERT_EQ(NewText[27], 'H');
  ASSERT_EQ(NewText[28], 'I');
  ASSERT_EQ(NewText[29], 'J');
  ASSERT_EQ(NewText[30], 'K');
  ASSERT_EQ(NewText[31], 'L');
  ASSERT_EQ(NewText[32], 'M');
  ASSERT_EQ(NewText[33], 'N');
  ASSERT_EQ(NewText[34], 'O');
  ASSERT_EQ(NewText[35], 'P');
  ASSERT_EQ(NewText[36], 'Q');
  ASSERT_EQ(NewText[37], 'R');
  ASSERT_EQ(NewText[38], 'S');
  ASSERT_EQ(NewText[39], 'T');

  delete[] anotherInput;
  delete[] NewText;
  delete[] input;
}

TEST(Tests, TestOfUnifying4) {
  int index = 19;
  char* input = new char[20];
  input[0] = 'k';
  input[1] = 'l';
  input[2] = 'm';
  input[3] = 'n';
  input[4] = 'o';
  input[5] = 'p';
  input[6] = 'q';
  input[7] = 'r';
  input[8] = 's';
  input[9] = 't';
  input[10] = 'u';
  input[11] = 'v';
  input[12] = 'w';
  input[13] = 'x';
  input[14] = 'y';
  input[15] = 'z';
  input[16] = '0';
  input[17] = '1';
  input[18] = '2';
  input[19] = '3';
  char* NewText = nullptr;

  int anotherIndex = 19;
  char* anotherInput = new char[20];
  anotherInput[0] = 'Z';
  anotherInput[1] = 'Y';
  anotherInput[2] = 'X';
  anotherInput[3] = 'W';
  anotherInput[4] = 'V';
  anotherInput[5] = 'U';
  anotherInput[6] = 'T';
  anotherInput[7] = 'S';
  anotherInput[8] = 'R';
  anotherInput[9] = 'Q';
  anotherInput[10] = 'P';
  anotherInput[11] = 'O';
  anotherInput[12] = 'N';
  anotherInput[13] = 'M';
  anotherInput[14] = 'L';
  anotherInput[15] = 'K';
  anotherInput[16] = 'J';
  anotherInput[17] = 'I';
  anotherInput[18] = 'H';
  anotherInput[19] = 'G';
  NewText = unify(input, index, anotherInput, anotherIndex);
  ASSERT_EQ(NewText[0], 'k');
  ASSERT_EQ(NewText[1], 'l');
  ASSERT_EQ(NewText[2], 'm');
  ASSERT_EQ(NewText[3], 'n');
  ASSERT_EQ(NewText[4], 'o');
  ASSERT_EQ(NewText[5], 'p');
  ASSERT_EQ(NewText[6], 'q');
  ASSERT_EQ(NewText[7], 'r');
  ASSERT_EQ(NewText[8], 's');
  ASSERT_EQ(NewText[9], 't');
  ASSERT_EQ(NewText[10], 'u');
  ASSERT_EQ(NewText[11], 'v');
  ASSERT_EQ(NewText[12], 'w');
  ASSERT_EQ(NewText[13], 'x');
  ASSERT_EQ(NewText[14], 'y');
  ASSERT_EQ(NewText[15], 'z');
  ASSERT_EQ(NewText[16], '0');
  ASSERT_EQ(NewText[17], '1');
  ASSERT_EQ(NewText[18], '2');
  ASSERT_EQ(NewText[19], '3');
  ASSERT_EQ(NewText[20], 'Z');
  ASSERT_EQ(NewText[21], 'Y');
  ASSERT_EQ(NewText[22], 'X');
  ASSERT_EQ(NewText[23], 'W');
  ASSERT_EQ(NewText[24], 'V');
  ASSERT_EQ(NewText[25], 'U');
  ASSERT_EQ(NewText[26], 'T');
  ASSERT_EQ(NewText[27], 'S');
  ASSERT_EQ(NewText[28], 'R');
  ASSERT_EQ(NewText[29], 'Q');
  ASSERT_EQ(NewText[30], 'P');
  ASSERT_EQ(NewText[31], 'O');
  ASSERT_EQ(NewText[32], 'N');
  ASSERT_EQ(NewText[33], 'M');
  ASSERT_EQ(NewText[34], 'L');
  ASSERT_EQ(NewText[35], 'K');
  ASSERT_EQ(NewText[36], 'J');
  ASSERT_EQ(NewText[37], 'I');
  ASSERT_EQ(NewText[38], 'H');
  ASSERT_EQ(NewText[39], 'G');

  delete[] anotherInput;
  delete[] NewText;
  delete[] input;
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
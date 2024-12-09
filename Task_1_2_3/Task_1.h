#pragma once

#include <iostream>

class Task_1 {
 private:
  void intro() {
    std::cout << "Условие задания: Из строки, состоящей из букв, цифр, \n"
                 "запятых, точек, знаков + и –, выделить подстроку, задающую \n"
                 "вещественное число с фиксированной точкой.\n";
  }
  int correctInputk() {
    std::cout << "[1 - да / 0 - нет]";
    int x = 0;
    bool incorrectInput = false;
    do {
      incorrectInput = false;
      std::cin >> x;
      if (std::cin.fail() || std::cin.peek() != '\n' ||
          std::cin.peek() == '.') {
        std::cin.clear();
        std::cout << "Некорректный ввод" << std::endl;
        std::cin.ignore(1000000, '\n');
        incorrectInput = true;
      }
      if (x != 1 && x != 0) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    } while (incorrectInput);
    return x;
  }

  char* CorrectInputCharArray(int& index) {
    std::cout << "Введите строку\n";
    int capacity = 81;
    char* input = new char[capacity];
    char c;
    while ((c = getchar()) != '\n') {
      input[index] = c;
      ++index;
    }
    if (index > 80) {
      std::cout << "Некорректный ввод \n";
      delete[] input;
      return nullptr;
    }
    --index;
    return input;
  }

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
          NumberFound = false;
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

  void outputResult(char* Number, int counterForNumber, bool NumberFound,
                    int flag = 0) {
    for (int i = 0; i <= counterForNumber; ++i) {
      std::cout << Number[i];
    }
    if (NumberFound) {
      std::cout << '\n';
    }
  }

  void outputInput(char* input, int index) {
    for (int i = 0; i <= index; ++i) {
      std::cout << input[i];
    }
    std::cout << '\n';
  }

 public:
  int Task_1_main() {
    intro();
    while (true) {
      std::cin.ignore();
      bool NumberFound = false;
      int index = 0;
      int counterForNumber = 0;
      int last_i = 0;
      char* input = CorrectInputCharArray(index);
      char* Number = new char[81];
      std::cout << "Найденные числа с фиксированной точкой: \n";
      do {
        NumberFound =
            findNumber(Number, input, index, counterForNumber, last_i);
        outputResult(Number, counterForNumber, NumberFound);
        counterForNumber = 0;
      } while (last_i < index);
      std::cout << "Исходный текст:\n";
      outputInput(input, index);
      delete[] input;
      std::cout << "Продолжить выполнение задания 1?\n";
      delete[] Number;
      int a = correctInputk();
      if (a == 0) {
        break;
      }
    }
    return 0;
  }
};
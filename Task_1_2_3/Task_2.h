#pragma once

#include <iostream>

class Task_2 {
 private:
  void intro() {
    std::cout << "Условие задания: Из текста удалить все символы, не \n"
                 "являющиеся буквами, кроме пробелов\n";
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
    std::cout << "Введите текст\n";
    int capacity = 80;
    char* input = new char[capacity];
    char c;
    while ((c = getchar()) != '\n') {
      if (index >= capacity) {
        capacity *= 2;
        char* newInput = new char[capacity];
        for (int i = 0; i < index; ++i) {
          newInput[i] = input[i];
        }
        delete[] input;
        input = newInput;
      }
      input[index] = c;
      ++index;
    }
    --index;
    return input;
  }

  void outputResult(char* NewText, int CounterForNewText) {
    for (int i = 0; i <= CounterForNewText; ++i) {
      std::cout << NewText[i];
    }
    std::cout << '\n';
  }

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

 public:
  int Task_2_main() {
    intro();
    while (true) {
      std::cin.ignore();
      int index = 0;
      int CounterforNewText = 0;
      char* input = CorrectInputCharArray(index);
      char* NewText = DeleteNonText(input, index, CounterforNewText);
      outputResult(NewText, CounterforNewText);
      std::cout << "Продолжить выполнение задания 2?\n";
      delete[] NewText;
      delete[] input;
      int a = correctInputk();
      std::cin.ignore();
      if (a == 0) {
        break;
      }
    }
    return 0;
  }
};
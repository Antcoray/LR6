#pragma once

#include <iostream>

class Task_3 {
 private:
  void intro() {
    std::cout << "Условие задания: Написать функции (копирование, сравнение, \n"
                 "объединение) для работы со строками, используя указатели \n ";
  }
  int correctInputk(int m = 1) {
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
      if (m == 1) {
        if (x != 1 && x != 0) {
          std::cout << "Некорректный ввод" << std::endl;
          incorrectInput = true;
        }
      }
      if (m == 3) {
        if (x != 1 && x != 2 && x != 3) {
          std::cout << "Некорректный ввод" << std::endl;
          incorrectInput = true;
        }
      }
    } while (incorrectInput);
    return x;
  }
  char* CorrectInputCharArray(int& index, int flag = 0) {
    if (flag == 0) {
      std::cout << "Введите текст\n";
    }
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

 public:
  int Task_3_main() {
    intro();
    while (true) {
      std::cin.ignore();
      int index = 0;
     char* input = CorrectInputCharArray(index);
      char* NewText = nullptr;
      std::cout << "Введите номер функции, которую хотите использовать\n [1 - "
                   "копирование / 2 - сравнение / 3 - объединение] \n";
      int b = correctInputk(3);
      if (b == 1) {
        std::cin.ignore();
        NewText = Copy(input, index);
        std::cout << "Скопированная строка: \n";
        outputResult(NewText, index);
      }
      if (b == 2) {
        std::cin.ignore();
        std::cout << "Введите строку для сравнения с ранее введенной строкой\n";
        int anotherIndex = 0;
        char* anotherInput = CorrectInputCharArray(anotherIndex, 1);
        int K = 0;
        if (compare(input, index, anotherInput, anotherIndex, K)) {
          std::cout << "Строки равны\n";
        } else {
          std::cout << "Строки отличаются на " << K << " символ(ов)\n";
        }
        delete[] anotherInput;
      }
      if (b == 3) {
        std::cin.ignore();
        std::cout
            << "Введите строку для объединения с ранее введенной строкой\n";
        int anotherIndex = 0;
        char* anotherInput = CorrectInputCharArray(anotherIndex, 1);
        NewText = unify(input, index, anotherInput, anotherIndex);
        std::cout << "Объединенная строка: \n";
        outputResult(NewText, index + anotherIndex + 1);
        delete[] anotherInput;
      }
      std::cout << "Продолжить выполнение задания 3?\n";
      delete[] NewText;
      delete[] input;
      std::cout << "[1 - да / 0 - нет]";
      int a = correctInputk();
      if (a == 0) {
        break;
      }
    }
    return 0;
  }
};
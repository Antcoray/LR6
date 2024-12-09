#include <iostream>

#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
int correctInputk(int m = 1) {
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
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
    if (m == 4) {
      if (x != 1 && x != 2 && x != 3 && x != 0) {
        std::cout << "Некорректный ввод" << std::endl;
        incorrectInput = true;
      }
    }
  } while (incorrectInput);
  return x;
}

int main() {
  Task_1 task1;
  Task_2 task2;
  Task_3 task3;
  std::cout << "Лабораторная работа номер 6. Выполнил Колесников Антон "
               "Сергееевич. Вариант 7\n";
  while (true) {
    std::cout << "Введите номер задания, которое нужно запустить [1 / 2 / 3]\n"
                 "или 0, чтобы выйти\n";
    int k = correctInputk(4);
    if (k == 0) {
      break;
    }
    if (k == 1) {
      task1.Task_1_main();
    }
    if (k == 2) {
      task2.Task_2_main();
    }
    if (k == 3) {
      task3.Task_3_main();
    }
  }
  return 0;
}
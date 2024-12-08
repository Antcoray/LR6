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
    bool minusFound = false;
    bool plusFound = false;

    for (int i = last_i; i <= index; ++i) {
      last_i = i;
      // если символ это +-. 0...9 то присваиваем число эл массива и (*)
      // проверяем следующее на 0...9 или '.'
      if (checkForEquality(input[i])) {
        // если '.' это первый символ то скипаем итерацию
        if (input[i] == '.' && counterForNumber == 0) {
          continue;
        }
        // если '0' это первый символ и за ним не следует '.' то скипаем
        // итерацию (чтобы избежать чисел вида 0234)
        if (input[i] == '0' && counterForNumber == 0 && input[i + 1] != '.') {
          continue;
        }
        // проверка что в числе всего одна '.'
        if (input[i] == '.' && dotFound) {
          ++last_i;
          break;
        }
        // проверка что после первой '.' идет число, если нет то прекращаем цикл
        // и обнуляем массив
        if (input[i] == '.' && !checkForEquality(input[i + 1], 10)) {
          for (int k = 0; k < counterForNumber; ++k) {
            Number[k] = '\0';
          }
          ++last_i;
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

  void outputResult(char* Number, int counterForNumber, bool NumberFound) {
    for (int i = 0; i <= counterForNumber; ++i) {
      std::cout << Number[i];
    }
    std::cout << '\n';
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
        outputInput(input, index);
        counterForNumber = 0;
      } while (last_i < index);
      delete[] input;
      std::cout << "Продолжить выполнение задания 2?\n";
      delete[] Number;
      int a = correctInputk();
      std::cin.ignore();  // чтобы 1 не записывалась в массив input
      if (a == 0) {
        break;
      }
    }
    return 0;
  }
};

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
      int index = 0;
      int CounterforNewText = 0;
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
          std::cout << "Строки отличаются на " << K << " символов\n";
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
      std::cin.ignore();
      if (a == 0) {
        break;
      }
    }
    return 0;
  }
};

int main() {
  Task_1 task1;
  Task_2 task2;
  Task_3 task3;
  // task1.Task_1_main();
  // task2.Task_2_main();
  task3.Task_3_main();
  return 0;
}
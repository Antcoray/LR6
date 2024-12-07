#include <iostream>

class Task_1 {
 private:
  char* CorrectInputCharArray(int& index) {
    int capacity = 80;
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
      // если символ это +-. 0...9 то присваиваем число массиву и (*) проверяем
      // следующее на 0...9 или '.'
      if (checkForEquality(input[i])) {
        // если '.' это первый символ то скипаем итерацию
        if (input[i] == '.' && counterForNumber == 0) {
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
            Number[k] = ' ';
          }
          ++last_i;
          break;
        }
        // проверка что + - . встретились в числе
        if (input[i] == '.') {
          dotFound = true;
        }
        if (input[i] == '+') {
          plusFound = true;
        }
        if (input[i] == '-') {
          minusFound = true;
        }
        // присваиваем массиву число
        Number[counterForNumber] = input[i];
        ++counterForNumber;
        NumberFound = true;
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

 public:
  int Task_1_main() {
    bool NumberFound = false;
    int index = 0;
    int counterForNumber = 0;
    int last_i = 0;
    char* input = CorrectInputCharArray(index);
    char* Number = new char[80];
    std::cout << "Найденные числа с фиксированной точкой: \n";
    do {
      NumberFound = findNumber(Number, input, index, counterForNumber, last_i);
      outputResult(Number, counterForNumber, NumberFound);
      counterForNumber = 0;
    } while (last_i < index);
    delete[] Number;
    delete[] input;
    return 0;
  }
};

class Task_2 {
 private:
  char* CorrectInputCharArray(int& index) {
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
    if (index > 80) {
      std::cout << "Некорректный ввод \n";
      delete[] input;
      return nullptr;
    }
    --index;
    return input;
  }

 public:
  int Task_2_main() {
    int index = 0;
    char* input = CorrectInputCharArray(index);
    delete[] input;
    return 0;
  }
};

int main() {
  Task_1 task1;
  task1.Task_1_main();
  return 0;
}
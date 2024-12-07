#include <iostream>

class Task_1 {
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
  int Task_1_main() {
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
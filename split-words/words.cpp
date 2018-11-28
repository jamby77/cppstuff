#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

int main() {
  int j = 0; // letter increment
  int i = 0; // words counter
  char temp[MAX] = {'\0'};
  char letter;

  char str[MAX] = {'\0'};
  cin.getline(str, MAX);

  int length = static_cast<int>(strlen(str));
  char matrix[MAX][MAX] = {'\0'};

  for (int k = 0; k < length; k++) {
    letter = str[k];

    if (letter >= 'A' && letter <= 'z') {
      matrix[i][j] = letter; //тук излиза проблема с паметта
      j++;
    } else {
      i++;
      j = 0;
    }
  }

  for (int t = 0; t <= i - 1; t++) {
    for (int p = t + 1; p <= i; p++) {
      if (strcmp(matrix[t], matrix[p]) > 0) {
        j = 0;
        char c = matrix[t][0];
        while (c!='\0') {
          temp[j++] = c;
          c = matrix[t][j];
        }
        temp[j] = c;
        j = 0;
        c = matrix[p][0];
        while (c!='\0') {
          matrix[t][j++] = c;
          c = matrix[p][j];
        }
        matrix[t][j] = c;
        j = 0;
        c = temp[0];
        while (c!='\0') {
          matrix[p][j++] = c;
          c = temp[j];
        }
        matrix[p][j] = c;
      }
    }
  }

  for (int t = 0; t <= i; t++) {
    cout << matrix[t] << endl;
  }

  return 0;
}

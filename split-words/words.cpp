#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 256;

char getMostCommonChar(const char *test);
int main() {
//  int j = 0; // letter increment
//  int i = 0; // words counter
//  char temp[MAX] = {'\0'};
//  char letter;
//
//  char str[MAX] = {'\0'};
//  cin.getline(str, MAX);
//
//  int length = static_cast<int>(strlen(str));
//  char matrix[MAX][MAX] = {'\0'};
//
//  for (int k = 0; k < length; k++) {
//    letter = str[k];
//
//    if (letter >= 'A' && letter <= 'z') {
//      matrix[i][j] = letter; //тук излиза проблема с паметта
//      j++;
//    } else {
//      i++;
//      j = 0;
//    }
//  }
//
//  for (int t = 0; t <= i - 1; t++) {
//    for (int p = t + 1; p <= i; p++) {
//      if (strcmp(matrix[t], matrix[p]) > 0) {
//        j = 0;
//        char c = matrix[t][0];
//        while (c!='\0') {
//          temp[j++] = c;
//          c = matrix[t][j];
//        }
//        temp[j] = c;
//        j = 0;
//        c = matrix[p][0];
//        while (c!='\0') {
//          matrix[t][j++] = c;
//          c = matrix[p][j];
//        }
//        matrix[t][j] = c;
//        j = 0;
//        c = temp[0];
//        while (c!='\0') {
//          matrix[p][j++] = c;
//          c = temp[j];
//        }
//        matrix[p][j] = c;
//      }
//    }
//  }
//
//  for (int t = 0; t <= i; t++) {
//    cout << matrix[t] << endl;
//  }

  const char test[] = "abbcc defgghi";

  char m = getMostCommonChar(test);

  std::cout << m << '\n';

  return 0;
}
char getMostCommonChar(const char *test) {
  int letters[MAX] = {0};
  for (int i = 0; i < strlen(test); ++i) {
    char t = test[i];

    letters[t] += 1;
  }

  char m = '\0';
  int t = 0;
  for (char j = 'a'; j <='z'; j++) {
    if (letters[j] > t) {
      m = j;
      t = letters[j];
    }
  }
  return m;
}

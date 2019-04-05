#include<iostream>
#include<fstream>
using namespace std;


struct Car {
  char brand[30];
  char model[30];
  float price;
};

int main() {

  Car carArray[4];
  for (int i = 0; i < 4; i++) {
    cin >> carArray[i].brand >> carArray[i].model >> carArray[i].price;
  }

  //for (int i = 0; i < 4; i++) {
  //cout << carArray[i].brand << "  " << carArray[i].model << "  " << carArray[i].price << endl;
  //}
  ofstream oFile("text.bin", ios::binary);

  if (!oFile.is_open()) {
    cout << "error";
  }

  for (int i = 0; i < 4; i++) {
    oFile.write((char *) &carArray[i], sizeof(Car));
  }
  oFile.close();

  Car tempCar;
  ofstream textFile("text.txt");
  ifstream iFile("text.bin", ios::binary);

  int k = 0;
  while (true) {
    iFile.read((char *) &tempCar, sizeof(Car));
    if (k%2==1) {
      textFile.write((char *) &tempCar, sizeof(Car));
    }
    if (iFile.eof()) {
      break;
    }
    k++;
  }
  //mazda cx-5 5000 mazda cx-7 6000 mazda cx-9 7000 mazda 6 5000
  textFile.close();

  ifstream itextFile("text.txt");
  Car *cars[10];
  int i = 0;
  while (i < k/2) {
    if (itextFile.eof()) {
      itextFile.close();
      break;
    }
    Car tempCar2;
    itextFile.read((char *) &tempCar2, sizeof(Car));
    cars[i] = &tempCar2;
    std::cout << tempCar2.brand << ' ' << tempCar2.model << ' ' << tempCar2.price << '\n';
    i++;
  }
  return 0;
}

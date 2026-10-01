#include <string>
#include <iostream>

using namespace std;

class Car
{
  // Private nariai pasiekiami tik klases viduje
private:
  string brand;
  int year;
  double price;
  char fuelType;
  bool isStarted;

protected:
  // Protected nariai pasiekiami sioje klaseje ir is jos paveldetose klasese
  int mileage;

public:
  // Nariai pasiekiami iš išorės
  // Numatytasis konstruktorius
  Car()
  {
    brand = "Nezinoma";
    year = 0;
    price = 0.0;
    fuelType = 'D';
    isStarted = false;
    mileage = 0;
  }

  // Konstruktorius su parametrais
  Car(string brand, int year, double price, char fuelType, int mileage)
  {
    this->brand = brand;
    this->year = year;
    this->price = price;
    this->fuelType = fuelType;
    this->isStarted = false;
    this->mileage = mileage;
  }

  // Kopijavimo konstruktorius
  Car(const Car &otherCar)
  {
    brand = otherCar.brand;
    year = otherCar.year;
    price = otherCar.price;
    fuelType = otherCar.fuelType;
    isStarted = otherCar.isStarted;
    mileage = otherCar.mileage;
  }

  void changePrice(double newPrice)
  {
    price = newPrice;
  }

  void changeMileage(int newMileage)
  {
    mileage = newMileage;
  }

  void startStop()
  {
    isStarted = !isStarted;
  }

  void showInfoInLT()
  {
    cout << "Marke: " << brand << endl;
    cout << "Metai: " << year << endl;
    cout << "Kaina: " << price << " EUR" << endl;
    cout << "Kuro tipas: " << fuelType << endl;
    cout << "Rida: " << mileage << " km" << endl;
    cout << "Uzvestas: " << (isStarted ? "Taip" : "Ne") << endl;
  }
};

int main()
{
  // Objektas sukuriamas naudojant numatytaji konstruktoriu
  Car car1;
  cout << "\nNumatomi automobilio duomenys:\n"
       << endl;
  car1.showInfoInLT();
  cout << "----------------\n\n";

  Car car2("Honda", 1998, 1800.50, 'B', 250000);
  cout << "Įvesti automobilio duomenys:\n"
       << endl;
  car2.showInfoInLT();
  cout << "----------------\n";

  // Automobilio duomenu keitimas
  car2.changePrice(1600.00);
  car2.changeMileage(255000);
  car2.startStop();

  cout << endl;
  cout << "Duomenys po pakeitimu:" << endl;
  car2.showInfoInLT();
  cout << "----------------\n";

  Car car3(car2);
  cout << "Nukopijuoto objekto duomenys su pakeitimu\n";
  car3.startStop();
  car3.showInfoInLT();
  return 0;
}
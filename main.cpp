#include <iostream>
#include <map>
#include <fstream>

using namespace std;

struct Car {
    string marka;
    string model;
    int moc;
};

void add_car(string key, Car new_car) {
    ofstream File("Save_file", ios::out|ios::app);
    File << key << endl;
    File << new_car.marka << endl;
    File << new_car.model << endl;
    File << new_car.moc << endl;
    File.close();
}

map<string, Car> load_car() {
    map<string, Car> garage;
    ifstream car_list("Save_file");
    string text;                        //zmienna pomocnicza
    string key;  
    Car input;                       //zmienna pomocnicza
    int loop_quantity = 0;
    while(getline(car_list, text)) {
       switch(loop_quantity) {
        case 0:
            key = text;
            garage.insert({key, input});
            break;
        case 1:
            garage.at(key).marka = text;
            break;
        case 2:
            garage.at(key).model = text;
            break;
        case 3:
            garage.at(key).moc = stoi(text);
            loop_quantity = -1;
            break;
       }
       loop_quantity++;
    }
    return garage;
}

int main () {
    map<string, Car> garage = load_car();
    while (true) {
        cout << "Aby wyswietlic liste aut nacisnij 1" << endl;
        cout << " Aby dodac nowe auto nacisnij 2" << endl;
        int a;
        cin >> a;

        if(a==1) {
            cout << "Lista :" << endl;
            for (auto car : garage) {
                cout << car.first << endl;
            }
            cout << "Aby wyświetlić specyfikacje auta, wpisz jego nazwę: ";
            string szukaj_auta;
            cin >> szukaj_auta;
            if(garage.count(szukaj_auta)) {
                 cout << garage[szukaj_auta].moc << endl;
                 cout << garage[szukaj_auta].marka << " " << garage[szukaj_auta].model << endl;

            }

        }
        else {
            Car krankenwagen;
            string nazwa_auta;
            cout << "Podaj nazwe auta: ";
            cin >> nazwa_auta;
            cout << "Podaj marke auta: ";
            cin >> krankenwagen.marka;
            cout << "Podaj model: ";
            cin >> krankenwagen.model;;
            cout << "Podaj moc tego szatana: ";
            cin >> krankenwagen.moc;
            garage.insert({nazwa_auta, krankenwagen});
            add_car(nazwa_auta, krankenwagen);
        }
    }

    return 0;
}

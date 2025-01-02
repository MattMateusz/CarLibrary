#include <iostream>
#include <map>

using namespace std;

struct Car {
    string marka;
    string model;
    int moc;
};


int main () {
    map<string, Car> garage;
    while (true) {
        cout << "Aby wyswietlic liste aut nacisnij 1" << endl;
        cout << " Aby dodac nowe auto nacisnij 2" << endl;
        int a;
        cin >> a;

        if (a==1) {
            cout << "LIsta :" << endl;
            for (auto car : garage) {
                cout << car.first << endl;
            }
            string szukaj_auta;
            cin >> szukaj_auta;
            if (garage.contains(szukaj_auta)) {
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
        }
    }

    return 0;
}

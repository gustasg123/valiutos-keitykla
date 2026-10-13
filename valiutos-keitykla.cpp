#include <iostream>
#include <iomanip>
using namespace std;

const double GBP_Bendras = 0.8729;
const double GBP_Pirkti = 0.8600;
const double GBP_Parduoti = 0.9220;

const double USD_Bendras = 1.1793;
const double USD_Pirkti = 1.1460;
const double USD_Parduoti = 1.230;

const double INR_Bendras = 104.6918;
const double INR_Pirkti = 101.3862;
const double INR_Parduoti = 107.8546;

void rodytiMeniu() {
    cout << "\n========== VALIUTOS KEITIMAS ==========\n";
    cout << "1. Valiutos kursu palyginimas su euru\n";
    cout << "2. Valiutos pirkimas (EUR -> valiuta)\n";
    cout << "3. Valiutos pardavimas (valiuta -> EUR)\n";
    cout << "4. Iseiti\n";
    cout << "=======================================\n";
    cout << "Pasirinkite veiksma (1-4): ";
}

void rodytiValiutuMeniu() {
    cout << "\n---------- PASIRINKITE VALIUTA ----------\n";
    cout << "1. GBP - Didziosios Britanijos svaras\n";
    cout << "2. USD - JAV doleris\n";
    cout << "3. INR - Indijos rupija\n";
    cout << "-----------------------------------------\n";
    cout << "Jusu pasirinkimas: ";
}

double pirktiValiuta(double suma, double kursas) {
    return suma * kursas;
}

double parduotiValiuta(double suma, double kursas) {
    return suma / kursas;
}

int main() {
    int pasirinkimas, valiuta;
    double suma, rezultatas;

    do {
        rodytiMeniu();
        cin >> pasirinkimas;

        switch (pasirinkimas) {
        case 1:
            cout << fixed << setprecision(2);
            rodytiValiutuMeniu();
            cin >> valiuta;

            switch (valiuta) {
            case 1:
                cout << "Uz 1 EUR gauname "
                     << GBP_Bendras << " GBP\n";
                break;
            case 2:
                cout << "Uz 1 EUR gauname "
                     << USD_Bendras << " USD\n";
                break;
            case 3:
                cout << "Uz 1 EUR gauname "
                     << INR_Bendras << " INR\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas.\n";
            }
            break;

        case 2:
            cout << fixed << setprecision(2);
            rodytiValiutuMeniu();
            cin >> valiuta;

            switch (valiuta) {
            case 1:
                cout << "Iveskite suma EUR, kuria norite keisti i GBP: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Suma turi buti didesne uz nuli.\n";
                    break;
                }

                rezultatas = pirktiValiuta(suma, GBP_Pirkti);
                cout << suma << " EUR -> "
                     << rezultatas << " GBP\n";
                break;

            case 2:
                cout << "Iveskite suma EUR, kuria norite keisti i USD: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Suma turi buti didesne uz nuli.\n";
                    break;
                }

                rezultatas = pirktiValiuta(suma, USD_Pirkti);
                cout << suma << " EUR -> "
                     << rezultatas << " USD\n";
                break;

            case 3:
                cout << "Iveskite suma EUR, kuria norite keisti i INR: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Suma turi buti didesne uz nuli.\n";
                    break;
                }

                rezultatas = pirktiValiuta(suma, INR_Pirkti);
                cout << suma << " EUR -> "
                     << rezultatas << " INR\n";
                break;

            default:
                cout << "Neteisingas pasirinkimas.\n";
            }
            break;

        case 3:
            cout << fixed << setprecision(2);
            rodytiValiutuMeniu();
            cin >> valiuta;

            switch (valiuta) {
            case 1:
                cout << "Iveskite suma GBP, kuria norite keisti i EUR: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Suma turi buti didesne uz nuli.\n";
                    break;
                }

                rezultatas = parduotiValiuta(suma, GBP_Parduoti);
                cout << suma << " GBP / " << GBP_Parduoti
                     << " = " << rezultatas << " EUR\n";
                break;

            case 2:
                cout << "Iveskite suma USD, kuria norite keisti i EUR: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Suma turi buti didesne uz nuli.\n";
                    break;
                }

                rezultatas = parduotiValiuta(suma, USD_Parduoti);
                cout << suma << " USD / " << USD_Parduoti
                     << " = " << rezultatas << " EUR\n";
                break;

            case 3:
                cout << "Iveskite suma INR, kuria norite keisti i EUR: ";
                cin >> suma;

                if (suma <= 0) {
                    cout << "Suma turi buti didesne uz nuli.\n";
                    break;
                }

                rezultatas = parduotiValiuta(suma, INR_Parduoti);
                cout << suma << " INR / " << INR_Parduoti
                     << " = " << rezultatas << " EUR\n";
                break;

            default:
                cout << "Neteisingas pasirinkimas.\n";
            }
            break;

        case 4:
            cout << "Programa baigta.\n";
            break;

        default:
            cout << "Pasirinkite skaiciu nuo 1 iki 4.\n";
        }

    } while (pasirinkimas != 4);

    return 0;
}
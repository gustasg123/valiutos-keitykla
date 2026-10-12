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
	cout << "1. Valiutos kurso palyginimas su euru.\n";
	cout << "2. Valiutos pirkimas (EUR -> pasirinkta valiuta).\n";
	cout << "3. Valiutos pardavimas (pasirinkta valiuta -> EUR).\n";
	cout << "4. Iseiti.\n";
}

double pirktiValiuta(double suma, double kursas) {
	return suma * kursas;
}

double parduotiValiuta(double suma, double kursas) {
	return suma / kursas;
}

int main() {
	int pasirinkimas;
	double suma, rezultatas;

	do {
		rodytiMeniu();
		cout << "Pasirinkite veiksma (1-4): ";
		cin >> pasirinkimas;

		switch (pasirinkimas) {
		case 1:
			cout << fixed << setprecision(2);
			cout << "Pasirinkite valiuta:\n";
			cout << "1. GBP\n";
			cout << "2. USD\n";
			cout << "3. INR\n";
			int valiuta;
			cin >> valiuta;
			switch (valiuta) {
			case 1:
				cout << "Uz 1 EUR gauname " << GBP_Bendras << " GBP\n";
				break;
			case 2:
				cout << "Uz 1 EUR gauname " << USD_Bendras << " USD\n";
				break;
			case 3:
				cout << "Uz 1 EUR gauname " << INR_Bendras << " INR\n";
				break;
			default:
				cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
			}
			break;
		case 2:
			cout << fixed << setprecision(2);
			cout << "Pasirinkite valiuta:\n";
			cout << "1. GBP\n";
			cout << "2. USD\n";
			cout << "3. INR\n";
			cin >> valiuta;
			switch (valiuta) {
			case 1:
				cout << "Iveskite suma EUR, kuria noresite pirkti GBP: ";
				cin >> suma;
				if (suma < 0) {
					cout << "Suma negali buti neigiama. Bandykite dar karta.\n";
					break;
				}
				rezultatas = pirktiValiuta(suma, GBP_Pirkti);
				cout << suma << " EUR -> GBP pirkimas = " << rezultatas << " GBP.\n";
				break;
			case 2:
				cout << "Iveskite suma EUR, kuria noresite pirkti USD: ";
				cin >> suma;
				if (suma < 0) {
					cout << "Suma negali buti neigiama. Bandykite dar karta.\n";
					break;
				}
				rezultatas = pirktiValiuta(suma, USD_Pirkti);
				cout << suma << " EUR -> USD pirkimas = " << rezultatas << " USD.\n";
				break;
			case 3:
				cout << "Iveskite suma EUR, kuria noresite pirkti INR: ";
				cin >> suma;
				if (suma < 0) {
					cout << "Suma negali buti neigiama. Bandykite dar karta.\n";
					break;
				}
				rezultatas = pirktiValiuta(suma, INR_Pirkti);
				cout << suma << " EUR -> INR pirkimas = " << rezultatas << " INR.\n";
				break;
			default:
				cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
			}
			break;
		case 3:
			cout << fixed << setprecision(2);
			cout << "Pasirinkite valiuta:\n";
			cout << "1. GBP\n";
			cout << "2. USD\n";
			cout << "3. INR\n";
			cin >> valiuta;
			switch (valiuta) {
			case 1:
				cout << "Iveskite suma GBP, kuria noresite parduoti EUR: ";
				cin >> suma;
				if (suma < 0) {
					cout << "Suma negali buti neigiama. Bandykite dar karta.\n";
					break;
				}
				rezultatas = parduotiValiuta(suma, GBP_Parduoti);
				cout << suma << " GBP pardavimas = " << suma << " / " << GBP_Parduoti << " = " << rezultatas << " EUR.\n";
				break;
			case 2:
				cout << "Iveskite suma USD, kuria noresite parduoti EUR: ";
				cin >> suma;
				if (suma < 0) {
					cout << "Suma negali buti neigiama. Bandykite dar karta.\n";
					break;
				}
				rezultatas = parduotiValiuta(suma, USD_Parduoti);
				cout << suma << " USD pardavimas = " << suma << " / " << USD_Parduoti << " = " << rezultatas << " EUR.\n";
				break;
			case 3:
				cout << "Iveskite suma INR, kuria noresite parduoti EUR: ";
				cin >> suma;
				if (suma < 0) {
					cout << "Suma negali buti neigiama. Bandykite dar karta.\n";
					break;
				}
				rezultatas = parduotiValiuta(suma, INR_Parduoti);
				cout << suma << " INR pardavimas = " << suma << " / " << INR_Parduoti << " = " << rezultatas << " EUR.\n";
				break;
			default:
				cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
			}
			break;
		case 4:
			cout << "Iseinate is programos.\n";
			break;
		default:
			cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
		}
	} while (pasirinkimas != 4);

	return 0;
}
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void wyswietl_pracownikow(), edytuj_pracownika(int numer), usun_pracownika(int numer);
class Pracownik {
protected:
	string imie;
	string nazwisko;
	int wynagrodzenie;
public:
	Pracownik(string imie, string nazwisko, int wynagrodzenie) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->wynagrodzenie = wynagrodzenie;
	}

	string getImie() {
		return imie;
	}
	string getNazwisko() {
		return nazwisko;
	}
	int getWynagrodzenie() {
		return wynagrodzenie;
	}
};
vector<Pracownik> Pracownicy;
void wyswietl_pracownikow() {
	Pracownicy.clear();
	ifstream plik("Pracownicy.txt");
	string imie, nazwisko;
	int wynagrodzenie;
	if (plik.is_open()) {
		while (plik >> imie >> nazwisko >> wynagrodzenie) {
			Pracownik p1 = Pracownik(imie, nazwisko, wynagrodzenie);
			Pracownicy.push_back(p1);

		}
		plik.close();
	}
	cout << "Pracownicy" << endl;
	cout << "_____________________" << endl;
	cout << setw(10) << left << "Imie"
		<< setw(15) << left << "Nazwisko"
		<< setw(20) << left << "Wynagrodzenie" << endl;
	cout << "_____________________________________________" << endl;
	for (int i = 0; i < Pracownicy.size(); i++) {
		cout << setw(10) << left << Pracownicy[i].getImie()
			<< setw(15) << left << Pracownicy[i].getNazwisko()
			<< setw(20) << left << Pracownicy[i].getWynagrodzenie() << endl;
	}
}
void dodajPracownika() {
	string imie, nazwisko;
	int wynagrodzenie;
	cout << "Podaj Imie Pracownika" << endl;
	cin >> imie;
	cout << "Podaj Nazwisko Pracownika" << endl;
	cin >> nazwisko;
	cout << "Podaj Wynagrodzenie Pracownika" << endl;
	cin >> wynagrodzenie;
	ofstream plik("Pracownicy.txt", ios::app);
	if (plik.is_open()) {
		plik << imie << " " << nazwisko << " " << wynagrodzenie << endl;
	}
	plik.close();

}
void edytuj_pracownika(int numer) {
	system("cls");
	ifstream plik("Pracownicy.txt");
	ofstream plik_temp("temp.txt");
	string imie, nazwisko, linia, nowy_string;
	int wynagrodzenie, aktualna_linia = 0, wybor, nowe_wynagrodzenie;
	while (getline(plik, linia)) {
		if (aktualna_linia == numer - 1) {
			plik >> imie >> nazwisko >> wynagrodzenie;
			cout << "Pracownik" << endl;
			cout << "_____________________" << endl;
			cout << setw(10) << left << "Imie"
				<< setw(15) << left << "Nazwisko"
				<< setw(20) << left << "Wynagrodzenie" << endl;
			cout << "_____________________________________________" << endl;
			cout << setw(10) << left << Pracownicy[aktualna_linia].getImie()
				<< setw(15) << left << Pracownicy[aktualna_linia].getNazwisko()
				<< setw(20) << left << Pracownicy[aktualna_linia].getWynagrodzenie() << endl;
			cout << "Co chciałbyś edytować?" << endl;
			cout << "1. Imie" << endl;
			cout << "2. Nazwisko" << endl;
			cout << "3. Wynagrodzenie" << endl;
			cout << "Wybór: ";
			cin >> wybor;
			if (wybor == 1) {
				cout << "Podaj nowe imie dla pracownika " << Pracownicy[aktualna_linia].getImie() << " -> ";
				cin >> nowy_string;
				plik_temp << nowy_string << " " << Pracownicy[aktualna_linia].getNazwisko() << " " << Pracownicy[aktualna_linia].getWynagrodzenie() << endl;
			}
			if (wybor == 2) {
				cout << "Podaj nowe nazwisko dla pracownika " << Pracownicy[aktualna_linia].getImie() << " " << Pracownicy[aktualna_linia].getNazwisko() << " -> ";
				cin >> nowy_string;
				plik_temp << Pracownicy[aktualna_linia].getImie() << " " << nowy_string << " " << Pracownicy[aktualna_linia].getWynagrodzenie() << endl;
			}
			if (wybor == 3) {
				cout << "Podaj nowe wynagrodzenie dla pracownika " << Pracownicy[aktualna_linia].getImie() << " " << Pracownicy[aktualna_linia].getNazwisko() << " " << Pracownicy[aktualna_linia].getWynagrodzenie() << " -> ";
				cin >> nowe_wynagrodzenie;
				plik_temp << Pracownicy[aktualna_linia].getImie() << " " << Pracownicy[aktualna_linia].getNazwisko() << " " << nowe_wynagrodzenie << endl;
			}
		}
		else {
			plik_temp << Pracownicy[aktualna_linia].getImie() << " " << Pracownicy[aktualna_linia].getNazwisko() << " " << Pracownicy[aktualna_linia].getWynagrodzenie() << endl;
		}
		aktualna_linia++;
	}
	plik.close();
	plik_temp.close();
	remove("Pracownicy.txt");
	rename("temp.txt", "Pracownicy.txt");


	Pracownicy.clear();
	ifstream plik3("Pracownicy.txt");
	if (plik3.is_open()) {
		while (plik3 >> imie >> nazwisko >> wynagrodzenie) {
			Pracownik p1 = Pracownik(imie, nazwisko, wynagrodzenie);
			Pracownicy.push_back(p1);

		}
		plik3.close();
	}
}
void usun_pracownika(int numer) {
	system("cls");
	ifstream plik("Pracownicy.txt");
	ofstream plik_temp("temp.txt");
	string imie, nazwisko, linia, nowy_string;
	int wynagrodzenie, aktualna_linia = 0, wybor, nowe_wynagrodzenie;
	while (getline(plik, linia)) {
		if (aktualna_linia == numer - 1) {
		}
		else {
			plik_temp << Pracownicy[aktualna_linia].getImie() << " " << Pracownicy[aktualna_linia].getNazwisko() << " " << Pracownicy[aktualna_linia].getWynagrodzenie() << endl;
		}
		aktualna_linia++;
	}
	plik.close();
	plik_temp.close();
	remove("Pracownicy.txt");
	rename("temp.txt", "Pracownicy.txt");


	Pracownicy.clear();
	ifstream plik3("Pracownicy.txt");
	if (plik3.is_open()) {
		while (plik3 >> imie >> nazwisko >> wynagrodzenie) {
			Pracownik p1 = Pracownik(imie, nazwisko, wynagrodzenie);
			Pracownicy.push_back(p1);

		}
		plik3.close();
	}
}
class Menadzer: public Pracownik {
	string funkcja;
public: 
	Menadzer(string imie, string nazwisko, int wynagrodzenie, string funkcja):Pracownik(imie, nazwisko, wynagrodzenie) {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->wynagrodzenie = wynagrodzenie;
		this->funkcja = funkcja;
	}

	string getFunkcja() {
		return funkcja;
	}
};
vector<Menadzer> Menadzerowie;
void wyswietl_menadzerow() {
	Menadzerowie.clear();
	ifstream plik("Menadzerowie.txt");
	string imie, nazwisko, funkcja;
	int wynagrodzenie;
	if (plik.is_open()) {
		while (plik >> imie >> nazwisko >> wynagrodzenie >> funkcja) {
			Menadzer m1 = Menadzer(imie, nazwisko, wynagrodzenie, funkcja);
			Menadzerowie.push_back(m1);

		}
		plik.close();
	}
	cout << "Menadżerowie" << endl;
	cout << "_____________________" << endl;
	cout << setw(10) << left << "Imie"
		<< setw(15) << left << "Nazwisko"
		<< setw(20) << left << "Wynagrodzenie" <<
	 setw(20) << left << "Funkcja" << endl;
	cout << "_________________________________________________________________" << endl;
	for (int i = 0; i < Menadzerowie.size(); i++) {
		cout << setw(10) << left << Menadzerowie[i].Pracownik::getImie()
			<< setw(15) << left << Menadzerowie[i].Pracownik::getNazwisko()
			<< setw(20) << left << Menadzerowie[i].Pracownik::getWynagrodzenie()
			<< setw(20) << left << Menadzerowie[i].getFunkcja() << endl;
	}
}
void dodajmenadzera() {
	string imie, nazwisko, funkcja;
	int wynagrodzenie;
	cout << "Podaj Imie Menadżera" << endl;
	cin >> imie;
	cout << "Podaj Nazwisko Menadżera" << endl;
	cin >> nazwisko;
	cout << "Podaj Wynagrodzenie Menadżera" << endl;
	cin >> wynagrodzenie;
	cout << "Podaj Funkcje Menadżera" << endl;
	cin >> funkcja;
	ofstream plik("Menadzerowie.txt", ios::app);
	if (plik.is_open()) {
		plik << imie << " " << nazwisko << " " << wynagrodzenie << " " << funkcja << endl;
	}
	plik.close();

}
void edytuj_menadzera(int numer) {
	system("cls");
	ifstream plik("Menadzerowie.txt");
	ofstream plik_temp("temp.txt");
	string imie, nazwisko,funkcja, linia, nowy_string;
	int wynagrodzenie, aktualna_linia = 0, wybor, nowe_wynagrodzenie;
	while (getline(plik, linia)) {
		if (aktualna_linia == numer - 1) {
			plik >> imie >> nazwisko >> wynagrodzenie, funkcja;
			cout << "Menadzer" << endl;
			cout << "_____________________" << endl;
			cout << setw(10) << left << "Imie"
				<< setw(15) << left << "Nazwisko"
				<< setw(20) << left << "Wynagrodzenie"
				<< setw(20) << left << "Funkcja" << endl;
			cout << "_________________________________________________________________" << endl;
			cout << setw(10) << left << Menadzerowie[aktualna_linia].getImie()
				<< setw(15) << left << Menadzerowie[aktualna_linia].getNazwisko()
				<< setw(20) << left << Menadzerowie[aktualna_linia].getWynagrodzenie()
				<< setw(20) << left << Menadzerowie[aktualna_linia].getFunkcja() << endl;
			cout << "Co chciałbyś edytować?" << endl;
			cout << "1. Imie" << endl;
			cout << "2. Nazwisko" << endl;
			cout << "3. Wynagrodzenie" << endl;
			cout << "4. Funkcje" << endl;
			cout << "Wybór: ";
			cin >> wybor;
			if (wybor == 1) {
				cout << "Podaj nowe imie dla menadzera " << Menadzerowie[aktualna_linia].getImie() << " -> ";
				cin >> nowy_string;
				plik_temp << nowy_string << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << Menadzerowie[aktualna_linia].getWynagrodzenie()<<" " << Menadzerowie[aktualna_linia].getFunkcja() << endl;
			}
			if (wybor == 2) {
				cout << "Podaj nowe nazwisko dla menadzera " << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " -> ";
				cin >> nowy_string;
				plik_temp << Menadzerowie[aktualna_linia].getImie() << " " << nowy_string << " " << Menadzerowie[aktualna_linia].getWynagrodzenie()<<" " << Menadzerowie[aktualna_linia].getFunkcja() << endl;
			}
			if (wybor == 3) {
				cout << "Podaj nowe wynagrodzenie dla menadzera " << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << Menadzerowie[aktualna_linia].getFunkcja() <<" " << Menadzerowie[aktualna_linia].getWynagrodzenie() << " -> ";
				cin >> nowe_wynagrodzenie;
				plik_temp << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << nowe_wynagrodzenie << " " << Menadzerowie[aktualna_linia].getFunkcja() << endl;
			}
			if (wybor == 4) {
				cout << "Podaj nową funkcje dla menadzera " << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << Menadzerowie[aktualna_linia].getFunkcja() << " -> ";
				cin >> nowy_string;
				plik_temp << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << Menadzerowie[aktualna_linia].getWynagrodzenie() << " " << nowy_string << endl;
			}
		}
		else {
			plik_temp << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << Menadzerowie[aktualna_linia].getWynagrodzenie() << " " << Menadzerowie[aktualna_linia].getFunkcja() << endl;
		}
		aktualna_linia++;
	}
	plik.close();
	plik_temp.close();
	remove("Menadzerowie.txt");
	rename("temp.txt", "Menadzerowie.txt");

	Menadzerowie.clear();
	ifstream plik3("Menadzerowie.txt");
	if (plik3.is_open()) {
		while (plik3 >> imie >> nazwisko >> wynagrodzenie >> funkcja) {
			Menadzer m1 = Menadzer(imie, nazwisko, wynagrodzenie, funkcja);
			Menadzerowie.push_back(m1);

		}
		plik3.close();
	}
}
void usun_menadzera(int numer) {
	system("cls");
	ifstream plik("Menadzerowie.txt");
	ofstream plik_temp("temp.txt");
	string imie, nazwisko, linia, nowy_string, funkcja;
	int wynagrodzenie, aktualna_linia = 0, wybor, nowe_wynagrodzenie;
	while (getline(plik, linia)) {
		if (aktualna_linia == numer - 1) {
		}
			else {
			plik_temp << Menadzerowie[aktualna_linia].getImie() << " " << Menadzerowie[aktualna_linia].getNazwisko() << " " << Menadzerowie[aktualna_linia].getWynagrodzenie() << " " << Menadzerowie[aktualna_linia].getFunkcja() << endl;
			}
			aktualna_linia++;
		}
		plik.close();
		plik_temp.close();
		remove("Menadzerowie.txt");
		rename("temp.txt", "Menadzerowie.txt");
		remove("temp.txt");


		Pracownicy.clear();
		ifstream plik3("Menadzerowie.txt");
		if (plik3.is_open()) {
			while (plik3 >> imie >> nazwisko >> wynagrodzenie >> funkcja) {
				Menadzer m1 = Menadzer(imie, nazwisko, wynagrodzenie, funkcja);
				Menadzerowie.push_back(m1);

			}
			plik3.close();
		}
}
class Kierownik :public Menadzer {
	string dzial;
public:
	Kierownik(string imie, string nazwisko, int wynagrodzenie, string dzial):Menadzer(imie, nazwisko, wynagrodzenie,"") {
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->wynagrodzenie = wynagrodzenie;
		this->dzial = dzial;
	}
		string getDzial() {
			return dzial;
	}
};
vector<Kierownik> Kierownicy;
void wyswietl_kierownikow() {
	Kierownicy.clear();
	ifstream plik("Kierownicy.txt");
	string imie, nazwisko, dzial;
	int wynagrodzenie;
	if (plik.is_open()) {
		while (plik >> imie >> nazwisko >> wynagrodzenie  >> dzial) {
			Kierownik k1 = Kierownik(imie, nazwisko, wynagrodzenie, dzial);
			Kierownicy.push_back(k1);

		}
		plik.close();
	}
	cout << "Kierownicy" << endl;
	cout << "_____________________" << endl;
	cout << setw(10) << left << "Imie"
		<< setw(15) << left << "Nazwisko"
		<< setw(20) << left << "Wynagrodzenie" <<
		setw(20) << left << "Dział" << endl;
	cout << "_________________________________________________________________" << endl;
	for (int i = 0; i < Kierownicy.size(); i++) {
		cout << setw(10) << left << Kierownicy[i].Pracownik::getImie()
			<< setw(15) << left << Kierownicy[i].Pracownik::getNazwisko()
			<< setw(20) << left << Kierownicy[i].Pracownik::getWynagrodzenie()
			<< setw(20) << left << Kierownicy[i].getDzial() << endl;
	}
}
void dodajkierownika() {
	string imie, nazwisko, dzial;
	int wynagrodzenie;
	cout << "Podaj Imie Kierownika" << endl;
	cin >> imie;
	cout << "Podaj Nazwisko Kierownika" << endl;
	cin >> nazwisko;
	cout << "Podaj Wynagrodzenie Kierownika" << endl;
	cin >> wynagrodzenie;
	cout << "Podaj Dział Kierownika" << endl;
	cin >> dzial;
	ofstream plik("Kierownicy.txt", ios::app);
	if (plik.is_open()) {
		plik << imie << " " << nazwisko << " " << wynagrodzenie << " " << dzial << endl;
	}
	plik.close();

}
void edytuj_kierownika(int numer) {
	system("cls");
	ifstream plik("Kierownicy.txt");
	ofstream plik_temp("temp.txt");
	string imie, nazwisko, dzial, linia, nowy_string;
	int wynagrodzenie, aktualna_linia = 0, wybor, nowe_wynagrodzenie;
	while (getline(plik, linia)) {
		if (aktualna_linia == numer - 1) {
			plik >> imie >> nazwisko >> wynagrodzenie, dzial;
			cout << "Kierownik" << endl;
			cout << "_____________________" << endl;
			cout << setw(10) << left << "Imie"
				<< setw(15) << left << "Nazwisko"
				<< setw(20) << left << "Wynagrodzenie"
				<< setw(20) << left << "Dział" << endl;
			cout << "_________________________________________________________________" << endl;
			cout << setw(10) << left << Kierownicy[aktualna_linia].getImie()
				<< setw(15) << left << Kierownicy[aktualna_linia].getNazwisko()
				<< setw(20) << left << Kierownicy[aktualna_linia].getWynagrodzenie()
				<< setw(20) << left << Kierownicy[aktualna_linia].getDzial() << endl;
			cout << "Co chciałbyś edytować?" << endl;
			cout << "1. Imie" << endl;
			cout << "2. Nazwisko" << endl;
			cout << "3. Wynagrodzenie" << endl;
			cout << "4. Dział" << endl;
			cout << "Wybór: ";
			cin >> wybor;
			if (wybor == 1) {
				cout << "Podaj nowe imie dla kierownika " << Kierownicy[aktualna_linia].getImie() << " -> ";
				cin >> nowy_string;
				plik_temp << nowy_string << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " " << Kierownicy[aktualna_linia].getDzial() << endl;
			}
			if (wybor == 2) {
				cout << "Podaj nowe nazwisko dla kierownika " << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " -> ";
				cin >> nowy_string;
				plik_temp << Kierownicy[aktualna_linia].getImie() << " " << nowy_string << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " " << Kierownicy[aktualna_linia].getDzial() << endl;
			}
			if (wybor == 3) {
				cout << "Podaj nowe wynagrodzenie dla kierownika " << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << Kierownicy[aktualna_linia].getDzial() << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " -> ";
				cin >> nowe_wynagrodzenie;
				plik_temp << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << nowe_wynagrodzenie << " " << Kierownicy[aktualna_linia].getDzial() << endl;
			}
			if (wybor == 4) {
				cout << "Podaj nowy dział dla kierownika " << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " " << Kierownicy[aktualna_linia].getDzial() << " -> ";
				cin >> nowy_string;
				plik_temp << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " " << nowy_string << endl;
			}
		}
		else {
			plik_temp << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " " << Kierownicy[aktualna_linia].getDzial() << endl;
		}
		aktualna_linia++;
	}
	plik.close();
	plik_temp.close();
	remove("Kierownicy.txt");
	rename("temp.txt", "Kierownicy.txt");

	Pracownicy.clear();
	ifstream plik3("Kierownicy.txt");
	if (plik3.is_open()) {
		while (plik3 >> imie >> nazwisko >> wynagrodzenie >> dzial) {
			Kierownik k1 = Kierownik(imie, nazwisko, wynagrodzenie, dzial);
			Kierownicy.push_back(k1);

		}
		plik3.close();
	}
}
void usun_kierownika(int numer) {
	system("cls");
	ifstream plik("Kierownicy.txt");
	ofstream plik_temp("temp.txt");
	string imie, nazwisko, linia, nowy_string, dzial;
	int wynagrodzenie, aktualna_linia = 0, wybor, nowe_wynagrodzenie;
	while (getline(plik, linia)) {
		if (aktualna_linia == numer - 1) {
		}
		else {
			plik_temp << Kierownicy[aktualna_linia].getImie() << " " << Kierownicy[aktualna_linia].getNazwisko() << " " << Kierownicy[aktualna_linia].getWynagrodzenie() << " " << Kierownicy[aktualna_linia].getDzial() << endl;
		}
		aktualna_linia++;
	}
	plik.close();
	plik_temp.close();
	remove("Kierownicy.txt");
	rename("temp.txt", "Kierownicy.txt");
	remove("temp.txt");
	Pracownicy.clear();
	ifstream plik3("Kierownicy.txt");
	if (plik3.is_open()) {
		while (plik3 >> imie >> nazwisko >> wynagrodzenie >> dzial) {
			Kierownik k1 = Kierownik(imie, nazwisko, wynagrodzenie, dzial);
			Kierownicy.push_back(k1);

		}
		plik3.close();
	}
}
void wyswietl_menu(){
	system("cls");
	int wybor, wynagrodzenie, wybierz;
	string imie, nazwisko;
	cout << "Firma" << endl;
	cout << "_____________________" << endl;
	cout << "Menu" << endl;
	cout << "_____________________" << endl;
	cout << "Pracownicy" << endl;
	cout << "_____________________" << endl;
	cout << "1. Wyświetl pracowników" << endl;
	cout << "2. Dodaj pracownika" << endl;
	cout << "3. Edytuj pracownika" << endl;
	cout << "4. Usuń pracownika" << endl;
	cout << "_____________________" << endl;
	cout << "Menadżerowie" << endl;
	cout << "_____________________" << endl;
	cout << "5. Wyświetl menadzerów." << endl;
	cout << "6. Dodaj menadzera" << endl;
	cout << "7. Edytuj menadzera" << endl;
	cout << "8. Usuń menadzera" << endl;
	cout << "_____________________" << endl;
	cout << "Kierownicy" << endl;
	cout << "_____________________" << endl;
	cout << "9. Wyświetl kierownikow." << endl;
	cout << "10. Dodaj kierownika" << endl;
	cout << "11.Edytuj kierownika" << endl;
	cout << "12. Usuń kierownika" << endl;
	cout << "_____________________" << endl;
	cout << "Wybór: "; cin >> wybor;
	if (wybor == 1) {
		system("cls");
		wyswietl_pracownikow();
		_getch();
	}
	if (wybor == 2) {
		system("cls");
		dodajPracownika();
		_getch();
	}
	if (wybor == 3) {
		system("cls");
		wyswietl_pracownikow();
		cout << "Wybierz pracownika którego chcesz edytować" << endl << "Wybor: ";
		cin >> wybierz;
		edytuj_pracownika(wybierz);
	}
	if (wybor == 4) {
		system("cls");
		wyswietl_pracownikow();
		cout << "Wybierz pracownika którego chcesz usunąć" << endl << "Wybor: ";
		cin >> wybierz;
		usun_pracownika(wybierz);
	}
	if (wybor == 5) {
		system("cls");
		wyswietl_menadzerow();
		_getch();
	}
	if (wybor == 6) {
		system("cls");
		dodajmenadzera();
		_getch();
	}
	if (wybor == 7) {
		system("cls");
		wyswietl_menadzerow();
		cout << "Wybierz menadżera którego chcesz edytować" << endl << "Wybor: ";
		cin >> wybierz;
		edytuj_menadzera(wybierz);
	}
	if (wybor == 8) {
		system("cls");
		wyswietl_menadzerow();
		cout << "Wybierz menadżera którego chcesz usunąć" << endl << "Wybor: ";
		cin >> wybierz;
		usun_menadzera(wybierz);
	}
	if (wybor == 9) {
		system("cls");
		wyswietl_kierownikow();
		_getch();
	}
	if (wybor == 10) {
		system("cls");
		dodajkierownika();
		_getch();
	}
	if (wybor == 11) {
		system("cls");
		wyswietl_kierownikow();
		cout << "Wybierz kierownika którego chcesz edytować" << endl << "Wybor: ";
		cin >> wybierz;
		edytuj_kierownika(wybierz);
	}
	if (wybor == 12) {
		system("cls");
		wyswietl_kierownikow();
		cout << "Wybierz kierownika którego chcesz usunąć" << endl << "Wybor: ";
		cin >> wybierz;
		usun_kierownika(wybierz);
	}
	wyswietl_menu();
}
int main()
{
	setlocale(LC_CTYPE, "Polish");
	wyswietl_menu();
	main();
}

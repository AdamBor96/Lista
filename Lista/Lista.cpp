#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "mylib.h"
#include "mylib2.h"

using namespace std;

int main()
{
	fstream file;
	vector<Person>students;

	// PONIŻEJ GOTOWA LISTA
	students.push_back({ "Jan", "Kowalski" });
	students[0].add_Subject("Podstawy programowania");
	students[0].set_pkt_grades(&students[0], 1, 0.7, 1, 1, 0.7, 0.9, 1, 1, 1, 1, 1); // <--- PUNKTY Z KOLOKWIUM JAKO ARGUMENTY

	students.push_back({ "Miroslaw", "Nowak" });
	students[1].add_Subject("Podstawy programowania");
	students[1].set_pkt_grades(&students[1], 1, 0.7, 0, 1, 0.9, 0, 0, 0.6, 1, 0.5, 1);

	students.push_back({ "Alina", "Wisniewska" });
	students[2].add_Subject("Podstawy programowania");
	students[2].set_pkt_grades(&students[2], 1, 1, 1, 1, 0.7, 0.6, 1, 0.8, 1, 0.8, 1);

	students.push_back({ "Jan", "Nowak" });
	students[3].add_Subject("Podstawy programowania");
	students[3].set_pkt_grades(&students[3], 0.5, 0.7, 0.7, 1, 0.9, 0.8, 1, 1, 1, 0.8, 1);

	students.push_back({ "Czeslaw", "Milosz" });
	students[4].add_Subject("Podstawy programowania");
	students[4].set_pkt_grades(&students[4], 1, 1, 0.6, 1, 0.5, 0, 0.3, 0.8, 1, 1, 0.3);

	students.push_back({ "Mikolaj", "Lewandowski" });
	students[5].add_Subject("Podstawy programowania");
	students[5].set_pkt_grades(&students[5], 1, 1, 0.7, 1, 0.9, 0.6, 1, 0.6, 1, 1, 1);

	int wybor;
	//PONIŻEJ MENU GŁÓWNE
	for (;;)
	{
		menu();
		cout << "Wybierz: "; 
		cin >> wybor;
		check_cin(wybor);
		switch (wybor)
		{
		// 1 - WYŚWIETLA LISTĘ STUDENTÓW
		case 1:
		{
			system("cls");
			for (int i = 0; i < students.size(); i++)
			{
				oddziel();
				students[i].show_Student();
				students[i].show_Subject();
				students[i].show_pkt_and_grades(&students[i]);
			}
			break;
		}
		// 2 - OPCJA DODANIA NOWEGO STUDENTA DO LISTY
		case 2:
		{
			string imie, nazwisko, przedmiot;
			float pkt[2][6];

			system("cls");
			cout << endl << "Imie: ";
			cin >> imie;
			cout << "Nazwisko: ";
			cin >> nazwisko;
			students.push_back({ imie, nazwisko });
			cout << "Nazwa przedmiotu: ";
			cin >> przedmiot;
			students[students.size() - 1].add_Subject(przedmiot); // dodać możliwość wybrania przedmiotu
			cout << endl << "Wpisz uzyskane punkty z zadan z pierwszego kolokwium:" << endl;
			for (int j = 0; j < 6; j++)
			{
				cout << "z" << j + 1 << ": ";
				cin >> pkt[0][j];
				while (cin.fail())
				{
					cout << "Wpisz cyfre: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> pkt[0][j];
				};
				if (pkt[0][j] > 1)
				{
					cout << "Maksymalna dopuszczalna ilosc punktow to 1." << endl;
					j--;
				}
			}
			cout << endl << "Wpisz uzyskane punkty z zadan z drugiego kolokwium:" << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << "z" << j + 1 << ": ";
				cin >> pkt[1][j];
				while (cin.fail())
				{
					cout << "Wpisz cyfre: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> pkt[1][j];
				};
				if (pkt[1][j] > 1)
				{
					cout << "Maksymalna dopuszczalna ilosc punktow to 1." << endl;
					j--;
				}
			}
			students[students.size() - 1].set_pkt_grades(&students[students.size() - 1], pkt[0][0], pkt[0][1], pkt[0][2], pkt[0][3], pkt[0][4], pkt[0][5], pkt[1][0], pkt[1][1], pkt[1][2], pkt[1][3], pkt[1][4]);
			system("cls");
			cout << "ZAPISANO NOWEGO STUDENTA.";
			oddziel();
			students[students.size() - 1].show_Student();
			students[students.size() - 1].show_Subject();
			students[students.size() - 1].show_pkt_and_grades(&students[students.size() - 1]);
			break;
		}
		// 3 - USUNIĘCIE STUDENTA Z LISTY
		case 3:
		{
			int selected_number;
			system("cls");
			for (int i = 0; i < students.size(); i++)
			{
				cout << "[" << i + 1 << "] - " << students[i].get_Name() << " " << students[i].get_Surname() << endl;
			}
			cout << "[" << students.size() + 1 << "] - WROC DO MENU" << endl;
			cout << "Wybierz do usuniecia: ";
			cin >> selected_number;
			while (cin.fail())
			{
				cout << "Wpisz cyfre: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> selected_number;
			};
			while ((selected_number < 1) || (selected_number > students.size() + 1))
			{
				cout << endl << "Wybierz od 1 do " << students.size() + 1 << endl;
				cout << "Wybierz do usuniecia: ";
				cin >> selected_number;
				while (cin.fail())
				{
					cout << "Wpisz cyfre: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> selected_number;
				};
			}
			if (selected_number == students.size() + 1) { system("cls"); break; }
			else
			{
				system("cls");
				cout << endl << "Usunieto studenta: " << students[selected_number - 1].get_Name() << " " << students[selected_number - 1].get_Surname() << endl << endl;
				if (selected_number == 1) 
				{ 
					students.erase(students.begin()); 
					for (int i = 0; i < students.size(); i++) { students[i].reset_ID(&students[i], students.size()); }
					for (int i = 0; i < students.size(); i++) { students[i].update_ID(&students[i], i); }
					break;
				}
				else 
				{ 
					students.erase(students.begin() + selected_number - 1); 
					for (int i = 0; i < students.size(); i++) { students[i].reset_ID(&students[i], students.size()); }
					for (int i = 0; i < students.size(); i++) { students[i].update_ID(&students[i], i); }
					break; 
				}
			}
		}
		// 4 - ZAPISUJE LISTE W PLIKU .CSV
		case 4:
		{
			file.open("lista.csv", ios::out | ios::trunc);
			file.close();
			system("cls");
			cout << endl << "LISTA ZAPISANA." << endl;
			for (int j = 0; j < students.size(); j++)
			{
				file.open("lista.csv", ios::out | ios::app);
				file << endl << "---------------------------------------------------------------" << endl;
				file << students[j].get_ID() << ".\t" << students[j].get_Name() << " " << students[j].get_Surname() << endl;
				file << "\t" << students[j].get_subject_name() << endl;
				file << "\tPunkty z zadan z pierwszego kolokwium: " << endl;

				int nr = 6;
				for (int i = 0; i < nr; i++) file << "\t" << "z" << i + 1 << ": " << students[j].get_pkt_1(i) << "\t";
				file << endl << "\t" << "Srednia punktow : " << students[j].get_Srednia_1() << endl;
				file << "\tOcena: " << students[j].get_ocena_1() << endl;
				file << endl;
				file << "\tPunkty z zadan z drugiego kolokwium: " << endl;
				for (int i = 0; i < nr - 1; i++) file << "\t" << "z" << i + 1 << ": " << students[j].get_pkt_2(i) << "\t";
				file << endl << "\t" << "Srednia punktow : " << students[j].get_Srednia_2() << endl;
				file << "\tOcena: " << students[j].get_ocena_2() << endl;
				file << endl << "\tOcena koncowa: " << students[j].get_ocena_koncowa() << endl;

				file.close();
			}
			break;
		}
		// 5 - WCZYTUJE PLIK .CSV
		case 5:
		{
			system("cls");
			file.open("lista.csv", ios::in);
			if (file.good() == false)
			{
				cout << "Plik nie istnieje." << endl;
				break;
			}
			else
			{
				string line;
				while (getline(file, line))
				{
					cout << line << endl;
				}
				file.close();
				break;
			}
		}
		// 6 - WYJŚCIE Z PROGRAMU
		case 6: exit(0);
		default: system("cls"); cout << endl << "Wybierz od 1 do 6." << endl; break;
		}
	}

	return 0;
}
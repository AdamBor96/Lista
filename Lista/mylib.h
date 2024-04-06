#include <iostream>

using namespace std;

/*void menu()
{
    cout << "MENU" << endl << endl;
    cout << "[1] - POKAZ LISTE" << endl;
    cout << "[2] - DODAJ STUDENTA" << endl;
    cout << "[3] - USUN STUDENTA" << endl;
    cout << "[4] - ZAPISZ LISTE" << endl;
    cout << "[5] - WCZYTAJ LISTE" << endl;
    cout << "[6] - EXIT" << endl;
}*/
//void oddziel() { cout << endl << "---------------------------------------------------------------" << endl; }

class Student // klasa abstrakcyjna
{
protected:
    size_t id;
	string name;
	string surname;
    static size_t number;

public:
	Student(const string name, const string surname) : name(name), surname(surname)     // konstruktor i destruktor
	{
		number++;
		id = number;
	}
    ~Student() {}

    string get_Name(); //{ return name; }
    string get_Surname(); //{ return surname; }
    void set_Name(string n); //{ name = n; }
    void set_Surname(string n); //{ surname = n; }

    size_t get_ID(); //{ return id; }
};

class Person : public Student
{
private:
	string subject_name;

	float pkt_kolos_1[6];                           
	float srednia_1;                                
	float ocena_1;                                  

	float pkt_kolos_2[5];                           
	float srednia_2;                                
	float ocena_2;                                 
	float ocena_koncowa;

public:
	Person(string name, string surname) : Student(name, surname) {}

    void add_Subject(string n);
    string get_subject_name();
    void show_Subject();
    void show_Student();

    float get_pkt_1(int nr);
    void set_pkt_1(int nr, float z);
    void add_pkt_1(float z1, float z2, float z3, float z4, float z5, float z6);
    void show_pkt_kolos_1();

    float srednia_pkt_1(float z1, float z2, float z3, float z4, float z5, float z6);
    float get_Srednia_1();
    void show_srednia_1();

    float get_pkt_2(int nr);
    void set_pkt_2(int nr, float z);
    void add_pkt_2(float z1, float z2, float z3, float z4, float z5);
    void show_pkt_kolos_2();
    float srednia_pkt_2(float z1, float z2, float z3, float z4, float z5);
    float get_Srednia_2();
    void show_srednia_2();
                                               
    float get_ocena_1();
    void show_ocena_1();
    float get_ocena_2();
    void show_ocena_2();
    float get_ocena_koncowa();
    void show_ocena_koncowa();

    void set_pkt_grades(Person* s, float pkt1_1, float pkt1_2, float pkt1_3, float pkt1_4, float pkt1_5, float pkt1_6, float pkt2_1, float pkt2_2, float pkt2_3, float pkt2_4, float pkt2_5);
    void show_pkt_and_grades(Person* s);

    void reset_ID(Person* s, size_t p);
    void update_ID(Person* s, int i);

};

size_t Student::number = 0;
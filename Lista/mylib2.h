#include <iostream>

using namespace std;

void menu()
{
    cout << "MENU" << endl << endl;
    cout << "[1] - POKAZ LISTE" << endl;
    cout << "[2] - DODAJ STUDENTA" << endl;
    cout << "[3] - USUN STUDENTA" << endl;
    cout << "[4] - ZAPISZ LISTE" << endl;
    cout << "[5] - WCZYTAJ LISTE" << endl;
    cout << "[6] - EXIT" << endl;
}
void oddziel() { cout << endl << "---------------------------------------------------------------" << endl; }
void check_cin(int n)
{
    while (cin.fail())
    {
        cout << "Wpisz cyfre: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }
}

string Student::get_Name() { return name; }
string Student::get_Surname() { return surname; }
void Student::set_Name(string n) { name = n; }
void Student::set_Surname(string n) { surname = n; }
size_t Student::get_ID() { return id; }


void Person::add_Subject(string n) { subject_name = n; }
string Person::get_subject_name() { return subject_name; }
void Person::show_Subject() { cout << "\t" << get_subject_name() << endl; }

void Person::show_Student() { cout << id << ".\t" << get_Name() << " " << get_Surname() << endl; }

// PONI¯EJ FUNKCJE S£U¯¥CE DO OBLICZANIA ŒREDNIEJ PUNKTÓW PIERWSZEGO I DRUGIEGO KOLOKWIUM Z PODSTAWY PROGRAMOWANIA
float Person::get_pkt_1(int nr) { return pkt_kolos_1[nr]; }
void Person::set_pkt_1(int nr, float z) { pkt_kolos_1[nr] = z; }
void Person::add_pkt_1(float z1, float z2, float z3, float z4, float z5, float z6)
{
    set_pkt_1(0, z1);
    set_pkt_1(1, z2);
    set_pkt_1(2, z3);
    set_pkt_1(3, z4);
    set_pkt_1(4, z5);
    set_pkt_1(5, z6);
}
void Person::show_pkt_kolos_1()
{
    cout << "\tPunkty z zadan z pierwszego kolokwium: " << endl;
    int nr = 6;
    for (int i = 0; i < nr; i++)
    {
        cout << "\t" << "z" << i + 1 << ": " << get_pkt_1(i) << "\t";
    }
}

float Person::srednia_pkt_1(float z1, float z2, float z3, float z4, float z5, float z6)
{
    float sr;
    sr = (z1 + z2 + z3 + z4 + z5 + z6) / 6;
    srednia_1 = sr;
    return srednia_1;
}
float Person::get_Srednia_1() { return srednia_1; }
void Person::show_srednia_1() { cout << endl << "\t" << "Srednia punktow : " << get_Srednia_1() << endl; }

float Person::get_pkt_2(int nr) { return pkt_kolos_2[nr]; }
void Person::set_pkt_2(int nr, float z) { pkt_kolos_2[nr] = z; }
void Person::add_pkt_2(float z1, float z2, float z3, float z4, float z5)
{
    set_pkt_2(0, z1);
    set_pkt_2(1, z2);
    set_pkt_2(2, z3);
    set_pkt_2(3, z4);
    set_pkt_2(4, z5);
}
void Person::show_pkt_kolos_2()
{
    cout << "\tPunkty z zadan z drugiego kolokwium: " << endl;
    int nr = 5;
    for (int i = 0; i < nr; i++)
    {
        cout << "\t" << "z" << i + 1 << ": " << get_pkt_2(i) << "\t";
    }
}
float Person::srednia_pkt_2(float z1, float z2, float z3, float z4, float z5)
{
    float sr;
    sr = (z1 + z2 + z3 + z4 + z5) / 5;
    srednia_2 = sr;
    return srednia_2;
}
float Person::get_Srednia_2() { return srednia_2; }
void Person::show_srednia_2() { cout << endl << "\t" << "Srednia punktow : " << get_Srednia_2() << endl; }

// PONI¯EJ FUNKCJE S£U¯¥CE DO OBLICZANIA OCEN I OCENY KOÑCOWEJ Z PODSTAWY PROGRAMOWANIA                                                
float Person::get_ocena_1()
{
    if ((srednia_1 <= 1) && (srednia_1 > 0.89))    ocena_1 = 5;
    else if ((srednia_1 <= 0.89) && (srednia_1 > 0.77)) ocena_1 = 4.5;
    else if ((srednia_1 <= 0.77) && (srednia_1 > 0.69)) ocena_1 = 4;
    else if ((srednia_1 <= 0.69) && (srednia_1 > 0.65)) ocena_1 = 3.5;
    else if ((srednia_1 <= 0.65) && (srednia_1 > 0.49)) ocena_1 = 3;
    else if (srednia_1 <= 0.49) ocena_1 = 2;
    return ocena_1;
}
void Person::show_ocena_1() { cout << "\tOcena: " << get_ocena_1() << endl; }
float Person::get_ocena_2()
{
    if ((srednia_2 <= 1) && (srednia_2 > 0.89))    ocena_2 = 5;
    else if ((srednia_2 <= 0.89) && (srednia_2 > 0.77)) ocena_2 = 4.5;
    else if ((srednia_2 <= 0.77) && (srednia_2 > 0.69)) ocena_2 = 4;
    else if ((srednia_2 <= 0.69) && (srednia_2 > 0.65)) ocena_2 = 3.5;
    else if ((srednia_2 <= 0.65) && (srednia_2 > 0.49)) ocena_2 = 3;
    else if (srednia_2 <= 0.49) ocena_2 = 2;
    return ocena_2;
}
void Person::show_ocena_2() { cout << "\tOcena: " << get_ocena_2() << endl; }
float Person::get_ocena_koncowa()
{
    ocena_koncowa = (ocena_1 + ocena_2) / 2;
    if (ocena_koncowa >= 4.75)
    {
        ocena_koncowa = 5;
        return ocena_koncowa;
    }
    else return ocena_koncowa;
}
void Person::show_ocena_koncowa() { cout << endl << "\tOcena koncowa: " << get_ocena_koncowa() << endl; }

void Person::set_pkt_grades(Person* s, float pkt1_1, float pkt1_2, float pkt1_3, float pkt1_4, float pkt1_5, float pkt1_6, float pkt2_1, float pkt2_2, float pkt2_3, float pkt2_4, float pkt2_5)
{
    s->add_pkt_1(pkt1_1, pkt1_2, pkt1_3, pkt1_4, pkt1_5, pkt1_6);
    s->srednia_pkt_1(pkt1_1, pkt1_2, pkt1_3, pkt1_4, pkt1_5, pkt1_6);
    s->add_pkt_2(pkt2_1, pkt2_2, pkt2_3, pkt2_4, pkt2_5);
    s->srednia_pkt_2(pkt2_1, pkt2_2, pkt2_3, pkt2_4, pkt2_5);
}
void Person::show_pkt_and_grades(Person* s)
{
    cout << endl;
    s->show_pkt_kolos_1();
    s->show_srednia_1();
    s->show_ocena_1();
    cout << endl;
    s->show_pkt_kolos_2();
    s->show_srednia_2();
    s->show_ocena_2();
    s->show_ocena_koncowa();
}

// PONI¯EJ FUNKCJE DO ZMIANY WARTOŒCI ID PO USUNIÊCIU STUDENTA
void Person::reset_ID(Person* s, size_t p)
{
    number = p;
    s->id = 0;
}
void Person::update_ID(Person* s, int i) { s->id = i + 1; }
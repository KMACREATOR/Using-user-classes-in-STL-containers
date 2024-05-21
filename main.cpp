#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
using namespace std;
//Объект - студент (поля: ФИО, группа, номер зачетной книжки, массив 4-х оценок  за сессию)
//Сортировка по ФИО
//Исходный контейнер - list, копируем в vector

class Student{
    public:
    string name;
    string group;
    string zachetka;
    int session[4];
    Student(){}
    Student(string& name, string& group, string& zachetka, int session[4]){
    this->name = name;
    this->group = group;
    this->zachetka = zachetka;
    for (int i = 0; i < 4; ++i){
            this->session[i] = session[i];
   }
    }
    Student(const Student& S){
    this->name = S.name;
    this->group = S.group;
    this->zachetka = S.zachetka;
    for (int i = 0; i < 4; ++i){
            this->session[i] = S.session[i];
    }
    }
    print(){
        cout << "\nФИО: " << name << "\nГруппа: " << group << "\nЗачетка: " << zachetka << endl;
        for (auto pos: session){
            cout << session[pos];
        }
    }
    friend ostream& operator << (ostream& osm, Student& St){
        osm << "\nФИО: " << St.name << "\nГруппа: " << St.group << "\nЗачетка: " << St.zachetka << endl;
        for (int i = 0; i < 4; ++i){
            osm << St.session[i];
        }
    osm << endl;
    return osm;
    }
    bool operator <(const Student& s1){
    if (name < s1.name){
        return 1;
    }
    else{
        return 0;
    }
    }

};

int main(){
    ifstream infile("input.txt");
    fstream outfile("output.txt");
    setlocale(LC_ALL, "RUS");
    cout << "Hello world!" << endl;
    //создаем list
    list <Student> origin;
    string name, group, zachetka;
    int session[4];
    while(!infile.eof()){
        getline(infile, name);
//        cout << name << "\t";
        infile >> group;
        infile.ignore();
//        cout << group << "\t";
        infile >> zachetka;
        infile.ignore();
//        cout << zachetka << "\t";

        for (int i = 0; i < 4; ++i){
                infile >> session[i];
                cout << session[i];
        }
        cout << "\t";
        infile.ignore();
        origin.push_back(Student(name, group, zachetka, session));
    }
    //сортируем с помощью sort без параметров
    cout << "Исходный список до сортировки:\n";
    outfile << "Исходный список до сортировки:\n";
    for (auto iter = origin.begin(); iter != origin.end(); iter++)
    {
        outfile << *iter << "\t";
        cout << *iter << "\t";
    }
    vector <Student> legacy;
    legacy.resize(origin.size());
    copy(origin.begin(), origin.end(), legacy.begin());
    cout << "Результат копирования в другой контейнер:\n";
    outfile << "Результат копирования в другой контейнер:\n";
    for (auto iter = legacy.begin(); iter != legacy.end(); iter++)
    {
        outfile << *iter << "\t";
        cout << *iter << "\t";
    }
    cout << "Исходный список после сортировки:\n";
    outfile << "Исходный список после сортировки:\n";
    origin.sort();
    for (auto iter = origin.begin(); iter != origin.end(); iter++)
    {
        outfile << *iter << "\t";
        cout << *iter << "\t";
    }

    return 0;
}

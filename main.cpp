#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
using namespace std;
//������ - ������� (����: ���, ������, ����� �������� ������, ������ 4-� ������  �� ������)
//���������� �� ���
//�������� ��������� - list, �������� � vector

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
        cout << "\n���: " << name << "\n������: " << group << "\n�������: " << zachetka << endl;
        for (auto pos: session){
            cout << session[pos];
        }
    }
    friend ostream& operator << (ostream& osm, Student& St){
        osm << "\n���: " << St.name << "\n������: " << St.group << "\n�������: " << St.zachetka << endl;
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
    setlocale(LC_ALL, "RUS");
    cout << "Hello world!" << endl;
    //������� list
    list <Student> origin;
    string name, group, zachetka;
    int session[4];
    while(!infile.eof()){
        getline(infile, name);
        cout << name << "\t";

        infile >> group;
        infile.ignore();
        cout << group << "\t";

        infile >> zachetka;
        infile.ignore();
        cout << zachetka << "\t";

        for (int i = 0; i < 4; ++i){
                infile >> session[i];
                cout << session[i];
        }
        cout << "\t";
        infile.ignore();
        origin.push_back(Student(name, group, zachetka, session));
    }
    //��������� � ������� sort ��� ����������
    cout << "�������� ������ �� ����������:\n";
    for (auto iter = origin.begin(); iter != origin.end(); iter++)
    {
        std::cout << *iter << "\t";
    }
    vector <Student> legacy;
    legacy.resize(origin.size());
    copy(origin.begin(), origin.end(), legacy.begin());
    cout << "��������� ����������� � ������ ���������:\n";
    for (auto iter = legacy.begin(); iter != legacy.end(); iter++)
    {
        std::cout << *iter << "\t";
    }
    cout << "�������� ������ ����� ����������:\n";
    origin.sort();
    for (auto iter = origin.begin(); iter != origin.end(); iter++)
    {
        std::cout << *iter << "\t";
    }

    return 0;
}

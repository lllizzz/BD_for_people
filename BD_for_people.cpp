#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


string path = "BD.txt";
string str;

class Person
{
private:
    string name;
    string surname;
    int id;
    static int count;
public:

    Person()
    {
        cout << "Enter name: " << endl;
        cin >> this->name;
        cout << "Enter surname: " << endl;
        cin >> this->surname;
        this->id = count;
        count++;
    }
    string Print()
    {

        return  "Name: " + this->name + " Surname: " + this->surname + " ID: " + to_string(this->id);
    }
};

int StCount(string& path);
int Person::count = StCount(path);

void fileNew(string& path, Person& NewPerson)
{
    ofstream file;
    file.open(path, ofstream::app);
    if (!file.is_open())
    {
        cout << "error" << endl;
    }
    else
    {
        cout << "file is opened" << endl;
        file << NewPerson.Print() << endl;
    }
    file.close();
}

int num = 0;
int StCount(string& path)
{
    ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        //cout << "error" << endl;
        num = 1;
    }
    else
    {
        cout << "file is opened" << endl;
        while (!file.eof())
        {
            getline(file, str);
            num++;
        }
    }
    file.close();
    return num;
}





int main()
{
    Person NewPerson;
    fileNew(path, NewPerson);

}
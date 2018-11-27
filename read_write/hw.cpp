#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
    string name;
    string school;
    double grade;
};

void menu()
{
    string menuItems[5] = {
        "Add new record",
        "Show best student",
        "Show report",
        "Corrupt school",
        "Exit"};
    cout << "Pick one operation" << endl;
    // Print menu
    for (int i = 0; i < 5; i++)
    {
        cout << menuItems[i] << endl;
    }
}
void writeRecord(string name, string school, double grade)
{
    // todo implement binary writing of the record
    // всеки запис в students.dat трябва да е с фиксирана дължина
    //     име(символен низ до 23 символа) училище(едно от СМГ, НТБГ, НФСГ, ИЕГ) оценка(число между 2.0 и 6.0) sizeof(char) *
    //     23 // max 23 symbols
    //     sizeof(char) *
    //     4              // max 4 symbols for school name
    //     sizeof(double) // single double
}

void addRecord()
{
    string name, school;
    double grade;
    int schoolNum;
    cout << "student name" << endl;
    cin >> name;
    cout << "school 1.СМГ\n2.НТБГ\n3.НФСГ\n4.ИЕГ\nEnter a number corresponding to school\n";
    cin >> schoolNum;
    switch (schoolNum)
    {
    case 1:
        school = "СМГ";
        break;
    case 2:
        school = "НТБГ";
        break;
    case 3:
        school = "НФСГ";
        break;
    case 4:
        school = "ИЕГ";
        break;
    default:
        cout << "Unknown school";
        return;
    }

    cout << "Enter grade between 2.0 and 6.0\n";
    cin >> grade;
    if (grade < 2.0 || grade > 6.0)
    {
        cout << "Invalid grade\n";
        return;
    }

    writeRecord(name, school, grade);
}

void showBestStudent()
{
    // todo
}

void showReport()
{
    // todo
}

void corruptSchool()
{
    // todo
}

// за да разбереш коя операция е избрана, в мейн може нещо от рода на:
int main()
{
    int operation;
    int runLoop = 1;
    while (runLoop) // безкраен цикъл, да се върти докато не бъде избрана опция Exit (5)
    {
        operation = 0;
        menu();
        cin >> operation;

        switch (operation)
        {
        case 1:
            addRecord();
            break;
        case 2:
            showBestStudent();
            break;
        case 3:
            showReport();
            break;
        case 4:
            corruptSchool();
            break;
        case 5: // Exit
            cout << "Thanks for using our system, come back soon" << endl;
            runLoop = 0;
            break;
        default:
            cout << "Please enter single numeric option from 1 to 5" << endl;
        }
    }
}
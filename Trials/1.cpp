#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int max_skip_value = 255;

void clearscr();
void clearscr()
{
    system("cls");
}

class Student;
// Student Class
class Student
{
public:
    string name;
    int roll_no;

    void logIn()
    {
        // cin.getline(name, 50);
        cin >> roll_no;
    }
};

class Admin
{
    string PIN;

public:
    Admin()
    {
        PIN = "12345";
    }

    void menuPrinter();
    void operationChecker();
    void operationPerform();
    void logIn();
    void changePin();
    void showAllDetails();
    void studentAdd();
    void studentDelete();
    void studentDetails();
    void dataAt();
    void allData();
    void changeDate();
};

// Admin function Definitions
void Admin::menuPrinter()
{
    clearscr();
    cout << "Select one of the following operations:\n";
    cout << "\t 1 = Change PIN\n";
    cout << "\t 2 = Show All details upto today\n";
    cout << "\t 3 = Add new Student\n";
    cout << "\t 4 = Delete a Student\n";
    cout << "\t 5 = See details of a Student\n";
    cout << "\t 6 = Check attendance for a particular date\n";
    cout << "\t 7 = Check all attendance uptil today\n";
    cout << "\t 8 = Change date\n";
    cout << "\t 9 = Exit\n";

    operationChecker(); 
}

void Admin::operationChecker()
{
    int ch;
    cout << "Enter your choice (1 to 9) -> ";
    cin >> ch;
    cin.ignore();
    // cout << "cin fail = " << cin.fail();
    // if (cin.fail())
    // {
    //     cout << "Please enter a number between 1 to 7 only!\n";
    //     cout << "Press enter to continue -> ";
    //     cin.clear();
    //     cin.ignore(7, '\n');
    //     cin.get();
    //     operationChecker();
    // }

    switch (ch)
    {
    case 1:
        changePin();
        break;

    case 2:
        allData();
        break;

    case 3:
        studentAdd();
        break;

    case 4:
        studentDelete();
        break;

    case 5:
        studentDetails();
        break;

    case 6:
        dataAt();
        break;

    case 7:
        studentDetails();
        break;

    case 8:
        changeDate();
        break;
        
    case 9:
    break;

    default:
        cout << "Wrong choice number !!";
        cout << "Press enter to continue ";
        cin.clear();
        cin.ignore(max_skip_value, '\n');
        cin.get();
        cin.clear();
    }
}

void Admin::operationPerform()
{
}
void Admin::logIn()
{
    clearscr();
    string tempPIN;
    cout << "Enter your PIN to log in as admin -> ";
    cin >> tempPIN;

    if (tempPIN != PIN)
        cout << "Error! Wrong PIN\n";
    cout << "Try again -> ";
    cin >> tempPIN;
}

void Admin::changePin()
{   
    clearscr();
    
    string temp;
    
    cout << "Enter your old PIN -> ";
    getline(cin,temp);
    
    // if (cin.fail())
    // {
    //     cout << "\n Please enter numbers only !!";
    //     cout << "\n Enter 'e' to continue ->";
    //     cin.ignore(255, 'e');
    //     changePin();
    // }

    if (temp != PIN)
    {
        cout << "Wrong PIN!!\n";
        cout << "Press 0 to try again or enter 'e' to exit -> ";
        getline(cin, temp);
        
        if (temp == "0"){
            changePin();
        }
        else
        {
            cout << "Exiting the program";
            menuPrinter();
        }

    }

    else
    {
        cout << "Old PIN matches successfully!\n";
        cout << "Enter the new PIN ->";
        getline(cin,temp);
        //getline alredy consumes enter after it to proceed not like cin which store enter in buffer 
        //cin.ignore() also need a enter to eat so use in below code
        PIN = temp;
        cout << "New PIN set successfully\n";
        
        //cin.clear();
        cout << "Press Enter to continue -> \n";
        cin.ignore();
        //cin.get();
        menuPrinter();
    }
}

void Admin::showAllDetails()
{
}

void Admin::studentAdd()
{
    cout << "Add a new student\n";
    cout << "________________________________\n\n\n\n\n";
    Student temp;
    cout << "Enter details of the new student :\n";
    cout << "Enter name of the student :\n";
    getline(cin >> ws, temp.name);
    cout << "Enter roll no. of the student, Enter '0' to automatically allocate a new roll no.:\n";
}

void Admin::studentDelete()
{
}
void Admin::studentDetails()
{
}
void Admin::dataAt()
{
}
void Admin::allData()
{
}
void Admin::changeDate()
{
}


// Start function
void startAdmin();
void startAdmin(Admin obj)
{
    obj.menuPrinter();
}

void start()
{
    Admin ad;
    Student sd;
    startAdmin(ad);
}

int main()
{
    start();
}



// cin.ignore(1, '\n')
// cin.ignore();
// cin.ignore(numeric_limits<streasize>::max(), '\n');
// cin.get(); //gets whatever is remaining
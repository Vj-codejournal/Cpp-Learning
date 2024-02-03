#include <iostream>

// Define an enum for weekdays
enum class Weekday {//each is assigned with a number by default for easy access and we can give the a num of char according to our choice also
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    // Use the enum
    Weekday day = Weekday::Monday;

    if (day == Weekday::Monday) {
        std::cout << "It's Monday!" << std::endl;
    } else if (day == Weekday::Friday) {
        std::cout << "It's Friday!" << std::endl;
    }

    // Iterate over the enum values
    for (int i = static_cast<int>(Weekday::Monday); i <= static_cast<int>(Weekday::Sunday); i++) {
        Weekday weekday = static_cast<Weekday>(i);
        switch (weekday) {
            case Weekday::Monday:
                std::cout << "Monday" << std::endl;
                break;
            case Weekday::Tuesday:
                std::cout << "Tuesday" << std::endl;
                break;
            case Weekday::Wednesday:
                std::cout << "Wednesday" << std::endl;
                break;
            case Weekday::Thursday:
                std::cout << "Thursday" << std::endl;
                break;
            case Weekday::Friday:
                std::cout << "Friday" << std::endl;
                break;
            case Weekday::Saturday:
                std::cout << "Saturday" << std::endl;
                break;
            case Weekday::Sunday:
                std::cout << "Sunday" << std::endl;
                break;
        }
    }

    return 0;
}


#include <iostream>

// Define an enum for menu options
enum MenuOption {
    OPTION_1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    OPTION_5,
    EXIT
};

int main() {
    MenuOption choice;

    do {
        // Display the menu
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Option 1" << std::endl;
        std::cout << "2. Option 2" << std::endl;
        std::cout << "3. Option 3" << std::endl;
        std::cout << "4. Option 4" << std::endl;
        std::cout << "5. Option 5" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int input;
        std::cin >> input;
        choice = static_cast<MenuOption>(input);

        // Handle the selected option
        switch (choice) {
            case OPTION_1:
                std::cout << "You chose Option 1" << std::endl;
                break;
            case OPTION_2:
                std::cout << "You chose Option 2" << std::endl;
                break;
            case OPTION_3:
                std::cout << "You chose Option 3" << std::endl;
                break;
            case OPTION_4:
                std::cout << "You chose Option 4" << std::endl;
                break;
            case OPTION_5:
                std::cout << "You chose Option 5" << std::endl;
                break;
            case EXIT:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != EXIT);

    return 0;
}

/*
enum Example{
    A,B,C
}//by defalut a = 0, b = 1, c = 2
but can do A= 0, B= 2 ,C = 5
also if A= 5,B,C B automatic becomes 6 as increment C is 7
*/
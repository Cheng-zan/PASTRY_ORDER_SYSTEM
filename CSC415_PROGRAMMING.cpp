//Can't run in DEVC++ COMPILER
//DevC++ doesnt support fstream library
//Try other c++ compiler

#include <string>
#include <algorithm> //using build in function
#include <cctype>
#include <iostream>
#include <fstream> // reading and writing files 
#include <iomanip> // for setw
using namespace std;


//global variable
string username, password, fullName, address, userInput;
float discount = 0, price = 0, newPrice = 0, pastryOrderPrice = 0, deliveryFee = 0, 
//menu price
pastryPrice[8] = { 7.5 , 8 , 8.5 , 4.5 , 5.5 , 6.5 , 6 , 7 };
char deliveryOption;
int age = 0, 
//the initial amount of food
foodCount[8] = { 0,0,0,0,0,0,0,0 };

//function prototype
bool isLoggedIn(); // login system
void orderFood();
float calculatePrice(float price);
void displayBill();
char change_case(char c); // change all the characters of user full name to uppercase

int main()
{
    int choiceTwo;
    string choice;
   
    do {
        system("cls");
        cout << "------------------------------------" << endl;
        cout << "|  WELCOME TO PASTRY ORDER SYSTEM  |" << endl;
        cout << "------------------------------------" << endl;
        cout << "Main menu:    " << endl;
        cout << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << endl;
        cout << "Your choice: ";
        cin >> choice;


        //register
        if (choice == "1")
        {
            char option;
            string un, pw; // comparison strings

            cout << "------------------------------------------" << endl;
            cout << "REGISTER" << endl;
            cout << "------------------------------------------" << endl;
            cout << "Enter a username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Enter a password: ";
            cin >> password;

            ofstream file(username + ".txt"); // ofstream creates a file
            file << username << endl << password;
            file.close();
            cout << "Welcome!" << endl;
            cout << "Back to the main menu? (y/n): ";
            cin >> option;

            if (option == 'y')
            {
                cout << endl;
                main();
 
            }
            else if (option == 'n')
            {
                cout << endl;
                cout << "***************************" << endl;
                cout << "THANK YOU AND SEE YOU AGAIN" << endl;
                cout << "***************************" << endl;
                break;
            }
        }

        else if (choice == "2") // if user chooses to login

        {
            bool status = isLoggedIn();

            if (!status) // if isLoggedIn() returns false
            {
                cout << endl;
                cout << "Invalid login!" << endl;
                return 0;
            }
            else // if isLoggedIn() returns true, the dashboard is displayed
            {
                system("cls");
                cout << "Successfully logged in!" << endl;
                cout << endl;

                // Display dashboard: 
                transform(username.begin(), username.end(), username.begin(), change_case);
                cout << "Welcome back " << username << "!" << endl;
                cout << "CHOOSE YOUR OPTION" << endl;
                cout << endl;
                cout << "1. Order" << endl;
                cout << "2. Sign Out" << endl;
                cout << "3. Back to the main menu" << endl;
                cout << endl;
                cout << "Your choice: ";
                cin >> choiceTwo;

                if (choiceTwo == 1)
                {
                    orderFood();

                }
                else if (choiceTwo == 2)
                {
                    exit(0); // exits program
                }
                else if (choiceTwo == 3)
                {
                    system("cls");
                    main(); // returns to the beginning of the main() function
                }
            }
        }
        else {
            cout << "Invalid input" << endl;
            break;
        }
        cout << endl;
        cout << "Do you wish to continue? y/n: ";
        cin >> userInput;    

        //reset value for the next customer;
        //-----------------------
        for (int i = 0; i <= 7; i++) {
            foodCount[i] = 0;
        }
        pastryOrderPrice = 0;
        deliveryFee = 0;
        //-----------------------
    } while (userInput != "n");

    cout << endl;
    cout << "Goodbye have a nice day";
    cout << endl;

    return 0;
}

void orderFood()
{
    int userMenu;
    system("cls");

    string pastryMenu[8] = {
        "Quick Cherry Turnovers",
        "Cinnamon Swirl Quick Bread",
        "Chocolate Banana Bundles",
        "Caramel Bubble Ring",
        "Cherry Chip Scones",
        "Chocolate Toffee Biscuits",
        "Raspberry Cheese Danish",
        "Nutella Hand Pies"
    };

    cout << "PASTRY MENU LIST" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\tMENU\t\t\t\tPRICE\t\t\tMENU\t\t\t\tPRICE" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. " << pastryMenu[0] << setw(11) << "\t\t\tRM 7.50\t\t\t5. " 
        << pastryMenu[4] << setw(15) << "RM 5.50" << endl;
    cout << "2. " << pastryMenu[1] << setw(7) << "\t\t\tRM 8.00\t\t\t6. " 
        << pastryMenu[5] << setw(8) << "RM 6.50" << endl;
    cout << "3. " << pastryMenu[2] << setw(9) << "\t\t\tRM 8.50\t\t\t7. " 
        << pastryMenu[6] << setw(10) << "RM 6.00" << endl;
    cout << "4. " << pastryMenu[3] << setw(14) << "\t\t\t\tRM 4.50\t\t\t8. " 
        << pastryMenu[7] << setw(16) << "RM 7.00" << endl;
    cout << endl;
    cout << "Press 0 to Exit" << endl;


    do {
        cout << "Choose your menu: ";
        cin >> userMenu;
        userMenu = userMenu - 1;//to access first index we need to subtract the user menu by 1

        if (userMenu == 0) {
            foodCount[0] += 1;
        }
        else if (userMenu == 1) {
            foodCount[1] += 1;
        }
        else if (userMenu == 2) {
            foodCount[2] += 1;
        }
        else if (userMenu == 3) {
            foodCount[3] += 1;
        } else if (userMenu == 4) {
            foodCount[4] += 1;
        }
        else if (userMenu == 5) {
            foodCount[5] += 1;
        }
        else if (userMenu == 6) {
            foodCount[6] += 1;
        }
        else if (userMenu == 7) {
            foodCount[7] += 1;
        }

        //we used this to prevent duplication price;
        if (userMenu == 0 - 1) {
            pastryOrderPrice;
        }
        else {
            pastryOrderPrice += pastryPrice[userMenu];
        }

    } while (userMenu != 0 - 1);

    cout << endl;
    cout << "Do you want to self pickup or delivery?" << endl;
    cout << "Delivery fee: RM4" << endl;
    cout << "S - Selfpickup\t D - Delivery: ";
    cin >> deliveryOption;
    cout << endl;

    if (deliveryOption == 'S') 
    {
        cout << endl;
        cout << "You choose self pickup!!" << endl;
        cout << "Insert your name: ";
        cin.ignore();
        getline(cin, fullName);
    }
    else if (deliveryOption == 'D') {
        deliveryFee += 4;
        cout << "You choose delivery!!" << endl;
        cout << "Insert your name: ";
        cin.ignore();
        getline(cin, fullName);
        transform(fullName.begin(), fullName.end(), fullName.begin(), change_case);
        cout << "Please enter your address:";
        cin.ignore();
        getline(cin, address);        
        transform(address.begin(), address.end(), address.begin(), change_case);
        cout << endl;
    }
    else {
        cout << "Invalid error";
    }

    newPrice = calculatePrice(pastryOrderPrice) + deliveryFee;
    displayBill();

}

float  calculatePrice(float price) {
    if (age <= 18) {
        discount = 5;
        price = price - (price * discount / 100);
    }
    else if (age >= 50) {
        discount = 10;
        price = price - (price * discount / 100);
    }
    else {
        discount = 2;
        price = price - (price * discount / 100);
    }
    return price;
}

bool isLoggedIn() // login system
{
    string un, pw; // comparison strings

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt"); // ifstream reads a file 
    if (!read)
    {
        cout << "Error..." << endl;
        return false;
    }
    getline(read, un); // reads the username 
    getline(read, pw); // reads the password

    if (un == username && pw == password) // if both un & username and pw & password are the same, true
    {
        return true;
    }
    else // if both un & username and pw & password are not matching, false
    {
        return false;
    }
}

void displayBill() {
    cout << "========================================" << endl;
    cout << setw(10) << fullName << " SPASTRY BILL" << endl;
    cout << "========================================" << endl;
    cout << "YOUR ORDER: " << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Quick Cherry Turnovers: " << foodCount[0] << "x RM" << pastryPrice[0] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Cinnamon Swirl Quick Bread: " << foodCount[1] << "x RM" << pastryPrice[1] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Chocolate Banana Bundles: " << foodCount[2] << "x RM" << pastryPrice[2] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Caramel Bubble Ring: " <<  foodCount[3] << "x RM" << pastryPrice[3] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Cherry Chip Scones: " << foodCount[4] << "x RM" << pastryPrice[4] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Chocolate Toffee Biscuits: " << foodCount[5] << "x RM" << pastryPrice[5] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Raspberry Cheese Danish: " << foodCount[6] << "x RM" << pastryPrice[6] << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Nutella Hand Pies: " << foodCount[7] << "x RM" << pastryPrice[7] << endl;
    cout << "---------------------------------------------" << endl;
    cout << "NAME: " << fullName << endl;
    cout << "AGE: " << age << endl;
    cout << "ADDRESS: " << address << endl;
    cout << "PASTRY ORDER: " << "RM" << pastryOrderPrice << endl;
    cout << "DELIVERY FEE: " << "RM" << deliveryFee << endl;
    cout << "DISCOUNT: " << discount << "%" << endl;
    cout << "TOTAL FEES: " << "RM" << newPrice << endl;
    cout << "==================================================" << endl;
}

char change_case(char c) // change all the characters of user full name to uppercase
{
    if (isupper(c))
        return toupper(c);
    else
        return toupper(c);
}
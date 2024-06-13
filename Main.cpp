#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <memory>
#include"Bank.h"
#include"CheckingAccount.h"
#include"SavingAccount.h"
#include"Account.h"
#include"Customer.h"
#include"Transaction.h"

using namespace std;


void displayAllCustomersSFML(sf::RenderWindow& window, Bank& myBank);
void accessCustomerAccountSFML(sf::RenderWindow& window, Bank& myBank);
void handleAccountOperations(sf::RenderWindow& window, Account* account);
void createNewAccountSFML(sf::RenderWindow& window, Bank& myBank);
void createNewCustomerAccountSFML(sf::RenderWindow& window, Bank& myBank);

int main() {
    Bank myBank;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bank Management System");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Could not load font" << endl;
        return -1;
    }

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("bank_background.jpg")) {
        cerr << "Could not load background image" << endl;
        return -1;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::Text title("Bank Management System", font, 30);
    title.setFillColor(sf::Color::Black);
    title.setPosition(20, 20);

    sf::Text option1("1. Display All Customers", font, 20);
    option1.setFillColor(sf::Color::Black);
    option1.setPosition(20, 100);

    sf::Text option2("2. Access Specific Account", font, 20);
    option2.setFillColor(sf::Color::Black);
    option2.setPosition(20, 150);

    sf::Text option3("3. Create New Account for Existing Customer", font, 20);
    option3.setFillColor(sf::Color::Black);
    option3.setPosition(20, 200);

    sf::Text option4("4. Create New Customer Account", font, 20);
    option4.setFillColor(sf::Color::Black);
    option4.setPosition(20, 250);

    sf::Text option5("5. Exit", font, 20);
    option5.setFillColor(sf::Color::Black);
    option5.setPosition(20, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (option1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    displayAllCustomersSFML(window, myBank);
                }
                else if (option2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    accessCustomerAccountSFML(window, myBank);
                }
                else if (option3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    createNewAccountSFML(window, myBank);
                }
                else if (option4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    createNewCustomerAccountSFML(window, myBank);
                }
                else if (option5.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);
        window.draw(title);
        window.draw(option1);
        window.draw(option2);
        window.draw(option3);
        window.draw(option4);
        window.draw(option5);
        window.display();
    }

    return 0;
}

void displayAllCustomersSFML(sf::RenderWindow& window, Bank& myBank) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Could not load font" << endl;
        return;
    }

    sf::Text title("All Customers", font, 24);
    title.setFillColor(sf::Color::Black);
    title.setPosition(20, 20);
    window.draw(title);

    int yOffset = 60;
    for (const auto& customer : myBank.getCustomers()) {
        sf::Text customerText(customer->getName(), font, 20);
        customerText.setFillColor(sf::Color::Black);
        customerText.setPosition(20, yOffset);
        window.draw(customerText);
        yOffset += 30;

        for (const auto& account : customer->getAccounts()) {
            sf::Text accountText("  " + account->getAccountNumber() + ": " + to_string(account->getBalance()), font, 18);
            accountText.setFillColor(sf::Color::Black);
            accountText.setPosition(40, yOffset);
            window.draw(accountText);
            yOffset += 30;
        }
    }

    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                return;
            }
        }
    }
}

void handleAccountOperations(sf::RenderWindow& window, Account* account) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Could not load font" << endl;
        return;
    }

    while (window.isOpen()) {
        window.clear(sf::Color::White);

        sf::Text title("Account Menu for " + account->getAccountNumber(), font, 24);
        title.setFillColor(sf::Color::Black);
        title.setPosition(20, 20);
        window.draw(title);

        sf::Text option1("1. Display Balance", font, 20);
        option1.setFillColor(sf::Color::Black);
        option1.setPosition(20, 60);
        window.draw(option1);

        sf::Text option2("2. Deposit", font, 20);
        option2.setFillColor(sf::Color::Black);
        option2.setPosition(20, 100);
        window.draw(option2);

        sf::Text option3("3. Withdraw", font, 20);
        option3.setFillColor(sf::Color::Black);
        option3.setPosition(20, 140);
        window.draw(option3);

        sf::Text option4("4. Back to Customer Menu", font, 20);
        option4.setFillColor(sf::Color::Black);
        option4.setPosition(20, 180);
        window.draw(option4);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (option1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                window.clear(sf::Color::White);
                sf::Text balanceText("Balance: " + to_string(account->getBalance()), font, 20);
                balanceText.setFillColor(sf::Color::Black);
                balanceText.setPosition(20, 60);
                window.draw(balanceText);
                window.display();
                sf::Event event;
                while (true) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                            return;
                        }
                    }
                }
            }
            else if (option2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                sf::Text depositText("Deposited: " + to_string(amount), font, 20);
                depositText.setFillColor(sf::Color::Black);
                depositText.setPosition(20, 100);
                window.draw(depositText);
                window.display();
                sf::Event event;
                while (true) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                            break;
                        }
                    }
                    break;
                }
            }
            else if (option3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (account->withdraw(amount)) {
                    sf::Text withdrawText("Withdrawn: " + to_string(amount), font, 20);
                    withdrawText.setFillColor(sf::Color::Black);
                    withdrawText.setPosition(20, 140);
                    window.draw(withdrawText);
                    window.display();
                }
                else {
                    sf::Text errorText("Insufficient balance", font, 20);
                    errorText.setFillColor(sf::Color::Red);
                    errorText.setPosition(20, 140);
                    window.draw(errorText);
                    window.display();
                }
                sf::Event event;
                while (true) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                            break;
                        }
                    }
                    break;
                }
            }
            else if (option4.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                return;
            }
        }

        window.display();
    }
}

void accessCustomerAccountSFML(sf::RenderWindow& window, Bank& myBank) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Could not load font" << endl;
        return;
    }

    string customerName;
    cout << "Enter customer name: ";
    cin >> customerName;
    Customer* customer = myBank.getCustomer(customerName);
    if (customer) {
        window.clear(sf::Color::White);
        sf::Text title("Customer Menu for " + customerName, font, 24);
        title.setFillColor(sf::Color::Black);
        title.setPosition(20, 20);
        window.draw(title);

        int yOffset = 60;
        for (const auto& account : customer->getAccounts()) {
            sf::Text accountText("  " + account->getAccountNumber() + ": " + to_string(account->getBalance()), font, 18);
            accountText.setFillColor(sf::Color::Black);
            accountText.setPosition(40, yOffset);
            window.draw(accountText);
            yOffset += 30;
        }

        window.display();

        sf::Event event;
        while (true) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                    break;
                }
            }
            break;
        }

        string accountNumber;
        cout << "Enter account number: ";
        cin >> accountNumber;
        Account* account = customer->getAccount(accountNumber);
        if (account) {
            handleAccountOperations(window, account);
        }
        else {
            cout << "Account not found." << endl;
        }
    }
    else {
        cout << "Customer not found." << endl;
    }
}

void createNewAccountSFML(sf::RenderWindow& window, Bank& myBank) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Could not load font" << endl;
        return;
    }

    string customerName;
    cout << "Enter customer name: ";
    cin >> customerName;
    Customer* customer = myBank.getCustomer(customerName);
    if (customer) {
        string accountNumber;
        cout << "Enter new account number: ";
        cin >> accountNumber;
        if (myBank.isAccountNumberTaken(accountNumber)) {
            cout << "Account number already taken, choose another." << endl;
            return;
        }

        int accountTypeChoice;
        cout << "Choose account type (1. Savings, 2. Checking): ";
        cin >> accountTypeChoice;

        double initialBalance;
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        if (accountTypeChoice == 1) {
            double interestRate;
            cout << "Enter interest rate: ";
            cin >> interestRate;
            customer->addAccount(new SavingsAccount(accountNumber, initialBalance, interestRate));
        }
        else if (accountTypeChoice == 2) {
            double overdraftLimit;
            cout << "Enter overdraft limit: ";
            cin >> overdraftLimit;
            customer->addAccount(new CheckingAccount(accountNumber, initialBalance, overdraftLimit));
        }

        myBank.addAccountNumber(accountNumber);
        cout << "Account created successfully." << endl;
    }
    else {
        cout << "Customer not found." << endl;
    }
}

void createNewCustomerAccountSFML(sf::RenderWindow& window, Bank& myBank) {
    window.clear(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Could not load font" << endl;
        return;
    }

    string customerName;
    cout << "Enter new customer name: ";
    cin >> customerName;

    string accountNumber;
    cout << "Enter new account number: ";
    cin >> accountNumber;
    if (myBank.isAccountNumberTaken(accountNumber)) {
        cout << "Account number already taken, choose another." << endl;
        return;
    }

    int accountTypeChoice;
    cout << "Choose account type (1. Savings, 2. Checking): ";
    cin >> accountTypeChoice;

    double initialBalance;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Customer* newCustomer = new Customer(customerName);
    if (accountTypeChoice == 1) {
        double interestRate;
        cout << "Enter interest rate: ";
        cin >> interestRate;
        newCustomer->addAccount(new SavingsAccount(accountNumber, initialBalance, interestRate));
    }
    else if (accountTypeChoice == 2) {
        double overdraftLimit;
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        newCustomer->addAccount(new CheckingAccount(accountNumber, initialBalance, overdraftLimit));
    }

    myBank.addCustomer(newCustomer);
    myBank.addAccountNumber(accountNumber);
    cout << "Customer and account created successfully." << endl;
}

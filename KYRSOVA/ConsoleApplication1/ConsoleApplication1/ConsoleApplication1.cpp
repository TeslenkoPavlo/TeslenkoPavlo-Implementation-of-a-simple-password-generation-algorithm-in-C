#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <vector>

using namespace std;

void Clear() {
    std::cin.clear();
    while (std::cin.get() != '\n');
}

void checkPassword(const std::string& GeneratedPassword) {
    std::cout << std::endl;
    std::cout << "-----------Перевірка пароля-----------" << std::endl;
    char C = ' ';
    std::string password;

    do {
        password = "";
        std::cout << "Введіть пароль: ";

        while (C != 13) {
            C = _getch();
            if (C != 13) {
                password += C;
                std::cout << "*";
            }
        }

        if (password != GeneratedPassword) {
            std::cout << std::endl;
            std::cout << std::endl << "Пароль введено неправильно. Спробуйте ще раз." << std::endl;
            std::cout << "Згенерований пароль: " << GeneratedPassword << std::endl;
            C = ' ';
            std::cout << std::endl;
        }

    } while (password != GeneratedPassword);

    std::cout << std::endl;
    std::cout << "Пароль введений вірно!" << std::endl;
}

void savePassword(const std::string& password) {
    char C;

    do {
        std::cout << std::endl;
        std::cout << "Бажаєте зберегти пароль? (y/n): ";
        std::cin >> C;

        if (C == 'y') {
            std::ofstream file("passwords.txt", std::ios::app);
            if (file.is_open()) {
                file << password << std::endl;
                file.close();
                std::cout << "Пароль успішно збережений." << std::endl;
            }
            else {
                std::cout << "Пароль не зберігся." << std::endl;
            }
        }
        else if (C != 'n') {
            std::cout << "Некоректний ввід. Будь ласка, введіть 'y' або 'n'." << std::endl;
            Clear();
        }
    } while (C != 'y' && C != 'n');
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int program = 0;
    while (program != 3) {
        std::string S;
        std::cout << "-----------Програма----------" << std::endl;
        std::cout << "1. Згенерувати новий пароль" << std::endl;
        std::cout << "2. Переглянути каталог паролів" << std::endl;
        std::cout << "3. Вийти" << std::endl;
        std::cout << "Виберіть опцію: ";
        std::cin >> S;

        bool b = true;
        try {
            program = std::stoi(S);
        }
        catch (const std::invalid_argument&) {
            b = false;
            std::cout << "Виберіть наявну програму від 1 до 3" << std::endl;
            continue;
        }

        switch (program) {
        case 1: {
            while (true) {
                int type;

                std::string S;
                std::cout << std::endl;
                std::cout << "-----------Тип паролів----------" << std::endl;
                std::cout << "1. Згенерувати пароль без спеціальних символів" << std::endl;
                std::cout << "2. Згенерувати пароль без літер" << std::endl;
                std::cout << "3. Згенерувати пароль без цифр" << std::endl;
                std::cout << "4. Усі символи" << std::endl;
                std::cout << std::endl;
                std::cout << "Оберіть тип пароля: ";
                std::cin >> S;

                bool b = true;
                try {
                    type = std::stoi(S);
                }
                catch (const std::invalid_argument&) {
                    b = false;
                    std::cout << "Виберіть наявний тип пароля від 1 до 4" << std::endl;
                    continue;
                }

                if (type >= 1 && type <= 4) {
                    srand(static_cast<unsigned>(time(nullptr)));
                    int length;
                    std::string S;
                    bool b = false;
                    while (!b) {
                        std::cout << "Введіть довжину пароля: ";
                        std::cin >> S;

                        try {
                            length = std::stoi(S);
                            if (length <= 0) {
                                std::cout << "Довжина пароля повинна бути більше нуля. Спробуйте ще раз." << std::endl;
                                continue;
                            }
                            b = true;
                        }
                        catch (const std::invalid_argument&) {
                            std::cout << "Довжина пароля повинна бути числом. Спробуйте ще раз." << std::endl;
                        }
                    }

                    std::string password;
                    std::string password2;
                    if (type == 1) {
                        std::string data = "1234567890"
                            "abcdefghijklmnopqrstuvwxyz"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                        for (int i = 1; i <= length; i++) {
                            password2 += data[rand() % 62];
                        }
                    }
                    else if (type == 2) {
                        std::string data = "1234567890"
                            "!#$%&()*+,-./|:;<=>?@[]^_`{}~";
                        for (int i = 1; i <= length; i++) {
                            password2 += data[rand() % 16];
                        }
                    }
                    else if (type == 3) {
                        std::string data = "!#$%&()*+,-./|:;<=>?@[]^_`{}~"
                            "abcdefghijklmnopqrstuvwxyz"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                        for (int i = 1; i <= length; i++) {
                            password2 += data[rand() % 58];
                        }
                    }
                    else if (type == 4) {
                        for (int i = 33; i <= 126; i++) {
                            password += static_cast<char>(i);
                        }
                        for (int i = 0; i < length; i++) {
                            int symbol = rand() % password.size();
                            password2 += password[symbol];
                        }
                    }

                    std::cout << std::endl;
                    std::cout << "Згенерований пароль: " << password2 << std::endl;
                    checkPassword(password2);
                    savePassword(password2);
                }
                else {
                    std::cout << "Виберіть наявний тип пароля від 1 до 4" << std::endl;
                    continue;
                }

                std::string S2;
                do {
                    std::cout << std::endl;
                    std::cout << "Бажаєте продовжити? (y/n): ";
                    std::cin >> S2;

                    if (S2 != "y" && S2 != "n") {
                        std::cout << "Будь ласка, введіть 'y' або 'n'." << std::endl;
                    }
                } while (S2 != "y" && S2 != "n");

                if (S2 == "n") {
                    break;
                }
            }
        }
              break;
        case 2: {
            std::vector<string> password;
            std::string S;

            std::ifstream file("passwords.txt");
            if (file.is_open()) {
                while (std::getline(file, S)) {
                    password.push_back(S);
                }
                file.close();
            }

            if (password.empty()) {
                std::cout << "Каталог паролів пустий" << std::endl;
            }
            else {
                std::cout << std::endl;
                std::cout << "-----------Каталог паролів----------" << std::endl;
                for (size_t i = 0; i < password.size(); i++) {
                    std::cout << i + 1 << ". " << password[i] << std::endl;
                }
            }

            std::string S2;
            do {
                std::cout << std::endl;
                std::cout << "Бажаєте видалити пароль?(y/n): ";
                std::cin >> S2;
                if (S2 != "y" && S2 != "n") {
                    std::cout << "Для того, щоб видалити пароль введіть 'y', а щоб вийти введіть 'n'." << std::endl;
                    Clear();
                    continue;
                }
                Clear();
                S2 = tolower(S2[0]);

                if (S2 == "y") {
                    if (password.empty()) {
                        std::cout << "Неможливо видалити пароль, оскільки каталог пустий." << std::endl;
                    }
                    else {
                        int N;
                        bool b = false;
                        while (!b) {
                            std::cout << std::endl;
                            std::cout << "Щоб видалити пароль введіть порядковий номер: ";
                            std::cin >> N;
                            if (std::cin.fail() || N < 1 || N > password.size()) {
                                std::cout << "Неправильний ввід. Виберіть порядковий номер." << std::endl;
                                std::cin.clear();
                                Clear();
                            }
                            else {
                                b = true;
                            }
                        }
                        password.erase(password.begin() + N - 1);
                        std::cout << "Пароль був успішно видалений." << std::endl;

                        std::ofstream outFile("passwords.txt");
                        for (const string& password : password) {
                            outFile << password << std::endl;
                        }
                        outFile.close();
                    }
                }
            } while (S2 != "n");
        }
              break;
        case 3: {
            std::cout << "До побачення!" << std::endl;
        }
              break;
        default: std::cout << "Виберіть наявний програму від 1 до 3" << std::endl;
            break;
        }
    }
    return 0;
}
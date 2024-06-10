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

void Color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Print(const std::string& text, bool newline = true) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int padding = (columns - text.length()) / 2;
    if (padding > 0) {
        std::cout << std::string(padding, ' ');
    }
    std::cout << text;
    if (newline) {
        std::cout << std::endl;
    }
}

void checkPassword(const std::string& GeneratedPassword) {
    Print("");
    Print("-----------Перевірка пароля-----------");
    char C = ' ';
    std::string password;

    do {
        password = "";
        Print("Введіть пароль: ", false);
        while (C != 13) {
            C = _getch();
            if (C == 8 && !password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
            else if (C != 8 && C != 13) {
                password += C;
                std::cout << "*";
            }
        }

        if (password != GeneratedPassword) {
            Print("");
            Print("Пароль введено неправильно. Спробуйте ще раз.");
            Print("Згенерований пароль: " + GeneratedPassword);
            C = ' ';
            Print("");
        }

    } while (password != GeneratedPassword);

    Print("");
    Print("Пароль введений вірно!");

}

void savePassword(const std::string& password) {
    char C;

    do {
        Print("");
        Print("Бажаєте зберегти пароль? (y/n): ", false);
        std::cin >> C;

        if (tolower(C) == 'y') {
            std::ofstream file("passwords.txt", std::ios::app);
            if (file.is_open()) {
                file << password << std::endl;
                file.close();
                Print("Пароль успішно збережений.");
            }
            else {
                Print("Пароль не зберігся.");
            }
        }
        else if (tolower(C) != 'n') {
            Print("Некоректний ввід. Будь ласка, введіть 'y' або 'n'.");
            Clear();
        }
    } while (tolower(C) != 'y' && tolower(C) != 'n');
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int program = 0;
    while (program != 4) {
        std::string S;
        Color(14);
        Print("-----------Програма----------");
        Print("1. Згенерувати новий пароль");
        Print("2. Переглянути каталог паролів");
        Print("3. Перевірити надійність пароля");
        Print("4. Вийти");
        Print("Виберіть опцію: ", false);
        std::cin >> S;

        bool b = true;
        try {
            program = std::stoi(S);
        }
        catch (const std::invalid_argument&) {
            b = false;
            Print("Виберіть наявну програму від 1 до 4");
            continue;
        }

        switch (program) {
        case 1: {
            while (true) {
                int type;

                std::string S;
                Print("");
                Print("-----------Тип паролів----------");
                Print("1. Згенерувати пароль без спеціальних символів");
                Print("2. Згенерувати пароль без літер");
                Print("3. Згенерувати пароль без цифр");
                Print("4. Усі символи");
                Print("");
                Print("Оберіть тип пароля: ", false);
                std::cin >> S;

                bool b = true;
                try {
                    type = std::stoi(S);
                }
                catch (const std::invalid_argument&) {
                    b = false;
                    Print("Виберіть наявний тип пароля від 1 до 4");
                    continue;
                }

                if (type >= 1 && type <= 4) {
                    srand(static_cast<unsigned>(time(nullptr)));
                    int length;
                    std::string S;
                    bool b = false;
                    while (!b) {
                        Print("Введіть довжину пароля: ", false);
                        std::cin >> S;

                        try {
                            length = std::stoi(S);
                            if (length <= 0) {
                                Print("Довжина пароля повинна бути більше нуля. Спробуйте ще раз.");
                                continue;
                            }
                            b = true;
                        }
                        catch (const std::invalid_argument&) {
                            Print("Довжина пароля повинна бути числом. Спробуйте ще раз.");
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

                    Print("");
                    Print("Згенерований пароль: " + password2);
                    checkPassword(password2);
                    savePassword(password2);
                }
                else {
                    Print("Виберіть наявний тип пароля від 1 до 4");
                    continue;
                }

                std::string S2;
                do {
                    Print("");
                    Print("Бажаєте продовжити?(y - продовжити генерувати паролі/n - вихід в головне меню): ", false);
                    std::cin >> S2;

                    if (tolower(S2[0]) != 'y' && tolower(S2[0]) != 'n') {
                        Print("Будь ласка, введіть 'y' або 'n'.");
                    }
                } while (tolower(S2[0]) != 'y' && tolower(S2[0]) != 'n');

                if (tolower(S2[0]) == 'n') {
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
                Print("Каталог паролів пустий");
            }
            else {
                Print("");
                Print("-----------Каталог паролів----------");
                for (size_t i = 0; i < password.size(); i++) {
                    Print(std::to_string(i + 1) + ". " + password[i]);
                }
            }

            std::string S2;
            do {
                Print("");
                Print("Бажаєте видалити пароль?(y/n): ", false);
                std::cin >> S2;
                if (tolower(S2[0]) != 'y' && tolower(S2[0]) != 'n') {
                    Print("Для того, щоб видалити пароль введіть 'y', а щоб вийти введіть 'n'.");
                    Clear();
                    continue;
                }
                Clear();

                if (tolower(S2[0]) == 'y') {
                    if (password.empty()) {
                        Print("Каталог паролів порожній.");
                    }
                    else {
                        int N;
                        bool b = false;
                        while (!b) {
                            Print("");
                            Print("Щоб видалити пароль введіть порядковий номер: ", false);
                            std::cin >> N;
                            if (std::cin.fail() || N < 1 || N > password.size()) {
                                Print("Неправильний ввід. Виберіть порядковий номер.");
                                std::cin.clear();
                                Clear();
                            }
                            else {
                                b = true;
                            }
                        }
                        password.erase(password.begin() + N - 1);
                        Print("Пароль був успішно видалений.");

                        std::ofstream outFile("passwords.txt");
                        for (const string& password : password) {
                            outFile << password << std::endl;
                        }
                        outFile.close();

                        if (password.empty()) {
                            Print("Каталог паролів пустий");
                        }
                        else {
                            Print("");
                            Print("-----------Каталог паролів----------");
                            for (size_t i = 0; i < password.size(); i++) {
                                Print(std::to_string(i + 1) + ". " + password[i]);
                            }
                        }
                    }
                }
            } while (tolower(S2[0]) != 'n');
        }
              break;
        case 3: {
            do {
                std::string S;
                Print("Бажаєте перевірити пароль з каталогу?(y/n): ", false);
                std::cin >> S;

                std::string password;
                if (tolower(S[0]) == 'y') {
                    std::vector<std::string> catalog;
                    std::ifstream file("passwords.txt");
                    if (file.is_open()) {
                        std::string line;
                        while (std::getline(file, line)) {
                            catalog.push_back(line);
                        }
                        file.close();
                    }

                    if (catalog.empty()) {
                        Print("Каталог паролів порожній");
                        continue;
                    }

                    int index;
                    Print("");
                    Print("-----------Каталог паролів----------");
                    for (size_t i = 0; i < catalog.size(); i++) {
                        Print(std::to_string(i + 1) + ". " + catalog[i]);
                    }

                    do {
                        Print("");
                        Print("Введіть порядковий номер пароля для перевірки: ", false);
                        std::cin >> index;

                        if (std::cin.fail() || (index < 1 || index > catalog.size())) {
                            if (std::cin.fail()) {
                                std::cin.clear();
                                Clear();
                                Print("Введено неправильне значення. Будь ласка, введіть ціле число.");
                            }
                            else {
                                Clear();
                                Print("Оберіть існуючий індекс пароля.");
                            }
                        }
                    } while (std::cin.fail() || (index < 1 || index > catalog.size()));

                    password = catalog[index - 1];
                }
                else if (tolower(S[0]) != 'n') {
                    Print("Будь ласка, введіть 'y' або 'n'.");
                    continue;
                }
                else {
                    Print("");
                    Print("-----------Перевірка на надійність пароля----------");
                    Print("Введіть пароль: ", false);
                    std::cin.ignore();
                    std::getline(std::cin, password);
                }

                bool upper = false, lower = false, digit = false, punct = false;
                int length = password.length();

                for (int i = 0; i < length; i++) {
                    char c = password[i];
                    if (isupper(c)) {
                        upper = true;
                    }
                    else if (islower(c)) {
                        lower = true;
                    }
                    else if (isdigit(c)) {
                        digit = true;
                    }
                    else if (ispunct(c)) {
                        punct = true;
                    }
                }

                if (length < 8) {
                    Print("Пароль є слабким, оскільки містить менше 8 символів");
                }
                else if (!upper || !lower || !digit || !punct) {
                    Print("");
                    Print("Слабкий пароль.");
                    Print("Він повинен містити принаймні:");
                    Print("1.Одну велику літеру.");
                    Print("2.Одну малу літеру.");
                    Print("3.Одну цифру та один спеціальний символ.");
                }
                else {
                    Print("Пароль надійний");
                }

                do {
                    Print("");
                    Print("Бажаєте продовжити?(y - продовжити перевіряти паролі/n - вихід в головне меню): ", false);
                    std::cin >> S;

                    if (tolower(S[0]) != 'y' && tolower(S[0]) != 'n') {
                        Print("Будь ласка, введіть 'y' або 'n'.");
                    }
                } while (tolower(S[0]) != 'y' && tolower(S[0]) != 'n');

                if (tolower(S[0]) == 'n') {
                    break;
                }

            } while (true);
        }
              break;
        case 4: {
            Print("До побачення!");
        }
              break;
        default: Print("Виберіть наявний програму від 1 до 4");
            break;
        }
    }
    return 0;
}

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
    Print("-----------�������� ������-----------");
    char C = ' ';
    std::string password;

    do {
        password = "";
        Print("������ ������: ", false);
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
            Print("������ ������� �����������. ��������� �� ���.");
            Print("������������ ������: " + GeneratedPassword);
            C = ' ';
            Print("");
        }

    } while (password != GeneratedPassword);

    Print("");
    Print("������ �������� ����!");

}

void savePassword(const std::string& password) {
    char C;

    do {
        Print("");
        Print("������ �������� ������? (y/n): ", false);
        std::cin >> C;

        if (tolower(C) == 'y') {
            std::ofstream file("passwords.txt", std::ios::app);
            if (file.is_open()) {
                file << password << std::endl;
                file.close();
                Print("������ ������ ����������.");
            }
            else {
                Print("������ �� �������.");
            }
        }
        else if (tolower(C) != 'n') {
            Print("����������� ���. ���� �����, ������ 'y' ��� 'n'.");
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
        Print("-----------��������----------");
        Print("1. ����������� ����� ������");
        Print("2. ����������� ������� ������");
        Print("3. ��������� �������� ������");
        Print("4. �����");
        Print("������� �����: ", false);
        std::cin >> S;

        bool b = true;
        try {
            program = std::stoi(S);
        }
        catch (const std::invalid_argument&) {
            b = false;
            Print("������� ������ �������� �� 1 �� 4");
            continue;
        }

        switch (program) {
        case 1: {
            while (true) {
                int type;

                std::string S;
                Print("");
                Print("-----------��� ������----------");
                Print("1. ����������� ������ ��� ����������� �������");
                Print("2. ����������� ������ ��� ����");
                Print("3. ����������� ������ ��� ����");
                Print("4. �� �������");
                Print("");
                Print("������ ��� ������: ", false);
                std::cin >> S;

                bool b = true;
                try {
                    type = std::stoi(S);
                }
                catch (const std::invalid_argument&) {
                    b = false;
                    Print("������� ������� ��� ������ �� 1 �� 4");
                    continue;
                }

                if (type >= 1 && type <= 4) {
                    srand(static_cast<unsigned>(time(nullptr)));
                    int length;
                    std::string S;
                    bool b = false;
                    while (!b) {
                        Print("������ ������� ������: ", false);
                        std::cin >> S;

                        try {
                            length = std::stoi(S);
                            if (length <= 0) {
                                Print("������� ������ ������� ���� ����� ����. ��������� �� ���.");
                                continue;
                            }
                            b = true;
                        }
                        catch (const std::invalid_argument&) {
                            Print("������� ������ ������� ���� ������. ��������� �� ���.");
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
                    Print("������������ ������: " + password2);
                    checkPassword(password2);
                    savePassword(password2);
                }
                else {
                    Print("������� ������� ��� ������ �� 1 �� 4");
                    continue;
                }

                std::string S2;
                do {
                    Print("");
                    Print("������ ����������?(y - ���������� ���������� �����/n - ����� � ������� ����): ", false);
                    std::cin >> S2;

                    if (tolower(S2[0]) != 'y' && tolower(S2[0]) != 'n') {
                        Print("���� �����, ������ 'y' ��� 'n'.");
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
                Print("������� ������ ������");
            }
            else {
                Print("");
                Print("-----------������� ������----------");
                for (size_t i = 0; i < password.size(); i++) {
                    Print(std::to_string(i + 1) + ". " + password[i]);
                }
            }

            std::string S2;
            do {
                Print("");
                Print("������ �������� ������?(y/n): ", false);
                std::cin >> S2;
                if (tolower(S2[0]) != 'y' && tolower(S2[0]) != 'n') {
                    Print("��� ����, ��� �������� ������ ������ 'y', � ��� ����� ������ 'n'.");
                    Clear();
                    continue;
                }
                Clear();

                if (tolower(S2[0]) == 'y') {
                    if (password.empty()) {
                        Print("������� ������ �������.");
                    }
                    else {
                        int N;
                        bool b = false;
                        while (!b) {
                            Print("");
                            Print("��� �������� ������ ������ ���������� �����: ", false);
                            std::cin >> N;
                            if (std::cin.fail() || N < 1 || N > password.size()) {
                                Print("������������ ���. ������� ���������� �����.");
                                std::cin.clear();
                                Clear();
                            }
                            else {
                                b = true;
                            }
                        }
                        password.erase(password.begin() + N - 1);
                        Print("������ ��� ������ ���������.");

                        std::ofstream outFile("passwords.txt");
                        for (const string& password : password) {
                            outFile << password << std::endl;
                        }
                        outFile.close();
                    }
                }
            } while (tolower(S2[0]) != 'n');
        }
              break;
        case 3: {
            do {
                std::string S;
                Print("������ ��������� ������ � ��������?(y/n): ", false);
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
                        Print("������� ������ �������");
                        continue;
                    }

                    int index;
                    Print("");
                    Print("-----------������� ������----------");
                    for (size_t i = 0; i < catalog.size(); i++) {
                        Print(std::to_string(i + 1) + ". " + catalog[i]);
                    }

                    do {
                        Print("");
                        Print("������ ���������� ����� ������ ��� ��������: ", false);
                        std::cin >> index;

                        if (std::cin.fail() || (index < 1 || index > catalog.size())) {
                            if (std::cin.fail()) {
                                std::cin.clear();
                                Clear();
                                Print("������� ����������� ��������. ���� �����, ������ ���� �����.");
                            }
                            else {
                                Clear();
                                Print("������ �������� ������ ������.");
                            }
                        }
                    } while (std::cin.fail() || (index < 1 || index > catalog.size()));

                    password = catalog[index - 1];
                }
                else if (tolower(S[0]) != 'n') {
                    Print("���� �����, ������ 'y' ��� 'n'.");
                    continue;
                }
                else {
                    Print("");
                    Print("-----------�������� �� �������� ������----------");
                    Print("������ ������: ", false);
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
                    Print("������ � �������, ������� ������ ����� 8 �������");
                }
                else if (!upper || !lower || !digit || !punct) {
                    Print("");
                    Print("������� ������.");
                    Print("³� ������� ������ ��������:");
                    Print("1.���� ������ �����.");
                    Print("2.���� ���� �����.");
                    Print("3.���� ����� �� ���� ����������� ������.");
                }
                else {
                    Print("������ �������");
                }

                do {
                    Print("");
                    Print("������ ����������?(y - ���������� ��������� �����/n - ����� � ������� ����): ", false);
                    std::cin >> S;

                    if (tolower(S[0]) != 'y' && tolower(S[0]) != 'n') {
                        Print("���� �����, ������ 'y' ��� 'n'.");
                    }
                } while (tolower(S[0]) != 'y' && tolower(S[0]) != 'n');

                if (tolower(S[0]) == 'n') {
                    break;
                }

            } while (true);
        }
              break;
        case 4: {
            Print("�� ���������!");
        }
              break;
        default: Print("������� ������� �������� �� 1 �� 4");
            break;
        }
    }
    return 0;
}

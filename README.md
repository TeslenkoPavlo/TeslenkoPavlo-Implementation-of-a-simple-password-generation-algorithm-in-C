# Функції
## Функція Clear
![1](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/1.png)
1. std::cin.clear(); - очищує стан помилки стандартного потоку вводу (std::cin).
2. while (std::cin.get() != '\n'); - цикл while, який продовжує читати символи з стандартного потоку вводу, поки не зустріне символ нового рядка ('\n'). Щоб очистити буфер вводу від залишкових символів, які можуть завадити наступному вводу.
## Функція checkPassword
![2](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/2.png)
1. std::cout << "-----------Перевірка пароля-----------" << std::endl; - створення заголовку для розділу перевірки пароля.
2. char C = ' '; - змінна C типу char, яка використовується для зберігання коду натиснутої клавіші.
3. std::string password; - змінна password типу string, яка використовується для зберігання введеного користувачем пароля.
4. Цикл do-while продовжує запитувати введення пароля, доки введений пароль не буде співпадати зі згенерованим паролем (password != GeneratedPassword).
5. password = ""; - очищує введений пароль перед кожною новою спробою.
6. std::cout << "Введіть пароль: "; - виводить запит на введення пароля.
7. Внутрішній цикл while (C != 13) - читає кожен символ, введений користувачем, поки не буде натиснута клавіша Enter (код ASCII для Enter - 13).
8. C = _getch(); - отримує код натиснутої клавіші без виводу символу на екран.
9. if (C != 13) - перевіряє, чи не натиснута клавіша Enter.
10. password += C; - додає введений символ до рядка password.
11. std::cout << "*"; - виводить символ * замість введеного символу пароля.
12. if (password != GeneratedPassword) - перевіряє, чи співпадають введений пароль та згенерований пароль.
13. Якщо паролі не співпадають, виводиться повідомлення про помилку та згенерований пароль.
14. C = ' '; - скидає змінну C, щоб підготуватися до наступної ітерації циклу.
15. Після успішного введення пароля виводиться повідомлення "Пароль введений вірно!"
## Функція savePassword
![3](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/3.png)
1.	savePassword(const std::string& password) - назва функції та її параметр. Параметр password є константним посиланням на рядок, щоб уникнути непотрібного копіювання та запобігти зміні пароля всередині функції.
2.	char C; - оголошення змінної C типу char, яка буде використовуватися для зберігання відповіді користувача (y - так, n - ні).
3.	do {...} while (C != 'y' && C != 'n'); - цикл do-while, який буде виконуватися доти, доки користувач не введе коректну відповідь (y або n).
4.	std::cout << std::endl; - виведення пустого рядка для кращого форматування.
5.	std::cout << "Бажаєте зберегти пароль? (y/n): "; - виведення запитання для користувача.
6.	std::cin >> C; - зчитування відповіді користувача з клавіатури.
7.	if (C == 'y') {...} - перевірка, чи ввів користувач 'y'.
8.	std::ofstream file("passwords.txt", std::ios::app); - створення об'єкта file типу std::ofstream (використовується для запису у файл) та відкриття файлу passwords.txt у режимі дозапису (std::ios::app).
9.	if (file.is_open()) {...} - перевірка, чи файл успішно відкрився.
10.	file << password << std::endl; - запис пароля у файл.
11.	file.close(); - закриття файлу.
12.	std::cout << "Пароль успішно збережений." << std::endl; - виведення повідомлення про успішне збереження пароля.
13.	else {...} - блок коду, який виконується, якщо файл не відкрився.
14.	std::cout << "Пароль не зберігся." << std::endl; - виведення повідомлення про невдале збереження пароля.
15.	else if (C != 'n') {...} - блок коду, який виконується, якщо користувач ввів некоректну відповідь (не y та не n).
16.	std::cout << "Некоректний ввід. Будь ласка, введіть 'y' або 'n'." << std::endl; - виведення повідомлення про некоректний ввід.
17.	Clear(); - виклик функції Clear, яка очищає консоль.
№ Опції програми

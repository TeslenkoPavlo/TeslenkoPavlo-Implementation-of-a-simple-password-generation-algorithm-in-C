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
# Головна функція
![4](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/4.png)
![5](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/5.png)
1. SetConsoleCP(1251); та SetConsoleOutputCP(1251); - ці рядки встановлюють кодування консолі Windows CP1251 (кирилиця).
2.	int program = 0; - змінна, яка зберігає номер обраної програми.
3.	while (program != 3) {...} - головний цикл програми, який працює, поки користувач не вибере опцію "Вийти" (номер 3).
# Опції програми
![6](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/6.png)
1. std::string S; - створюється змінна S типу std::string.
2. std::cout << "-----------Програма----------" << std::endl; - виводить на екран текст "-----------Програма----------".
3. std::cout << "1. Згенерувати новий пароль" << std::endl; - виводить на екран текст "1. Згенерувати новий пароль".
4. std::cout << "2. Переглянути каталог паролів" << std::endl; - виводить на екран текст "2. Переглянути каталог паролів".
5. std::cout << "3. Вийти" << std::endl; - виводить на екран текст "3. Вийти".
6. std::cout << "Виберіть опцію: "; - виводить на екран текст "Виберіть опцію: ".
7. std::cin >> S; - зчитує введення користувача з клавіатури опції та зберігає його в змінній S.
8. bool b = true; - створюється змінна b типу bool (логічний тип, який може приймати значення true або false) та ініціалізується значенням true.
9. try { program = std::stoi(S); } - спроба перетворити змінну S в ціле число за допомогою функції std::stoi. Якщо перетворення відбулося успішно, результат зберігається в змінній program.
10. catch (const std::invalid_argument&) { b = false; std::cout << "Виберіть наявну програму від 1 до 3" << std::endl; continue; } - якщо під час виконання блоку try виникне помилка std::invalid_argument (тобто, якщо в змінній S зберігається не число), виконується блок catch. В цьому блоці змінній b присвоюється значення false, виводиться повідомлення про помилку та виконується команда continue, яка переходить до наступної ітерації циклу.
# Згенерування нового пароля
## Вибір типа пароля
![7](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/7.png)
1. while (true) { - починається нескінченний цикл, який буде виконуватися доти, доки не буде виконано break.
2. int type; - змінна type оголошується як ціле число. Вона буде зберігати тип пароля, обраний користувачем.
3. std::string S; - змінна S оголошується як рядок. Вона буде використовуватися для тимчасового зберігання введення користувача.
4. std::cout << std::endl; - виводить порожній рядок, щоб відокремити попередній вивід від наступного.
5. std::cout << "-----------Тип паролів----------" << std::endl; - виводить заголовок.
6. std::cout << "1. Згенерувати пароль без спеціальних символів" << std::endl; - виводить перший варіант типу пароля.
7. std::cout << "2. Згенерувати пароль без літер" << std::endl; - виводить другий варіант типу пароля.
8. std::cout << "3. Згенерувати пароль без цифр" << std::endl; - виводить третій варіант типу пароля.
9. std::cout << "4. Усі символи" << std::endl; - виводить четвертий варіант типу пароля.
10. std::cout << std::endl; - виводить порожній рядок, щоб відокремити попередній вивід від наступного.
11. std::cout << "Оберіть тип пароля: "; - виводить запит до користувача, щоб обрати тип пароля.
12. std::cin >> S; - зчитує введення користувача з клавіатури та зберігає його в змінній S.
13. bool b = true; - змінна b оголошується як булева та ініціалізується як true. Вона буде використовуватися для перевірки, чи введення користувача є дійсним.
14. try { - починається блок try, який містить код, який може генерувати винятки.
15. type = std::stoi(S); - намагається перетворити змінну S на ціле число та зберігає результат у змінній type.
16. } catch (const std::invalid_argument&) { - починається блок catch, який виконується, якщо код у блоці try генерує виняток std::invalid_argument.
17. b = false; - встановлює змінну b на false, щоб позначити, що введення користувача є недійсним.
18. std::cout << "Виберіть наявний тип пароля від 1 до 4" << std::endl; - виводить повідомлення про помилку.
19. continue; - переходить до наступної ітерації циклу while, щоб дати користувачеві ще одну спробу.
## Генерація пароля
![8](https://github.com/TeslenkoPavlo/TeslenkoPavlo-Implementation-of-a-simple-password-generation-algorithm-in-C/blob/main/PNG/8.png)
1. if (type >= 1 && type <= 4) { - перевірка, чи введений користувачем тип пароля знаходиться в діапазоні від 1 до 4.
2. srand(static_cast<unsigned>(time(nullptr))); - ініціалізація генератора випадкових чисел поточним часом. Це робиться для того, щоб кожен раз при виконанні програми генерувалися різні паролі.
3. int length; - змінна для зберігання довжини пароля.
4. std::string S; - змінна для зберігання введеного користувачем рядка.
5. bool b = false; - змінна, яка використовується для перевірки, чи ввів користувач довжину пароля правильно.
6. while (!b) { - цикл, який виконується, поки користувач не введе довжину пароля правильно.
7. std::cout << "Введіть довжину пароля: "; - виведення на екран запиту до користувача ввести довжину пароля.
8. std::cin >> S; - зчитування з клавіатури введеного користувачем рядка.
9. try { - початок блоку обробки винятків.
10. length = std::stoi(S); - перетворення введеного користувачем рядка в число.
11. if (length <= 0) { - перевірка, чи введена довжина пароля більша нуля.
12. std::cout << "Довжина пароля повинна бути більше нуля. Спробуйте ще раз." << std::endl; - виведення на екран повідомлення про помилку, якщо довжина пароля менша або дорівнює нулю.
13. continue; - перехід до наступної ітерації циклу.
14. b = true; - зміна значення змінної b на true, якщо довжина пароля введена правильно.
15. } catch (const std::invalid_argument&) { - обробка винятку, який виникає, якщо введений користувачем рядок не може бути перетворений в число.
16. std::cout << "Довжина пароля повинна бути числом. Спробуйте ще раз." << std::endl; - виведення на екран повідомлення про помилку, якщо введений користувачем рядок не є числом.
17. std::string password; і std::string password2; - змінні для зберігання згенерованого пароля.
18. if (type == 1) { - перевірка, чи введений користувачем тип пароля дорівнює 1.
19. std::string data = "1234567890" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; - створення рядка, який містить всі можливі символи для пароля типу 1.
20. for (int i = 1; i <= length; i++) { - цикл, який виконується length разів.
21. password2 += data[rand() % 62]; - додавання до змінної password2 випадкового символу з рядка data.
22. else if (type == 2) { - перевірка, чи введений користувачем тип пароля дорівнює 2.
23. std::string data = "1234567890" "!#$%&()*+,-./|:;<=>?@[]^_{}~";` - створення рядка, який містить всі можливі символи для пароля типу 2.
24. for (int i = 1; i <= length; i++) { - цикл, який виконується length разів.
25. password2 += data[rand() % 16]; - додавання до змінної password2 випадкового символу з рядка data.
26. else if (type == 3) { - перевірка, чи введений користувачем тип пароля дорівнює 3.
27. std::string data = "!#$%&()*+,-./|:;<=>?@[]^_{}~" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";` - створення рядка, який містить всі можливі символи для пароля типу 3.
28. for (int i = 1; i <= length; i++) { - цикл, який виконується length разів.
29 password2 += data[rand() % 58]; - додавання до змінної password2 випадкового символу з рядка data.
30. else if (type == 4) { - перевірка, чи введений користувачем тип пароля дорівнює 4.
31. for (int i = 33; i <= 126; i++) { - цикл, який виконується 94 рази (від 33 до 126 включно).
32. password += static_cast<char>(i); - додавання до змінної password символу, який відповідає ASCII-коду числа i.
33. for (int i = 0; i < length; i++) { - цикл, який виконується length разів.
34. int symbol = rand() % password.size(); - вибір випадкового індексу символу з рядка password.
35. password2 += password[symbol]; - додавання до змінної password2 символу з рядка password за випадковим індексом.
36. std::cout << std::endl; - виведення на екран порожнього рядка.
37. std::cout << "Згенерований пароль: " << password2 << std::endl; - виведення на екран згенерованого пароля.
38. checkPassword(password2); - виклик функції checkPassword для перевірки згенерованого пароля.
39. savePassword(password2); - виклик функції savePassword для збереження згенерованого пароля.
40. } else { - виконується, якщо введений користувачем тип пароля не знаходиться в діапазоні від 1 до 4.
41. std::cout << "Виберіть наявний тип пароля від 1 до 4" << std::endl; - виведення на екран повідомлення про помилку.
42. continue; - перехід до наступної ітерації циклу.


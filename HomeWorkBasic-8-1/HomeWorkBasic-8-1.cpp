#include <iostream>
#include <Windows.h>

class ForbiddenLength : std::exception {
public:
    const char* what() const override {
        return "Вы ввели слово запретной длины! До свидания.";
    }
};

int Function(std::string str, int forbiddenLength) {
    if (str.length() == forbiddenLength) {
        throw ForbiddenLength();
    }
    return str.length();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str{};
    int forbiddenLength{};
    std::cout << "Введите запретную длину: ";
    std::cin >> forbiddenLength;
    do {
        std::cout << "Введите слово: ";
        std::cin >> str;
        try {
            std::cout << "Длина слова: \"" << str << "\" равна " << Function(str, forbiddenLength) << "\n";
        }
        catch (const ForbiddenLength& FL) {
            std::cout << FL.what();
        }
    } while (str.length() != forbiddenLength);
}
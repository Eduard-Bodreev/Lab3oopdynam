#ifndef LAB3_CPP
#define LAB3_CPP

#include "Lab3.h"

namespace Input {
    template <class T >
    T read() {
        T val = T();

        while (!(std::cin >> val)) {
            if (std::cin.eof()) throw std::runtime_error("Unexpected EOF!");
            std::cout << "Input again: " << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize > ::max(), '\n');
        }
        return val;
    }


    template <typename T>
    T getNumber(T min, T max) {
        T a;
        do {
            std::cout << "(Enter number between " << min << " and " << max << "): ";
            a = read<T>();
        } while (a < min || a > max);
        return a;
    }

    int getInt(int min, int max) {
        return getNumber(min, max);
    }

    int getPositiveInt(int max) {
        return getInt(1, max);
    }

    std::string getString() {
        return read<std::string>();
    }

    char getChar() {
        return read<char>();
    }

    int dialog(const char* msgs[], int n) {
        char* error = (char*)"";
        int choice;
        do {
            std::cout << error;
            error = (char*)"You're wrong. Try again!\n";
            for (int i = 0; i < n; ++i) {
                std::cout << msgs[i] << std::endl;
            }
            std::cout << "Make your choice:" << std::endl;
            choice = getInt(0, n - 1);
        } while (choice < 0 || choice >= n);
        return choice;
    }
}

namespace Program {
    Set InputPowerSet() {
        std::cout << "Input power ";
        return Set(Input::getPositiveInt(2147483647));
    }

    Set InputStringSet() {
        std::cout << "Input string ";
        return Set(Input::getString());
    }


    Set CreateSet() {
        const char* MSGS[] = { "0 - Initialize with power",
                            "1 - Initialize with string" };

        const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);
        int choice = 0;
        choice = Input::dialog(MSGS, MSGS_SIZE);

        if (choice == 0) {
            return InputPowerSet();
        }
        return InputStringSet();
    }

    void PrintSet(Set& set) {
        set.print();
    }

    void Union(Set& set) {
        std::cout << "Second set ";
        Set other = InputStringSet();
        Set result = set.Union(other);
        std::cout << "Result : ";
        result.print();
    }

    void Add(Set& set) {
        std::cout << "Input value ";
        char val = Input::getChar();
        if (set.insert(val) == true)
            std::cout << "Inserted" << std::endl;
        else
            std::cout << "Not inserted" << std::endl;
    }

    void Intersection(Set& set) {
        std::cout << "Second set ";
        Set other = InputStringSet();
        Set result = set.interection(other);
        std::cout << "Result : ";
        std::cout << result;
    }

    void Exception(Set& set) {
        std::cout << "Second set ";
        Set other = InputStringSet();
        Set result = set.exception(other);
        std::cout << "Result : ";
        result.print();
    }
    void IsExist(Set& set) {
        std::cout << "Input value ";
        char val = Input::getChar();
        if (set.is_exists(val))
            std::cout << "Exists" << std::endl;
        else
            std::cout << "Not exists" << std::endl;
    }
}

#endif

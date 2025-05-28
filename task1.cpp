#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

bool is_letter_or_digit(wchar_t ch, const std::locale& loc) {
    return std::isalpha(ch, loc) || std::isdigit(ch, loc);
}

void task1() {
    std::locale loc("");
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    std::string input;
    std::cout << "Введите текст: ";
    std::getline(std::cin, input);

    std::wstring text = converter.from_bytes(input);

    if (text.empty()) {
        std::wcout << L"Пустой ввод.\n";
        return;
    }

    size_t first_letter_index = std::wstring::npos;
    for (size_t i = 0; i < text.size(); ++i) {
        if (is_letter_or_digit(text[i], loc)) {
            first_letter_index = i;
            break;
        }
    }

    size_t last_dot_index = std::wstring::npos;
    for (size_t i = text.size() - 2; i > 0; --i) {
        if (text[i] == L'.') {
            last_dot_index = i;
            break;
        }
    }

    size_t last_letter_index = std::wstring::npos;
    if (last_dot_index != std::wstring::npos) {
        for (size_t i = last_dot_index + 1; i < text.size(); ++i) {
            if (is_letter_or_digit(text[i], loc)) {
                last_letter_index = i;
                break;
            }
        }
    }

    if (first_letter_index != std::wstring::npos &&
        last_letter_index != std::wstring::npos &&
        first_letter_index != last_letter_index) {
        std::swap(text[first_letter_index], text[last_letter_index]);
    }

    std::string result = converter.to_bytes(text);
    std::cout << "Результат: " << result << "\n";
}

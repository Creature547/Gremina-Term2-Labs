#include "Planet.h"
#include <limits>
#include <sstream>

int Planet::counter = 0;

void Planet::allocateName(const char* source) {
    delete[] name;
    if (source && strlen(source) > 0) {
        name = new char[strlen(source) + 1];
        strcpy(name, source);
    } else {
        name = nullptr;
    }
}

Planet::Planet() : id(++counter), name(nullptr), diameter(0), hasLife(false), moons(0) {}

Planet::Planet(const char* n, int d, bool h, int m)
    : id(++counter), diameter(d), hasLife(h), moons(m) {
    allocateName(n);
}

Planet::~Planet() {
    delete[] name;
}

Planet::Planet(const Planet& other)
    : id(++counter), diameter(other.diameter), hasLife(other.hasLife), moons(other.moons) {
    allocateName(other.name);
}

Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {
        diameter = other.diameter;
        hasLife = other.hasLife;
        moons = other.moons;
        allocateName(other.name);
    }
    return *this;
}

Planet::Planet(Planet&& other) noexcept
    : id(++counter),
      name(std::exchange(other.name, nullptr)),
      diameter(std::exchange(other.diameter, 0)),
      hasLife(std::exchange(other.hasLife, false)),
      moons(std::exchange(other.moons, 0)) {}

Planet& Planet::operator=(Planet&& other) noexcept {
    if (this != &other) {
        delete[] name;
        name = std::exchange(other.name, nullptr);
        diameter = std::exchange(other.diameter, 0);
        hasLife = std::exchange(other.hasLife, false);
        moons = std::exchange(other.moons, 0);
    }
    return *this;
}

const char* Planet::getName() const { return name; }
int Planet::getDiameter() const { return diameter; }
bool Planet::getHasLife() const { return hasLife; }
int Planet::getMoons() const { return moons; }

void Planet::setName(const char* n) { allocateName(n); }
void Planet::setDiameter(int d) { diameter = d; }
void Planet::setHasLife(bool h) { hasLife = h; }
void Planet::setMoons(int m) { moons = m; }

void Planet::editDemo() {
    char buffer[256];
    std::cout << "\n=== Редактирование планеты ===" << '\n';

    std::cout << "Текущее название: " << (name ? name : "N/A") << '\n';
    std::cout << "Введите новое название (оставьте пустым, чтобы не менять): ";
    std::cin.getline(buffer, sizeof(buffer));
    if (strlen(buffer) > 0) {
        setName(buffer);
    }

    std::cout << "Текущий диаметр: " << diameter << " км" << '\n';
    std::cout << "Введите новый диаметр: ";
    if (std::cin >> diameter) {
        std::cin.ignore();
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Диаметр не изменен." << '\n';
    }

    std::cout << "Текущий статус жизни: " << (hasLife ? "Да" : "Нет") << '\n';
    std::cout << "Введите наличие жизни (1 - Да, 0 - Нет): ";
    if (std::cin >> hasLife) {
        std::cin.ignore();
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Статус жизни не изменен." << '\n';
    }

    std::cout << "Текущее количество спутников: " << moons << '\n';
    std::cout << "Введите новое количество спутников: ";
    if (std::cin >> moons) {
        std::cin.ignore();
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Количество спутников не изменено." << '\n';
    }

    std::cout << "Данные обновлены!\n";
}

void Planet::addDemo() {
    char buffer[256];
    std::cout << "\n=== Добавление планеты ===" << '\n';

    std::cout << "Введите новое название: ";
    std::cin.getline(buffer, sizeof(buffer));
    if (strlen(buffer) > 0) {
        setName(buffer);
    }

    std::cout << "Введите новый диаметр: ";
    if (std::cin >> diameter) {
        std::cin.ignore();
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Диаметр не изменен." << '\n';
    }

    std::cout << "Введите наличие жизни (1 - Да, 0 - Нет): ";
    if (std::cin >> hasLife) {
        std::cin.ignore();
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Статус жизни не изменен." << '\n';
    }

    std::cout << "Введите новое количество спутников: ";
    if (std::cin >> moons) {
        std::cin.ignore();
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Количество спутников не изменено." << '\n';
    }

    std::cout << "Данные добавлены!\n";
}

void Planet::printInfo() const {
    std::cout << "Название: " << (name ? name : "N/A")
              << "\nДиаметр: " << diameter << " км"
              << "\nЖизнь: " << (hasLife ? "Да" : "Нет")
              << "\nСпутники: " << moons << "\n\n";
}

std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << planet.getName() << ";"
       << planet.getDiameter() << ";"
       << planet.getHasLife() << ";"
       << planet.getMoons();
    return os;
}

std::istream& operator>>(std::istream& is, Planet& planet) {
    char buffer[256];
    int d, m;
    bool h;

    is.getline(buffer, sizeof(buffer), ';');
    planet.setName(buffer);

    is >> d >> h >> m;
    is.ignore();

    planet.setDiameter(d);
    planet.setHasLife(h);
    planet.setMoons(m);

    return is;
}

bool Planet::operator<(const Planet& other) const {
    return diameter < other.diameter;
}

bool Planet::operator==(const Planet& other) const {
    return strcmp(name, other.name) == 0;
}

void Planet::readFromFile(Planet*& planets, size_t& count, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: файл " << filename << " не найден!\n";
        return;
    }
    else {
        delete[] planets;
        planets = nullptr;
        count = 0;

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            char nameBuf[256];
            int d, m;
            bool h;

            if (iss.getline(nameBuf, sizeof(nameBuf), ',') &&
                iss >> d >> h >> m)
            {
                iss >> std::ws;

                Planet* newArr = new Planet[count + 1];
                for (size_t i = 0; i < count; ++i) {
                    newArr[i] = std::move(planets[i]);
                }
                newArr[count] = Planet(nameBuf, d, h, m);
                delete[] planets;
                planets = newArr;
                ++count;
            } else {
                std::cerr << "Ошибка формата строки: " << line << '\n';
            }
        }
        file.close();
        std::cout << "Файл был успешно открыт!\n";
    }
}

void Planet::writeToFile(const Planet* planets, size_t count, const char* filename) {
    std::ofstream file(filename);
    if (!file) return;

    for (size_t i = 0; i < count; ++i) {
        file << planets[i] << "\n";
    }
    file.close();
}

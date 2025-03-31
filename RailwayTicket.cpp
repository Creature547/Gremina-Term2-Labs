#include "RailwayTicket.h"
#include <limits>
#include <sstream>

int RailwayTicket::counter = 0;

void RailwayTicket::allocateString(char*& dest, const char* source) {
    delete[] dest;
    if (source && strlen(source) > 0) {
        dest = new char[strlen(source) + 1];
        strcpy(dest, source);
    } else {
        dest = nullptr;
    }
}

RailwayTicket::RailwayTicket()
    : id(++counter), passengerName(nullptr), seatNumber(0), departureStation(nullptr), price(0.0) {}

RailwayTicket::RailwayTicket(const char* name, int seat, const char* station, double price)
    : id(++counter), seatNumber(seat), price(price) {
    allocateString(passengerName, name);
    allocateString(departureStation, station);
}

RailwayTicket::~RailwayTicket() {
    delete[] passengerName;
    delete[] departureStation;
}

RailwayTicket::RailwayTicket(const RailwayTicket& other)
    : id(++counter), seatNumber(other.seatNumber), price(other.price) {
    allocateString(passengerName, other.passengerName);
    allocateString(departureStation, other.departureStation);
}

RailwayTicket& RailwayTicket::operator=(const RailwayTicket& other) {
    if (this != &other) {
        seatNumber = other.seatNumber;
        price = other.price;
        allocateString(passengerName, other.passengerName);
        allocateString(departureStation, other.departureStation);
    }
    return *this;
}

RailwayTicket::RailwayTicket(RailwayTicket&& other) noexcept
    : id(other.id), // Используем существующий ID
      passengerName(std::exchange(other.passengerName, nullptr)),
      departureStation(std::exchange(other.departureStation, nullptr)),
      seatNumber(other.seatNumber),
      price(other.price) {}

      RailwayTicket& RailwayTicket::operator=(RailwayTicket&& other) noexcept {
        if (this != &other) {
            delete[] passengerName;
            delete[] departureStation;

            id = other.id; // Сохраняем исходный ID
            passengerName = std::exchange(other.passengerName, nullptr);
            departureStation = std::exchange(other.departureStation, nullptr);
            seatNumber = other.seatNumber;
            price = other.price;
        }
        return *this;
    }

const char* RailwayTicket::getPassengerName() const { return passengerName; }
int RailwayTicket::getSeatNumber() const { return seatNumber; }
const char* RailwayTicket::getDepartureStation() const { return departureStation; }
double RailwayTicket::getPrice() const { return price; }

void RailwayTicket::setPassengerName(const char* name) { allocateString(passengerName, name); }
void RailwayTicket::setSeatNumber(int seat) { seatNumber = seat; }
void RailwayTicket::setDepartureStation(const char* station) { allocateString(departureStation, station); }
void RailwayTicket::setPrice(double price) { this->price = price; }

void RailwayTicket::editInteractive() {
    char buffer[256];
    std::cout << "Редактирование билета:\n";

    std::cout << "Пассажир (текущий: " << (passengerName ? passengerName : "N/A") << "): ";
    std::cin.getline(buffer, sizeof(buffer));
    if (strlen(buffer) > 0) setPassengerName(buffer);

    std::cout << "Место (текущее: " << seatNumber << "): ";
    std::cin >> seatNumber;

    std::cin.ignore();
    std::cout << "Станция (текущая: " << (departureStation ? departureStation : "N/A") << "): ";
    std::cin.getline(buffer, sizeof(buffer));
    if (strlen(buffer) > 0) setDepartureStation(buffer);

    std::cout << "Цена (текущая: " << price << "): ";
    std::cin >> price;
    std::cin.ignore();
}

void RailwayTicket::printInfo() const {
    std::cout << "Пассажир: " << (passengerName ? passengerName : "N/A")
              << "\nМесто: " << seatNumber
              << "\nСтанция: " << (departureStation ? departureStation : "N/A")
              << "\nЦена: " << price << " руб.\n\n";
}

std::ostream& operator<<(std::ostream& os, const RailwayTicket& ticket) {
    os << ticket.getPassengerName() << ";"
       << ticket.getSeatNumber() << ";"
       << ticket.getDepartureStation() << ";"
       << ticket.getPrice();
    return os;
}

std::istream& operator>>(std::istream& is, RailwayTicket& ticket) {
    char buffer[256];
    int seat;
    double price;

    is.getline(buffer, sizeof(buffer), ';');
    ticket.setPassengerName(buffer);

    is >> seat;
    is.ignore();

    is.getline(buffer, sizeof(buffer), ';');
    ticket.setDepartureStation(buffer);

    is >> price;
    is.ignore();

    ticket.setSeatNumber(seat);
    ticket.setPrice(price);

    return is;
}

bool RailwayTicket::operator<(const RailwayTicket& other) const {
    return seatNumber < other.seatNumber;
}

bool RailwayTicket::operator==(const RailwayTicket& other) const {
    return strcmp(passengerName, other.passengerName) == 0;
}


// RailwayTicket.cpp
// RailwayTicket.cpp
void RailwayTicket::readFromFile(RailwayTicket*& tickets, size_t& count, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: файл " << filename << " не найден!\n";
        return;
    }

    // Удаляем старые данные
    delete[] tickets;
    tickets = nullptr;
    count = 0;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Пропускаем пустые строки

        std::istringstream iss(line);
        char nameBuf[256], stationBuf[256];
        int seat;
        double price;

        // Чтение данных через разделитель ';'
        if (iss.getline(nameBuf, sizeof(nameBuf), ';') &&
            iss >> seat &&
            iss.ignore() && // Пропускаем ';'
            iss.getline(stationBuf, sizeof(stationBuf), ';') &&
            iss >> price)
        {
            // Создаем новый массив с перемещением старых данных
            RailwayTicket* newArr = new RailwayTicket[count + 1];
            for (size_t i = 0; i < count; ++i) {
                newArr[i] = std::move(tickets[i]);
            }
            newArr[count] = RailwayTicket(nameBuf, seat, stationBuf, price);

            delete[] tickets;
            tickets = newArr;
            ++count;
        } else {
            std::cerr << "Ошибка формата строки: " << line << '\n';
        }
    }
    file.close();
    std::cout << "Файл был успешно открыт!\n";
}

void RailwayTicket::writeToFile(const RailwayTicket* tickets, size_t count, const char* filename) {
    std::ofstream file(filename);
    if (!file) return;

    for (size_t i = 0; i < count; ++i) {
        file << tickets[i] << "\n";
    }
    file.close();
}

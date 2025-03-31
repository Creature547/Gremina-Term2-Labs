#ifndef RAILWAYTICKET_H
#define RAILWAYTICKET_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>

class RailwayTicket {
private:
    char* passengerName;
    int seatNumber;
    char* departureStation;
    double price;
    static int counter;
    int id;

    void allocateString(char*& dest, const char* source);

public:
    RailwayTicket();
    RailwayTicket(const char* name, int seat, const char* station, double price);
    ~RailwayTicket();

    RailwayTicket(const RailwayTicket& other);
    RailwayTicket& operator=(const RailwayTicket& other);
    RailwayTicket(RailwayTicket&& other) noexcept;
    RailwayTicket& operator=(RailwayTicket&& other) noexcept;

    const char* getPassengerName() const;
    int getSeatNumber() const;
    const char* getDepartureStation() const;
    double getPrice() const;

    void setPassengerName(const char* name);
    void setSeatNumber(int seat);
    void setDepartureStation(const char* station);
    void setPrice(double price);

    void editInteractive();
    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& os, const RailwayTicket& ticket);
    friend std::istream& operator>>(std::istream& is, RailwayTicket& ticket);
    bool operator<(const RailwayTicket& other) const;
    bool operator==(const RailwayTicket& other) const;
    
    static void readFromFile(RailwayTicket*& tickets, size_t& count, const char* filename);
    static void writeToFile(const RailwayTicket* tickets, size_t count, const char* filename);
};

#endif

#pragma once

#include <cstring>
#include <iostream>

class PrintedEdition {
protected:
    char* title;
    int year;
    int pages;

    void copyString(char*& dest, const char* source);

public:
    PrintedEdition(const char* title, int year, int pages);
    PrintedEdition(const PrintedEdition& other);
    virtual ~PrintedEdition();

    PrintedEdition& operator=(const PrintedEdition& other);

    virtual void show() const = 0;
    virtual const char* getType() const = 0;

    const char* getTitle() const { return title; }
    int getYear() const { return year; }
    int getPages() const { return pages; }
};

class Magazine : public PrintedEdition {
private:
    char* theme;
    int issue;

public:
    Magazine(const char* title, int year, int pages, const char* theme, int issue);
    Magazine(const Magazine& other);
    ~Magazine() override;

    Magazine& operator=(const Magazine& other);

    void show() const override;
    const char* getType() const override { return "Magazine"; }
};

class Book : public PrintedEdition {
private:
    char* author;
    int chapters;

public:
    Book(const char* title, int year, int pages, const char* author, int chapters);
    Book(const Book& other);
    ~Book() override;

    Book& operator=(const Book& other);

    void show() const override;
    const char* getType() const override { return "Book"; }
};

class Textbook : public PrintedEdition {
private:
    char* subject;
    char* institution;

public:
    Textbook(const char* title, int year, int pages, const char* subject, const char* institution);
    Textbook(const Textbook& other);
    ~Textbook() override;

    Textbook& operator=(const Textbook& other);

    void show() const override;
    const char* getType() const override { return "Textbook"; }
};

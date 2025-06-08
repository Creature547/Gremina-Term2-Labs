#include "MyClasses.h"

void PrintedEdition::copyString(char*& dest, const char* source) {
    if (source) {
        dest = new char[strlen(source) + 1];
        strcpy(dest, source);
    } else {
        dest = nullptr;
    }
}

PrintedEdition::PrintedEdition(const char* title, int year, int pages)
    : year(year), pages(pages) {
    copyString(this->title, title);
    std::cout << "PrintedEdition()" << std::endl;
}

PrintedEdition::PrintedEdition(const PrintedEdition& other)
    : year(other.year), pages(other.pages) {
    copyString(title, other.title);
    std::cout << "PrintedEdition(const PrintedEdition&)" << std::endl;
}

PrintedEdition::~PrintedEdition() {
    delete[] title;
    std::cout << "~PrintedEdition()" << std::endl;
}

PrintedEdition& PrintedEdition::operator=(const PrintedEdition& other) {
    if (this != &other) {
        delete[] title;
        copyString(title, other.title);
        year = other.year;
        pages = other.pages;
    }
    std::cout << "PrintedEdition::operator=" << std::endl;
    return *this;
}

// MAGAZINE

Magazine::Magazine(const char* title, int year, int pages, const char* theme, int issue)
    : PrintedEdition(title, year, pages), issue(issue) {
    copyString(this->theme, theme);
    std::cout << "Magazine()" << std::endl;
}

Magazine::Magazine(const Magazine& other)
    : PrintedEdition(other), issue(other.issue) {
    copyString(theme, other.theme);
    std::cout << "Magazine(const Magazine&)" << std::endl;
}

Magazine::~Magazine() {
    delete[] theme;
    std::cout << "~Magazine()" << std::endl;
}

Magazine& Magazine::operator=(const Magazine& other) {
    if (this != &other) {
        PrintedEdition::operator=(other);
        delete[] theme;
        copyString(theme, other.theme);
        issue = other.issue;
    }
    std::cout << "Magazine::operator=" << std::endl;
    return *this;
}

void Magazine::show() const {
    std::cout << "Magazine: " << title << ", Year: " << year << ", Pages: " << pages
              << ", Theme: " << theme << ", Issue: " << issue << std::endl;
}

// BOOK

Book::Book(const char* title, int year, int pages, const char* author, int chapters)
    : PrintedEdition(title, year, pages), chapters(chapters) {
    copyString(this->author, author);
    std::cout << "Book()" << std::endl;
}

Book::Book(const Book& other)
    : PrintedEdition(other), chapters(other.chapters) {
    copyString(author, other.author);
    std::cout << "Book(const Book&)" << std::endl;
}

Book::~Book() {
    delete[] author;
    std::cout << "~Book()" << std::endl;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        PrintedEdition::operator=(other);
        delete[] author;
        copyString(author, other.author);
        chapters = other.chapters;
    }
    std::cout << "Book::operator=" << std::endl;
    return *this;
}

void Book::show() const {
    std::cout << "Book: " << title << ", Year: " << year << ", Pages: " << pages
              << ", Author: " << author << ", Chapters: " << chapters << std::endl;
}

// TEXTBOOK

Textbook::Textbook(const char* title, int year, int pages, const char* subject, const char* institution)
    : PrintedEdition(title, year, pages) {
    copyString(this->subject, subject);
    copyString(this->institution, institution);
    std::cout << "Textbook()" << std::endl;
}

Textbook::Textbook(const Textbook& other)
    : PrintedEdition(other) {
    copyString(subject, other.subject);
    copyString(institution, other.institution);
    std::cout << "Textbook(const Textbook&)" << std::endl;
}

Textbook::~Textbook() {
    delete[] subject;
    delete[] institution;
    std::cout << "~Textbook()" << std::endl;
}

Textbook& Textbook::operator=(const Textbook& other) {
    if (this != &other) {
        PrintedEdition::operator=(other);
        delete[] subject;
        delete[] institution;
        copyString(subject, other.subject);
        copyString(institution, other.institution);
    }
    std::cout << "Textbook::operator=" << std::endl;
    return *this;
}

void Textbook::show() const {
    std::cout << "Textbook: " << title << ", Year: " << year << ", Pages: " << pages
              << ", Subject: " << subject << ", Institution: " << institution << std::endl;
}

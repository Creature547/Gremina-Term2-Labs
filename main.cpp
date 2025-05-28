#include <iostream>
#include "containers/myvector.h"
#include "containers/myset.h"

#include <string>
#include <cstring>

void main_try() {
    char* newstr = new char[10];
    strcpy(newstr, "Hiii");
    MyVector<char*> v((char*)"Hello!");
    v.add_element(newstr);
    v.add_element((char*)"Привет!");
    v.add_element((char*)"Привет!");
    v.add_element((char*)"Привет!");
    v.add_element((char*)"Привет!");
    v.add_element((char*)"Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    v.add_element((char*)"Привет!");
    v.add_element((char*)"Привет!");
    v.add_element((char*)"Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    MyVector<char*> v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;
    for (int i = 0; i < v1.get_size(); i++)
        v1.delete_element(0);
    std::cout << "Вектор v1: " << v1 << std::endl;

    v1 = v;
    std::cout << "V1 = " << v1 << std::endl;

    MySet<char*> s((char*)"Yes"), s1, s2;
    s.add_element(newstr);
    s.add_element((char*)"Привет!");
    s.add_element((char*)"No");
    s.add_element((char*)"Hello!");
    std::cout << "Множество s: " << s << std::endl;
    s1.add_element((char*)"Cat");
    s1.add_element((char*)"No");
    s1.add_element((char*)"Привет!");
    std::cout << "Множество s1: " << s1 << std::endl;
    s2 = s1 - s;
    std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    s2 = s - s1;
    std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    s2 = s1 + s;
    std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    s2 = s1 * s;
    std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    MySet<char*> s3 = s2;
    std::cout << "Множество s3=s2: " << s3 << std::endl;
    if (s3 == s2)
        std::cout << "Множество s3=s2\n";
    else
        std::cout << "Множество s3!=s2\n";

    if (s3 == s1)
        std::cout << "Множество s3=s1\n";
    else
        std::cout << "Множество s3!=s1\n";
    if (s1 == s3)
        std::cout << "Множество s1=s3\n";
    else
        std::cout << "Множество s1!=s3\n";
    delete[] newstr;
}

int main() {
    setlocale(LC_ALL, "Russian");

    main_try();
    std::cout << "next" << std::endl;

    MyVector<int> v(5);
    v.add_element(4);
    v.add_element(1);
    v.add_element(3);
    v.add_element(2);
    v.add_element(4);
    std::cout << "Вектор v: " << v << '\n';
    v.sort();
    std::cout << "Вектор v: " << v << '\n';
    v.delete_element(2);
    v.delete_element(2);
    std::cout << "Вектор v: " << v << '\n';
    std::cout << "v.find(4): " << v.find(4) << '\n';
    std::cout << "v.find(3): " << v.find(3) << '\n';
    std::cout << "v.get_capacity(): " << v.get_capacity() << '\n';
    std::cout << "v.size(): " << v.get_size() << '\n';

    std::cout << std::endl;
    std::cout << "next" << std::endl;

    char text[10][11] = {"A", "BB", "CCC", "DDDD", "EEEEE", "FFFFFF", "GGGGGGG", "HHHHHHHH", "JJJJJJJJJ", "KKKKKKKKKK"};
    MyVector<char*> v1(text[5]);
    v1.add_element(text[3]);
    v1.add_element(text[1]);
    v1.add_element(text[9]);
    v1.add_element(text[0]);
    v1.sort();
    MyVector<char*> v2(v1);
    v2.add_element(text[7]);
    v2.add_element(text[8]);
    std::cout << "Вектор v1: " << v1 << '\n';
    std::cout << "Вектор v2: " << v2 << '\n';
    std::cout << "v1.find(text[4]): " << v1.find(text[4]) << '\n';
    std::cout << "v1.find(text[5]): " << v1.find(text[5]) << '\n';

    std::cout << std::endl;
    std::cout << "next" << std::endl;

    MySet<int> A;
    A.add_element(1);
    A.add_element(2);
    A.add_element(5);
    A.add_element(4);
    MySet<int> B;
    B.add_element(2);
    B.add_element(3);
    B.add_element(5);
    B.add_element(6);

    std::cout << A << ' ' << B << '\n';
    std::cout << A + B << "\n";
    std::cout << A - B << "\n";
    std::cout << A * B << "\n";
    std::cout << A << ' ' << B << '\n';

    MySet<char*> sA;
    for (int i = 0; i < 5; ++i) {
        sA.add_element(text[i]);
    }
    MySet<char*> sB;
    for (int i = 3; i < 8; ++i) {
        sB.add_element(text[i]);
    }

    std::cout << sA << " -- " << sB << '\n';
    std::cout << sA + sB << "\n";
    std::cout << sA - sB << "\n";
    std::cout << sA * sB << "\n";

    std::cout << std::endl;
    std::cout << "next" << std::endl;

    std::string str = "stostosto";
    MySet<std::string> stringsA(str);
    str = "tototo";
    stringsA.add_element(str);
    str = "qweqwe";
    stringsA.add_element(str);

    MySet<std::string> stringsB = stringsA;
    str = "reeeeeee";
    stringsA.add_element(str);
    str = "word";
    stringsA.add_element(str);

    std::cout << stringsA << " -- " << stringsB << '\n';
    std::cout << stringsA + stringsB << "\n";
    std::cout << stringsA - stringsB << "\n";
    std::cout << stringsA * stringsB << "\n";

    return 0;
}

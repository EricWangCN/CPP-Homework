#include "MyString.h"

int main() {
    MyString myString("233");
    MyString myString1;
    MyString myString2("2");
    std::cout << MyString::get_num() << "\n" << myString.get_string();
    return 0;
}
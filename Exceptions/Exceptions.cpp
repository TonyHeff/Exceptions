//Anthony Heffernan
//7/27/2023
//CIS.1202.5T1

#include <iostream>

class InvalidCharacterException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid character exception: Start is not a letter (A-Z, a-z).";
    }
};

class InvalidRangeException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid range exception: Target is not a letter (A-Z, a-z) or is attempting to change case of target letter";
    }
};

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw InvalidCharacterException();
    }

    if (!(start >= 'A' && start <= 'Z') && !(start >= 'a' && start <= 'z')) {  // throws exception if not between a and z or A and Z
        throw InvalidCharacterException();
    }

    char target = start + offset;   //allows the claculation of the character based on the total of the start and offset

    if (!(target >= 'A' && target <= 'Z') && !(target >= 'a' && target <= 'z')) {
        throw InvalidRangeException();  //throws exception if character calculation results in target not being between required parameters
    }

    if ((isupper(start) && islower(target)) || (islower(start) && isupper(target))) {
        throw InvalidRangeException();    //throw exception if an attempt to change cases occurs
    }

    return target;
}

int main() {
    try {
        char result1 = character('a', 1);
        std::cout << "character('a', 1) returns: " << result1 << std::endl;
    }
    catch (const InvalidCharacterException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
    catch (const InvalidRangeException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    try {
        char result2 = character('a', -1);                                      //looking for thrown exception
        std::cout << "character('a', -1) returns: " << result2 << std::endl;
    }
    catch (const InvalidCharacterException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
    catch (const InvalidRangeException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    try {
        char result3 = character('Z', -1);
        std::cout << "character('Z', -1) returns: " << result3 << std::endl;
    }
    catch (const InvalidCharacterException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
    catch (const InvalidRangeException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    try {
        char result4 = character('?', 5);
        std::cout << "character('?', 5) returns: " << result4 << std::endl;   //looking for an exception
    }
    catch (const InvalidCharacterException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
    catch (const InvalidRangeException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    try {
        char result5 = character('A', 32);                                   //change of case should throw exception
        std::cout << "character('A', 32) returns: " << result5 << std::endl;
    }
    catch (const InvalidCharacterException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }
    catch (const InvalidRangeException& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}

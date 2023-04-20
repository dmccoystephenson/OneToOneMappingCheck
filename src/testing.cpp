#include <string>
#include <iostream>
#include <map>

bool checkMapping(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    if (s1.length() == 0) {
        return false;
    }
    if (s1.find(' ') != std::string::npos || s2.find(' ') != std::string::npos) {
        return false;
    }

    std::map<char, char> map;

    for (int i = 0; i < s1.length(); i++) {
        // if the character is not in the map, add it
        if (map.find(s1[i]) == map.end()) {
            map[s1[i]] = s2[i];
        }
        // if the character is in the map, check if it maps to the same character
        else {
            if (map[s1[i]] != s2[i]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Checks if two strings are one-to-one mapped.
*/
bool isOneToOneMapping(std::string s1, std::string s2) {
    bool forwardResult = checkMapping(s1, s2);
    if (!forwardResult) {
        return false;
    }

    bool reverseResult = checkMapping(s2, s1);
    if (!reverseResult) {
        return false;
    }
    return true;
}

void runTestSuccess() {
    std::string testName = "runTestSuccess()";
    // prepare
    std::string s1 = "abg";
    std::string s2 = "bcd";

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // assert
    if (result) {
        std::cout << testName << " passed with strings: " << s1 << " and " << s2 << std::endl;
    }
    else {
        std::cout << testName << " failed with strings: " << s1 << " and " << s2 << std::endl;
    }
}

void runTestFailureFooBar() {
    std::string testName = "runTestFailureFooBar()";
    // prepare
    std::string s1 = "foo";
    std::string s2 = "bar";

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // assert
    if (!result) {
        std::cout << testName << " passed with strings: " << s1 << " and " << s2 << std::endl;
    }
    else {
        std::cout << testName << " failed with strings: " << s1 << " and " << s2 << std::endl;
    }
}

void runTestFailureBarFoo() {
    std::string testName = "runTestFailureBarFoo()";
    // prepare
    std::string s1 = "bar";
    std::string s2 = "foo";

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // assert
    if (!result) {
        std::cout << testName << " passed with strings: " << s1 << " and " << s2 << std::endl;
    }
    else {
        std::cout << testName << " failed with strings: " << s1 << " and " << s2 << std::endl;
    }
}

void runTestFailureEmptyString() {
    std::string testName = "runTestFailureEmptyString()";
    // prepare
    std::string s1 = "";
    std::string s2 = "";

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // assert
    if (!result) {
        std::cout << testName << " passed with empty strings" << std::endl;
    }
    else {
        std::cout << testName << " failed with empty strings" << std::endl;
    }
}

void runTestFailureSpaces() {
    std::string testName = "runTestFailureSpaces()";
    // prepare
    std::string s1 = "a b";
    std::string s2 = "b c";

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // assert
    if (!result) {
        std::cout << testName << " passed with strings: " << s1 << " and " << s2 << std::endl;
    }
    else {
        std::cout << testName << " failed with strings: " << s1 << " and " << s2 << std::endl;
    }
}

void runTestFailureDifferentLength() {
    std::string testName = "runTestFailureDifferentLength()";
    // prepare
    std::string s1 = "abc";
    std::string s2 = "abcd";

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // assert
    if (!result) {
        std::cout << testName << " passed with strings: " << s1 << " and " << s2 << std::endl;
    }
    else {
        std::cout << testName << " failed with strings: " << s1 << " and " << s2 << std::endl;
    }
}

void runInteractiveTest() {
    // prepare
    std::string s1;
    std::string s2;

    std::cout << "Enter the first string: ";
    std::cin >> s1;
    
    std::cout << "Enter the second string: ";
    std::cin >> s2;

    // execute
    bool result = isOneToOneMapping(s1, s2);

    // verify
    if (result) {
        std::cout << "True. The strings are one-to-one mapped." << std::endl;
    }
    else {
        std::cout << "False. The strings are not one-to-one mapped." << std::endl;
    }
}

int main() {
    std::cout << " == One-to-One Mapping Tests == " << std::endl;
    runTestSuccess();
    runTestFailureFooBar();
    runTestFailureBarFoo();
    runTestFailureEmptyString();
    runTestFailureSpaces();
    runTestFailureDifferentLength();

    std::cout << "\n == Interactive Testing == " << std::endl;
    while (true) {
        char c;
        std::cout << "Run another test? (y/n): ";
        std::cin >> c;
        if (c == 'y') {
            std::cout << std::endl;
            runInteractiveTest();
        }
        else {
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <cmath>

bool isPrime(int num) {
    for (int counter = 2; counter <= sqrt(num); ++counter) {
        if (0 == num % counter) {
            return false;
        }
    }
    return true;
}

void inputNumbers(int& num1, int& num2) {
    std :: cout << "Enter numbers to find prime divisors : ";
    std :: cin >> num1 >> num2;
    while (!std :: cin || (num1 < 0) || (num2 < 0)) {
        std :: cin.clear();
        std :: cin.ignore();
        std :: cout << "Please input only positive integers : ";
        std :: cin >> num1 >> num2;
    }
}

bool printNotCommonPrimeDeviders(int num1, int num2) {
    int temp = 0;
    bool noOne = 1;
    for (int counter = 2; counter <= num1; ++counter) {
        if (0 == num2 % counter && isPrime(counter)) {
            temp = counter;
        }
        if (0 == num1 % counter && isPrime(counter) && temp != counter) {
            noOne = 0;
            std :: cout << counter << std :: endl;
        } 
    }
    return noOne;
}

int main() {
    int firstNum = 0;
    int secondNum = 0;
    inputNumbers(firstNum, secondNum);
    if (printNotCommonPrimeDeviders(firstNum, secondNum)) {
        std :: cout << "There isn't any not common prime deviders." << std :: endl;
    }

    return 0;
}

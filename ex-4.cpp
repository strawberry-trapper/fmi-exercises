#include <iostream>

const int MAX_SIZE = 1024;

bool isPrime(int num) {
    int a = sqrt(num);
    for (int i = 2; i <= a; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return num > 1;
}

int numOfProblems(int* arr, int length) {
    int problems = 0;

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (i < j) {
                if (isPrime(arr[i]) && isPrime(arr[j]) == false) {
                    problems++;
                }
                else if (isPrime(arr[i]) && isPrime(arr[j]) && arr[i] > arr[j]) {
                    problems++;
                }   
            }
        }
    }

    return problems;
}

int main()
{
    int length;
    std::cout << "How long should your array be: ";
    std::cin >> length;

    while (length < 2) {
        if (length >= 0) {
            std::cout << "Array must have at least 2 elements!" << std::endl;
            std::cout << "How long should your array be: ";
            std::cin >> length;
        }
        else if(length < 0) {
            std::cout << "The array can't have a negative amount of elements!" << std::endl;
            std::cout << "How long should your array be: ";
            std::cin >> length;
        }
    
    }

    int arr[MAX_SIZE];

    for (int i = 0; i < length; ++i) {
        std::cout << "Enter number for " << i + 1 << " element: ";
        std::cin >> arr[i];
    }

    std::cout << "Number of problems in your array: " << numOfProblems(arr, length) << std::endl;

    return 0;
}



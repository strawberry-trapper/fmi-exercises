#include <iostream>

int countDigits(int num) {
	int count = 0;
	do {
		num /= 10;
		count++;
	} while (num > 0);

	return count;
}

bool compatable(int n, int k) {

	int countN = countDigits(n);
	int countK = countDigits(k);


	int copyK = k;
	int copyN = n;
	bool compatable = true;
	if (n < k) {
		for (int i = 0; i < countN; ++i) {
			int currentDigitN = n % 10;
			for (int j = 0; j < countK; ++j) {
				if (currentDigitN == copyK % 10) {
					compatable = true;
					break;
				}
				else {
					compatable = false;

				}
				copyK /= 10;
			}
			copyK = k;
			n /= 10;

			if (compatable == false) {
				break;
			}
		}
	}
	else {
		for (int i = 0; i < countK; ++i) {
			int currentDigitK = n % 10;
			for (int j = 0; j < countN; ++j) {
				if (currentDigitK == copyN % 10) {
					compatable = true;
					break;
				}
				else {
					compatable = false;

				}
				copyN /= 10;
			}
			copyN = k;
			n /= 10;

			if (compatable == false) {
				break;
			}
		}
	
	}

	return compatable;
}

int allDiffDigits(int num) {
	
	int copyNum = num / 10;
	int countNum = countDigits(num);
	int actualCount = countDigits(num);

	for (int i = 0; i < countNum-1; ++i) { // Правя го (count - 1), защото вземам последната цифра  
		int currentDigit = num % 10;	   // и остават само (count - 1) цифри
		
		for (int j = 0; j < countNum-1; ++j) {
			if (currentDigit == copyNum % 10 ) {
				actualCount--;
				break;
			}
			copyNum /= 10;
		}
		num /= 10;
		copyNum = num / 10;
	}

	return actualCount;
}

void weakerNum(int n, int k) {
	int diffDigitsN = allDiffDigits(n);
	int diffDigitsK = allDiffDigits(k);

	if (diffDigitsN > diffDigitsK) {
		std::cout << "The second number is weaker in strength! " << std::endl;
	}
	else if (diffDigitsN < diffDigitsK) {
		std::cout << "The first number is weaker in strength! " << std::endl;
	}
	else{
		std::cout << "The numbers are equal in strength! " << std::endl;
	}
}

int main()
{
	int n;
	int k;
	std::cout << "Enter the first number: " << std::endl;
	std::cin >> n;
	std::cout << "Enter the second number: " << std::endl;
	std::cin >> k;

	if (n < 0) {
		n = -1 * n;
	}
	else if (k < 0) {
		k = -1 * k;
	}

	if (compatable(n, k)) {
		std::cout << allDiffDigits(n) << std::endl;
		std::cout << allDiffDigits(k) << std::endl;

		weakerNum(n, k);
	}
	else {
		std::cout << "Numbers aren't compatable!" << std::endl;
	}

	return 0;
}
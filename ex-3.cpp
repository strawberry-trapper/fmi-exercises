#include <iostream>
#include <iomanip>

const int MAX_SIZE = 1024;

bool validation(int num) {
	if(num < 0) {
		std::cout << "Value of the number must be positive! " << std::endl;
		return true;
	}

	return false;
}

void create(int* arrX, int* arrY, int size) {

	for (int i = 0; i < size; ++i) {
		std::cout << "Enter " << i + 1 << " coordinates: ";
		std::cin >> arrX[i];
		std::cin >> arrY[i];
		while (validation(arrX[i]) || validation(arrY[i])) {
			std::cout << "Enter coordinates of position " << i+1 << " again: ";
				std::cin >> arrX[i];
				std::cin >> arrY[i];
		}
	}

}

int power(int base, int exponent) {

	int number = 1;

	for (int i = 0; i < exponent; ++i) {
		number *= base;
	}

	return number;
}

/*
double squareRoot(int num) {

	double squareRoot = num;
	double copyNum;

	do {
		copyNum = squareRoot;
		squareRoot = 0.5 *(copyNum + num / copyNum);
	
	}while(squareRoot* squareRoot - num > 0);
	return squareRoot;
}
*/ // не работи


double findPointLength(int* arrX, int* arrY, int size) {
	double length = 0;

	for (int i = 0; i < size - 1; ++i) {
		length += sqrt(power(arrX[i] - arrX[i + 1], 2) + power(arrY[i] - arrY[i + 1], 2));
	}

	return length;
}

bool sameDistance(int* arrX1, int* arrY1, int size1, int* arrX2, int* arrY2, int size2) {
	if (findPointLength(arrX1, arrY1, size1) == findPointLength(arrX2, arrY2, size2)) {
		return true;
	}

	return false;
}

void compareDistance(int* arrX1, int* arrY1, int size1, int* arrX2, int* arrY2, int size2) {

	double distance1 = findPointLength(arrX1, arrY1, size1);
	double distance2 = findPointLength(arrX2, arrY2, size2);

	bool sameDis = sameDistance(arrX1, arrY1, size1, arrX2, arrY2, size2);
	if (sameDis) {
		std::cout << std::boolalpha << sameDis << std::endl;
		std::cout << std::fixed << std::setprecision(2) << distance1 << std::endl;
	}
	else {
		std::cout << std::boolalpha << sameDis << std::endl;
	}
}


int main()
{
	int size1;
	std::cin >> size1;

	while (validation(size1)) {
		std::cout << "Enter size_1 again: ";
		std::cin >> size1;
	}
	

	int arrX1[MAX_SIZE];
	int arrY1[MAX_SIZE];

	create(arrX1, arrY1, size1);

	int size2;
	std::cin >> size2;
	
	while (validation(size2)) {
		std::cout << "Enter size_2 again: ";
		std::cin >> size2;
	}
	

	int arrX2[MAX_SIZE];
	int arrY2[MAX_SIZE];
	
	create(arrX2, arrY2, size2);
	
	compareDistance(arrX1, arrY1, size1, arrX2, arrY2, size2);

	return 0;
}

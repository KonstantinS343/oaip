#include <iostream>
int Cycle(int*, int, int);
int Recursion(int*, int, int,int);
int main() {
	int SizeOfArray = 0;
	std::cout << "Enter a size of array:" << std::endl;
	std::cin >> SizeOfArray;
	int* ArrayOfNumber = new int[SizeOfArray];
	std::cout << "Enter each element of array:" << std::endl;
	for (int i = 0; i < SizeOfArray; i++) {
		std::cin >> ArrayOfNumber[i];
	}
	for (int j = 0; j < SizeOfArray; j++) {
		int min = ArrayOfNumber[j];
		int bufer = 0;
		for (int i = j; i < SizeOfArray; i++) {
			if (ArrayOfNumber[i] < min) {
				bufer = ArrayOfNumber[j];
				ArrayOfNumber[j] = ArrayOfNumber[i];
				ArrayOfNumber[i] = bufer;
				min = ArrayOfNumber[j];
			}
		}
	}
	for (int i = 0; i < SizeOfArray; i++)
	{
		std::cout << ArrayOfNumber[i];
		std::cout << " ";
	}
	std::cout << "\nEnter the element of array:" << std::endl;
	int key = 0, choice = 0;
	std::cin >> key;
	std::cout << "Select the operations:\n1.Cycle\n2.Function" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		for (int i = 0; i < SizeOfArray; i++) {
			if (ArrayOfNumber[i] == ArrayOfNumber[Cycle(ArrayOfNumber, key, SizeOfArray)]) {
				std::cout << "Index of your element:" <<i<<std::endl;
			}
		}
		break;
	case 2:
		for (int i = 0; i < SizeOfArray; i++) {
			if (ArrayOfNumber[i] == ArrayOfNumber[Recursion(ArrayOfNumber, key, SizeOfArray, 0)]) {
				std::cout << "Index of your element:" << i << std::endl;
			}
		}
		break;
	}
}
int Cycle(int* ArrayOfNumber, int key, int SizeOfArray) {
	bool CheckKey = false;
	int begin = 0, end = SizeOfArray, middle = 0;
	while (CheckKey != true) {
		middle = (begin + end) / 2;
		if (ArrayOfNumber[middle] == key) {
			CheckKey = true;
		}
		if (key > ArrayOfNumber[middle]) {
			begin = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}
	return middle;
}
int Recursion(int* ArrayOfNumber, int key, int end, int begin) {
	int middle = (begin + end) / 2;
	if (ArrayOfNumber[middle] == key) {
		return middle;
	}
	if (ArrayOfNumber[middle] < key) {
		return Recursion(ArrayOfNumber, key, end, middle + 1);
	}
	else {
		return Recursion(ArrayOfNumber, key, middle - 1, begin);
	}
}
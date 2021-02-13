#include <iostream>
using namespace std;

int checksum(unsigned long long int number);

int main() {
	unsigned long long int number = 0;

	//while (number > 9999999999999999 || number < 10000000000000) {  //needs to be 13 to 16 digits
		cout << "Number >" << flush;
		cin >> number;
	//}

	int creditCode =  checksum(number) % 10;

	int digit16 = (number % 10000000000000000) / 1000000000000000;
	cout << "digit 16: " << digit16 << endl;
	int digit15 = (number % 1000000000000000) / 100000000000000;
	cout << "digit 15: " << digit15 << endl;
	int digit14 = (number % 100000000000000) / 10000000000000;
	cout << "digit 14: " << digit14 << endl;
	int digit13 = (number % 10000000000000) / 1000000000000;
	cout << "digit 13: " << digit13 << endl;

	if (creditCode == 0) {
		if (digit16 == 4) {
			cout << "VISA" << endl;
			return 0;
		}

		if (digit16 == 5 && (digit15 > 0 || digit15 < 6)) {
			cout << "MASTERCARD" << endl;
			return 0;
		}

		if (digit15 == 3 && (digit14 == 4 || digit14 == 7)) {
			cout << "AMERICAN EXPRESS" << endl;
			return 0;
		}

		if (digit15 == 4 || digit14 == 4 || digit13 == 4) {
			cout << "VISA" << endl;
			return 0;
		}
		
		cout << "INVALID" << endl;

	}
	else {
		cout << "INVALID" << endl;
	}

	return 0;
}

int checksum(unsigned long long int number) {
	/* brute force solution
	cout << "checksum initialized..." << endl;
	int firstDigit = number % 10;
	int secondDigit = (number % 100) / 10;
	int thirdDigit = (number % 1000) / 100;
	int fourthDigit = (number % 10000) / 1000;
	int fifthDigit = (number % 100000) / 10000;
	int sixthDigit = (number % 1000000) / 100000;
	int seventhDigit = (number % 10000000) / 1000000;
	
	/*cout << firstDigit << endl;
	cout << secondDigit << endl;
	cout << thirdDigit << endl;
	cout << fourthDigit << endl;
	cout << fifthDigit << endl;
	cout << sixthDigit << endl;
	cout << seventhDigit << endl;*/

	int evenSum = 0;

	// a clear pattern is above seen. switching to a loop
	for (unsigned long long int i = 100; i <= 10000000000000000; i *= 100) {  // use unsigned long long int to avoid overflow
		int currentDigit = (number % i) / (i / 10); 
		cout << currentDigit << " x 2  = "<< currentDigit * 2 << endl; // multiply every other digit by two and print

		if (currentDigit * 2 > 9) {
			cout << "double digit here" << endl;
			int currentDigitDoubledSeperated = 1 + ((currentDigit * 2) % 10); // 1 from the tens place added
			cout << "1 + (second digit) = " << currentDigitDoubledSeperated  << endl;
			
			evenSum = evenSum + currentDigitDoubledSeperated;
			
		}
		else if (currentDigit * 2 < 10) {
			int currentDigitDoubled = currentDigit * 2;

			evenSum = evenSum + currentDigitDoubled;
		}
	}

	cout << "Sum of the digits for even numbers * 2: " << evenSum << endl;

	int oddSum = 0;

	for (unsigned long long int i = 10; i <= 10000000000000000; i *= 100) {
		int currentDigit = (number % i) / (i / 10);
		cout << currentDigit << endl;
		oddSum = oddSum + currentDigit;
	}

	cout << "Sum of the odd digit numbers: " << oddSum << endl;

	int totalSum = evenSum + oddSum;
	cout << "CheckSum total: " << totalSum << endl;
	
	return totalSum;
}
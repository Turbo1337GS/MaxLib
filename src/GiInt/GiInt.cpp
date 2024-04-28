#include "GiInt.hpp"





/**
 * @brief Adds two integers.
 *
 * @param num1 The first integer to be added.
 * @param num2 The second integer to be added.
 * @return The sum of the two input integers.
 * @throws std::invalid_argument If the sum exceeds the integer limits.
 */

int GiInt::add(int num1, int num2) {
    long long result = static_cast<long long>(num1) + static_cast<long long>(num2);
    
    if (result < INT_MIN || result > INT_MAX) {
        throw std::invalid_argument("Integer overflow error in GiInt::add");
    }
    
    return static_cast<int>(result);
}

// Example usage:
// GiInt giInt;
// int sum = giInt.add(10, 20);
// std::cout << "Sum: " << sum << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Subtracts the second number from the first number.
 *
 * @param num1 The first number.
 * @param num2 The second number to subtract from the first number.
 * @return The result of subtracting num2 from num1.
 * @throws std::invalid_argument If the result is outside the range of representable values by the data type.
 */
int GiInt::subtract(int num1, int num2) {
    try {
        // Perform subtraction
        long long result = static_cast<long long>(num1) - static_cast<long long>(num2);

        // Check if the result is within the range of an integer
        if (result < INT_MIN || result > INT_MAX) {
            throw std::invalid_argument("Result is outside the range of representable values.");
        }

        return static_cast<int>(result);
    } catch (const std::exception& e) {
        throw std::invalid_argument("subtract: Error caused by " + std::string(e.what()));
    }
}

// Example usage:
// GiInt giInt;
// int result = giInt.subtract(10, 5);
// std::cout << "Result: " << result << std::endl;




/**
 * @brief Multiplies two integers.
 *
 * @param num1 The first integer to be multiplied.
 * @param num2 The second integer to be multiplied.
 * @return The result of multiplying num1 by num2.
 * @throws std::invalid_argument If the result is too large to be represented by an integer.
 */
int GiInt::multiply(int num1, int num2) {
    long long result = static_cast<long long>(num1) * static_cast<long long>(num2);
    
    if (result > INT_MAX || result < INT_MIN) {
        throw std::invalid_argument("Result is too large to be represented by an integer. GiInt::multiply");
    }
    
    return static_cast<int>(result);
}

// Example usage:
// GiInt giInt;
// int result = giInt.multiply(5, 10);
// std::cout << "Result: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Divides the first number by the second number and returns the quotient.
 *
 * @param num1 The dividend.
 * @param num2 The divisor. Must be non-zero.
 * @return The quotient of the division.
 * @throws std::invalid_argument If the divisor is zero.
 */
int GiInt::divide(int num1, int num2) {
    if (num2 == 0) {
        throw std::invalid_argument("Division by zero error: divide");
    }

    return num1 / num2;
}

// Example usage:
// GiInt giInt;
// int result = giInt.divide(10, 2);
// std::cout << "Result of division: " << result << std::endl;




// GiInt.cpp
/**
 * @brief Returns the remainder of dividing the first number by the second number.
 *
 * @param num1 The dividend.
 * @param num2 The divisor.
 * @return The remainder of the division.
 * @throws std::invalid_argument If the second number (divisor) is zero.
 */
int GiInt::mod(int num1, int num2) {
    if (num2 == 0) {
        throw std::invalid_argument("Division by zero error: mod");
    }
    
    return num1 % num2;
}

// Example usage:
// GiInt giInt;
// int result = giInt.mod(10, 3); // Result will be 1




/**
 * @brief Increments a number by one.
 *
 * @param number The number to be incremented.
 * @return The incremented number.
 * @throws std::invalid_argument If the input number is invalid.
 */

int GiInt::increment(int number) {
    if (number < std::numeric_limits<int>::max()) {
        return number + 1;
    } else {
        throw std::invalid_argument("GiInt::increment: Error, number increment would exceed maximum integer value.");
    }
}

// Example usage:
// GiInt giInt;
// int originalNumber = 5;
// int incrementedNumber = giInt.increment(originalNumber);
// std::cout << "Original number: " << originalNumber << std::endl;
// std::cout << "Incremented number: " << incrementedNumber << std::endl;




/**
 * @brief Decrements a number by one.
 *
 * @param number The number to decrement.
 * @return The decremented number.
 * @throws std::invalid_argument If the input number is not valid.
 */
int GiInt::decrement(int number) {
    if (number < std::numeric_limits<int>::min()) {
        throw std::invalid_argument("decrement: Error caused by input number");
    }
    
    return number - 1;
}

// Example usage:
// GiInt giInt;
// int originalNumber = 10;
// int decrementedNumber = giInt.decrement(originalNumber);
// std::cout << "Original number: " << originalNumber << std::endl;
// std::cout << "Decremented number: " << decrementedNumber << std::endl;




/**
 * @brief Changes the sign of a number to its opposite.
 *
 * @param num The number to negate.
 * @return The negated number.
 * @throws std::invalid_argument If the input is not a number.
 */

int GiInt::negate(int num) {
    // Check if the input is a number
    if (!std::isdigit(num)) {
        throw std::invalid_argument("negate: Input is not a number.");
    }

    // Negate the number
    return -num;
}

// Example usage:
// GiInt giInt;
// int num = 10;
// int negatedNum = giInt.negate(num);
// std::cout << "Negated number: " << negatedNum << std::endl;




/**
 * @brief Returns the absolute value of a number.
 *
 * @param number The input number.
 * @return The absolute value of the input number.
 */
int GiInt::abs(int number) {
    if (number < 0) {
        return -number;
    }
    return number;
}

// Example usage:
// GiInt giInt;
// int input = -10;
// int result = giInt.abs(input);
// // Result will be 10




/**
 * @brief Returns the smaller of two numbers.
 *
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The smaller of the two numbers.
 */
int GiInt::min(int num1, int num2) {
    if (num1 < num2) {
        return num1;
    } else {
        return num2;
    }
}

// Example usage:
// GiInt giInt;
// int result = giInt.min(10, 5);
// // Result should be 5




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Returns the greater of two numbers.
 *
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The greater of the two numbers.
 * @throws std::invalid_argument If both numbers are equal.
 */
int GiInt::max(int num1, int num2) {
    if (num1 == num2) {
        throw std::invalid_argument("Both numbers are equal. Cannot determine the greater number.");
    }

    return (num1 > num2) ? num1 : num2;
}

// Example usage:
// GiInt giInt;
// int result = giInt.max(5, 10);
// std::cout << "The greater number is: " << result << std::endl;




/**
 * @brief Raises a number to the power of the specified exponent.
 *
 * @param base The base number.
 * @param exponent The exponent to raise the base to.
 * @return The result of raising the base to the exponent.
 * @throws std::invalid_argument If the exponent is negative.
 */

int GiInt::pow(int base, int exponent) {
    if (exponent < 0) {
        throw std::invalid_argument("Exponent must be a non-negative number.");
    }

    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Example usage:
// GiInt giInt;
// int base = 2;
// int exponent = 3;
// int result = giInt.pow(base, exponent);
// std::cout << base << " raised to the power of " << exponent << " is: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Calculates the square root of a number.
 *
 * @param number The number for which the square root will be calculated.
 * @return The square root of the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
double GiInt::sqrt(double number) {
    if (number < 0) {
        throw std::invalid_argument("Cannot calculate square root of a negative number. GiInt::sqrt");
    }

    // Implementation of square root calculation
    double result = sqrt(number);

    return result;
}

// Example usage:
// GiInt gi;
// double number = 16.0;
// double result = gi.sqrt(number);
// std::cout << "Square root of " << number << " is: " << result << std::endl;




/**
 * @brief Checks if a number is even.
 *
 * @param number The number to be checked.
 * @return true if the number is even, false otherwise.
 * @throws std::invalid_argument If the number is negative.
 */
bool GiInt::isEven(int number) {
    if (number < 0) {
        throw std::invalid_argument("isEven: Number cannot be negative.");
    }

    return number % 2 == 0;
}

// Example usage:
// GiInt giInt;
// int num = 10;
// if (giInt.isEven(num)) {
//     std::cout << num << " is even." << std::endl;
// } else {
//     std::cout << num << " is not even." << std::endl;
// }




/**
 * @brief Checks if a number is odd.
 *
 * @param number The number to check.
 * @return true if the number is odd, false otherwise.
 */
bool GiInt::isOdd(int number) {
    if (number % 2 != 0) {
        return true;
    } else {
        return false;
    }
}

// Example usage:
// GiInt giInt;
// int num = 5;
// bool isNumOdd = giInt.isOdd(num);
// if (isNumOdd) {
//     std::cout << num << " is odd." << std::endl;
// } else {
//     std::cout << num << " is not odd." << std::endl;
// }




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Changes the sign of a number to its opposite.
 *
 * @param number The input number to change the sign of.
 * @return The number with the opposite sign.
 * @throws std::invalid_argument If the input number is zero.
 */
int GiInt::flipSign(int number) {
    if (number == 0) {
        throw std::invalid_argument("GiInt::flipSign: Error - Cannot flip the sign of zero.");
    }

    return -number;
}

// Example usage:
// GiInt giInt;
// int number = 10;
// int result = giInt.flipSign(number);
// std::cout << "Number with opposite sign: " << result << std::endl;




/**
 * @brief Converts a number to a string in binary format.
 *
 * @param number The number to convert to binary string.
 * @return The binary string representation of the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
std::string GiInt::binaryToString(int number) {
    if (number < 0) {
        throw std::invalid_argument("GiInt::binaryToString: Input number cannot be negative.");
    }

    if (number == 0) {
        return "0";
    }

    std::string binaryString;
    while (number > 0) {
        binaryString = std::to_string(number % 2) + binaryString;
        number /= 2;
    }

    return binaryString;
}

// Example usage:
// GiInt giInt;
// int number = 10;
// std::string binaryString = giInt.binaryToString(number);
// std::cout << "Binary representation of " << number << ": " << binaryString << std::endl;




/**
 * @brief Converts a number to a hexadecimal string.
 *
 * @param number The number to convert to hexadecimal string.
 * @return The hexadecimal string representation of the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
std::string GiInt::hexToString(int number) {
    if (number < 0) {
        throw std::invalid_argument("GiInt::hexToString: Input number cannot be negative.");
    }

    std::stringstream ss;
    ss << std::hex << number;
    std::string result = ss.str();

    return result;
}

// Example usage:
// int num = 255;
// std::string hexStr = GiInt::hexToString(num);
// std::cout << "Hexadecimal representation of " << num << " is: " << hexStr << std::endl;




/**
 * @brief Converts a number to a string in decimal system.
 *
 * @param number The number to be converted to a string.
 * @return The string representation of the input number.
 * @throws std::invalid_argument If the input number is not a valid number.
 */
std::string GiInt::decimalToString(int number) {
    // Check if the input number is valid
    if (!std::isfinite(number)) {
        throw std::invalid_argument("decimalToString: Invalid input number.");
    }

    // Convert the number to a string
    std::string result = std::to_string(number);

    return result;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// std::string result = giInt.decimalToString(number);
// std::cout << "Number as string: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Clamps a number within the specified range.
 *
 * @param value The number to clamp.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return The clamped value within the range [min, max].
 * @throws std::invalid_argument If min is greater than max.
 */
int GiInt::clamp(int value, int min, int max) {
    if (min > max) {
        throw std::invalid_argument("GiInt::clamp: Error - min value cannot be greater than max value.");
    }

    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

// Example usage:
// int num = 25;
// int minVal = 10;
// int maxVal = 50;
// int result = GiInt::clamp(num, minVal, maxVal);
// std::cout << "Clamped value: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Compares two integers and returns the result of the comparison.
 *
 * @param num1 The first integer to compare.
 * @param num2 The second integer to compare.
 * @return 0 if num1 is equal to num2, 1 if num1 is greater than num2, -1 if num1 is less than num2.
 */
int GiInt::compareTo(int num1, int num2) {
    if (num1 == num2) {
        return 0;
    } else if (num1 > num2) {
        return 1;
    } else {
        return -1;
    }
}

// Example usage:
// GiInt giInt;
// int result = giInt.compareTo(5, 10);
// // 'result' will be -1 since 5 is less than 10




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Calculates the factorial of a number.
 *
 * @param n The number for which to calculate the factorial.
 * @return The factorial of the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial: Input number cannot be negative");
    }

    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Example usage:
// GiInt giInt;
// int number = 5;
// int result = giInt.factorial(number);
// std::cout << "Factorial of " << number << " is: " << result << std::endl;




/**
 * @brief Calculates the greatest common divisor of two numbers.
 *
 * @param a The first number.
 * @param b The second number.
 * @return The greatest common divisor of the two numbers.
 * @throws std::invalid_argument If either a or b is zero.
 */
int GiInt::gcd(int a, int b) {
    if (a == 0 || b == 0) {
        throw std::invalid_argument("Invalid input: numbers cannot be zero. gcd");
    }

    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Example usage:
// GiInt giInt;
// int result = giInt.gcd(48, 18);
// std::cout << "Greatest common divisor: " << result << std::endl;




/**
 * @brief Calculates the Least Common Multiple (LCM) of two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The LCM of the two input integers.
 * @throws std::invalid_argument If either input is zero.
 */
int GiInt::lcm(int a, int b) {
    if (a == 0 || b == 0) {
        throw std::invalid_argument("GiInt::lcm - Error: Input cannot be zero.");
    }
    
    int max = (a > b) ? a : b;
    int lcm = max;

    while (true) {
        if (lcm % a == 0 && lcm % b == 0) {
            break;
        }
        lcm += max;
    }

    return lcm;
}

// Example usage:
// GiInt giInt;
// int result = giInt.lcm(12, 18);
// std::cout << "LCM of 12 and 18 is: " << result << std::endl;




/**
 * @brief Checks if a number is a prime number.
 *
 * @param number The number to check.
 * @return true if the number is prime, false otherwise.
 * @throws std::invalid_argument If the input number is less than 2.
 */
bool GiInt::isPrime(int number) {
    if (number < 2) {
        throw std::invalid_argument("isPrime: Input number must be greater than or equal to 2.");
    }

    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiInt giInt;
// int number = 17;
// bool isNumberPrime = giInt.isPrime(number);
// std::cout << number << " is prime: " << std::boolalpha << isNumberPrime << std::endl;




/**
 * @brief Finds the closest prime number greater than a given number.
 *
 * @param num The input number to find the next prime for.
 * @return The next prime number greater than the input number.
 * @throws std::invalid_argument If the input number is less than 2.
 */
int GiInt::nextPrime(int num) {
    if (num < 2) {
        throw std::invalid_argument("nextPrime: Input number must be 2 or greater.");
    }

    int next = num + 1;
    while (true) {
        bool isPrime = true;
        for (int i = 2; i <= next / 2; ++i) {
            if (next % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            return next;
        }
        ++next;
    }
}

// Example usage:
// GiInt giInt;
// int input = 10;
// int result = giInt.nextPrime(input);
// std::cout << "Next prime number after " << input << " is: " << result << std::endl;




/**
 * @brief Counts the number of digits in an integer.
 *
 * @param num The integer for which to count the digits.
 * @return The number of digits in the input integer.
 * @throws std::invalid_argument If the input is not an integer.
 */
int GiInt::countDigits(int num) {
    if (num < 0) {
        num = -num; // Make the number positive if it's negative
    }

    int count = (num == 0) ? 1 : 0; // If the number is 0, it has 1 digit

    while (num != 0) {
        count++;
        num /= 10;
    }

    return count;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// int result = giInt.countDigits(number);
// std::cout << "Number of digits in " << number << ": " << result << std::endl;




/**
 * @brief Sums the digits of a given number.
 *
 * @param num The number whose digits are to be summed.
 * @return The sum of the digits of the number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::sumDigits(int num) {
    if (num < 0) {
        throw std::invalid_argument("sumDigits: Input number cannot be negative.");
    }

    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// int sum = giInt.sumDigits(number);
// std::cout << "Sum of digits of " << number << " is: " << sum << std::endl;




/**
 * @brief Reverses the digits of a given number.
 *
 * @param number The number whose digits are to be reversed.
 * @return The number with reversed digits.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::reverseDigits(int number) {
    if (number < 0) {
        throw std::invalid_argument("reverseDigits: Input number cannot be negative.");
    }

    int reversedNumber = 0;
    while (number != 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    return reversedNumber;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// int reversedNumber = giInt.reverseDigits(number);
// std::cout << "Reversed number: " << reversedNumber << std::endl;




/**
 * @brief Checks if a given number is a palindrome.
 *
 * @param num The number to be checked for being a palindrome.
 * @return true if the number is a palindrome, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */
bool GiInt::isPalindrome(int num) {
    if (num < 0) {
        throw std::invalid_argument("isPalindrome: Input number cannot be negative.");
    }

    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return originalNum == reversedNum;
}

// Example usage:
// GiInt giInt;
// int number = 12321;
// if (giInt.isPalindrome(number)) {
//     std::cout << number << " is a palindrome." << std::endl;
// } else {
//     std::cout << number << " is not a palindrome." << std::endl;
// }




// GiInt.cpp

/**
 * @brief Rotates the digits of a number to the left.
 *
 * This function takes an integer input and rotates its digits to the left by one position.
 *
 * @param num The integer number to rotate.
 * @return The number after rotating its digits to the left by one position.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::rotateLeft(int num) {
    if (num < 0) {
        throw std::invalid_argument("rotateLeft: Input number cannot be negative.");
    }

    // Extract the first digit
    int firstDigit = num / 10;

    // Extract the remaining digits
    int remainingDigits = num % 10;

    // Calculate the new number after rotating digits to the left
    int rotatedNum = remainingDigits * pow(10, static_cast<int>(log10(num))) + firstDigit;

    return rotatedNum;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// int rotatedNumber = giInt.rotateLeft(number);
// std::cout << "Rotated number: " << rotatedNumber << std::endl;




// GiInt.cpp
// File path: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Rotates the digits of a number to the right.
 *
 * This function takes an integer input and rotates the digits to the right.
 * For example, rotating 1234 to the right would result in 4123.
 *
 * @param num The integer number to rotate.
 * @return The rotated number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::rotateRight(int num) {
    if (num < 0) {
        throw std::invalid_argument("rotateRight: Input number cannot be negative.");
    }

    if (num < 10) {
        return num; // No rotation needed for single-digit numbers
    }

    int lastDigit = num % 10;
    int remainingNum = num / 10;
    int multiplier = 1;

    while (multiplier <= remainingNum) {
        multiplier *= 10;
    }

    return lastDigit * multiplier + remainingNum;
}

// Example usage:
// int number = 1234;
// int rotatedNumber = GiInt::rotateRight(number);
// std::cout << "Rotated number: " << rotatedNumber << std::endl;




/**
 * @brief Checks if a number is a part of the Fibonacci sequence.
 *
 * @param num The number to check.
 * @return true if the number is a part of the Fibonacci sequence, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */

bool GiInt::isFibonacci(int num) {
    if (num < 0) {
        throw std::invalid_argument("isFibonacci: Input number cannot be negative.");
    }

    int a = 0, b = 1;
    while (a < num) {
        int temp = a;
        a = b;
        b = temp + b;
    }

    return a == num;
}

// Example usage:
// GiInt giInt;
// int number = 5;
// bool result = giInt.isFibonacci(number);
// std::cout << number << " is " << (result ? "a part of the Fibonacci sequence." : "not a part of the Fibonacci sequence.") << std::endl;




/**
 * @brief Finds the nearest Fibonacci number to the given input number.
 *
 * @param num The input number to find the nearest Fibonacci number to.
 * @return The nearest Fibonacci number to the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::nearestFibonacci(int num) {
    if (num < 0) {
        throw std::invalid_argument("nearestFibonacci: Input number cannot be negative.");
    }

    int prev = 0;
    int curr = 1;
    int next = prev + curr;

    while (next <= num) {
        prev = curr;
        curr = next;
        next = prev + curr;
    }

    // Calculate the absolute differences between the current and previous Fibonacci numbers and the input number
    int diff1 = num - curr;
    int diff2 = next - num;

    // Return the nearest Fibonacci number
    if (diff1 < diff2) {
        return curr;
    } else {
        return next;
    }
}

// Example usage:
// GiInt giInt;
// int input = 15;
// int result = giInt.nearestFibonacci(input);
// std::cout << "Nearest Fibonacci number to " << input << " is: " << result << std::endl;




/**
 * @brief Counts the number of set bits in the binary representation of an integer.
 *
 * @param num The integer for which to count the set bits.
 * @return The number of set bits in the binary representation of the integer.
 * @throws std::invalid_argument If the input integer is negative.
 */
int GiInt::numSetBits(int num) {
    if (num < 0) {
        throw std::invalid_argument("GiInt::numSetBits: Input integer must be non-negative.");
    }

    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

// Example usage:
// GiInt giInt;
// int num = 25;
// int result = giInt.numSetBits(num);
// std::cout << "Number of set bits in " << num << ": " << result << std::endl;




// GiInt.cpp
// File path: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp


/**
 * @brief Finds the longest gap between set bits in a binary number.
 *
 * @param N The input integer for which to find the binary gap.
 * @return The length of the longest binary gap.
 * @throws std::invalid_argument If the input integer is negative.
 */
int GiInt::binaryGap(int N) {
    if (N < 0) {
        throw std::invalid_argument("Input integer cannot be negative. GiInt::binaryGap");
    }

    int maxGap = 0;
    int currentGap = 0;
    bool counting = false;

    while (N > 0) {
        if (N % 2 == 1) {
            if (!counting) {
                counting = true;
            } else {
                maxGap = std::max(maxGap, currentGap);
            }
            currentGap = 0;
        } else {
            if (counting) {
                currentGap++;
            }
        }
        N = N >> 1;
    }

    return maxGap;
}

// Example usage:
// GiInt giInt;
// int result = giInt.binaryGap(1041);
// std::cout << "Longest binary gap: " << result << std::endl;




/**
 * @brief Swaps the values of two integers.
 *
 * @param a The first integer to swap.
 * @param b The second integer to swap.
 * @throws std::invalid_argument If the input integers are the same.
 */
void GiInt::swap(int& a, int& b) {
    if (a == b) {
        throw std::invalid_argument("swap: Error - The input integers are the same.");
    }

    a = a + b;
    b = a - b;
    a = a - b;
}

// Example usage:
// int num1 = 5;
// int num2 = 10;
// std::cout << "Before swap - num1: " << num1 << ", num2: " << num2 << std::endl;
// GiInt::swap(num1, num2);
// std::cout << "After swap - num1: " << num1 << ", num2: " << num2 << std::endl;




// GiInt.cpp

/**
 * @brief Calculates the average of two numbers.
 *
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The average of the two numbers.
 * @throws std::invalid_argument If division by zero occurs.
 */
double GiInt::average(int num1, int num2) {
    if (num2 == 0) {
        throw std::invalid_argument("Division by zero error in average function");
    }
    
    return static_cast<double>(num1 + num2) / 2;
}

// Example usage:
// GiInt giInt;
// int number1 = 10;
// int number2 = 20;
// try {
//     double avg = giInt.average(number1, number2);
//     std::cout << "Average: " << avg << std::endl;
// } catch (const std::invalid_argument& e) {
//     std::cerr << e.what() << std::endl;
// }




/**
 * @brief Checks if a number is a square of another number.
 *
 * @param number The number to check.
 * @return true if the number is a square of another number, false otherwise.
 */
bool GiInt::isSquare(int number) {
    if (number < 0) {
        throw std::invalid_argument("isSquare: Input number must be a non-negative integer.");
    }

    int root = sqrt(number);
    return (root * root == number);
}

// Example usage:
// GiInt gi;
// int num = 25;
// if (gi.isSquare(num)) {
//     std::cout << num << " is a square number." << std::endl;
// } else {
//     std::cout << num << " is not a square number." << std::endl;
// }




/**
 * @brief Checks if a number is a cube of another number.
 *
 * @param num The number to check.
 * @return True if the number is a cube of another number, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */
bool GiInt::isCube(int num) {
    if (num < 0) {
        throw std::invalid_argument("isCube: Input number cannot be negative.");
    }

    int cubeRoot = std::round(std::cbrt(num));
    return (cubeRoot * cubeRoot * cubeRoot == num);
}

// Example usage:
// GiInt giInt;
// int number = 27;
// if (giInt.isCube(number)) {
//     std::cout << number << " is a cube of another number." << std::endl;
// } else {
//     std::cout << number << " is not a cube of another number." << std::endl;
// }




// GiInt.cpp

/**
 * @brief Finds the nearest square number to the given input number.
 *
 * @param num The input number for which the nearest square needs to be found.
 * @return The nearest square number to the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::nearestSquare(int num) {
    if (num < 0) {
        throw std::invalid_argument("nearestSquare: Input number cannot be negative.");
    }

    int lowerSquare = 0;
    int higherSquare = 0;

    // Find the lower and higher square numbers
    for (int i = 0; i * i <= num; i++) {
        lowerSquare = i * i;
        higherSquare = (i + 1) * (i + 1);
    }

    // Determine the nearest square number
    if ((num - lowerSquare) <= (higherSquare - num)) {
        return lowerSquare;
    } else {
        return higherSquare;
    }
}

// Example usage:
// GiInt giInt;
// int input = 17;
// int result = giInt.nearestSquare(input);
// std::cout << "Nearest square to " << input << " is: " << result << std::endl;




// GiInt.cpp

/**
 * @brief Finds the nearest cube number to the given input number.
 *
 * @param num The input number to find the nearest cube for.
 * @return The nearest cube number to the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::nearestCube(int num) {
    if (num < 0) {
        throw std::invalid_argument("nearestCube: Input number cannot be negative.");
    }

    int lowerCube = pow(std::cbrt(num), 3);
    int upperCube = pow(std::cbrt(num) + 1, 3);

    if (abs(num - lowerCube) <= abs(num - upperCube)) {
        return lowerCube;
    } else {
        return upperCube;
    }
}

// Example usage:
// GiInt giInt;
// int inputNum = 27;
// int result = giInt.nearestCube(inputNum);
// std::cout << "Nearest cube to " << inputNum << " is: " << result << std::endl;




/**
 * @brief Simplifies a fraction by finding the greatest common divisor and dividing both the numerator and denominator by it.
 *
 * @param numerator The numerator of the fraction.
 * @param denominator The denominator of the fraction.
 * @return A string representation of the simplified fraction in the format "numerator/denominator".
 * @throws std::invalid_argument If the denominator is zero.
 */
std::string GiInt::simplifyFraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero. simplifyFraction: Error caused by division by zero");
    }

    int gcd = findGCD(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /= gcd;

    // Construct the simplified fraction string
    std::string result = std::to_string(numerator) + "/" + std::to_string(denominator);
    return result;
}

/**
 * @brief Finds the greatest common divisor (GCD) of two numbers using Euclidean algorithm.
 *
 * @param a The first number.
 * @param b The second number.
 * @return The GCD of the two numbers.
 */
int GiInt::findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Example usage:
// GiInt giInt;
// int numerator = 24;
// int denominator = 36;
// std::string simplifiedFraction = giInt.simplifyFraction(numerator, denominator);
// std::cout << "Simplified fraction: " << simplifiedFraction << std::endl;




/**
 * @brief Divides a number proportionally by a given ratio.
 *
 * This function divides a number proportionally by a given ratio.
 *
 * @param number The number to divide.
 * @param ratio The ratio by which to divide the number.
 * @return The result of dividing the number proportionally by the ratio.
 * @throws std::invalid_argument If the ratio is zero.
 */
int GiInt::propDivide(int number, int ratio) {
    if (ratio == 0) {
        throw std::invalid_argument("propDivide: Error - Division by zero is not allowed.");
    }
    
    // Perform the proportional division
    return number / ratio;
}

// Example usage:
// GiInt giInt;
// int result = giInt.propDivide(10, 2);
// std::cout << "Result of proportional division: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Converts a ratio to a fraction.
 *
 * @param ratio The ratio to convert to a fraction.
 * @return std::pair<int, int> A pair representing the fraction in the format (numerator, denominator).
 * @throws std::invalid_argument If the denominator is zero.
 */
std::pair<int, int> GiInt::ratioToFraction(double ratio) {
    // Check if the ratio is negative
    bool isNegative = ratio < 0;
    ratio = std::abs(ratio);

    const double EPSILON = 1e-6; // Tolerance for comparing double values

    int lowerNumerator = 0, lowerDenominator = 1;
    int upperNumerator = 1, upperDenominator = 1;

    // Continued fraction expansion
    while (true) {
        int mediantNumerator = lowerNumerator + upperNumerator;
        int mediantDenominator = lowerDenominator + upperDenominator;

        if (mediantDenominator * (ratio + EPSILON) < mediantNumerator) {
            if (mediantDenominator > 10000) {
                break; // Prevent infinite loop
            }
            upperNumerator = mediantNumerator;
            upperDenominator = mediantDenominator;
        } else if (mediantDenominator * (ratio - EPSILON) > mediantNumerator) {
            if (mediantDenominator > 10000) {
                break; // Prevent infinite loop
            }
            lowerNumerator = mediantNumerator;
            lowerDenominator = mediantDenominator;
        } else {
            if (mediantDenominator < 1 || mediantDenominator > 10000) {
                throw std::invalid_argument("Denominator out of valid range.");
            }
            int finalNumerator = isNegative ? -mediantNumerator : mediantNumerator;
            return std::make_pair(finalNumerator, mediantDenominator);
        }
    }

    throw std::invalid_argument("Unable to convert ratio to fraction.");
}

// Example usage:
// double ratio = 1.5;
// std::pair<int, int> result = ratioToFraction(ratio);
// std::cout << "Fraction: " << result.first << "/" << result.second << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Converts a decimal number to a fraction.
 *
 * @param decimal The decimal number to convert to a fraction.
 * @return The fraction as a string in the format "numerator/denominator".
 * @throws std::invalid_argument If the input decimal is not a finite decimal number.
 */
std::string GiInt::decimalToFraction(double decimal) {
    // Check if the input is a finite decimal number
    if (!std::isfinite(decimal)) {
        throw std::invalid_argument("decimalToFraction: Invalid input, not a finite decimal number.");
    }

    // Convert the decimal to a fraction
    std::ostringstream oss;
    oss << std::setprecision(10) << decimal; // Set precision to avoid floating-point precision issues
    std::string decimalStr = oss.str();

    // Find the position of the decimal point
    size_t decimalPointPos = decimalStr.find('.');
    if (decimalPointPos == std::string::npos) {
        // If no decimal point is found, the number is already an integer
        return decimalStr + "/1"; // Integer as a fraction
    } else {
        // Calculate the numerator and denominator
        int integerPart = std::stoi(decimalStr.substr(0, decimalPointPos));
        int decimalPart = std::stoi(decimalStr.substr(decimalPointPos + 1));
        int denominator = std::pow(10, decimalStr.size() - decimalPointPos - 1);
        
        // Calculate the greatest common divisor (GCD) to simplify the fraction
        int gcd = std::__gcd(decimalPart, denominator);
        int numerator = integerPart * denominator + decimalPart / gcd;
        denominator /= gcd;

        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
}

// Example usage:
// GiInt giInt;
// double inputDecimal = 3.75;
// std::string result = giInt.decimalToFraction(inputDecimal);
// std::cout << "Fraction: " << result << std::endl;




// GiInt.cpp
/**
 * @brief Returns the Fibonacci number at a given index.
 *
 * @param index The index of the Fibonacci number to retrieve.
 * @return The Fibonacci number at the specified index.
 * @throws std::invalid_argument If the index is negative.
 */
int GiInt::fibonacciAtIndex(int index) {
    if (index < 0) {
        throw std::invalid_argument("Index cannot be negative. fibonacciAtIndex");
    }

    if (index == 0) {
        return 0;
    } else if (index == 1) {
        return 1;
    } else {
        int a = 0;
        int b = 1;
        int temp;
        for (int i = 2; i <= index; ++i) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
}

// Example usage:
// GiInt giInt;
// int index = 10;
// int result = giInt.fibonacciAtIndex(index);
// std::cout << "Fibonacci number at index " << index << " is: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Returns the Lucas number at the given index.
 *
 * @param index The index of the Lucas number to retrieve.
 * @return The Lucas number at the specified index.
 * @throws std::invalid_argument If the index is negative.
 */
int GiInt::lucasNumberAtIndex(int index) {
    if (index < 0) {
        throw std::invalid_argument("Invalid index. Index must be a non-negative integer.");
    }

    if (index == 0) {
        return 2; // First Lucas number is 2
    } else if (index == 1) {
        return 1; // Second Lucas number is 1
    } else {
        int a = 2, b = 1, c;
        for (int i = 2; i <= index; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

// Example usage:
// GiInt gi;
// int lucasNum = gi.lucasNumberAtIndex(5); // Get Lucas number at index 5
// std::cout << "Lucas number at index 5: " << lucasNum << std::endl;




/**
 * @brief Calculates the next number in the Hailstone sequence.
 *
 * @param number The current number in the sequence.
 * @return The next number in the Hailstone sequence.
 * @throws std::invalid_argument If the input number is not a positive integer.
 */
int GiInt::hailstoneNext(int number) {
    if (number <= 0) {
        throw std::invalid_argument("GiInt::hailstoneNext: Input number must be a positive integer.");
    }

    if (number % 2 == 0) {
        return number / 2;
    } else {
        return 3 * number + 1;
    }
}

// Example usage:
// GiInt giInt;
// int currentNumber = 10;
// int nextNumber = giInt.hailstoneNext(currentNumber);
// std::cout << "Next number in Hailstone sequence after " << currentNumber << " is: " << nextNumber << std::endl;




/**
 * @brief Calculates the length of the Hailstone sequence for a given number.
 *
 * @param number The input number for which the Hailstone sequence length is to be calculated.
 * @return The length of the Hailstone sequence for the input number.
 * @throws std::invalid_argument If the input number is less than 1.
 */
int GiInt::hailstoneSequenceLength(int number) {
    if (number < 1) {
        throw std::invalid_argument("Invalid input number. Number must be greater than or equal to 1.");
    }

    int length = 1; // Initialize the length to 1 for the input number itself

    while (number != 1) {
        if (number % 2 == 0) {
            number = number / 2;
        } else {
            number = 3 * number + 1;
        }
        length++;
    }

    return length;
}

// Example usage:
// GiInt giInt;
// int number = 27;
// int sequenceLength = giInt.hailstoneSequenceLength(number);
// std::cout << "Hailstone sequence length for number " << number << " is: " << sequenceLength << std::endl;




// GiInt.cpp
/**
 * @brief Checks if a number is a power of two.
 *
 * @param num The number to check.
 * @return true If the number is a power of two, false otherwise.
 */
bool GiInt::isPowerOfTwo(int num) {
    if (num <= 0) {
        throw std::invalid_argument("isPowerOfTwo: Input number must be greater than zero.");
    }

    return (num & (num - 1)) == 0;
}

// Example usage:
// GiInt giInt;
// int number = 16;
// bool result = giInt.isPowerOfTwo(number);
// std::cout << number << " is a power of two: " << std::boolalpha << result << std::endl;




// GiInt.cpp

/**
 * @brief Finds the next power of two greater than or equal to the given number.
 *
 * @param num The input number to find the next power of two for.
 * @return The next power of two greater than or equal to the input number.
 * @throws std::invalid_argument If the input number is less than or equal to 0.
 */
int GiInt::nextPowerOfTwo(int num) {
    if (num <= 0) {
        throw std::invalid_argument("nextPowerOfTwo: Input number must be greater than 0.");
    }

    num--; // To handle the case where the input number is already a power of 2
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16);
    num++; // Increment to get the next power of two

    return num;
}

// Example usage:
// int number = 15;
// int result = GiInt::nextPowerOfTwo(number);
// std::cout << "Next power of two for " << number << " is: " << result << std::endl;




// GiInt.cpp

/**
 * @brief Finds the closest smaller power of two to the given number.
 *
 * @param num The input number to find the closest smaller power of two for.
 * @return The closest smaller power of two to the input number.
 * @throws std::invalid_argument If the input number is less than or equal to 0.
 */
int GiInt::previousPowerOfTwo(int num) {
    if (num <= 0) {
        throw std::invalid_argument("Input number must be greater than 0. GiInt::previousPowerOfTwo");
    }

    int power = 1;
    while (power * 2 < num) {
        power *= 2;
    }

    return power;
}

// Example usage:
// GiInt giInt;
// int input = 17;
// int result = giInt.previousPowerOfTwo(input);
// std::cout << "Closest smaller power of two to " << input << " is: " << result << std::endl;




/**
 * @brief Counts the number of distinct prime factors of a given number.
 *
 * @param number The input number to count prime factors.
 * @return The count of distinct prime factors of the input number.
 * @throws std::invalid_argument If the input number is less than 2.
 */
int GiInt::countPrimeFactors(int number) {
    if (number < 2) {
        throw std::invalid_argument("countPrimeFactors: Input number must be 2 or greater.");
    }

    int count = 0;
    for (int i = 2; i * i <= number; ++i) {
        while (number % i == 0) {
            ++count;
            number /= i;
        }
    }
    if (number > 1) {
        ++count;
    }
    return count;
}

// Example usage:
// GiInt giInt;
// int number = 60;
// int result = giInt.countPrimeFactors(number);
// std::cout << "Number of distinct prime factors of " << number << ": " << result << std::endl;




/**
 * @brief Sums up the prime factors of a given number.
 *
 * @param num The number for which prime factors need to be summed.
 * @return The sum of all prime factors of the input number.
 * @throws std::invalid_argument If the input number is less than 2.
 */
int GiInt::sumPrimeFactors(int num) {
    if (num < 2) {
        throw std::invalid_argument("sumPrimeFactors: Input number must be 2 or greater.");
    }

    int sum = 0;
    for (int i = 2; i <= num; ++i) {
        while (num % i == 0) {
            sum += i;
            num /= i;
        }
    }

    return sum;
}

// Example usage:
// GiInt giInt;
// int number = 56;
// int result = giInt.sumPrimeFactors(number);
// std::cout << "Sum of prime factors of " << number << " is: " << result << std::endl;




/**
 * @brief Calculates the product of the digits of a number.
 *
 * @param num The input number for which the product of digits will be calculated.
 * @return The product of the digits of the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::productOfDigits(int num) {
    if (num < 0) {
        throw std::invalid_argument("GiInt::productOfDigits: Input number cannot be negative.");
    }

    int product = 1;
    while (num != 0) {
        int digit = num % 10;
        if (digit != 0) {
            product *= digit;
        }
        num /= 10;
    }

    return product;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// int result = giInt.productOfDigits(number);
// std::cout << "Product of digits of " << number << " is: " << result << std::endl;




/**
 * @brief Finds the lowest common ancestor for two numbers in a given structure (e.g., binary tree).
 *
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The lowest common ancestor of the two numbers.
 * @throws std::invalid_argument If the numbers are negative.
 */

int GiInt::lowestCommonAncestor(int num1, int num2){
        if (num1 < 0 || num2 < 0) {
            throw std::invalid_argument("lowestCommonAncestor: Numbers must be non-negative.");
        }
        
        // Method to find LCA assuming a perfect binary tree layout
        while (num1 != num2) {
            if (num1 > num2) {
                num1 /= 2; // Move to the parent of num1
            } else {
                num2 /= 2; // Move to the parent of num2
            }
        }
        return num1; // At this point, num1 == num2 which is the LCA
    }
// Example usage:
// GiInt giIntObj;
// int num1 = 8, num2 = 12;
// int result = giIntObj.lowestCommonAncestor(num1, num2);
// std::cout << "Lowest common ancestor of " << num1 << " and " << num2 << " is: " << result << std::endl;




// GiInt.cpp

/**
 * @brief Checks if a number is a deficient number (the sum of its divisors is less than the number itself).
 *
 * @param num The number to check.
 * @return true if the number is a deficient number, false otherwise.
 * @throws std::invalid_argument If the input number is less than or equal to 0.
 */
bool GiInt::isDeficientNumber(int num) {
    if (num <= 0) {
        throw std::invalid_argument("isDeficientNumber: Input number must be greater than 0.");
    }

    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum < num;
}

// Example usage:
// int number = 12;
// if (GiInt::isDeficientNumber(number)) {
//     std::cout << number << " is a deficient number." << std::endl;
// } else {
//     std::cout << number << " is not a deficient number." << std::endl;
// }




// GiInt.cpp
/**
 * @brief Checks if a number is a perfect number (sum of divisors equals the number).
 *
 * @param num The number to check.
 * @return true if the number is perfect, false otherwise.
 * @throws std::invalid_argument If the input number is less than 1.
 */
bool GiInt::isPerfectNumber(int num) {
    if (num < 1) {
        throw std::invalid_argument("isPerfectNumber: Input number must be greater than 0.");
    }

    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

// Example usage:
// int number = 28;
// if (isPerfectNumber(number)) {
//     std::cout << number << " is a perfect number." << std::endl;
// } else {
//     std::cout << number << " is not a perfect number." << std::endl;
// }




/**
 * @brief Checks if a number is an abundant number (the sum of its divisors is greater than the number itself).
 *
 * @param number The number to be checked.
 * @return true if the number is an abundant number, false otherwise.
 * @throws std::invalid_argument If the input number is less than 1.
 */
bool GiInt::isAbundantNumber(int number) {
    if (number < 1) {
        throw std::invalid_argument("isAbundantNumber: Input number must be greater than 0.");
    }

    int sum = 0;
    for (int i = 1; i <= number / 2; ++i) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum > number;
}

// Example usage:
// int num = 12;
// if (GiInt::isAbundantNumber(num)) {
//     std::cout << num << " is an abundant number." << std::endl;
// } else {
//     std::cout << num << " is not an abundant number." << std::endl;
// }




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Returns the digit at the specified position in a given number.
 *
 * @param number The input number.
 * @param position The position of the digit to retrieve (0-based index).
 * @return The digit at the specified position.
 * @throws std::invalid_argument If the position is out of range or the input number is negative.
 */
int GiInt::digitAt(int number, int position) {
    if (number < 0) {
        throw std::invalid_argument("GiInt::digitAt: Input number must be non-negative.");
    }

    // Convert the number to a string to access digits easily
    std::string numStr = std::to_string(number);

    if ((size_t)position < 0 || (size_t)position >= numStr.length()) {
        throw std::invalid_argument("GiInt::digitAt: Position out of range.");
    }

    // Get the digit at the specified position
    char digitChar = numStr[position];
    int digit = digitChar - '0'; // Convert char to int

    return digit;
}

// Example usage:
// int num = 12345;
// int pos = 2;
// int result = GiInt::digitAt(num, pos);
// std::cout << "Digit at position " << pos << ": " << result << std::endl;





/**
 * @brief Sets a digit at a specified position in a given number and returns the new number.
 * 
 * @param num The number in which the digit will be replaced.
 * @param position The position of the digit to replace (starting from 0 for the rightmost digit).
 * @param digit The new digit to set at the specified position.
 * @return int The number with the digit set at the specified position.
 * @throws std::invalid_argument If the position is negative, or if the digit is not between 0 and 9, 
 *         or if the position is out of the bounds of the number.
 */
int GiInt::setDigitAt(int num, int position, int digit) {
    if (position < 0) {
        throw std::invalid_argument("setDigitAt: Position cannot be negative.");
    }

    if (digit < 0 || digit > 9) {
        throw std::invalid_argument("setDigitAt: Digit must be between 0 and 9.");
    }

    int currentDigit = (int) (num / pow(10, position)) % 10;

    if (num == 0 && position > 0) {
        throw std::invalid_argument("setDigitAt: Position is out of bounds for the number provided.");
    }

    // Calculate the number to subtract (current digit) and add (new digit)
    int subtractAmount = currentDigit * pow(10, position);
    int addAmount = digit * pow(10, position);

    return num - subtractAmount + addAmount;
}



// GiInt.cpp
/**
 * @brief Combines two numbers into one.
 *
 * This function takes two integer numbers and merges them into one by concatenating their digits.
 *
 * @param num1 The first integer number to merge.
 * @param num2 The second integer number to merge.
 * @return The merged number obtained by concatenating the digits of num1 and num2.
 * @throws std::invalid_argument If num1 or num2 is negative.
 */

int GiInt::mergeNumbers(int num1, int num2) {
    if (num1 < 0 || num2 < 0) {
        throw std::invalid_argument("mergeNumbers: Numbers must be non-negative.");
    }

    std::string num1Str = std::to_string(num1);
    std::string num2Str = std::to_string(num2);

    return std::stoi(num1Str + num2Str);
}

// Example usage:
// GiInt giInt;
// int mergedNumber = giInt.mergeNumbers(123, 456);
// std::cout << "Merged number: " << mergedNumber << std::endl;




/**
 * @brief Splits a number into two parts at a specified position.
 *
 * @param number The number to be split.
 * @param position The position at which to split the number.
 * @return A pair of numbers representing the split parts.
 * @throws std::invalid_argument If the position is out of range.
 */
std::pair<int, int> GiInt::splitNumber(int number, int position) {
    std::string numStr = std::to_string(number);
    
    if ((size_t)position < 0 || (size_t)position >= numStr.length()) {
        throw std::invalid_argument("Position is out of range. splitNumber");
    }
    
    int firstPart = std::stoi(numStr.substr(0, position));
    int secondPart = std::stoi(numStr.substr(position));
    
    return std::make_pair(firstPart, secondPart);
}

// Example usage:
// GiInt giInt;
// int number = 123456;
// int position = 3;
// auto result = giInt.splitNumber(number, position);
// std::cout << "First part: " << result.first << ", Second part: " << result.second << std::endl;




// GiInt.cpp

/**
 * @brief Converts a number to words.
 *
 * This function takes an integer number and converts it into words.
 * It supports numbers from 0 to 999.
 *
 * @param number The integer number to be converted to words.
 * @return The string representation of the number in words.
 * @throws std::invalid_argument If the input number is out of range (less than 0 or greater than 999).
 */
std::string GiInt::numberToWords(int number) {
    if (number < 0 || number > 999) {
        throw std::invalid_argument("Input number is out of range. GiInt::numberToWords");
    }

    // Arrays for number words
    const std::vector<std::string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const std::vector<std::string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    std::string result;

    if (number == 0) {
        return "zero";
    }

    if (number >= 100) {
        result += ones[number / 100] + " hundred ";
        number %= 100;
    }

    if (number >= 20) {
        result += tens[number / 10] + " ";
        number %= 10;
    }

    if (number >= 10) {
        result += teens[number - 10];
    } else if (number > 0) {
        result += ones[number];
    }

    return result;
}

// Example usage:
// GiInt giInt;
// int num = 123;
// std::string words = giInt.numberToWords(num);
// std::cout << num << " in words: " << words << std::endl;




// GiInt.cpp

/**
 * @brief Generates a random number within a specified range.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return A random number within the specified range.
 * @throws std::invalid_argument If the minimum value is greater than the maximum value.
 */
int GiInt::generateRandom(int min, int max) {
    if (min > max) {
        throw std::invalid_argument("generateRandom: Minimum value cannot be greater than the maximum value.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);

    return dis(gen);
}

// Example usage:
// GiInt giInt;
// int randomNumber = giInt.generateRandom(1, 100);
// std::cout << "Random number: " << randomNumber << std::endl;




/**
 * @brief Counts the number of unique digits in a given number.
 *
 * @param number The input number to count unique digits in.
 * @return The count of unique digits in the number.
 * @throws std::invalid_argument If the input number is negative.
 */

int GiInt::numUniqueDigits(int number) {
    if (number < 0) {
        throw std::invalid_argument("numUniqueDigits: Input number cannot be negative.");
    }

    std::unordered_set<char> uniqueDigits;
    std::string numStr = std::to_string(number);

    for (char digit : numStr) {
        if (isdigit(digit)) {
            uniqueDigits.insert(digit);
        }
    }

    return uniqueDigits.size();
}

// Example usage:
// GiInt giInt;
// int number = 987654321;
// int uniqueDigitsCount = giInt.numUniqueDigits(number);
// std::cout << "Number of unique digits in " << number << ": " << uniqueDigitsCount << std::endl;





/**
 * @brief Shifts the bits of a number to the right by a specified amount.
 *
 * @param number The number to shift.
 * @param shiftAmount The number of positions to shift the bits to the right.
 * @return The number after shifting the bits to the right.
 * @throws std::invalid_argument If the shiftAmount is negative.
 */
int GiInt::shiftRight(int number, int shiftAmount) {
    if (shiftAmount < 0) {
        throw std::invalid_argument("shiftRight: Shift amount cannot be negative.");
    }

    return number >> shiftAmount;
}

// Example usage:
// GiInt giInt;
// int number = 10;
// int shiftedNumber = giInt.shiftRight(number, 2);
// std::cout << "Shifted number: " << shiftedNumber << std::endl;




/**
 * @brief Toggles a specific bit in an integer.
 *
 * @param num The integer to toggle the bit in.
 * @param bitPos The position of the bit to toggle (0-indexed).
 * @return The integer after toggling the specified bit.
 * @throws std::invalid_argument If the bit position is out of range (less than 0 or greater than the number of bits in an integer).
 */
int GiInt::toggleBit(int num, int bitPos) {
    if ((size_t)bitPos < 0 || (size_t)bitPos >= (sizeof(int) * 8)) {
        throw std::invalid_argument("Bit position is out of range.");
    }

    return num ^ (1 << bitPos);
}

// Example usage:
// int number = 10; // Binary: 1010
// int position = 1; // Toggle the 2nd bit
// int result = GiInt::toggleBit(number, position); // Result should be 8 (Binary: 1000)




/**
 * @brief Checks if the bit at the specified position is set.
 *
 * @param num The number to check the bit in.
 * @param pos The position of the bit to check (0-indexed).
 * @return true if the bit is set, false otherwise.
 * @throws std::invalid_argument If the position is out of range (less than 0 or greater than the number of bits in num).
 */
bool GiInt::isBitSet(int num, int pos) {
    if ((size_t)pos < 0 || (size_t)pos >= sizeof(int)*8) {
        throw std::invalid_argument("Position out of range in isBitSet function");
    }
    
    return (num & (1 << pos)) != 0;
}

// Example usage:
// GiInt giInt;
// int number = 5; // 101 in binary
// int position = 2;
// bool isSet = giInt.isBitSet(number, position);
// std::cout << "Is bit at position " << position << " set? " << std::boolalpha << isSet << std::endl;




// GiInt.cpp

/**
 * @brief Clears a bit at a specified position in an integer.
 *
 * @param num The integer from which to clear the bit.
 * @param pos The position of the bit to clear (0-indexed).
 * @return The integer with the specified bit cleared.
 * @throws std::invalid_argument If the position is out of range (negative or greater than the number of bits in the integer).
 */
int GiInt::clearBit(int num, int pos) {
    if ((size_t)pos < 0 || (size_t)pos >= sizeof(int) * 8) {
        throw std::invalid_argument("Position out of range in clearBit");
    }

    int mask = ~(1 << pos);
    return num & mask;
}

// Example usage:
// int number = 12; // 1100 in binary
// int position = 2; // Clearing the bit at position 2
// int result = GiInt::clearBit(number, position); // Result will be 8 (1000 in binary)




/**
 * @brief Sets a bit at a specified position in an integer.
 *
 * @param num The integer where the bit will be set.
 * @param pos The position (0-indexed) where the bit will be set.
 * @return The integer with the bit set at the specified position.
 * @throws std::invalid_argument If the position is out of range (negative or greater than the number of bits in an integer).
 */
int GiInt::setBit(int num, int pos) {
    if ((size_t)pos < 0 || (size_t)pos >= (sizeof(int) * 8)) {
        throw std::invalid_argument("Position out of range in setBit function");
    }

    int mask = 1 << pos;
    return num | mask;
}

// Example usage:
// GiInt giInt;
// int number = 5; // 0000 0101 in binary
// int position = 2; // Setting the bit at position 2 (from the right)
// int result = giInt.setBit(number, position); // Result should be 5 (0000 0101) -> 5 (0000 0101) | (0000 0100) = 7 (0000 0111)




/**
 * @brief Returns the position of the least significant set bit.
 *
 * @param num The input integer to find the position of the least significant set bit.
 * @return The position of the least significant set bit (0-indexed).
 * @throws std::invalid_argument If the input number is less than or equal to 0.
 */

int GiInt::lowBit(int num) {
    if (num <= 0) {
        throw std::invalid_argument("lowBit: Input number must be greater than 0.");
    }

    return ffs(num) - 1; // Using ffs (find first set) to find the position of the least significant set bit
}

// Example usage:
// GiInt giInt;
// int position = giInt.lowBit(18); // Returns 1 since the binary representation of 18 is 10010




// GiInt.cpp
// File path: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Returns the position of the most significant set bit.
 *
 * This function takes an integer as input and returns the position of the most significant set bit.
 *
 * @param num The input integer for which the position of the most significant set bit is to be found.
 * @return The position of the most significant set bit. If no bit is set, returns -1.
 */
int GiInt::highBit(int num) {
    if (num == 0) {
        return -1; // No bit is set
    }

    int position = 0;
    while (num > 0) {
        num = num >> 1;
        position++;
    }

    return position;
}

// Example usage:
// GiInt giInt;
// int number = 18; // Binary representation: 10010
// int result = giInt.highBit(number); // Result: 5 (bit at position 5 is the most significant set bit)




// GiInt.cpp

/**
 * @brief Checks if two numbers are anagrams (have the same digits in different order).
 *
 * @param num1 The first number to compare.
 * @param num2 The second number to compare.
 * @return true if the numbers are anagrams, false otherwise.
 * @throws std::invalid_argument If either of the numbers is negative.
 */
bool GiInt::isAnagramNumber(int num1, int num2) {
    if (num1 < 0 || num2 < 0) {
        throw std::invalid_argument("isAnagramNumber: Numbers must be non-negative.");
    }

    // Convert numbers to strings to compare digits
    std::string strNum1 = std::to_string(num1);
    std::string strNum2 = std::to_string(num2);

    // Sort the digits in the strings
    std::sort(strNum1.begin(), strNum1.end());
    std::sort(strNum2.begin(), strNum2.end());

    // Check if the sorted strings are equal
    return strNum1 == strNum2;
}

// Example usage:
// GiInt giInt;
// int number1 = 1234;
// int number2 = 4321;
// bool result = giInt.isAnagramNumber(number1, number2);
// std::cout << number1 << " and " << number2 << " are anagrams: " << std::boolalpha << result << std::endl;




/**
 * @brief Counts the occurrences of a specific digit in a number.
 *
 * @param number The number in which to count the occurrences.
 * @param digit The digit to count occurrences of.
 * @return The count of occurrences of the specified digit in the number.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::countOccurrences(int number, int digit) {
    if (number < 0) {
        throw std::invalid_argument("countOccurrences: Input number cannot be negative.");
    }

    int count = 0;
    while (number != 0) {
        int remainder = number % 10;
        if (remainder == digit) {
            count++;
        }
        number /= 10;
    }

    return count;
}

// Example usage:
// GiInt giInt;
// int number = 123456789;
// int digit = 3;
// int occurrences = giInt.countOccurrences(number, digit);
// std::cout << "Number of occurrences of digit " << digit << " in " << number << " is: " << occurrences << std::endl;




/**
 * @brief Counts the common digits between two numbers.
 *
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The count of common digits between the two numbers.
 * @throws std::invalid_argument If either of the numbers is negative.
 */
int GiInt::numCommonDigits(int num1, int num2) {
    if (num1 < 0 || num2 < 0) {
        throw std::invalid_argument("Both numbers must be non-negative. GiInt::numCommonDigits");
    }

    int commonDigitsCount = 0;
    bool num1Digits[10] = {false};
    
    while (num1 > 0) {
        num1Digits[num1 % 10] = true;
        num1 /= 10;
    }

    while (num2 > 0) {
        if (num1Digits[num2 % 10]) {
            commonDigitsCount++;
        }
        num2 /= 10;
    }

    return commonDigitsCount;
}

// Example usage:
// GiInt giInt;
// int result = giInt.numCommonDigits(12345, 54321);
// std::cout << "Number of common digits: " << result << std::endl;




// GiInt.cpp

/**
 * @brief Rotates the digits of a number by a specified number of places.
 *
 * @param number The input number to rotate digits.
 * @param places The number of places to rotate the digits by.
 * @return The number with digits rotated by the specified number of places.
 * @throws std::invalid_argument If the input number is negative or if the number of places is less than 0.
 */

int GiInt::rotateDigits(int number, int places) {
    if (number < 0 || places < 0) {
        throw std::invalid_argument("GiInt::rotateDigits: Input number cannot be negative and places to rotate must be non-negative.");
    }

    int rotatedNumber = 0;
    
    int divider = 1;

    while (number / divider > 9) {
        divider *= 10;
    }

    for (int i = 0; i < places; i++) {
        int lastDigit = number % 10;
        number /= 10;
        rotatedNumber += lastDigit * divider;
        divider /= 10;
    }

    rotatedNumber += number;

    return rotatedNumber;
}

// Example usage:
// int inputNumber = 123456;
// int rotatedNumber = GiInt::rotateDigits(inputNumber, 2);
// std::cout << "Rotated number: " << rotatedNumber << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Removes leading zeros from a number.
 *
 * @param number The input number as a string.
 * @return std::string The number with leading zeros removed.
 * @throws std::invalid_argument If the input number is empty.
 */
std::string GiInt::trimNumber(std::string number) {
    if (number.empty()) {
        throw std::invalid_argument("trimNumber: Input number is empty.");
    }

    // Find the position of the first non-zero digit
    size_t nonZeroPos = number.find_first_not_of('0');

    // If all zeros, return "0"
    if (nonZeroPos == std::string::npos) {
        return "0";
    }

    // Return the number without leading zeros
    return number.substr(nonZeroPos);
}

// Example usage:
// std::string input = "000123";
// std::string result = trimNumber(input);
// std::cout << "Number with leading zeros removed: " << result << std::endl;




/**
 * @brief Extends the number by adding digits with a specified value.
 *
 * @param number The number to be expanded.
 * @param digitValue The value of the digits to be added.
 * @return The expanded number.
 * @throws std::invalid_argument If the input number is negative.
 */

std::string GiInt::expandNumber(int number, int digitValue) {
    if (number < 0) {
        throw std::invalid_argument("expandNumber: Input number cannot be negative.");
    }

    std::string expandedNumber = std::to_string(number);

    for (char& digit : expandedNumber) {
        int digitInt = digit - '0';
        digitInt += digitValue;
        digit = '0' + (digitInt % 10); // Ensures the digit remains within 0-9 range
    }

    return expandedNumber;
}

// Example usage:
// GiInt giInt;
// int number = 123;
// int digitValue = 3;
// std::string expandedNumber = giInt.expandNumber(number, digitValue);
// std::cout << "Expanded number: " << expandedNumber << std::endl;




/**
 * @brief Compresses a number by removing digits to a specified length.
 *
 * @param number The input number to compress.
 * @param length The desired length of the compressed number.
 * @return The compressed number.
 * @throws std::invalid_argument If the input number is negative or if the length is greater than the number of digits in the input number.
 */
std::string GiInt::compressNumber(int number, int length) {
    if (number < 0) {
        throw std::invalid_argument("compressNumber: Input number must be non-negative.");
    }

    std::string numStr = std::to_string(number);
    if ((size_t)length > numStr.length()) {
        throw std::invalid_argument("compressNumber: Compression length cannot exceed the number of digits.");
    }

    return numStr.substr(0, length);
}

// Example usage:
// GiInt giInt;
// int inputNumber = 123456789;
// int compressionLength = 4;
// std::string compressedNumber = giInt.compressNumber(inputNumber, compressionLength);
// std::cout << "Compressed number: " << compressedNumber << std::endl;




/**
 * @brief Toggles the parity of a given integer (from even to odd and vice versa).
 *
 * @param num The input integer to toggle parity.
 * @return The integer with toggled parity.
 */
int GiInt::toggleParity(int num) {
    if (num % 2 == 0) {
        // If the number is even, make it odd by adding 1
        return num + 1;
    } else {
        // If the number is odd, make it even by subtracting 1
        return num - 1;
    }
}

// Example usage:
// GiInt giInt;
// int number = 10;
// int toggledNumber = giInt.toggleParity(number);
// std::cout << "Toggled number: " << toggledNumber << std::endl;




/**
 * @brief Reflects a number around its center.
 *
 * @param number The number to be reflected.
 * @return int The reflected number.
 * @throws std::invalid_argument If the number is negative.
 */
int GiInt::mirrorNumber(int number) {
    if (number < 0) {
        throw std::invalid_argument("mirrorNumber: Number cannot be negative.");
    }
    
    std::string numStr = std::to_string(number);
    int length = numStr.length();
    int mid = length / 2;
    
    for (int i = 0; i < mid; ++i) {
        std::swap(numStr[i], numStr[length - 1 - i]);
    }
    
    return std::stoi(numStr);
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// int reflectedNumber = giInt.mirrorNumber(number);
// std::cout << "Reflected number: " << reflectedNumber << std::endl;




// GiInt.cpp
/**
 * @brief Checks if the digits in a number are in ascending order.
 *
 * @param number The input number to check.
 * @return true if the digits are in ascending order, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */

bool GiInt::isAscending(int number) {
    if (number < 0) {
        throw std::invalid_argument("GiInt::isAscending: Input number cannot be negative.");
    }

    int prevDigit = number % 10;
    number /= 10;

    while (number > 0) {
        int currentDigit = number % 10;
        if (currentDigit >= prevDigit) {
            prevDigit = currentDigit;
            number /= 10;
        } else {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// bool result = giInt.isAscending(number);
// std::cout << "Are digits in " << number << " in ascending order? " << std::boolalpha << result << std::endl;




/**
 * @brief Checks if the digits in a number are in descending order.
 *
 * @param number The input number to check.
 * @return true if the digits are in descending order, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */

bool GiInt::isDescending(int number) {
    if (number < 0) {
        throw std::invalid_argument("isDescending: Input number cannot be negative.");
    }

    int prevDigit = 10; // Start with a value greater than any digit
    while (number > 0) {
        int currentDigit = number % 10;
        if (currentDigit >= prevDigit) {
            return false;
        }
        prevDigit = currentDigit;
        number /= 10;
    }
    return true;
}

// Example usage:
// GiInt giInt;
// int number = 54321;
// bool result = giInt.isDescending(number);
// std::cout << "Are digits in descending order? " << std::boolalpha << result << std::endl;




/**
 * @brief Shuffles the digits of a given number randomly.
 *
 * @param number The input number to shuffle its digits.
 * @return int The number with its digits shuffled randomly.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::shuffleDigits(int number) {
    if (number < 0) {
        throw std::invalid_argument("shuffleDigits: Input number must be non-negative.");
    }

    // Convert the number to a string to shuffle its digits
    std::string numStr = std::to_string(number);

    // Shuffle the digits randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numStr.begin(), numStr.end(), g);

    // Convert the shuffled string back to an integer
    int shuffledNumber = std::stoi(numStr);

    return shuffledNumber;
}

// Example usage:
// GiInt giInt;
// int inputNumber = 123456;
// int shuffledNumber = giInt.shuffleDigits(inputNumber);
// std::cout << "Original number: " << inputNumber << std::endl;
// std::cout << "Shuffled number: " << shuffledNumber << std::endl;




// GiInt.cpp

/**
 * @brief Sorts the digits of a number in ascending order.
 *
 * @param number The input number to sort its digits.
 * @return The number with its digits sorted in ascending order.
 * @throws std::invalid_argument If the input number is negative.
 */
int GiInt::sortDigitsAsc(int number) {
    if (number < 0) {
        throw std::invalid_argument("sortDigitsAsc: Input number cannot be negative.");
    }

    // Convert the number to a string for easier digit sorting
    std::string numStr = std::to_string(number);

    // Sort the digits in ascending order
    std::sort(numStr.begin(), numStr.end());

    // Convert the sorted string back to an integer
    int sortedNumber = std::stoi(numStr);

    return sortedNumber;
}

// Example usage:
// GiInt giInt;
// int inputNumber = 354671;
// int result = giInt.sortDigitsAsc(inputNumber);
// std::cout << "Number with digits sorted in ascending order: " << result << std::endl;




// File: /home/turbo/Pulpit/github/MaxLib/src/GiInt/GiInt.cpp

/**
 * @brief Sorts the digits of a number in descending order.
 *
 * @param number The number whose digits need to be sorted.
 * @return The number with its digits sorted in descending order.
 * @throws std::invalid_argument If the input number is negative.
 */

int GiInt::sortDigitsDesc(int number) {
    if (number < 0) {
        throw std::invalid_argument("sortDigitsDesc: Input number cannot be negative.");
    }

    // Convert number to string for easier digit sorting
    std::string numberStr = std::to_string(number);

    // Sort digits in descending order
    std::sort(numberStr.begin(), numberStr.end(), std::greater<char>());

    // Convert sorted string back to integer
    int sortedNumber = std::stoi(numberStr);

    return sortedNumber;
}

// Example usage:
// GiInt giInt;
// int number = 384719;
// int sortedNumber = giInt.sortDigitsDesc(number);
// std::cout << "Number with digits sorted in descending order: " << sortedNumber << std::endl;




/**
 * @brief Checks if a number is a Harshad number (a number that is divisible by the sum of its digits).
 *
 * @param number The number to check.
 * @return True if the number is a Harshad number, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */
bool GiInt::isHarshadNumber(int number) {
    if (number < 0) {
        throw std::invalid_argument("GiInt::isHarshadNumber: Input number cannot be negative.");
    }

    int sumOfDigits = 0;
    int originalNumber = number;

    // Calculate the sum of digits
    while (number > 0) {
        sumOfDigits += number % 10;
        number /= 10;
    }

    // Check if the number is divisible by the sum of its digits
    return (originalNumber % sumOfDigits == 0);
}

// Example usage:
// GiInt giInt;
// int number = 18;
// if (giInt.isHarshadNumber(number)) {
//     std::cout << number << " is a Harshad number." << std::endl;
// } else {
//     std::cout << number << " is not a Harshad number." << std::endl;
// }




/**
 * @brief Calculates the arithmetic mean of the digits in a number.
 *
 * @param num The input number for which the arithmetic mean of digits will be calculated.
 * @return The arithmetic mean of the digits in the input number.
 * @throws std::invalid_argument If the input number is negative.
 */
double GiInt::meanOfDigits(int num) {
    if (num < 0) {
        throw std::invalid_argument("meanOfDigits: Input number cannot be negative.");
    }

    int sum = 0;
    int count = 0;
    int tempNum = num;

    // Calculate the sum of digits and count the number of digits
    while (tempNum != 0) {
        sum += tempNum % 10;
        tempNum /= 10;
        count++;
    }

    // Calculate the arithmetic mean
    double mean = static_cast<double>(sum) / count;
    return mean;
}

// Example usage:
// GiInt giInt;
// int number = 12345;
// double result = giInt.meanOfDigits(number);
// std::cout << "Arithmetic mean of digits in " << number << " is: " << result << std::endl;




// GiInt.cpp
/**
 * @brief Determines the frequency of each digit in a given number.
 *
 * @param num The input number for which to determine digit frequency.
 * @return A map containing the frequency of each digit in the number.
 * @throws std::invalid_argument If the input number is negative.
 */

std::map<int, int> GiInt::digitFrequency(int num) {
    if (num < 0) {
        throw std::invalid_argument("GiInt::digitFrequency: Input number cannot be negative.");
    }

    std::map<int, int> frequencyMap;

    while (num > 0) {
        int digit = num % 10;
        frequencyMap[digit]++;
        num /= 10;
    }

    return frequencyMap;
}

// Example usage:
// GiInt giInt;
// int number = 123456789;
// std::map<int, int> result = giInt.digitFrequency(number);
// for (const auto& pair : result) {
//     std::cout << "Digit: " << pair.first << ", Frequency: " << pair.second << std::endl;
// }




/**
 * @brief Replaces a digit in a number with another digit.
 *
 * @param number The original number where the digit will be replaced.
 * @param digitToReplace The digit to be replaced.
 * @param replacementDigit The digit to replace with.
 * @return The number with the specified digit replaced.
 * @throws std::invalid_argument If the input number is negative or if the digitToReplace or replacementDigit is not a valid digit (0-9).
 */
int GiInt::replaceDigit(int number, int digitToReplace, int replacementDigit) {
    if (number < 0 || digitToReplace < 0 || digitToReplace > 9 || replacementDigit < 0 || replacementDigit > 9) {
        throw std::invalid_argument("replaceDigit: Invalid input. Ensure number is non-negative and digits are between 0 and 9.");
    }

    int result = 0;
    int position = 1;

    while (number != 0) {
        int currentDigit = number % 10;
        number /= 10;

        if (currentDigit == digitToReplace) {
            result += replacementDigit * position;
        } else {
            result += currentDigit * position;
        }

        position *= 10;
    }

    return result;
}

// Example usage:
// GiInt giInt;
// int originalNumber = 12345;
// int replacedNumber = giInt.replaceDigit(originalNumber, 3, 7);
// std::cout << "Replaced number: " << replacedNumber << std::endl;




/**
 * @brief Checks if a number is automorphic (a number whose square ends with the same number).
 *
 * @param num The number to be checked.
 * @return true if the number is automorphic, false otherwise.
 * @throws std::invalid_argument If the input number is negative.
 */
bool GiInt::isAutomorphic(int num) {
    if (num < 0) {
        throw std::invalid_argument("isAutomorphic: Input number cannot be negative.");
    }

    long long square = static_cast<long long>(num) * static_cast<long long>(num);
    std::string numStr = std::to_string(num);
    std::string squareStr = std::to_string(square);

    return squareStr.substr(squareStr.length() - numStr.length()) == numStr;
}

// Example usage:
// GiInt giInt;
// int number = 5;
// if (giInt.isAutomorphic(number)) {
//     std::cout << number << " is an automorphic number." << std::endl;
// } else {
//     std::cout << number << " is not an automorphic number." << std::endl;
// }




/**
 * @brief Repeats the given number a specified number of times.
 *
 * @param number The number to repeat.
 * @param times The number of times to repeat the input number.
 * @return The repeated number as a string.
 * @throws std::invalid_argument If the input number is negative or if the times to repeat is less than 1.
 */

std::string GiInt::repeatNumber(int number, int times) {
    if (number < 0 || times < 1) {
        throw std::invalid_argument("repeatNumber: Input number must be non-negative and times must be at least 1.");
    }

    std::string repeatedNumber;
    for (int i = 0; i < times; ++i) {
        repeatedNumber += std::to_string(number);
    }

    return repeatedNumber;
}

// Example usage:
// GiInt giInt;
// int inputNumber = 12;
// int repeatTimes = 3;
// std::string repeatedResult = giInt.repeatNumber(inputNumber, repeatTimes);
// std::cout << "Repeated number: " << repeatedResult << std::endl;
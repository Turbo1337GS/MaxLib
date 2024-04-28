#include <cmath>
#include <any>
#include <regex>
#include <string>
#include <stdexcept>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <cassert>
#include <vector>
#include <sstream>
#include <cctype>
#include <functional>
#include <random>
#include <stdexcept>
#include <iomanip>
#include <bitset>
#include <iomanip>
#include <stack>
#include <utility>
#include <unordered_set>
#include <fstream>
#include <chrono>

class GiInt
{
public:
    int add(int num1, int num2);
    int subtract(int num1, int num2);
    int multiply(int num1, int num2);
    int divide(int num1, int num2);
    int mod(int num1, int num2);
    int increment(int number);
    int decrement(int number);
    int negate(int num);
    int abs(int number);
    int min(int num1, int num2);
    int max(int num1, int num2);
    int pow(int base, int exponent);
    double sqrt(double number);
    bool isEven(int number);
    bool isOdd(int number);
    int flipSign(int number);
    std::string binaryToString(int number);
    std::string hexToString(int number);
    std::string decimalToString(int number);
    int clamp(int value, int min, int max);
    int compareTo(int num1, int num2);
    int factorial(int n);
    int gcd(int a, int b);
    int lcm(int a, int b);
        bool isPrime(int number);
        int nextPrime(int num);
        int countDigits(int num);
        int sumDigits(int num);
        int reverseDigits(int number);
        bool isPalindrome(int num);
        int rotateLeft(int num);
        int rotateRight(int num);
        bool isFibonacci(int num);
        int nearestFibonacci(int num);
        int numSetBits(int num);
        int binaryGap(int N);
        void swap(int &a, int &b);
        double average(int num1, int num2);
        bool isSquare(int number);
        bool isCube(int num);
        int nearestSquare(int num);
        int nearestCube(int num);
        std::string simplifyFraction(int numerator, int denominator);
        int findGCD(int a, int b);
        int propDivide(int number, int ratio);
        std::pair<int, int> ratioToFraction(double ratio);
        std::string decimalToFraction(double decimal);
        int fibonacciAtIndex(int index);
        int lucasNumberAtIndex(int index);
        int hailstoneNext(int number);
        int hailstoneSequenceLength(int number);
        bool isPowerOfTwo(int num);
        int nextPowerOfTwo(int num);
        int previousPowerOfTwo(int num);
        int countPrimeFactors(int number);
        int sumPrimeFactors(int num);
        int productOfDigits(int num);
        int lowestCommonAncestor(int num1, int num2);
        bool isDeficientNumber(int num);
        bool isPerfectNumber(int num);
        bool isAbundantNumber(int number);
        int digitAt(int number, int position);
        int setDigitAt(int num, int position, int digit);
        int mergeNumbers(int num1, int num2);
        std::pair<int, int> splitNumber(int number, int position);
        std::string numberToWords(int number);
        int generateRandom(int min, int max);
        int numUniqueDigits(int number);
        int shiftRight(int number, int shiftAmount);
        int toggleBit(int num, int bitPos);
        bool isBitSet(int num, int pos);
        int clearBit(int num, int pos);
        int setBit(int num, int pos);
        int lowBit(int num);
        int highBit(int num);
        bool isAnagramNumber(int num1, int num2);
        int countOccurrences(int number, int digit);
        int numCommonDigits(int num1, int num2);
        int rotateDigits(int number, int places);
        std::string trimNumber(std::string number);
        std::string expandNumber(int number, int digitValue);
        std::string compressNumber(int number, int length);
        int toggleParity(int num);
        int mirrorNumber(int number);
        bool isAscending(int number);
        bool isDescending(int number);
        int shuffleDigits(int number);
        int sortDigitsAsc(int number);
        int sortDigitsDesc(int number);
        bool isHarshadNumber(int number);
        double meanOfDigits(int num);
        std::map<int, int> digitFrequency(int num);
        int replaceDigit(int number, int digitToReplace, int replacementDigit);
        bool isAutomorphic(int num);
        std::string repeatNumber(int number, int times);
};
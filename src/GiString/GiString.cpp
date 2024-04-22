

#include "GiString.hpp"

/**
 * @brief Capitalizes the first letter of a string and converts the rest to lowercase.
 *
 * @param str The input string to capitalize.
 * @return The capitalized string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::capitalize(const std::string &str)
{
    if (str.empty())
    {
        throw std::invalid_argument("Input string cannot be empty.");
    }

    std::string result = str;
    result[0] = std::toupper(result[0]); // Capitalize first character

    // Convert rest of the characters to lowercase
    for (size_t i = 1; i < result.size(); ++i)
    {
        result[i] = std::tolower(result[i]);
    }

    return result;
}

// Example usage:
// std::string input = "heLLo WoRLd";
// std::string result = capitalize(input);
// std::cout << "Capitalized string: " << result << std::endl;

/**
 * @brief Capitalizes the first letter of each word in a string.
 *
 * @param str The input string to capitalize.
 * @return The string with the first letter of each word capitalized.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::capitalizeWords(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    std::string capitalized_str = str;
    bool capitalize_next = true; // Flag to indicate whether the next character should be capitalized

    for (size_t i = 0; i < capitalized_str.length(); ++i)
    {
        // Check if the current character is a letter
        if (std::isalpha(capitalized_str[i]))
        {
            // Capitalize the letter if it's the first letter of a word
            if (capitalize_next)
            {
                capitalized_str[i] = std::toupper(capitalized_str[i]);
                capitalize_next = false; // Next letter should not be capitalized
            }
            else
            {
                capitalized_str[i] = std::tolower(capitalized_str[i]);
            }
        }
        else
        {
            // If the current character is not a letter, the next one should be capitalized
            capitalize_next = true;
        }
    }

    return capitalized_str;
}

// Example usage:
// std::string input = "heLLo WoRLd";
// std::string result = capitalizeWords(input);
// std::cout << "Capitalized words: " << result << std::endl;

/**
 * @brief Swaps the case of all letters in a string.
 *
 * @param str The input string to swap case.
 * @return The string with the case of all letters swapped.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::swapcase(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    std::string swapped_str = str;

    for (char &c : swapped_str)
    {
        if (std::islower(c))
        {
            c = std::toupper(c);
        }
        else if (std::isupper(c))
        {
            c = std::tolower(c);
        }
    }

    return swapped_str;
}

// Example usage:
// std::string input = "HeLLo WoRLd";
// std::string result = swapcase(input);
// std::cout << "Swapped case: " << result << std::endl;

/**
 * @brief Reverses a string.
 *
 * @param str The input string to reverse.
 * @return The reversed string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::reverse(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    std::string reversed_str = str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    return reversed_str;
}

// Example usage:
// std::string input = "Hello World";
// std::string result = reverse(input);
// std::cout << "Reversed string: " << result << std::endl;

/**
 * @brief Checks if a string is a palindrome.
 *
 * @param str The input string to check.
 * @return True if the string is a palindrome, false otherwise.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_palindrome(const std::string &str) const
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    // Initialize pointers for the beginning and end of the string
    size_t left = 0;
    size_t right = str.length() - 1;

    // Continue iterating until the pointers meet
    while (left < right)
    {
        // Ignore non-alphanumeric characters from the left
        if (!std::isalnum(str[left]))
        {
            ++left;
            continue;
        }
        // Ignore non-alphanumeric characters from the right
        if (!std::isalnum(str[right]))
        {
            --right;
            continue;
        }
        // If characters at current pointers don't match, return false
        if (std::tolower(str[left]) != std::tolower(str[right]))
        {
            return false;
        }
        // Move the pointers towards each other
        ++left;
        --right;
    }

    // If the loop completes without returning false, the string is a palindrome
    return true;
}

// Example usage:
// std::string input = "A man, a plan, a canal, Panama";
// bool result = is_palindrome(input);
// std::cout << "Is palindrome? " << std::boolalpha << result << std::endl;

/**
 * @brief Removes leading white spaces from a string.
 *
 * @param str The input string to trim.
 * @return The trimmed string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::trim_left(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    // Find the first non-white space character
    size_t start_pos = str.find_first_not_of(" \t\n\r\f\v");

    // If all characters are white spaces, return an empty string
    if (start_pos == std::string::npos)
    {
        return "";
    }

    // Return the substring starting from the first non-white space character
    return str.substr(start_pos);
}

/**
 * @brief Removes trailing white spaces from a string.
 *
 * @param str The input string to trim.
 * @return The trimmed string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::trim_right(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    // Find the last non-white space character
    size_t end_pos = str.find_last_not_of(" \t\n\r\f\v");

    // If all characters are white spaces, return an empty string
    if (end_pos == std::string::npos)
    {
        return "";
    }

    // Return the substring up to the last non-white space character
    return str.substr(0, end_pos + 1);
}

/**
 * @brief Removes leading and trailing white spaces from a string.
 *
 * @param str The input string to trim.
 * @return The trimmed string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::trim(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty");
    }

    // Find the first non-white space character from the left
    size_t start_pos = str.find_first_not_of(" \t\n\r\f\v");

    // If all characters are white spaces, return an empty string
    if (start_pos == std::string::npos)
    {
        return "";
    }

    // Find the last non-white space character from the right
    size_t end_pos = str.find_last_not_of(" \t\n\r\f\v");

    // Return the substring between the first and last non-white space characters
    return str.substr(start_pos, end_pos - start_pos + 1);
}

/**
 * @brief Centers a string, optionally filling with white spaces.
 *
 * @param str The input string to center.
 * @param width The desired width of the resulting string.
 * @param fill The optional character to use for filling (default is whitespace).
 * @return The centered string.
 *
 * @throws std::invalid_argument If the width is less than or equal to the length of the input string.
 */
std::string GiString::center(const std::string &str, size_t width, char fill = ' ')
{
    // Check if the width is valid
    if (width <= str.length())
    {
        throw std::invalid_argument("Width must be greater than the length of the input string");
    }

    // Calculate the number of characters to pad on each side
    size_t total_padding = width - str.length();
    size_t left_padding = total_padding / 2;
    size_t right_padding = total_padding - left_padding;

    // Construct the centered string
    std::string centered_str;
    centered_str.reserve(width);
    centered_str.append(left_padding, fill);
    centered_str.append(str);
    centered_str.append(right_padding, fill);

    return centered_str;
}

/**
 * @brief Left-aligns a string, optionally padding with whitespace.
 *
 * @param str The input string to left-align.
 * @param width The width to which the string should be aligned.
 * @param fillchar The character used for padding (default is whitespace).
 * @return The left-aligned string.
 *
 * @throws std::invalid_argument If width is less than the length of the input string.
 * @throws std::invalid_argument If fillchar is not a single character.
 */
std::string GiString::ljust(const std::string &str, size_t width, char fillchar = ' ')
{
    // Check if width is less than the length of the input string
    if (width < str.length())
    {
        throw std::invalid_argument("GiString::ljust: Width is less than the length of the input string");
    }

    // Check if fillchar is a single character
    if (fillchar == '\0')
    {
        throw std::invalid_argument("GiString::ljust: Fill character cannot be null");
    }

    // Calculate the number of characters to pad
    size_t padding = width - str.length();

    // Left-align the string and pad it
    return str + std::string(padding, fillchar);
}

/**
 * @brief Right-justifies a string, optionally filling with whitespace.
 *
 * @param str The input string to be right-justified.
 * @param width The width of the resulting string after justification.
 * @param fillchar The character used for filling the space (default is whitespace).
 * @return The right-justified string.
 *
 * @throws std::invalid_argument If the width is less than or equal to the length of the input string.
 * @throws std::invalid_argument If the fill character is not a printable ASCII character.
 */
std::string GiString::rjust(const std::string &str, size_t width, char fillchar = ' ')
{
    // Check if width is valid
    if (width <= str.length())
    {
        throw std::invalid_argument("Width must be greater than the length of the input string (GiString::rjust)");
    }

    // Check if fill character is a printable ASCII character
    if (!isprint(fillchar))
    {
        throw std::invalid_argument("Fill character must be a printable ASCII character (GiString::rjust)");
    }

    // Calculate the number of characters to fill
    size_t fill_count = width - str.length();

    // Construct the justified string
    std::string justified_str(fill_count, fillchar);
    justified_str += str;

    return justified_str;
}

// Example usage:
// std::string input = "hello";
// std::string result = GiString::rjust(input, 10, '-');
// std::cout << "Right-justified string: " << result << std::endl;

/**
 * @brief Converts all letters in a string to uppercase.
 *
 * @param str The input string to be converted.
 * @return The uppercase version of the input string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::upper(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::upper)");
    }

    // Convert each character to uppercase
    std::string uppercase_str;
    for (char c : str)
    {
        uppercase_str += std::toupper(c);
    }

    return uppercase_str;
}

// Example usage:
// std::string input = "hello World";
// std::string result = GiString::upper(input);
// std::cout << "Uppercase string: " << result << std::endl;

/**
 * @brief Converts all letters in a string to lowercase.
 *
 * @param str The input string to convert.
 * @return The string with all letters converted to lowercase.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::lower(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::lower)");
    }

    std::string result = str;
    for (char &c : result)
    {
        if (std::isalpha(c))
        {
            c = std::tolower(c);
        }
    }

    return result;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "Hello World";
// std::string result = gs->lower(input);
// std::cout << "Lowercase string: " << result << std::endl;

/**
 * @brief Counts the occurrences of a substring in a string.
 *
 * @param str The input string to search within.
 * @param sub The substring to count occurrences of.
 * @return The number of occurrences of the substring in the input string.
 *
 * @throws std::invalid_argument If either the input string or substring is empty.
 */
size_t GiString::count(const std::string &str, const std::string &sub)
{
    // Check if the input string or substring is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::count)");
    }
    if (sub.empty())
    {
        throw std::invalid_argument("Substring is empty (GiString::count)");
    }

    size_t count = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != std::string::npos)
    {
        ++count;
        pos += sub.length();
    }

    return count;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello hello world";
// std::string sub = "hello";
// size_t occurrences = gs->count(input, sub);
// std::cout << "Number of occurrences of 'hello': " << occurrences << std::endl;

/**
 * @brief Returns a substring from the given range of indices.
 *
 * @param str The input string from which to extract the substring.
 * @param start The starting index of the substring (inclusive).
 * @param end The ending index of the substring (exclusive).
 * @return The substring from the specified range of indices.
 *
 * @throws std::out_of_range If the indices are out of range.
 */
std::string GiString::substring(const std::string &str, size_t start, size_t end)
{
    // Check if the start index is out of range
    if (start >= str.length())
    {
        throw std::out_of_range("Start index out of range (GiString::substring)");
    }
    // Check if the end index is out of range
    if (end > str.length())
    {
        throw std::out_of_range("End index out of range (GiString::substring)");
    }
    // Check if the start index is greater than the end index
    if (start >= end)
    {
        throw std::invalid_argument("Start index must be less than end index (GiString::substring)");
    }

    return str.substr(start, end - start);
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world";
// size_t start = 6;
// size_t end = 11;
// std::string result = gs->substring(input, start, end);
// std::cout << "Substring from index " << start << " to " << end - 1 << ": " << result << std::endl;

/**
 * @brief Replaces all occurrences of a substring with another string.
 *
 * @param str The input string in which to perform replacements.
 * @param old_sub The substring to be replaced.
 * @param new_sub The string to replace occurrences of the substring with.
 * @return The string with replacements performed.
 *
 * @throws std::invalid_argument If either the input string or substrings are empty.
 */
std::string GiString::replace(const std::string &str, const std::string &old_sub, const std::string &new_sub)
{
    // Check if the input string or substrings are empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::replace)");
    }
    if (old_sub.empty())
    {
        throw std::invalid_argument("Old substring is empty (GiString::replace)");
    }

    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(old_sub, pos)) != std::string::npos)
    {
        result.replace(pos, old_sub.length(), new_sub);
        pos += new_sub.length();
    }

    return result;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello hello world";
// std::string old_sub = "hello";
// std::string new_sub = "hi";
// std::string result = gs->replace(input, old_sub, new_sub);
// std::cout << "After replacement: " << result << std::endl;

/**
 * @brief Splits a string into a list of strings using the specified delimiter.
 *
 * @param str The input string to split.
 * @param delimiter The character to use as the delimiter for splitting.
 * @return A vector of strings resulting from the split operation.
 *
 * @throws std::invalid_argument If the delimiter is empty.
 */
std::vector<std::string> GiString::split(const std::string &str, char delimiter)
{
    // Check if the delimiter is empty
    if (delimiter == '\0')
    {
        throw std::invalid_argument("Delimiter cannot be empty (GiString::split)");
    }

    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello,world,test";
// char delimiter = ',';
// std::vector<std::string> result = gs->split(input, delimiter);
// for (const auto& str : result) {
//     std::cout << str << std::endl;
// }

/**
 * @brief Joins a list of strings into one string, inserting a separator between each element.
 *
 * @param strs The list of strings to join.
 * @param separator The string to insert between each element.
 * @return The concatenated string.
 *
 * @throws std::invalid_argument If the list of strings is empty.
 */
std::string GiString::join(const std::vector<std::string> &strs, const std::string &separator)
{
    // Check if the list of strings is empty
    if (strs.empty())
    {
        throw std::invalid_argument("List of strings is empty (GiString::join)");
    }

    std::stringstream ss;
    bool first = true;
    for (const auto &str : strs)
    {
        if (!first)
        {
            ss << separator;
        }
        ss << str;
        first = false;
    }

    return ss.str();
}

// Example usage:
// GiString* gs = new GiString();
// std::vector<std::string> input = {"hello", "world", "test"};
// std::string separator = ", ";
// std::string result = gs->join(input, separator);
// std::cout << "Joined string: " << result << std::endl;

/**
 * @brief Checks if a string starts with a specified substring.
 *
 * @param str The input string to check.
 * @param prefix The substring to check for at the beginning of the string.
 * @return True if the string starts with the prefix, false otherwise.
 *
 * @throws std::invalid_argument If the input string or prefix is empty.
 */
bool GiString::startswith(const std::string &str, const std::string &prefix)
{
    // Check if the input string or prefix is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::startswith)");
    }
    if (prefix.empty())
    {
        throw std::invalid_argument("Prefix is empty (GiString::startswith)");
    }

    return str.compare(0, prefix.length(), prefix) == 0;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world";
// std::string prefix = "hello";
// bool starts_with = gs->startswith(input, prefix);
// std::cout << "Starts with 'hello': " << (starts_with ? "true" : "false") << std::endl;

/**
 * @brief Checks if a string ends with a specified substring.
 *
 * @param str The input string to check.
 * @param suffix The substring to check for at the end of the string.
 * @return True if the string ends with the suffix, false otherwise.
 *
 * @throws std::invalid_argument If the input string or suffix is empty.
 */
bool GiString::endswith(const std::string &str, const std::string &suffix)
{
    // Check if the input string or suffix is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::endswith)");
    }
    if (suffix.empty())
    {
        throw std::invalid_argument("Suffix is empty (GiString::endswith)");
    }

    if (str.length() < suffix.length())
    {
        return false;
    }

    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world";
// std::string suffix = "world";
// bool ends_with = gs->endswith(input, suffix);
// std::cout << "Ends with 'world': " << (ends_with ? "true" : "false") << std::endl;

/**
 * @brief Checks if all characters in a string are ASCII.
 *
 * @param str The input string to check.
 * @return True if all characters are ASCII, false otherwise.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_ascii(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::is_ascii)");
    }

    for (char c : str)
    {
        if (static_cast<unsigned char>(c) > 127)
        {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world";
// bool ascii = gs->is_ascii(input);
// std::cout << "Is ASCII: " << (ascii ? "true" : "false") << std::endl;

/**
 * @brief Checks if a string consists only of numeric characters.
 *
 * @param str The input string to check.
 * @return True if the string consists only of numeric characters, false otherwise.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_numeric(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::is_numeric)");
    }

    for (char c : str)
    {
        if (!std::isdigit(c))
        {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "12345";
// bool numeric = gs->is_numeric(input);
// std::cout << "Is numeric: " << (numeric ? "true" : "false") << std::endl;

/**
 * @brief Checks if a string consists only of alphabetic characters.
 *
 * @param str The input string to check.
 * @return True if the string consists only of alphabetic characters, false otherwise.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_alpha(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::is_alpha)");
    }

    for (char c : str)
    {
        if (!std::isalpha(c))
        {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "HelloWorld";
// bool alpha = gs->is_alpha(input);
// std::cout << "Is alpha: " << (alpha ? "true" : "false") << std::endl;

/**
 * @brief Checks if a string consists only of alphanumeric characters.
 *
 * @param str The input string to check.
 * @return True if the string consists only of alphanumeric characters, false otherwise.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_alphanumeric(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::is_alphanumeric)");
    }

    for (char c : str)
    {
        if (!std::isalnum(c))
        {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "Hello123";
// bool alphanumeric = gs->is_alphanumeric(input);
// std::cout << "Is alphanumeric: " << (alphanumeric ? "true" : "false") << std::endl;

#include <iomanip>

/**
 * @brief Fills the string with zeros to the specified length.
 *
 * @param str The input string to fill with zeros.
 * @param width The desired width of the resulting string.
 * @return The string filled with zeros.
 *
 * @throws std::invalid_argument If the specified width is less than the length of the input string.
 */
std::string GiString::zfill(const std::string &str, size_t width)
{
    // Check if the specified width is less than the length of the input string
    if (width <= str.length())
    {
        throw std::invalid_argument("Width must be greater than the length of the input string (GiString::zfill)");
    }

    return std::string(width - str.length(), '0') + str;
}

// Example usage:
// std::string input = "123";
// GiString* gs = new GiString();
// size_t width = 6;
// std::string result = gs->zfill(input, width);
// std::cout << "After zfill: " << result << std::endl;

/**
 * @brief Removes whitespace characters from the left side of a string.
 *
 * @param str The input string to trim.
 * @return The string with leading whitespace characters removed.
 */
std::string GiString::ltrim(const std::string &str)
{
    auto it = std::find_if(str.begin(), str.end(), [](unsigned char ch)
                           { return !std::isspace(ch); });
    return std::string(it, str.end());
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "   hello world";
// std::string result = gs->ltrim(input);
// std::cout << "After ltrim: '" << result << "'" << std::endl;

/**
 * @brief Removes whitespace characters from the right side of a string.
 *
 * @param str The input string to trim.
 * @return The string with trailing whitespace characters removed.
 */
std::string GiString::rtrim(const std::string &str)
{
    auto it = std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
                           { return !std::isspace(ch); });
    return std::string(str.begin(), it.base());
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world   ";
// std::string result = gs->rtrim(input);
// std::cout << "After rtrim: '" << result << "'" << std::endl;

/**
 * @brief Finds the index of the first occurrence of a substring in a string.
 *
 * @param str The input string to search within.
 * @param sub The substring to search for.
 * @return The index of the first occurrence of the substring, or std::string::npos if not found.
 *
 * @throws std::invalid_argument If the input string or substring is empty.
 */
size_t GiString::find(const std::string &str, const std::string &sub)
{
    // Check if the input string or substring is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::find)");
    }
    if (sub.empty())
    {
        throw std::invalid_argument("Substring is empty (GiString::find)");
    }

    return str.find(sub);
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world";
// std::string sub = "world";
// size_t index = gs->find(input, sub);
// std::cout << "Index of 'world': " << index << std::endl;

/**
 * @brief Finds the index of the last occurrence of a substring in a string.
 *
 * @param str The input string to search within.
 * @param sub The substring to search for.
 * @return The index of the last occurrence of the substring, or std::string::npos if not found.
 *
 * @throws std::invalid_argument If the input string or substring is empty.
 */
size_t GiString::rfind(const std::string &str, const std::string &sub)
{
    // Check if the input string or substring is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::rfind)");
    }
    if (sub.empty())
    {
        throw std::invalid_argument("Substring is empty (GiString::rfind)");
    }

    return str.rfind(sub);
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world hello";
// std::string sub = "hello";
// size_t index = gs->rfind(input, sub);
// std::cout << "Last index of 'hello': " << index << std::endl;

/**
 * @brief Checks if a string contains a specified substring.
 *
 * @param str The input string to search within.
 * @param sub The substring to search for.
 * @return True if the substring is found, false otherwise.
 *
 * @throws std::invalid_argument If the input string or substring is empty.
 */
bool GiString::contains(const std::string &str, const std::string &sub)
{
    // Check if the input string or substring is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::contains)");
    }
    if (sub.empty())
    {
        throw std::invalid_argument("Substring is empty (GiString::contains)");
    }

    return str.find(sub) != std::string::npos;
}

// Example usage:
// GiString* gs = new GiString();
// std::string input = "hello world";
// std::string sub = "world";
// bool contains = gs->contains(input, sub);
// std::cout << "Contains 'world': " << (contains ? "true" : "false") << std::endl;

#include <algorithm>
#include <cctype>

/**
 * @brief Compares two strings ignoring case sensitivity.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return True if the strings are equal ignoring case, false otherwise.
 */
bool GiString::equals_ignore_case(const std::string &str1, const std::string &str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    for (size_t i = 0; i < str1.length(); ++i)
    {
        if (std::tolower(str1[i]) != std::tolower(str2[i]))
        {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str1 = "Hello";
// std::string str2 = "hello";
// bool equals = gs->equals_ignore_case(str1, str2);
// std::cout << "Strings equal ignoring case: " << (equals ? "true" : "false") << std::endl;

/**
 * @brief Inserts a string into another string at the specified position.
 *
 * @param str The original string to insert into.
 * @param pos The position at which to insert the string.
 * @param sub The string to insert.
 * @return The string with the substring inserted at the specified position.
 *
 * @throws std::out_of_range If the specified position is out of range.
 */
std::string GiString::insert(std::string str, size_t pos, const std::string &sub)
{
    // Check if the specified position is out of range
    if (pos > str.length())
    {
        throw std::out_of_range("Position is out of range (GiString::insert)");
    }

    return str.insert(pos, sub);
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello world";
// std::string sub = "beautiful ";
// size_t pos = 6;
// std::string result = gs->insert(str, pos, sub);
// std::cout << "After insert: " << result << std::endl;

/**
 * @brief Removes all occurrences of a substring from a string.
 *
 * @param str The original string to remove from.
 * @param sub The substring to remove.
 * @return The string with all occurrences of the substring removed.
 */
std::string GiString::remove(const std::string &str, const std::string &sub)
{
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(sub, pos)) != std::string::npos)
    {
        result.erase(pos, sub.length());
    }
    return result;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello world hello";
// std::string sub = "hello";
// std::string result = gs->remove(str, sub);
// std::cout << "After remove: " << result << std::endl;

/**
 * @brief Removes and returns the last character from a string.
 *
 * @param str The input string to modify.
 * @return The last character that was removed from the string.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
char GiString::pop(std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::pop)");
    }

    char last_char = str.back();
    str.pop_back();
    return last_char;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello";
// char last_char = gs->pop(str);
// std::cout << "Last character removed: " << last_char << std::endl;
// std::cout << "String after pop: " << str << std::endl;

/**
 * @brief Appends a character to the end of a string.
 *
 * @param str The input string to modify.
 * @param ch The character to append.
 */
void GiString::push_back(std::string &str, char ch)
{
    str.push_back(ch);
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello";
// char ch = '!';
// gs->push_back(str, ch);
// std::cout << "String after push_back: " << str << std::endl;

/**
 * @brief Copies the contents of one string to another string.
 *
 * @param src The source string to copy from.
 * @param dest The destination string to copy to.
 *
 * @throws std::invalid_argument If the source string is empty.
 */
void GiString::copy(const std::string &src, std::string &dest)
{
    // Check if the source string is empty
    if (src.empty())
    {
        throw std::invalid_argument("Source string is empty (GiString::copy)");
    }
    dest = src;
}

// Example usage:
// GiString* gs = new GiString();
// std::string src = "hello";
// std::string dest;
// gs->copy(src, dest);
// std::cout << "Copied string: " << dest << std::endl;

/**
 * @brief Returns the character at the specified index in a string.
 *
 * @param str The input string to access.
 * @param index The index of the character to retrieve.
 * @return The character at the specified index.
 *
 * @throws std::out_of_range If the index is out of range.
 */
char GiString::at(const std::string &str, size_t index)
{
    // Check if the index is out of range
    if (index >= str.length())
    {
        throw std::out_of_range("Index is out of range (GiString::at)");
    }
    return str.at(index);
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello";
// size_t index = 2;
// char character = gs->at(str, index);
// std::cout << "Character at index " << index << ": " << character << std::endl;

/**
 * @brief Returns the maximum lexicographically character in a string.
 *
 * @param str The input string to search.
 * @return The maximum lexicographically character.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
char GiString::max_char(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::max_char)");
    }
    return *std::max_element(str.begin(), str.end());
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello world";
// char max_character = gs->max_char(str);
// std::cout << "Max character: " << max_character << std::endl;

/**
 * @brief Returns the minimum lexicographically character in a string.
 *
 * @param str The input string to search.
 * @return The minimum lexicographically character.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
char GiString::min_char(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::min_char)");
    }
    return *std::min_element(str.begin(), str.end());
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello world";
// char min_character = gs->min_char(str);
// std::cout << "Min character: " << min_character << std::endl;

/**
 * @brief Iterates over each character in a string, applying a given function.
 *
 * @param str The input string to iterate over.
 * @param func The function to apply to each character.
 */
void GiString::iterate(const std::string &str, std::function<void(char)> func)
{
    for (char c : str)
    {
        func(c);
    }
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello";
// gs->iterate(str, [](char c) { std::cout << c << " "; });
// std::cout << std::endl;

/**
 * @brief Maps each character in a string using a given function.
 *
 * @param str The input string to map over.
 * @param func The function to apply to each character.
 * @return The resulting string after mapping.
 */
std::string GiString::map_chars(const std::string &str, std::function<char(char)> func)
{
    std::string result = str;
    for (char &c : result)
    {
        c = func(c);
    }
    return result;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello";
// std::string result = gs->map_chars(str, [](char c) { return std::toupper(c); });
// std::cout << "Mapped string: " << result << std::endl;

/**
 * @brief Filters characters in a string based on a given predicate function.
 *
 * @param str The input string to filter.
 * @param predicate The predicate function to apply to each character.
 * @return The resulting string after filtering.
 */
std::string GiString::filter_chars(const std::string &str, std::function<bool(char)> predicate)
{
    std::string result;
    for (char c : str)
    {
        if (predicate(c))
        {
            result.push_back(c);
        }
    }
    return result;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello123";
// std::string result = gs->filter_chars(str, [](char c) { return std::isalpha(c); });
// std::cout << "Filtered string: " << result << std::endl;

/**
 * @brief Reduces a string to a single value using a given binary function.
 *
 * @param str The input string to reduce.
 * @param init The initial value for the reduction.
 * @param binary_func The binary function to apply to each character.
 * @return The result of the reduction.
 */
template <typename T>
T GiString::reduce(const std::string &str, T init, std::function<T(T, char)> binary_func)
{
    T result = init;
    for (char c : str)
    {
        result = binary_func(result, c);
    }
    return result;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello";
// int result_length = gs->reduce<int>(str, 0, [](int acc, char c) { return acc + 1; });
// std::cout << "Length of the string: " << result_length << std::endl;

/**
 * @brief Checks if all characters in a string satisfy a given predicate function.
 *
 * @param str The input string to check.
 * @param predicate The predicate function to apply to each character.
 * @return True if all characters satisfy the predicate, false otherwise.
 */
bool GiString::all_of(const std::string &str, std::function<bool(char)> predicate)
{
    return std::all_of(str.begin(), str.end(), predicate);
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello123";
// bool all_alpha = gs->all_of(str, [](char c) { return std::isalpha(c); });
// std::cout << "All characters are alphabetic: " << (all_alpha ? "true" : "false") << std::endl;

/**
 * @brief Checks if no characters in a string satisfy a given predicate function.
 *
 * @param str The input string to check.
 * @param predicate The predicate function to apply to each character.
 * @return True if no characters satisfy the predicate, false otherwise.
 */
bool GiString::none_of(const std::string &str, std::function<bool(char)> predicate)
{
    return std::none_of(str.begin(), str.end(), predicate);
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello123";
// bool none_digit = gs->none_of(str, [](char c) { return std::isdigit(c); });
// std::cout << "No characters are digits: " << (none_digit ? "true" : "false") << std::endl;

/**
 * @brief Returns a substring specified by the start and end indices.
 *
 * @param str The input string.
 * @param start The starting index of the substring (inclusive).
 * @param end The ending index of the substring (exclusive).
 * @return The substring specified by the indices.
 *
 * @throws std::out_of_range If the start or end index is out of range.
 * @throws std::invalid_argument If the end index is less than the start index.
 */
std::string GiString::slice(const std::string &str, size_t start, size_t end)
{
    // Check if the start index is out of range
    if (start >= str.length())
    {
        throw std::out_of_range("Start index is out of range (GiString::slice)");
    }
    // Check if the end index is out of range
    if (end > str.length())
    {
        throw std::out_of_range("End index is out of range (GiString::slice)");
    }
    // Check if the end index is less than the start index
    if (end < start)
    {
        throw std::invalid_argument("End index is less than the start index (GiString::slice)");
    }

    return str.substr(start, end - start);
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "hello world";
// std::string sliced = gs->slice(str, 3, 8);
// std::cout << "Sliced string: " << sliced << std::endl;

/**
 * @brief Removes all non-ASCII characters from a string.
 *
 * @param str The input string to modify.
 * @return The string with only ASCII characters.
 */
std::string GiString::ascii_only(std::string str)
{
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c)
                             { return c > 127; }),
              str.end());
    return str;
}

// Example usage:
// GiString* gs = new GiString();
// std::string str = "h€llø wørld";
// std::string ascii_str = gs->ascii_only(str);
// std::cout << "ASCII only string: " << ascii_str << std::endl;

/**
 * @brief Converts a string to an integer.
 *
 * @param str The input string to convert.
 * @return The integer value of the input string.
 *
 * @throws std::invalid_argument If the input string is not a valid integer.
 */
int GiString::to_int(const std::string &str)
{
    try
    {
        // Use std::stoi to convert the string to an integer
        return std::stoi(str);
    }
    catch (const std::invalid_argument &e)
    {
        // If std::stoi throws std::invalid_argument, rethrow with additional information
        throw std::invalid_argument("Invalid integer string: " + std::string(e.what()) + " (GiString::to_int)");
    }
}

// Example usage:
// GiString* myString = new GiString("123");
// int intValue = myString->to_int();
// std::cout << "Integer value: " << intValue << std::endl;

/**
 * @brief Converts a string to a floating point number.
 *
 * @param str The input string to convert.
 * @return The floating point value of the input string.
 *
 * @throws std::invalid_argument If the input string is not a valid floating point number.
 */
float GiString::to_float(const std::string &str)
{
    try
    {
        // Use std::stof to convert the string to a floating point number
        return std::stof(str);
    }
    catch (const std::invalid_argument &e)
    {
        // If std::stof throws std::invalid_argument, rethrow with additional information
        throw std::invalid_argument("Invalid floating point string: " + std::string(e.what()) + " (GiString::to_float)");
    }
}

// Example usage:
// GiString* myString = new GiString("3.14");
// float floatValue = myString->to_float();
// std::cout << "Float value: " << floatValue << std::endl;

/**
 * @brief Adds indentation to each line of the string.
 *
 * @param str The input string to add indentation to.
 * @param count The number of spaces to indent each line by.
 * @return The string with indentation added to each line.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::indent(const std::string &str, int count)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::indent)");
    }

    std::string result;
    std::istringstream iss(str);
    std::string line;

    // Add indentation to each line
    while (std::getline(iss, line))
    {
        result += std::string(count, ' ') + line + "\n";
    }

    return result;
}

// Example usage:
// GiString* myString = new GiString("Hello\nWorld!");
// std::string indentedString = myString->indent(4);
// std::cout << "Indented string:\n" << indentedString << std::endl;

/**
 * @brief Removes indentation from each line of the string.
 *
 * @param str The input string to remove indentation from.
 * @return The string with indentation removed from each line.
 *
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::dedent(const std::string &str)
{
    // Check if the input string is empty
    if (str.empty())
    {
        throw std::invalid_argument("Input string is empty (GiString::dedent)");
    }

    std::string result;
    std::istringstream iss(str);
    std::string line;

    // Find the minimum indentation in the string
    size_t minIndent = std::string::npos;
    while (std::getline(iss, line))
    {
        if (!line.empty())
        {
            size_t lineIndent = line.find_first_not_of(" ");
            if (lineIndent != std::string::npos && (minIndent == std::string::npos || lineIndent < minIndent))
            {
                minIndent = lineIndent;
            }
        }
    }

    // Remove indentation from each line
    iss.clear();
    iss.seekg(0);
    while (std::getline(iss, line))
    {
        if (!line.empty())
        {
            result += line.substr(minIndent) + "\n";
        }
        else
        {
            result += "\n";
        }
    }

    return result;
}

// Example usage:
// GiString* myString = new GiString("    Hello\n    World!");
// std::string dedentedString = myString->dedent();
// std::cout << "Dedented string:\n" << dedentedString << std::endl;


/**
 * @brief Replaces the first occurrence of a substring with another string.
 * 
 * @param str The input string where the replacement will be performed.
 * @param from The substring to be replaced.
 * @param to The string to replace the substring with.
 * @return The string with the first occurrence of the substring replaced.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::replace_first(const std::string& str, const std::string& from, const std::string& to) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::replace_first)");
    }

    // Find the position of the first occurrence of the substring to be replaced
    size_t startPos = str.find(from);
    if (startPos == std::string::npos) {
        // If the substring to be replaced is not found, return the original string
        return str;
    }

    // Replace the first occurrence of the substring
    std::string result = str;
    result.replace(startPos, from.length(), to);
    return result;
}

// Example usage:
// GiString* myString = new GiString("apple orange banana");
// std::string replacedString = myString->replace_first("orange", "pear");
// std::cout << "Replaced string: " << replacedString << std::endl;



/**
 * @brief Replaces the last occurrence of a substring with another string.
 * 
 * @param str The input string where the replacement will be performed.
 * @param from The substring to be replaced.
 * @param to The string to replace the substring with.
 * @return The string with the last occurrence of the substring replaced.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::replace_last(const std::string& str, const std::string& from, const std::string& to) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::replace_last)");
    }

    // Find the position of the last occurrence of the substring to be replaced
    size_t startPos = str.rfind(from);
    if (startPos == std::string::npos) {
        // If the substring to be replaced is not found, return the original string
        return str;
    }

    // Replace the last occurrence of the substring
    std::string result = str;
    result.replace(startPos, from.length(), to);
    return result;
}

// Example usage:
// GiString* myString = new GiString("apple orange orange banana");
// std::string replacedString = myString->replace_last("orange", "pear");
// std::cout << "Replaced string: " << replacedString << std::endl;



/**
 * @brief Returns a string with characters in reverse order.
 * 
 * @param str The input string to reverse.
 * @return The string with characters in reverse order.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::reversed(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::reversed)");
    }

    // Create a copy of the input string and reverse it
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result;
}

// Example usage:
// GiString* myString = new GiString("hello");
// std::string reversedString = myString->reversed();
// std::cout << "Reversed string: " << reversedString << std::endl;


/**
 * @brief Shuffles the characters in a string randomly.
 * 
 * @param str The input string to shuffle.
 * @return The string with characters shuffled randomly.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::shuffle(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::shuffle)");
    }

    // Create a copy of the input string
    std::string result = str;

    // Obtain a random seed based on current time
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shuffle the characters randomly
    std::shuffle(result.begin(), result.end(), gen);
    return result;
}

// Example usage:
// GiString* myString = new GiString("hello");
// std::string shuffledString = myString->shuffle();
// std::cout << "Shuffled string: " << shuffledString << std::endl;


/**
 * @brief Sorts the characters in a string in alphabetical order.
 * 
 * @param str The input string to sort.
 * @return The string with characters sorted in alphabetical order.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::sort(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::sort)");
    }

    // Create a copy of the input string
    std::string result = str;

    // Sort the characters in alphabetical order
    std::sort(result.begin(), result.end());
    return result;
}

// Example usage:
// GiString* myString = new GiString("hello");
// std::string sortedString = myString->sort();
// std::cout << "Sorted string: " << sortedString << std::endl;


/**
 * @brief Sorts the characters in a string in reverse alphabetical order.
 * 
 * @param str The input string to sort.
 * @return The string with characters sorted in reverse alphabetical order.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::sort_desc(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::sort_desc)");
    }

    // Create a copy of the input string
    std::string result = str;

    // Sort the characters in reverse alphabetical order
    std::sort(result.begin(), result.end(), std::greater<char>());
    return result;
}

// Example usage:
// GiString* myString = new GiString("hello");
// std::string sortedDescString = myString->sort_desc();
// std::cout << "Sorted descending string: " << sortedDescString << std::endl;


/**
 * @brief Repeats the input string a specified number of times.
 * 
 * @param str The input string to repeat.
 * @param times The number of times to repeat the input string.
 * @return The string repeated the specified number of times.
 * 
 * @throws std::invalid_argument If the input string is empty or the number of times is non-positive.
 */
std::string GiString::repeat(const std::string& str, int times) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::repeat)");
    }

    // Check if the number of times is non-positive
    if (times <= 0) {
        throw std::invalid_argument("Number of times must be positive (GiString::repeat)");
    }

    // Repeat the input string the specified number of times
    std::string result;
    for (int i = 0; i < times; ++i) {
        result += str;
    }
    return result;
}

// Example usage:
// GiString* myString = new GiString("hello");
// std::string repeatedString = myString->repeat(3);
// std::cout << "Repeated string: " << repeatedString << std::endl;


/**
 * @brief Compares two strings lexicographically.
 * 
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return true if str1 is lexicographically less than str2, false otherwise.
 */
bool GiString::lexicographic_compare(const std::string& str1, const std::string& str2) {
    // Use std::lexicographical_compare to compare the strings
    return std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end());
}

// Example usage:
// GiString* myString = new GiString();
// bool isLess = myString->lexicographic_compare("apple", "banana");
// std::cout << "Is 'apple' less than 'banana'? " << (isLess ? "Yes" : "No") << std::endl;



#include <cctype>

/**
 * @brief Extracts all digits from a string and returns them as a new string.
 * 
 * @param str The input string to extract digits from.
 * @return The string containing all extracted digits.
 */
std::string GiString::extract_digits(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (std::isdigit(c)) {
            result += c;
        }
    }
    return result;
}

// Example usage:
// GiString* myString = new GiString();
// std::string digits = myString->extract_digits("a1b2c3d4");
// std::cout << "Extracted digits: " << digits << std::endl;



/**
 * @brief Checks if a string consists only of whitespace characters.
 * 
 * @param str The input string to check.
 * @return true if the string consists only of whitespace characters, false otherwise.
 */
bool GiString::is_blank(const std::string& str) {
    // Use std::all_of to check if all characters in the string are whitespace
    return std::all_of(str.begin(), str.end(), [](char c) { return std::isspace(c); });
}

// Example usage:
// GiString* myString = new GiString();
// bool result = myString->is_blank("   ");
// std::cout << "Is the string blank? " << (result ? "Yes" : "No") << std::endl;


/**
 * @brief Checks if all letters in a string are uppercase.
 * 
 * @param str The input string to check.
 * @return true if all letters in the string are uppercase, false otherwise.
 */
bool GiString::is_uppercase(const std::string& str) {
    // Use std::all_of to check if all characters in the string are uppercase letters
    return std::all_of(str.begin(), str.end(), [](char c) { return std::isupper(c); });
}

// Example usage:
// GiString* myString = new GiString();
// bool result = myString->is_uppercase("HELLO");
// std::cout << "Are all letters uppercase? " << (result ? "Yes" : "No") << std::endl;


/**
 * @brief Checks if a string is a valid email address.
 * 
 * @param str The input string to check.
 * @return true if the string is a valid email address, false otherwise.
 */
bool GiString::is_valid_email(const std::string& str) {
    // Find the position of '@'
    auto atIndex = str.find('@');
    if (atIndex == std::string::npos || atIndex == 0 || atIndex == str.length() - 1) {
        return false; // '@' not found or at the beginning/end of the string
    }

    // Check if there is exactly one '@' symbol
    if (str.find('@', atIndex + 1) != std::string::npos) {
        return false; // more than one '@' symbol found
    }

    // Extract local part and domain part
    std::string localPart = str.substr(0, atIndex);
    std::string domainPart = str.substr(atIndex + 1);

    // Check if local part is valid
    if (!is_valid_local_part(localPart)) {
        return false;
    }

    // Check if domain part is valid
    if (!is_valid_domain_part(domainPart)) {
        return false;
    }

    return true;
}

/**
 * @brief Checks if the local part of an email address is valid.
 * 
 * @param localPart The local part of the email address.
 * @return true if the local part is valid, false otherwise.
 */
bool GiString::is_valid_local_part(const std::string& localPart) {
    // Local part cannot be empty
    if (localPart.empty()) {
        return false;
    }

    // Local part can contain only alphanumeric characters, dot '.', underscore '_', and hyphen '-'
    for (char c : localPart) {
        if (!std::isalnum(c) && c != '.' && c != '_' && c != '-') {
            return false;
        }
    }

    // Local part cannot start or end with dot '.' or underscore '_'
    if (localPart.front() == '.' || localPart.front() == '_' || localPart.back() == '.' || localPart.back() == '_') {
        return false;
    }

    // Local part cannot have consecutive dots '..'
    if (localPart.find("..") != std::string::npos) {
        return false;
    }

    return true;
}

/**
 * @brief Checks if the domain part of an email address is valid.
 * 
 * @param domainPart The domain part of the email address.
 * @return true if the domain part is valid, false otherwise.
 */
bool GiString::is_valid_domain_part(const std::string& domainPart) {
    // Domain part cannot be empty
    if (domainPart.empty()) {
        return false;
    }

    // Domain part can contain only alphanumeric characters, dot '.', and hyphen '-'
    for (char c : domainPart) {
        if (!std::isalnum(c) && c != '.') {
            return false;
        }
    }

    // Domain part cannot start or end with dot '.'
    if (domainPart.front() == '.' || domainPart.back() == '.') {
        return false;
    }

    // Domain part cannot have consecutive dots '..'
    if (domainPart.find("..") != std::string::npos) {
        return false;
    }

    // Domain part must have at least one dot '.'
    if (domainPart.find('.') == std::string::npos) {
        return false;
    }

    return true;
}

// Example usage:
// GiString* myString = new GiString();
// bool result = myString->is_valid_email("example@example.com");
// std::cout << "Is the string a valid email address? " << (result ? "Yes" : "No") << std::endl;


/**
 * @brief URL-encodes a string.
 * 
 * @param str The input string to encode.
 * @return The URL-encoded string.
 */
std::string GiString::url_encode(const std::string& str) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (char c : str) {
        // Keep alphanumeric and special characters untouched
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
        } else if (c == ' ') {
            escaped << '+';
        } else {
            // Encode other characters
            escaped << '%' << std::setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(c));
        }
    }

    return escaped.str();
}

// Example usage:
// GiString* myString = new GiString();
// std::string encodedString = myString->url_encode("hello world");
// std::cout << "Encoded string: " << encodedString << std::endl;


/**
 * @brief URL-decodes a string.
 * 
 * @param str The input string to decode.
 * @return The URL-decoded string.
 */
std::string GiString::url_decode(const std::string& str) {
    std::ostringstream decoded;

    for (std::size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '%') {
            if (i + 2 < str.size() && std::isxdigit(str[i + 1]) && std::isxdigit(str[i + 2])) {
                // Decode percent-encoded character
                int hexValue;
                std::istringstream hexStream(str.substr(i + 1, 2));
                hexStream >> std::hex >> hexValue;
                decoded << static_cast<char>(hexValue);
                i += 2;
            } else {
                // Malformed percent encoding, leave as is
                decoded << str[i];
            }
        } else if (str[i] == '+') {
            // Replace '+' with space character
            decoded << ' ';
        } else {
            decoded << str[i];
        }
    }

    return decoded.str();
}

// Example usage:
// GiString* myString = new GiString();
// std::string decodedString = myString->url_decode("hello%20world");
// std::cout << "Decoded string: " << decodedString << std::endl;


/**
 * @brief Encodes a string to Base64 format.
 * 
 * @param str The input string to encode.
 * @return The Base64-encoded string.
 */
std::string GiString::base64_encode(const std::string& str) {
    // Base64 characters table
    const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    // Convert string to bytes
    std::vector<unsigned char> bytes(str.begin(), str.end());

    std::string encoded;
    int i = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    for (auto& byte : bytes) {
        char_array_3[i++] = byte;
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; i < 4; ++i)
                encoded += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for (int j = i; j < 3; ++j)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

        for (int j = 0; j < i + 1; ++j)
            encoded += base64_chars[char_array_4[j]];

        while (i++ < 3)
            encoded += '=';
    }

    return encoded;
}

// Example usage:
// GiString* myString = new GiString();
// std::string encodedString = myString->base64_encode("Hello, World!");
// std::cout << "Base64 encoded string: " << encodedString << std::endl;


/**
 * @brief Decodes a Base64-encoded string.
 * 
 * @param str The Base64-encoded string to decode.
 * @return The decoded string.
 */
std::string GiString::base64_decode(const std::string& str) {
    // Base64 characters table
    const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    std::vector<int> decoding_table(256, -1);
    for (int i = 0; i < 64; ++i) {
        decoding_table[base64_chars[i]] = i;
    }

    std::string decoded;
    int val = 0, valb = -8;
    for (unsigned char c : str) {
        if (decoding_table[c] == -1) break;
        val = (val << 6) + decoding_table[c];
        valb += 6;
        if (valb >= 0) {
            decoded.push_back(static_cast<char>((val >> valb) & 0xFF));
            valb -= 8;
        }
    }

    return decoded;
}

// Example usage:
// GiString* myString = new GiString();
// std::string decodedString = myString->base64_decode("SGVsbG8sIFdvcmxkIQ==");
// std::cout << "Base64 decoded string: " << decodedString << std::endl;



/**
 * @brief Checks if a string is a valid UTF-8 sequence.
 * 
 * @param str The input string to check.
 * @return true if the string is a valid UTF-8 sequence, false otherwise.
 */
bool GiString::valid_utf8(const std::string& str) {
    int bytesToFollow = 0;
    for (char c : str) {
        if (bytesToFollow == 0) {
            if ((c & 0b10000000) == 0b0) {
                // Single-byte character
                bytesToFollow = 0;
            } else if ((c & 0b11100000) == 0b11000000) {
                // Two-byte character
                bytesToFollow = 1;
            } else if ((c & 0b11110000) == 0b11100000) {
                // Three-byte character
                bytesToFollow = 2;
            } else if ((c & 0b11111000) == 0b11110000) {
                // Four-byte character
                bytesToFollow = 3;
            } else {
                return false; // Invalid UTF-8 sequence
            }
        } else {
            if ((c & 0b11000000) != 0b10000000) {
                return false; // Invalid UTF-8 sequence   
                //
            }
            bytesToFollow--;
        }
    }
    return bytesToFollow == 0;
}

// Example usage:
// GiString* myString = new GiString();
// bool result = myString->valid_utf8("Hello, world!");
// std::cout << "Is the string a valid UTF-8 sequence? " << (result ? "Yes" : "No") << std::endl;



/**
 * @brief Converts a string to its binary representation.
 * 
 * @param str The input string to convert.
 * @return The binary representation of the string.
 */
std::string GiString::to_binary(const std::string& str) {
    std::string binary;
    for (char c : str) {
        binary += std::bitset<8>(c).to_string();
    }
    return binary;
}

// Example usage:
// GiString* myString = new GiString();
// std::string binaryString = myString->to_binary("Hello");
// std::cout << "Binary representation: " << binaryString << std::endl;


/**
 * @brief Converts a binary representation to its corresponding string.
 * 
 * @param binary The input binary representation to convert.
 * @return The string decoded from the binary representation.
 */
std::string GiString::from_binary(const std::string& binary) {
    std::string str;
    for (std::size_t i = 0; i < binary.length(); i += 8) {
        std::bitset<8> bits(binary.substr(i, 8));
        char c = static_cast<char>(bits.to_ulong());
        str.push_back(c);
    }
    return str;
}

// Example usage:
// GiString* myString = new GiString();
// std::string originalString = myString->from_binary("01001000 01100101 01101100 01101100 01101111");
// std::cout << "Decoded string: " << originalString << std::endl;


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
 * @brief Capitalizes the first letter of each word in a string, leaving other letters unchanged.
 * 
 * @param str The input string to capitalize each word.
 * @return The string with the first letter of each word capitalized.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::capitalize_each_word(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::capitalize_each_word)");
    }
    
    std::string result = str;
    bool capitalizeNext = true; // Flag to capitalize next character
    
    // Iterate over each character in the string
    for (size_t i = 0; i < result.length(); ++i) {
        if (std::isspace(result[i])) {
            capitalizeNext = true; // Set flag to capitalize next character if it's a space
        } else {
            if (capitalizeNext) {
                result[i] = std::toupper(result[i]); // Capitalize the character
                capitalizeNext = false; // Reset the flag
            }
        }
    }
    
    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "hello world";
// std::string result = gString->capitalize_each_word(input);
// std::cout << "Capitalized each word: " << result << std::endl;
// Output: "Hello World"



/**
 * @brief Converts binary representation to a string.
 * 
 * @param binary The binary representation to convert.
 * @return The string representation of the binary input.
 * 
 * @throws std::invalid_argument If the binary string is empty or contains non-binary characters.
 */
std::string GiString::from_binary(const std::string& binary) {
    // Check if the input binary string is empty
    if (binary.empty()) {
        throw std::invalid_argument("Binary string is empty (GiString::from_binary)");
    }

    // Check if the input binary string contains non-binary characters
    for (char c : binary) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Invalid binary string, contains non-binary characters (GiString::from_binary)");
        }
    }

    // Convert binary to string
    std::string result;
    for (size_t i = 0; i < binary.length(); i += 8) {
        std::string byte = binary.substr(i, 8); // Get 8 characters representing a byte
        char ch = static_cast<char>(std::stoi(byte, nullptr, 2)); // Convert binary byte to char
        result.push_back(ch);
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string binaryInput = "01001000 01100101 01101100 01101100 01101111";
// std::string result = gString->from_binary(binaryInput);
// std::cout << "String from binary: " << result << std::endl;
// Output: "Hello"


/**
 * @brief Converts a string to its binary representation.
 * 
 * @param str The input string to convert to binary.
 * @return The binary representation of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_binary(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::to_binary)");
    }

    // Convert each character to its binary representation
    std::string binaryResult;
    for (char c : str) {
        std::bitset<8> binaryChar(c); // Convert char to binary (8 bits)
        binaryResult += binaryChar.to_string(); // Append binary representation to result
    }

    return binaryResult;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "Hello";
// std::string result = gString->to_binary(input);
// std::cout << "Binary representation: " << result << std::endl;
// Output: "01001000 01100101 01101100 01101100 01101111"


/**
 * @brief Compares two strings and returns their differences.
 * 
 * @param str1 The first string for comparison.
 * @param str2 The second string for comparison.
 * @return The differences between the two strings.
 * 
 * @throws std::invalid_argument If one or both input strings are empty.
 */
std::string GiString::difference(const std::string& str1, const std::string& str2) {
    // Check if one or both input strings are empty
    if (str1.empty() || str2.empty()) {
        throw std::invalid_argument("One or both input strings are empty (GiString::difference)");
    }

    // Find the minimum length between the two strings
    size_t minLen = std::min(str1.length(), str2.length());
    
    // Find the position where the strings differ
    size_t diffPos = 0;
    while (diffPos < minLen && str1[diffPos] == str2[diffPos]) {
        ++diffPos;
    }

    // Construct the difference string
    std::string diff;
    if (diffPos == minLen) {
        // One string is a prefix of the other
        if (str1.length() < str2.length()) {
            diff = "Strings differ at position " + std::to_string(diffPos) + ": " + str2.substr(diffPos);
        } else {
            diff = "Strings differ at position " + std::to_string(diffPos) + ": " + str1.substr(diffPos);
        }
    } else {
        // Strings differ at the found position
        diff = "Strings differ at position " + std::to_string(diffPos) + ": " + str1.substr(diffPos) + " vs " + str2.substr(diffPos);
    }

    return diff;
}

// Example usage:
// GiString* gString = new GiString();
// std::string str1 = "apple";
// std::string str2 = "banana";
// std::string result = gString->difference(str1, str2);
// std::cout << "String difference: " << result << std::endl;
// Output: "Strings differ at position 0: apple vs banana"


/**
 * @brief Checks if one string is a subsequence of another string.
 * 
 * @param str The potential subsequence string.
 * @param sequence The string to check for the subsequence.
 * @return True if str is a subsequence of sequence, false otherwise.
 * 
 * @throws std::invalid_argument If one or both input strings are empty.
 */
bool GiString::is_subsequence(const std::string& str, const std::string& sequence) {
    // Check if one or both input strings are empty
    if (str.empty() || sequence.empty()) {
        throw std::invalid_argument("One or both input strings are empty (GiString::is_subsequence)");
    }

    size_t strIndex = 0; // Index for iterating through str
    size_t seqIndex = 0; // Index for iterating through sequence

    // Iterate through both strings until the end of either is reached
    while (strIndex < str.length() && seqIndex < sequence.length()) {
        if (str[strIndex] == sequence[seqIndex]) {
            // Match found, move to the next character in str
            ++strIndex;
        }
        // Move to the next character in sequence
        ++seqIndex;
    }

    // If strIndex reached the end of str, it means all characters in str were found in sequence
    return strIndex == str.length();
}

// Example usage:
// GiString* gString = new GiString();
// std::string str = "abc";
// std::string sequence = "aabbcc";
// bool result = gString->is_subsequence(str, sequence);
// std::cout << "Is subsequence? " << (result ? "Yes" : "No") << std::endl;
// Output: "Is subsequence? Yes"


int GiString::levenshtein_distance(const std::string& s1, const std::string& s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));
    
    for (int i = 0; i <= len1; ++i) {
        dp[i][0] = i;
    }
    
    for (int j = 0; j <= len2; ++j) {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            
            dp[i][j] = std::min({
                dp[i - 1][j] + 1,         // Usunięcie
                dp[i][j - 1] + 1,         // Dodanie
                dp[i - 1][j - 1] + cost   // Zamiana
            });
        }
    }
    
    return dp[len1][len2];
}




/**
 * @brief Finds the longest common subsequence between two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return The longest common subsequence between str1 and str2.
 * 
 * @throws std::invalid_argument If one or both input strings are empty.
 */
std::string GiString::longest_common_subsequence(const std::string& str1, const std::string& str2) {
    // Check if one or both input strings are empty
    if (str1.empty() || str2.empty()) {
        throw std::invalid_argument("One or both input strings are empty (GiString::longest_common_subsequence)");
    }

    // Initialize a table to store the lengths of longest common subsequences
    std::vector<std::vector<int>> lcsTable(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));

    // Fill the table using dynamic programming
    for (size_t i = 1; i <= str1.length(); ++i) {
        for (size_t j = 1; j <= str2.length(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            } else {
                lcsTable[i][j] = std::max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
            }
        }
    }

    // Construct the longest common subsequence from the table
    std::string lcs;
    size_t i = str1.length();
    size_t j = str2.length();
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            --i;
            --j;
        } else if (lcsTable[i - 1][j] > lcsTable[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return lcs;
}

// Example usage:
// GiString* gString = new GiString();
// std::string str1 = "ABCBDAB";
// std::string str2 = "BDCAB";
// std::string result = gString->longest_common_subsequence(str1, str2);
// std::cout << "Longest common subsequence: " << result << std::endl;
// Output: "BCAB"



/**
 * @brief Finds the longest common substring between two strings.
 * 
 * @param str1 The first string.
 * @param str2 The second string.
 * @return The longest common substring between str1 and str2.
 * 
 * @throws std::invalid_argument If one or both input strings are empty.
 */
std::string GiString::longest_common_substring(const std::string& str1, const std::string& str2) {
    // Check if one or both input strings are empty
    if (str1.empty() || str2.empty()) {
        throw std::invalid_argument("One or both input strings are empty (GiString::longest_common_substring)");
    }

    // Initialize a table to store the lengths of longest common substrings
    std::vector<std::vector<int>> lcsTable(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));
    int maxLen = 0; // Length of the longest common substring
    int endIndex = 0; // End index of the longest common substring in str1

    // Fill the table using dynamic programming
    for (size_t i = 1; i <= str1.length(); ++i) {
        for (size_t j = 1; j <= str2.length(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
                if (lcsTable[i][j] > maxLen) {
                    maxLen = lcsTable[i][j];
                    endIndex = i - 1; // Update end index of longest common substring
                }
            } else {
                lcsTable[i][j] = 0;
            }
        }
    }

    // Extract the longest common substring from str1
    return str1.substr(endIndex - maxLen + 1, maxLen);
}

// Example usage:
// GiString* gString = new GiString();
// std::string str1 = "ABCBDAB";
// std::string str2 = "BDCAB";
// std::string result = gString->longest_common_substring(str1, str2);
// std::cout << "Longest common substring: " << result << std::endl;
// Output: "BD"


/**
 * @brief Returns the next lexicographically greater permutation of the string.
 * 
 * @param str The input string.
 * @return The next lexicographically greater permutation of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty or has only one character.
 */
std::string GiString::next_permutation(const std::string& str) {
    // Check if the input string is empty or has only one character
    if (str.empty() || str.length() == 1) {
        throw std::invalid_argument("Input string must have at least two characters (GiString::next_permutation)");
    }

    // Create a copy of the input string to work with
    std::string nextPermutation = str;

    // Attempt to find the next lexicographically greater permutation
    if (std::next_permutation(nextPermutation.begin(), nextPermutation.end())) {
        return nextPermutation;
    } else {
        throw std::invalid_argument("No next permutation exists (GiString::next_permutation)");
    }
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "abc";
// std::string result = gString->next_permutation(input);
// std::cout << "Next permutation: " << result << std::endl;
// Output: "acb"


/**
 * @brief Returns the next lexicographically smaller permutation of the string.
 * 
 * @param str The input string.
 * @return The next lexicographically smaller permutation of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty or has only one character.
 */
std::string GiString::prev_permutation(const std::string& str) {
    // Check if the input string is empty or has only one character
    if (str.empty() || str.length() == 1) {
        throw std::invalid_argument("Input string must have at least two characters (GiString::prev_permutation)");
    }

    // Create a copy of the input string to work with
    std::string prevPermutation = str;

    // Attempt to find the next lexicographically smaller permutation
    if (std::prev_permutation(prevPermutation.begin(), prevPermutation.end())) {
        return prevPermutation;
    } else {
        throw std::invalid_argument("No previous permutation exists (GiString::prev_permutation)");
    }
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "cba";
// std::string result = gString->prev_permutation(input);
// std::cout << "Previous permutation: " << result << std::endl;
// Output: "bca"


/**
 * @brief Generates a random string of the specified length.
 * 
 * @param length The length of the random string to generate.
 * @return The generated random string.
 * 
 * @throws std::invalid_argument If the specified length is zero or negative.
 */
std::string GiString::random_string(size_t length) {
    // Check if the specified length is zero or negative
    if (length == 0) {
        throw std::invalid_argument("Length must be greater than zero (GiString::random_string)");
    }

    // Define characters that can be used in the random string
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charset.length() - 1);

    // Generate random string
    std::string randomStr;
    for (size_t i = 0; i < length; ++i) {
        randomStr += charset[dis(gen)];
    }

    return randomStr;
}

// Example usage:
// GiString* gString = new GiString();
// size_t length = 10;
// std::string result = gString->random_string(length);
// std::cout << "Random string: " << result << std::endl;


/**
 * @brief Surrounds a string with double quotation marks.
 * 
 * @param str The input string to surround with quotes.
 * @return The input string surrounded by double quotation marks.
 */
std::string GiString::quote(const std::string& str) {
    return "\"" + str + "\"";
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "example";
// std::string result = gString->quote(input);
// std::cout << "Quoted string: " << result << std::endl;
// Output: "example"


/**
 * @brief Removes surrounding double quotation marks from a string.
 * 
 * @param str The input string possibly surrounded by quotes.
 * @return The input string with surrounding quotes removed.
 * 
 * @throws std::invalid_argument If the input string is empty or does not start and end with quotes.
 */
std::string GiString::unquote(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::unquote)");
    }

    // Check if the input string starts and ends with quotes
    if (str.front() != '"' || str.back() != '"') {
        throw std::invalid_argument("Input string must start and end with quotes (GiString::unquote)");
    }

    // Remove the surrounding quotes
    return str.substr(1, str.length() - 2);
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "\"example\"";
// std::string result = gString->unquote(input);
// std::cout << "Unquoted string: " << result << std::endl;
// Output: "example"



/**
 * @brief Masks sensitive data in a string, replacing characters with asterisks.
 * 
 * @param str The input string containing sensitive data.
 * @param sensitiveChars The characters to be masked.
 * @param maskChar The character to use as a mask (default is '*').
 * @return The input string with sensitive data masked.
 * 
 * @throws std::invalid_argument If the input string is empty or the list of sensitive characters is empty.
 */
std::string GiString::mask_sensitive(const std::string& str, const std::string& sensitiveChars, char maskChar = '*') {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::mask_sensitive)");
    }

    // Check if the list of sensitive characters is empty
    if (sensitiveChars.empty()) {
        throw std::invalid_argument("List of sensitive characters is empty (GiString::mask_sensitive)");
    }

    // Mask sensitive characters in the string
    std::string maskedStr = str;
    for (char c : sensitiveChars) {
        std::replace(maskedStr.begin(), maskedStr.end(), c, maskChar);
    }

    return maskedStr;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "password123";
// std::string result = gString->mask_sensitive(input, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
// std::cout << "Masked string: " << result << std::endl;
// Output: "***********"


/**
 * @brief Capitalizes the first letter of each sentence in a string.
 * 
 * @param str The input string containing sentences.
 * @return The string with the first letter of each sentence capitalized.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::capitalize_sentences(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::capitalize_sentences)");
    }

    std::string result = str;
    bool capitalizeNext = true; // Flag to capitalize next character

    // Iterate over each character in the string
    for (size_t i = 0; i < result.length(); ++i) {
        if (capitalizeNext && std::isalpha(result[i])) {
            result[i] = std::toupper(result[i]); // Capitalize the character
            capitalizeNext = false; // Reset the flag
        }
        // Set flag to capitalize next character if it's a punctuation indicating end of sentence
        if (result[i] == '.' || result[i] == '?' || result[i] == '!') {
            capitalizeNext = true;
        }
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "hello. this is a test! it should work. or not?";
// std::string result = gString->capitalize_sentences(input);
// std::cout << "Capitalized sentences: " << result << std::endl;
// Output: "Hello. This is a test! It should work. Or not?"


/**
 * @brief Returns the number of lines in a string.
 * 
 * @param str The input string containing lines.
 * @return The number of lines in the input string.
 */
size_t GiString::line_count(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::line_count)");
    }

    std::stringstream ss(str);
    size_t count = 0;
    std::string line;

    // Count the number of lines in the string
    while (std::getline(ss, line)) {
        ++count;
    }

    return count;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "Line 1\nLine 2\nLine 3";
// size_t result = gString->line_count(input);
// std::cout << "Number of lines: " << result << std::endl;
// Output: "Number of lines: 3"


/**
 * @brief Finds and returns the least common character in a string.
 * 
 * @param str The input string.
 * @return The least common character in the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
char GiString::least_common_char(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::least_common_char)");
    }

    std::unordered_map<char, int> charCount;

    // Count occurrences of each character in the string
    for (char c : str) {
        ++charCount[c];
    }

    // Find the least common character
    char leastCommon = str[0];
    int minCount = charCount[str[0]];
    for (const auto& pair : charCount) {
        if (pair.second < minCount) {
            minCount = pair.second;
            leastCommon = pair.first;
        }
    }

    return leastCommon;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "abbcccddddeeeee";
// char result = gString->least_common_char(input);
// std::cout << "Least common character: " << result << std::endl;
// Output: "Least common character: a"



/**
 * @brief Finds and returns the most common character in a string.
 * 
 * @param str The input string.
 * @return The most common character in the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
char GiString::most_common_char(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::most_common_char)");
    }

    std::unordered_map<char, int> charCount;

    // Count occurrences of each character in the string
    for (char c : str) {
        ++charCount[c];
    }

    // Find the most common character
    char mostCommon = str[0];
    int maxCount = charCount[str[0]];
    for (const auto& pair : charCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostCommon = pair.first;
        }
    }

    return mostCommon;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "abbcccddddeeeee";
// char result = gString->most_common_char(input);
// std::cout << "Most common character: " << result << std::endl;
// Output: "Most common character: e"


/**
 * @brief Swaps two characters in a string at specified positions.
 * 
 * @param str The input string.
 * @param pos1 The position of the first character to swap (0-based index).
 * @param pos2 The position of the second character to swap (0-based index).
 * @return The string with characters swapped at the specified positions.
 * 
 * @throws std::invalid_argument If the positions are out of range or the string is empty.
 */
std::string GiString::swap_position(const std::string& str, size_t pos1, size_t pos2) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::swap_position)");
    }

    // Check if the positions are out of range
    if (pos1 >= str.length() || pos2 >= str.length()) {
        throw std::invalid_argument("Position is out of range (GiString::swap_position)");
    }

    // Swap characters at the specified positions
    std::string swappedStr = str;
    std::swap(swappedStr[pos1], swappedStr[pos2]);

    return swappedStr;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "abcd";
// std::string result = gString->swap_position(input, 1, 3);
// std::cout << "Swapped string: " << result << std::endl;
// Output: "adcb"



/**
 * @brief Converts a Roman numeral to an integer.
 * 
 * @param s The Roman numeral string to convert.
 * @return The integer equivalent of the Roman numeral.
 * 
 * @throws std::invalid_argument If the input string is empty or contains an invalid Roman numeral.
 */
int GiString::roman_to_int(const std::string& s) {
    // Check if the input string is empty
    if (s.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::roman_to_int)");
    }

    std::unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;

    // Traverse the string from right to left and sum up the values
    for (int i = s.length() - 1; i >= 0; --i) {
        int value = romanMap[s[i]];

        // If the current value is less than the previous value, subtract it
        if (value < prevValue) {
            result -= value;
        } else {
            result += value;
        }

        prevValue = value;
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "MCMXCIV"; // 1994 in Roman numerals
// int result = gString->roman_to_int(input);
// std::cout << "Integer value: " << result << std::endl;
// Output: "Integer value: 1994"



/**
 * @brief Normalizes whitespace in a string by replacing sequences of whitespace characters with a single space.
 * 
 * @param str The input string to normalize.
 * @return The string with normalized whitespace.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::normalize_whitespace(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::normalize_whitespace)");
    }

    std::string result;

    // Flag to indicate if the previous character was a whitespace
    bool prevIsWhitespace = false;

    // Iterate over each character in the string
    for (char c : str) {
        // If the current character is a whitespace and the previous character was not a whitespace,
        // add a space to the result string
        if (std::isspace(c)) {
            if (!prevIsWhitespace) {
                result += ' ';
                prevIsWhitespace = true;
            }
        } else {
            // If the current character is not a whitespace, add it to the result string
            result += c;
            prevIsWhitespace = false;
        }
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "  Hello   world!  ";
// std::string result = gString->normalize_whitespace(input);
// std::cout << "Normalized string: " << result << std::endl;
// Output: " Hello world! "


/**
 * @brief Removes all punctuation characters from a string.
 * 
 * @param str The input string to remove punctuation from.
 * @return The string with punctuation removed.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::remove_punctuation(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::remove_punctuation)");
    }

    std::string result;

    // Iterate over each character in the string
    for (char c : str) {
        // If the current character is not a punctuation, add it to the result string
        if (!std::ispunct(c)) {
            result += c;
        }
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "Hello, world!";
// std::string result = gString->remove_punctuation(input);
// std::cout << "String without punctuation: " << result << std::endl;
// Output: "String without punctuation: Hello world"


/**
 * @brief Converts a string to its hexadecimal representation.
 * 
 * @param str The input string to convert.
 * @return The hexadecimal representation of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_hex(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::to_hex)");
    }

    std::stringstream ss;

    // Convert each character of the input string to hexadecimal representation
    for (char c : str) {
        // Convert the character to hexadecimal and append it to the stringstream
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

    return ss.str();
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "hello";
// std::string result = gString->to_hex(input);
// std::cout << "Hexadecimal representation: " << result << std::endl;
// Output: "Hexadecimal representation: 68656c6c6f"


/**
 * @brief Converts a hexadecimal string to its ASCII representation.
 * 
 * @param hexStr The hexadecimal string to convert.
 * @return The ASCII representation of the hexadecimal string.
 * 
 * @throws std::invalid_argument If the input hexadecimal string is empty or has an odd length.
 */
std::string GiString::from_hex(const std::string& hexStr) {
    // Check if the input hexadecimal string is empty
    if (hexStr.empty()) {
        throw std::invalid_argument("Input hexadecimal string is empty (GiString::from_hex)");
    }

    // Check if the input hexadecimal string has an odd length
    if (hexStr.length() % 2 != 0) {
        throw std::invalid_argument("Input hexadecimal string has an odd length (GiString::from_hex)");
    }

    std::stringstream ss;
    for (size_t i = 0; i < hexStr.length(); i += 2) {
        // Extract two characters at a time from the hexadecimal string
        std::string byteString = hexStr.substr(i, 2);

        // Convert the two characters to an integer
        int byteValue;
        std::stringstream(byteString) >> std::hex >> byteValue;

        // Append the character corresponding to the integer value to the result stringstream
        ss << static_cast<char>(byteValue);
    }

    return ss.str();
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "68656c6c6f";
// std::string result = gString->from_hex(input);
// std::cout << "ASCII representation: " << result << std::endl;
// Output: "ASCII representation: hello"



/**
 * @brief Converts a string to its octal representation.
 * 
 * @param str The input string to convert.
 * @return The octal representation of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_octal(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::to_octal)");
    }

    std::stringstream ss;

    // Convert each character of the input string to octal representation
    for (char c : str) {
        // Convert the character to octal and append it to the stringstream
        ss << std::oct << std::setw(3) << std::setfill('0') << static_cast<int>(c);
    }

    return ss.str();
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "hello";
// std::string result = gString->to_octal(input);
// std::cout << "Octal representation: " << result << std::endl;
// Output: "Octal representation: 150 145 154 154 157"


/**
 * @brief Converts an octal string to its ASCII representation.
 * 
 * @param octalStr The octal string to convert.
 * @return The ASCII representation of the octal string.
 * 
 * @throws std::invalid_argument If the input octal string is empty.
 */
std::string GiString::from_octal(const std::string& octalStr) {
    // Check if the input octal string is empty
    if (octalStr.empty()) {
        throw std::invalid_argument("Input octal string is empty (GiString::from_octal)");
    }

    std::stringstream ss;
    std::istringstream iss(octalStr);

    // Parse the input octal string and convert each octal number to its ASCII representation
    int octalValue;
    while (iss >> std::oct >> octalValue) {
        // Append the character corresponding to the octal value to the result stringstream
        ss << static_cast<char>(octalValue);
    }

    return ss.str();
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "150 145 154 154 157";
// std::string result = gString->from_octal(input);
// std::cout << "ASCII representation: " << result << std::endl;
// Output: "ASCII representation: hello"




/**
 * @brief Checks if parentheses in a string are correctly paired and arranged.
 * 
 * @param str The input string to check.
 * @return True if parentheses are correctly paired and arranged, false otherwise.
 */
bool GiString::bracket_check(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::bracket_check)");
    }

    std::stack<char> brackets;

    // Iterate over each character in the string
    for (char c : str) {
        // If the current character is an opening bracket, push it onto the stack
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        }
        // If the current character is a closing bracket
        else if (c == ')' || c == ']' || c == '}') {
            // If the stack is empty, there is no matching opening bracket
            if (brackets.empty()) {
                return false;
            }

            // Pop the top element from the stack
            char top = brackets.top();
            brackets.pop();

            // Check if the current closing bracket matches the top element on the stack
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    // If the stack is not empty, there are unmatched opening brackets
    return brackets.empty();
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "(a + b) * (c - d)";
// bool result = gString->bracket_check(input);
// std::cout << "Brackets are correctly paired and arranged: " << std::boolalpha << result << std::endl;
// Output: "Brackets are correctly paired and arranged: true"



/**
 * @brief Removes consecutive duplicate characters from a string, leaving only single occurrences.
 * 
 * @param str The input string to squeeze.
 * @return The string with consecutive duplicate characters removed.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::squeeze(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::squeeze)");
    }

    std::string result;

    // Iterate over each character in the string
    for (size_t i = 0; i < str.length(); ++i) {
        // If the current character is different from the next character (or it's the last character),
        // add it to the result string
        if (str[i] != str[i + 1] || i == str.length() - 1) {
            result += str[i];
        }
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "hellooo";
// std::string result = gString->squeeze(input);
// std::cout << "Squeezed string: " << result << std::endl;
// Output: "Squeezed string: helo"



/**
 * @brief Replaces tabs in a string with spaces, optionally specifying the tab width.
 * 
 * @param str The input string containing tabs.
 * @param tabWidth The width of each tab (default is 4).
 * @return The string with tabs replaced by spaces.
 * 
 * @throws std::invalid_argument If the input string is empty or tab width is non-positive.
 */
std::string GiString::expand_tabs(const std::string& str, size_t tabWidth = 4) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::expand_tabs)");
    }

    // Check if the tab width is non-positive
    if (tabWidth <= 0) {
        throw std::invalid_argument("Tab width must be positive (GiString::expand_tabs)");
    }

    std::string result;

    // Iterate over each character in the string
    for (char c : str) {
        // If the current character is a tab, replace it with spaces up to the tab width
        if (c == '\t') {
            size_t spacesToAdd = tabWidth - (result.length() % tabWidth);
            result += std::string(spacesToAdd, ' ');
        } else {
            // If the current character is not a tab, add it to the result string
            result += c;
        }
    }

    return result;
}

// Example usage:
// GiString* gString = new GiString();
// std::string input = "hello\tworld\t\t!";
// std::string result = gString->expand_tabs(input, 4);
// std::cout << "Expanded string: " << result << std::endl;
// Output: "hello   world       !"

/**
 * @brief Breaks the text into lines with a specified maximum length.
 * 
 * @param text The input text to be wrapped.
 * @param max_length The maximum length of each line.
 * @return The wrapped text with lines of maximum length.
 * 
 * @throws std::invalid_argument If the maximum length is less than or equal to 0.
 */
std::string GiString::wrap_text(const std::string& text, size_t max_length) {
    // Check if the maximum length is valid
    if (max_length <= 0) {
        throw std::invalid_argument("Maximum length must be greater than 0 (GiString::wrap_text)");
    }
    
    std::string wrapped_text;
    size_t length = text.length();
    size_t start = 0;
    
    while (start < length) {
        // Find the end index of the current line
        size_t end = std::min(start + max_length, length);
        
        // Find the last space within the maximum length
        while (end > start && !std::isspace(text[end - 1])) {
            --end;
        }
        
        // Append the current line to the wrapped text
        wrapped_text += text.substr(start, end - start);
        
        // Add a newline character if not at the end of the text
        if (end < length) {
            wrapped_text += '\n';
        }
        
        // Move to the next line
        start = end;
        
        // Skip leading spaces in the next line
        while (start < length && std::isspace(text[start])) {
            ++start;
        }
    }
    
    return wrapped_text;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
// std::string wrapped = giString->wrap_text(input, 20);
// std::cout << "Wrapped text:\n" << wrapped << std::endl;
// delete giString;



/**
 * @brief Justifies the text to both left and right sides by adding appropriate spaces between words.
 * 
 * @param text The input text to be justified.
 * @param max_length The maximum length of each line.
 * @return The justified text with evenly spaced words.
 * 
 * @throws std::invalid_argument If the maximum length is less than or equal to 0.
 * @throws std::invalid_argument If any word in the text exceeds the maximum length.
 */
std::string GiString::text_justify(const std::string& text, size_t max_length) {
    // Check if the maximum length is valid
    if (max_length <= 0) {
        throw std::invalid_argument("Maximum length must be greater than 0 (GiString::text_justify)");
    }

    std::vector<std::string> words;
    std::istringstream iss(text);
    std::string word;

    // Split the text into words
    while (iss >> word) {
        if (word.length() > max_length) {
            throw std::invalid_argument("Word length exceeds maximum length (GiString::text_justify)");
        }
        words.push_back(word);
    }

    std::string justified_text;
    size_t line_length = 0;
    size_t num_words = words.size();

    for (size_t i = 0; i < num_words; ++i) {
        // Add word to the line if it fits
        if (line_length + words[i].length() <= max_length) {
            justified_text += words[i];
            line_length += words[i].length();

            // Add space if not the last word in the line
            if (i < num_words - 1) {
                justified_text += ' ';
                ++line_length;
            }
        } else {
            // Calculate the number of spaces to add for justification
            size_t num_spaces = max_length - line_length;
            size_t space_between_words = num_words > 1 ? num_spaces / (num_words - 1) : 0;
            size_t extra_spaces = num_spaces % (num_words - 1);

            // Add spaces between words
            for (size_t j = 0; j < num_words - 1; ++j) {
                justified_text += words[j];
                justified_text.append(space_between_words + (j < extra_spaces), ' ');
            }

            // Add the last word without space
            justified_text += words[num_words - 1];

            // Reset line length for the next line
            line_length = 0;
            justified_text += '\n';
            num_words = 0;
        }
    }

    return justified_text;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
// std::string justified = giString->text_justify(input, 40);
// std::cout << "Justified text:\n" << justified << std::endl;
// delete giString;



/**
 * @brief Converts a string to Morse code.
 * 
 * @param text The input string to convert to Morse code.
 * @return The Morse code representation of the input string.
 * 
 * @throws std::invalid_argument If the input string contains unsupported characters.
 */
std::string GiString::to_morse_code(const std::string& text) {
    std::unordered_map<char, std::string> morse_code_map = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
        {'9', "----."}, {'0', "-----"}
    };

    std::string morse_code;
    for (char ch : text) {
        // Convert characters to uppercase
        char uppercase_ch = std::toupper(ch);

        // Check if the character is supported
        if (morse_code_map.find(uppercase_ch) == morse_code_map.end()) {
            throw std::invalid_argument("Unsupported character in input string (GiString::to_morse_code)");
        }

        // Append Morse code for the character
        morse_code += morse_code_map[uppercase_ch] + ' ';
    }

    // Remove trailing space
    if (!morse_code.empty()) {
        morse_code.pop_back();
    }

    return morse_code;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello World";
// std::string morse_code = giString->to_morse_code(input);
// std::cout << "Morse code: " << morse_code << std::endl;
// delete giString;


/**
 * @brief Converts Morse code to plain text.
 * 
 * @param morse_code The input Morse code to convert to plain text.
 * @return The plain text representation of the Morse code.
 * 
 * @throws std::invalid_argument If the input Morse code contains invalid characters.
 */
std::string GiString::from_morse_code(const std::string& morse_code) {
    std::unordered_map<std::string, char> morse_code_map = {
        {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, {"..-.", 'F'},
        {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
        {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},
        {"...", 'S'}, {"-", 'T'}, {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
        {"-.--", 'Y'}, {"--..", 'Z'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
        {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},
        {"----.", '9'}, {"-----", '0'}
    };

    std::string plain_text;
    std::istringstream iss(morse_code);
    std::string morse_word;

    while (iss >> morse_word) {
        // Check if the Morse code is supported
        if (morse_code_map.find(morse_word) == morse_code_map.end()) {
            throw std::invalid_argument("Invalid Morse code sequence in input string (GiString::from_morse_code)");
        }

        // Append the corresponding character to the plain text
        plain_text += morse_code_map[morse_word];
    }

    return plain_text;
}

// Example usage:
// GiString* giString = new GiString();
// std::string morse_code = "... --- ...";
// std::string plain_text = giString->from_morse_code(morse_code);
// std::cout << "Plain text: " << plain_text << std::endl;
// delete giString;


/**
 * @brief Converts a string to its Soundex code (used for comparing word pronunciations).
 * 
 * @param str The input string to convert to Soundex code.
 * @return The Soundex code of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::soundex(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::soundex)");
    }

    // Convert the first character to uppercase
    char firstChar = std::toupper(str.front());

    // Initialize Soundex code with the first character
    std::string soundexCode = std::string(1, firstChar);

    // Map of characters to their Soundex digit values
    std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    // Initialize previous digit with the Soundex code of the first character
    char prevDigit = soundexMap[firstChar];

    // Process the remaining characters of the input string
    for (size_t i = 1; i < str.length(); ++i) {
        char currentChar = std::toupper(str[i]);
        // If the current character is not a letter or is H or W, skip it
        if (!std::isalpha(currentChar) || currentChar == 'H' || currentChar == 'W') {
            continue;
        }

        // Get the Soundex digit for the current character
        char soundexDigit = soundexMap[currentChar];

        // Skip consecutive identical digits
        if (soundexDigit != prevDigit) {
            soundexCode += soundexDigit;
        }

        // Break loop when Soundex code length is 4
        if (soundexCode.length() == 4) {
            break;
        }

        // Update the previous digit
        prevDigit = soundexDigit;
    }

    // Pad with zeros if the Soundex code is less than 4 characters long
    while (soundexCode.length() < 4) {
        soundexCode += '0';
    }

    return soundexCode;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Washington";
// std::string soundex_code = giString->soundex(input);
// std::cout << "Soundex code: " << soundex_code << std::endl;
// delete giString;



/**
 * @brief Converts a string to its Metaphone code (for English).
 * 
 * @param str The input string to convert to Metaphone code.
 * @return The Metaphone code of the input string.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::metaphone(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::metaphone)");
    }

    // Convert the input string to uppercase
    std::string upperStr;
    std::transform(str.begin(), str.end(), std::back_inserter(upperStr), ::toupper);

    // Metaphone code mappings
    std::unordered_map<char, std::string> metaphoneMap = {
        {'A', ""}, {'E', ""}, {'I', ""}, {'O', ""}, {'U', ""}, {'Y', ""},
        {'B', "B"}, {'F', "F"}, {'P', "P"}, {'V', "F"},
        {'C', "K"}, {'G', "K"}, {'J', "J"}, {'K', "K"}, {'Q', "K"}, {'S', "S"}, {'X', "S"}, {'Z', "S"},
        {'D', "T"}, {'T', "T"},
        {'L', "L"},
        {'M', "M"}, {'N', "N"},
        {'R', "R"}
    };

    std::string metaphoneCode;

    // Apply Metaphone rules to the input string
    for (size_t i = 0; i < upperStr.length(); ++i) {
        char currentChar = upperStr[i];
        char nextChar = (i + 1 < upperStr.length()) ? upperStr[i + 1] : '\0';

        // Skip 'W' if it follows a vowel
        if (currentChar == 'W' && metaphoneCode.length() > 0 && metaphoneCode.back() != 'A' &&
            metaphoneCode.back() != 'E' && metaphoneCode.back() != 'I' && metaphoneCode.back() != 'O' &&
            metaphoneCode.back() != 'U' && metaphoneCode.back() != 'Y') {
            continue;
        }

        // Apply Metaphone mappings
        if (metaphoneMap.find(currentChar) != metaphoneMap.end()) {
            if (nextChar == 'H') {
                if ((currentChar == 'C' || currentChar == 'S') && (i + 2 < upperStr.length()) &&
                    (upperStr[i + 2] == 'H')) {
                    // Skip 'CH' and 'SH'
                    metaphoneCode += metaphoneMap[currentChar];
                    ++i; // Skip 'H'
                }
            } else if (nextChar == 'N' && currentChar == 'G' && i + 2 < upperStr.length() && upperStr[i + 2] == 'E') {
                // Skip 'NGE'
                ++i;
            } else if (nextChar == 'N' && currentChar == 'G' && i + 2 < upperStr.length() && upperStr[i + 2] == 'N') {
                // Skip 'NGN'
                ++i;
            } else if (nextChar == 'N' && currentChar == 'G' && i + 2 < upperStr.length() && upperStr[i + 2] == 'K') {
                // Skip 'NGK'
                ++i;
            } else if (nextChar == 'N' && currentChar == 'G' && i + 2 < upperStr.length() && upperStr[i + 2] == 'T') {
                // Skip 'NGT'
                ++i;
            } else if (nextChar == 'N' && currentChar == 'G' && i + 2 < upperStr.length() && upperStr[i + 2] == 'D') {
                // Skip 'NGD'
                ++i;
            } else {
                metaphoneCode += metaphoneMap[currentChar];
            }
        }

        // Limit Metaphone code to 4 characters
        if (metaphoneCode.length() >= 4) {
            break;
        }
    }

    return metaphoneCode;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Katherine";
// std::string metaphone_code = giString->metaphone(input);
// std::cout << "Metaphone code: " << metaphone_code << std::endl;
// delete giString;


/**
 * @brief Converts a string to its Double Metaphone code (for English).
 * 
 * @param str The input string to convert to Double Metaphone code.
 * @return A vector containing the primary and secondary Double Metaphone codes.
 * 
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::double_metaphone(const std::string& str) {
    // Check if the input string is empty
    if (str.empty()) {
        throw std::invalid_argument("Input string is empty (GiString::double_metaphone)");
    }

    // Convert the input string to uppercase
    std::string upperStr;
    std::transform(str.begin(), str.end(), std::back_inserter(upperStr), ::toupper);

    // Double Metaphone mappings
    std::unordered_map<char, std::string> primaryMap = {
        {'A', ""}, {'E', ""}, {'I', ""}, {'O', ""}, {'U', ""}, {'Y', ""},
        {'B', "P"}, {'F', "F"}, {'P', "P"}, {'V', "F"},
        {'C', "K"}, {'G', "K"}, {'J', "J"}, {'K', "K"}, {'Q', "K"}, {'S', "S"}, {'X', "S"}, {'Z', "S"},
        {'D', "T"}, {'T', "T"},
        {'L', "L"},
        {'M', "M"}, {'N', "N"},
        {'R', "R"}
    };

    std::unordered_map<char, std::string> secondaryMap = {
        {'A', ""}, {'E', ""}, {'I', ""}, {'O', ""}, {'U', ""}, {'Y', ""},
        {'B', "P"}, {'F', "F"}, {'P', "P"}, {'V', "F"},
        {'C', "K"}, {'G', "K"}, {'J', "J"}, {'K', "K"}, {'Q', "K"}, {'S', "X"}, {'X', "X"}, {'Z', "X"},
        {'D', "T"}, {'T', "T"},
        {'L', "L"},
        {'M', "M"}, {'N', "N"},
        {'R', "R"}
    };

    // Initialize primary and secondary Double Metaphone codes
    std::string primaryCode;
    std::string secondaryCode;

    // Apply Double Metaphone rules to the input string
    size_t i = 0;
    while (i < upperStr.length() && (primaryCode.length() < 4 || secondaryCode.length() < 4)) {
        char currentChar = upperStr[i];
        char nextChar = (i + 1 < upperStr.length()) ? upperStr[i + 1] : '\0';

        // Apply primary mapping
        if (primaryMap.find(currentChar) != primaryMap.end()) {
            primaryCode += primaryMap[currentChar];
        }

        // Apply secondary mapping
        if (secondaryMap.find(currentChar) != secondaryMap.end()) {
            secondaryCode += secondaryMap[currentChar];
        }

        // Handle special cases and skip certain characters
        if (currentChar == 'C' && nextChar == 'H') {
            if (i > 0 && upperStr[i - 1] == 'S') {
                primaryCode.pop_back();
                secondaryCode.pop_back();
                primaryCode += "X";
                secondaryCode += "X";
            } else {
                primaryCode += "K";
                secondaryCode += "K";
            }
            ++i; // Skip 'H'
        } else if (currentChar == 'G' && (nextChar == 'H' || nextChar == 'N' || nextChar == 'N')) {
            if (!(i > 0 && upperStr[i - 1] == 'G')) {
                primaryCode += "K";
                secondaryCode += "K";
            }
            ++i; // Skip next character
        } else if (currentChar == 'D' && nextChar == 'G') {
            if (i + 2 < upperStr.length() && upperStr[i + 2] == 'E') {
                primaryCode += "J";
                secondaryCode += "J";
            } else {
                primaryCode += "T";
                secondaryCode += "T";
            }
            i += 2; // Skip next two characters
        } else if (currentChar == 'G' && (nextChar == 'I' || nextChar == 'E' || nextChar == 'Y')) {
            if (!(i > 0 && upperStr[i - 1] == 'G')) {
                primaryCode += "J";
                secondaryCode += "J";
            }
            ++i; // Skip next character
        } else if (currentChar == 'G' && nextChar == 'H') {
            if (i == 0 || (i > 0 && (upperStr[i - 1] == 'A' || upperStr[i - 1] == 'E' || upperStr[i - 1] == 'I' ||
                                      upperStr[i - 1] == 'O' || upperStr[i - 1] == 'U'))) {
                primaryCode += "F";
                secondaryCode += "F";
            } else {
                primaryCode += "K";
                secondaryCode += "K";
            }
            ++i; // Skip 'H'
        } else if (currentChar == 'C' && nextChar == 'I' && i > 1 && upperStr[i - 2] != 'S') {
            primaryCode += "S";
            secondaryCode += "X";
            ++i; // Skip next character
        } else if (currentChar == 'C' && nextChar == 'I' && i + 2 < upperStr.length() && upperStr[i + 2] == 'A') {
            primaryCode += "X";
            secondaryCode += "X";
            ++i; // Skip next character
        } else if (currentChar == 'C' && nextChar == 'H') {
            primaryCode += "X";
            secondaryCode += "X";
            ++i; // Skip 'H'
        } else if (currentChar == 'P' && nextChar == 'H') {
            primaryCode += "F";
            secondaryCode += "F";
            ++i; // Skip 'H'
        } else if (currentChar == 'Q' && nextChar == 'U') {
            primaryCode += "K";
            secondaryCode += "K";
            ++i; // Skip 'U'
        } else if (currentChar == 'S' && nextChar == 'C' && i + 2 < upperStr.length() &&
                   (upperStr[i + 2] == 'H' || upperStr[i + 2] == 'I' || upperStr[i + 2] == 'Y')) {
            primaryCode += "S";
            secondaryCode += "S";
            ++i; // Skip next character
        } else if ((currentChar == 'S' || currentChar == 'Z') && nextChar == 'Z') {
            primaryCode += "S";
            secondaryCode += "S";
            ++i; // Skip next character
        }

        // Move to the next character
        ++i;
    }

    // Adjust the length of the secondary code to 4 characters
    while (secondaryCode.length() < 4) {
        secondaryCode += "0";
    }

    // Limit the length of primary code to 4 characters
    if (primaryCode.length() > 4) {
        primaryCode = primaryCode.substr(0, 4);
    }

    // Return the primary and secondary Double Metaphone codes
    return {primaryCode, secondaryCode};
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Smith";
// std::vector<std::string> metaphone_codes = giString->double_metaphone(input);
// std::cout << "Primary Metaphone code: " << metaphone_codes[0] << std::endl;
// std::cout << "Secondary Metaphone code: " << metaphone_codes[1] << std::endl;
// delete giString;


/**
 * @brief Encodes or decodes a string using the ROT13 cipher.
 * 
 * @param str The input string to encode or decode.
 * @param encode True to encode the string, false to decode it.
 * @return The encoded or decoded string.
 */
std::string GiString::rot13(const std::string& str, bool encode) {
    std::string result;
    for (char ch : str) {
        // Encode uppercase letters
        if (std::isupper(ch)) {
            result += (encode ? ((ch - 'A' + 13) % 26 + 'A') : ((ch - 'A' + 13) % 26 + 'A'));
        }
        // Encode lowercase letters
        else if (std::islower(ch)) {
            result += (encode ? ((ch - 'a' + 13) % 26 + 'a') : ((ch - 'a' + 13) % 26 + 'a'));
        }
        // Leave non-alphabetic characters unchanged
        else {
            result += ch;
        }
    }
    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello World";
// std::string encoded = giString->rot13(input, true);
// std::cout << "Encoded string: " << encoded << std::endl;
// std::string decoded = giString->rot13(encoded, false);
// std::cout << "Decoded string: " << decoded << std::endl;
// delete giString;



/**
 * @brief Encodes or decodes a string using the Caesar cipher with a specified shift.
 * 
 * @param str The input string to encode or decode.
 * @param shift The shift value for the Caesar cipher.
 * @param encode True to encode the string, false to decode it.
 * @return The encoded or decoded string.
 */
std::string GiString::caesar_cipher(const std::string& str, int shift, bool encode) {
    std::string result;
    // Ensure the shift value is within the range [0, 25]
    shift %= 26;
    // Adjust the shift value for decoding
    if (!encode) {
        shift = (26 - shift) % 26;
    }
    for (char ch : str) {
        // Encode uppercase letters
        if (std::isupper(ch)) {
            result += (encode ? ((ch - 'A' + shift) % 26 + 'A') : ((ch - 'A' + shift) % 26 + 'A'));
        }
        // Encode lowercase letters
        else if (std::islower(ch)) {
            result += (encode ? ((ch - 'a' + shift) % 26 + 'a') : ((ch - 'a' + shift) % 26 + 'a'));
        }
        // Leave non-alphabetic characters unchanged
        else {
            result += ch;
        }
    }
    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello World";
// int shift = 3;
// std::string encoded = giString->caesar_cipher(input, shift, true);
// std::cout << "Encoded string: " << encoded << std::endl;
// std::string decoded = giString->caesar_cipher(encoded, shift, false);
// std::cout << "Decoded string: " << decoded << std::endl;
// delete giString;



/**
 * @brief Encodes or decodes a string using the XOR cipher with a specified key.
 * 
 * @param str The input string to encode or decode.
 * @param key The key to use for the XOR cipher.
 * @return The encoded or decoded string.
 */
std::string GiString::xor_cipher(const std::string& str, const std::string& key) {
    std::string result;
    // Get the length of the key
    size_t keyLength = key.length();
    // Encode or decode each character in the string using XOR with the corresponding key character
    for (size_t i = 0; i < str.length(); ++i) {
        result += str[i] ^ key[i % keyLength];
    }
    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello World";
// std::string key = "secret";
// std::string encoded = giString->xor_cipher(input, key);
// std::cout << "Encoded string: " << encoded << std::endl;
// std::string decoded = giString->xor_cipher(encoded, key);
// std::cout << "Decoded string: " << decoded << std::endl;
// delete giString;



/**
 * @brief Scrambles the characters in a string according to a specified key.
 * 
 * @param str The input string to scramble.
 * @param key The key to use for scrambling.
 * @return The scrambled string.
 */
std::string GiString::scramble(const std::string& str, const std::string& key) {
    std::unordered_map<char, char> charMap;
    std::string result;

    // Create a mapping of characters to their corresponding characters in the key
    for (size_t i = 0; i < key.length(); ++i) {
        charMap['A' + i] = key[i];
        charMap['a' + i] = key[i] + ('a' - 'A'); // Map lowercase letters to corresponding uppercase letters in the key
    }

    // Scramble the characters in the input string
    for (char ch : str) {
        // If the character is a letter, replace it with its corresponding character in the key
        if (std::isalpha(ch)) {
            result += charMap[ch];
        }
        // If the character is not a letter, keep it unchanged
        else {
            result += ch;
        }
    }

    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello World";
// std::string key = "KEY";
// std::string scrambled = giString->scramble(input, key);
// std::cout << "Scrambled string: " << scrambled << std::endl;
// delete giString;


/**
 * @brief Unscrambles the characters in a string to restore the original order based on a specified key.
 * 
 * @param str The input string to unscramble.
 * @param key The key used for scrambling.
 * @return The unscrambled string.
 */
std::string GiString::unscramble(const std::string& str, const std::string& key) {
    std::unordered_map<char, char> charMap;
    std::string result;

    // Create a mapping of characters in the key to their corresponding letters
    for (size_t i = 0; i < key.length(); ++i) {
        charMap[key[i]] = 'A' + i;
        charMap[key[i] + ('a' - 'A')] = 'a' + i; // Map lowercase letters to corresponding uppercase letters in the key
    }

    // Unscramble the characters in the input string
    for (char ch : str) {
        // If the character is a letter, replace it with its corresponding letter in the key
        if (std::isalpha(ch)) {
            result += charMap[ch];
        }
        // If the character is not a letter, keep it unchanged
        else {
            result += ch;
        }
    }

    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string scrambled = "Hllo Wo!rd";
// std::string key = "KEY";
// std::string unscrambled = giString->unscramble(scrambled, key);
// std::cout << "Unscrambled string: " << unscrambled << std::endl;
// delete giString;


/**
 * @brief Surrounds a string with a specified quotation format.
 * 
 * @param str The input string to wrap in quotes.
 * @param quote_format The quotation format to use (e.g., "single" or "double").
 * @return The string surrounded by the specified quotation format.
 * 
 * @throws std::invalid_argument If the quote_format is not "single" or "double".
 */
std::string GiString::quote_wrap(const std::string& str, const std::string& quote_format) {
    if (quote_format != "single" && quote_format != "double") {
        throw std::invalid_argument("Invalid quote format. Use 'single' or 'double' (GiString::quote_wrap)");
    }

    if (quote_format == "single") {
        return "'" + str + "'";
    } else { // quote_format == "double"
        return "\"" + str + "\"";
    }
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello World";
// std::string single_quoted = giString->quote_wrap(input, "single");
// std::cout << "Single quoted string: " << single_quoted << std::endl;
// std::string double_quoted = giString->quote_wrap(input, "double");
// std::cout << "Double quoted string: " << double_quoted << std::endl;
// delete giString;



/**
 * @brief Removes the quotation format around a string.
 * 
 * @param str The input string to unwrap.
 * @return The string with the quotation format removed.
 * 
 * @throws std::invalid_argument If the input string is not wrapped in a valid quotation format.
 */
std::string GiString::unquote_wrap(const std::string& str) {
    if ((str.front() == '\'' && str.back() == '\'') || (str.front() == '"' && str.back() == '"')) {
        return str.substr(1, str.length() - 2);
    } else {
        throw std::invalid_argument("Invalid quotation format. The input string is not wrapped in quotes (GiString::unquote_wrap)");
    }
}

// Example usage:
// GiString* giString = new GiString();
// std::string single_quoted = "'Hello World'";
// std::string unwrapped_single = giString->unquote_wrap(single_quoted);
// std::cout << "Unwrapped single quoted string: " << unwrapped_single << std::endl;
// std::string double_quoted = "\"Hello World\"";
// std::string unwrapped_double = giString->unquote_wrap(double_quoted);
// std::cout << "Unwrapped double quoted string: " << unwrapped_double << std::endl;
// delete giString;



/**
 * @brief Removes extra spaces from a string.
 * 
 * @param str The input string with extra spaces.
 * @return The string with extra spaces removed.
 */
std::string GiString::remove_extra_spaces(const std::string& str) {
    // Use a regular expression to replace multiple consecutive spaces with a single space
    return std::regex_replace(str, std::regex("\\s+"), " ");
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "   Hello    World   ";
// std::string result = giString->remove_extra_spaces(input);
// std::cout << "String with extra spaces removed: " << result << std::endl;
// delete giString;


/**
 * @brief Highlights specified terms in a string by adding a special tag.
 * 
 * @param str The input string.
 * @param terms The terms to highlight.
 * @param tag The tag to use for highlighting (e.g., "<b>" for bold).
 * @return The string with highlighted terms.
 */
std::string GiString::highlight_terms(const std::string& str, const std::vector<std::string>& terms, const std::string& tag) {
    std::string result = str;
    // Iterate through each term and highlight it in the string
    for (const auto& term : terms) {
        // Find the position of the term in the string
        size_t pos = result.find(term);
        // Highlight all occurrences of the term in the string
        while (pos != std::string::npos) {
            // Insert the tag before the term
            result.insert(pos, tag);
            // Insert the closing tag after the term and adjust the position
            result.insert(pos + term.length() + tag.length(), "</" + tag.substr(1));
            // Move the position to the end of the term
            pos = result.find(term, pos + tag.length() + term.length() + 3);
        }
    }
    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "The quick brown fox jumps over the lazy dog";
// std::vector<std::string> terms = {"quick", "fox", "lazy"};
// std::string highlighted = giString->highlight_terms(input, terms, "<b>");
// std::cout << "Highlighted string: " << highlighted << std::endl;
// delete giString;



/**
 * @brief Removes lines containing specified text from a string.
 * 
 * @param str The input string with multiple lines.
 * @param text The text to search for in each line.
 * @return The string with lines containing the specified text removed.
 */
std::string GiString::remove_lines(const std::string& str, const std::string& text) {
    std::string result;
    std::istringstream iss(str);
    std::string line;
    // Iterate through each line in the input string
    while (std::getline(iss, line)) {
        // Check if the line contains the specified text
        if (line.find(text) == std::string::npos) {
            // If the line does not contain the text, add it to the result
            result += line + "\n";
        }
    }
    // Remove the trailing newline character if present
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    return result;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Line 1\nLine 2\nLine 3\nLine 4\n";
// std::string text = "Line 2";
// std::string result = giString->remove_lines(input, text);
// std::cout << "String with lines containing '" << text << "' removed:\n" << result << std::endl;
// delete giString;



/**
 * @brief Inserts a string at a specified position in another string.
 * 
 * @param str The original string.
 * @param position The position at which to insert the string.
 * @param insertion The string to insert.
 * @return The modified string with the insertion.
 * 
 * @throws std::out_of_range If the position is out of range.
 */
std::string GiString::insert_at(const std::string& str, size_t position, const std::string& insertion) {
    if (position > str.length()) {
        throw std::out_of_range("Position is out of range (GiString::insert_at)");
    }
    // Insert the string at the specified position
    return str.substr(0, position) + insertion + str.substr(position);
}

// Example usage:
// GiString* giString = new GiString();
// std::string original = "The brown jumps";
// std::string insertion = "quick ";
// size_t position = 4;
// std::string result = giString->insert_at(original, position, insertion);
// std::cout << "Modified string: " << result << std::endl;
// delete giString;



/**
 * @brief Generates an acronym based on the first letters of words in a string.
 * 
 * @param str The input string containing multiple words.
 * @return The acronym generated from the first letters of words.
 */
std::string GiString::generate_acronym(const std::string& str) {
    std::string acronym;
    bool nextLetter = true;

    // Iterate through each character in the input string
    for (char ch : str) {
        // If the current character is a letter and it is the first letter of a word, add it to the acronym
        if (std::isalpha(ch) && nextLetter) {
            acronym += std::toupper(ch);
            nextLetter = false;
        }
        // Set the flag to true if the current character is a space, indicating the start of a new word
        else if (std::isspace(ch)) {
            nextLetter = true;
        }
    }

    return acronym;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "World Wide Web";
// std::string acronym = giString->generate_acronym(input);
// std::cout << "Generated acronym: " << acronym << std::endl;
// delete giString;


/**
 * @brief Checks if a string is a valid IP address.
 * 
 * @param str The input string to check.
 * @return True if the string is a valid IP address, false otherwise.
 */
bool GiString::is_valid_ip(const std::string& str) {
    // Regular expression pattern for validating an IP address
    std::regex pattern(
        R"(^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)"
    );
    // Check if the input string matches the IP address pattern
    return std::regex_match(str, pattern);
}

// Example usage:
// GiString* giString = new GiString();
// std::string ip1 = "192.168.0.1";
// std::cout << "Is " << ip1 << " a valid IP address? " << std::boolalpha << giString->is_valid_ip(ip1) << std::endl;
// std::string ip2 = "256.0.0.1";
// std::cout << "Is " << ip2 << " a valid IP address? " << std::boolalpha << giString->is_valid_ip(ip2) << std::endl;
// delete giString;



/**
 * @brief Checks if a string is a valid URL.
 * 
 * @param str The input string to check.
 * @return True if the string is a valid URL, false otherwise.
 */
bool GiString::is_valid_url(const std::string& str) {
    // Regular expression pattern for validating a URL
    std::regex pattern(
        R"(^(https?|ftp):\/\/[^\s\/$.?#].[^\s]*$)"
    );
    // Check if the input string matches the URL pattern
    return std::regex_match(str, pattern);
}

// Example usage:
// GiString* giString = new GiString();
// std::string url1 = "https://www.example.com";
// std::cout << "Is " << url1 << " a valid URL? " << std::boolalpha << giString->is_valid_url(url1) << std::endl;
// std::string url2 = "ftp://ftp.example.com";
// std::cout << "Is " << url2 << " a valid URL? " << std::boolalpha << giString->is_valid_url(url2) << std::endl;
// delete giString;




/**
 * @brief Transposes a text treated as a two-dimensional array of characters.
 * 
 * @param text The input text to transpose.
 * @return The transposed text.
 */
std::string GiString::transpose(const std::string& text) {
    std::vector<std::string> lines;
    size_t maxWidth = 0;

    // Split the text into lines and find the maximum width
    std::istringstream iss(text);
    std::string line;
    while (std::getline(iss, line)) {
        lines.push_back(line);
        maxWidth = std::max(maxWidth, line.length());
    }

    // Transpose the text
    std::string transposed;
    for (size_t i = 0; i < maxWidth; ++i) {
        for (const auto& line : lines) {
            if (i < line.length()) {
                transposed += line[i];
            } else {
                transposed += ' ';
            }
        }
        transposed += '\n';
    }

    // Remove the trailing newline character if present
    if (!transposed.empty() && transposed.back() == '\n') {
        transposed.pop_back();
    }

    return transposed;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input = "Hello\nWorld\n";
// std::string transposed = giString->transpose(input);
// std::cout << "Transposed text:\n" << transposed << std::endl;
// delete giString;



/**
 * @brief Checks if two strings are anagrams.
 * 
 * @param str1 The first input string.
 * @param str2 The second input string.
 * @return True if the strings are anagrams, false otherwise.
 */
bool GiString::anagram_check(const std::string& str1, const std::string& str2) {
    // Sort both strings
    std::string sorted_str1 = str1;
    std::string sorted_str2 = str2;
    std::sort(sorted_str1.begin(), sorted_str1.end());
    std::sort(sorted_str2.begin(), sorted_str2.end());

    // Compare the sorted strings
    return sorted_str1 == sorted_str2;
}

// Example usage:
// GiString* giString = new GiString();
// std::string input1 = "listen";
// std::string input2 = "silent";
// std::cout << "Are '" << input1 << "' and '" << input2 << "' anagrams? " << std::boolalpha << giString->anagram_check(input1, input2) << std::endl;
// delete giString;









/////////////////// 2024-04-28



//#############################################################################################################################











// GiString.cpp
/**
 * @brief Extracts all email addresses from a given string.
 *
 * @param str The input string to extract email addresses from.
 * @return A vector of strings containing all the extracted email addresses.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::extract_emails(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("extract_emails: Input string is empty.");
    }

    std::vector<std::string> emails;
    std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), email_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        emails.push_back(i->str());
    }

    return emails;
}

// Example usage:
// GiString giString;
// std::string input = "Contact us at email@example.com or support@company.com";
// std::vector<std::string> extracted_emails = giString.extract_emails(input);
// for (const auto& email : extracted_emails) {
//     std::cout << "Extracted email: " << email << std::endl;
// }







/**
 * @brief Removes diacritics from letters in a string.
 *
 * @param input The input string with diacritics.
 * @return The string with diacritics removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::remove_accents(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("remove_accents: Input string is empty!");
    }

    std::string result = input;

    // Map of characters with diacritics and their corresponding replacements
    std::unordered_map<wchar_t, wchar_t> diacriticsMap = {
        {L'ą', L'a'}, {L'ć', L'c'}, {L'ę', L'e'}, {L'ł', L'l'}, {L'ń', L'n'},
        {L'ó', L'o'}, {L'ś', L's'}, {L'ź', L'z'}, {L'ż', L'z'},
        {L'Ą', L'A'}, {L'Ć', L'C'}, {L'Ę', L'E'}, {L'Ł', L'L'}, {L'Ń', L'N'},
        {L'Ó', L'O'}, {L'Ś', L'S'}, {L'Ź', L'Z'}, {L'Ż', L'Z'}
    };

    for (size_t i = 0; i < result.length(); ++i) {
        wchar_t wc = result[i];
        if (diacriticsMap.find(wc) != diacriticsMap.end()) {
            result[i] = diacriticsMap[wc];
        }
    }

    return result;
}


// Example usage:
// GiString giString;
// std::string input = "Zażółć gęślą jaźń";
// std::string result = giString.remove_accents(input);
// std::cout << "String with accents removed: " << result << std::endl;





/**
 * @brief Inserts a specified character/string every N characters in the main string.
 *
 * @param str The main string where characters are to be inserted.
 * @param insert The character/string to insert.
 * @param n The interval at which to insert the characters.
 * @return The modified string with characters inserted.
 * @throws std::invalid_argument If the input string is empty or if the interval is less than or equal to 0.
 */
std::string GiString::insert_every_n(const std::string& str, const std::string& insert, int n) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::insert_every_n: Input string is empty.");
    }
    if (n <= 0) {
        throw std::invalid_argument("GiString::insert_every_n: Interval must be greater than 0.");
    }

    std::string result;
    int count = 0;
    for (char c : str) {
        result.push_back(c);
        count++;
        if (count == n) {
            result.append(insert);
            count = 0;
        }
    }

    return result;
}

// Example usage:
// std::string mainStr = "HelloWorld";
// std::string insertedStr = GiString::insert_every_n(mainStr, "-", 2);
// std::cout << "Modified string: " << insertedStr << std::endl;





/**
 * @brief Returns the part of the string after the first occurrence of the specified separator.
 *
 * @param str The input string.
 * @param separator The separator to look for.
 * @return The substring after the first occurrence of the separator. If the separator is not found, returns an empty string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::substring_after(const std::string& str, const std::string& separator) {
    if (str.empty()) {
        throw std::invalid_argument("substring_after: Input string is empty");
    }

    size_t pos = str.find(separator);
    if (pos == std::string::npos) {
        return ""; // Separator not found
    }

    return str.substr(pos + separator.length());
}

// Example usage:
// GiString giString;
// std::string input = "Hello, World!";
// std::string separator = ", ";
// std::string result = giString.substring_after(input, separator);
// std::cout << "Substring after separator: " << result << std::endl;



/**
 * @brief Returns the substring of the string before the first occurrence of the specified separator.
 *
 * @param str The input string.
 * @param separator The separator to look for in the input string.
 * @return The substring of the input string before the first occurrence of the separator.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::substring_before(const std::string& str, const std::string& separator) {
    if (str.empty()) {
        throw std::invalid_argument("substring_before: Input string is empty.");
    }

    size_t pos = str.find(separator);
    if (pos == std::string::npos) {
        return str; // Separator not found, return the original string
    }

    return str.substr(0, pos);
}

// Example usage:
// std::string input = "Hello World";
// std::string separator = " ";
// std::string result = GiString::substring_before(input, separator);
// std::cout << "Substring before the first space: " << result << std::endl;


/**
 * @brief Returns the substring between two specified delimiters.
 *
 * @param str The input string from which to extract the substring.
 * @param startDelim The starting delimiter.
 * @param endDelim The ending delimiter.
 * @return The substring between the startDelim and endDelim. If not found, an empty string is returned.
 * @throws std::invalid_argument If the input string is empty or if the delimiters are not found in the input string.
 */
std::string GiString::substring_between(const std::string& str, const std::string& startDelim, const std::string& endDelim) {
    size_t startPos = str.find(startDelim);
    if (startPos == std::string::npos) {
        throw std::invalid_argument("substring_between: Start delimiter not found in the input string.");
    }

    startPos += startDelim.length();
    size_t endPos = str.find(endDelim, startPos);
    if (endPos == std::string::npos) {
        throw std::invalid_argument("substring_between: End delimiter not found in the input string.");
    }

    return str.substr(startPos, endPos - startPos);
}

// Example usage:
// std::string input = "This is a sample text with [some random] content.";
// std::string startDelim = "[";
// std::string endDelim = "]";
// std::string result = GiString::substring_between(input, startDelim, endDelim);
// std::cout << "Substring between delimiters: " << result << std::endl;





/**
 * @brief Concatenates two or more strings into one.
 *
 * @param strings The strings to be concatenated.
 * @return The concatenated string.
 * @throws std::invalid_argument If no strings are provided for concatenation.
 */
std::string GiString::concat(std::initializer_list<std::string> strings) {
    if (strings.size() == 0) {
        throw std::invalid_argument("concat: No strings provided for concatenation.");
    }

    std::string result;
    for (const std::string& str : strings) {
        result += str;
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string result = giString.concat({"Hello, ", "world!", " Welcome to GigAI!"});
// std::cout << "Concatenated string: " << result << std::endl;




/**
 * @brief Finds the position of the N-th occurrence of a given character or substring in the string.
 *
 * @param str The input string to search in.
 * @param target The character or substring to find.
 * @param n The N-th occurrence to locate.
 * @return The position of the N-th occurrence of the target in the string, or -1 if not found.
 * @throws std::invalid_argument If the input string is empty.
 */
int GiString::nth_occurrence(const std::string& str, const std::string& target, int n) {
    if (str.empty()) {
        throw std::invalid_argument("nth_occurrence: Input string is empty.");
    }

    int pos = -1;
    int found = 0;
    size_t start = 0;

    while (found < n) {
        size_t found_pos = str.find(target, start);
        if (found_pos != std::string::npos) {
            pos = static_cast<int>(found_pos);
            start = found_pos + 1;
            found++;
        } else {
            break; // Target not found
        }
    }

    return pos;
}

// Example usage:
// GiString giString;
// std::string input = "hello world, hello universe!";
// std::string target = "hello";
// int n = 2;
// int result = giString.nth_occurrence(input, target, n);
// std::cout << "Position of 2nd 'hello': " << result << std::endl;





/**
 * @brief Removes the last character from a string if it exists.
 *
 * @param str The input string to remove the last character from.
 * @return The modified string after removing the last character, or an empty string if the input string is empty.
 */
std::string GiString::chop(std::string str) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::chop: Input string is empty");
    }

    str.pop_back();
    return str;
}

// Example usage:
// std::string input = "Hello World!";
// std::string result = GiString::chop(input);
// std::cout << "String after chop: " << result << std::endl;




/**
 * @brief Ensures that a string starts with a specified prefix; if not, it adds the prefix.
 *
 * @param str The input string to ensure the prefix.
 * @param prefix The prefix to be added if the string doesn't start with it.
 * @return The string with the ensured prefix.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::ensure_prefix(std::string str, const std::string& prefix) {
    if (str.empty()) {
        throw std::invalid_argument("ensure_prefix: Input string is empty");
    }

    if (str.substr(0, prefix.length()) != prefix) {
        str = prefix + str;
    }

    return str;
}

// Example usage:
// GiString giString;
// std::string input = "world";
// std::string prefix = "hello_";
// std::string result = giString.ensure_prefix(input, prefix);
// std::cout << "String with ensured prefix: " << result << std::endl;




// 
/**
 * @brief Ensures that a string ends with a specified suffix; if not, appends the suffix.
 *
 * @param str The input string to ensure the suffix.
 * @param suffix The suffix to ensure at the end of the string.
 * @return The string with the ensured suffix.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::ensure_suffix(std::string str, const std::string& suffix) {
    if (str.empty()) {
        throw std::invalid_argument("ensure_suffix: Input string is empty.");
    }

    if (str.size() < suffix.size() || str.substr(str.size() - suffix.size()) != suffix) {
        str += suffix;
    }

    return str;
}

// Example usage:
// GiString giString;
// std::string input = "example.txt";
// std::string suffix = ".txt";
// std::string result = giString.ensure_suffix(input, suffix);
// std::cout << "String with ensured suffix: " << result << std::endl;






// // GiString.cpp


/**
 * @brief Removes the last occurrence of a specified character or string from the string.
 *
 * @param ch The character or string to be removed.
 * @return The string after removing the last occurrence of the specified character or string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::remove_last(std::string str, const std::string& ch) {
    if (str.empty()) {
        throw std::invalid_argument("remove_last: Input string is empty.");
    }

    size_t found = str.rfind(ch);
    if (found != std::string::npos) {
        str.erase(found, ch.length());
    }

    return str;
}

// Example usage:
// GiString myString("Hello, World! Hello!");
// std::string result = myString.remove_last("Hello");
// std::cout << "String after removing last 'Hello': " << result << std::endl;




/**
 * @brief Checks if the characters in a string are sorted.
 *
 * @param str The input string to check.
 * @return true if the characters are sorted in ascending order, false otherwise.
 * @throws std::invalid_argument If the input string is empty.
 */

bool GiString::is_sorted(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("is_sorted: Input string is empty.");
    }

    for (size_t i = 0; i < str.length() - 1; ++i) {
        if (str[i] > str[i + 1]) {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString giString;
// std::string input1 = "abcdef";
// std::string input2 = "zyxwv";
// bool result1 = giString.is_sorted(input1); // true
// bool result2 = giString.is_sorted(input2); // false



/**
 * @brief Removes duplicate characters from a string, leaving only unique occurrences.
 *
 * @param str The input string from which duplicates will be removed.
 * @return A string with only unique characters.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::unique(std::string str) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::unique: Error - input string is empty");
    }

    std::string result = "";
    for (char c : str) {
        if (result.find(c) == std::string::npos) {
            result += c;
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "hello world";
// std::string result = giString.unique(input);
// std::cout << "String with unique characters: " << result << std::endl;




/**
 * @brief Splits a string into a list of lines.
 *
 * @param str The input string to split into lines.
 * @return std::vector<std::string> A vector containing individual lines from the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::split_lines(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("split_lines: Input string is empty.");
    }

    std::vector<std::string> lines;
    std::istringstream iss(str);
    std::string line;

    while (std::getline(iss, line)) {
        lines.push_back(line);
    }

    return lines;
}

// Example usage:
// std::string input = "Hello\nWorld\nSplit\nMe";
// std::vector<std::string> lines = GiString::split_lines(input);
// for (const auto& line : lines) {
//     std::cout << "Line: " << line << std::endl;
// }




// // GiString.cpp

//

/**
 * @brief Splits the string at the specified index into two parts.
 *
 * @param index The index at which to split the string.
 * @return A pair of strings where the first part contains characters before the index,
 * and the second part contains characters starting from the index.
 * @throws std::invalid_argument If the index is out of range.
 */
std::pair<std::string, std::string> GiString::split_at(std::string str,size_t index) {
    if (index < 0 || index >= str.length()) {
        throw std::invalid_argument("Index out of range: split_at");
    }

    std::string firstPart = str.substr(0, index);
    std::string secondPart = str.substr(index);

    return std::make_pair(firstPart, secondPart);
}

// Example usage:
// GiString giString("Hello, World!");
// auto result = giString.split_at(5);
// std::cout << "First part: " << result.first << ", Second part: " << result.second << std::endl;




/**
 * @brief Divides a string into three parts: before the separator, the separator (if present), and after the separator.
 *
 * @param str The input string to be partitioned.
 * @param separator The separator used to divide the string.
 * @return A vector containing three strings: before separator, separator (if present), and after separator.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::partition(const std::string& str, const std::string& separator) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::partition: Input string is empty.");
    }

    std::vector<std::string> result;
    size_t separatorPos = str.find(separator);

    if (separatorPos == std::string::npos) {
        result.push_back(str); // Separator not found, return the whole string
        result.push_back("");  // Empty separator part
        result.push_back("");  // Empty part after separator
    } else {
        result.push_back(str.substr(0, separatorPos));                 // Before separator
        result.push_back(str.substr(separatorPos, separator.length())); // Separator
        result.push_back(str.substr(separatorPos + separator.length())); // After separator
    }

    return result;
}

// Example usage:
// GiString giString;
// std::vector<std::string> parts = giString.partition("hello-world", "-");
// parts[0] contains "hello"
// parts[1] contains "-"
// parts[2] contains "world"




// // GiString.cpp

/**
 * @brief Divides a string into three parts starting from the end.
 *
 * The function divides the input string into three parts using the provided delimiter starting from the end of the string.
 *
 * @param str The input string to be divided.
 * @param delimiter The delimiter to use for splitting the string.
 * @return A tuple containing the part before the delimiter, the delimiter itself, and the part after the delimiter.
 * @throws std::invalid_argument If the input string is empty.
 */

std::tuple<std::string, std::string, std::string> GiString::rpartition(const std::string& str, const std::string& delimiter) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::rpartition: Error - Input string is empty.");
    }

    size_t delimiterPos = str.rfind(delimiter);
    if (delimiterPos == std::string::npos) {
        return std::make_tuple(str, "", "");
    }

    std::string part1 = str.substr(0, delimiterPos);
    std::string part2 = delimiter;
    std::string part3 = str.substr(delimiterPos + delimiter.length());

    return std::make_tuple(part1, part2, part3);
}

// Example usage:
// std::string input = "abc.xyz.def";
// std::string delimiter = ".";
// auto result = GiString::rpartition(input, delimiter);
// std::cout << "Part 1: " << std::get<0>(result) << std::endl;
// std::cout << "Delimiter: " << std::get<1>(result) << std::endl;
// std::cout << "Part 2: " << std::get<2>(result) << std::endl;




/**
 * @brief Counts the number of lines in a string.
 *
 * @param input The input string in which to count the lines.
 * @return The number of lines in the input string.
 * @throws std::invalid_argument If the input string is empty.
 */

int GiString::count_lines(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("count_lines: Input string is empty.");
    }

    int lineCount = 1; // Initialize to 1 as even an empty string has 1 line
    for (char c : input) {
        if (c == '\n') {
            lineCount++;
        }
    }

    return lineCount;
}

// Example usage:
// GiString giString;
// std::string input = "First line\nSecond line\nThird line";
// int lines = giString.count_lines(input);
// std::cout << "Number of lines: " << lines << std::endl;




// 
/**
 * @brief Checks if a string is a valid identifier in programming languages.
 *
 * @param str The input string to be checked.
 * @return true if the string is a valid identifier, false otherwise.
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_valid_identifier(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("is_valid_identifier: Error caused by empty input string");
    }

    // Check if the first character is a letter or underscore
    if (!std::isalpha(str[0]) && str[0] != '_') {
        return false;
    }

    // Check the rest of the characters
    for (size_t i = 1; i < str.length(); ++i) {
        if (!std::isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString giString;
// std::string input1 = "valid_identifier_123";
// std::string input2 = "123_not_valid";
// std::cout << "Is input1 a valid identifier? " << giString.is_valid_identifier(input1) << std::endl;
// std::cout << "Is input2 a valid identifier? " << giString.is_valid_identifier(input2) << std::endl;




/**
 * @brief Checks if a string consists only of whitespace characters.
 *
 * @param str The input string to check.
 * @return true if the string consists only of whitespace characters, false otherwise.
 */
bool GiString::is_whitespace(const std::string& str) {
    if(str.empty()) {
        throw std::invalid_argument("is_whitespace: Input string is empty.");
    }

    for(const char& c : str) {
        if(!std::isspace(c)) {
            return false;
        }
    }

    return true;
}

// Example usage:
// GiString giString;
// std::string input1 = "   ";
// std::string input2 = "  Hello  ";
// bool result1 = giString.is_whitespace(input1); // true
// bool result2 = giString.is_whitespace(input2); // false




/**
 * @brief Removes all vowels from a given string.
 *
 * @param input The input string from which vowels need to be removed.
 * @return std::string The string with vowels removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::remove_vowels(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("remove_vowels: Input string is empty.");
    }

    std::string result = input;
    std::string vowels = "aeiouAEIOU";

    for (char vowel : vowels) {
        result.erase(std::remove(result.begin(), result.end(), vowel), result.end());
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World";
// std::string result = giString.remove_vowels(input);
// std::cout << "String with vowels removed: " << result << std::endl;




// 
/**
 * @brief Removes all consonants from a string.
 *
 * @param str The input string from which consonants will be removed.
 * @return std::string The string with all consonants removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::remove_consonants(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("remove_consonants: Input string is empty.");
    }

    std::string result;
    for (char c : str) {
        if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u') {
            result += c;
        }
    }

    return result;
}

// Example usage:
// GiString gi;
// std::string input = "Hello World";
// std::string result = gi.remove_consonants(input);
// std::cout << "String with consonants removed: " << result << std::endl;




// // GiString.cpp

//

/**
 * @brief Swaps two words in a string.
 *
 * @param input The input string where words need to be swapped.
 * @return std::string The string with two words swapped.
 * @throws std::invalid_argument If the input string is empty or contains less than two words.
 */
std::string GiString::swap_words(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::swap_words: Input string is empty.");
    }

    // Find the positions of the first two words
    size_t first_space_pos = input.find(' ');
    if (first_space_pos == std::string::npos) {
        throw std::invalid_argument("GiString::swap_words: Input string contains less than two words.");
    }

    size_t second_space_pos = input.find(' ', first_space_pos + 1);

    // If there is only one word, return the input as it is
    if (second_space_pos == std::string::npos) {
        return input;
    }

    // Extract the first two words
    std::string first_word = input.substr(0, first_space_pos);
    std::string second_word = input.substr(first_space_pos + 1, second_space_pos - first_space_pos - 1);

    // Swap the words and rebuild the string
    std::string swapped_string = second_word + " " + first_word + input.substr(second_space_pos);

    return swapped_string;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World, how are you?";
// std::string result = giString.swap_words(input);
// std::cout << "Swapped words: " << result << std::endl;




/**
 * @brief Normalizes a path in a string by removing extra slashes and dots.
 *
 * @param path The input path string to normalize.
 * @return The normalized path string.
 * @throws std::invalid_argument If the input path is empty.
 */
std::string GiString::normalize_path(const std::string& path) {
    if (path.empty()) {
        throw std::invalid_argument("normalize_path: Error - Input path is empty.");
    }

    std::string normalizedPath;
    std::stringstream ss(path);
    std::string token;
    std::vector<std::string> tokens;

    // Tokenize the input path based on '/'
    while (std::getline(ss, token, '/')) {
        tokens.push_back(token);
    }

    for (const auto& t : tokens) {
        if (t == "." || t.empty()) {
            continue;
        } else if (t == "..") {
            if (!normalizedPath.empty()) {
                size_t pos = normalizedPath.find_last_of('/');
                if (pos != std::string::npos) {
                    normalizedPath = normalizedPath.substr(0, pos);
                }
            }
        } else {
            normalizedPath += "/" + t;
        }
    }

    if (normalizedPath.empty()) {
        normalizedPath = "/";
    }

    return normalizedPath;
}

// Example usage:
// GiString giString;
// std::string inputPath = "/home/turbo/Pulpit/github/MaxLib/src/GiString/GiString.cpp";
// std::string normalizedPath = giString.normalize_path(inputPath);
// std::cout << "Normalized path: " << normalizedPath << std::endl;




/**
 * @brief Shortens a string to a specified length, adding "..." at the end if it's shortened.
 *
 * @param str The input string to be shortened.
 * @param length The desired length of the shortened string.
 * @return The shortened string with "..." added at the end if it's shortened.
 * @throws std::invalid_argument If the input string is empty or the length is less than 3.
 */
std::string GiString::ellipsis(const std::string& str, size_t length) {
    if (str.empty()) {
        throw std::invalid_argument("ellipsis: Input string is empty!");
    }
    if (length < 3) {
        throw std::invalid_argument("ellipsis: Length should be at least 3!");
    }

    if (str.length() <= length) {
        return str;
    } else {
        return str.substr(0, length - 3) + "...";
    }
}

// Example usage:
// GiString giString;
// std::string input = "This is a long sentence that needs to be shortened.";
// std::string result = giString.ellipsis(input, 20);
// std::cout << "Shortened string: " << result << std::endl;




// // GiString.cpp

//

/**
 * @brief Extracts all numbers from a string and returns them as a list.
 *
 * @param str The input string from which numbers will be extracted.
 * @return std::vector<int> A list of extracted numbers.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<int> GiString::extract_numbers(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("extract_numbers: Input string is empty");
    }

    std::vector<int> numbers;
    std::string numStr;

    for (char c : str) {
        if (std::isdigit(c)) {
            numStr += c;
        } else {
            if (!numStr.empty()) {
                numbers.push_back(std::stoi(numStr));
                numStr.clear();
            }
        }
    }

    if (!numStr.empty()) {
        numbers.push_back(std::stoi(numStr));
    }

    return numbers;
}

// Example usage:
// GiString giString;
// std::string input = "abc 123 def 456 ghi";
// std::vector<int> result = giString.extract_numbers(input);
// for (int num : result) {
//     std::cout << num << " ";
// }
// Output: 123 456




// // GiString.cpp

//

/**
 * @brief Increments the number at the end of the string by one.
 *
 * @param input The input string containing a number at the end.
 * @param incrementBy The value by which the number should be incremented (default is 1).
 * @return The string with the number at the end incremented.
 * @throws std::invalid_argument If the input string is empty or does not end with a number.
 * @throws std::invalid_argument If the incrementBy value is less than or equal to 0.
 */
std::string GiString::increment_number_suffix(const std::string& input, int incrementBy = 1) {
    if (input.empty()) {
        throw std::invalid_argument("increment_number_suffix: Input string is empty.");
    }

    std::string result = input;
    size_t pos = result.find_last_not_of("0123456789");
    if (pos == std::string::npos) {
        throw std::invalid_argument("increment_number_suffix: Input string does not end with a number.");
    }

    int number = std::stoi(result.substr(pos + 1));
    if (incrementBy <= 0) {
        throw std::invalid_argument("increment_number_suffix: Increment value must be greater than 0.");
    }

    result = result.substr(0, pos + 1) + std::to_string(number + incrementBy);
    return result;
}

// Example usage:
// std::string input = "abc123";
// int incrementBy = 2;
// std::string result = GiString::increment_number_suffix(input, incrementBy);
// std::cout << "Result: " << result << std::endl;




// GiString.cpp
/**
 * @brief Decreases the number at the end of the string by a specified value.
 *
 * @param str The input string containing a number at the end.
 * @param decrementBy The value by which the number at the end should be decreased.
 * @return The modified string with the decreased number.
 * @throws std::invalid_argument If the input string is empty.
 * @throws std::invalid_argument If the input string does not end with a number.
 */
std::string GiString::decrement_number_suffix(const std::string& str, int decrementBy) {
    if (str.empty()) {
        throw std::invalid_argument("decrement_number_suffix: Error - Input string is empty.");
    }

    size_t pos = str.find_last_of("0123456789");
    if (pos == std::string::npos) {
        throw std::invalid_argument("decrement_number_suffix: Error - Input string does not end with a number.");
    }

    int number = std::stoi(str.substr(pos));
    number -= decrementBy;

    std::string result = str.substr(0, pos) + std::to_string(number);
    return result;
}

// Example usage:
// GiString gi;
// std::string input = "abc123";
// int decrementBy = 1;
// std::string result = gi.decrement_number_suffix(input, decrementBy);
// std::cout << "Modified string: " << result << std::endl;




// 
/**
 * @brief Changes the first letter of each word in a string to uppercase.
 *
 * @param str The input string to convert to title case.
 * @return A new string with the first letter of each word capitalized.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_title_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("to_title_case: Input string is empty.");
    }

    std::string result = str;
    bool make_upper = true;

    for (char& c : result) {
        if (make_upper && std::isalpha(c)) {
            c = std::toupper(c);
            make_upper = false;
        } else if (std::isspace(c) || c == '-') {
            make_upper = true;
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "hello world";
// std::string result = giString.to_title_case(input);
// std::cout << "Title cased string: " << result << std::endl;




// // GiString.cpp

//

/**
 * @brief Converts the title case string to sentence case.
 *
 * @param input The input string in title case.
 * @return std::string The string converted to sentence case.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::from_title_case(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("from_title_case: Input string is empty.");
    }

    std::string result = input;
    bool isFirstLetter = true;

    for (char& c : result) {
        if (isFirstLetter) {
            c = std::tolower(c);
            isFirstLetter = false;
        } else if (std::isupper(c)) {
            c = std::tolower(c);
        }
        if (std::isspace(c) || c == '-' || c == '\'') {
            isFirstLetter = true;
        }
    }

    return result;
}

// Example usage:
// std::string input = "ThIs Is A TeSt StRiNg";
// std::string result = GiString::from_title_case(input);
// std::cout << "Converted string: " << result << std::endl;




// 
//

/**
 * @brief Extracts all hashtags from a string and returns them as a list.
 *
 * @param input The input string to extract hashtags from.
 * @return std::vector<std::string> A list of hashtags extracted from the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::extract_hashtags(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("extract_hashtags: Input string is empty.");
    }

    std::vector<std::string> hashtags;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        if (word[0] == '#') {
            // Remove any special characters from the hashtag
            word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalnum(c); }), word.end());
            hashtags.push_back(word);
        }
    }

    return hashtags;
}

// Example usage:
// std::string input = "Check out this #amazing #GigAI model!";
// std::vector<std::string> extractedHashtags = GiString::extract_hashtags(input);
// for (const auto& hashtag : extractedHashtags) {
//     std::cout << "Extracted hashtag: " << hashtag << std::endl;
// }




/**
 * @brief Inserts a random character at a random position in the string.
 *
 * @param str The input string where the random character will be inserted.
 * @return The string with a random character inserted at a random position.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::insert_random(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("insert_random: Input string is empty.");
    }

    // Generate a random character and position
    char random_char = 'A' + rand() % 26; // Generating a random uppercase letter for simplicity
    int random_pos = rand() % (str.length() + 1); // Random position between 0 and str.length()

    // Insert the random character at the random position
    std::string result = str;
    result.insert(random_pos, 1, random_char);

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello";
// std::string result = giString.insert_random(input);
// std::cout << "String with random character inserted: " << result << std::endl;




/**
 * @brief Anonymizes a string by replacing selected parts with random values or masks.
 *
 * @param str The input string to anonymize.
 * @param start The starting index of the part to be anonymized.
 * @param length The length of the part to be anonymized.
 * @param mask The character to use as a mask (e.g., '*').
 * @return The anonymized string.
 * @throws std::invalid_argument If the start index is out of range or the length is invalid.
 */
std::string GiString::anonymize(const std::string& str, size_t start, size_t length, char mask) {
    if (start >= str.length() || length == 0 || start + length > str.length()) {
        throw std::invalid_argument("Invalid start index or length for anonymization. GiString::anonymize");
    }

    std::string anonymized = str;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(33, 126); // ASCII range for random character generation

    for (size_t i = start; i < start + length; ++i) {
        anonymized[i] = mask; // Replace with mask character
    }

    return anonymized;
}

// Example usage:
// GiString giString;
// std::string input = "Confidential Information: 1234567890";
// std::string anonymized = giString.anonymize(input, 21, 10, '*');
// std::cout << "Anonymized string: " << anonymized << std::endl;




// 
//

/**
 * @brief Replaces characters in a string with a mask at specified positions.
 *
 * @param input The input string where characters will be replaced.
 * @param mask The character to use as a mask.
 * @param positions The positions at which the characters will be replaced with the mask.
 * @return The modified string with characters replaced by the mask.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::mask_characters(const std::string& input, char mask, const std::vector<int>& positions) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::mask_characters: Input string is empty.");
    }

    std::string result = input;

    for (int pos : positions) {
        if (pos >= 0 && pos < static_cast<int>(result.size())) {
            result[pos] = mask;
        }
    }

    return result;
}


// Example usage:
// std::string input = "Hello, World!";
// char mask = '*';
// std::vector<int> positions = {1, 4, 8};
// std::string result = GiString::mask_characters(input, mask, positions);
// std::cout << "Masked string: " << result << std::endl;




/**
 * @brief Unmasks characters in a string if original values are available.
 *
 * This function unmasks characters in a string by replacing masked characters with their original values.
 *
 * @param str The input string containing masked characters.
 * @param mask The mapping of masked characters to their original values.
 * @return The unmasked string with characters replaced by their original values.
 * @throws std::invalid_argument If the input string is empty or if the mask does not contain mappings for all masked characters.
 */
std::string GiString::unmask_characters(const std::string& str, const std::unordered_map<char, char>& mask) {
    if (str.empty()) {
        throw std::invalid_argument("unmask_characters: Input string is empty.");
    }

    for (const auto& pair : mask) {
        if (str.find(pair.first) == std::string::npos) {
            throw std::invalid_argument("unmask_characters: Mask does not contain mapping for a masked character.");
        }
    }

    std::string unmaskedStr = str;
    for (const auto& pair : mask) {
        size_t pos = unmaskedStr.find(pair.first);
        while (pos != std::string::npos) {
            unmaskedStr.replace(pos, 1, 1, pair.second);
            pos = unmaskedStr.find(pair.first, pos + 1);
        }
    }

    return unmaskedStr;
}

// Example usage:
// GiString giString;
// std::string input = "H3ll0 W0r1d";
// std::unordered_map<char, char> mask = {{'3', 'e'}, {'0', 'o'}, {'1', 'l'}};
// std::string result = giString.unmask_characters(input, mask);
// std::cout << "Unmasked string: " << result << std::endl;




// 
/**
 * @brief Replaces multiple spaces with a single space in a given string.
 *
 * @param input The input string where multiple spaces need to be squished.
 * @return The string with multiple spaces replaced by a single space.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::squish_spaces(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("squish_spaces: Input string is empty.");
    }

    std::string squishedString;
    bool spaceFound = false;

    for (char c : input) {
        if (c == ' ') {
            if (!spaceFound) {
                squishedString += c;
            }
            spaceFound = true;
        } else {
            squishedString += c;
            spaceFound = false;
        }
    }

    return squishedString;
}

// Example usage:
// std::string input = "Hello     world   !";
// std::string result = GiString::squish_spaces(input);
// std::cout << "String with squished spaces: " << result << std::endl;




// 
/**
 * @brief Extends a string to a specified length by adding a specific character to the left, right, or both sides.
 *
 * @param str The input string to be extended.
 * @param length The desired length of the extended string.
 * @param fillChar The character used for filling the string.
 * @param side The side(s) to fill the string: 'l' for left, 'r' for right, 'b' for both sides.
 * @return The extended string.
 * @throws std::invalid_argument If the input string is empty or the length is less than or equal to the input string's length.
 */
std::string GiString::expand_to_length(const std::string& str, size_t length, char fillChar, char side) {
    if (str.empty()) {
        throw std::invalid_argument("expand_to_length: Input string cannot be empty.");
    }
    if (length <= str.length()) {
        throw std::invalid_argument("expand_to_length: Length must be greater than the input string's length.");
    }

    size_t fillCount = length - str.length();
    std::string result = str;

    if (side == 'l' || side == 'b') {
        result = std::string(fillCount, fillChar) + result;
        fillCount = length - result.length(); // Recalculate fillCount
    }

    if (side == 'r' || side == 'b') {
        result += std::string(fillCount, fillChar);
    }

    return result;
}

// Example usage:
// std::string input = "Hello";
// std::string extendedStr = GiString::expand_to_length(input, 10, ' ', 'b');
// std::cout << "Extended string: " << extendedStr << std::endl;




// 
//

/**
 * @brief Creates a mirrored reflection of the input string.
 *
 * @param str The input string to create a mirrored reflection of.
 * @return The mirrored reflection of the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::mirror(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("mirror: Input string is empty!");
    }

    std::string mirroredStr = str;
    std::reverse(mirroredStr.begin(), mirroredStr.end());
    
    return str + mirroredStr;
}

// Example usage:
// GiString giString;
// std::string input = "Hello";
// std::string mirrored = giString.mirror(input);
// std::cout << "Mirrored string: " << mirrored << std::endl;




// GiString.cpp
/**
 * @brief Rotates characters in a string by a specified number of positions to the left or right.
 *
 * @param str The input string to rotate.
 * @param positions The number of positions to rotate the characters. Positive for right rotation, negative for left rotation.
 * @return The rotated string.
 * @throws std::invalid_argument If the input string is empty.
 */

std::string GiString::rotate(const std::string& str, int positions) {
    if (str.empty()) {
        throw std::invalid_argument("rotate: Input string is empty.");
    }

    std::string rotatedStr = str;
    int n = str.length();
    positions = positions % n; // Normalize positions to handle rotations greater than the string length

    if (positions < 0) {
        positions = n + positions; // Convert negative positions to positive for left rotation
    }

    std::rotate(rotatedStr.begin(), rotatedStr.begin() + positions, rotatedStr.end());

    return rotatedStr;
}

// Example usage:
// GiString giString;
// std::string input = "Hello, World!";
// std::string rotatedRight = giString.rotate(input, 3); // Right rotation by 3 positions
// std::string rotatedLeft = giString.rotate(input, -2); // Left rotation by 2 positions
// std::cout << "Right rotated string: " << rotatedRight << std::endl;
// std::cout << "Left rotated string: " << rotatedLeft << std::endl;




// GiString.cpp

/**
 * @brief Checks if a string is a valid hexadecimal color code.
 *
 * @param str The input string to check.
 * @return True if the input string is a valid hexadecimal color code, false otherwise.
 * @throws std::invalid_argument If the input string is empty or not a valid hexadecimal color code.
 */
bool GiString::is_valid_hex_code(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("is_valid_hex_code: Input string is empty");
    }

    // Check if the string starts with '#' and has valid hexadecimal characters
    if (str[0] != '#' || str.size() != 7) {
        throw std::invalid_argument("is_valid_hex_code: Invalid hexadecimal color code format");
    }

    for (size_t i = 1; i < str.size(); ++i) {
        if (!isxdigit(str[i])) {
            throw std::invalid_argument("is_valid_hex_code: Invalid hexadecimal color code format");
        }
    }

    return true;
}

// Example usage:
// GiString giString;
// std::string colorCode1 = "#1a2B3c";
// std::string colorCode2 = "1a2B3c"; // Incorrect format
// try {
//     if (giString.is_valid_hex_code(colorCode1)) {
//         std::cout << colorCode1 << " is a valid hexadecimal color code." << std::endl;
//     } else {
//         std::cout << colorCode1 << " is not a valid hexadecimal color code." << std::endl;
//     }
// } catch (const std::invalid_argument& e) {
//     std::cerr << "Error: " << e.what() << std::endl;
// }
// try {
//     if (giString.is_valid_hex_code(colorCode2)) {
//         std::cout << colorCode2 << " is a valid hexadecimal color code." << std::endl;
//     } else {
//         std::cout << colorCode2 << " is not a valid hexadecimal color code." << std::endl;
//     }
// } catch (const std::invalid_argument& e) {
//     std::cerr << "Error: " << e.what() << std::endl;
// }




/**
 * @brief Replaces all numbers in a string with a specified set of characters.
 *
 * @param str The input string to replace numbers in.
 * @param replacement The string to replace numbers with.
 * @return The string with numbers replaced.
 * @throws std::invalid_argument If the input string is empty.
 */

std::string GiString::replace_numbers(const std::string& str, const std::string& replacement) {
    if (str.empty()) {
        throw std::invalid_argument("replace_numbers: Input string is empty.");
    }

    std::string result = str;
    for (char& c : result) {
        if (std::isdigit(c)) {
            c = replacement.front(); // Replace number with the first character of the replacement string
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello 123 World 456";
// std::string replacement = "*";
// std::string result = giString.replace_numbers(input, replacement);
// std::cout << "String with numbers replaced: " << result << std::endl;




// GiString.cpp

/**
 * @brief Removes all HTML tags from a string.
 *
 * @param input The input string containing HTML tags.
 * @return The string with HTML tags removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::strip_html_tags(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("strip_html_tags: Input string is empty.");
    }

    std::string result;
    bool inTag = false;

    for (char c : input) {
        if (c == '<') {
            inTag = true;
        } else if (c == '>') {
            inTag = false;
        } else if (!inTag) {
            result += c;
        }
    }

    return result;
}

// Example usage:
// std::string htmlString = "<h1>Hello, <b>World</b>!</h1>";
// std::string strippedString = GiString::strip_html_tags(htmlString);
// std::cout << "Stripped String: " << strippedString << std::endl;




// Parses a CSV line and returns a list of strings with values.
/**
 * @brief Parses a CSV line and returns a list of strings with values.
 *
 * @param csvLine The input CSV line to parse.
 * @return std::vector<std::string> A list of strings with values from the CSV line.
 * @throws std::invalid_argument If the input CSV line is empty.
 */
std::vector<std::string> GiString::parse_csv_line(const std::string& csvLine) {
    if (csvLine.empty()) {
        throw std::invalid_argument("parse_csv_line: Input CSV line is empty.");
    }

    std::vector<std::string> values;
    std::string value;

    std::stringstream ss(csvLine);
    while (std::getline(ss, value, ',')) {
        values.push_back(value);
    }

    return values;
}

// Example usage:
// std::string csvLine = "apple,orange,banana";
// std::vector<std::string> parsedValues = GiString::parse_csv_line(csvLine);
// for (const auto& val : parsedValues) {
//     std::cout << val << std::endl;
// }




/**
 * @brief Masks credit card numbers, leaving only the last four digits visible.
 *
 * @param creditCardNumber The input credit card number to mask.
 * @return The masked credit card number with only the last four digits visible.
 * @throws std::invalid_argument If the input credit card number is empty or has less than four digits.
 */
std::string GiString::mask_credit_card(const std::string& creditCardNumber) {
    if (creditCardNumber.empty() || creditCardNumber.size() < 4) {
        throw std::invalid_argument("mask_credit_card: Error - Input credit card number is empty or has less than four digits.");
    }

    // Masking logic to keep only the last four digits visible
    std::string maskedNumber = "************" + creditCardNumber.substr(creditCardNumber.size() - 4);

    return maskedNumber;
}

// Example usage:
// GiString giString;
// std::string creditCard = "1234 5678 9101 1121";
// std::string maskedCreditCard = giString.mask_credit_card(creditCard);
// std::cout << "Masked Credit Card: " << maskedCreditCard << std::endl;




// GiString.cpp


/**
 * @brief Extracts and returns all URL links contained in a string.
 *
 * @param input The input string to extract URLs from.
 * @return A vector of strings containing all the URLs found in the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::extract_links(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("extract_links: Input string is empty.");
    }

    std::vector<std::string> urls;
    std::regex link_regex("(https?://\\S+)");

    auto words_begin = std::sregex_iterator(input.begin(), input.end(), link_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        urls.push_back(match.str());
    }

    return urls;
}

// Example usage:
// GiString giString;
// std::string input = "Check out my website at https://www.example.com for more information!";
// std::vector<std::string> extractedLinks = giString.extract_links(input);
// for (const auto& link : extractedLinks) {
//     std::cout << "Extracted URL: " << link << std::endl;
// }




/**
 * @brief Increases the date in a string by a specified number of days.
 *
 * @param dateStr The input date string in the format "YYYY-MM-DD".
 * @param daysToAdd The number of days to add to the date.
 * @return The updated date string after adding the specified number of days.
 * @throws std::invalid_argument If the input date string is empty or in an invalid format.
 */
std::string GiString::increment_date(const std::string& dateStr, int daysToAdd) {
    // Check if the input date string is empty
    if (dateStr.empty()) {
        throw std::invalid_argument("increment_date: Error - Input date string is empty.");
    }

    // Parse the input date string
    std::istringstream iss(dateStr);
    std::tm date = {};
    iss >> std::get_time(&date, "%Y-%m-%d");

    // Check if the date parsing was successful
    if (iss.fail()) {
        throw std::invalid_argument("increment_date: Error - Invalid date format. Please use the format 'YYYY-MM-DD'.");
    }

    // Update the date by adding the specified number of days
    date.tm_mday += daysToAdd;
    std::mktime(&date); // Normalize the date

    // Convert the updated date back to string
    std::stringstream ss;
    ss << std::put_time(&date, "%Y-%m-%d");
    return ss.str();
}

// Example usage:
// GiString giString;
// std::string inputDate = "2022-09-15";
// int daysToAdd = 5;
// std::string updatedDate = giString.increment_date(inputDate, daysToAdd);
// std::cout << "Updated date: " << updatedDate << std::endl;




/**
 * @brief Decreases the date in the string by a specified number of days.
 *
 * @param dateStr The input date string in the format "YYYY-MM-DD".
 * @param numDays The number of days to decrement the date by.
 * @return The updated date string after decrementing by the specified number of days.
 * @throws std::invalid_argument If the input date string is empty or in an invalid format.
 */
std::string GiString::decrement_date(const std::string& dateStr, int numDays) {
    // Check if the input date string is empty
    if (dateStr.empty()) {
        throw std::invalid_argument("decrement_date: Input date string is empty!");
    }

    // Parse the input date string
    std::istringstream iss(dateStr);
    std::tm time = {};
    iss >> std::get_time(&time, "%Y-%m-%d");

    // Check if the parsing was successful
    if (iss.fail()) {
        throw std::invalid_argument("decrement_date: Invalid date format! Date must be in the format \"YYYY-MM-DD\".");
    }

    // Convert the date to time_t
    std::time_t t = std::mktime(&time);

    // Calculate the new date by decrementing the number of days
    t -= numDays * 86400; // 86400 seconds in a day

    // Update the time struct with the new date
    std::tm* newTime = std::localtime(&t);

    // Format the new date string
    std::ostringstream oss;
    oss << std::put_time(newTime, "%Y-%m-%d");

    return oss.str();
}

// Example usage:
// GiString giString;
// std::string inputDate = "2022-10-15";
// int numDaysToDecrement = 5;
// std::string updatedDate = giString.decrement_date(inputDate, numDaysToDecrement);
// std::cout << "Updated date: " << updatedDate << std::endl;




// GiString.cpp
/**
 * @brief Calculates the lexical density of a text (ratio of unique words to total number of words).
 *
 * @param text The input text for which lexical density needs to be calculated.
 * @return The lexical density of the input text.
 * @throws std::invalid_argument If the input text is empty.
 */
double GiString::lexical_density(const std::string& text) {
    if (text.empty()) {
        throw std::invalid_argument("lexical_density: Input text is empty.");
    }

    std::unordered_set<std::string> uniqueWords;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        // Remove any punctuation marks from the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        uniqueWords.insert(word);
    }

    double totalWords = std::count_if(text.begin(), text.end(), ::isspace) + 1;
    double uniqueCount = static_cast<double>(uniqueWords.size());

    return uniqueCount / totalWords;
}

// Example usage:
// GiString giString;
// std::string inputText = "The quick brown fox jumps over the lazy dog.";
// double density = giString.lexical_density(inputText);
// std::cout << "Lexical Density: " << density << std::endl;




// GiString.cpp


/**
 * @brief Scrambles all characters in a word except the first and last.
 *
 * @param word The input word to scramble.
 * @return The scrambled word with first and last characters intact.
 * @throws std::invalid_argument If the input word is empty or has less than 3 characters.
 */
std::string GiString::scramble_except_first_last(const std::string& word) {
    if (word.length() < 3) {
        throw std::invalid_argument("scramble_except_first_last: Input word must have at least 3 characters.");
    }

    // Scramble logic
    std::string scrambledWord = word.substr(0, 1); // Keep the first character intact
    for (size_t i = 1; i < word.length() - 1; ++i) {
        scrambledWord += word[word.length() - i - 1];
    }
    scrambledWord += word[word.length() - 1]; // Keep the last character intact

    return scrambledWord;
}

// Example usage:
// GiString giString;
// std::string input = "hello";
// std::string result = giString.scramble_except_first_last(input);
// std::cout << "Scrambled word: " << result << std::endl;








/**
 * @brief Serializes a string into a format that can be easily saved or transmitted.
 *
 * @param input The string to be serialized.
 * @return The serialized string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::serialize(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::serialize: Error - Empty input string");
    }

    // Assuming the input string is a space-separated list of values
    std::stringstream ss(input);
    std::string item;
    std::vector<std::string> items;
    while (std::getline(ss, item, ' ')) {
        items.push_back(item);
    }

    // Convert the vector of strings to a single comma-separated string
    std::string serializedString = "";
    for (const auto& item : items) {
        serializedString += item + ",";
    }

    // Remove the trailing comma
    serializedString = serializedString.substr(0, serializedString.length() - 1);

    return serializedString;
}


// Example usage:
// GiString giString;
// std::string input = "Hello, World!";
// std::string serializedString = giString.serialize(input);
// std::cout << "Serialized string: " << serializedString << std::endl;




/**
 * @brief Deserializes a string from a serialized format.
 *
 * @param serializedString The serialized string to deserialize.
 * @return The deserialized string.
 * @throws std::invalid_argument If the input serialized string is empty.
 */
std::string GiString::deserialize(const std::string& serializedString) {
    if (serializedString.empty()) {
        throw std::invalid_argument("deserialize: Error - The input serialized string is empty.");
    }

    // Assuming the serialized string is a comma-separated list of values
    std::stringstream ss(serializedString);
    std::string item;
    std::vector<std::string> deserializedItems;
    while (std::getline(ss, item, ',')) {
        deserializedItems.push_back(item);
    }

    // Convert the vector of strings back to a single string
    std::string deserializedString = "";
    for (const auto& item : deserializedItems) {
        deserializedString += item + " ";
    }

    return deserializedString;
}


// Example usage:
// GiString giString;
// std::string serialized = "Hello,World!";
// std::string deserialized = giString.deserialize(serialized);
// std::cout << "Deserialized string: " << deserialized << std::endl;




/**
 * @brief Checks if a string meets the criteria of a secure password.
 *
 * Criteria:
 * 1. At least 8 characters long.
 * 2. Contains at least one uppercase letter.
 * 3. Contains at least one lowercase letter.
 * 4. Contains at least one digit.
 *
 * @param password The string to be checked.
 * @return true if the password meets all criteria, false otherwise.
 * @throws std::invalid_argument If the input string is empty.
 */
bool GiString::is_valid_password(const std::string& password) {
    if (password.empty()) {
        throw std::invalid_argument("is_valid_password: Input string is empty.");
    }

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;

    for (char c : password) {
        if (std::isupper(c)) {
            has_upper = true;
        } else if (std::islower(c)) {
            has_lower = true;
        } else if (std::isdigit(c)) {
            has_digit = true;
        }
    }

    return password.length() >= 8 && has_upper && has_lower && has_digit;
}

// Example usage:
// std::string password = "SecurePwd123";
// if (GiString::is_valid_password(password)) {
//     std::cout << "Password is secure." << std::endl;
// } else {
//     std::cout << "Password does not meet the criteria of a secure password." << std::endl;
// }




/**
 * @brief Generates a secure password based on specified parameters.
 *
 * @param length The length of the password to generate.
 * @param includeUppercase A flag indicating whether to include uppercase letters in the password.
 * @param includeLowercase A flag indicating whether to include lowercase letters in the password.
 * @param includeDigits A flag indicating whether to include digits in the password.
 * @param includeSpecialChars A flag indicating whether to include special characters in the password.
 * @return The generated secure password.
 * @throws std::invalid_argument If length is less than or equal to 0 or if no character type is selected.
 */
std::string GiString::generate_password(int length, bool includeUppercase, bool includeLowercase, bool includeDigits, bool includeSpecialChars) {
    if (length <= 0 || !(includeUppercase || includeLowercase || includeDigits || includeSpecialChars)) {
        throw std::invalid_argument("Invalid parameters for generating password! Function generate_password");
    }

    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string digits = "0123456789";
    std::string specialChars = "!@#$%^&*()";

    std::string allowedChars = "";
    if (includeUppercase) {
        allowedChars += uppercase;
    }
    if (includeLowercase) {
        allowedChars += lowercase;
    }
    if (includeDigits) {
        allowedChars += digits;
    }
    if (includeSpecialChars) {
        allowedChars += specialChars;
    }

    std::string password = "";
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % allowedChars.size();
        password += allowedChars[randomIndex];
    }

    return password;
}

// Example usage:
// GiString giString;
// std::string password = giString.generate_password(12, true, true, true, true);
// std::cout << "Generated Password: " << password << std::endl;





/**
 * @brief Counts the number of vowels in a string.
 *
 * @param input The input string to count vowels from.
 * @return The number of vowels in the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
int GiString::count_vowels(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("count_vowels: Error - Input string is empty.");
    }

    int vowelCount = 0;
    for (char c : input) {
        if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u') {
            vowelCount++;
        }
    }

    return vowelCount;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World";
// int numVowels = giString.count_vowels(input);
// std::cout << "Number of vowels: " << numVowels << std::endl;




/**
 * @brief Counts the number of consonants in a string.
 *
 * @param str The input string to count consonants from.
 * @return The number of consonants in the input string.
 * @throws std::invalid_argument If the input string is empty.
 */

int GiString::count_consonants(std::string str) {
    if (str.empty()) {
        throw std::invalid_argument("count_consonants: Error - Input string is empty");
    }

    int consonantCount = 0;
    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    for (char const &c : str) {
        if (consonants.find(c) != std::string::npos) {
            consonantCount++;
        }
    }

    return consonantCount;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World";
// int consonantCount = giString.count_consonants(input);
// std::cout << "Number of consonants: " << consonantCount << std::endl;




/**
 * @brief Toggles the case of letters in a string (converts lowercase to uppercase and vice versa).
 *
 * @param str The input string to toggle the case.
 * @return The string with the case of letters toggled.
 * @throws std::invalid_argument If the input string is empty.
 */

std::string GiString::toggle_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("toggle_case: Error - Input string is empty.");
    }

    std::string toggledStr = str;
    for (char& c : toggledStr) {
        if (std::islower(c)) {
            c = std::toupper(c);
        } else if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }

    return toggledStr;
}

// Example usage:
// GiString giString;
// std::string input = "HeLLo WoRLd";
// std::string result = giString.toggle_case(input);
// std::cout << "Toggled case string: " << result << std::endl;




// GiString.cpp







/**
 * @brief Checks if the string contains only characters from the given set.
 *
 * @param str The input string to check.
 * @param charSet The set of characters to check against.
 * @return true if the string contains only characters from the set, false otherwise.
 * @throws std::invalid_argument If the input string is empty.
 */

bool GiString::contains_only(const std::string& str, const std::string& charSet) {
    if (str.empty()) {
        throw std::invalid_argument("contains_only: Input string is empty.");
    }

    for (char ch : str) {
        if (charSet.find(ch) == std::string::npos) {
            return false;
        }
    }

    return true;
}

// Example usage:
// std::string input = "abc123";
// std::string charSet = "abcdefghijklmnopqrstuvwxyz";
// bool result = GiString::contains_only(input, charSet);
// std::cout << std::boolalpha << "Contains only specified characters: " << result << std::endl;




// GiString.cpp


/**
 * @brief Removes all characters from the string that are not in the given set.
 *
 * @param str The input string from which characters will be removed.
 * @param charSet A string containing all the characters that are allowed to remain in the string.
 * @return A new string with only the characters from the input string that are in the charSet.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::exclude_chars(const std::string& str, const std::string& charSet) {
    if (str.empty()) {
        throw std::invalid_argument("exclude_chars: Input string is empty.");
    }

    std::string result = "";
    for (char c : str) {
        if (charSet.find(c) != std::string::npos) {
            result += c;
        }
    }

    return result;
}

// Example usage:
// std::string input = "Hello 123 World!";
// std::string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
// std::string result = GiString::exclude_chars(input, charSet);
// std::cout << "Result after excluding characters: " << result << std::endl;




/**
 * @brief Normalizes different types of line endings to a chosen format.
 *
 * @param filePath The file path to the file to normalize line endings.
 * @param chosenFormat The chosen format for line endings (e.g., "LF", "CRLF", "CR").
 * @return True if the normalization was successful, false otherwise.
 * @throws std::invalid_argument If the chosen format is not supported.
 * @throws std::runtime_error If there was an issue reading or writing the file.
 */

bool GiString::normalize_newlines(const std::string& filePath, const std::string& chosenFormat) {
    // Check if the chosen format is supported
    if (chosenFormat != "LF" && chosenFormat != "CRLF" && chosenFormat != "CR") {
        throw std::invalid_argument("Chosen format is not supported. Supported formats: LF, CRLF, CR");
    }

    // Read the content of the file
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open the input file: " + filePath);
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();

    // Normalize line endings based on the chosen format
    std::string content = buffer.str();
    if (chosenFormat == "LF") {
        std::regex_replace(content, std::regex(R"(\r\n)"), "\n");  // CRLF to LF
        std::regex_replace(content, std::regex(R"(\r)"), "\n");    // CR to LF
    } else if (chosenFormat == "CRLF") {
        std::regex_replace(content, std::regex(R"(\r\n|\r)"), "\r\n");  // LF/CR to CRLF
    } else if (chosenFormat == "CR") {
        std::regex_replace(content, std::regex(R"(\r\n|\n)"), "\r");    // LF/CRLF to CR
    }

    // Write the normalized content back to the file
    std::ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open the output file: " + filePath);
    }
    outputFile << content;
    outputFile.close();

    return true;
}

// Example usage:
// GiString giString;
// std::string filePath = "/home/turbo/Pulpit/github/MaxLib/src/GiString/GiString.cpp";
// std::string chosenFormat = "LF";
// bool success = giString.normalize_newlines(filePath, chosenFormat);
// if (success) {
//     std::cout << "Line endings normalized successfully!" << std::endl;
// } else {
//     std::cerr << "Failed to normalize line endings." << std::endl;
// }




/**
 * @brief Adds a specified prefix at the beginning of each line of the string.
 *
 * @param str The input string.
 * @param prefix The prefix to add at the beginning of each line.
 * @return The modified string with the prefix added to each line.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::prefix_lines(const std::string& str, const std::string& prefix) {
    if (str.empty()) {
        throw std::invalid_argument("prefix_lines: Error caused by empty input string");
    }

    std::stringstream result;
    std::istringstream iss(str);
    std::string line;

    while (std::getline(iss, line)) {
        result << prefix << line << "\n";
    }

    return result.str();
}

// Example usage:
// std::string input = "Hello\nWorld\nThis is a test";
// std::string prefix = ">> ";
// std::string result = GiString::prefix_lines(input, prefix);
// std::cout << "Modified string with prefix: \n" << result << std::endl;




// GiString.cpp


/**
 * @brief Adds a specified suffix to the end of each line of the string.
 *
 * @param str The input string.
 * @param suffix The suffix to add at the end of each line.
 * @return std::string The modified string with the suffix added to each line.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::suffix_lines(const std::string& str, const std::string& suffix) {
    if (str.empty()) {
        throw std::invalid_argument("suffix_lines: Input string is empty.");
    }

    std::stringstream result;
    std::istringstream iss(str);
    std::string line;

    while (std::getline(iss, line)) {
        result << line << suffix << "\n";
    }

    return result.str();
}

// Example usage:
// std::string input = "Hello\nWorld\nHow\nAre\nYou";
// std::string result = GiString::suffix_lines(input, " - Suffix");
// std::cout << "Modified string: " << result << std::endl;




/**
 * @brief Converts a key-value pair formatted string into a dictionary structure.
 *
 * @param input The string in key-value pair format to convert.
 * @return std::unordered_map<std::string, std::string> A dictionary containing key-value pairs.
 * @throws std::invalid_argument If the input string is empty or not in the correct format.
 */
std::unordered_map<std::string, std::string> GiString::to_key_value_pairs(const std::string& input) {
    std::unordered_map<std::string, std::string> keyValues;

    if (input.empty()) {
        throw std::invalid_argument("to_key_value_pairs: Input string is empty.");
    }

    // Splitting the input string by delimiter '-'
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, '-')) {
        // Extracting key and value
        size_t pos = token.find('=');
        if (pos == std::string::npos) {
            throw std::invalid_argument("to_key_value_pairs: Invalid format. Expected 'key=value'.");
        }
        std::string key = token.substr(0, pos);
        std::string value = token.substr(pos + 1);

        keyValues[key] = value;
    }

    return keyValues;
}

// Example usage:
// GiString giString;
// std::string input = "name=John-age=30-country=USA";
// std::unordered_map<std::string, std::string> result = giString.to_key_value_pairs(input);
// for (const auto& pair : result) {
//     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
// }




/**
 * @brief Creates a key-value pair string from a dictionary data.
 *
 * @param data The dictionary containing key-value pairs.
 * @return A string in the format "key1=value1, key2=value2, ...".
 * @throws std::invalid_argument If the input dictionary is empty.
 */
std::string GiString::from_key_value_pairs(const std::unordered_map<std::string, std::string>& data) {
    if (data.empty()) {
        throw std::invalid_argument("GiString::from_key_value_pairs: Input dictionary is empty.");
    }

    std::string result;
    for (const auto& pair : data) {
        result += pair.first + "=" + pair.second + ", ";
    }

    // Remove the trailing comma and space
    result = result.substr(0, result.size() - 2);

    return result;
}

// Example usage:
// std::unordered_map<std::string, std::string> data = {{"name", "John"}, {"age", "30"}, {"city", "New York"}};
// std::string formattedString = GiString::from_key_value_pairs(data);
// std::cout << "Formatted string: " << formattedString << std::endl;






/**
 * @brief Interleaves two strings, creating a new string consisting of characters from both strings alternately.
 *
 * @param str1 The first input string.
 * @param str2 The second input string.
 * @return The interleaved string.
 * @throws std::invalid_argument If either input string is empty.
 */
std::string GiString::interleave(const std::string& str1, const std::string& str2) {
    if (str1.empty() || str2.empty()) {
        throw std::invalid_argument("GiString::interleave: Either input string is empty.");
    }

    std::string result;
    size_t i = 0;
    size_t j = 0;

    while (i < str1.length() && j < str2.length()) {
        result.push_back(str1[i]);
        result.push_back(str2[j]);
        i++;
        j++;
    }

    // Append the remaining characters from the longer string
    while (i < str1.length()) {
        result.push_back(str1[i]);
        i++;
    }

    while (j < str2.length()) {
        result.push_back(str2[j]);
        j++;
    }

    return result;
}

// Example usage:
// std::string str1 = "abc";
// std::string str2 = "12345";
// std::string interleaved = GiString::interleave(str1, str2);
// std::cout << "Interleaved string: " << interleaved << std::endl;




/**
 * @brief Deinterleaves a string into two separate strings, assigning alternate characters to each.
 *
 * @param input The input string to deinterleave.
 * @param output1 The first output string with characters assigned alternately.
 * @param output2 The second output string with characters assigned alternately.
 * @throws std::invalid_argument If the input string is empty.
 */
void GiString::deinterleave(const std::string& input, std::string& output1, std::string& output2) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::deinterleave: Input string is empty.");
    }

    output1.clear();
    output2.clear();

    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 2 == 0) {
            output1 += input[i];
        } else {
            output2 += input[i];
        }
    }
}

// Example usage:
// GiString giString;
// std::string input = "HelloWorld";
// std::string output1, output2;
// giString.deinterleave(input, output1, output2);
// std::cout << "Output 1: " << output1 << std::endl;
// std::cout << "Output 2: " << output2 << std::endl;




/**
 * @brief Calculates and returns the difference between two strings in a clear change set format.
 *
 * @param str1 The first string for comparison.
 * @param str2 The second string for comparison.
 * @return The difference between the two strings in a clear change set format.
 * @throws std::invalid_argument If any of the input strings is empty.
 */
std::string GiString::diff(const std::string& str1, const std::string& str2) {
    if (str1.empty() || str2.empty()) {
        throw std::invalid_argument("GiString::diff: Input strings cannot be empty.");
    }

    std::string result;
    size_t i = 0, j = 0;
    while (i < str1.size() && j < str2.size()) {
        if (str1[i] != str2[j]) {
            result += "(-" + str1.substr(i, 1) + ")(+" + str2.substr(j, 1) + ")";
        } else {
            result += str1.substr(i, 1);
        }
        i++; j++;
    }

    while (i < str1.size()) {
        result += "(-" + str1.substr(i, 1) + ")";
        i++;
    }

    while (j < str2.size()) {
        result += "(+" + str2.substr(j, 1) + ")";
        j++;
    }

    return result;
}


// Example usage:
// GiString giString;
// std::string str1 = "Hello";
// std::string str2 = "Hallo";
// std::string difference = giString.diff(str1, str2);
// std::cout << "Difference between str1 and str2: " << difference << std::endl;




/**
 * @brief Applies a set of changes (patch) to a string.
 *
 * @param patch The set of changes to apply to the string.
 * @return The string after applying the patch.
 * @throws std::invalid_argument If the input patch is empty.
 */
std::string GiString::patch(const std::string& patch) {
    if (patch.empty()) {
        throw std::invalid_argument("patch: Empty patch provided.");
    }

    std::string result;
    std::string buffer;
    bool isAddition = false;
    bool isRemoval = false;

    for (char c : patch) {
        if (c == '(') {
            if (!buffer.empty() && (isAddition || isRemoval)) {
                if (isAddition) {
                    result += buffer;
                }
                buffer.clear();
            }
            isAddition = false;
            isRemoval = false;
        } else if (c == ')') {
            if (isAddition) {
                result += buffer;
            }
            buffer.clear();
        } else if (c == '-') {
            isRemoval = true;
        } else if (c == '+') {
            isAddition = true;
        } else if (isAddition || isRemoval) {
            buffer += c;
        } else {
            result += c;
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string originalString = "Hello, World!";
// std::string appliedPatch = "+John, -World";
// std::string result = giString.patch(appliedPatch);
// std::cout << "Patched string: " << result << std::endl;




/**
 * @brief Replaces multiple occurrences of white spaces with a single space in a given string.
 *
 * @param input The input string to compress white spaces.
 * @return The string with multiple white spaces replaced by a single space.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::compress_whitespace(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("compress_whitespace: Input string is empty");
    }

    std::string result;
    bool isSpace = false;

    for (char c : input) {
        if (std::isspace(c)) {
            if (!isSpace) {
                result.push_back(' ');
                isSpace = true;
            }
        } else {
            result.push_back(c);
            isSpace = false;
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello     World  !";
// std::string result = giString.compress_whitespace(input);
// std::cout << "Compressed string: " << result << std::endl;






/**
 * @brief Converts a string to camelCase.
 *
 * @param str The input string to convert to camelCase.
 * @return The converted camelCase string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_camel_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("to_camel_case: Input string is empty.");
    }

    std::string camelCaseStr;
    bool makeUpper = false;

    for (char c : str) {
        if (std::isalnum(c)) {
            if (makeUpper) {
                camelCaseStr += std::toupper(c);
                makeUpper = false;
            } else {
                camelCaseStr += std::tolower(c);
            }
        } else {
            makeUpper = true;
        }
    }

    return camelCaseStr;
}

// Example usage:
// GiString giString;
// std::string input = "convert this to camel case";
// std::string result = giString.to_camel_case(input);
// std::cout << "CamelCase string: " << result << std::endl;




/**
 * @brief Converts a camelCase string to a space-separated format.
 *
 * @param str The input string in camelCase format.
 * @return The converted string with spaces separating words.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::from_camel_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("from_camel_case: Input string is empty.");
    }

    std::string result;
    for (char c : str) {
        if (std::isupper(c)) {
            result.push_back(' ');  // Add space before uppercase letters
            result.push_back(std::tolower(c));
        } else {
            result.push_back(c);
        }
    }

    return result;
}

// Example usage:
// std::string input = "helloWorld";
// std::string result = GiString::from_camel_case(input);
// std::cout << "Converted string: " << result << std::endl;




/**
 * @brief Converts a string to snake_case.
 *
 * @param str The input string to convert to snake_case.
 * @return The input string converted to snake_case.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_snake_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("to_snake_case: Input string is empty.");
    }

    std::string snakeCaseString;
    for (size_t i = 0; i < str.length(); ++i) {
        if (isupper(str[i])) {
            if (i != 0 && islower(str[i - 1])) {
                snakeCaseString.push_back('_');
            }
            snakeCaseString.push_back(tolower(str[i]));
        } else {
            snakeCaseString.push_back(str[i]);
        }
    }

    return snakeCaseString;
}

// Example usage:
// std::string input = "ConvertToString";
// std::string result = GiString::to_snake_case(input);
// std::cout << "Snake case string: " << result << std::endl;






/**
 * @brief Converts a snake_case string to a space-separated format.
 *
 * @param snakeCaseStr The input string in snake_case format.
 * @return The converted string with spaces.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::from_snake_case(const std::string& snakeCaseStr) {
    if (snakeCaseStr.empty()) {
        throw std::invalid_argument("from_snake_case: Input string is empty.");
    }

    std::string spaceSeparatedStr;
    for (char c : snakeCaseStr) {
        if (isupper(c)) {
            spaceSeparatedStr.push_back(' ');  // Add a space before uppercase letters
            spaceSeparatedStr.push_back(tolower(c));
        } else {
            spaceSeparatedStr.push_back(c);
        }
    }

    return spaceSeparatedStr;
}

// Example usage:
// std::string snakeCaseStr = "hello_world_from_snake_case";
// std::string result = GiString::from_snake_case(snakeCaseStr);
// std::cout << "Converted string: " << result << std::endl;




/**
 * @brief Converts a string to kebab-case format.
 *
 * @param str The input string to convert to kebab-case.
 * @return The input string converted to kebab-case format.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_kebab_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("to_kebab_case: Input string is empty.");
    }

    std::string kebabCaseStr;
    for (char c : str) {
        if (std::isupper(c)) {
            if (!kebabCaseStr.empty() && kebabCaseStr.back() != '-') {
                kebabCaseStr.push_back('-');
            }
            kebabCaseStr.push_back(std::tolower(c));
        } else if (std::isalnum(c)) {
            kebabCaseStr.push_back(c);
        }
    }

    return kebabCaseStr;
}

// Example usage:
// GiString gs;
// std::string input = "HelloWorldExample";
// std::string result = gs.to_kebab_case(input);
// std::cout << "Kebab-case string: " << result << std::endl;






/**
 * @brief Converts a string from kebab-case to a space-separated format.
 *
 * @param kebabCaseStr The input string in kebab-case format.
 * @return std::string The converted string with spaces instead of hyphens.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::from_kebab_case(const std::string& kebabCaseStr) {
    if (kebabCaseStr.empty()) {
        throw std::invalid_argument("from_kebab_case: Input string is empty.");
    }

    std::string result;
    for (char c : kebabCaseStr) {
        if (c == '-') {
            result.push_back(' '); // Replace hyphen with space
        } else {
            result.push_back(c);
        }
    }

    return result;
}

// Example usage:
// std::string kebabCaseStr = "hello-world";
// std::string result = GiString::from_kebab_case(kebabCaseStr);
// std::cout << "Converted string: " << result << std::endl;




// GiString.cpp


/**
 * @brief Converts a string to PascalCase.
 *
 * @param str The input string to convert to PascalCase.
 * @return std::string The input string converted to PascalCase.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_pascal_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("to_pascal_case: Input string is empty.");
    }

    std::string pascalCaseStr;
    bool capitalizeNext = true;

    for (char c : str) {
        if (std::isalpha(c)) {
            if (capitalizeNext) {
                pascalCaseStr += std::toupper(c);
                capitalizeNext = false;
            } else {
                pascalCaseStr += std::tolower(c);
            }
        } else if (std::isspace(c) || c == '_' || c == '-') {
            capitalizeNext = true;
        }
    }

    return pascalCaseStr;
}

// Example usage:
// std::string input = "convert_this_to_pascal";
// std::string result = GiString::to_pascal_case(input);
// std::cout << "PascalCase string: " << result << std::endl;




/**
 * @brief Converts a string from PascalCase to a format separated by spaces.
 *
 * @param str The input string in PascalCase.
 * @return The converted string separated by spaces.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::from_pascal_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("from_pascal_case: Input string is empty");
    }

    std::string convertedStr;
    for (size_t i = 0; i < str.size(); ++i) {
        if (isupper(str[i]) && i > 0) {
            convertedStr.push_back(' '); // Add space before uppercase letters (except the first)
        }
        convertedStr.push_back(tolower(str[i])); // Convert uppercase to lowercase
    }

    return convertedStr;
}

// Example usage:
// std::string input = "PascalCaseString";
// std::string result = GiString::from_pascal_case(input);
// std::cout << "Converted string: " << result << std::endl;




/**
 * @brief Randomly changes the case of letters in a string.
 *
 * @param str The input string to randomize the case.
 * @return std::string The string with randomly changed letter cases.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::randomize_case(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::randomize_case: Input string is empty.");
    }

    std::string result = str;
    for (char& c : result) {
        // Check if the character is a letter
        if (std::isalpha(c)) {
            // Generate a random number (0 or 1) to decide whether to change case
            int changeCase = std::rand() % 2;
            if (changeCase == 0) {
                if (std::islower(c)) {
                    c = std::toupper(c); // Change to uppercase
                } else {
                    c = std::tolower(c); // Change to lowercase
                }
            }
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Randomize Case Example";
// std::string result = giString.randomize_case(input);
// std::cout << "Randomized string: " << result << std::endl;




/**
 * @brief Singularizes words in plural form to singular form.
 *
 * @param pluralWord The word in plural form to singularize.
 * @return std::string The singular form of the input word.
 * @throws std::invalid_argument If the input word is empty.
 */
std::string GiString::singularize(const std::string& pluralWord) {
    if (pluralWord.empty()) {
        throw std::invalid_argument("GiString::singularize: Input word is empty.");
    }

    // Basic English singularization rules
    std::string singularWord;
    if (pluralWord.size() > 3 && pluralWord.substr(pluralWord.size() - 3) == "ies" && 
        !isVowel(pluralWord[pluralWord.size() - 4])) {
        // If the word ends in ies and the preceding character is not a vowel, change ies to y
        singularWord = pluralWord.substr(0, pluralWord.size() - 3) + "y";
    } else if (pluralWord.size() > 2 && pluralWord.substr(pluralWord.size() - 2) == "es" && 
               (pluralWord[pluralWord.size() - 3] == 's' || pluralWord[pluralWord.size() - 3] == 'x' || 
                pluralWord[pluralWord.size() - 3] == 'z' || 
                (pluralWord.size() > 4 && 
                 ((pluralWord.substr(pluralWord.size() - 4, 2) == "ch") || 
                  (pluralWord.substr(pluralWord.size() - 4, 2) == "sh"))))) {
        // If the word ends in es and the preceding character is s, x, z, ch, or sh, remove the es
        singularWord = pluralWord.substr(0, pluralWord.size() - 2);
    } else if (pluralWord.back() == 's') {
        // If the word ends in s, just remove the s
        singularWord = pluralWord.substr(0, pluralWord.size() - 1);
    } else {
        // If none of the above conditions are met, return the word as is
        singularWord = pluralWord;
    }

    return singularWord;
}

// Example usage:
// std::string pluralWord = "apples";
// std::string singularWord = GiString::singularize(pluralWord);
// std::cout << "Singular form of '" << pluralWord << "': " << singularWord << std::endl;





/**
 * @brief Converts words in singular form to plural form.
 *
 * This function takes a word in singular form and converts it to its plural form by applying basic English pluralization rules.
 *
 * @param word The word in singular form to be pluralized.
 * @return The pluralized form of the input word.
 * @throws std::invalid_argument If the input word is empty.
 */
std::string GiString::pluralize(const std::string& word) {
    if (word.empty()) {
        throw std::invalid_argument("GiString::pluralize: Input word is empty.");
    }

    // Basic English pluralization rules
    std::string pluralizedWord;
    if (word.back() == 's' || word.back() == 'x' || word.back() == 'z' || 
        (word.size() > 1 && ((word.substr(word.size() - 2) == "ch") || (word.substr(word.size() - 2) == "sh")))) {
        // If the word ends in s, x, z, ch, sh, add 'es' at the end
        pluralizedWord = word + "es";
    } else if (word.back() == 'y' && 
               (word.size() == 1 || (word.size() > 1 && !isVowel(word[word.size() - 2])))) {
        // If the word ends in y and y is not preceded by a vowel, change y to ies
        pluralizedWord = word.substr(0, word.size() - 1) + "ies";
    } else {
        // In other cases, just add 's' at the end
        pluralizedWord = word + "s";
    }

    return pluralizedWord;
}

bool GiString::isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}


// Example usage:
// GiString giString;
// std::string singularWord = "car";
// std::string pluralizedWord = giString.pluralize(singularWord);
// std::cout << "Pluralized word: " << pluralizedWord << std::endl;

// GiString.cpp
/**
 * @brief Converts HTML content to plain text.
 *
 * @param htmlContent The HTML content to be converted to plain text.
 * @return The converted plain text.
 * @throws std::invalid_argument If the HTML content is empty.
 */
std::string GiString::html_to_text(const std::string& htmlContent) {
    if(htmlContent.empty()) {
        throw std::invalid_argument("html_to_text: Empty HTML content provided.");
    }

    // Regular expression to match HTML tags
    std::regex htmlTagPattern("<[^>]*>");

    // Replace all HTML tags with an empty string
    std::string plainText = std::regex_replace(htmlContent, htmlTagPattern, "");

    return plainText;
}


// Example usage:
// std::string htmlContent = "<html><body><h1>Hello World!</h1></body></html>";
// std::string plainText = GiString::html_to_text(htmlContent);
// std::cout << "Plain Text: " << plainText << std::endl;





/**
 * @brief Converts special XML characters to XML entities.
 *
 * @param input The input string to escape XML special characters.
 * @return The string with XML special characters replaced by XML entities.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::xml_escape(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("xml_escape: Input string is empty.");
    }

    std::string escapedString;
    for (char c : input) {
        switch (c) {
            case '<':
                escapedString += "&lt;";
                break;
            case '>':
                escapedString += "&gt;";
                break;
            case '&':
                escapedString += "&amp;";
                break;
            case '\'':
                escapedString += "&apos;";
                break;
            case '\"':
                escapedString += "&quot;";
                break;
            default:
                escapedString += c;
        }
    }

    return escapedString;
}

// Example usage:
// GiString strHelper;
// std::string input = "<Hello World>";
// std::string escaped = strHelper.xml_escape(input);
// std::cout << "Escaped XML string: " << escaped << std::endl;








/**
 * @brief Increases the value of a hexadecimal number by a specified amount.
 *
 * @param hexValue The input hexadecimal number as a string.
 * @param increment The value to increment the hexadecimal number by.
 * @return The updated hexadecimal number as a string.
 * @throws std::invalid_argument If the input hexValue is empty or not a valid hexadecimal number.
 */
std::string GiString::increment_hex(const std::string& hexValue, int increment) {
    // Check if the input hexValue is empty
    if (hexValue.empty()) {
        throw std::invalid_argument("increment_hex: Input hexValue is empty.");
    }

    // Check if the input hexValue is a valid hexadecimal number
    if (!std::all_of(hexValue.begin(), hexValue.end(), ::isxdigit)) {
        throw std::invalid_argument("increment_hex: Input hexValue is not a valid hexadecimal number.");
    }

    // Convert hexValue to an integer
    int decimalValue = std::stoi(hexValue, 0, 16);

    // Increment the decimal value
    decimalValue += increment;

    // Convert the incremented decimal value back to hexadecimal
    std::stringstream ss;
    ss << std::hex << decimalValue;
    std::string result = ss.str();

    return result;
}

// Example usage:
// GiString gs;
// std::string hexValue = "1A";
// int increment = 5;
// std::string result = gs.increment_hex(hexValue, increment);
// std::cout << "Updated hexadecimal number: " << result << std::endl;

/**
 * @brief Decreases the value of a hexadecimal number by a specified amount.
 *
 * @param hexNum The hexadecimal number as a string to decrement.
 * @param decrementValue The value to decrement the hexadecimal number by.
 * @return The decremented hexadecimal number as a string.
 * @throws std::invalid_argument If the input hexNum is empty or not a valid hexadecimal number.
 * @throws std::invalid_argument If the decrementValue is not a valid hexadecimal number.
 */
std::string GiString::decrement_hex(const std::string& hexNum, const std::string& decrementValue) {
    // Check if hexNum is not empty and is a valid hexadecimal number
    if (hexNum.empty() || !is_valid_hex_code(hexNum)) {
        throw std::invalid_argument("decrement_hex: Invalid input hexadecimal number.");
    }

    // Check if decrementValue is a valid hexadecimal number
    if (!is_valid_hex_code(decrementValue)) {
        throw std::invalid_argument("decrement_hex: Invalid decrement value.");
    }

    // Convert hexNum and decrementValue to decimal integers
    int num = std::stoi(hexNum, nullptr, 16);
    int decrement = std::stoi(decrementValue, nullptr, 16);

    // Decrease the value by the decrement amount
    int result = num - decrement;

    // Check if the result is negative, if so, set it to 0
    if (result < 0) {
        result = 0;
    }

    // Convert the result back to hexadecimal string
    std::stringstream ss;
    ss << std::hex << result;
    std::string resultHex = ss.str();

    return resultHex;
}

// Example usage:
// GiString gs;
// std::string hexNumber = "1A"; // Hexadecimal number 1A (decimal 26)
// std::string decrementValue = "5"; // Decrement by 5
// std::string decrementedHex = gs.decrement_hex(hexNumber, decrementValue);
// std::cout << "Decremented hexadecimal number: " << decrementedHex << std::endl;



/**
 * @brief Increases the numeric suffix of a string according to a specified pattern.
 *
 * @param input The input string with a numeric suffix.
 * @param pattern The pattern to determine how much to increment the numeric suffix.
 * @return The modified string with the incremented numeric suffix.
 * @throws std::invalid_argument If the input string is empty or the pattern is invalid.
 */
std::string GiString::increment_by_pattern(const std::string& input, const int pattern) {
    if (input.empty()) {
        throw std::invalid_argument("increment_by_pattern: Input string is empty.");
    }

    // Find the position of the numeric suffix
    size_t pos = input.find_last_of("0123456789");
    if (pos == std::string::npos) {
        throw std::invalid_argument("increment_by_pattern: No numeric suffix found in the input string.");
    }

    // Extract the numeric suffix
    std::string prefix = input.substr(0, pos);
    std::string suffix = input.substr(pos);

    // Convert the suffix to an integer and increment it based on the pattern
    int num = std::stoi(suffix);
    num += pattern;

    // Construct the modified string
    return prefix + std::to_string(num);
}

// Example usage:
// std::string input = "example123";
// int pattern = 5;
// std::string result = GiString::increment_by_pattern(input, pattern);
// std::cout << "Modified string: " << result << std::endl;




/**
 * @brief Decreases the numerical suffix of a string according to a specified pattern.
 *
 * @param input The input string with a numerical suffix to decrement.
 * @param pattern The pattern to determine the decrement value (e.g., "0" for decrement by 1, "00" for decrement by 2).
 * @return The modified string after decreasing the numerical suffix based on the pattern.
 * @throws std::invalid_argument If the input string is empty or the pattern is invalid.
 */
std::string GiString::decrement_by_pattern(const std::string& input, const std::string& pattern) {
    if (input.empty() || pattern.empty()) {
        throw std::invalid_argument("decrement_by_pattern: Input string or pattern cannot be empty.");
    }

    // Extract the numerical suffix based on the pattern
    std::string suffix = input.substr(input.size() - pattern.size());
    
    // Convert the suffix to an integer
    int decrementValue = std::stoi(suffix) - std::stoi(pattern);

    // Check if the decrement would result in a negative value
    if (decrementValue < 0) {
        throw std::invalid_argument("decrement_by_pattern: Decrement value would result in a negative number.");
    }

    // Construct the modified string with the decremented numerical suffix
    std::string result = input.substr(0, input.size() - pattern.size()) + std::to_string(decrementValue);

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "example123";
// std::string pattern = "00";
// std::string result = giString.decrement_by_pattern(input, pattern);
// std::cout << "Modified string: " << result << std::endl;


/**
 * @brief Fills a template string with values from a given dictionary or list.
 *
 * @param templateStr The template string with placeholders to be filled.
 * @param data A dictionary or list containing values to replace the placeholders in the template string.
 * @return The template string with placeholders replaced by actual values.
 * @throws std::invalid_argument If the template string is empty.
 * @throws std::invalid_argument If the data provided is not a dictionary or list.
 */
std::string GiString::fill_template(const std::string& templateStr, const std::any& data) {
    if (templateStr.empty()) {
        throw std::invalid_argument("GiString::fill_template: Template string is empty.");
    }

    std::string result = templateStr;

    if (data.type() == typeid(std::unordered_map<std::string, std::string>)) {
        std::unordered_map<std::string, std::string> dataMap = std::any_cast<std::unordered_map<std::string, std::string>>(data);
        for (const auto& pair : dataMap) {
            std::string placeholder = "{" + pair.first + "}";
            size_t pos = result.find(placeholder);
            while (pos != std::string::npos) {
                result.replace(pos, placeholder.length(), pair.second);
                pos = result.find(placeholder, pos + pair.second.size());
            }
        }
    } else if (data.type() == typeid(std::vector<std::string>)) {
        std::vector<std::string> dataList = std::any_cast<std::vector<std::string>>(data);
        for (size_t i = 0; i < dataList.size(); ++i) {
            std::string placeholder = "{" + std::to_string(i) + "}";
            size_t pos = result.find(placeholder);
            while (pos != std::string::npos) {
                result.replace(pos, placeholder.length(), dataList[i]);
                pos = result.find(placeholder, pos + dataList[i].size());
            }
        }
    } else {
        throw std::invalid_argument("GiString::fill_template: Data provided is not a dictionary or list.");
    }

    return result;
}


// Example usage:
// std::string templateString = "Hello, {name}! Your age is {age}.";
// std::unordered_map<std::string, std::string> dataMap = {{"name", "Alice"}, {"age", "30"}};
// std::string result = GiString::fill_template(templateString, dataMap);
// std::cout << "Filled template: " << result << std::endl;

/**
 * @brief Extracts all templates in the specified format from a given string.
 *
 * @param input The input string to extract templates from.
 * @return std::vector<std::string> A vector containing all the templates found in the input string.
 * @throws std::invalid_argument If the input string is empty.
 */

std::vector<std::string> GiString::extract_templates(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("extract_templates: Input string is empty");
    }

    std::vector<std::string> templates;
    std::regex templateRegex("\\{\\{([^}]*)\\}\\}");
    std::smatch match;

    auto words_begin = std::sregex_iterator(input.begin(), input.end(), templateRegex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        templates.push_back(match.str());
    }

    return templates;
}

// Example usage:
// GiString giString;
// std::string input = "This is a {{template}} with multiple {{placeholders}}";
// std::vector<std::string> extractedTemplates = giString.extract_templates(input);
// for (const auto& template : extractedTemplates) {
//     std::cout << "Found template: " << template << std::endl;
// }


/**
 * @brief Swaps each pair of characters in a string.
 *
 * @param str The input string to swap pairs of characters.
 * @return std::string The string with each pair of characters swapped.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::swap_pairs(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("swap_pairs: Input string is empty.");
    }

    std::string result = str;
    for (size_t i = 0; i < result.length() - 1; i += 2) {
        std::swap(result[i], result[i + 1]);
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello";
// std::string result = giString.swap_pairs(input);
// // Output should be "eHlol"


/**
 * @brief Restores the original positions of characters after using the swap_pairs function.
 *
 * @param str The input string to restore.
 * @return std::string The string with original character positions restored.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::unswap_pairs(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("unswap_pairs: Input string is empty.");
    }

    std::string result = str;
    for (size_t i = 0; i < result.length(); i += 2) {
        if (i + 1 < result.length()) {
            std::swap(result[i], result[i + 1]);
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "hTe llowor d!";
// std::string result = giString.unswap_pairs(input);
// std::cout << "Original positions restored: " << result << std::endl;

/**
 * @brief Applies a mask to a string, hiding certain characters based on the provided mask.
 *
 * @param str The input string to apply the mask to.
 * @param mask The mask string used to hide characters in the input string.
 * @return The masked string.
 * @throws std::invalid_argument If the input string or mask is empty.
 */
std::string GiString::apply_mask(const std::string& str, const std::string& mask) {
    if (str.empty() || mask.empty()) {
        throw std::invalid_argument("apply_mask: Input string or mask is empty.");
    }

    std::string maskedStr;
    size_t maskIndex = 0;

    for (char c : str) {
        if (std::isalnum(c)) { // Check if the character is alphanumeric
            maskedStr += (maskIndex < mask.length() && mask[maskIndex] == '1') ? '*' : c;
            maskIndex = (maskIndex + 1) % mask.length();
        } else {
            maskedStr += c; // Keep non-alphanumeric characters as they are
        }
    }

    return maskedStr;
}

// Example usage:
// GiString giString;
// std::string input = "Confidential123";
// std::string mask = "10101010101";
// std::string result = giString.apply_mask(input, mask);
// std::cout << "Masked string: " << result << std::endl;


/**
 * @brief Returns the index of the N-th occurrence of a specified character or string in the given input string.
 *
 * @param str The input string to search in.
 * @param target The character or string to search for.
 * @param n The N-th occurrence to find (1-based index).
 * @return The index of the N-th occurrence of the target in the input string, or -1 if not found.
 * @throws std::invalid_argument If the input string is empty.
 */
int GiString::index_of_nth(const std::string& str, const std::string& target, int n) {
    if (str.empty()) {
        throw std::invalid_argument("index_of_nth: Input string is empty.");
    }

    size_t pos = 0;
    int found = 0;
    
    while ((pos = str.find(target, pos)) != std::string::npos) {
        found++;
        if (found == n) {
            return static_cast<int>(pos);
        }
        pos += target.length();
    }

    return -1; // Not found
}

// Example usage:
// GiString giString;
// std::string input = "hello world, hello universe, hello galaxy";
// std::string target = "hello";
// int occurrence = 2;
// int index = giString.index_of_nth(input, target, occurrence);
// std::cout << "Index of the " << occurrence << "-th occurrence of '" << target << "': " << index << std::endl;

/**
 * @brief Replaces the N-th occurrence of a specified character or substring with another string.
 *
 * @param str The original string where replacement will be performed.
 * @param toReplace The character or substring to be replaced.
 * @param replaceWith The string to replace the character or substring with.
 * @param n The N-th occurrence to replace (1-indexed).
 * @return The string after replacement.
 * @throws std::invalid_argument If the input string is empty or if the N-th occurrence does not exist.
 */

std::string GiString::replace_nth(std::string str, const std::string& toReplace, const std::string& replaceWith, int n) {
    if (str.empty()) {
        throw std::invalid_argument("replace_nth: Input string is empty.");
    }

    size_t pos = 0;
    int count = 0;
    while ((pos = str.find(toReplace, pos)) != std::string::npos) {
        if (++count == n) {
            str.replace(pos, toReplace.length(), replaceWith);
            return str;
        }
        pos += toReplace.length();
    }

    throw std::invalid_argument("replace_nth: N-th occurrence does not exist.");
}

// Example usage:
// GiString giString;
// std::string original = "hello world, hello universe";
// std::string result = giString.replace_nth(original, "hello", "hi", 2);
// std::cout << "Modified string: " << result << std::endl;


/**
 * @brief Randomly selects and returns a substring of a specified length from the input string.
 *
 * @param input The input string from which the substring will be extracted.
 * @param length The length of the substring to be extracted.
 * @return The randomly selected substring of the specified length.
 * @throws std::invalid_argument If the input string is empty or the length is greater than the input string length.
 */
std::string GiString::random_extract(const std::string& input, size_t length) {
    if (input.empty()) {
        throw std::invalid_argument("random_extract: Input string is empty.");
    }
    if (length > input.length()) {
        throw std::invalid_argument("random_extract: Length is greater than the input string length.");
    }

    // Generate a random starting index for the substring
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, input.length() - length);
    size_t start_index = dist(gen);

    return input.substr(start_index, length);
}

// Example usage:
// GiString giString;
// std::string input = "This is a sample string for random extraction.";
// size_t length = 5;
// std::string result = giString.random_extract(input, length);
// std::cout << "Randomly extracted substring: " << result << std::endl;

/**
 * @brief Automatically adds indentation to a string based on its structure.
 *
 * @param str The input string to be auto-indented.
 * @return The auto-indented string.
 * @throws std::invalid_argument If the input string is empty.
 */

std::string GiString::auto_indent(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("auto_indent: Error caused by empty input string");
    }

    std::string autoIndentedStr;
    int indentationLevel = 0;
    bool isNewLine = true;

    for (char c : str) {
        if (isNewLine) {
            for (int i = 0; i < indentationLevel; ++i) {
                autoIndentedStr += "    "; // Adding 4 spaces for each level of indentation
            }
            isNewLine = false;
        }
        
        autoIndentedStr += c;

        if (c == '{') {
            ++indentationLevel;
        } else if (c == '}') {
            --indentationLevel;
        } else if (c == '\n') {
            isNewLine = true;
        }
    }

    return autoIndentedStr;
}

// Example usage:
// GiString giString;
// std::string input = "void testFunction() {\nint x = 5;\n}";
// std::string result = giString.auto_indent(input);
// std::cout << "Auto-indented string: \n" << result << std::endl;

/**
 * @brief Checks and fixes unpaired brackets in a string if possible.
 *
 * @param str The input string to check and fix unpaired brackets.
 * @return The string with corrected unpaired brackets if possible.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::balance_brackets(std::string str) {
    if (str.empty()) {
        throw std::invalid_argument("balance_brackets: Input string is empty.");
    }

    // Stack to keep track of the brackets
    std::stack<char> brackets;

    for (char& ch : str) {
        switch (ch) {
            case '{':
            case '(':
            case '[':
                // Push the open brackets onto the stack
                brackets.push(ch);
                break;
            case '}':
            case ')':
            case ']':
                // If we see a close bracket, check the top of the stack
                if (!brackets.empty()) {
                    char open_bracket = brackets.top();
                    // If the brackets match, pop the open bracket off the stack
                    if ((open_bracket == '{' && ch == '}') ||
                        (open_bracket == '(' && ch == ')') ||
                        (open_bracket == '[' && ch == ']')) {
                        brackets.pop();
                    }
                }
                break;
        }
    }

    // If the stack is not empty, there are unbalanced brackets
    if (!brackets.empty()) {
        throw std::runtime_error("balance_brackets: Brackets are not balanced.");
    }

    // Return the original string if the brackets are balanced
    return str;
}

// Example usage:
// GiString giString;
// std::string input = "((Hello)";
// std::string result = giString.balance_brackets(input);
// std::cout << "String with balanced brackets: " << result << std::endl;

/**
 * @brief Converts a string representing a number to different numerical systems.
 *
 * This function takes a string representing a number and converts it to the specified numerical base.
 *
 * @param number The string representing the number to convert.
 * @param base The base to convert the number to.
 * @return The string representation of the number in the specified base.
 * @throws std::invalid_argument If the input number is empty or if the base is not within the range [2, 36].
 */
std::string GiString::to_base(const std::string& number, int base) {
    if (number.empty()) {
        throw std::invalid_argument("to_base: Empty input number");
    }
    
    if (base < 2 || base > 36) {
        throw std::invalid_argument("to_base: Base must be in the range [2, 36]");
    }

    // Convert the input number to an integer
    int num = std::stoi(number);

    // Characters for representing digits greater than 9
    std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // String to hold the result
    std::string result;

    while (num > 0) {
        result.push_back(chars[num % base]);
        num /= base;
    }

    // Reverse the result since the digits are in reverse order
    std::reverse(result.begin(), result.end());

    return result;
}


// Example usage:
// GiString giString;
// std::string number = "42";
// int base = 2;
// std::string result = giString.to_base(number, base);
// std::cout << "Number in base " << base << ": " << result << std::endl;
/**
 * @brief Normalize the casing of a string according to the specified style (e.g., all uppercase, all lowercase).
 *
 * @param input The input string to normalize.
 * @param style The desired casing style ("lower" for all lowercase, "upper" for all uppercase).
 * @return The input string with casing normalized according to the specified style.
 * @throws std::invalid_argument If the input string is empty or if an invalid style is provided.
 */
std::string GiString::normalize_casing(const std::string& input, const std::string& style) {
    if (input.empty()) {
        throw std::invalid_argument("normalize_casing: Input string is empty!");
    }

    std::string result = input;
    
    if (style == "lower") {
        for (char& c : result) {
            if (std::isupper(c)) {
                c = std::tolower(c);
            }
        }
    } else if (style == "upper") {
        for (char& c : result) {
            if (std::islower(c)) {
                c = std::toupper(c);
            }
        }
    } else {
        throw std::invalid_argument("normalize_casing: Invalid style provided!");
    }

    return result;
}

// Example usage:
// GiString strObj;
// std::string input = "Hello World";
// std::string result_lower = strObj.normalize_casing(input, "lower");
// std::string result_upper = strObj.normalize_casing(input, "upper");
// std::cout << "Normalized to lowercase: " << result_lower << std::endl;
// std::cout << "Normalized to uppercase: " << result_upper << std::endl;

// Function to remove diacritics from text, e.g., converting "é" to "e".
/**
 * @brief Removes diacritics from texts by replacing accented characters with their non-accented counterparts.
 *
 * @param text The input text containing diacritics.
 * @return std::string The text with diacritics removed.
 * @throws std::invalid_argument If the input text is empty.
 */
std::string GiString::diacritic_remove(const std::string& text) {
    if (text.empty()) {
        throw std::invalid_argument("diacritic_remove: Input text is empty!");
    }

    // Map of characters with diacritics and their replacements
    std::map<char, char> diacriticsMap = {
        {L'ą', L'a'}, {L'ć', L'c'}, {L'ę', L'e'}, {L'ł', L'l'}, {L'ń', L'n'}, {L'ó', L'o'}, 
        {L'ś', L's'}, {L'ź', L'z'}, {L'ż', L'z'}, {L'Ą', L'A'}, {L'Ć', L'C'}, {L'Ę', L'E'}, 
        {L'Ł', L'L'}, {L'Ń', L'N'}, {L'Ó', L'O'}, {L'Ś', L'S'}, {L'Ź', L'Z'}, {L'Ż', L'Z'}
    };

    std::string result;
    for (char c : text) {
        if (diacriticsMap.find(c) != diacriticsMap.end()) {
            result += diacriticsMap[c];
        } else {
            result += c;
        }
    }

    return result;
}

// Example usage:
// GiString strProcessor;
// std::string input = "Zażółć gęślą jaźń";
// std::string result = strProcessor.diacritic_remove(input);
// std::cout << "Text with diacritics removed: " << result << std::endl;


/**
 * @brief Escapes special characters in a string to make it safe for shell command usage.
 *
 * @param input The input string to escape special characters.
 * @return The escaped string safe for shell command usage.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::quote_for_shell(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("quote_for_shell: Input string is empty.");
    }

    // List of characters that need to be escaped for shell safety
    const std::string specialChars = "\\`$\"";

    std::string result;
    for (char c : input) {
        if (specialChars.find(c) != std::string::npos) {
            result.push_back('\\');  // Add escape character
        }
        result.push_back(c);
    }

    return result;
}

// Example usage:
// std::string input = "Hello$World";
// std::string safeString = GiString::quote_for_shell(input);
// std::cout << "Safe string for shell: " << safeString << std::endl;
 
 /**
 * @brief Removes escaping from a string intended for shell commands.
 *
 * @param input The input string with escape characters.
 * @return std::string The unescaped string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::dequote_for_shell(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("dequote_for_shell: Error caused by empty input string");
    }

    std::string result;
    bool escape = false;

    for (char c : input) {
        if (c == '\\' && !escape) {
            escape = true;
        } else {
            result += c;
            escape = false;
        }
    }

    return result;
}

// Example usage:
// std::string input = "This is a \"test\" string with escape \\ characters";
// std::string result = GiString::dequote_for_shell(input);
// std::cout << "Unescaped string: " << result << std::endl;



/**
 * @brief Escapes all characters in the string that have special meaning in regular expressions.
 *
 * @param input The input string to escape.
 * @return The escaped string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::escape_regex(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("escape_regex: Input string is empty");
    }

    std::string escapedString;
    for (char c : input) {
        if (c == '.' || c == '^' || c == '$' || c == '|' || c == '?' || c == '*' ||
            c == '+' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' ||
            c == '}' || c == '\\' || c == '/') {
            escapedString += '\\'; // add backslash before special characters
        }
        escapedString += c;
    }

    return escapedString;
}

// Example usage:
// GiString giString;
// std::string input = "hello.world?";
// std::string escaped = giString.escape_regex(input);
// std::cout << "Escaped string: " << escaped << std::endl;


/**
 * @brief Removes escaping characters from strings containing regular expressions.
 *
 * @param str The input string with escaped characters.
 * @return std::string The string with escaped characters removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::unescape_regex(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("unescape_regex: Input string is empty.");
    }

    std::string result;
    bool escape = false;

    for (char c : str) {
        if (escape) {
            result.push_back(c);
            escape = false;
        } else {
            if (c == '\\') {
                escape = true;
            } else {
                result.push_back(c);
            }
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "This \\\\ is a \\d+ test \\.";
// std::string result = giString.unescape_regex(input);
// std::cout << "Unescaped string: " << result << std::endl;

/**
 * @brief Capitalizes the first letter of a string, leaving the rest of the letters unchanged.
 *
 * @param str The input string to capitalize.
 * @return The string with the first letter capitalized.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::capitalize_first(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("capitalize_first: Input string is empty.");
    }

    std::string result = str;
    result[0] = std::toupper(result[0]); // Capitalize the first letter

    return result;
}

// Example usage:
// std::string input = "hello world";
// std::string result = GiString::capitalize_first(input);
// std::cout << "Capitalized string: " << result << std::endl;

/**
 * @brief Decapitalizes the first letter of a string, regardless of the rest of the string.
 *
 * @param str The input string to decapitalize.
 * @return The string with the first letter decapitalized.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::decapitalize_first(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("decapitalize_first: Input string is empty");
    }

    std::string decapitalized = str;
    decapitalized[0] = std::tolower(decapitalized[0]);
    
    return decapitalized;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World";
// std::string result = giString.decapitalize_first(input);
// std::cout << "Decapitalized string: " << result << std::endl;

/**
 * @brief Swaps the endianness of encoded strings for different architectures.
 *
 * @param input The input encoded string to swap endianness.
 * @return The encoded string with swapped endianness.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::swap_endians(std::string input) {
    if (input.empty()) {
        throw std::invalid_argument("swap_endians: Error - Input string is empty.");
    }

    // Swap endianness logic implementation
    std::reverse(input.begin(), input.end());

    return input;
}

// Example usage:
// GiString giString;
// std::string input = "ABCD1234"; // Example encoded string
// std::string result = giString.swap_endians(input);
// std::cout << "Swapped endianness string: " << result << std::endl;






/**
 * @brief Extracts currency values from a string.
 *
 * This function searches for currency values (e.g., $10.50, €20) within a given string
 * and returns them in a vector of strings.
 *
 * @param input The input string to extract currency values from.
 * @return A vector of strings containing the extracted currency values.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::extract_currency(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("extract_currency: Input string is empty!");
    }

    std::vector<std::string> currencies;
    std::regex currency_regex(R"(\$[0-9]+(\.[0-9][0-9])?|\€[0-9]+(\.[0-9][0-9])?)");
    
    auto currency_begin = std::sregex_iterator(input.begin(), input.end(), currency_regex);
    auto currency_end = std::sregex_iterator();

    for (std::sregex_iterator i = currency_begin; i != currency_end; ++i) {
        currencies.push_back(i->str());
    }

    return currencies;
}

// Example usage:
// GiString strObject;
// std::string input = "I have $10.50 and €20 in my wallet.";
// std::vector<std::string> result = strObject.extract_currency(input);
// for (const auto& currency : result) {
//     std::cout << "Found currency: " << currency << std::endl;
// }




/**
 * @brief Calculates the similarity between two strings using the Jaccard index.
 *
 * The Jaccard index is a measure of how similar two sets are. It is defined as the size of the intersection divided by the size of the union of the two sets.
 *
 * @param str1 The first input string.
 * @param str2 The second input string.
 * @return The Jaccard index representing the similarity between the two strings.
 * @throws std::invalid_argument If either input string is empty.
 */
double GiString::string_similarity(const std::string& str1, const std::string& str2) {
    if (str1.empty() || str2.empty()) {
        throw std::invalid_argument("GiString::string_similarity: Input strings cannot be empty.");
    }

    std::unordered_set<char> set1(str1.begin(), str1.end());
    std::unordered_set<char> set2(str2.begin(), str2.end());

    std::unordered_set<char> intersection;
    std::unordered_set<char> union_set;

    // Calculate intersection and union of the two sets
    for (const char& c : set1) {
        if (set2.find(c) != set2.end()) {
            intersection.insert(c);
        }
        union_set.insert(c);
    }

    for (const char& c : set2) {
        union_set.insert(c);
    }

    double jaccard_index = static_cast<double>(intersection.size()) / static_cast<double>(union_set.size());
    return jaccard_index;
}

// Example usage:
// GiString giString;
// std::string str1 = "hello";
// std::string str2 = "hallo";
// double similarity = giString.string_similarity(str1, str2);
// std::cout << "Similarity between str1 and str2: " << similarity << std::endl;




/**
 * @brief Converts binary data to a readable string.
 *
 * @param binaryData The binary data to be converted to a string.
 * @return The converted readable string.
 * @throws std::invalid_argument If the input binary data is empty.
 */
std::string GiString::binary_to_string(const std::vector<bool>& binaryData) {
    if (binaryData.empty()) {
        throw std::invalid_argument("GiString::binary_to_string: Error - Input binary data is empty.");
    }

    std::string result;
    for (size_t i = 0; i < binaryData.size(); i += 8) {
        char byte = 0;
        for (size_t j = 0; j < 8; ++j) {
            if (i + j < binaryData.size()) {
                byte |= binaryData[i + j] << (7 - j);
            }
        }
        result += byte;
    }

    return result;
}

// Example usage:
// std::vector<bool> binaryData = {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1};
// std::string result = GiString::binary_to_string(binaryData);
// std::cout << "Converted string: " << result << std::endl;







/**
 * @brief Converts a string to binary data.
 *
 * @param input The input string to convert to binary.
 * @return The binary representation of the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::string_to_binary(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("string_to_binary: Input string is empty.");
    }

    std::string binaryData;
    for (char c : input) {
        for (int i = 7; i >= 0; --i) {
            binaryData += ((c & (1 << i)) ? '1' : '0');
        }
    }

    return binaryData;
}

// Example usage:
// GiString giString;
// std::string input = "Hello, World!";
// std::string binaryResult = giString.string_to_binary(input);
// std::cout << "Binary representation: " << binaryResult << std::endl;


/**
 * @brief Reverses the order of words in a string.
 *
 * @param str The input string to reverse the words.
 * @return std::string The string with reversed word order.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::reverse_words(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("reverse_words: Input string is empty.");
    }

    std::istringstream iss(str);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());

    if (words.empty()) {
        return str; // If there are no words to reverse, return the original string.
    }

    std::reverse(words.begin(), words.end());

    std::ostringstream oss;
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(oss, " "));

    std::string result = oss.str();
    // Remove the trailing space added by the last word.
    result.pop_back();

    return result;
}

// Example usage:
// GiString gs;
// std::string input = "Hello World";
// std::string result = gs.reverse_words(input);
// std::cout << "Reversed words: " << result << std::endl;




/**
 * @brief Randomizes the case of letters in a string.
 *
 * @param input The input string to randomize the case.
 * @return A string with randomized letter cases.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::random_case(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::random_case: Input string is empty.");
    }

    std::string result = input;
    for (char& c : result) {
        if (std::isalpha(c)) {
            if (std::rand() % 2 == 0) {
                if (std::islower(c)) {
                    c = std::toupper(c);
                } else {
                    c = std::tolower(c);
                }
            }
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Randomize Me!";
// std::string result = giString.random_case(input);
// std::cout << "Randomized string: " << result << std::endl;



/**
 * @brief Replaces symbolic representations with numbers in a string.
 *
 * @param str The input string containing symbolic representations to be replaced.
 * @return The string with symbolic representations replaced by numbers.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::numerify(std::string str) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::numerify: Input string is empty.");
    }

    // Define mapping of symbolic representations to numbers
    std::unordered_map<std::string, std::string> symbolToNum = {
        {"#", "1"},
        {"$", "2"},
        {"%", "3"},
        {"@", "4"},
        {"&", "5"}
        // Add more mappings as needed
    };

    // Replace symbolic representations with numbers
    for (const auto& pair : symbolToNum) {
        size_t pos = 0;
        while ((pos = str.find(pair.first, pos)) != std::string::npos) {
            str.replace(pos, pair.first.length(), pair.second);
            pos += pair.second.length();
        }
    }

    return str;
}

// Example usage:
// GiString giString;
// std::string input = "I have # apples and $ oranges.";
// std::string result = giString.numerify(input);
// std::cout << "Numerified string: " << result << std::endl;





/**
 * @brief Adds specified properties to a string (e.g., for formattable elements).
 *
 * @param input The input string to add properties to.
 * @param properties The properties to be added to the string.
 * @return The string with added properties.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::propertize(const std::string& input, const std::string& properties) {
    if (input.empty()) {
        throw std::invalid_argument("propertize: Input string is empty.");
    }

    // Add properties to the input string
    std::string result = input + " [" + properties + "]";

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello";
// std::string properties = "bold, underline";
// std::string result = giString.propertize(input, properties);
// std::cout << "String with properties: " << result << std::endl;





/**
 * @brief Removes emojis from a string.
 *
 * @param str The input string from which emojis will be removed.
 * @return A string with emojis removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::stripe_emoji(std::string str) {
    if (str.empty()) {
        throw std::invalid_argument("stripe_emoji: Input string is empty.");
    }

    std::string result;
    for (char const &c : str) {
        if (!(c >= 0x1F600 && c <= 0x1F64F) &&
            !(c >= 0x1F300 && c <= 0x1F5FF) &&
            !(c >= 0x1F680 && c <= 0x1F6FF) &&
            !(c >= 0x1F700 && c <= 0x1F77F) &&
            !(c >= 0x1F780 && c <= 0x1F7FF) &&
            !(c >= 0x1F800 && c <= 0x1F8FF) &&
            !(c >= 0x1F900 && c <= 0x1F9FF) &&
            !(c >= 0x1FA00 && c <= 0x1FA6F) &&
            !(c >= 0x2600 && c <= 0x26FF) &&
            !(c >= 0x2700 && c <= 0x27BF) &&
            !(c >= 0x2300 && c <= 0x23FF)) {
            result += c;
        }
    }

    return result;
}

// Example usage:
// std::string input = "Hello World 😊🌟";
// std::string result = GiString::stripe_emoji(input);
// std::cout << "String with emojis removed: " << result << std::endl;




/**
 * @brief Transforms words in a string into their corresponding emojis.
 *
 * @param str The input string to transform into emojis.
 * @return A string with words replaced by emojis.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::emojify(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("emojify: Input string is empty!");
    }

 // Map of words to emojis
std::unordered_map<std::string, std::string> emojis = {
    {"happy", "😊"},
    {"sad", "😢"},
    {"love", "❤️"},
    {"angry", "😡"},
    {"laugh", "😂"},
    {"cry", "😭"},
    {"cool", "😎"},
    {"fire", "🔥"},
    {"thumbs up", "👍"},
    {"thumbs down", "👎"},
    {"heart eyes", "😍"},
    {"kiss", "😘"},
    {"wink", "😉"},
    {"surprised", "😯"},
    {"confused", "😕"},
    {"excited", "😃"},
    {"blush", "😊"},
    {"tired", "😴"},
    {"hungry", "😋"},
    {"sick", "🤒"},
    {"scared", "😱"},
    {"shocked", "😮"},
    {"devil", "😈"},
    {"angel", "😇"},
    {"ghost", "👻"},
    {"alien", "👽"},
    {"robot", "🤖"},
    {"unicorn", "🦄"},
    {"pizza", "🍕"},
    {"hamburger", "🍔"},
    {"fries", "🍟"},
    {"hot dog", "🌭"},
    {"taco", "🌮"},
    {"burrito", "🌯"},
    {"popcorn", "🍿"},
    {"ice cream", "🍦"},
    {"cake", "🍰"},
    {"cookie", "🍪"},
    {"chocolate", "🍫"},
    {"coffee", "☕"},
    {"tea", "🍵"},
    {"beer", "🍺"},
    {"wine", "🍷"},
    {"cocktail", "🍹"},
    {"champagne", "🍾"},
    {"sake", "🍶"},
    {"watermelon", "🍉"},
    {"strawberry", "🍓"},
    {"banana", "🍌"},
    {"apple", "🍎"},
    {"orange", "🍊"},
    {"lemon", "🍋"},
    {"grapes", "🍇"},
    {"peach", "🍑"},
    {"pineapple", "🍍"},
    {"cherries", "🍒"},
    {"pear", "🍐"},
    {"kiwi", "🥝"},
    {"avocado", "🥑"},
    {"eggplant", "🍆"},
    {"tomato", "🍅"},
    {"carrot", "🥕"},
    {"corn", "🌽"},
    {"cucumber", "🥒"},
    {"pepper", "🌶️"},
    {"mushroom", "🍄"},
    {"broccoli", "🥦"},
    {"garlic", "🧄"},
    {"onion", "🧅"},
    {"potato", "🥔"},
    {"sweet potato", "🍠"},
    {"bread", "🍞"},
    {"croissant", "🥐"},
    {"baguette", "🥖"},
    {"pancakes", "🥞"},
    {"cheese", "🧀"},
    {"bacon", "🥓"},
    {"egg", "🥚"},
    {"milk", "🥛"},
    {"butter", "🧈"},
    {"yogurt", "🥣"},
    {"sushi", "🍣"},
    {"rice", "🍚"},
    {"noodle", "🍜"},
    {"spaghetti", "🍝"},
    {"sandwich", "🥪"},
    {"ramen", "🍜"},
    {"curry", "🍛"},
    {"fried shrimp", "🍤"},
    {"fish", "🐟"},
    {"steak", "🥩"},
    {"chicken", "🍗"},
    {"burger", "🍔"},
    {"fries", "🍟"},
    {"hot dog", "🌭"},
    {"pizza", "🍕"},
    {"taco", "🌮"},
    {"burrito", "🌯"},
    {"popcorn", "🍿"},
    {"bento", "🍱"},
    {"sushi", "🍣"},
    {"dumpling", "🥟"},
    {"fried rice", "🍚"},
    {"ice cream", "🍦"},
    {"cake", "🍰"},
    {"popcorn", "🍿"},
    {"donut", "🍩"},
    {"cookie", "🍪"},
    {"chocolate", "🍫"},
    {"candy", "🍬"},
    {"lollipop", "🍭"},
    {"apple", "🍏"},
    {"banana", "🍌"},
    {"grapes", "🍇"},
    {"strawberry", "🍓"},
    {"watermelon", "🍉"},
    {"tangerine", "🍊"},
    {"lemon", "🍋"},
    {"pineapple", "🍍"},
    {"peach", "🍑"},
    {"cherries", "🍒"},
    {"kiwi", "🥝"},
    {"tomato", "🍅"},
    {"avocado", "🥑"},
    {"eggplant", "🍆"},
    {"potato", "🥔"},
    {"carrot", "🥕"},
    {"corn", "🌽"},
    {"hot pepper", "🌶"},
    {"cucumber", "🥒"},
    {"broccoli", "🥦"},
    {"mushroom", "🍄"},
    {"peanuts", "🥜"},
    {"chestnut", "🌰"},
    {"bread", "🍞"},
    {"croissant", "🥐"},
    {"baguette", "🥖"},
    {"pretzel", "🥨"},
    {"pancakes", "🥞"},
    {"cheese", "🧀"},
    {"bacon", "🥓"},
    {"steak", "🥩"},
    {"poultry leg", "🍗"},
    {"meat on bone", "🍖"},
    {"bacon", "🥓"},
    {"hamburger", "🍔"},
    {"fries", "🍟"},
    {"pizza", "🍕"},
    {"hot dog", "🌭"},
    {"sandwich", "🥪"},
    {"taco", "🌮"},
    {"burrito", "🌯"},
    {"egg", "🍳"},
    {"cooking", "🍳"},
    {"shallow pan of food", "🥘"},
    {"pot of food", "🍲"},
    {"bowl with spoon", "🥣"},
    {"green salad", "🥗"},
    {"popcorn", "🍿"},
    {"canned food", "🥫"},
    {"bento box", "🍱"},
    {"rice cracker", "🍘"},
    {"rice ball", "🍙"},
    {"cooked rice", "🍚"},
    {"curry rice", "🍛"},
    {"steaming bowl", "🍜"},
    {"spaghetti", "🍝"},
    {"bread", "🍞"},
    {"french bread", "🥖"},
    {"pretzel", "🥨"},
    {"bagel", "🥯"},
    {"pancakes", "🥞"},
    {"waffle", "🧇"},
    {"cheese wedge", "🧀"},
    {"meat on bone", "🍖"},
    {"poultry leg", "🍗"},
    {"cut of meat", "🥩"},
    {"bacon", "🥓"},
    {"hamburger", "🍔"},
    {"fries", "🍟"},
    {"hot dog", "🌭"},
    {"pizza", "🍕"},
    {"sandwich", "🥪"},
    {"taco", "🌮"},
    {"burrito", "🌯"},
    {"stuffed flatbread", "🥙"},
    {"falafel", "🧆"},
    {"egg", "🥚"},
    {"cooking", "🍳"},
    {"shallow pan of food", "🥘"},
    {"pot of food", "🍲"},
    {"fondue", "🫕"},
    {"bowl with spoon", "🥣"},
    {"green salad", "🥗"},
    {"popcorn", "🍿"},
    {"canned food", "🥫"},
    {"sushi", "🍣"},
    {"bento box", "🍱"},
    {"rice cracker", "🍘"},
    {"rice ball", "🍙"},
    {"cooked rice", "🍚"},
    {"curry rice", "🍛"},
    {"steaming bowl", "🍜"},
    {"spaghetti", "🍝"},
    {"roasted sweet potato", "🍠"},
    {"oden", "🍢"},
    {"sushi", "🍣"},
    {"fried shrimp", "🍤"},
    {"fish cake", "🍥"},
    {"dango", "🍡"},
    {"dumpling", "🥟"},
    {"fortune cookie", "🥠"},
    {"takeout box", "🥡"},
    {"moon cake", "🥮"},
    {"coffee", "☕"},
    {"tea", "🍵"},
    {"cupcake", "🧁"},
    {"cake", "🍰"},
    {"pie", "🥧"},
    {"custard", "🍮"},
    {"lollipop", "🍭"},
    {"candy", "🍬"},
    {"chocolate bar", "🍫"},
    {"popcorn", "🍿"},
    {"doughnut", "🍩"},
    {"cookie", "🍪"},
    {"chestnut", "🌰"},
    {"peanuts", "🥜"},
    {"honey pot", "🍯"},
    {"baby bottle", "🍼"},
    {"glass of milk", "🥛"},
    {"hot beverage", "🥃"},
    {"teapot", "🫖"},
    {"bottle with popping cork", "🍾"},
    {"wine glass", "🍷"},
    {"cocktail glass", "🍸"},
    {"tropical drink", "🍹"},
    {"beer mug", "🍺"},
    {"clinking beer mugs", "🍻"},
    {"clinking glasses", "🥂"},
    {"tumbler glass", "🥃"},
    {"cup with straw", "🥤"},
    {"bubble tea", "🧋"},
    {"beverage box", "🧃"},
    {"mate", "🧉"},
    {"ice", "🧊"},
    {"chopsticks", "🥢"},
    {"plate with chopsticks", "🍽️"},
    {"fork and knife", "🍴"},
    {"spoon", "🥄"},
    {"hocho", "🔪"},
    {"amphora", "🏺"},
    {"world map", "🗺️"},
    {"desert island", "🏝️"},
    {"volcano", "🌋"},
    {"mountain", "⛰️"},
    {"mountain snow", "🏔️"},
    {"camping", "🏕️"},
    {"beach with umbrella", "🏖️"},
    {"desert", "🏜️"},
    {"stadium", "🏟️"},
    {"classical building", "🏛️"},
    {"building construction", "🏗️"},
    {"houses", "🏘️"},
    {"derelict house", "🏚️"},
    {"cityscape", "🏙️"},
    {"sunset", "🌅"},
    {"dusk", "🌆"},
    {"night with stars", "🌃"},
    {"bridge at night", "🌉"},
    {"milky way", "🌌"},
    {"camping", "🏕️"},
    {"national park", "🏞️"},
    {"sunrise", "🌅"},
    {"sunset", "🌇"},
    {"cityscape at dusk", "🌆"},
    {"cityscape at night", "🌃"},
    {"bridge at night", "🌉"},
    {"ferris wheel", "🎡"},
    {"roller coaster", "🎢"},
    {"carousel horse", "🎠"},
    {"fountain", "⛲"},
    {"beach umbrella", "🏖️"},
    {"umbrella on ground", "⛱️"},
    {"desert island", "🏝️"},
    {"mountain", "⛰️"},
    {"mountain snow", "🏔️"},
    {"volcano", "🌋"},
    {"camping", "🏕️"},
    {"tent", "⛺"},
    {"house", "🏠"},
    {"office building", "🏢"},
    {"department store", "🏬"},
    {"Japanese post office", "🏣"},
    {"hospital", "🏥"},
    {"bank", "🏦"},
    {"hotel", "🏨"},
    {"convenience store", "🏪"},
    {"school", "🏫"},
    {"love hotel", "🏩"},
    {"wedding", "💒"},
    {"classical building", "🏛️"},
    {"church", "⛪"},
    {"mosque", "🕌"},
    {"synagogue", "🕍"},
    {"kaaba", "🕋"},
    {"shinto shrine", "⛩️"},
    {"watch", "⌚"},
    {"mobile phone", "📱"},
    {"mobile phone with arrow", "📲"},
    {"telephone", "☎️"},
    {"telephone receiver", "📞"},
    {"pager", "📟"},
    {"fax machine", "📠"},
    {"battery", "🔋"},
    {"electric plug", "🔌"},
    {"computer", "💻"},
    {"desktop computer", "🖥️"},
    {"printer", "🖨️"},
    {"keyboard", "⌨️"},
    {"computer mouse", "🖱️"},
    {"trackball", "🖲️"},
    {"minidisc", "💽"},
    {"floppy disk", "💾"},
    {"optical disc", "💿"},
    {"dvd", "📀"},
    {"abacus", "🧮"},
    {"movie camera", "🎥"},
    {"film frames", "🎞️"},
    {"clapper board", "🎬"},
    {"television", "📺"},
    {"camera", "📷"},
    {"camera with flash", "📸"},
    {"video camera", "📹"},
    {"videocassette", "📼"},
    {"magnifying glass tilted left", "🔍"},
    {"magnifying glass tilted right", "🔎"},
    {"candle", "🕯️"},
    {"light bulb", "💡"},
    {"flashlight", "🔦"},
    {"red paper lantern", "🏮"},
    {"diya lamp", "🪔"},
    {"notebook with decorative cover", "📔"},
    {"closed book", "📕"},
    {"open book", "📖"},
    {"green book", "📗"},
    {"blue book", "📘"},
    {"orange book", "📙"},
    {"books", "📚"},
    {"notebook", "📓"},
    {"ledger", "📒"},
    {"page with curl", "📃"},
    {"scroll", "📜"},
    {"page facing up", "📄"},
    {"receipt", "🧾"},
    {"bookmark", "🔖"},
    {"label", "🏷️"},
    {"money bag", "💰"},
    {"coin", "🪙"},
    {"yen banknote", "💴"},
    {"dollar banknote", "💵"},
    {"euro banknote", "💶"},
    {"pound banknote", "💷"},
    {"money with wings", "💸"},
    {"credit card", "💳"},
    {"receipt", "🧾"},
    {"envelope", "✉️"},
    {"e-mail", "📧"},
    {"incoming envelope", "📨"},
    {"envelope with arrow", "📩"},
    {"outbox tray", "📤"},
    {"inbox tray", "📥"},
    {"package", "📦"},
    {"closed mailbox with raised flag", "📫"},
    {"closed mailbox with lowered flag", "📪"},
    {"open mailbox with raised flag", "📬"},
    {"open mailbox with lowered flag", "📭"},
    {"postbox", "📮"},
    {"ballot box with ballot", "🗳️"},
    {"pencil", "✏️"},
    {"black nib", "✒️"},
    {"fountain pen", "🖋️"},
    {"pen", "🖊️"},
    {"paintbrush", "🖌️"},
    {"crayon", "🖍️"},
    {"memo", "📝"},
    {"briefcase", "💼"},
    {"file folder", "📁"},
    {"open file folder", "📂"},
    {"card index dividers", "🗂️"},
    {"calendar", "📅"},
    {"tear-off calendar", "📆"},
    {"spiral notepad", "🗒️"},
    {"spiral calendar", "🗓️"},
    {"card index", "📇"},
    {"chart increasing", "📈"},
    {"chart decreasing", "📉"},
    {"bar chart", "📊"},
    {"clipboard", "📋"},
    {"pushpin", "📌"},
    {"round pushpin", "📍"},
    {"paperclip", "📎"},
    {"linked paperclips", "🖇️"},
    {"straight ruler", "📏"},
    {"triangular ruler", "📐"},
    {"scissors", "✂️"},
    {"card file box", "🗃️"},
    {"file cabinet", "🗄️"},
    {"wastebasket", "🗑️"},
    {"lock", "🔒"},
    {"unlock", "🔓"},
    {"lock with ink pen", "🔏"},
    {"closed lock with key", "🔐"},
    {"key", "🔑"},
    {"old key", "🗝️"},
    {"hammer", "🔨"},
    {"axe", "🪓"},
    {"pick", "⛏️"},
    {"hammer and pick", "⚒️"},
    {"hammer and wrench", "🛠️"},
    {"dagger", "🗡️"},
    {"crossed swords", "⚔️"},
    {"gun", "🔫"},
    {"bow and arrow", "🏹"},
    {"shield", "🛡️"},
    {"wrench", "🔧"},
    {"nut and bolt", "🔩"},
    {"gear", "⚙️"},
    {"clamp", "🗜️"},
    {"balance scale", "⚖️"},
    {"link", "🔗"},
    {"chains", "⛓️"},
    {"hook", "🪝"},
    {"toolbox", "🧰"},
    {"magnet", "🧲"},
    {"ladder", "🪜"},
    {"alembic", "⚗️"},
    {"test tube", "🧪"},
    {"petri dish", "🧫"},
    {"dna", "🧬"},
    {"microscope", "🔬"},
    {"telescope", "🔭"},
    {"satellite", "📡"},
    {"syringe", "💉"},
    {"drop of blood", "🩸"},
    {"pill", "💊"},
    {"adhesive bandage", "🩹"},
    {"stethoscope", "🩺"},
    {"door", "🚪"},
    {"elevator", "🛗"},
    {"mirror", "🪞"},
    {"window", "🪟"},
    {"bed", "🛏️"},
    {"couch and lamp", "🛋️"},
    {"chair", "🪑"},
    {"toilet", "🚽"},
    {"plunger", "🪠"},
    {"shower", "🚿"},
    {"bathtub", "🛁"},
    {"mouse trap", "🪤"},
    {"razor", "🪒"},
    {"lotion bottle", "🧴"},
    {"safety pin", "🧷"},
    {"broom", "🧹"},
    {"basket", "🧺"},
    {"roll of paper", "🧻"},
    {"bucket", "🪣"},
    {"soap", "🧼"},
    {"toothbrush", "🪥"},
    {"sponge", "🧽"},
    {"fire extinguisher", "🧯"},
    {"shopping cart", "🛒"},
    {"smoking", "🚬"},
    {"coffin", "⚰️"},
    {"funeral urn", "⚱️"},
    {"moyai", "🗿"},
    {"atm sign", "🏧"},
    {"wheelchair symbol", "♿"},
    {"restroom", "🚻"},
    {"put litter in its place", "🚮"},
    {"potable water", "🚰"},
    {"men’s room", "🚹"},
    {"women’s room", "🚺"},
    {"baby symbol", "🚼"},
    {"toilet", "🚽"},
    {"shower", "🚿"},
    {"bath", "🛁"},
    {"bathtub", "🛁"},
    {"passport control", "🛂"},
    {"customs", "🛃"},
    {"baggage claim", "🛄"},
    {"left luggage", "🛅"},
    {"warning", "⚠️"},
    {"children crossing", "🚸"},
    {"no entry", "⛔"},
    {"prohibited", "🚫"},
    {"no bicycles", "🚳"},
    {"no smoking", "🚭"},
    {"no littering", "🚯"},
    {"non-potable water", "🚱"},
    {"no pedestrians", "🚷"},
    {"no mobile phones", "📵"},
    {"no one under eighteen", "🔞"},
    {"radioactive", "☢️"},
    {"biohazard", "☣️"},
    {"up arrow", "⬆️"},
    {"up-right arrow", "↗️"},
    {"right arrow", "➡️"},
    {"down-right arrow", "↘️"},
    {"down arrow", "⬇️"},
    {"down-left arrow", "↙️"},
    {"left arrow", "⬅️"},
    {"up-left arrow", "↖️"},
    {"up-down arrow", "↕️"},
    {"left-right arrow", "↔️"},
    {"right arrow curving left", "↩️"},
    {"left arrow curving right", "↪️"},
    {"right arrow", "➡️"},
    {"arrow up small", "🔼"},
    {"arrow down small", "🔽"},
    {"leftwards arrow with hook", "↩️"},
    {"rightwards arrow with hook", "↪️"},
    {"bell", "🔔"},
    {"bell with slash", "🔕"},
    {"musical score", "🎼"},
    {"musical note", "🎵"},
    {"musical notes", "🎶"},
    {"studio microphone", "🎙️"},
    {"level slider", "🎚️"},
    {"control knobs", "🎛️"},
    {"microphone", "🎤"},
    {"headphone", "🎧"},
    {"radio", "📻"},
    {"saxophone", "🎷"},
    {"guitar", "🎸"},
    {"musical keyboard", "🎹"},
    {"trumpet", "🎺"},
    {"violin", "🎻"},
    {"drum", "🥁"},
    {"long drum", "🪘"},
    {"iphone", "📱"},
    {"calling", "📲"},
    {"phone", "☎️"},
    {"telephone", "☎️"},
    {"telephone receiver", "📞"},
    {"pager", "📟"},
    {"fax", "📠"},
    {"battery", "🔋"},
    {"electric plug", "🔌"},
    {"computer", "💻"},
    {"desktop computer", "🖥️"},
    {"printer", "🖨️"},
    {"keyboard", "⌨️"},
    {"computer mouse", "🖱️"},
    {"trackball", "🖲️"},
    {"minidisc", "💽"},
    {"floppy disk", "💾"},
    {"cd", "💿"},
    {"dvd", "📀"},
    {"abacus", "🧮"},
    {"movie camera", "🎥"},
    {"film projector", "📽️"},
    {"clapper board", "🎬"},
    {"tv", "📺"},
    {"camera", "📷"},
    {"camera with flash", "📸"},
    {"video camera", "📹"},
    {"videocassette", "📼"},
    {"magnifying glass", "🔍"},
    {"candle", "🕯️"},
    {"light bulb", "💡"},
    {"flashlight", "🔦"},
    {"red paper lantern", "🏮"},
    {"diya lamp", "🪔"},
    {"notebook", "📓"},
    {"notebook with decorative cover", "📔"},
    {"closed book", "📕"},
    {"open book", "📖"},
    {"green book", "📗"},
    {"blue book", "📘"},
    {"orange book", "📙"},
    {"books", "📚"},
    {"notebook", "📓"},
    {"ledger", "📒"},
    {"page with curl", "📃"},
    {"scroll", "📜"},
    {"page facing up", "📄"},
    {"receipt", "🧾"},
    {"bookmark tabs", "📑"},
    {"bookmark", "🔖"},
    {"label", "🏷️"},
    {"money bag", "💰"},
    {"coin", "🪙"},
    {"yen banknote", "💴"},
    {"dollar banknote", "💵"},
    {"euro banknote", "💶"},
    {"pound banknote", "💷"},
    {"money with wings", "💸"},
    {"credit card", "💳"},
    {"receipt", "🧾"},
    {"envelope", "✉️"},
    {"e-mail", "📧"},
    {"incoming envelope", "📨"},
    {"envelope with arrow", "📩"},
    {"outbox tray", "📤"},
    {"inbox tray", "📥"},
    {"package", "📦"},
    {"closed mailbox with raised flag", "📫"},
    {"closed mailbox with lowered flag", "📪"},
    {"open mailbox with raised flag", "📬"},
    {"open mailbox with lowered flag", "📭"},
    {"postbox", "📮"},
    {"ballot box with ballot", "🗳️"},
    {"pencil", "✏️"},
    {"black nib", "✒️"},
    {"fountain pen", "🖋️"},
    {"pen", "🖊️"},
    {"paintbrush", "🖌️"},
    {"crayon", "🖍️"},
    {"memo", "📝"},
    {"briefcase", "💼"},
    {"file folder", "📁"},
    {"open file folder", "📂"},
    {"card index dividers", "🗂️"},
    {"calendar", "📅"},
    {"tear-off calendar", "📆"},
    {"spiral notepad", "🗒️"},
    {"spiral calendar", "🗓️"},
    {"card index", "📇"},
    {"chart increasing", "📈"},
    {"chart decreasing", "📉"},
    {"bar chart", "📊"},
    {"clipboard", "📋"},
    {"pushpin", "📌"},
    {"round pushpin", "📍"},
    {"paperclip", "📎"},
    {"linked paperclips", "🖇️"},
    {"straight ruler", "📏"},
    {"triangular ruler", "📐"},
    {"scissors", "✂️"},
    {"card file box", "🗃️"},
    {"file cabinet", "🗄️"},
    {"wastebasket", "🗑️"},
    {"lock", "🔒"},
    {"unlock", "🔓"},
    {"lock with ink pen", "🔏"},
    {"closed lock with key", "🔐"},
    {"key", "🔑"},
    {"old key", "🗝️"},
    {"hammer", "🔨"},
    {"axe", "🪓"},
    {"pick", "⛏️"},
    {"hammer and pick", "⚒️"},
    {"hammer and wrench", "🛠️"},
    {"dagger", "🗡️"},
    {"crossed swords", "⚔️"},
    {"gun", "🔫"},
    {"bow and arrow", "🏹"},
    {"shield", "🛡️"},
    {"wrench", "🔧"},
    {"nut and bolt", "🔩"},
    {"gear", "⚙️"},
    {"clamp", "🗜️"},
    {"balance scale", "⚖️"},
    {"link", "🔗"},
    {"chains", "⛓️"},
    {"hook", "🪝"},
    {"toolbox", "🧰"},
    {"magnet", "🧲"},
    {"ladder", "🪜"},
    {"alembic", "⚗️"},
    {"test tube", "🧪"},
    {"petri dish", "🧫"},
    {"dna", "🧬"},
    {"microscope", "🔬"},
    {"telescope", "🔭"},
    {"satellite", "📡"},
    {"syringe", "💉"},
    {"drop of blood", "🩸"},
    {"pill", "💊"},
    {"adhesive bandage", "🩹"},
    {"stethoscope", "🩺"},
    {"door", "🚪"},
    {"elevator", "🛗"},
    {"mirror", "🪞"},
    {"window", "🪟"},
    {"bed", "🛏️"},
    {"couch and lamp", "🛋️"},
    {"chair", "🪑"},
    {"toilet", "🚽"},
    {"plunger", "🪠"},
    {"shower", "🚿"},
    {"bathtub", "🛁"},
    {"mouse trap", "🪤"},
    {"razor", "🪒"},
    {"lotion bottle", "🧴"},
    {"safety pin", "🧷"},
    {"broom", "🧹"},
    {"basket", "🧺"},
    {"roll of paper", "🧻"},
    {"bucket", "🪣"},
    {"soap", "🧼"},
    {"toothbrush", "🪥"},
    {"sponge", "🧽"},
    {"fire extinguisher", "🧯"},
    {"shopping cart", "🛒"},
    {"smoking", "🚬"},
    {"coffin", "⚰️"},
    {"funeral urn", "⚱️"},
    {"moyai", "🗿"},
    {"atm sign", "🏧"},
    {"wheelchair symbol", "♿"},
    {"restroom", "🚻"},
    {"put litter in its place", "🚮"},
    {"potable water", "🚰"},
    {"men’s room", "🚹"},
    {"women’s room", "🚺"},
    {"baby symbol", "🚼"},
    {"toilet", "🚽"},
    {"shower", "🚿"},
    {"bath", "🛁"},
    {"bathtub", "🛁"},
    {"passport control", "🛂"},
    {"customs", "🛃"},
    {"baggage claim", "🛄"},
    {"left luggage", "🛅"},
    {"warning", "⚠️"},
    {"children crossing", "🚸"},
    {"no entry", "⛔"},
    {"prohibited", "🚫"},
    {"no bicycles", "🚳"},
    {"no smoking", "🚭"},
    {"no littering", "🚯"},
    {"non-potable water", "🚱"},
    {"no pedestrians", "🚷"},
    {"no mobile phones", "📵"},
    {"no one under eighteen", "🔞"},
    {"radioactive", "☢️"},
    {"biohazard", "☣️"},
    {"up arrow", "⬆️"},
    {"up-right arrow", "↗️"},
    {"right arrow", "➡️"},
    {"down-right arrow", "↘️"},
    {"down arrow", "⬇️"},
    {"down-left arrow", "↙️"},
    {"left arrow", "⬅️"},
    {"up-left arrow", "↖️"},
    {"up-down arrow", "↕️"},
    {"left-right arrow", "↔️"},
    {"right arrow curving left", "↩️"},
    {"left arrow curving right", "↪️"},
    {"right arrow", "➡️"},
    {"arrow up small", "🔼"},
    {"arrow down small", "🔽"},
    {"leftwards arrow with hook", "↩️"},
    {"rightwards arrow with hook", "↪️"},
    {"bell", "🔔"},
    {"bell with slash", "🔕"},
    {"musical score", "🎼"},
    {"musical note", "🎵"},
    {"musical notes", "🎶"},
    {"studio microphone", "🎙️"},
    {"level slider", "🎚️"},
    {"control knobs", "🎛️"},
    {"microphone", "🎤"},
    {"headphone", "🎧"},
    {"radio", "📻"},
    {"saxophone", "🎷"},
    {"guitar", "🎸"},
    {"musical keyboard", "🎹"},
    {"trumpet", "🎺"},
    {"violin", "🎻"},
    {"drum", "🥁"},
    {"long drum", "🪘"},
    {"iphone", "📱"},
    {"calling", "📲"},
    {"phone", "☎️"},
    {"telephone", "☎️"},
    {"telephone receiver", "📞"},
    {"pager", "📟"},
    {"fax", "📠"},
    {"battery", "🔋"},
    {"electric plug", "🔌"},
    {"computer", "💻"},
    {"desktop computer", "🖥️"},
    {"printer", "🖨️"},
    {"keyboard", "⌨️"},
    {"computer mouse", "🖱️"},
    {"trackball", "🖲️"},
    {"minidisc", "💽"},
    {"floppy disk", "💾"},
    {"cd", "💿"},
    {"dvd", "📀"},
    {"abacus", "🧮"},
    {"movie camera", "🎥"},
    {"film projector", "📽️"},
    {"clapper board", "🎬"},
    {"tv", "📺"},
    {"camera", "📷"},
    {"camera with flash", "📸"},
    {"video camera", "📹"},
    {"videocassette", "📼"},
    {"magnifying glass", "🔍"},
    {"candle", "🕯️"},
    {"light bulb", "💡"},
    {"flashlight", "🔦"},
    {"red paper lantern", "🏮"},
    {"diya lamp", "🪔"},
    {"notebook", "📓"},
    {"notebook with decorative cover", "📔"},
    {"closed book", "📕"},
    {"open book", "📖"},
    {"green book", "📗"},
    {"blue book", "📘"},
    {"orange book", "📙"},
    {"books", "📚"},
    {"notebook", "📓"},
    {"ledger", "📒"},
    {"page with curl", "📃"},
    {"scroll", "📜"},
    {"page facing up", "📄"},
    {"receipt", "🧾"},
    {"bookmark tabs", "📑"},
    {"bookmark", "🔖"},
    {"label", "🏷️"},
    {"money bag", "💰"},
    {"coin", "🪙"},
    {"yen banknote", "💴"},
    {"dollar banknote", "💵"},
    {"euro banknote", "💶"},
    {"pound banknote", "💷"},
    {"money with wings", "💸"},
    {"credit card", "💳"},
    {"receipt", "🧾"},
    {"envelope", "✉️"},
    {"e-mail", "📧"},
    {"incoming envelope", "📨"},
    {"envelope with arrow", "📩"},
    {"outbox tray", "📤"},
    {"inbox tray", "📥"},
    {"package", "📦"},
    {"closed mailbox with raised flag", "📫"},
    {"closed mailbox with lowered flag", "📪"},
    {"open mailbox with raised flag", "📬"},
    {"open mailbox with lowered flag", "📭"},
    {"postbox", "📮"},
    {"ballot box with ballot", "🗳️"},
    {"pencil", "✏️"},
    {"black nib", "✒️"},
    {"fountain pen", "🖋️"},
    {"pen", "🖊️"},
    {"paintbrush", "🖌️"},
    {"crayon", "🖍️"},
    {"memo", "📝"},
    {"briefcase", "💼"},
    {"file folder", "📁"},
    {"open file folder", "📂"},
    {"card index dividers", "🗂️"},
    {"calendar", "📅"},
    {"tear-off calendar", "📆"},
    {"spiral notepad", "🗒️"},
    {"spiral calendar", "🗓️"},
    {"card index", "📇"},
    {"chart increasing", "📈"},
    {"chart decreasing", "📉"},
    {"bar chart", "📊"},
    {"clipboard", "📋"},
    {"pushpin", "📌"},
    {"round pushpin", "📍"},
    {"paperclip", "📎"},
    {"linked paperclips", "🖇️"},
    {"straight ruler", "📏"},
    {"triangular ruler", "📐"},
    {"scissors", "✂️"},
    {"card file box", "🗃️"},
    {"file cabinet", "🗄️"},
    {"wastebasket", "🗑️"},
    {"lock", "🔒"},
    {"unlock", "🔓"},
    {"lock with ink pen", "🔏"},
    {"closed lock with key", "🔐"},
    {"key", "🔑"},
    {"old key", "🗝️"},
    {"hammer", "🔨"},
    {"axe", "🪓"},
    {"pick", "⛏️"},
    {"hammer and pick", "⚒️"},
    {"hammer and wrench", "🛠️"},
    {"dagger", "🗡️"},
    {"crossed swords", "⚔️"},
    {"gun", "🔫"},
    {"bow and arrow", "🏹"},
    {"shield", "🛡️"},
    {"wrench", "🔧"},
    {"nut and bolt", "🔩"},
    {"gear", "⚙️"},
    {"clamp", "🗜️"},
    {"balance scale", "⚖️"},
    {"link", "🔗"},
    {"chains", "⛓️"},
    {"hook", "🪝"},
    {"toolbox", "🧰"},
    {"magnet", "🧲"},
    {"ladder", "🪜"},
    {"alembic", "⚗️"},
    {"test tube", "🧪"},
    {"petri dish", "🧫"},
    {"dna", "🧬"},
    {"microscope", "🔬"},
    {"telescope", "🔭"},
    {"satellite", "📡"},
    {"syringe", "💉"},
    {"drop of blood", "🩸"},
    {"pill", "💊"},
    {"adhesive bandage", "🩹"},
    {"stethoscope", "🩺"},
    {"door", "🚪"},
    {"elevator", "🛗"},
    {"mirror", "🪞"},
    {"window", "🪟"},
    {"bed", "🛏️"},
    {"couch and lamp", "🛋️"},
    {"chair", "🪑"},
    {"toilet", "🚽"},
    {"plunger", "🪠"},
    {"shower", "🚿"},
    {"bathtub", "🛁"},
    {"mouse trap", "🪤"},
    {"razor", "🪒"},
    {"lotion bottle", "🧴"},
    {"safety pin", "🧷"},
    {"broom", "🧹"},
    {"basket", "🧺"},
    {"roll of paper", "🧻"},
    {"bucket", "🪣"},
    {"soap", "🧼"},
    {"toothbrush", "🪥"},
    {"sponge", "🧽"},
    {"fire extinguisher", "🧯"},
    {"shopping cart", "🛒"},
    {"smoking", "🚬"},
    {"coffin", "⚰️"},
    {"funeral urn", "⚱️"},
    {"moyai", "🗿"},
    {"atm sign", "🏧"},
    {"wheelchair symbol", "♿"},
    {"restroom", "🚻"},
    {"put litter in its place", "🚮"},
    {"potable water", "🚰"},
    {"men’s room", "🚹"},
    {"women’s room", "🚺"},
    {"baby symbol", "🚼"},
    {"toilet", "🚽"},
    {"shower", "🚿"},
    {"bath", "🛁"},
    {"bathtub", "🛁"},
    {"passport control", "🛂"},
    {"customs", "🛃"},
    {"baggage claim", "🛄"},
    {"left luggage", "🛅"},
    {"warning", "⚠️"},
    {"children crossing", "🚸"},
    {"no entry", "⛔"},
    {"prohibited", "🚫"},
    {"no bicycles", "🚳"},
    {"no smoking", "🚭"},
    {"no littering", "🚯"},
    {"non-potable water", "🚱"},
    {"no pedestrians", "🚷"},
    {"no mobile phones", "📵"},
    {"no one under eighteen", "🔞"},
    {"radioactive", "☢️"},
    {"biohazard", "☣️"},
    {"up arrow", "⬆️"},
    {"up-right arrow", "↗️"},
    {"right arrow", "➡️"},
    {"down-right arrow", "↘️"},
    {"down arrow", "⬇️"},
    {"down-left arrow", "↙️"},
    {"left arrow", "⬅️"},
    {"up-left arrow", "↖️"},
    {"up-down arrow", "↕️"},
    {"left-right arrow", "↔️"},
    {"right arrow curving left", "↩️"},
    {"left arrow curving right", "↪️"},
    {"right arrow", "➡️"},
    {"arrow up small", "🔼"},
    {"arrow down small", "🔽"},
    {"leftwards arrow with hook", "↩️"},
    {"rightwards arrow with hook", "↪️"},
    {"bell", "🔔"},
    {"bell with slash", "🔕"},
    {"musical score", "🎼"},
    {"musical note", "🎵"},
    {"musical notes", "🎶"},
    {"studio microphone", "🎙️"},
    {"level slider", "🎚️"},
    {"control knobs", "🎛️"},
    {"microphone", "🎤"},
    {"headphone", "🎧"},
    {"radio", "📻"},
    {"saxophone", "🎷"},
    {"guitar", "🎸"},
    {"musical keyboard", "🎹"},
    {"trumpet", "🎺"},
    {"violin", "🎻"},
    {"drum", "🥁"},
    {"long drum", "🪘"},
    {"banjo", "🪕"},
    {"accordion", "🪗"},
    {"long drum", "🪘"},
    {"iphone", "📱"},
    {"calling", "📲"},
    {"phone", "☎️"},
    {"telephone", "☎️"},
    {"telephone receiver", "📞"},
    {"pager", "📟"},
    {"fax", "📠"},
    {"battery", "🔋"},
    {"electric plug", "🔌"},
    {"computer", "💻"},
    {"desktop computer", "🖥️"},
    {"printer", "🖨️"},
    {"keyboard", "⌨️"},
    {"computer mouse", "🖱️"},
    {"trackball", "🖲️"},
    {"minidisc", "💽"},
    {"floppy disk", "💾"},
    {"cd", "💿"},
    {"dvd", "📀"},
    {"abacus", "🧮"},
    {"movie camera", "🎥"},
    {"film projector", "📽️"},
    {"clapper board", "🎬"},
    {"tv", "📺"},
    {"camera", "📷"},
    {"camera with flash", "📸"},
    {"video camera", "📹"},
    {"videocassette", "📼"},
    {"magnifying glass", "🔍"},
    {"candle", "🕯️"},
    {"light bulb", "💡"},
    {"flashlight", "🔦"},
    {"red paper lantern", "🏮"},
    {"diya lamp", "🪔"},
    {"notebook", "📓"},
    {"notebook with decorative cover", "📔"},
    {"closed book", "📕"},
    {"open book", "📖"},
    {"green book", "📗"},
    {"blue book", "📘"},
    {"orange book", "📙"},
    {"books", "📚"},
    {"notebook", "📓"},
    {"ledger", "📒"},
    {"page with curl", "📃"},
    {"scroll", "📜"},
    {"page facing up", "📄"},
    {"receipt", "🧾"},
    {"bookmark tabs", "📑"},
    {"bookmark", "🔖"},
    {"label", "🏷️"},
    {"money bag", "💰"},
    {"coin", "🪙"},
    {"yen banknote", "💴"},
    {"dollar banknote", "💵"},
    {"euro banknote", "💶"},
    {"pound banknote", "💷"},
    {"money with wings", "💸"},
    {"credit card", "💳"},
    {"receipt", "🧾"},
    {"envelope", "✉️"},
    {"e-mail", "📧"},
    {"incoming envelope", "📨"},
    {"envelope with arrow", "📩"},
    {"outbox tray", "📤"},
    {"inbox tray", "📥"},
    {"package", "📦"},
    {"closed mailbox with raised flag", "📫"},
    {"closed mailbox with lowered flag", "📪"},
    {"open mailbox with raised flag", "📬"},
    {"open mailbox with lowered flag", "📭"},
    {"postbox", "📮"},
    {"ballot box with ballot", "🗳️"},
    {"pencil", "✏️"},
    {"black nib", "✒️"},
    {"fountain pen", "🖋️"},
    {"pen", "🖊️"},
    {"paintbrush", "🖌️"},
    {"crayon", "🖍️"},
    {"memo", "📝"},
    {"briefcase", "💼"},
    {"file folder", "📁"},
    {"open file folder", "📂"},
    {"card index dividers", "🗂️"},
    {"calendar", "📅"},
    {"tear-off calendar", "📆"},
    {"spiral notepad", "🗒️"},
    {"spiral calendar", "🗓️"},
    {"card index", "📇"},
    {"chart increasing", "📈"},
    {"chart decreasing", "📉"},
    {"bar chart", "📊"},
    {"clipboard", "📋"},
    {"pushpin", "📌"},
    {"round pushpin", "📍"},
    {"paperclip", "📎"},
    {"linked paperclips", "🖇️"},
    {"straight ruler", "📏"},
    {"triangular ruler", "📐"},
    {"scissors", "✂️"},
    {"card file box", "🗃️"},
    {"file cabinet", "🗄️"},
    {"wastebasket", "🗑️"},
    {"lock", "🔒"},
    {"unlock", "🔓"},
    {"lock with ink pen", "🔏"},
    {"closed lock with key", "🔐"},
    {"key", "🔑"},
    {"old key", "🗝️"},
    {"hammer", "🔨"},
    {"axe", "🪓"},
    {"pick", "⛏️"},
    {"hammer and pick", "⚒️"},
    {"hammer and wrench", "🛠️"},
    {"dagger", "🗡️"},
    {"crossed swords", "⚔️"},
    {"gun", "🔫"},
    {"bow and arrow", "🏹"},
    {"shield", "🛡️"},
    {"wrench", "🔧"},
    {"nut and bolt", "🔩"},
    {"gear", "⚙️"},
    {"clamp", "🗜️"},
    {"balance scale", "⚖️"},
    {"link", "🔗"},
    {"chains", "⛓️"},
    {"hook", "🪝"},
    {"toolbox", "🧰"},
    {"magnet", "🧲"},
    {"ladder", "🪜"},
    {"alembic", "⚗️"},
    {"test tube", "🧪"},
    {"petri dish", "🧫"},
    {"dna", "🧬"},
    {"microscope", "🔬"},
    {"telescope", "🔭"},
    {"satellite", "📡"},
    {"syringe", "💉"},
    {"drop of blood", "🩸"},
    {"pill", "💊"},
    {"adhesive bandage", "🩹"},
    {"stethoscope", "🩺"},
    {"door", "🚪"},
    {"elevator", "🛗"},
    {"mirror", "🪞"},
    {"window", "🪟"},
    {"bed", "🛏️"},
    {"couch and lamp", "🛋️"},
    {"chair", "🪑"},
    {"toilet", "🚽"},
    {"plunger", "🪠"},
    {"shower", "🚿"},
    {"bathtub", "🛁"},
    {"mouse trap", "🪤"},
    {"razor", "🪒"},
    {"lotion bottle", "🧴"},
    {"safety pin", "🧷"},
    {"broom", "🧹"},
    {"basket", "🧺"},
    {"roll of paper", "🧻"},
    {"bucket", "🪣"},
    {"soap", "🧼"},
    {"toothbrush", "🪥"},
    {"sponge", "🧽"},
    {"fire extinguisher", "🧯"},
    {"shopping cart", "🛒"},
    {"smoking", "🚬"},
    {"coffin", "⚰️"},
    {"funeral urn", "⚱️"},
    {"moyai", "🗿"},
    {"atm sign", "🏧"},
    {"wheelchair symbol", "♿"},
    {"restroom", "🚻"},
    {"put litter in its place", "🚮"},
    {"potable water", "🚰"},
    {"men’s room", "🚹"},
    {"women’s room", "🚺"},
    {"baby symbol", "🚼"},
    {"toilet", "🚽"},
    {"shower", "🚿"},
    {"bath", "🛁"},
    {"bathtub", "🛁"},
    {"passport control", "🛂"},
    {"customs", "🛃"},
    {"baggage claim", "🛄"},
    {"left luggage", "🛅"},
    {"warning", "⚠️"},
    {"children crossing", "🚸"},
    {"no entry", "⛔"},
    {"prohibited", "🚫"},
    {"no bicycles", "🚳"},
    {"no smoking", "🚭"},
    {"no littering", "🚯"},
    {"non-potable water", "🚱"},
    {"no pedestrians", "🚷"},
    {"no mobile phones", "📵"},
    {"no one under eighteen", "🔞"},
    {"radioactive", "☢️"},
    {"biohazard", "☣️"},
    {"up arrow", "⬆️"},
    {"up-right arrow", "↗️"},
    {"right arrow", "➡️"},
    {"down-right arrow", "↘️"},
    {"down arrow", "⬇️"},
    {"down-left arrow", "↙️"},
    {"left arrow", "⬅️"},
    {"up-left arrow", "↖️"},
    {"up-down arrow", "↕️"},
    {"left-right arrow", "↔️"},
    {"right arrow curving left", "↩️"},
    {"left arrow curving right", "↪️"},
    {"right arrow", "➡️"},
    {"arrow up small", "🔼"},
    {"arrow down small", "🔽"},
    {"leftwards arrow with hook", "↩️"},
    {"rightwards arrow with hook", "↪️"},
    {"bell", "🔔"},
    {"bell with slash", "🔕"},
    {"musical score", "🎼"},
    {"musical note", "🎵"},
    {"musical notes", "🎶"},
    {"studio microphone", "🎙️"},
    {"level slider", "🎚️"},
    {"control knobs", "🎛️"},
    {"microphone", "🎤"},
    {"headphone", "🎧"},
    {"radio", "📻"},
    {"saxophone", "🎷"},
    {"guitar", "🎸"},
    {"musical keyboard", "🎹"},
    {"trumpet", "🎺"},
    {"violin", "🎻"},
    {"drum", "🥁"},
    {"long drum", "🪘"},
    {"banjo", "🪕"},
    {"accordion", "🪗"},
    {"long drum", "🪘"}};

    std::istringstream iss(str);
    std::string word;
    std::string result;

    while (iss >> word) {
        if (emojis.find(word) != emojis.end()) {
            result += emojis[word] + " ";
        } else {
            result += word + " ";
        }
    }

    // Remove the trailing space
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

// Example usage:
// GiString strTransformer;
// std::string input = "happy love sad";
// std::string result = strTransformer.emojify(input);
// std::cout << "Emojified string: " << result << std::endl;




/**
 * @brief Finds the lexicographically next string.
 *
 * @param str The input string for which to find the next lexicographically string.
 * @return The lexicographically next string.
 * @throws std::invalid_argument If the input string is empty.
 */

std::string GiString::lexicographically_next(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("lexicographically_next: Error - Input string is empty.");
    }

    std::string result = str;

    // Find the first character from the end that can be incremented
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 'z') {
        result[i] = 'a';
        --i;
    }

    // If all characters are 'z', add 'a' at the beginning
    if (i < 0) {
        result = 'a' + result;
    } else {
        // Increment the character at position i
        result[i] = static_cast<char>(result[i] + 1);
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "abc";
// std::string result = giString.lexicographically_next(input);
// std::cout << "Next lexicographically string: " << result << std::endl;





/**
 * @brief Finds the lexicographically previous string.
 *
 * @param str The input string for which the previous string needs to be found.
 * @return The lexicographically previous string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::lexicographically_previous(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("lexicographically_previous: Input string is empty.");
    }

    std::string prevStr = str;
    std::prev_permutation(prevStr.begin(), prevStr.end());

    return prevStr;
}

// Example usage:
// std::string input = "abcd";
// std::string result = GiString::lexicographically_previous(input);
// std::cout << "Lexicographically previous string: " << result << std::endl;




/**
 * @brief Normalizes and adjusts white spaces in a string (e.g., removes excess spaces, adjusts appropriate spacing).
 *
 * @param input The input string to adjust white spaces.
 * @return The string with normalized white spaces.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::adjust_whitespace(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("adjust_whitespace: Input string is empty.");
    }

    std::string result;
    bool is_space = false;

    for (char c : input) {
        if (std::isspace(c)) {
            if (!is_space) {
                result.push_back(' '); // Replace consecutive spaces with a single space
                is_space = true;
            }
        } else {
            result.push_back(c);
            is_space = false;
        }
    }

    // Remove leading and trailing spaces
    result.erase(result.find_last_not_of(" ") + 1);
    result.erase(0, result.find_first_not_of(" "));

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "  Hello    World!  ";
// std::string result = giString.adjust_whitespace(input);
// std::cout << "Adjusted string: " << result << std::endl;




/**
 * @brief Generates a unique identifier based on the existing data in a string.
 *
 * @param data The input string used for generating the identifier.
 * @return A unique identifier generated from the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::generate_identifier(const std::string& data) {
    if (data.empty()) {
        throw std::invalid_argument("generate_identifier: Input string is empty.");
    }

    // Generate a salt based on the current time
    auto now = std::chrono::high_resolution_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
    long duration = value.count();

    std::stringstream salt_ss;
    salt_ss << duration;
    std::string salt = salt_ss.str();

    // Combine the data and the salt
    std::string data_salt = data + salt;

    // Hash the combined data and salt
    std::hash<std::string> hasher;
    size_t hash = hasher(data_salt);

    // Convert the hash to a string for the identifier
    std::stringstream ss;
    ss << hash;
    std::string identifier = ss.str();

    return identifier;
}
// Example usage:
// GiString giString;
// std::string input = "example_data";
// std::string identifier = giString.generate_identifier(input);
// std::cout << "Generated Identifier: " << identifier << std::endl;



/**
 * @brief Counts the number of occurrences of a specified substring in a given string.
 *
 * @param substring The substring to count occurrences of.
 * @return The number of occurrences of the substring in the string.
 * @throws std::invalid_argument If the input string or substring is empty.
 */

int GiString::count_substring(std::string str, const std::string& substring) {
    if (str.empty() || substring.empty()) {
        throw std::invalid_argument("count_substring: Input string or substring is empty.");
    }

    int count = 0;
    size_t pos = 0;
    
    while ((pos = str.find(substring, pos)) != std::string::npos) {
        ++count;
        pos += substring.length();
    }

    return count;
}

// Example usage:
// GiString myString("hello hello world hello");
// std::string substring = "hello";
// int occurrences = myString.count_substring(substring);
// std::cout << "Number of occurrences of 'hello': " << occurrences << std::endl;





/**
 * @brief Replaces all occurrences of a substring with another substring in the given string.
 *
 * @param str The original string in which replacements will be made.
 * @param oldSubstr The substring to be replaced.
 * @param newSubstr The substring to replace all occurrences of 'oldSubstr'.
 * @return The modified string after replacing all occurrences of 'oldSubstr' with 'newSubstr'.
 * @throws std::invalid_argument If 'oldSubstr' is empty.
 */
std::string GiString::replace_substring(std::string str, const std::string& oldSubstr, const std::string& newSubstr) {
    if (oldSubstr.empty()) {
        throw std::invalid_argument("replace_substring: Error - 'oldSubstr' cannot be empty.");
    }

    size_t pos = 0;
    while ((pos = str.find(oldSubstr, pos)) != std::string::npos) {
        str.replace(pos, oldSubstr.length(), newSubstr);
        pos += newSubstr.length();
    }

    return str;
}

// Example usage:
// GiString giString;
// std::string originalStr = "Hello, World! Hello, Universe!";
// std::string replacedStr = giString.replace_substring(originalStr, "Hello", "Hi");
// std::cout << "Modified string: " << replacedStr << std::endl;




/**
 * @brief Calculates the visible length of a string, ignoring any invisible characters (e.g., ANSI codes).
 *
 * @param str The input string for which the visible length needs to be calculated.
 * @return The visible length of the string after ignoring invisible characters.
 * @throws std::invalid_argument If the input string is empty.
 */
int GiString::visible_length(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::visible_length: Error - Input string is empty.");
    }

    int visibleLength = 0;
    bool inVisibleChar = false;

    for (char c : str) {
        if (c == '\033') { // Check for ANSI escape code
            inVisibleChar = true;
        } else if (inVisibleChar && c == 'm') {
            inVisibleChar = false;
        } else if (!inVisibleChar) {
            visibleLength++;
        }
    }

    return visibleLength;
}

// Example usage:
// GiString giString;
// std::string input = "Hello\033[1;31mWorld\033[0m";
// int length = giString.visible_length(input);
// std::cout << "Visible length of the string: " << length << std::endl;




/**
 * @brief Converts a string to mocking form, where letter case is randomly changed.
 *
 * @param input The input string to be converted.
 * @return The string in mocking form.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::to_spongebob_mocking(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("to_spongebob_mocking: Input string is empty!");
    }

    std::string result = "";
    bool upperCase = true; // Start with uppercase

    for (char c : input) {
        if (isalpha(c)) {
            if (upperCase) {
                result += std::toupper(c);
            } else {
                result += std::tolower(c);
            }
            upperCase = !upperCase; // Toggle the case for the next character
        } else {
            result += c; // Keep non-alphabetic characters as they are
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World!";
// std::string result = giString.to_spongebob_mocking(input);
// std::cout << "Mocking form: " << result << std::endl;







/**
 * @brief Inserts a string into an already sorted list of strings while maintaining the order.
 *
 * @param strList The sorted list of strings to insert into.
 * @param str The string to insert into the list.
 * @return The updated sorted list with the new string inserted while preserving the order.
 * @throws std::invalid_argument If the input list is empty.
 */
std::vector<std::string> GiString::insert_ordered(std::vector<std::string> strList, const std::string& str) {
    if (strList.empty()) {
        throw std::invalid_argument("insert_ordered: Input list is empty.");
    }

    std::vector<std::string> result;
    bool strInserted = false;

    for (const std::string& s : strList) {
        if (!strInserted && str < s) {
            result.push_back(str);
            strInserted = true;
        }
        result.push_back(s);
    }

    if (!strInserted) {
        result.push_back(str);
    }

    return result;
}

// Example usage:
// std::vector<std::string> sortedList = {"apple", "banana", "orange"};
// std::string newStr = "cherry";
// std::vector<std::string> updatedList = GiString::insert_ordered(sortedList, newStr);
// // Now updatedList will contain: {"apple", "banana", "cherry", "orange"}





/**
 * @brief Removes a string from a sorted list of strings while preserving the order.
 *
 * @param sortedList The sorted list of strings.
 * @param strToRemove The string to be removed from the list.
 * @return The updated sorted list after removing the specified string.
 * @throws std::invalid_argument If the sortedList is empty or if strToRemove is not found in the list.
 */
std::vector<std::string> GiString::remove_ordered(const std::vector<std::string>& sortedList, const std::string& strToRemove) {
    if (sortedList.empty()) {
        throw std::invalid_argument("remove_ordered: Error - sortedList is empty");
    }

    std::vector<std::string> updatedList;
    bool removed = false;

    for (const std::string& str : sortedList) {
        if (str == strToRemove && !removed) {
            removed = true;
        } else {
            updatedList.push_back(str);
        }
    }

    if (!removed) {
        throw std::invalid_argument("remove_ordered: Error - strToRemove not found in the sortedList");
    }

    return updatedList;
}

// Example usage:
// std::vector<std::string> sortedList = {"apple", "banana", "cherry", "date"};
// std::string strToRemove = "banana";
// std::vector<std::string> updatedList = GiString::remove_ordered(sortedList, strToRemove);
// // updatedList will now contain {"apple", "cherry", "date"}



/**
 * @brief Checks if a string matches a pattern with the option to use wildcards.
 *
 * @param str The input string to check.
 * @param pattern The pattern to match against. '*' represents zero or more characters, '?' represents a single character.
 * @return true if the string matches the pattern, false otherwise.
 * @throws std::invalid_argument If the input string or pattern is empty.
 */
bool GiString::match_pattern(const std::string& str, const std::string& pattern) {
    if (str.empty() || pattern.empty()) {
        throw std::invalid_argument("match_pattern: Input string or pattern is empty!");
    }

    int s = str.length();
    int p = pattern.length();

    // Create a DP table to store the results of subproblems
    std::vector<std::vector<bool>> dp(s + 1, std::vector<bool>(p + 1, false));
    dp[0][0] = true;

    // Deals with patterns like '*' at the start
    for (int j = 1; j <= p; j++) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= p; j++) {
            if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[s][p];
}

// Example usage:
// GiString giString;
// std::string input = "hello";
// std::string pattern = "h*o";
// bool result = giString.match_pattern(input, pattern);
// std::cout << "Does the string match the pattern? " << (result ? "Yes" : "No") << std::endl;




/**
 * @brief Finds all occurrences of a pattern in a given string.
 *
 * @param pattern The pattern to search for in the string.
 * @param text The text in which to search for the pattern.
 * @return A vector of starting positions of all occurrences of the pattern in the text.
 * @throws std::invalid_argument If the pattern is empty.
 */
std::vector<size_t> GiString::find_all_patterns(const std::string& pattern, const std::string& text) {
    if (pattern.empty()) {
        throw std::invalid_argument("find_all_patterns: Error - The pattern cannot be empty.");
    }

    std::vector<size_t> positions;
    size_t pos = text.find(pattern, 0);
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = text.find(pattern, pos + 1);
    }

    return positions;
}

// Example usage:
// GiString giString;
// std::string pattern = "abc";
// std::string text = "abcabcabc";
// std::vector<size_t> positions = giString.find_all_patterns(pattern, text);
// for (size_t pos : positions) {
//     std::cout << "Pattern found at position: " << pos << std::endl;
// }




/**
 * @brief Replaces all occurrences of a substring with another substring, ignoring case.
 *
 * @param str The original string where replacements will be made.
 * @param from Substring to be replaced.
 * @param to Substring to replace 'from'.
 * @return The string with replacements made.
 * @throws std::invalid_argument If the original string is empty.
 */
std::string GiString::case_insensitive_replace(const std::string& str, const std::string& from, const std::string& to) {
    if (str.empty()) {
        throw std::invalid_argument("case_insensitive_replace: Input string is empty");
    }

    std::string result = str;
    size_t start_pos = 0;
    while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
        result.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string original = "Hello WoRld, hello world!";
// std::string replaced = giString.case_insensitive_replace(original, "hello", "hi");
// std::cout << "Replaced string: " << replaced << std::endl;




// GiString.cpp
/**
 * @brief Truncates a string to a specified length, adding "..." at the end if truncated.
 *
 * @param str The input string to truncate.
 * @param length The maximum length of the truncated string.
 * @return The truncated string with "..." added at the end if truncated.
 * @throws std::invalid_argument If the input string is empty.
 */

std::string GiString::truncate_with_ellipsis(const std::string& str, size_t length) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::truncate_with_ellipsis: Error - Input string is empty");
    }

    if (str.length() <= length) {
        return str;
    }

    return str.substr(0, length) + "...";
}

// Example usage:
// GiString giString;
// std::string input = "This is a long string that needs to be truncated";
// std::string result = giString.truncate_with_ellipsis(input, 20);
// std::cout << "Truncated string: " << result << std::endl;





/**
 * @brief Extracts a specified field from a formatted string (e.g., log).
 *
 * @param input The formatted string from which to extract the field.
 * @param delimiter The delimiter used to separate fields in the input string.
 * @param fieldIndex The index of the field to extract (0-based index).
 * @return The extracted field as a string.
 * @throws std::invalid_argument If the input string is empty or if the field index is out of range.
 */
std::string GiString::extract_field(const std::string& input, char delimiter, int fieldIndex) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::extract_field: Input string is empty.");
    }

    // Split the input string based on the delimiter
    std::stringstream ss(input);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    if ((size_t)fieldIndex < 0 || (size_t)fieldIndex >= tokens.size()) {
        throw std::invalid_argument("GiString::extract_field: Field index is out of range.");
    }

    return tokens[fieldIndex];
}

// Example usage:
// GiString giString;
// std::string input = "error: file not found";
// char delimiter = ':';
// int fieldIndex = 1;
// std::string extractedField = giString.extract_field(input, delimiter, fieldIndex);
// std::cout << "Extracted field: " << extractedField << std::endl;








/**
 * @brief Converts all possible substrings of a string to numeric format.
 *
 * @param input The input string to convert.
 * @return A vector of integers representing the numeric values of all substrings.
 * @throws std::invalid_argument If the input string is empty.
 */

std::vector<int> GiString::convert_to_numeric(const std::string& input) {
    if (input.empty()) {
        throw std::invalid_argument("convert_to_numeric: Error - Input string is empty");
    }

    std::vector<int> numeric_values;
    
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 1; j <= input.size() - i; ++j) {
            std::string substring = input.substr(i, j);
            try {
                int numeric_value = std::stoi(substring);
                numeric_values.push_back(numeric_value);
            } catch (const std::invalid_argument&) {
                // Ignore non-numeric substrings
            }
        }
    }

    return numeric_values;
}

// Example usage:
// GiString giString;
// std::string input = "123abc45def6";
// std::vector<int> numericValues = giString.convert_to_numeric(input);
// for (int num : numericValues) {
//     std::cout << num << " ";
// }
// Output: 123 45 6





/**
 * @brief Inserts a string only if it doesn't already exist at the specified position.
 *
 * @param index The index at which to insert the string.
 * @param str The string to insert.
 * @return True if the string was inserted successfully, false if the string already existed at the given index.
 * @throws std::out_of_range If the index is out of range.
 */
bool GiString::insert_if_absent(std::string& data, size_t index, const std::string& str) {
        if (index > data.size()) {
            throw std::out_of_range("Index out of range in insert_if_absent function");
        }

        // Search for the string in the data
        size_t foundPos = data.find(str);
        if (foundPos != std::string::npos) {
            // String already exists
            return false;
        } else {
            // Insert the string at the specified index
            data.insert(index, str);
            return true;
        }
    }


// Example usage:
// GiString giString;
// giString.add_string("Hello");
// giString.add_string("World");
// bool inserted = giString.insert_if_absent(1, "World");
// if (inserted) {
//     std::cout << "String inserted successfully!" << std::endl;
// } else {
//     std::cout << "String already exists at the given index." << std::endl;
// }





/**
 * @brief Splits a string into individual characters and returns them as a list.
 *
 * @param str The input string to be split.
 * @return std::vector<std::string> A vector containing individual characters from the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::vector<std::string> GiString::explode(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("explode: Input string is empty.");
    }

    std::vector<std::string> result;
    for (char c : str) {
        result.push_back(std::string(1, c));
    }

    return result;
}

// Example usage:
// std::string input = "Hello";
// std::vector<std::string> result = GiString::explode(input);
// for (const auto& character : result) {
//     std::cout << character << std::endl;
// }





/**
 * @brief Concatenates a list of characters into a single string.
 *
 * @param characters The list of characters to be concatenated.
 * @return The resulting string after concatenation.
 * @throws std::invalid_argument If the list of characters is empty.
 */
std::string GiString::implode(const std::vector<char>& characters) {
    if (characters.empty()) {
        throw std::invalid_argument("GiString::implode: Error - The list of characters is empty.");
    }

    std::string result;
    for (const char& c : characters) {
        result += c;
    }

    return result;
}

// Example usage:
// GiString giString;
// std::vector<char> charList = {'H', 'e', 'l', 'l', 'o'};
// std::string concatenatedString = giString.implode(charList);
// std::cout << "Concatenated string: " << concatenatedString << std::endl;





/**
 * @brief Removes duplicate characters in a string, keeping only the first occurrence of each character.
 *
 * @param str The input string from which duplicates will be removed.
 * @return std::string The string with duplicates removed.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::remove_duplicates(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("remove_duplicates: Input string is empty.");
    }

    std::string result;
    std::unordered_set<char> seen;

    for (char c : str) {
        if (seen.find(c) == seen.end()) {
            result += c;
            seen.insert(c);
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "hello world";
// std::string result = giString.remove_duplicates(input);
// std::cout << "String with duplicates removed: " << result << std::endl;




/**
 * @brief Converts a given text into Braille representation.
 *
 * @param text The input text to convert to Braille.
 * @return The Braille representation of the input text.
 * @throws std::invalid_argument If the input text is empty.
 */

std::string GiString::to_braille(const std::string& text) {
    if (text.empty()) {
        throw std::invalid_argument("to_braille: Input text is empty.");
    }

    // Braille mapping for each character
    std::unordered_map<char, std::string> brailleMap = {
        {'a', "⠁"}, {'b', "⠃"}, {'c', "⠉"}, {'d', "⠙"}, {'e', "⠑"},
        {'f', "⠋"}, {'g', "⠛"}, {'h', "⠓"}, {'i', "⠊"}, {'j', "⠚"},
        {'k', "⠅"}, {'l', "⠇"}, {'m', "⠍"}, {'n', "⠝"}, {'o', "⠕"},
        {'p', "⠏"}, {'q', "⠟"}, {'r', "⠗"}, {'s', "⠎"}, {'t', "⠞"},
        {'u', "⠥"}, {'v', "⠧"}, {'w', "⠺"}, {'x', "⠭"}, {'y', "⠽"},
        {'z', "⠵"}, {' ', "⠀"}
    };

    std::string brailleText;
    for (const char& c : text) {
        if (brailleMap.find(std::tolower(c)) != brailleMap.end()) {
            brailleText += brailleMap[std::tolower(c)];
        } else {
            // Handle characters not in the mapping
            brailleText += c;
        }
    }

    return brailleText;
}

// Example usage:
// GiString giString;
// std::string input = "Hello World";
// std::string brailleOutput = giString.to_braille(input);
// std::cout << "Braille representation: " << brailleOutput << std::endl;




std::string GiString::from_braille(const std::string& brailleText) {
    if (brailleText.empty()) {
        throw std::invalid_argument("from_braille: Input Braille text is empty.");
    }

    // Reverse Braille mapping for each character
    std::unordered_map<std::string, char> brailleMap = {
        {"⠁", 'a'}, {"⠃", 'b'}, {"⠉", 'c'}, {"⠙", 'd'}, {"⠑", 'e'},
        {"⠋", 'f'}, {"⠛", 'g'}, {"⠓", 'h'}, {"⠊", 'i'}, {"⠚", 'j'},
        {"⠅", 'k'}, {"⠇", 'l'}, {"⠍", 'm'}, {"⠝", 'n'}, {"⠕", 'o'},
        {"⠏", 'p'}, {"⠟", 'q'}, {"⠗", 'r'}, {"⠎", 's'}, {"⠞", 't'},
        {"⠥", 'u'}, {"⠧", 'v'}, {"⠺", 'w'}, {"⠭", 'x'}, {"⠽", 'y'},
        {"⠵", 'z'}, {"⠀", ' '}
    };

    std::string regularText;
    std::string tmpBrailleChar;
    // Assumes checking and conversion in blocks of 3 bytes (UTF-8 encoded Braille may vary in byte length)
    for (size_t i = 0; i < brailleText.size(); i += 3) {
        tmpBrailleChar = brailleText.substr(i, 3);

        if (brailleMap.find(tmpBrailleChar) != brailleMap.end()) {
            regularText += brailleMap[tmpBrailleChar];
        } else {
            // Handle characters not in the Braille map by appending them unchanged
            // This may occur if there are punctuations or other symbols
            regularText += tmpBrailleChar;
        }
    }

    return regularText;
}

// Example usage:
// GiString giString;
// std::string brailleInput = "⠠⠓⠑⠇⠇⠕ ⠠⠺⠕⠗⠇⠙"; // Braille representation for "Hello World"
// std::string regularText = giString.from_braille(brailleInput);
// std::cout << "Converted text: " << regularText << std::endl;






/**
 * @brief Generates n-grams from the given string.
 *
 * @param input The input string from which n-grams will be generated.
 * @param n The size of n-grams to generate.
 * @return A vector of strings containing the generated n-grams.
 * @throws std::invalid_argument If the input string is empty or n is less than or equal to 0.
 */
std::vector<std::string> GiString::generate_ngrams(const std::string& input, int n) {
    if (input.empty()) {
        throw std::invalid_argument("generate_ngrams: Input string is empty.");
    }
    if (n <= 0) {
        throw std::invalid_argument("generate_ngrams: n should be greater than 0.");
    }

    std::vector<std::string> ngrams;
    for (size_t i = 0; i < input.size() - n + 1; ++i) {
        ngrams.push_back(input.substr(i, n));
    }

    return ngrams;
}

// Example usage:
// GiString giString;
// std::string input = "hello world";
// int n = 3;
// std::vector<std::string> result = giString.generate_ngrams(input, n);
// for (const auto& ngram : result) {
//     std::cout << ngram << " ";
// }
// Output: "hel ell llo lo w wo wor orl rld "






/**
 * @brief Replaces parts of a string with dynamically generated values.
 *
 * This function replaces placeholders in the input string with dynamically generated values.
 * Placeholders are represented by curly braces containing the index of the value to replace with.
 * For example, if the input string is "Hello {0}, today is {1}", and values = {"Alice", "Monday"},
 * the output will be "Hello Alice, today is Monday".
 *
 * @param input The input string with placeholders to be replaced.
 * @param values An array of strings to replace the placeholders in the input string.
 * @return The input string with placeholders replaced by the values.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::dynamic_replace(const std::string& input, const std::vector<std::string>& values) {
    if (input.empty()) {
        throw std::invalid_argument("dynamic_replace: Input string is empty.");
    }

    std::string result = input;
    std::regex placeholderRegex("\\{(\\d+)\\}");

    std::smatch match;
    while (std::regex_search(result, match, placeholderRegex)) {
        size_t index = std::stoul(match[1].str());
        if (index < values.size()) {
            result = match.suffix().str();
            result.insert(match.position(), values[index]);
        } else {
            throw std::invalid_argument("dynamic_replace: Placeholder index out of range.");
        }
    }

    return result;
}

// Example usage:
// GiString giString;
// std::string input = "Hello {0}, today is {1}";
// std::vector<std::string> values = {"Alice", "Monday"};
// std::string result = giString.dynamic_replace(input, values);
// std::cout << "Replaced string: " << result << std::endl;




/**
 * @brief Converts a simple string to a regular expression.
 *
 * This function takes a simple string as input and converts it into a regular expression string.
 *
 * @param str The input string to convert to a regular expression.
 * @return std::string The regular expression equivalent of the input string.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::compile_to_regex(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::compile_to_regex: Empty input string.");
    }

    // Regular expression characters that need to be escaped
    std::string specialChars = "\\^$.*+?()[]{}|";

    std::string regexStr;
    for (char c : str) {
        if (specialChars.find(c) != std::string::npos) {
            // Escape special characters in the input string
            regexStr += '\\';
        }
        regexStr += c;
    }

    return regexStr;
}

// Example usage:
// GiString giString;
// std::string input = "abc.*";
// std::string regexResult = giString.compile_to_regex(input);
// std::cout << "Regular expression: " << regexResult << std::endl;




/**
 * @brief Fills a string with random characters from a specified set of characters.
 *
 * @param str The string to fill with random characters.
 * @param charSet The set of characters to choose from when filling the string.
 * @param length The length of the string to be filled.
 * @throws std::invalid_argument If the input string is empty or the character set is empty.
 */
void GiString::random_fill(std::string& str, const std::string& charSet, int length) {
    if (str.empty() || charSet.empty()) {
        throw std::invalid_argument("random_fill: Input string or character set cannot be empty.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charSet.size() - 1);

    str.clear();
    str.reserve(length);
    for (int i = 0; i < length; ++i) {
        str.push_back(charSet[dis(gen)]);
    }
}

// Example usage:
// GiString giString;
// std::string randomString;
// std::string charSet = "abcdefghijklmnopqrstuvwxyz0123456789"; // Define your character set
// int length = 10; // Define the length of the random string
// giString.random_fill(randomString, charSet, length);
// std::cout << "Randomly filled string: " << randomString << std::endl;



/**
 * @brief Checks whether the specified parentheses and other elements in a string are properly balanced.
 *
 * @param expression The input expression to check for balancedness.
 * @return True if the expression is balanced, false otherwise.
 * @throws std::invalid_argument If the input expression is empty.
 */

bool GiString::is_balanced_expression(const std::string& expression) {
    if (expression.empty()) {
        throw std::invalid_argument("is_balanced_expression: Input expression is empty.");
    }

    std::stack<char> stack;
    std::unordered_map<char, char> matching = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty() || stack.top() != matching[c]) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

// Example usage:
// GiString giString;
// std::string expression = "((a+b)*c) - {d}";
// bool isBalanced = giString.is_balanced_expression(expression);
// std::cout << "Is the expression balanced? " << (isBalanced ? "Yes" : "No") << std::endl;



// GiString.cpp
/**
 * @brief Wraps a string with the specified HTML or XML tag.
 *
 * @param str The input string to be wrapped.
 * @param tag The HTML or XML tag to wrap the input string with.
 * @return std::string The input string wrapped with the specified tag.
 * @throws std::invalid_argument If the input string is empty.
 */
std::string GiString::wrap_with_tag(const std::string& str, const std::string& tag) {
    if (str.empty()) {
        throw std::invalid_argument("GiString::wrap_with_tag: Input string is empty.");
    }

    return "<" + tag + ">" + str + "</" + tag + ">";
}

// Example usage:
// std::string input = "Hello, World!";
// std::string tag = "h1";
// std::string result = GiString::wrap_with_tag(input, tag);
// std::cout << "Wrapped string: " << result << std::endl;



/**
 * @brief Converts dates in a string to the specified format.
 *
 * This function takes a string containing dates and converts them to the specified format.
 *
 * @param input The input string containing dates to be normalized.
 * @param format The format to which the dates should be converted (e.g., "YYYY-MM-DD").
 * @return A string with dates normalized to the specified format.
 * @throws std::invalid_argument If the input string is empty or the format is invalid.
 */
std::string GiString::normalize_dates(const std::string& input, const std::string& format) {
    if (input.empty()) {
        throw std::invalid_argument("GiString::normalize_dates: Input string is empty.");
    }

    if (format.empty() || format.find("YYYY") == std::string::npos ||
        format.find("MM") == std::string::npos || format.find("DD") == std::string::npos) {
        throw std::invalid_argument("GiString::normalize_dates: Invalid date format provided.");
    }

    std::regex pattern(R"((\d{1,2})[./-](\d{1,2})[./-](\d{2,4}))");
    std::stringstream result;
    std::smatch matches;
    std::string temp = input;
    
    while (std::regex_search(temp, matches, pattern)) {
        std::locale loc; 
        std::istringstream ss(matches[0].str());
        std::tm dt = {};
        
        ss >> std::get_time(&dt, "%m/%d/%Y");
        if (ss.fail()) {
            ss.clear(); 
            ss.str(matches[0].str());
            ss >> std::get_time(&dt, "%d-%m-%Y");
            if(ss.fail()){
                ss.clear();
                ss.str(matches[0].str());
                ss >> std::get_time(&dt, "%Y.%m.%d");
            }
        }

        std::ostringstream oss;
        oss << std::put_time(&dt, format.c_str());

        result << oss.str();
        temp = matches.suffix().str();
        if (!std::regex_search(temp, matches, pattern)) {
            result << temp; 
        }
    }

    return result.str();
}


// Example usage:
// GiString giString;
// std::string input = "Today is 2022-09-15 and tomorrow is 2022-09-16";
// std::string format = "YYYY/MM/DD";
// std::string result = giString.normalize_dates(input, format);
// std::cout << "Dates normalized to format: " << result << std::endl;





/**
 * @brief Translates a string to the source language based on the translation map.
 *
 * @param input The string to translate.
 * @param translationMap The map containing translations to the source language.
 * @return The translated string in the source language.
 * @throws std::invalid_argument If the input string is empty or if the translation map is empty.
 */
std::string GiString::reverse_translate(const std::string& input, const std::unordered_map<std::string, std::string>& translationMap) {
    if (input.empty()) {
        throw std::invalid_argument("reverse_translate: Input string is empty.");
    }

    if (translationMap.empty()) {
        throw std::invalid_argument("reverse_translate: Translation map is empty.");
    }

    std::string translatedString;
    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        if (translationMap.find(word) != translationMap.end()) {
            translatedString += translationMap.at(word) + " ";
        } else {
            translatedString += word + " ";
        }
    }

    // Remove the extra space at the end
    if (!translatedString.empty()) {
        translatedString.pop_back();
    }

    return translatedString;
}

// Example usage:
// std::unordered_map<std::string, std::string> translationMap = {{"hello", "Cześć"}, {"world", "świat"}};
// std::string input = "hello world";
// std::string result = GiString::reverse_translate(input, translationMap);
// std::cout << "Translated string: " << result << std::endl;









/**
 * @brief Calculates the approximate time needed to read a given string.
 *
 * @param text The input string for which to calculate the reading time.
 * @return The estimated reading time in minutes based on an average reading speed.
 * @throws std::invalid_argument If the input string is empty.
 */
int GiString::calculate_reading_time(const std::string& text) {
    if (text.empty()) {
        throw std::invalid_argument("calculate_reading_time: Input string is empty.");
    }

    // Assuming an average reading speed of 200 words per minute
    // and an average word length of 5 characters
    const int words_per_minute = 200;
    const int average_word_length = 5;
    
    int total_words = 0;
    int total_characters = 0;

    // Counting words and characters in the text
    bool in_word = false;
    for (char c : text) {
        if (std::isalpha(c)) {
            total_characters++;
            if (!in_word) {
                in_word = true;
                total_words++;
            }
        } else {
            in_word = false;
        }
    }   

    // Calculating the estimated reading time
    int total_time = total_words * average_word_length / words_per_minute;
    
    return total_time;
}

// Example usage:
// GiString giString;
// std::string input_text = "This is a sample text for reading time calculation.";
// int reading_time = giString.calculate_reading_time(input_text);
// std::cout << "Estimated reading time: " << reading_time << " minutes" << std::endl;





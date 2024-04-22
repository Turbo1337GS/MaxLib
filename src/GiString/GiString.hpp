// Headers C and C++

#include <string>
#include <stdexcept>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <sstream>
#include <cctype>
#include <functional>
#include <random>
#include <stdexcept>
class GiString
{
public:

    std::string capitalize(const std::string &str);
    std::string capitalizeWords(const std::string &str);
    std::string swapcase(const std::string &str);
    std::string reverse(const std::string &str);
    bool is_palindrome(const std::string &str) const;

    std::string trim_left(const std::string &str);
    std::string trim_right(const std::string &str);
    std::string trim(const std::string &str);
    std::string center(const std::string &str, size_t width, char fill);
    std::string ljust(const std::string &str, size_t width, char fillchar);
    std::string rjust(const std::string &str, size_t width, char fillchar);
    std::string upper(const std::string &str);
    std::string lower(const std::string &str);
    size_t count(const std::string &str, const std::string &sub);

    std::string substring(const std::string &str, size_t start, size_t end);

    std::string replace(const std::string &str, const std::string &old_sub, const std::string &new_sub);
    std::vector<std::string> split(const std::string &str, char delimiter);
    std::string join(const std::vector<std::string> &strs, const std::string &separator);
    bool startswith(const std::string &str, const std::string &prefix);
    bool endswith(const std::string &str, const std::string &suffix);
    bool is_ascii(const std::string &str);
    bool is_numeric(const std::string &str);
    bool is_alpha(const std::string &str);
    bool is_alphanumeric(const std::string &str);
    std::string zfill(const std::string &str, size_t width);
    std::string ltrim(const std::string &str);
    std::string rtrim(const std::string &str);
    size_t find(const std::string &str, const std::string &sub);
    size_t rfind(const std::string &str, const std::string &sub);
    bool contains(const std::string &str, const std::string &sub);
    bool equals_ignore_case(const std::string &str1, const std::string &str2);
    std::string insert(std::string str, size_t pos, const std::string &sub);
    std::string remove(const std::string &str, const std::string &sub);
    char pop(std::string &str);
    void push_back(std::string &str, char ch);
    void copy(const std::string &src, std::string &dest);
    char at(const std::string &str, size_t index);
    char max_char(const std::string &str);
    char min_char(const std::string &str);
    void iterate(const std::string &str, std::function<void(char)> func);
    std::string map_chars(const std::string &str, std::function<char(char)> func);
    std::string filter_chars(const std::string &str, std::function<bool(char)> predicate);
    bool all_of(const std::string &str, std::function<bool(char)> predicate);
    bool none_of(const std::string &str, std::function<bool(char)> predicate);
    std::string slice(const std::string &str, size_t start, size_t end);
    std::string ascii_only(std::string str);
    int to_int(const std::string &str);
    float to_float(const std::string &str);
    std::string indent(const std::string &str, int count);
    std::string dedent(const std::string &str);
    std::string replace_first(const std::string &str, const std::string &from, const std::string &to);

    std::string replace_last(const std::string &str, const std::string &from, const std::string &to);

    std::string reversed(const std::string &str);

    std::string shuffle(const std::string &str);

    std::string sort(const std::string &str);

    template <typename T>
    T reduce(const std::string &str, T init, std::function<T(T, char)> binary_func);
};
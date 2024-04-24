// Headers C and C++

#include <string>
#include <stdexcept>
#include <cstdio>
#include <algorithm>
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
    std::string sort_desc(const std::string &str);
    std::string repeat(const std::string &str, int times);
    bool lexicographic_compare(const std::string &str1, const std::string &str2);
    std::string extract_digits(const std::string &str);
    bool is_blank(const std::string &str);
    bool is_uppercase(const std::string &str);
    bool is_valid_email(const std::string &str);
    bool is_valid_local_part(const std::string &localPart);
    bool is_valid_domain_part(const std::string &domainPart);
    std::string url_encode(const std::string &str);
    std::string url_decode(const std::string &str);
    std::string base64_encode(const std::string &str);
    std::string base64_decode(const std::string &str);
    bool valid_utf8(const std::string &str);
    std::string from_binary(const std::string &binary);
    std::string to_binary(const std::string &str);
    std::string difference(const std::string &str1, const std::string &str2);
    bool is_subsequence(const std::string &str, const std::string &sequence);
    int levenshtein_distance(const std::string &s1, const std::string &s2);
    std::string longest_common_subsequence(const std::string &str1, const std::string &str2);
    std::string longest_common_substring(const std::string &str1, const std::string &str2);
    std::string next_permutation(const std::string &str);
    std::string prev_permutation(const std::string &str);
    std::string random_string(size_t length);
    std::string quote(const std::string &str);
    std::string unquote(const std::string &str);
    std::string mask_sensitive(const std::string &str, const std::string &sensitiveChars, char maskChar);
    std::string capitalize_sentences(const std::string &str);
    size_t line_count(const std::string &str);
    char least_common_char(const std::string &str);
    char most_common_char(const std::string &str);
    std::string swap_position(const std::string &str, size_t pos1, size_t pos2);
    int roman_to_int(const std::string &s);
    std::string normalize_whitespace(const std::string &str);
    std::string remove_punctuation(const std::string &str);
    std::string to_hex(const std::string &str);
    std::string from_hex(const std::string &hexStr);
    std::string to_octal(const std::string &str);
    std::string from_octal(const std::string &octalStr);
    bool bracket_check(const std::string &str);
    std::string squeeze(const std::string &str);
    std::string expand_tabs(const std::string &str, size_t tabWidth);
    std::string capitalize_each_word(const std::string &str);
    template <typename T>
    T reduce(const std::string &str, T init, std::function<T(T, char)> binary_func);
};
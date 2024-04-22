
#include "src/init/init.hpp"
#include <iostream>

// Obejcts
GiString *gs = new GiString();

void JOIN_Demo()
{
  std::vector<std::string> input = {"hello", "world", "test"};
  std::string separator = ", ";
  std::string result = gs->join(input, separator);
  std::cout << "Joined string: " << result << std::endl;
}

void StartWith_Demo()
{
  std::string input = "hello world";
  std::string prefix = "hello";
  bool starts_with = gs->startswith(input, prefix);
  std::cout << "Starts with 'hello': " << (starts_with ? "true" : "false") << std::endl;
}
void EndWith_Demo()
{
  std::string input = "hello world";
  std::string suffix = "world";
  bool ends_with = gs->endswith(input, suffix);
  std::cout << "Ends with 'world': " << (ends_with ? "true" : "false") << std::endl;
}
void is_ascii_Demo()
{
  std::string input = "hello world";
  bool ascii = gs->is_ascii(input);
  std::cout << "Is ASCII: " << (ascii ? "true" : "false") << std::endl;
}
void is_numeric_Demo()
{
  std::string input = "12345";
  bool numeric = gs->is_numeric(input);
  std::cout << "Is numeric: " << (numeric ? "true" : "false") << std::endl;
}
void is_alpha_Demo()
{
  std::string input = "HelloWorld";
  bool alpha = gs->is_alpha(input);
  std::cout << "Is alpha: " << (alpha ? "true" : "false") << std::endl;
}
void is_alphanumeric_Demo()
{
  std::string input = "Hello123";
  bool alphanumeric = gs->is_alphanumeric(input);
  std::cout << "Is alphanumeric: " << (alphanumeric ? "true" : "false") << std::endl;
}
void zfill_Demo()
{
  std::string input = "123";
  size_t width = 6;
  std::string result = gs->zfill(input, width);
  std::cout << "After zfill: " << result << std::endl;
}
void ltrim_Demo()
{
  std::string input = "   hello world";
  std::string result = gs->ltrim(input);
  std::cout << "After ltrim: '" << result << "'" << std::endl;
}

void find_Demo()
{
  std::string input = "hello world";
  std::string sub = "world";
  size_t index = gs->find(input, sub);
  std::cout << "Index of 'world': " << index << std::endl;
}
void contains_Demo()
{
  std::string input = "hello world";
  std::string sub = "world";
  bool contains = gs->contains(input, sub);
  std::cout << "Contains 'world': " << (contains ? "true" : "false") << std::endl;
}
void equals_ignore_case_Demo()
{
  std::string str1 = "Hello";
  std::string str2 = "hello";
  bool equals = gs->equals_ignore_case(str1, str2);
  std::cout << "Strings equal ignoring case: " << (equals ? "true" : "false") << std::endl;
}
void insert_Demo()
{
  std::string str = "hello world";
std::string sub = "beautiful ";
size_t pos = 6;
std::string result = gs->insert(str, pos, sub);
std::cout << "After insert: " << result << std::endl;
}
void remove_Demo()
{
  std::string str = "hello world hello";
std::string sub = "hello";
std::string result = gs->remove(str, sub);
std::cout << "After remove: " << result << std::endl;
}
void pop_Demo()
{
  std::string str = "hello";
char last_char = gs->pop(str);
std::cout << "Last character removed: " << last_char << std::endl;
std::cout << "String after pop: " << str << std::endl;
}
void DemoGiString()
{
  pop_Demo();
  remove_Demo();
  insert_Demo();
  equals_ignore_case_Demo();
  JOIN_Demo();
  StartWith_Demo();
  EndWith_Demo();
  is_ascii_Demo();
  is_numeric_Demo();
  is_alpha_Demo();
  is_alphanumeric_Demo();
  zfill_Demo();
  ltrim_Demo();
  find_Demo();
  contains_Demo();
   {
    GiString *GString = new GiString();

    std::string text = "hello, turbo1337GS";
    std::string input = "A man, a plan, a canal, Panama";
    std::string hello = "hello, Hello, hELLO world";

    text = GString->capitalize(text);
    std::cout << text << "\n";

    text = GString->capitalizeWords(text);
    std::cout << text << "\n";

    text = GString->swapcase(text);
    std::cout << text << "\n";

    text = GString->reverse(text);
    std::cout << text << "\n";

    // To normal ;)
    text = GString->reverse(text);

    bool palindrome = GString->is_palindrome(input);
    std::cout << "Is palindrome? " << std::boolalpha << palindrome << std::endl;

    size_t width = input.size() + 10;
    char fill = '-';
    std::string centered = GString->center(input, width, fill);
    std::cout << "Centered string: " << centered << std::endl;

    std::string result = GString->rjust(input, input.size() + 10, '-');
    std::cout << "Right-justified string: " << result << std::endl;

    std::cout << "Uppercase string: " << GString->upper(input) << std::endl;
    std::cout << "Lower string: " << GString->lower(input) << std::endl;

    std::string sub = "hello";
    size_t occurrences = GString->count(hello, sub);
    std::cout << "Number of occurrences of 'hello': " << occurrences << std::endl;

    size_t start = 6;
    size_t end = 11;

    std::cout << "Substring from index " << start << " to " << end - 1 << ": " << GString->substring(input, start, end) << std::endl;

    std::string old_sub = "hELLO";
    std::string new_sub = "hi";
    std::cout << "After replacement: " << GString->replace(hello, old_sub, new_sub) << std::endl;

    char delimiter = ' ';
    std::cout << "chunks:\n";
    std::vector<std::string> chunks = GString->split(input, delimiter);
    for (const auto &str : chunks)
    {
      std::cout << str << std::endl;
    }
  }
}
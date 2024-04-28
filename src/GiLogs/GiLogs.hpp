#ifndef Logs
#define Logs
#include <string>

#include <iostream>
#include <cstdarg>
#include <string>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdarg>
#include <filesystem>

#include <cstdarg>
#include <cstdio>
#include <cstring> 
#include <thread>  
#include <chrono>  
class Glogs
{
public:
    enum class ConsoleColor
    {
        Black = 0,
        DarkBlue = 1,
        DarkGreen = 2,
        DarkCyan = 3,
        DarkRed = 4,
        DarkMagenta = 5,
        DarkYellow = 6,
        Gray = 7,
        DarkGray = 8,
        Blue = 9,
        Green = 10,
        Cyan = 11,
        Red = 12,
        Magenta = 13,
        Yellow = 14,
        White = 15
    };

    void SetConsoleColor(Glogs::ConsoleColor color);
    std::string FormatString(const char *format, ...);
    void Error(std::string e);
    void Succes(std::string e);

    void Warn(std::string e);
    void Info(std::string e);
    void Table(std::vector<std::vector<std::string>> rows);

    void ClearConsole();
    void SetConsoleTitle(std::string e);
    void File(std::string fn);
    void Block(std::string e, char pr = '#');
    void coutFlush(const char *format, ...);
    void LogToFile(const std::string &message, const std::string &filename);
    void LogToConsole(const std::string &message, ConsoleColor color);
    void LogErrorAndExit(const std::string &errorMessage, int exitCode);
    void LogDebug(const std::string &debugMessage);
    void PrintSystemInfo();
};
#endif //! Logs
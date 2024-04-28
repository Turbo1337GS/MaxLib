#include "GiLogs.hpp"
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#elif defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#include <termios.h>
#endif

void Glogs::SetConsoleColor(Glogs::ConsoleColor color)
{
#if defined(_WIN32) || defined(_WIN64) // Dla Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
#elif defined(__unix__) || defined(__APPLE__) // Dla Unix / Linux / MacOS
    const char *colors[] = {
        "\x1B[30m", "\x1B[34m", "\x1B[32m", "\x1B[36m", "\x1B[31m",
        "\x1B[35m", "\x1B[33m", "\x1B[37m", "\x1B[90m", "\x1B[94m",
        "\x1B[92m", "\x1B[96m", "\x1B[91m", "\x1B[95m", "\x1B[93m", "\x1B[97m"};
    std::cout << colors[static_cast<int>(color)];
#else
#error Platform not supported
#endif
}

std::string Glogs::FormatString(const char *format, ...)
{
    // Start with a reasonable size of buffer
    size_t size = 1024 * 4;
    std::vector<char> buffer(size);

    va_list args;
    while (true)
    {
        // Begin extracting arguments
        va_start(args, format);
        // Try to print to the buffer
        int needed = vsnprintf(buffer.data(), size, format, args);
        va_end(args);

        if (needed <= -1)
        {
            // Error occurred
            return {};
        }
        else if ((size_t)needed < (size_t)size)
        {
            // String fit into the buffer
            return std::string(buffer.data());
        }
        else
        {
            // Resize buffer according to needed size (accounting for null terminator)
            size = needed + 1;
            buffer.resize(size);
        }
    }
}
void Glogs::Error(std::string e)
{
    SetConsoleColor(ConsoleColor::Red);
    std::cerr << e << std::endl;
    SetConsoleColor(ConsoleColor::White);
}
void Glogs::Succes(std::string e)
{
    SetConsoleColor(ConsoleColor::Green);
    std::cerr << e << std::endl;
    SetConsoleColor(ConsoleColor::White);
}
void Glogs::Warn(std::string e)
{
    SetConsoleColor(ConsoleColor::Yellow);
    std::cerr << e << std::endl;
    SetConsoleColor(ConsoleColor::White);
}
void Glogs::Info(std::string e)
{
    SetConsoleColor(ConsoleColor::Gray);
    std::cerr << e << std::endl;
    SetConsoleColor(ConsoleColor::White);
}

void Glogs::Table(std::vector<std::vector<std::string>> rows)
{
    std::vector<int> colWidths;
    for (const auto &row : rows)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            if (colWidths.size() <= i)
            {
                colWidths.push_back(0);
            }
            colWidths[i] = std::max(colWidths[i], static_cast<int>(row[i].length()));
        }
    }

    for (const auto &row : rows)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            std::cout << std::left << std::setw(colWidths[i] + 2) << row[i];
        }
        std::cout << std::endl;
    }
}

void Glogs::ClearConsole()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__unix__) || defined(__APPLE__)
    system("reset");
#endif
}

void Glogs::SetConsoleTitle(std::string e)
{
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleTitleA(e.c_str());
#elif defined(__linux__) || defined(__unix__)
    std::cout << "\033]0;" << e << "\007";
#elif defined(__APPLE__) || defined(__MACH__)
    std::cout << "\033]0;" << e << "\007";
#else
    std::cout << "ERROR." << std::endl;
#endif
}
void Glogs::File(std::string fn)
{
    if (std::filesystem::exists(fn))
    {
        std::stringstream buf;
        std::fstream f(fn);
        buf << f.rdbuf();
        std::cout << buf.str() << std::endl;
    }
    else
    {
        std::string e = FormatString("Canon't find %s file", fn.c_str());
        Error(e);
    }
}
void Glogs::Block(std::string e, char pr)
{
    int leng = e.length();

    int width = leng + 10;
    int height = 5;

    for (int h = 0; h < height; h++)
    {
        if (h == 0 || h == height - 1)
        {
            for (int w = 0; w < width; w++)
            {
                std::cout << pr;
            }
        }
        else if (h == height / 2)
        {
            std::cout << pr;
            for (int sp = 0; sp < 4; sp++)
                std::cout << " ";
            std::cout << e;
            for (int sp = 0; sp < 4; sp++)
                std::cout << " ";
            std::cout << pr;
        }
        else
        {
            std::cout << pr;
            for (int w = 1; w < width - 1; w++)
            {
                std::cout << " ";
            }
            std::cout << pr;
        }
        std::cout << std::endl;
    }
}
void Glogs::coutFlush(const char *format, ...)
{
    static std::string lastBuffer = "";
    char buffer[3096];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    std::cout << "\r" << std::string(lastBuffer.size(), ' ');
    std::cout << "\r" << buffer;
    std::cout.flush();

    lastBuffer = buffer;
}

void Glogs::LogToFile(const std::string& message, const std::string& filename)
{
    std::ofstream logFile(filename, std::ios_base::app);
    if (logFile.is_open())
    {
        logFile << message << std::endl;
        logFile.close();
    }
    else
    {
        Warn("Failed to open log file for writing");
    }
}

void Glogs::LogToConsole(const std::string& message, ConsoleColor color)
{
    SetConsoleColor(color);
    std::cout << message << std::endl;
    SetConsoleColor(ConsoleColor::White);
}

void Glogs::LogErrorAndExit(const std::string& errorMessage, int exitCode)
{
    Error(errorMessage);
    std::exit(exitCode);
}

void Glogs::LogDebug(const std::string& debugMessage)
{
#ifdef DEBUG_MODE
    LogToConsole(debugMessage, ConsoleColor::White);
#else
    // Debug logging is only active in DEBUG_MODE
#endif
}

void Glogs::PrintSystemInfo()
{
#if defined(_WIN32) || defined(_WIN64)
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    std::cout << "Processor Architecture: " << sysInfo.wProcessorArchitecture << std::endl;
#elif defined(__unix__) || defined(__APPLE__)
    std::cout << "Number of Cores: " << std::thread::hardware_concurrency() << std::endl;
#endif
}







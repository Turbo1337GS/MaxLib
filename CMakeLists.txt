cmake_minimum_required(VERSION 3.10)

# Nazwa projektu oraz używane języki
project(MaxLib VERSION 1.0 LANGUAGES CXX)

# Dodanie standardu C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ustawienia kompilatora
add_compile_options(-Wall -g)

# Dodanie katalogu z plikami źródłowymi
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Automatyczne znajdowanie plików źródłowych *.cpp
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")

# Ustawienie nazwy pliku wykonywalnego
set(EXECUTABLE_NAME MaxLib)

# Dodanie pliku wykonywalnego
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Ustawienie katalogu z plikami wykonywalnymi
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Włączenie obsługi katalogu z plikami .o
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/obj)

# Dodanie opcji czyszczenia (clean)
add_custom_target(clean-all
   COMMAND ${CMAKE_BUILD_TOOL} clean
   COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/CMakeClean.cmake
)


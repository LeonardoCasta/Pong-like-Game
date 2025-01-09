cmake_minimum_required(VERSION 3.31.3)
project(GAME)

# Set the source directory (update the path if necessary)
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/source")

# Collect all source files in the directory
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

# Specify the executable name
set(EXECUTABLE_NAME "game")

# Create the executable from the collected sources
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Set the output directory for the executable
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# Link SFML libraries
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)

# Optional: Set compiler options
# target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Wextra -O2)
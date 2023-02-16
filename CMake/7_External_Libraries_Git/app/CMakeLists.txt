
# Set varaibles and list all the source files
set(EXE_SOURCES
    "main.cc")

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

# Set external target library using the project name as nlohmann_json in its CMakeLists.txt
target_link_libraries(${EXECUTABLE_NAME}  PUBLIC 
    ${LIBRARY_NAME}
    nlohmann_json)
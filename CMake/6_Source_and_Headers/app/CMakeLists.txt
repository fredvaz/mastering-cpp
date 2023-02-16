
# Set varaibles and list all the source files
set(EXE_SOURCES
    "main.cc")


add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

# Set the variables names using ${}
target_link_libraries(${EXECUTABLE_NAME}  PUBLIC ${LIBRARY_NAME})
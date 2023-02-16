
# Set the variables names using ${}
add_executable(${EXECUTABLE_NAME} main.cc)

# Set the variables names using ${}
target_link_libraries(${EXECUTABLE_NAME}  PUBLIC ${LIBRARY_NAME})
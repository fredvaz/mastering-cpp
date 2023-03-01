# Set the variables names using ${}
add_library(${LIBRARY_NAME} STATIC my_lib.cc)

# Set the variables names using ${}
target_include_directories(${LIBRARY_NAME} PUBLIC "./")
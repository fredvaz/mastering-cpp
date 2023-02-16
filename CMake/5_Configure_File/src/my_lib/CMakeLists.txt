
# All these directories add to our include directories 

# Set the variables names using ${}
add_library(${LIBRARY_NAME} STATIC my_lib.cc)

# Set the variables names using ${}
# Add the version config to our library, then to be include in main.cc our project varaibles
target_include_directories(${LIBRARY_NAME} PUBLIC 
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")
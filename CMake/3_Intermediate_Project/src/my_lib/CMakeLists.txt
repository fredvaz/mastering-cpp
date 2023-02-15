# Moved to here and removed the directory src/
add_library(Library STATIC my_lib.cc)

# To define where should find the header files (in this case in same directory)
target_include_directories(Library PUBLIC "./")
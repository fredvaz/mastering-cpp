
# Set varaibles and list all the source files
set(LIBRARY_SOURCES
    "my_lib.cc")

# Set varaibles and list all the headers files
set(LIBRARY_HEADERS
    "my_lib.h")

# Set a new varaible for the added the Feteched Libraries
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC 
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

# changed to LIBRARY_INCLUDES set above
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${LIBRARY_INCLUDES})

# added
target_link_libraries(${LIBRARY_NAME} PUBLIC
    nlohmann_json::nlohmann_json
    fmt::fmt
    spdlog::spdlog
    cxxopts::cxxopts)

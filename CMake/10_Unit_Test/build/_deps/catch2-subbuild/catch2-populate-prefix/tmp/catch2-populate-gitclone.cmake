
if(NOT "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitinfo.txt" IS_NEWER_THAN "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --depth 1 --no-single-branch "https://github.com/catchorg/Catch2" "catch2-src"
    WORKING_DIRECTORY "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/catchorg/Catch2'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout v2.13.9 --
  WORKING_DIRECTORY "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v2.13.9'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitinfo.txt"
    "/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/fredvaz/mastering_cpp/CMake/10_Unit_Test/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/catch2-populate-gitclone-lastrun.txt'")
endif()


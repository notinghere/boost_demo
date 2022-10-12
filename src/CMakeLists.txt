
option(ENABLE_CPP_14 "compile with the c++14" ON)
if (ENABLE_CPP_14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

MESSAGE(STATUS, "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

set(CMAKE_C_FLAGS "-ffunction-sections -Wall -maes -msse2 -msse4.1 -mpclmul -Wfatal-errors -pthread -fPIC -Wno-ignored-attributes")

# Set build type
if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Select flags.
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO " -O2 -g -ggdb -rdynamic")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb -rdynamic")

# The options for the static library
set(LINK_FLAGS "-Wl,-rpath=.,-static -Wl,-Bdynamic -lgcc_s")

# The linker options
set(CMAKE_SHARED_LINKER_FLAGS "${LINK_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS    "${LINK_FLAGS}")

FIND_PACKAGE(Boost 1.77.0 REQUIRED COMPONENTS system  thread)
IF(Boost_FOUND)
    MESSAGE(STATUS, "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
    MESSAGE(STATUS, "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}")
    MESSAGE(STATUS, "Boost_VERSION = ${Boost_VERSION}")
    MESSAGE(STATUS, "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
ELSE()
    MESSAGE(STATUS, "BOOST NOT FOUND")
ENDIF()

add_subdirectory(./demo1)
add_subdirectory(./config_test)
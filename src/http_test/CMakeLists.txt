cmake_minimum_required(VERSION 3.16)

project(http_test)

aux_source_directory(./src SRC_MAIN)
add_executable (${PROJECT_NAME} ${SRC_MAIN})
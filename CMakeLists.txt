cmake_minimum_required(VERSION 3.26)

project(UICustomer)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    GD_VERSION 2.208
    SOURCES 
        src/main.cpp
        src/MenuEditLayer.cpp
)

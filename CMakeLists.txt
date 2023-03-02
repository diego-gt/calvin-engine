cmake_minimum_required(VERSION 3.18)

project(calvin_engine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To use with LSPs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ENGINE_INCLUDES
        include/core/Types.hpp
        include/core/Visibility.hpp
        include/math/Angle.hpp
        include/math/Coordinates.hpp
        include/math/Joint2D.hpp
        include/math/Link2D.hpp
        include/math/Vector2D.hpp
)

set(ENGINE_SOURCES
        src/math/Angle.cpp
        src/math/Coordinates.cpp
        src/math/Vector2D.cpp
        src/math/Joint2D.cpp
        src/math/Link2D.cpp
)

add_library(calvin_engine
        ${ENGINE_INCLUDES}
        ${ENGINE_SOURCES}
)

find_package(fmt REQUIRED)

target_include_directories(calvin_engine PUBLIC include)
target_link_libraries(calvin_engine PRIVATE fmt::fmt)

set(DEMO_SOURCES
        jpl/src/main.cpp
)

add_executable(jpl
        ${DEMO_SOURCES}
)

target_link_libraries(jpl PRIVATE calvin_engine)

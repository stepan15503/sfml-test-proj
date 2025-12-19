cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp src/additional_data/Engine.cpp src/additional_data/Player.cpp src/additional_data/Input.cpp src/additional_data/Update.cpp src/additional_data/Draw.cpp src/additional_data/Bullet.cpp src/additional_data/EnemyBullet.cpp src/additional_data/Enemy.cpp src/additional_data/checkCollisionPE.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

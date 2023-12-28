cmake_minimum_required(VERSION 3.27)
project(tetrimino-game VERSION 0.1.0 LANGUAGES C CXX)

# 소스 파일 목록
set(SOURCES
    src/main.cpp
    src/direction.cpp
    src/eventHandler.cpp
    src/game.cpp
    src/map.cpp
    src/mino.cpp
    src/renderer.cpp
)

# 헤더 파일 목록
set(HEADERS
    include/direction.h
    include/eventHandler.h
    include/game.h
    include/map.h
    include/mino.h
    include/renderer.h
)

# 프로젝트 빌드 설정
add_executable(tetrimino-game ${SOURCES} ${HEADERS})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 헤더 파일 디렉토리 추가
target_include_directories(tetrimino-game PRIVATE include)
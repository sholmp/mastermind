set(sources
        mastermind.cpp
        mastermindgame.cpp
    )

set(headers
        mastermind.hpp
        mastermindgame.hpp
    )

message(status ${Mastermind_SOURCE_DIR})
add_library(mastermind STATIC ${sources} ${headers})

add_executable(demo demo.cpp)
target_link_libraries(demo mastermind)

add_executable(MMGameTest mmclasstest.cpp)
target_link_libraries(MMGameTest mastermind)



set(sources
        #mastermind.cpp
        mastermindgame.cpp
        mastermindlogic.cpp
#        mastermindplayer.cpp
    )

set(headers
        #mastermind.hpp
        mastermindgame.hpp
        mastermindlogic.hpp
        mastermindplayer.hpp
    )

message(status ${Mastermind_SOURCE_DIR})
add_library(mastermind STATIC ${sources} ${headers})

add_executable(demo demo.cpp inputparser.hpp)
target_link_libraries(demo mastermind)

#add_executable(MMGameTest mmclasstest.cpp inputparser.hpp)
#target_link_libraries(MMGameTest mastermind)



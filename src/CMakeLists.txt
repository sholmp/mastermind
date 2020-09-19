set(sources
        mastermindgame.cpp
        mastermindlogic.cpp
#        mastermindplayer.cpp
#        fiveguessai.cpp
    )

set(headers
        mastermindgame.hpp
        mastermindlogic.hpp
        mastermindplayer.hpp
#        fiveguessai.hpp
    )

message(status ${Mastermind_SOURCE_DIR})
add_library(mastermind STATIC ${sources} ${headers})

add_executable(demo demo.cpp inputparser.hpp)
target_link_libraries(demo mastermind)

add_executable(five_guess_testing
                main.cpp
                combotree.h combotree.cpp
                fiveguessai.cpp fiveguessai.hpp)
target_link_libraries(five_guess_testing mastermind)





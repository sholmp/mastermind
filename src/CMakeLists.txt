set(sources
        mastermindgame.cpp
        mastermindlogic.cpp
        mastermindplayer.cpp
        humanplayer.cpp
        fiveguessai.cpp
        simpleai.cpp
    )

set(headers
        mastermindgame.hpp
        mastermindlogic.hpp
        mastermindplayer.hpp
        humanplayer.hpp
        fiveguessai.hpp
        simpleai.hpp
    )

add_library(mastermind STATIC ${sources} ${headers})


#add_library(mastermindplayers STATIC combotree.h combotree.cpp
#                                    fiveguessai.hpp fiveguessai.cpp
#                                    humanplayer.hpp humanplayer.cpp)


add_executable(demo demo.cpp)
target_link_libraries(demo mastermind)

add_executable(player_testing
                main.cpp
                fiveguessai.hpp fiveguessai.cpp
                humanplayer.hpp humanplayer.cpp)


target_link_libraries(player_testing mastermind)





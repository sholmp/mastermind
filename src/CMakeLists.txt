set(sources
	mastermind.cpp
	)

set(headers
	mastermind.hpp
	)

message(status ${Mastermind_SOURCE_DIR})
add_library(mastermind STATIC ${sources} ${headers})

add_executable(demo main.cpp)
target_link_libraries(demo mastermind)


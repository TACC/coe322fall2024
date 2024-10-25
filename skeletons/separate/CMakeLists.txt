cmake_minimum_required( VERSION 3.20 )
project( prog VERSION 1.0 )

add_executable( prog )
target_sources( prog PRIVATE main.cpp func.cpp )

install( TARGETS prog DESTINATION . )


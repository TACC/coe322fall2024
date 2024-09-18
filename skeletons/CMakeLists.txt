cmake_minimum_required( VERSION 3.20 )
project( newton VERSION 1.0 )

message( "Using sources: newton.cpp" )
add_executable( newton )
target_sources( newton PRIVATE newton.cpp )

target_compile_features( newton PRIVATE cxx_std_17 )
install( TARGETS newton DESTINATION . )


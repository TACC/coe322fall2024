cmake_minimum_required( VERSION 3.12 )
project( ${PROJECTNAME} VERSION 1.0 )

add_executable( ${PROJECTNAME} ${PROJECTNAME}.cpp )
target_compile_features( ${PROJECTNAME} PRIVATE cxx_std_17 )

find_package( Eigen3 REQUIRED  )
target_link_libraries( ${PROJECTNAME} PUBLIC Eigen3::Eigen )

install( TARGETS ${PROJECTNAME} DESTINATION . )

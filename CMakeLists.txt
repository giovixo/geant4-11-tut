#cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
# cmake versions 3.27 > 3.5 because the versioning systems follow the sequence 3.5, 3.6, 3.7.....3.19, 3.20...3.27
# See:  https://stackoverflow.com/questions/76672135/confused-about-cmake-versions-need-cmake-3-5-but-cmakes-site-can-only-find-cma
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Tutorial)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)



file(GLOB MACRO_FILES "macros/*.mac")
file(COPY ${MACRO_FILES} DESTINATION ${CMAKE_BINARY_DIR}/)

add_executable(sim sim.cc ${sources})
target_link_libraries(sim ${Geant4_LIBRARIES})

add_custom_target(Tutorial DEPENDS sim)



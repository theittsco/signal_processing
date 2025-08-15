cmake_minimum_required(VERSION 3.15)
project(dsp_eigen CXX)

find_package(Eigen3 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(FFTW3 QUIET fftw3)

add_executable(demo demo.cpp)
target_include_directories(demo PRIVATE ${EIGEN3_INCLUDE_DIR})
if(FFTW3_FOUND)
  target_include_directories(demo PRIVATE ${FFTW3_INCLUDE_DIRS})
  target_link_libraries(demo PRIVATE ${FFTW3_LIBRARIES})
endif()

CMAKE_MINIMUM_REQUIRED(VERSION 2.4)


SET(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Options are Debug or Release")
PROJECT(my_executable C)

# header files
INCLUDE_DIRECTORIES(include)

FILE(GLOB SRCS src/tunnel/*.c *.c)

ADD_EXECUTABLE(main ${SRCS})


# Define custom targets to easily switch the build type:
ADD_CUSTOM_TARGET(debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
  )

ADD_CUSTOM_TARGET(release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Switch CMAKE_BUILD_TYPE to Release"
  )

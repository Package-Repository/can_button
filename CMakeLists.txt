cmake_minimum_required(VERSION 3.5)
project(can_button)

get_filename_component(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)

file(GLOB SOURCES 
    src/can_button.cpp
    src/fork_program.cpp
)
include_directories(include)

add_library(
    ${PROJECT_NAME}
    SHARED 
    ${SOURCES}
)

add_executable(
    ${PROJECT_NAME}_exec
    main/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
)

target_link_libraries(
    ${PROJECT_NAME}_exec PRIVATE 
    ${PROJECT_NAME}
)

install(
    TARGETS ${PROJECT_NAME} 
    DESTINATION lib/${PROJECT_NAME}
)

install(
    TARGETS ${PROJECT_NAME}_exec 
    DESTINATION bin/${PROJECT_NAME}
)

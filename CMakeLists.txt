cmake_minimum_required(VERSION 3.0.0)
project(DiffuseLighting VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(DiffuseLighting main.cpp)

add_subdirectory(external/glm)

# This enables you to include your library without the path to the library. This is for header files.*
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    ${PROJECT_BINARY_DIR}
	external/glm/glm
)

# This is for the actual source of your libraries, as opposed to header files.*
target_link_directories(${PROJECT_NAME}
	PRIVATE
    external/glm/glm
)

# Link library to project.
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    glm::glm
)

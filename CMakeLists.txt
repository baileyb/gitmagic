cmake_minimum_required (VERSION 3.12)
project (Tutorial)
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

include_directories ("${PROJECT_BINARY_DIR}")

option (USE_MYMATH "Use tutorial provide math implementation" ON)

# add the MathFunctions library
if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable(Tutorial tutorial.cc)
target_link_libraries(Tutorial ${EXTRA_LIBS})

# add the install targets
set (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
          DESTINATION include)
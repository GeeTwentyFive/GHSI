cmake_minimum_required(VERSION 3.30...4.4)
project(GHSInstaller)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/embed")
message(STATUS "Archiving & compressing game files...")
file(ARCHIVE_CREATE
        OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/build/embed/GameFiles.zip"
        PATHS
                "${CMAKE_CURRENT_SOURCE_DIR}/embed/GameFiles/hidden"
                "${CMAKE_CURRENT_SOURCE_DIR}/embed/GameFiles/hidden-4a"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/embed/GameFiles"
        FORMAT "zip"
)
message(STATUS "Archiving & compressing Source SDK Base 2006 patched files...")
file(ARCHIVE_CREATE
        OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/build/embed/SourceSDKBase2006_Patches.zip"
        PATHS
                "${CMAKE_CURRENT_SOURCE_DIR}/embed/SourceSDKBase2006_Patches/bin"
                "${CMAKE_CURRENT_SOURCE_DIR}/embed/SourceSDKBase2006_Patches/platform"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/embed/SourceSDKBase2006_Patches"
        FORMAT "zip"
)

add_executable(${PROJECT_NAME}
	"main.cpp"
)

set(ZIP_ENABLE_DEFLATE OFF CACHE BOOL "" FORCE)
add_subdirectory("libs/zip")

target_link_libraries(${PROJECT_NAME} PRIVATE
        zip
)
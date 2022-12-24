# define minimum make version
cmake_minimum_required(VERSION 3.20)
project (Wordsmith)
set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

##--------------------------------------------------
## Please set your wxWidgets configuration here
##--------------------------------------------------

# Here you can define what libraries of widgets you need for your
# application. You can figure out what libraries you need here;
# https://www.wxwidgets.org/manuals/2.8/wx_librarieslist.html
# We need the Find package for wxWidgets to work
# NOTE: if you're using aui, include aui in this required components list.

# It was noticed that when using MinGW gcc it is essential that 'core' is mentioned before 'base'
find_package (wxWidgets COMPONENTS core base REQUIRED)

##--------------------------------------------------
## Actual config file starts here
##--------------------------------------------------

# For Rhymer.h
include_directories(
        ${PROJECT_SOURCE_DIR}/include)

# wxWidgets include (this will do all the magic to configure everything)
include ("${wxWidgets_USE_FILE}")

set (SRCS main.cpp)

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources

if (WIN32)
    set (SRCS ${SRCS} wxWidgetTest.rc main.cpp Wordcrafter.h Affix.h)
endif (WIN32)

add_executable(${PROJECT_NAME} WIN32 ${SRCS})
target_link_libraries (${PROJECT_NAME} ${wxWidgets_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON)

# For Rhymer.h
if(MSVC)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cmudict-0.7b $<TARGET_FILE_DIR:${PROJECT_NAME}>\\..
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cmudict-0.7b.phones $<TARGET_FILE_DIR:${PROJECT_NAME}>\\..)
else()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cmudict-0.7b $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/cmudict-0.7b.phones $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()





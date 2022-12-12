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

# wxWidgets include (this will do all the magic to configure everything)
include ("${wxWidgets_USE_FILE}")

set (SRCS main.cpp)

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources

if (WIN32)
    set (SRCS ${SRCS} wxWidgetTest.rc main.cpp Wordcrafter.h Wordcrafter.cpp)
endif (WIN32)

add_executable(${PROJECT_NAME} WIN32 ${SRCS})
target_link_libraries (${PROJECT_NAME} ${wxWidgets_LIBRARIES})



include_directories("${CMAKE_SOURCE_DIR}/Base/Header")
include_directories("${CMAKE_SOURCE_DIR}/Log/Header")

if(UNIX AND ANDROID)
  include_directories("${CMAKE_SOURCE_DIR}/Base/Header/rbx/Android")
endif()
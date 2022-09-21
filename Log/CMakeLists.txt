include(Base)

include_directories(Header)

list(APPEND HEADERS Header/FastLog.h)
list(APPEND HEADERS Header/FastLogStream.h)

list(APPEND SOURCES Source/FastLog.cpp)
list(APPEND SOURCES Source/FastLogStream.cpp)

add_library(Log STATIC ${SOURCES} ${HEADERS})

if(WIN32)
  target_compile_definitions(Log PRIVATE _WINSOCK_DEPRECATED_NO_WARNINGS=1)
endif()
include(App)

include_directories(Header)
include_directories(Header/AppDraw)
include_directories(../Graphics3D/Header)
include_directories(../GfxBase/Header)

list(APPEND HEADERS Header/AppDraw/Draw.h)
list(APPEND HEADERS Header/AppDraw/HitTest.h)
list(APPEND HEADERS Header/AppDraw/DrawAdorn.h)
list(APPEND HEADERS Header/AppDraw/HandleType.h)
list(APPEND HEADERS Header/AppDraw/DrawPrimitives.h)

list(APPEND SOURCES Source/Draw.cpp)
list(APPEND SOURCES Source/DrawAdorn.cpp)
list(APPEND SOURCES Source/HitTest.cpp)

add_library(AppDraw STATIC ${SOURCES} ${HEADERS})
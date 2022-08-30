include(App)

if(TAMPA_ANDROID)
  add_definitions(-DGLEW_NO_GLU)
endif()

include_directories("${CMAKE_SOURCE_DIR}/Rendering/AppDraw/Header")
include_directories("${CMAKE_SOURCE_DIR}/Rendering/GfxBase/Header")
include_directories("${CMAKE_SOURCE_DIR}/Rendering/GfxCore/Header")
include_directories("${CMAKE_SOURCE_DIR}/Rendering/Graphics3D/Header")

include_directories("${CMAKE_SOURCE_DIR}/Rendering/GfxCore/Header/GL")

if(TAMPA_WINDOWS)
  include_directories("${CMAKE_SOURCE_DIR}/Rendering/GfxCore/Header/D3D9")
  include_directories("${CMAKE_SOURCE_DIR}/Rendering/GfxCore/Header/D3D11")
endif()
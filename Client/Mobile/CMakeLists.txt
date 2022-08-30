include(App)
include(Network)
include(Rendering)
include_directories(../Client/Common/Shared/Header)

list(APPEND HEADERS AndroidSettingsService.h)
list(APPEND SOURCES AndroidSettingsService.cpp)
list(APPEND HEADERS JNIMain.h)
list(APPEND SOURCES JNIMain.cpp)
list(APPEND SOURCES JNIActivityCurlTest.cpp)
list(APPEND SOURCES JNICurlTestHelper.cpp)
list(APPEND SOURCES JNIGLActivity.cpp)
list(APPEND SOURCES JNIInputListener.cpp)
list(APPEND SOURCES JNIRobloxSettings.cpp)
list(APPEND HEADERS JNIUtil.h)
list(APPEND SOURCES JNIUtil.cpp)
list(APPEND HEADERS LogManager.h)
list(APPEND SOURCES LogManager.cpp)
list(APPEND HEADERS PlaceLauncher.h)
list(APPEND SOURCES PlaceLauncher.cpp)
list(APPEND HEADERS RobloxView.h)
list(APPEND SOURCES RobloxView.cpp)
list(APPEND HEADERS FunctionMarshaller.h)
list(APPEND SOURCES FunctionMarshaller.cpp)
list(APPEND SOURCES RobloxInfo.cpp)
list(APPEND HEADERS RobloxInfo.h)
list(APPEND SOURCES RobloxUtilities.cpp)
list(APPEND HEADERS RobloxUtilities.h)
list(APPEND SOURCES RobloxInput.cpp)
list(APPEND HEADERS Teleporter.h)
list(APPEND SOURCES Teleporter.cpp)
list(APPEND HEADERS RobloxInput.h)
list(APPEND HEADERS ../Client/Common/Base/Header/RenderSettingsItem.h)
list(APPEND SOURCES ../Client/Common/Base/Source/RenderSettingsItem.cpp)

add_library(Android OBJECT ${SOURCES} ${HEADERS})

add_library(Tampa SHARED
  $<TARGET_OBJECTS:Android>

  $<TARGET_OBJECTS:App>
  $<TARGET_OBJECTS:Base>
  $<TARGET_OBJECTS:BulletPhysics>
  $<TARGET_OBJECTS:Log>
  $<TARGET_OBJECTS:Network>
  $<TARGET_OBJECTS:AppDraw>
  $<TARGET_OBJECTS:GfxBase>
  $<TARGET_OBJECTS:GfxCore>
  $<TARGET_OBJECTS:GfxRender>
  $<TARGET_OBJECTS:Graphics3D>
)

set_target_properties(Tampa PROPERTIES OUTPUT_NAME "libtampa")
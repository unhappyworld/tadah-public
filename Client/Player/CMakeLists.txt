include(App)
include(Base)
include(FMOD)
include(LibWWW)
include(Log)
include(Network)
include(Rendering)
include(VMProtect)
include(RapidJSON)

if(WIN32)
  include(DirectX)
endif()

include_directories(Header)
include_directories(Resource)

include_directories(../Common/Base/Header)
include_directories(../Common/Shared/Header)
include_directories(../Common/Windows/Header)

if(WIN32)
  list(APPEND RESOURCES Resource/Client.rc)
endif()

list(APPEND HEADERS ../Common/Base/Header/ReflectionMetadata.h)
list(APPEND HEADERS ../Common/Base/Header/MachineConfiguration.h)

list(APPEND SOURCES ../Common/Base/Source/ReflectionMetadata.cpp)
list(APPEND SOURCES ../Common/Base/Source/MachineConfiguration.cpp)

list(APPEND HEADERS Header/Application.h)
list(APPEND HEADERS Header/Crypt.h)
list(APPEND HEADERS Header/Document.h)
list(APPEND HEADERS Header/functionHooks.h)
list(APPEND HEADERS Header/FunctionMarshaller.h)
list(APPEND HEADERS Header/GameVerbs.h)
list(APPEND HEADERS Header/InitializationError.h)
list(APPEND HEADERS Header/ReleasePatcher.h)
list(APPEND HEADERS Header/resource.h)
list(APPEND HEADERS Header/RobloxHooks.h)
list(APPEND HEADERS Header/stdafx.h)
list(APPEND HEADERS Header/Teleporter.h)
list(APPEND HEADERS Header/UserInput.h)
list(APPEND HEADERS Header/View.h)

list(APPEND SOURCES Source/Application.cpp)
list(APPEND SOURCES Source/Crypt.cpp)
list(APPEND SOURCES Source/Document.cpp)
list(APPEND SOURCES Source/functionHooks.cpp)
list(APPEND SOURCES Source/FunctionMarshaller.cpp)
list(APPEND SOURCES Source/GameVerbs.cpp)
list(APPEND SOURCES Source/main.cpp)
list(APPEND SOURCES Source/RandomPadding.cpp)
list(APPEND SOURCES Source/ReleasePatcher.cpp)
list(APPEND SOURCES Source/RenderJob.cpp)
list(APPEND SOURCES Source/robloxHooks.cpp)
list(APPEND SOURCES Source/stdafx.cpp)
list(APPEND SOURCES Source/Teleporter.cpp)
list(APPEND SOURCES Source/UserInput.cpp)
list(APPEND SOURCES Source/View.cpp)

if(WIN32)
  add_executable(Tampa WIN32
    ${SOURCES}
    ${HEADERS}
    ${RESOURCES}
  
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
  
  set(PLAYER_DEFINITIONS "_WINDOWS=1 WIN32=1 NDEBUG=1 WINVER=0x0603 _WIN32_WINNT=0x0603")
  set(PLAYER_OPTIONS "/FIXED /DEBUG:FULL /OPT:REF /OPT:ICF /LARGEADDRESSAWARE /LTCG:INCREMENTAL")
  
  if(x86)
    set(PLAYER_OPTIONS "${PLAYER_OPTIONS} /SAFESEH /BASE:0x00400000")
  elseif(x64)
    set(PLAYER_OPTIONS "${PLAYER_OPTIONS} /BASE:0x140000000")
    set(PLAYER_DEFINITIONS "${PLAYER_DEFINITIONS} _WIN64=1")
  endif()
  
  target_link_options(Tampa PRIVATE ${PLAYER_OPTIONS})
  target_compile_definitions(Tampa PRIVATE ${PLAYER_DEFINITIONS})
endif()

set_target_properties(Tampa PROPERTIES OUTPUT_NAME "TadahPlayer")
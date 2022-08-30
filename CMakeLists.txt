cmake_minimum_required(VERSION 3.22)

project(Tampa C CXX ASM)

if(NOT WIN32 OR UNIX)
  message(FATAL_ERROR "Unsupported platform.")
endif()

# Set the THIRD_PARTY_PATH from ENV.
if(NOT THIRD_PARTY_PATH)
  file(TO_CMAKE_PATH "$ENV{THIRD_PARTY_PATH}" THIRD_PARTY_PATH)
endif()

if(NOT THIRD_PARTY_PATH)
  message(FATAL_ERROR "THIRD_PARTY_PATH is not set")
endif()

file(TO_CMAKE_PATH "${THIRD_PARTY_PATH}" THIRD_PARTY_PATH)
list(APPEND CMAKE_PREFIX_PATH "${THIRD_PARTY_PATH}")

# Use modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules")

# x64 or x86?
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(x64 TRUE)
  set(x86 FALSE)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(x64 FALSE)
  set(x86 TRUE)
else()
  message(FATAL_ERROR "Unsupported platform.")
endif()

# MSVC specific things
if(WIN32)
  include_directories($ENV{INCLUDE})

  add_compile_definitions(
    WIN32=1
    _WIN32=1
    _HAS_AUTO_PTR_ETC=1
    _ENFORCE_MATCHING_ALLOCATORS=0
  )
  add_compile_options(/w)
  
  if(x64)
    add_compile_definitions(_WIN64=1)
  endif()
endif()

# Use C++17
set(CMAKE_CXX_STANDARD 17)

# Get all our packages from vcpkg
find_package(Boost REQUIRED)
find_package(cppnetlib CONFIG REQUIRED)
find_package(CURL CONFIG REQUIRED)
find_package(JPEG REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(PNG REQUIRED)
find_package(lz4 CONFIG REQUIRED)
find_package(OpenVR REQUIRED) 
find_package(SDL2 CONFIG REQUIRED)
find_package(ZLIB REQUIRED)

include_directories("${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include")
link_directories("${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/lib")

# Any other modules?
include(FMOD)
if(WIN32)
  include(DirectX)
endif()

# Include the projects and build them
add_subdirectory(App)
add_subdirectory(Base)
add_subdirectory(BulletPhysics)
add_subdirectory(Log)
add_subdirectory(Network)
add_subdirectory(Rendering)

if(TAMPA_STUDIO)
  if(ANDROID)
    message(FATAL_ERROR "Unsupported platform.")
  endif()
  
  add_subdirectory(Client/Studio)
elseif(TAMPA_PLAYER)
  if(ANDROID)
    add_subdirectory(Client/Mobile)
  else()
    add_subdirectory(Client/Player)
  endif()
elseif(TAMPA_SERVER)
  if(ANDROID)
    message(FATAL_ERROR "Unsupported platform.")
  endif()
  
  add_subdirectory(Client/Server)
endif()

# those subdirectories build, then they do add_executable/add_library to the target, etc. etc...

set_target_properties(Tampa PROPERTIES
  LINKER_LANGUAGE CXX
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(Tampa
  ${Boost_LIBRARIES}
  cppnetlib-uri cppnetlib-server-parsers cppnetlib-client-connections
  CURL::libcurl
  jpeg
  freetype
  fmod64_vc
  PNG::PNG
  lz4::lz4
  OpenVR::OpenVR
  SDL2::SDL2 SDL2::SDL2main
  ZLIB::ZLIB
)
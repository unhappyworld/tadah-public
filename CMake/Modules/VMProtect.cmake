set(vmp_ROOT "${THIRD_PARTY_PATH}/vmp")
include_directories("${vmp_ROOT}/Include/C")

if(WIN32)
  link_directories("${vmp_ROOT}/Lib/Windows")
elseif(UNIX)
  link_directories("${vmp_ROOT}/Lib/Linux")
endif()
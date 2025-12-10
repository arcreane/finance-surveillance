# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/EuronextSurveilllance_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/EuronextSurveilllance_autogen.dir/ParseCache.txt"
  "EuronextSurveilllance_autogen"
  )
endif()

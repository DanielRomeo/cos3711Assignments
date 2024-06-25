# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/cos3711q1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cos3711q1_autogen.dir/ParseCache.txt"
  "cos3711q1_autogen"
  )
endif()

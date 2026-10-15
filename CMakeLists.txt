cmake_minimum_required (VERSION 3.16)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("uni_labs")

add_executable (uni_labs
    "uni_labs.cpp"
    "oop_labs/oop_labs.h" 
    "oop_labs/oop_lab_1.h" 
    "oop_labs/oop_lab_2.h"
    "oop_labs/oop_lab_3.h"
    "oop_labs/oop_lab_4.h"
    "oop_labs/oop_lab_5.h"
    "intro_labs/intro_labs.h" 
    "intro_labs/intro_lab_1.h" 
    "intro_labs/intro_lab_2.h" 
    "intro_labs/intro_lab_3.h"
    "intro_labs/intro_lab_4.h"
    "intro_labs/intro_lab_5.h"
    "systems/presentation_system.h"
    "systems/timer.h" 
    "systems/Random.h" 
    "pch.h"
    "oop_labs/oop_lab_6.h" 
    "intro_labs/intro_lab_6.h" "oop_labs/oop_lab_7.h" "intro_labs/intro_lab_7.h" "algorithms/quick_sort.h")

target_include_directories(uni_labs PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/systems"
    "${CMAKE_CURRENT_SOURCE_DIR}/oop_labs"
    "${CMAKE_CURRENT_SOURCE_DIR}/intro_labs"
)


target_compile_definitions(uni_labs PRIVATE SOURCE_PATH="${CMAKE_SOURCE_DIR}")

#target_precompile_headers(uni_labs PRIVATE "pch.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET uni_labs PROPERTY CXX_STANDARD 20)
  set_property(TARGET uni_labs PROPERTY CXX_STANDARD_REQUIRED ON)
endif()
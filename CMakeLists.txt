cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "FilterRed.cpp" "FilterRed.h" "FilterWhiteBlack.cpp" "FilterWhiteBlack.h" "Filter.h" "png_toolkit.h" 
    "stb_image.h" "stb_image_write.h" "Cfg_Reader.cpp" "Cfg_Reader.h" "Filter.cpp" "FilterThreshold.cpp" "FilterThreshold.h" )

cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "png_toolkit.h" "stb_image.h" "stb_image_write.h" "png_toolkit.cpp" "main.cpp" "Cfg_Reader.h" "Cfg_Reader.cpp" "PixelRGB.h"
"Filter.h" "Filter.cpp" "FilterRed.h" "FilterRed.cpp" "FilterBlackWhite.h" "FilterBlackWhite.cpp" "FilterThreshold.h" "FilterThreshold.cpp"
"FilterConvolutional.h" "FilterConvolutional.cpp" "FilterEdge.h" "FilterEdge.cpp" "FilterBlur.h" "FilterBlur.cpp")

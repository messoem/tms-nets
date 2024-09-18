cmake_minimum_required(VERSION 3.10)
project(sample_project)

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Укажите каталог с заголовочными файлами
include_directories(tms-nets-3.0.1/include)
include_directories(tms-nets-3.0.1/include/tms-nets)
include_directories(tms-nets-3.0.1/include/tms-nets/details)
include_directories(tms-nets-3.0.1/include/tms-nets/thirdparty)
include_directories(tms-nets-3.0.1/include/tms-nets/thirdparty/irrpoly)

# Добавьте исполняемый файл
add_executable(sample_project sample_project.cpp)

# Добавьте исходные файлы
file(GLOB SOURCE_FILES
    tms-nets-3.0.1/source/digital_net.cpp
    tms-nets-3.0.1/source/niederreiter.cpp
    tms-nets-3.0.1/source/sobol.cpp
    tms-nets-3.0.1/source/details/common.cpp
    tms-nets-3.0.1/source/details/genmat.cpp
    tms-nets-3.0.1/source/details/gf2poly.cpp
    tms-nets-3.0.1/source/details/gfppoly.cpp
    tms-nets-3.0.1/source/details/recseq.cpp
    tms-nets-3.0.1/source/thirdparty/irrpoly/gf.cpp
    tms-nets-3.0.1/source/thirdparty/irrpoly/gfcheck.cpp
    tms-nets-3.0.1/source/thirdparty/irrpoly/gfpoly.cpp
    
)

# Свяжите исполняемый файл с исходными файлами
target_sources(sample_project PRIVATE ${SOURCE_FILES})

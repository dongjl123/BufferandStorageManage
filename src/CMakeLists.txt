aux_source_directory(./buffer TEMP_SRC)
SET(MY_SRC ${TEMP_SRC})

aux_source_directory(./storage TEMP_SRC)
SET(MY_SRC ${TEMP_SRC})

add_library(src_lib ${TEMP_SRC})

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(src_lib PUBLIC DEBUG)
endif(CMAKE_BUILD_TYPE MATCHES Debug)
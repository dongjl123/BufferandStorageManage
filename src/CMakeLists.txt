aux_source_directory(./buffer TEMP_SRC)
SET(MY_SRC ${TEMP_SRC})

add_library(buffer ${TEMP_SRC})
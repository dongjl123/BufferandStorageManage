aux_source_directory(./buffer TEMP_SRC)
SET(MY_SRC ${TEMP_SRC})

aux_source_directory(./storage TEMP_SRC)
SET(MY_SRC ${TEMP_SRC})

add_library(src_lib ${TEMP_SRC})
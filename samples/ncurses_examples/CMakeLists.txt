# Get a list of all folders
file(GLOB ALL_FILES_CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/* )

# Set output bin in a subfolder
get_filename_component(CURRENT_BIN_PATH ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_NCI_BIN_PATH}/samples/${CURRENT_BIN_PATH}/)

foreach(CURRENT_FILE ${ALL_FILES_CURRENT_PATH})
  if(IS_DIRECTORY ${CURRENT_FILE})
    message("Adding samples: ${CURRENT_FILE}")
    add_subdirectory( ${CURRENT_FILE} )
  endif()
endforeach()

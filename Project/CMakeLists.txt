# Add source directory
aux_source_directory(src/ PROJECT_SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Project ${PROJECT_SOURCES} include/constants.h src/person.cpp include/person.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Project PRIVATE include/)
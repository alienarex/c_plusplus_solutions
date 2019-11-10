# Add source directory
aux_source_directory(src/ LAB_3_SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_3 ${LAB_3_SOURCES} include/Stats.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_3 PRIVATE include/)

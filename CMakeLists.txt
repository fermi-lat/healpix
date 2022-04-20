add_library(
  healpix SHARED
  src/alm_filter_tools.cxx
  src/AlmOp.cxx
  src/CosineBinner.cxx
  src/Healpix.cxx
  src/HealpixArrayIO.cxx
  src/HealPixel.cxx
  src/HealpixMap.cxx
  src/HealpixRegion.cxx
  src/Map.cxx
)

target_include_directories(
  healpix PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:>
)

target_link_libraries(
  healpix
  PUBLIC PkgConfig::healpix_cxx astro
  PRIVATE OpenMP::OpenMP_CXX
)

# target_compile_definitions(healpix PRIVATE _OPENMP)

add_executable(test_healpix src/test/test_healpix.cxx)
target_link_libraries(test_healpix PRIVATE healpix)

###############################################################
# Installation
###############################################################
install(DIRECTORY healpix DESTINATION ${FERMI_INSTALL_INCLUDEDIR})
install(DIRECTORY data/ DESTINATION ${FERMI_INSTALL_DATADIR})

install(
  TARGETS healpix test_healpix
  EXPORT fermiTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

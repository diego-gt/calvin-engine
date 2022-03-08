project(
  'calvin_engine',
  'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++20'
    ])

engine_includes = include_directories('core/include')

engine_sources = files([
  'core/src/math/Angle.cpp',
  'core/src/math/Coordinates.cpp',
  'core/src/math/Links.cpp',
  'core/src/math/Vectors.cpp',
  'core/src/utils/Print.cpp'
  ])

engine_lib = library(
  'calvin_engine',
  engine_sources,
  install : false,
  include_directories : engine_includes
  )

engine_lib_dep = declare_dependency(
  include_directories : engine_includes,
  link_with : engine_lib
  )

demo = executable(
  'jpl',
  'jpl/src/main.cpp',
  include_directories : engine_includes,
  link_with : engine_lib
  )

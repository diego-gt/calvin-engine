project(
  'calvin_engine',
  'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++20'
    ])

engine_includes = include_directories('include')

engine_sources = files([
  'src/math/Angle.cpp',
  'src/math/Coordinates.cpp',
  'src/math/Links.cpp',
  'src/math/Vectors.cpp',
  'src/utils/Print.cpp'
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

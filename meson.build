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
  'src/math/Vector2D.cpp',
  'src/math/Joint2D.cpp',
  'src/math/Link2D.cpp',
  'src/utils/Print.cpp'
  ])

# dependencies
imgui_proj = subproject('imgui')
imgui_dep = imgui_proj.get_variable('imgui_dep')
glfw3_dep = dependency('glfw3', version : '>=3.3')
vulkan_dep = dependency('vulkan', version : '>=1.2')

engine_lib = library(
  'calvin_engine',
  engine_sources,
  install : false,
  include_directories : engine_includes,
  dependencies : [ imgui_dep, glfw3_dep, vulkan_dep ]
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

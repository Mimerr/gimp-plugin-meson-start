project('plugin-name', 'c')

cc = meson.get_compiler('c')

libs = [
  cc.find_library('pthread'),
  cc.find_library('gimpui-2.0'),
  cc.find_library('gimpwidgets-2.0'),
  cc.find_library('gimpmodule-2.0'),
  cc.find_library('gimp-2.0'),
  cc.find_library('gimpmath-2.0'),
  cc.find_library('gimpconfig-2.0'),
  cc.find_library('gimpcolor-2.0'),
  cc.find_library('gimpbase-2.0'),
  cc.find_library('gegl-0.4'),
  cc.find_library('gegl-npd-0.4'),
  cc.find_library('m'),
  cc.find_library('gmodule-2.0'),
  cc.find_library('json-glib-1.0'),
  cc.find_library('babl-0.1'),
  cc.find_library('gtk-x11-2.0'),
  cc.find_library('gdk-x11-2.0'),
  cc.find_library('pangocairo-1.0'),
  cc.find_library('atk-1.0'),
  cc.find_library('cairo'),
  cc.find_library('gdk_pixbuf-2.0'),
  cc.find_library('gio-2.0'),
  cc.find_library('pangoft2-1.0'),
  cc.find_library('pango-1.0'),
  cc.find_library('gobject-2.0'),
  cc.find_library('glib-2.0'),
  cc.find_library('harfbuzz'),
  cc.find_library('fontconfig'),
  cc.find_library('freetype')
]

incs = include_directories([
  'inc',
  '/usr/include/gimp-2.0',
  '/usr/include/gegl-0.4',
  '/usr/include/gio-unix-2.0',
  '/usr/include/json-glib-1.0',
  '/usr/include/babl-0.1',
  '/usr/include/gtk-2.0',
  '/usr/lib/x86_64-linux-gnu/gtk-2.0/include',
  '/usr/include/pango-1.0',
  '/usr/include/atk-1.0',
  '/usr/include/gdk-pixbuf-2.0',
  '/usr/include/libmount',
  '/usr/include/blkid',
  '/usr/include/pango-1.0',
  '/usr/include/fribidi',
  '/usr/include/cairo',
  '/usr/include/pixman-1',
  '/usr/include/harfbuzz',
  '/usr/include/glib-2.0',
  '/usr/lib/x86_64-linux-gnu/glib-2.0/include',
  '/usr/include/uuid',
  '/usr/include/freetype2',
  '/usr/include/libpng16',
  '/usr/include/gimp-2.0'
])

srcs = [
  'src/main.c'
]

executable(
  'plugin-name',
  sources: srcs,
  dependencies: libs,
  include_directories: incs,
  link_args: '-Wl,--export-dynamic'
)

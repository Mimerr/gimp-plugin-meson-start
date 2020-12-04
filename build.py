""" Simple way to build, compile, and deploy. """
import os
import sys
import shutil

class colors:
  """ Colors for terminal output. """
  END = "\033[0m"
  GO = "\033[1;32m"
  TASK = "\033[1;94m"
  ALERT = "\033[1;31m"

def meson():
  """ Create the meson build setup. """
  print(colors.TASK + "Initiate Meson Build" + colors.END)
  os.system("meson build")

def ninja():
  """ Compile the meson build setup. """
  print(colors.TASK + "Initiate Ninja Build" + colors.END)
  os.system("ninja -C build")

def deploy():
  """ Deploy the plugin with gimptool. """
  print(colors.GO + "Deploy GIMP Plugin" + colors.END)
  os.system("gimptool-2.0 --install-bin build/plugin-name")

def compile_and_deploy():
  """ Compile and deploy in one action. """
  print(colors.TASK + "Compile and deploy.")
  ninja()
  deploy()

def clean():
  """ Remove the build setup. """
  print(colors.ALERT + "Removing Build Directory")
  shutil.rmtree("./build", ignore_errors=True)

print(colors.GO + "Start" + colors.END)

for arg in sys.argv:
  if (arg == sys.argv[0]):
    continue  # Skip the python script's name.
  if (arg == "clean"):
    clean()
  if (arg == "compiledeploy"):
    compile_and_deploy()
  if (arg == "ninja"):
    ninja()
  if (arg == "meson"):
    meson()
  if (arg == "deploy"):
    deploy()

if (len(sys.argv) == 1):
  compile_and_deploy()

print(colors.GO + "Done" + colors.END)

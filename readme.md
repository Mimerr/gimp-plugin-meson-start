# GIMP Plugin Starting Point

This is a simple starting point for creating a GIMP Plugin. It uses meson/ninja
as a build system and can accommodate multiple source files.

Currently this is only setup to work on Linux systems. Specifically created on
Kubuntu after installing libraries.

This may not be a complete list but I'm pretty sure these are definitely
needed.

```
sudo apt-get install libgimp2.0-dev meson
```

### Getting started

This isn't a tutorial on how to create a GIMP Plugin. But here are some links
that I have found to be helpful.

https://developer.gimp.org/writing-a-plug-in/1/index.html
https://developer.gimp.org/api/2.0/index.html

Ultimately this is a barely modified version of the Hello World by David Neary.

To get started with your plugin, go to main.c and change all the information
there to match your plans and you as the developer.

Then in the run function add your functionality.

It may be better to put your functionality in separate files, like
my-super-awesome-plugin.c and my-super-awesome-plugin.h files that you can then
reference from the main.c run function. This way you can add as much code from
wherever you want.

If you do decide to make your own files that way, you will need to add them to
the meson.build file in the srcs section. Headers in the inc folder do not need
added to the build file because the inc folder is already included.

Also in the meson.build file change plugin-name to your plugin's name.

### Building and deploying

If you are already familiar with the meson build system feel free to do what
you normally do. If not, it is a very simple system. For this specific setup
just run the `meson build` command to set thigns up and the `ninja -C build`
command to actually create your plugin.

To install your plugin for your GIMP, you'll either need to run the gimptool2.0
command for installing bin on your newly created executable from ninja, or
you can simply copy the created file to your GIMP folder.

Or you can use the python build file for convenience. You will need Python
set up on your system of course. But this makes it pretty easy to run the
needed development commands without having to remember it all.

Even if you don't want to run them through Python you can check the file to
see what the commands are and run them manually.

If you do use the python script though, change the plugin-name to match what
you change it to in meson.build.

So basically just run these commands as needed:

```
python build.py meson # To build the meson setup.
python build.py ninja # To compile the build.
python build.py deploy # To run the gimptool command and deploy the plugin.
python build.py # Will do the ninja build and deploy all in one!
```

### Future ideas that may affect this project

This is a pretty simple template to start a plugin so not a ton to do here.

If anyone would like to edit the build so it can be done on Mac or Windows also
that'd be useful, but it is not in my plans to do so.

However, on my long TODO list of things that will probably never actually get
done is to create a plugin that can manage other plugins. Specifically the idea
is to allow people to create a git repo with their plugin then have a
descriptive file of some sort in the root and then request to be added to the
registry so it shows up in the plugin manager. Which can then pull the plugin
from the git repo and deploy it to your local GIMP. So if this ever happens,
I'll be adding a descriptor example for that.

### License

I'm not really sure how licenses work in this case. I think the the tutorial I
followed to get the basic idea how to do this was using a non commercial
sharealike license of some kind. I'm not sure if this is really subject to that
since it was just a reference and this is pretty standard boilerplate code that
any plugin would need but I'm also not sure if GIMP in general requires such a
license on plugins.

In the end if you use this for your plugin, you should probably not try to
make it commercial or whatnot and be cool and try to share it! But I'm not
a lawyer so I have no clue what to tell you.

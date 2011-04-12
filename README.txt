Ignatus
=======

This is our game engine. It's written in C++, and it uses:
* SFML (http://sfml-dev.org/ )
* Boost (http://www.boost.org/ )

At all times, it is written with the goal in mind of being simple and
magical. For the most part, it has been grown out of need and experience, not
out of whims or nice-to-have's.

Ignatus is hosted on github at https://github.com/tylerc/Ignatus
Ignatus' documentation can be found at http://tylerc.github.com/Ignatus

Building the Engine
-------------------

There are two ways to build Ignatus. The first, and easiest way, is to simply
open up the codeblocks project file and compile it from there. But, if you
don't want to use codeblocks, you can compile it from the command line with
the following:

        for f in *.cpp GUI/*.cpp ; do gcc -c "$f" ; done && ar rcs libIgnatus.a *.o

Making a Game With Ignatus
--------------------------

As this is just the README, I won't go into too much depth. The starting
point for a game would look like this:

        #include <Ignatus/All.hpp>

        int main()
        {
            Engine e("My Awesome Game!", 640, 480);
            e.Looptastic();
            return 0;
        }

This will create a window 640 pixels in width, and 480 pixels high, with the
title "My Awesome Game!". It will then enter into the main game loop.

Now to compile it.

We don't distribute pre-built binary versions of Ignatus, so you'll have to
build it yourself first (see the section above). The easiest way to link
against Ignatus is to have the folder for your game, and Ignatus in the same
directory. Then, add "../Ignatus" to your linking directories, and link
against Ignatus and SFML (sfml-system, sfml-window, sfml-graphics, and
sfml-audio). Also, add ".." to your include directories.

Save the example as main.cpp, and run this command:

        gcc main.cpp -L../Ignatus -I.. -lIgnatus -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -o Game

And you'll have a working blank window! :)

For more, see the documentation at http://tylerc.github.com/Ignatus
Features
--------

* Fire and Forget object creation (they add themselves to the game, and clean
up after themselves when they die).
* Easy management of multiple game states.
* Support for background music and sound effects.
* Easy particle effects.
* It's simple to create an object with an animated image.
* You can create simple Polygons.
* Support for displaying Text.
* Collision detection, and the ability to disable it when you don't want the
overhead associated with it.

And much, much more! :)

License
-------

Copyright (c) 2010-2011 Tyler Church, Michael Jerrick

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

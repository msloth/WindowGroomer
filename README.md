WindowGroomer
=============

WindowGroomer arranges desktop application windows on a grid. It is an
open-source (GPL) clone of the now-defunct [dfgbt Window Manager][dfgbt].

[dfgbt]: http://www.youtube.com/watch?v=NM8OMcvTk9U "dfgbt Window Manager"

Binary releases
---------------

### v0.1.0

[Download](http://www.albertarmea.com/releases/WindowGroomer/WindowGroomer-win-0.1.0.zip)

* Proof of concept with basic window resizing and multiple monitor support.
* Requires Microsoft Windows XP, Vista, 7, or 8 (x86 and x86-64 only).
* Keyboard shortcut (Ctrl+Shift+F12) and grid size (4x3) cannot be changed.

Building from source
--------------------

### Microsoft Windows
On Windows, WindowGroomer uses [Qt 4.8.4][qt] for
[Microsoft Visual C++ 2010][msvc] and [libqxt 0.6.2][libqxt].

[qt]: http://qt-project.org/downloads
[libqxt]: https://bitbucket.org/libqxt/libqxt
[msvc]: http://www.microsoft.com/visualstudio/eng/downloads#d-2010-express

#### Setup
1. Install Microsoft Visual C++ 2010. Any edition, including Express, will
work.
2. Install Qt 4.8.x for VS 2010.
3. Compile and install Qxt:
    1. Download and extract libqxt 0.6.x to a directory.
    2. Open a Qt 4.8 Command Prompt and do the following:

            cd [extracted-libqxt]

            # Compile and install for release
            configure
            qmake
            nmake
            nmake install

            # Compile and install for debug
            configure -debug
            qmake
            nmake
            nmake install

#### Compiling
1. Clone WindowGroomer into a directory.
2. Open a Qt 4.8 Command Prompt and do the following:

        cd [cloned-source]
        qmake
        nmake

For release mode, replace `nmake` with `nmake release`. You may need to copy
some Qt and Qxt *.dll files from their install directories to the
WindowGroomer directory for it to run.

Copyright
---------

© 2012-2013 Albert Armea

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

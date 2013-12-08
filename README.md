Tutorial - Simple Verse Client
==============================

This repository includes files for tutorial of simple Verse client
implemented in C language. Complete tutorial could be found
at verse viki:

 * https://github.com/verse/verse/wiki/Tutorial-Simple-C-Verse-Client

Each step of tutorial has own tag (v0.1, v0.2, v0.3, v0.4, v0.5). You
can list all tags with:

    git tag -l

You can checkout each step of tutorial with e.g.:

    git checkout tags/v0.1

To compile source file you have open new terminal and type:

    mkdir ../build
    cd ../build
    cmake $OLDPWD
    make

To run *verse_client* you have to have running *verse_server*.

Enjoy!

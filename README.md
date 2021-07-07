# Archiver
In development

## How to install

### Linux
1. clone this repsitory _git clone https://github.com/Stalker7101/Archiver.git_
2. make dir for build files and go to it
3. run _cmake (path to dir with project Archiver)_
4. run _make_

### Windows
1. clone this repsitory _git clone https://github.com/Stalker7101/Archiver.git_
2. configure project with _cmake gui_ interface for your Visual Studio version
3. build project from Visual Studio in Release configuration

You will get archive.exe executive file in Release folder of VS project

**Note:** If you want send program and run it on another machine you should
change settings of the VS project:
_Configuration Properties --> C/C++ --> Code Generation, change the
"Runtime Library" field to "Multi-Threaded (/MT)"_


## How to use
When file is arcvive it has addition extention .darch or .sarch
When file is unarchiving it just delete addition extention from name of archive

Linux: run program - _./archiver_ from build directory
Windows: run _archiver.exe_
Follow intructions in console menu

1. choose type of archiver 1 - dynamic (Vitter), 0 - static (Haffman)
2. choose 1 - archive or 0 - unarchive file
3. enter name of file to archive / unarchive

## Implemented in this project
- archiver with Haffman static algorithm
- archiver with Vitter dynamic algorithm
- console menu
- colsole interface like in Linux utilities

## In development
- special labels which will allow to identify archive and it's type
- fixes of inner classes (StatTree, DynTree ...)
- library of encryption algorithms

# Archiver
In development

## How to install
1. clone this repsitory _git clone https://github.com/Stalker7101/Archiver.git_
2. make dir for build files and go to it
3. run cmake _../(path to dir with project Archiver)_
4. run _./make_

## How to use
When file is arcvive it has addition extention .darch or .sarch
When file is unarchiving it just delete addition extention from name of archive

Run program - _./archiver_ from build directory
Follow intructions in console menu

1. choose type of archiver 1 - dynamic (Vitter), 0 - static (Haffman)
2. choose 1 - archive or 0 - unarchive file
3. enter name of file to archive / unarchive

## Implemented in this project
- archiver with Haffman static algorithm
- archiver with Vitter dynamic algorithm
- console menu

## In development
- special labels which will allow to identify archive and it's type
- colsole interface like in Linux utilities
- fixes of inner classes (StatTree, DynTree ...)
- library of encryption algorithms

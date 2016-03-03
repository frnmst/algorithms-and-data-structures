# algorithms-and-data-structures
C functions related to "Algoritmi e strutture dati" 
course in UNIFE (University of Ferrara), years 2014-2016.

##What this repository is about

This repository is a collection of C functions you can freely use.

What you need is a compilant C compiler and preferibily `bash` to run the 
compile script like this:
```
$ cd src/<directory> && ./build.sh
```
An executable file called `<directory>.o` will be created in the 
`src/<directory>` directory.

If you have the program `indent` installed in your system, the files called by 
every `build.sh` will automatically be indented (and changed) with the options
specified by the `indentOptions` variable in `src/mainBuild.sh` if, and only if 
you add `-i` option after issuing `build.sh`, like this:
```
$ ./build.sh -i
```
Some exercises need `gnuplot` to be installed, otherwise no output is shown.
Specifically the build files behave similarly to `build.sh` 
and they are called `buildAndPlot.sh`.

Fell free to contribute to this repository.

##Covered arguments

Autogenerated with `$ tree src/`

```
src/
├── common
│   └── printArray
│       ├── build.sh
│       ├── printArray.c
│       └── printArray.h
├── graphs
│   ├── adt
│   │   ├── adt.c
│   │   ├── adt.h
│   │   ├── adt.o
│   │   ├── build.sh
│   │   ├── main.c
│   │   └── main.h
│   ├── btree
│   │   ├── btree.c
│   │   ├── btree.h
│   │   ├── btree.o
│   │   ├── build.sh
│   │   ├── main.c
│   │   └── main.h
│   └── mainBuild.sh -> ../mainBuild.sh
├── lists
│   ├── adt
│   │   ├── adt.c
│   │   ├── adt.h
│   │   └── build.sh
│   ├── doubleLinkedList
│   │   ├── build.sh
│   │   ├── doubleLinkedList.c
│   │   ├── doubleLinkedList.h
│   │   ├── doubleLinkedList.o
│   │   ├── main.c
│   │   └── main.h
│   ├── list
│   │   ├── build.sh
│   │   ├── liste.c
│   │   ├── liste.h
│   │   ├── list.o
│   │   ├── main.c
│   │   └── main.h
│   ├── mainBuild.sh -> ../mainBuild.sh
│   ├── queue
│   │   ├── build.sh
│   │   ├── main.c
│   │   ├── main.h
│   │   ├── queue.c
│   │   ├── queue.h
│   │   └── queue.o
│   └── stack
│       ├── build.sh
│       ├── main.c
│       ├── main.h
│       ├── stack.c
│       ├── stack.h
│       └── stack.o
├── mainBuild.sh
├── pointers
│   ├── pointersExamples
│   │   └── test.c
│   └── sizes.c
└── training
    ├── atoi
    │   ├── atoi.c
    │   ├── atoi.h
    │   ├── atoi.o
    │   ├── build.sh
    │   ├── main.c
    │   ├── main.h
    │   └── vectorAsList.o
    ├── belongs
    │   ├── belongs.c
    │   ├── belongs.h
    │   ├── belongs.o
    │   ├── build.sh
    │   ├── main.c
    │   └── main.h
    ├── greedyScheduler
    │   ├── build.sh
    │   ├── greedyScheduler.c
    │   ├── greedyScheduler.h
    │   ├── greedyScheduler.o
    │   ├── main.c
    │   └── main.h
    ├── heapSort
    │   ├── build.sh
    │   ├── heapSort.c
    │   ├── heapSort.h
    │   ├── heapSort.jpg
    │   ├── heapSort.o
    │   ├── main.c
    │   └── main.h
    ├── mainBuild.sh -> ../mainBuild.sh
    ├── printArray -> ../common/printArray
    ├── straightInsertion
    │   ├── build.sh
    │   ├── main.c
    │   ├── main.h
    │   ├── straightInsertion.c
    │   ├── straightInsertion.h
    │   └── straightInsertion.o
    └── vectorAsList
        ├── build.sh
        ├── main.c
        ├── main.h
        ├── vectorAsList.c
        ├── vectorAsList.h
        └── vectorAsList.o

21 directories, 86 files
```

##Function file structure

```
  License notice
  

  Include header(s)

  Brief description of what the (*) function does.

  Function prototype
    
  Function code
```

(*) Each file can contain more than one function.

##License

Every file in this repository is covered by the WTFPL. We decided not to use 
the GPL because all these are implemetations of well known algorithms, 
so the copyleft clause and others clauses are not necessary here.


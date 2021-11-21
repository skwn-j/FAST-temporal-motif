# FAST-temporal-motif
*Fast-temporal-motif* is an algorithm proposed to count sub-graphs(*3 types, star, pair and triangle*) in temporal graphs. This repositority provides source code of the algorithm, which may help researchers have a better understanding of the algorithm. Besides, people can directly compile the project to have a quick start to verify the correctness and efficiency of the algorithm.

## Compile
### Compile the project
1. download the project, the project looks like:
```bash
/FAST-temporal-motif
├── include
│   ├── global.h
│   ├── egeLoader.h
│   ├── starAndPairCount.h
│   ├── triangleCount.h
│   └── convertMartix.h
├── src
│   ├── global.cpp
│   ├── egeLoader.cpp
│   ├── starAndPairCount.cpp
│   ├── triangleCount.cpp
│   ├── convertMartix.cpp
│   └── main.cpp
├── makefile
└── README.md
```

2. do "make* to compile the project, and get FAST_temporal_motif.exe
```bash
make
```

3. you can do *make clean* to remove FAST_temporal_motif.exe and all .o files
```bash
make clean
```

### Compile settings
you can modify *makefile* to change compile settings. The default settings:
1. compile the project without using OPENMP. You can set the *OMPFLAG* to true to compile the project into a openmp program if you want it work with multiple threads
2. use -O3 Optimize

## Command line arguments
```bash
FAST_temporal_motif -input -output -f -t -d -w
```
| Argument | Type      | Meaning                                                           | Required                   |
|----------- |----------|--------------------------------------------------|----------------------|
| -input       | string     | the path of input data file                                 | Yes                            |
| -output    | string      | the path of output file                                      | Yes                            |
| -f              | int *1/0* | use/not use OPENMP                                       | No default 0             |
| -t              | int           | the number of thread (when using OPENMP) |  No default 1              |
| -d             | int          | the thrd (when using OPENMP)                        | No default INT_MAX |
| -w            | int           | time span                                                          | No default INT_MAX |

for example, if you want to count all temporal-motifs within the time span of 600 in *input.txt*, with 8 threads, thrd=200000 and output results to *output.txt*, you can run the program as follows:
```bash
FAST_temporal_motif -input input.txt -output output.txt -f 1 -t 8 -d 200000 -w 600
```
The order of the arguments can be changed

## Data file
### Input data file
n rows, each row represents a directed edge

3 data in each row, representing node 1, node 2, and timestamp

use space as separator
### Output file
a 6*6 martix


# $$\texttt{\large\color{Dandelion}Nanner}$$
Executes commands by fuzzy finding their alias

## Dependencies
The following dependencies are needed to use nanner, currently only supports linux-based systems.
```
sed
```

## Usage

To use run `nnr [alias]` eg.
```bash
nnr cmatrix
# or even
nnr mat
nnr rx
```
Currently, the aliases and commands are stored in `data.txt`, to modify or add aliases it needs to be modified manually.




## Building
`nnr` requires a `Cmake` to be installed.
Then simply build by running
```bash
cmake
make
make install
```
## To DO
Features being worked on or are in need of implementation

```
nnr set alias command
nnr get fuz
nnr list fuz
nnr remove
nnr help

switches:
 -d, --dry
     fuzzy find cmd without execution
 -f, --force
     do not prompt
 -i, --interactive
     prompt before executing cmd
 -q, --quiet
     recklessly execute matched cmd
 -p, --perfect
     don't fuzzy match
```

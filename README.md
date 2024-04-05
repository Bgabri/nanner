
# <p style="text-align:center; color:#fabd2f">Nanner</p>
Executes commands by fuzzy finding their alias
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

Build using `make`, an output file will be created in `bin`.

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



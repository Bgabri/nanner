
#define SET "set"
#define GET "get"
#define LIST "list"
#define REMOVE "remove"
#define RENAME "rename"
#define HELP "help"


int parseInput(char *argv[]);
int parseSet(char *argv[]);
int parseGet(char *argv[]);
int parseList(char *argv[]);
int parseRemove(char *argv[]);
int parseHelp(char *argv[]);
int parseSwitch(char *argv[]);
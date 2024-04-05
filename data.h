#define DATA_PATH "data.txt"

void addEntry(char *alias, char *command);
void setEntry(char *alias, char *command);
void listEntries();
char* getFuzzyEntry(char *alias);
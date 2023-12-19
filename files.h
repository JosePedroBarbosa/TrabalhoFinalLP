#ifndef FILES_H
#define FILES_H

#define FILENAME "companies.bin"
#define LOG_FILE "logs.txt"
#define MAX_COMPANIES 50

void logMsg(char *msg, char *filename);
void write();
void read();

#endif /* FILES_H */
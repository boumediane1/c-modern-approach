#ifndef READ_LINE_H
#define READ_LINE_H

/*
 * Skips leading white-space characters, then
 * read the remainder of the input line and
 * stores it in str. Truncates the line if its
 * length exceeds n. Returns the number of
 * characters stored.*/
int read_line(char str[], int n);

#endif
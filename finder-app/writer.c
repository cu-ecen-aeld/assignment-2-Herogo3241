#include <stdio.h>
#include <stdlib.h>
#include <sys/syslog.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
  openlog("writer", LOG_PID, LOG_USER);

  if (argc < 3) {
    syslog(LOG_ERR, "Needs 2 arguments \n Arg1: File Name \n Arg2: String");
    closelog();
    return 1;
  }

  const char *filename = argv[1];
  const char *string = argv[2];

  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    syslog(LOG_ERR, "Error opening %s", filename);
    fclose(fp);
    closelog();
    return 1;
  }

  syslog(LOG_INFO, "Writing %s to file %s", string, filename);
  fprintf(fp, "%s", string);
  fclose(fp);

  closelog();
  return 0;
}

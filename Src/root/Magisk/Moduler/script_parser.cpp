//! Script parser.
#include <filesystem>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
  std::string logfile;
  int c;
  int loged = 0;
  while(1) {
     static struct option long_options[] =
        {
          {"verbose", no_argument,       &verbose_flag, 1},
          {"brief",   no_argument,       &verbose_flag, 0},
          {"silent", no_argument, 0, 's'},
          {"log", optional_argument, 0, 18}
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "abc:d:f:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c) {
        case 18:
          if (loged !=0) {
            fprintf(stdout, "[Startup -> Log]: You may not specify 2 log files at one run.");
            _exit(1);
          };
          logfile = optarg == NULL ? './.loged' : optarg;
          loged = 1;
          break;
        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }
  
};

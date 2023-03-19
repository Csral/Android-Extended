//! Script parser.
#include <filesystem>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fstream>

int main(int argc, char *argv[]) {
  static int verbose_flag;
  std::string logfile;
  int silent = 0;
  int c;
  int loged = 0;
  while(1) {
     static struct option long_options[] =
        {
          {"verbose", no_argument, &verbose_flag, 1},
          {"brief",   no_argument, &verbose_flag, 0},
          {"silent", no_argument, 0, 's'},
          {"log", optional_argument, 0, 18},
          {"config", required_argument, 0, 'c'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "sc:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c) {
        case 18:
        {
          if (loged !=0) {
            fprintf(stdout, "[Startup -> Log]: You may not specify 2 log files at one run.");
            _exit(1);
          };
          optarg == NULL ? logfile = "./.loged" : logfile = optarg;
          loged = 1;
          break;
        }
        case 's':
          {
            silent = 1;
            break;
          }
        case 'c':
        {
          if (!std::filesystem::exists(optarg)) {
            fprintf(stderr, "[Startup -> Config]: Configuration file (specified: %s) not found.", optarg);
            _exit(1);
          };
          
          /* Start appending the configurations specified into the configuration variables for later use */
          std::string lines;
          std::ifstream conf;
          conf.open(optarg);
          
          while(getline(conf, lines)) {
            /* Start Parsing */
            
          };
        } 
        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }
  
};

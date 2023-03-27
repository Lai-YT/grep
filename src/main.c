/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main file of the project
 *
 *        Created:  03/24/2016 19:40:56
 *
 *         Author:  Gustavo Pantuza
 *   Organization:  Software Community
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "colors.h"
#include "regexp.h"

int main(int argc, char* argv[]) {
  /* Read command line options */
  options_t options;
  options_parser(argc, argv, &options);

#ifdef DEBUG
  fprintf(stdout, CYAN "Command line options:\n" NO_COLOR);
  fprintf(stdout, CYAN "  help: %d\n" NO_COLOR, options.help);
  fprintf(stdout, CYAN "  version: %d\n" NO_COLOR, options.version);
  fprintf(stdout, CYAN "  regexp: %s\n" NO_COLOR, options.regexp);
  fprintf(stdout, CYAN "  string: %s\n" NO_COLOR, options.string);
#endif

  if (regexp(options.regexp, options.string)) {
#ifdef DEBUG
    fprintf(stdout, YELLOW "The regexp matches the string.\n" NO_COLOR);
#endif
    return 0;
  }
#ifdef DEBUG
  fprintf(stdout, RED "The regexp doesn't match the string.\n" NO_COLOR);
#endif
  return 1;
}

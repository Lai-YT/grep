#ifndef REGEXP_H
#define REGEXP_H

#include <stdlib.h>

/*
 * Implements the McNaughton-Yamada-Thompson algorithm with extra supports on +
 * (one or more) and ? (zero or one) operators.
 */

enum {
  EPSILON = 128,
  SPLIT = 129,
  ACCEPT = 130,
};

typedef struct State {
  int label;
  struct State** outs;
} State;

/// @brief A labeled state have 1 labeled transition, an epsilon state (label ==
/// EPSILON) has 1 epsilon transition, a spliting state (label == SPLIT) has 2
/// epsilon transitions, an accepting state (label == ACCEPT) has 1 reserved
/// transition (see note).
/// @note The accepting state may later become part of an NFA and turns into an
/// epsilon state. outs is ignored under this condition since the space is only
/// reserved.
State* create_state(const int label, State** outs);

typedef struct Nfa {
  State* start;
  State* accept;
} Nfa;

Nfa* create_nfa(State* start, State* accept);

Nfa* post2nfa(const char* post);

#endif /* end of include guard: REGEXP_H */

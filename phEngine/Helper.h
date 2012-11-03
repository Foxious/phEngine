#ifndef HELPER_H
#define HELPER_H

#include <assert.h>

#define RELEASE(x) if (x) x->Release(); x = 0;

#endif

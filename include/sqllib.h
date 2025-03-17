#ifndef __SQLLIB_H__
#define __SQLLIB_H__

#include "sqlite3.h"

auto sql_init(const char *filename) -> sqlite3 *;

#endif

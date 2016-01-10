#pragma once

typedef long long Int64;
typedef int Int32;
typedef short Int16;
typedef char Int8;
typedef unsigned long long Uint64;
typedef unsigned int Uint32;
typedef unsigned short Uint16;
typedef unsigned char Uint8;

static_assert( sizeof( long long ) == 8, "Long long must be 64bit" );
static_assert( sizeof( int ) == 4, "Int must be 32bit" );
static_assert( sizeof( short ) == 2, "Short must be 16bit" );
static_assert( sizeof( char ) == 1, "Char must be 8bit" );

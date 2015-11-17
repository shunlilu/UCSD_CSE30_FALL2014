#ifndef PA3_H
#define PA3_H



/* TODO #define flag bitmasks and constants for min/max/default bases */


/* Mode bits masks */
#define H_FLAG 0x01   // Help mode
#define E_FLAG 0x02   // Print english mode
#define B_FLAG 0x04   // Print Binary mode
#define I_FLAG 0x08   // Input mode
#define O_FLAG 0x10   // Output mode
#define F_FLAG 0x20   // Read file mode

#define MIN_BASE 2
#define MAX_BASE 36
#define DEF_BASE  10

#define BUF_MAX_SIZE 1024


#define BASE_MASK(ob) (((long long) 0x1) << (ob))

struct argsInfo {
  unsigned char mode;
  unsigned int inputBase;
  unsigned long long outputBases;
  char* inFileStr;
};

void printEnglish( long num );
void printIntBinary( long num );
void printFPBinary( float num );
void printBase( long num, int base );
long strToLong( const char* str, const int base );
int checkRange( long value, long minRange, long maxRange );
void processIntToken( char* inStr, struct argsInfo info );
void processFPToken( char* inStr, struct argsInfo info );
struct argsInfo setFlags( int argc, char* argv[] );
int getRealBase( long long outputBases);

int ptrError;
#endif /* PA3_H */

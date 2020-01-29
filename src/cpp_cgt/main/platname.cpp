
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
const char * g_platname = TOSTRING(PLAT);
// this is global variable used in other modules
// without header declaration


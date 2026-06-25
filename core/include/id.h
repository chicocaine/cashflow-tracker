#include <stdint.h>

typedef struct {
  uint8_t bytes[16];
} uuid_t;

typedef uint8_t stdid_t;

typedef enum {
  ID_TYPE_UNKNOWN = 0,
  ID_TYPE_UUID = 1,
  ID_TYPE_STID = 2
} id_type_t;

typedef struct {
  id_type_t type;
  union {
    uuid_t uuid;
    stdid_t stdid;
  } value;
} genid_t;
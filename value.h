#ifndef byte_value_h
#define byte_value_h

#include "common.h"

// Base Class
typedef struct Obj       Obj;

typedef struct ObjString ObjString;

typedef enum
{
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
    VAL_OBJ
} ValueType;

typedef struct
{
    ValueType type;
    union
    {
        bool   boolean;
        double number;
        Obj*   obj;
    } as;
} Value;

bool valuesEqual( Value a, Value b );

// The _VAL macros lift a C value into the heavens.
// The AS_ macros bring it back down.
#define IS_BOOL( value )   ( ( value ).type == VAL_BOOL )
#define IS_NIL( value )    ( ( value ).type == VAL_NIL )
#define IS_NUMBER( value ) ( ( value ).type == VAL_NUMBER )
#define IS_OBJ( value )    ( ( value ).type == VAL_OBJ )

// From byteLang value to C value
#define AS_OBJ( value )    ( ( value ).as.obj )
#define AS_BOOL( value )   ( ( value ).as.boolean )
#define AS_NUMBER( value ) ( ( value ).as.number )

// From C value to byteLang value
#define BOOL_VAL( value )   ( ( Value ){ VAL_BOOL, { .boolean = value } } )
#define NIL_VAL             ( ( Value ){ VAL_NIL, { .number = 0 } } )
#define NUMBER_VAL( value ) ( ( Value ){ VAL_NUMBER, { .number = value } } )
#define OBJ_VAL( object )   ( ( Value ){ VAL_OBJ, { .obj = ( Obj* ) object } } )

typedef struct
{
    int    capacity;
    int    count;
    Value* values;
} ValueArray;

void initValueArray( ValueArray* array );
void writeValueArray( ValueArray* array, Value value );
void freeValueArray( ValueArray* array );

void printValue( Value value );

#endif

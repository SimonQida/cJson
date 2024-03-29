#ifndef JSON_H
#define JSON_H
#include<stdbool.h>
#include<stdio.h>

typedef struct Json Json;
typedef struct array Array;
typedef union valueType ValueType;
typedef struct arrayNode ArrayNode;
typedef struct JsonNode JsonNode;

struct array{
    int len;
    ArrayNode *array_address;
};

union valueType{
    int i;
    bool b;
    float f;
    double d;
    const char *string;
    Json *Json_child;
    Array *array_child;
};

struct arrayNode{
    int index;
    int type;
    ValueType value;
    ArrayNode *next;
};

struct JsonNode{
    int type;
    const char *key;
    ValueType value;
    JsonNode *next;
};

struct Json{
    JsonNode *head;
};

// day2 
Json *json_new_obj();

Array *json_new_arr();

bool json_add_obj(Json*, JsonNode*);

//bool json_add_arr(Array*, ValueType);


JsonNode *json_create_bool(const char* ,const char*);

JsonNode *json_create_int(const char* ,int);

JsonNode *json_create_str(const char* ,const char *);

JsonNode *json_create_arr(const char* ,Array*);

JsonNode *json_create_json(const char* ,Json*);

ArrayNode *arr_create_int( int);

ArrayNode *arr_create_bool(const char*);

ArrayNode *arr_create_str(const char*);

ArrayNode *arr_create_json(Json*);

ArrayNode *arr_create_arr(Array*);

bool arr_add_obj(Array *,ArrayNode*);


//day 3 
//get part
void print_json(const Json* json,FILE*);

int json_get_int(Json* ,const char* );

int json_get_bool(Json* , const char*);

const char* json_get_str(Json* ,const char *);

Json* json_get_arr_json(Json* ,const char* ,int);

Json* json_get_json(Json* ,const char* );

#endif

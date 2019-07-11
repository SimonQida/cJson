#ifndef JSON_H
#define JSON_H
#include<stdbool.h>


typedef struct Json Json;
typedef struct arrayNode arrayNode;
typedef struct array{
    arrayNode* arrayaddress;
    int len;
}array;

typedef struct JsonNode JsonNode;

typedef union nodevalue{
    int i;
    float f;
    double d;
    bool b;
    char* string;
    Json* Jsonchild;
    array arraychild;
}nodevalue;

typedef struct arrayNode{
    int index;
    nodevalue value;
    arrayNode* next;
} arrayNode;


typedef struct JsonNode{
    char* key;
    nodevalue value;
    JsonNode * next;
}JsonNode;

struct Json{
    JsonNode * head;
    //more attribute to add...
};

#endif

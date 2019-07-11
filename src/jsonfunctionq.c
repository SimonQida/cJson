#define NULL (void*)0
#include "json.h"
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>

//JsonNode* newNode = (JsonNode* )malloc(sizeof(JsonNode));
//
Json* json_new_obj(){
    Json * newJ = (Json*)malloc(sizeof(Json));
    newJ->head = NULL;
    return newJ;
}

Array *json_new_arr(){
    Array * newA = (Array*)malloc(sizeof(Array));
    newA->len = 0;
    newA->array_address = NULL;
    return newA;
}

//1 -> json_add_obj succeed
bool json_add_obj(Json* Jsonlink, JsonNode* JNode){
    //check if the key exist
    const char* key = JNode->key;
    if(json_check_key(Jsonlink,key)){
        //succeed
        // __
        //|__|<-?
        //head
        //  ||
        //  \/
        // __    __JNode
        //|__|<-|__|
        //      head
        JNode->next = Jsonlink->head;
        Jsonlink->head = JNode;
        return 1;
    }
    else{
        return 0;
    }
    //link JNode to the Jsonlink
}

bool json_check_key(Json* Jsonlink,const char* key){
//return 1 if key not exist , ok to add
    JsonNode *head = json_search_node(Jsonlink,key);
    if(head == NULL){
        //printf("ok to add");
        return 1;
    }
    else {
        //printf("bad to add");
        return 0;
    }
}

JsonNode* json_search_node(Json* Jsonlink ,const char* key){
    JsonNode *head = Jsonlink->head;
    while(head != NULL &&strcmp(head->key,key)){
        head = head->next;
    }
    return head;
}

ArrayNode* arr_search_node(Array *arraylink ,int index){
    //if index out of arr-len return NULL
    ArrayNode* head = arraylink->array_address;
    if(head->index < index){
        printf("index out of range\n");
        return NULL;
    }
    while(head->index != index){
        head = head->next;
    }
    return head;
}

bool arr_add_obj(Array *arraylink,ArrayNode*aNode){
        //succeed
        // __
        //|1_|<-?
        //head
        //  ||
        //  \/
        // __    __JNode
        //|1_|<-|2_|
        //      head
    //Array  :  len
    //ArrayNode : index
    //Array's head <- ArrayNode
    arraylink->len +=1;
    ArrayNode *head = arraylink->array_address;
    aNode->next = head;
    if(!head){
        aNode->index = 0;
    }
    else aNode->index = head->index+1;
    arraylink->array_address = aNode;
    return 1;
}


//get a value -- don't need to manage space and pointer,if key not exist ,give message
int json_get_int(Json* Jsonlink,const char* key){
    JsonNode * node = json_search_node(Jsonlink,key);
    if(!node){
        //key not in Json
        printf("key %s not in current json %d\n",key,node);
        return INT_MAX;
    }
    return node->value.i;
}

int json_get_bool(Json* Jsonlink, const char* key){
    JsonNode * node = json_search_node(Jsonlink,key);
    if(!node){
        //key not in Json
        printf("key %s not in current json %d\n",key,node);
        return -1;
    }
    return node->value.b;

}

const char* json_get_str(Json* Jsonlink,const char *key){
    JsonNode * node = json_search_node(Jsonlink,key);
    if(!node){
        //key not in Json
        printf("key %s not in current json %d\n",key,node);
        return NULL;
    }
    return node->value.string;

}

Json* json_get_arr_json(Json* Jsonlink,const char* key,int index){
//just demo a _get_json function from json
    JsonNode * node = json_search_node(Jsonlink,key);
    if(!node){
        //key not in Json
        printf("key %s not in current json %d\n",key,node);
        return NULL;
    }
    return arr_search_node(node->value.array_child,index)->value.Json_child;
    
}

Json* json_get_json(Json* Jsonlink,const char* key){
    JsonNode * node = json_search_node(Jsonlink,key);
    if(!node){
        //key not in Json
        printf("key %s not in current json %d\n",key,node);
        return NULL;
    }
    return node->value.Json_child;
}


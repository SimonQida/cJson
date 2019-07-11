#include<stdio.h>
#include "json.h"
#include<stdlib.h>
#include<string.h>

void print(Json* Jsonlink){
    JsonNode * head = Jsonlink->head;
    while(head){
        printf("%s %d \n",head->key,head->value.i);
        head = head->next;
    }
}

void print_(Array* arraylink){
    ArrayNode * head = arraylink->array_address;
    while(head){
        printf("%d %d \n",head->index,head->value.i);
        head = head->next;
    }
}

int main(){
    Json* jsonH = json_new_obj();
    Json* jsonB = json_new_obj();
    Array* arrayH = json_new_arr();
    //printf("%d",json_create_int("int1",10)->value.i);
    json_add_obj(jsonH,json_create_int("int101",100));
    json_add_obj(jsonH,json_create_int("int2124",200));
    json_add_obj(jsonH,json_create_bool("bool1","true"));
    json_add_obj(jsonH,json_create_str("str1","json_str"));
    //json_add_obj(jsonH,json_create_arr());
    json_add_obj(jsonB,json_create_json("json1",jsonH));
    print(jsonH);
    
    arr_add_obj(arrayH,arr_create_int(100));
    arr_add_obj(arrayH,arr_create_bool("false"));
    arr_add_obj(arrayH,arr_create_str("yuxiang"));
    print_(arrayH);
}

#define NULL (void*)0
#include "json.h"
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

int a[10] = {10,10,10,10,10,10,10,10,10,10};
int aindex = 0;
FILE pFile;
FILE* pFile = fopen("fprintyml","w");
void printprefix(FILE* pFile){
    int ahead = -1;
    /*
    for(int i =0 ;i<aindex;++i){
        fprintf(pFile,"%d",a[i]);
    }
    */
    for(int i =0 ;i<aindex;++i){
        if(i != 0)
            //00 or 11 print space 
            if(a[i] == ahead){
                fprintf(pFile," ");
            }
            else if(a[i] - ahead == 1&& a[i+1] == 10)
                fprintf(pFile,"-");
            else if(a[i] - ahead == 1&& a[i+1] == a[i-1])
                fprintf(pFile,"-");
            else if(ahead - a[i] == 1)
                a[i] = 1;
        ahead =a[i];
    }
}

JsonNode *json_create_bool(const char *key, const char *str)
{
    JsonNode *jsonNode = (JsonNode *)calloc(1, sizeof(JsonNode));
    if(!jsonNode)
        return NULL;
    jsonNode->key = key;
    jsonNode->type = 1;
    if(!strcmp(str, "true"))
    {
        jsonNode->value.b = 1;
        jsonNode->next = NULL;
        return jsonNode;
    }
    else if(!strcmp(str, "false"))
    {
        jsonNode->value.b = 0;
        jsonNode->next = NULL;
        return jsonNode;
    }
    else
        return NULL;
}

JsonNode *json_create_int(const char *key, int i)
{
    JsonNode *jsonNode = (JsonNode *)calloc(1, sizeof(JsonNode));
    if(!jsonNode)
        return NULL;
    jsonNode->key = key;
    jsonNode->value.i = i;
    jsonNode->next = NULL;
    jsonNode->type = 0;
    return jsonNode;
}

JsonNode *json_create_str(const char *key, const char *str)
{
    JsonNode *jsonNode = (JsonNode *)calloc(1, sizeof(JsonNode));
    if(!jsonNode)
        return NULL;
    jsonNode->key = key;
    jsonNode->value.string = str;
    jsonNode->next = NULL;
    jsonNode->type = 4;
    return jsonNode;
}

JsonNode* json_create_json(const char* key, Json* json)
{
	JsonNode* jsonNode = (JsonNode*)calloc(1, sizeof(JsonNode));
	if (!jsonNode)
		return NULL;
	jsonNode->key = key;
	jsonNode->value.Json_child = json;
	jsonNode->next = NULL;
    jsonNode->type = 5;
	return jsonNode;
}

JsonNode* json_create_arr(const char* key, Array* arr)
{
	JsonNode* jsonNode = (JsonNode*)calloc(1, sizeof(JsonNode));
	if (!jsonNode)
		return NULL;
	jsonNode->key = key;
	jsonNode->value.array_child = arr;
	jsonNode->next = NULL;
    jsonNode->type = 6;
	return jsonNode;
}

ArrayNode* arr_create_int(int i)
{
	ArrayNode* arrNode = (ArrayNode*)calloc(1, sizeof(ArrayNode));
	if (!arrNode)
		return NULL;
	arrNode->index = 0;
	arrNode->value.i = i;
	arrNode->next = NULL;
    arrNode->type = 0;
	return arrNode;
}

ArrayNode* arr_create_bool(const char* bstr)
{
	ArrayNode* arrNode = (ArrayNode*)calloc(1, sizeof(ArrayNode));
	if (!arrNode)
		return NULL;
	arrNode->index = 0;
    arrNode->next = NULL;
    arrNode->type = 1;
    if(!strcmp(bstr, "true"))
    {
        arrNode->value.b = 1;
    }
    else if(!strcmp(bstr, "false"))
    {
        arrNode->value.b = 0;
    }
    else
        return NULL;
	return arrNode;
}

ArrayNode* arr_create_str(const char* str)
{
	ArrayNode* arrNode = (ArrayNode*)calloc(1, sizeof(ArrayNode));
	if (!arrNode)
		return NULL;
	arrNode->index = 0;
	arrNode->value.string = str;
	arrNode->next = NULL;
    arrNode->type = 4;
	return arrNode;
}

ArrayNode* arr_create_json(Json* json)
{
	ArrayNode* arrNode = (ArrayNode*)calloc(1, sizeof(ArrayNode));
	if (!arrNode)
		return NULL;
	arrNode->index = 0;
	arrNode->value.Json_child = json;
    arrNode->type = 5;
	arrNode->next = NULL;
	return arrNode;
}

ArrayNode* arr_create_arr(Array* arr)
{
	ArrayNode* arrNode = (ArrayNode*)calloc(1, sizeof(ArrayNode));
	if (!arrNode)
		return NULL;
	arrNode->index = 0;
	arrNode->value.array_child = arr;
	arrNode->next = NULL;
    arrNode->type = 6;
	return arrNode;
}

void print_arrNode(ArrayNode* arrNode,FILE* pFile)
{
	if (arrNode == NULL)
		return;
	print_arrNode(arrNode->next);
	switch (arrNode->type)
	{
	case 0:
        printprefix();
		fprintf(pFile," %d\n", arrNode->value.i);
		break;
	case 1:
        printprefix();
		fprintf(pFile," %d\n", arrNode->value.b);
		break;
	case 2:
        printprefix();
		fprintf(pFile," %f\n", arrNode->value.f);
		break;
	case 3:
        printprefix();
		fprintf(pFile," %lf\n", arrNode->value.d);
		break;
	case 4:
        printprefix();
		fprintf(pFile," %s\n", arrNode->value.string);
		break;
	case 5:
		print_json(arrNode->value.Json_child);
		break;
	case 6:
		print_arr(arrNode->value.array_child);
		break;
	default:
		break;
	}
}

void print_arr(const Array* arr,FILE* pFile)
{
    a[aindex] = 1;
    aindex +=1;
	ArrayNode* arrHead = arr->array_address;
	if (arrHead != NULL)
	{
		print_arrNode(arrHead);
	}
    a[aindex] =10;
    aindex -=1;
}

void print_jsonNode(JsonNode* node,FILE* pFile)
{
	if (node == NULL)
		return;
	print_jsonNode(node->next);
	switch (node->type)
	{
	case 0:
        printprefix();
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile," %d\n", node->value.i);
		break;
	case 1:
        printprefix();
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile," %d\n", node->value.b);
		break;
	case 2:
        printprefix();
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile," %f\n", node->value.f);
		break;
	case 3:
        printprefix();
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile," %lf\n", node->value.d);
		break;
	case 4:
        printprefix();
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile," %s\n", node->value.string);
		break;
	case 5:
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile,"\n");
		print_json(node->value.Json_child);
		break;
	case 6:
        printprefix();
	fprintf(pFile,"%s:", node->key);
		fprintf(pFile,"\n");
		print_arr(node->value.array_child);
		break;
	default:
		break;
	}
}

void print_json(const Json* json,FILE* pFile)
{

    a[aindex] = 0;
    aindex +=1;

	JsonNode* head = json->head;
	if(head != NULL)
		print_jsonNode(head);

    a[aindex] = 10;
    aindex -=1;

}



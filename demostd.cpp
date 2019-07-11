#include<iostream>

using namespace std;

class Json{
    
    union {
        int i;
        float f;
        double d;
        bool b;
        char
    };
    Json* next;
};

Json* cJSON_CreateObj(){

}

int main(){
    Json * jsonroot = cJSON_CreateObj();
    Json * jsonitem1 = cJSON_CreateObj();
    Json * jsonitem2 = cJSON_CreateObj();

    cJSON_AddItemToObj(jsonroot,"int1",cJSON_CreateNumber(10));
    cJSON_AddItemToObj(jsonroot,"string1",cJSON_CreateString("string10"));
    cJSON_AddItemToObj(jsonroot,"json1",jsonitem1);
    cJSON_AddItemToObj(jsonitem1,"json2",jsonitem2);
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cJSON_AddItemToObj(jsonroot,"jsonarray",cJSON_CreateArray(a);

    cout<<cJSON_Print(jsonroot)<<endl;
}

#include<json.h>

using std::cout;
using std::endl;

// param : Json pointer, key string,  value's type, value's value
Json* Json_new(const Json*,const char * key,enum type,union value);
Json* Json_set(const Json*,const char * key,enum type,union value);

Json* Json_del(const Json*,const char * key);
Json* Json_get(const Json*,const char * key);
// delete a link of Json , and *free*
Json* Json_delall(const Json*);

int main(){
    Json * head = Json_new(NULL,'key1',int,10);
    head = Json_new(head,'key1',int,10);
    head = Json_set(head,
}

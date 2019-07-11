#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int main(){
    int int_bool =0;
    bool b = 1;
    b = int_bool;
    FILE * pFile = fopen("fprintftest","w");

    fprintf(pFile,"%ld\n",sizeof(b));
    fprintf(pFile,"%d",b);
    //printf("%ld",sizeof(int));
    if(b == true)
        printf("%d",b);
    else printf("error in asfg");
    printf("%d",INT_MAX);

}


/*
main_(){
    Json * json = json_new_obj();
    int x = json_get_int(json,"keyint");
    bool b =json_get_bool(json,"keybool");
    const char* b =json_get_str(json,"keystr");
    // is it necessary to get array
    // json_get_arr(json,"keyarr")
    // get arr's json directly
    Json *arrsubJson = json_get_arr_json(json,"keyarr_sub_json",index(0,1,2,...));
    Json * subJson = json_get_json(json,"keyjson");
}
*/

#include<stdio.h>
#include "json.h"
#include<stdlib.h>

int main(){
	Json* root = json_new_obj();
	Json* basic = json_new_obj();
	Json* advance = json_new_obj();
	Json* dns = json_new_obj();
	Json* huanan = json_new_obj();
	Json* huabei = json_new_obj();

	json_add_obj(root, json_create_json("basic", basic));
	json_add_obj(root, json_create_json("advance", advance));

	json_add_obj(basic, json_create_bool("enable", "true"));
	json_add_obj(basic, json_create_str("ip", "200.200.3.61"));
	json_add_obj(basic, json_create_int("port", 389));
	json_add_obj(basic, json_create_int("timeout", 10));
	json_add_obj(basic, json_create_str("basedn", "aaa"));
	json_add_obj(basic, json_create_int("fd", -1));
	json_add_obj(basic, json_create_str("maxcnt", "10000000000000000000000000000000000033333333333"));
	Array* dns_arr = json_new_arr();
	arr_add_obj(dns_arr, arr_create_str("200.200.0.1"));
	arr_add_obj(dns_arr, arr_create_str("200.0.0.254"));
	json_add_obj(basic, json_create_arr("dns", dns_arr));

	Array* j_arr = json_new_arr();
	json_add_obj(huanan, json_create_str("name", "huanan"));
	json_add_obj(huanan, json_create_str("ip", "200.200.0.1"));
	json_add_obj(huabei, json_create_str("name", "huabei"));
	json_add_obj(huabei, json_create_str("ip", "200.0.0.254"));
	arr_add_obj(j_arr, arr_create_json(huanan));
	arr_add_obj(j_arr, arr_create_json(huabei));
	json_add_obj(advance, json_create_arr("dns", j_arr));
	Array* port_arr = json_new_arr();
	arr_add_obj(port_arr, arr_create_int(130));
	arr_add_obj(port_arr, arr_create_int(131));
	arr_add_obj(port_arr, arr_create_int(132));
	json_add_obj(advance, json_create_arr("portpool", port_arr));
	json_add_obj(advance, json_create_str("url", "http://200.200.0.4/main"));
	json_add_obj(advance, json_create_str("path", "/etc/sinfors"));
	json_add_obj(advance, json_create_str("value", "3.14"));

	print_json(root);

    return 0;
}

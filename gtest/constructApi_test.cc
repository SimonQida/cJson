#include "gtest/gtest.h"
#include "../src/json.h"
#include<limits.h>
#include<stdlib.h>


TEST(json_new_objTest, Normal) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  //Json* jsonH = json_new_obj();
  EXPECT_EQ(NULL, json_new_obj()->head);
  //EXPECT_EQ(11, c1.getx(10));

}

TEST(json_new_arrTest, Normal){
  EXPECT_EQ(NULL, json_new_arr()->array_address);

}

TEST(json_add_objTest,Normal){
    Json* root = json_new_obj();
	Json* basic = json_new_obj();
	json_add_obj(root, json_create_json("basic", basic));
	json_add_obj(basic, json_create_bool("enable", "true"));
	json_add_obj(basic, json_create_str("ip", "200.200.3.61"));
	json_add_obj(basic, json_create_int("port", 389));
	json_add_obj(basic, json_create_int("timeout", 10));
	json_add_obj(basic, json_create_str("basedn", "aaa"));
	json_add_obj(basic, json_create_int("fd", -1));
	json_add_obj(basic, json_create_str("maxcnt", "10000000000000000000000000000000000033333333333"));

    EXPECT_EQ(0,json_check_key(root,"basic"));
    //EXPECT_EQ(0,json_check_key(root,"advance"));
    EXPECT_EQ(1,json_check_key(root,"ip"));
    EXPECT_EQ(0,json_check_key(basic,"enable"));
    EXPECT_EQ(0,json_check_key(basic,"ip"));
    EXPECT_EQ(0,json_check_key(basic,"port"));
    EXPECT_EQ(0,json_check_key(basic,"timeout"));
    EXPECT_EQ(1,json_check_key(basic,"basic"));
    
	Array* dns_arr = json_new_arr();
	arr_add_obj(dns_arr, arr_create_str("200.200.0.1"));
	arr_add_obj(dns_arr, arr_create_str("200.0.0.254"));
	json_add_obj(basic, json_create_arr("dns", dns_arr));
}

TEST(json_check_keyTest,Normal){
    // find the key return 0
    // no such key return 1
    Json* basic = json_new_obj();
    EXPECT_EQ(1,json_check_key(basic,"enable"));
	json_add_obj(basic, json_create_bool("enable", "true"));
    EXPECT_EQ(0,json_check_key(basic,"enable"));
    EXPECT_EQ(1,json_check_key(basic,"enable123"));
    EXPECT_EQ(1,json_check_key(basic,"ip"));
	json_add_obj(basic, json_create_str("ip", "200.200.3.61"));
    EXPECT_EQ(0,json_check_key(basic,"ip"));
    EXPECT_EQ(1,json_check_key(basic,"ip123"));
}

TEST(arr_add_objTest,Normal){
    Array* basic = json_new_arr();
	arr_add_obj(basic, arr_create_bool("true"));
    EXPECT_EQ(0,basic->array_address->index);
    EXPECT_EQ(true,basic->array_address->value.b);
    //EXPECT_EQ(NULL,basic->array_address->next);
    const char * str =  "true";
	arr_add_obj(basic, arr_create_str(str));
    EXPECT_EQ(0,basic->array_address->next->index);
    EXPECT_EQ(str,basic->array_address->value.string);
    EXPECT_EQ(NULL,basic->array_address->next->next);
    
}

TEST(json_create_arrTest,Normal){
    Json* root = json_new_obj();
	Array* arr = json_new_arr();
	json_add_obj(root, json_create_arr("basic", arr));

    EXPECT_EQ(root->head->value.array_child,arr);
    
}

TEST(json_create_jsonTest,Normal){
    Json* root = json_new_obj();
	Json* basic = json_new_obj();
	json_add_obj(root, json_create_json("basic", basic));
	json_add_obj(basic, json_create_bool("enable", "true"));

    EXPECT_EQ(root->head->value.Json_child,basic);
}

TEST(json_create_bool, json_create_bool_TEST) {
	EXPECT_EQ(true, json_create_bool("enable", "true")->value.b);
}

TEST(json_create_int, json_create_int_TEST) {
	Json* basic = json_new_obj();
	json_add_obj(basic, json_create_int("port", 389));
	EXPECT_EQ(389, basic->head->value.i);
	EXPECT_EQ("port", basic->head->key);
}

TEST(json_create_str, json_create_str_TEST) {
	Json* basic = json_new_obj();
	json_add_obj(basic, json_create_str("ip", "200.200.3.61"));
	EXPECT_EQ("200.200.3.61", basic->head->value.string);
	EXPECT_EQ("ip", basic->head->key);
}

TEST(arr_create_int, arr_create_int_TEST) {
	Array* port_arr = json_new_arr();
	arr_add_obj(port_arr, arr_create_int(130));
	EXPECT_EQ(130, port_arr->array_address->value.i);
}

TEST(arr_create_str, arr_create_str_TEST) {
	Array* dns_arr = json_new_arr();
	arr_add_obj(dns_arr, arr_create_str("200.200.0.1"));
	EXPECT_EQ("200.200.0.1", dns_arr->array_address->value.string);
}

TEST(arr_create_bool, arr_create_bool_TEST) {
	Array* bool_arr = json_new_arr();
	arr_add_obj(bool_arr, arr_create_bool("true"));
	EXPECT_EQ(true, bool_arr->array_address->value.b);
}

TEST(arr_create_arr, arr_create_arr_TEST) {
	Array* dns_arr = json_new_arr();
	arr_add_obj(dns_arr, arr_create_str("200.200.0.1"));
	arr_add_obj(dns_arr, arr_create_str("200.0.0.254"));
	Array* dns = json_new_arr();
	EXPECT_EQ(dns_arr, arr_create_arr(dns_arr)->value.array_child);
}

TEST(arr_create_jsonTest,Normal){
	Array* dns_arr = json_new_arr();
	Json* basic = json_new_obj();
	arr_add_obj(dns_arr, arr_create_json(basic));
	EXPECT_EQ(basic, dns_arr->array_address->value.Json_child);
}

TEST(json_search_nodeTest,Normal){
	Json* basic = json_new_obj();
	EXPECT_EQ(NULL, json_search_node(basic,"keyint1"));
	json_add_obj(basic, json_create_int("keyint1",100));
	json_add_obj(basic, json_create_int("keyint2",200));
	EXPECT_NE(NULL, (long int)json_search_node(basic,"keyint1"));
	EXPECT_NE(NULL, (long int)json_search_node(basic,"keyint2"));
}

TEST(json_get_intTest,Normal){
	Json* basic = json_new_obj();
	EXPECT_EQ(INT_MAX, json_get_int(basic,"keyint1"));
	json_add_obj(basic, json_create_int("keyint1",100));
	EXPECT_EQ(100, json_get_int(basic,"keyint1"));
	EXPECT_EQ(INT_MAX, json_get_int(basic,"keyint2"));
}

TEST(json_get_boolTest,Normal){
	Json* basic = json_new_obj();
	EXPECT_EQ(-1, json_get_bool(basic,"keybool1"));
	json_add_obj(basic, json_create_bool("keybool1","true"));
	EXPECT_EQ(1, json_get_bool(basic,"keybool1"));
	json_add_obj(basic, json_create_bool("keybool0","false"));
	EXPECT_EQ(0, json_get_int(basic,"keybool0"));
	EXPECT_EQ(-1, json_get_bool(basic,"keybool-1"));
}

TEST(json_get_strTest,Normal){
	Json* basic = json_new_obj();
	EXPECT_EQ(NULL, json_get_str(basic,"keystr1"));
	json_add_obj(basic, json_create_str("keystr1","json_test_"));
	EXPECT_EQ("json_test_", json_get_str(basic,"keystr1"));
	EXPECT_EQ(NULL, json_get_str(basic,"keystr2"));
    
}

TEST(json_get_arr_jsonTest,Normal){
    Json* root = json_new_obj();
	Array* subarr = json_new_arr();
    Json* subjson = json_new_obj();
    EXPECT_EQ(NULL,json_get_arr_json(root,"subarr",0));
	json_add_obj(root, json_create_arr("subarr", subarr));
    arr_add_obj(subarr,arr_create_json(subjson));
    EXPECT_EQ(subjson,json_get_arr_json(root,"subarr",0));
    
}

TEST(json_get_jsonTest,Normal){
    Json* root = json_new_obj();
	Json* basic = json_new_obj();
    EXPECT_EQ(NULL,json_get_json(root,"basic"));
	json_add_obj(root, json_create_json("basic", basic));
    EXPECT_EQ(basic,json_get_json(root,"basic"));
}

/*
TEST(json_printTest,Normal){
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

}
*/

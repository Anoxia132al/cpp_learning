#pragma once

#include <iostream>
#include <vector>

using std::string;

void slp_in_function ();
string::size_type find_char (const string &s, char c, string::size_type &occurs);
size_t find_char2 (const string &s, char c, size_t &occurs);
void run_find_char2 ();
void ts_initializer_list (std::initializer_list<string> ls);
int fix_stg (int val);
void run_stg_one ();
int (*back_arrypointer (int i))[10];
void run_back_arryppointer ();
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
int (*get_row(int matrix[][1920], int row_index))[1920];
int tt_func (int a, int b);
int tt_func2 (int a, int b);
void run_tt_func ();
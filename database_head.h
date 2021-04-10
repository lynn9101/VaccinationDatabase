//Header file
////////////////////////////////////////////////
//contents:
// - all #include's 
// - declares methods from Person_info, Database and Menu classes 

#ifndef DATABASE_H
#define DATABASE_H

#include "cmpt_error.h"
#include <cassert>
#include <iomanip>
#include <ncurses.h>
#include <fstream>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <chrono> 
#include <thread>

using namespace std;

//Person_info class
class Person_info{
private:
	string new_name;
	string yob; //year of birth (yob)
	string new_city;
	long phone_num; 
	string vaccinated; 
    
public:
	Person_info();

	void new_person(); 
	string get_name() const;
	string get_yob() const;
	string get_city() const;
	int get_phone() const;
	string get_status() const;

	void set_name(string name);
	void set_yob(string data);
	void set_city(string city);
	void set_phone(long phone);
	void set_status(string status);

	bool valid_name (string user_input);
	bool check_year (int year);
	bool valid_year (string user_input);
	bool valid_city (string city_name);
	bool valid_phone (long num);
	~Person_info();
};


//Database class 
class Database{
private:
	int size;
	int capacity;
	Person_info *new_data;

public:
	Database();
	
	int get_size() const;
	int get_cap() const;
	void get_data();
	void resize();
	
	void add_data(const Person_info& person);
	void delete_name(string name);
	void delete_yob(string yob);
	void delete_phone(long phone);
	void delete_status(string status);
	void delete_city(string city);

	void search_name (string name);
	void search_yob (string yob);
	void search_city (string city);
	void search_phone (long phone);
	void search_status(string status);
	void search_substr_name(string findData);
	void search_substr_city(string findCity);
	void search_substr_phone(long num);
	void search_range_yob(int low, int high);
	string print_record (int i);

	void list_name_alpha();
	void list_name_reverse();
	void list_yob_ascend();
	void list_phone_ascend();
	void list_yob_descend();
	void list_phone_descend();

	~Database();
};

//display.cpp
void destroy_win(WINDOW *deleteWin);
WINDOW* create_win();
char feature_display();
void newwind();
char search_display(char response);
char search_str_display();
char search_int_display();
char update_display();
char list_display();
char list_str_display();
char list_int_display();
void test();

//Menu class 
class Menu{
private:
	Database new_database;
	Person_info person;
	string fname;

public:
	Menu();
	
	void adding();
	char searching(char user_input);
	char list();
	void quit();
	string search_get_input();
	int search_num_input();
	
};
#endif
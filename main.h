#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int map_num_rows;            //! số hàng ma trận
int map_num_cols;            //! số cột của ma trận
int max_num_moving_objects;  //! số lượng tối đa của nhân vật game
int num_walls;               //! số lượng tường trong game
int **arr_walls;             //! danh sách các vị trị tường trong game mảng 2 chiều với mỗi phần tử [x,y]
int num_fake_walls;          //! số lượng tường ảo trong game
int **arr_fake_walls;        //! danh sách các vị trị tường ảo trong game mảng 2 chiều với mỗi phần tử [x,y]
string sherlock_moving_rule; //! chuỗi di chuyển của sherlock
int sherlock_init_pos[2];    //! vị trí của sherlock [x,y]
int sherlock_init_hp;        //! máu của sherlock
int sherlock_init_exp;       //! kinh nghiệm của sherlock
string watson_moving_rule;
int watson_init_pos[2];
int watson_init_hp;
int watson_init_exp;
int criminal_init_pos[2]; //! vị trí của tên trộm [x,y]
int num_steps;            //! thời gian chơi game

static ofstream OUTPUT;
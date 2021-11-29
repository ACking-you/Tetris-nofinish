//
// Created by Alone on 2021/11/28.
//

#ifndef TETRIS_TETRIS_H
#define TETRIS_TETRIS_H

#include <stdio.h>
#include <stdbool.h> //定义bool类型的头文件
#include <windows.h> //定义Sleep函数的头文件

struct tetris;  //结构体的结构对外隐藏


void tetris_init(struct tetris* t,int w,int h);//初始化内容

void tetris_destroy(struct tetris* t);

/*游戏功能相关函数*/
bool tetris_hit_test(struct tetris *t);//边界检测函数

void tetris_update_block(struct tetris *t);//将cur的方块内容更新到date中去：这说明需要直接静态保存到里面去了，而不是在天空中下落的状态

void tetris_new_block(struct tetris *t);//更新方块cur和next

void tetris_gravity(struct tetris *t);//重力施加函数，如果到了边界则需要把方块更新到date中去，且更新方块cur和next

void tetris_rotate(struct tetris *t);//游戏中较为重要的算法之一，把方块的各项位置旋转

void tetris_check_lines(struct tetris *t);//游戏中较为重要的算法之二，检查是否需要消除行

/*游戏画面打印*/
void tetris_print(struct tetris *t);//每一帧的画面生成全靠它

/*游戏主循环*/
void tetris_run(int h, int w);//main函数只需调用它，整个界面循环便开始运作，里面包含了与用户交互的操作

#endif //TETRIS_TETRIS_H

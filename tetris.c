//
// Created by Alone on 2021/11/29.
//
#include <assert.h>
#include <time.h>
#include <conio.h>

#include "tetris.h"

//存储类型定义
struct tetris{//描述整个组成的方块游戏界面
    int h,w;        //界面的高和宽
    char** data;    //界面的数据
    int x,y;        //当前运动方块的左上角坐标
    int level;      //游戏难度
    bool isOver;    //判断游戏是否结束
    int score;      //游戏的当前分数
    struct tetris_block{//定义方块类型并且创建cur,next
        //cur表示当前状态，next表示下一个
        //由于方块的大小最多占有四格，我们给它底层数据5*5
        int h,w;
        char data[5][5];
    }cur,next;
};

struct tetris_level{//控制着游戏的难度：存储两个映射->每个score对应的sleep暂停时间
    int score;
    int nsec;
}levels[]={
        {0,200},//1.2s刷新一次
        {1500,150},//0.9s刷新一次
        {8000,100},
        {20000,50},
        {40000,40},
        {75000,30},
        {100000,20}
};
#define BLOCKS_SIZE (sizeof(blocks)/sizeof(struct tetris_block))    //方便计算长度
#define LEVELS_SIZE (sizeof(levels)/sizeof(struct tetris_level))


struct tetris_block blocks[] = {//六种方块
        {2,2,{"##","##"}},
        {2,3,{" X ","XXX"}},
        {1,4,{"@@@@"}},
        {3,2,{"OO","O ","O "}},
        {3,2,{"&&"," &"," &"}},
        {2,3,{"ZZ "," ZZ"}},
};

void tetris_init(struct tetris *t, int h, int w) {
    t->level = 0;
    t->score = 0;
    t->w = w;
    t->h = h;
    t->isOver = 0;
    t->data = (char**)malloc(sizeof(char*)*h);
    assert(t->data != NULL);
    for(int i=0;i<h;i++){
        t->data[i] = (char*)malloc(sizeof(char)*w);
        assert(t->data[i] != NULL);
        memset(t->data[i],' ',sizeof(char)*w);
    }
}


void tetris_destroy(struct tetris *t){
    for(int i=0;i<t->h;i++){
        free(t->data[i]);
    }
    free(t->data);
}

bool tetris_hit_test(struct tetris *t) {
    int x,y,X,Y;    //注意我按照数组下标的先后顺序表示的x、y所以x是纵坐标
    struct tetris_block tmp = t->cur;
    for(x=0;x<tmp.h;x++){
        for(y=0;y<tmp.w;y++){
            X = t->x + x;
            Y = t->y + y;
            if(Y<0 || Y>=t->w)//左右越界了
                return true;
            if(tmp.data[x][y] != ' ')//如果左右没有越界，查看所有的实体方块位置是否越界
            {
                if((X>=t->h)||(X>=0&&t->data[X][Y] != ' '))//如果超过底，或者是遇到已经固定在底下的方块
                    return true;
            }
        }
    }
    return false;
}

void tetris_update_block(struct tetris *t) {
    int x,y,X,Y;
    struct tetris_block tmp=t->cur;
    for (x=0; x<tmp.h; x++)
        for (y=0; y<tmp.w; y++) {
            if (tmp.data[x][y]!=' '){
                assert(t->x+x < t->h && t->y+y < t->w);
                t->data[t->x+x][t->y+y]=tmp.data[y][x];
            }
        }
}

void tetris_new_block(struct tetris *t) {//next最开始进行过一次初始化，然后每次只需要更新next即可
    t->cur = t->next;
    t->next = blocks[rand()%BLOCKS_SIZE];
    t->y=(t->w/2) - (t->cur.w/2);
    t->x=0;
    if (tetris_hit_test(t)) {//如果在最上方产生新方块的时候，直接就触底了，直接游戏结束
        t->isOver=1;
    }
}

void tetris_gravity(struct tetris *t) {
    t->x++;//方块纵坐标+1
    if(tetris_hit_test(t)){//直接就落地了（只可能落地毕竟是正常重力，而不是左右）
        t->x--;
        tetris_update_block(t);//落地进行固定
        tetris_new_block(t);//然后产生新的方块
    }
}

void tetris_rotate(struct tetris *t) {
    int h = t->cur.h;
    int w = t->cur.w;//横的给它变成竖的，竖的给它变成横的
    struct tetris_block change = t->cur;//临时矩阵存储
    change.w = h;
    change.h = w;   //存储旋转后的方块
    for(int c1=0,r2=0;r2<w;r2++,c1++){//r表示行，c表示列
        for(int c2=0,r1=0;r1<h;c2++,r1++){
            change.data[r2][c2] = t->cur.data[r1][c1];
        }
    }
    struct tetris_block tmp = t->cur;//做备份万一出现越界，则需要恢复
    t->cur = change;
    if(tetris_hit_test(t)){
        t->cur = tmp;
    }
}


static inline bool check_floor(struct tetris* t,int l){
    //检查这一层是否需要抵消
    for(int i=0;i<t->w;i++){
        if(t->data[l][i] == ' ')
            return false;
    }
}

void tetris_check_lines(struct tetris *t) {
     int point = 100;
     int i,j;
     char tmp[t->h][t->w];//临时存储消除结果的空间
     int index = 0;
     for(i=0;i<t->h;i++){
         if(check_floor(t,i))//检查是否需要抵消，需要则不更新到tmp，并记录分数
             t->score += point;
         else{
             for(j=0;j<t->w;j++){
                 tmp[index][j] = t->data[i][j];
             }
             index++;
         }
     }
     //最后复原抵消后的数据
    for (int k = t->h-1; k >= 0; k--) {
        if(index>0){
            memmove(t->data[k],tmp[index-1],sizeof(char)*t->w);
            index--;
        }else{//剩余的缺口都用' '填补，正好一个字节，可以用memset
            memset(t->data[k],' ',sizeof(char)*t->w);
        }
    }
}


void tetris_print(struct tetris *t) {   //每一帧画面的打印
    int x,y;
    for (x=0; x<30; x++)
        printf("\n");
    printf("[LEVEL: %d | SCORE: %d]\n", t->level, t->score);
    for (x=0; x<2*t->w+2; x++)
        printf("~");
    printf("\n");
    for (x=0; x<t->h; x++) {
        printf ("!");
        for (y=0; y<t->w; y++) {
            if (x>=t->x && y>=t->y
                && x<(t->x+t->cur.h) && y<(t->y+t->cur.w)
                && t->cur.data[x-t->x][y-t->y]!=' ')
                printf("%c", t->cur.data[x-t->x][y-t->y]);
            else
                printf("%c", t->data[x][y]);
        }
        printf ("!\n");
    }
    for (x=0; x<2*t->w+2; x++)
        printf("~");
    printf("\n");
}

static inline int get_level(struct tetris *t) {//计算当前的游戏难度等级
    int i;
    for (i=0; i<LEVELS_SIZE; i++) {
        if (t->score>=levels[i].score) {
            t->level = i;
        } else break;
    }
    return levels[t->level].nsec;//返回这个等级对应的刷新率
}

void tetris_run(int w, int h) {
    struct tetris t;
    tetris_init(&t,w,h);
    srand((unsigned)time(NULL));
    t.next = blocks[rand()%BLOCKS_SIZE];
    tetris_new_block(&t);
    char cmd;
    while (!t.isOver) {
        system("cls");
        tetris_print(&t);
        if(_kbhit()&&(cmd=_getch())>0) {
            switch (cmd) {
                case 'a':
                    t.y--;
                    if (tetris_hit_test(&t))
                        t.y++;
                    break;
                case 'd':
                    t.y++;
                    if (tetris_hit_test(&t))
                        t.y--;
                    break;
                case 's':
                    tetris_gravity(&t);
                    break;
                case 'w':
                    tetris_rotate(&t);
                    break;
            }
        }
        tetris_gravity(&t);
        tetris_check_lines(&t);
        Sleep(500);
    }
    tetris_print(&t);
    printf("*** GAME OVER ***\n");
    tetris_destroy(&t);
}

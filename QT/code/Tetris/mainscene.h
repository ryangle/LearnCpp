#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <QPushButton>
#include "config.h"
//方向
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};

//定义边界信息
struct Border
{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};

//坐标
struct block_point
{
    int pos_x;
    int pos_y;
};
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event); //键盘响应

public:
    void InitGame(); //初始化
    void StartGame(); //开始游戏
    void GameOver(); //游戏结束

    void ResetBlock(); //重置方块
    void BlockMove(Direction dir); //方块变动
    void BlockRotate(int block[4][4]); //方块旋转
    void CreateBlock(int block[4][4],int block_id); //产生方块
    void GetBorder(int block[4][4],Border &border); //计算边界
    void ConvertStable(int x,int y); //转换为稳定方块
    bool IsCollide(int x,int y,Direction dir); //判断是否会碰撞

private:
    int game_area[AREA_ROW][AREA_COL]; //场景区域，1表示活动的方块，2表示稳定的方块，0表示空
    block_point cur_blockPos; //当前方块坐标
    int cur_block[4][4]; //当前方块形状
    Border cur_border; //当前方块边界
    int next_block[4][4]; //下一个方块形状
    int score;  //游戏分数
    int speed_ms; //下落时间间隔
    int refresh_ms; //刷新时间间隔

    QTimer timerBlockMove;
    QTimer timerRefresh;

    QPushButton *startBtn;
    QPushButton *stopBtn;
};
#endif // MAINSCENE_H

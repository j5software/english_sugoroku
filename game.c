//koba
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYERMAX 4

#define TRUE  1
#define FALSE 0

#define SIZE 20


struct position {
  int x;
  int y;
};

struct road {
  position pos; 
};

struct board {
  road *m;
  int size;
};

struct quiz {
  char question[SIZE];
  char anwer[SIZE];
};

struct player {
  char name[SIZE];
  int score;
  road *now;
};


// 名前入力
void inputName(struct player *p);

// 初期化
void initPlayer(struct player *p, int num);
void initBoard(struct board *p);
void initQuestion(struct question *p);

// サイコロを振る
int throwDaice(void);

// 問題に答える
int answerQuestion(struct question *p);

// 移動
void movePlayer(struct player *p, int num, int torf);

int length(char answer[]);

// 正解したときの得点加算
void getPoint(struct player *p, int point, int torf);

// 順位による得点加算
void addRankingPoint(struct player *p, int rank);

// 最終的な順位の決定
void decideRanking(struct player *p);

// 表示
void printBoard(struct board *board, int turn, int p_num, struct player **p);
void printPlayer(struct player **p, int p_num);


int main(void) {

  return 0;
}

void inputName(struct player *p)
{
  printf("Player Name :");
  scanf("%s", p->name);
}

void initBoard(struct board *p)
{
  int i;

  for (i = 0; i < 50; i++) {
    p->num = i;
    if (p->num == 0) {
      p->content = START;
    } else if (p->num == 50) {
      p->content = GOAL;
    } else {
      p->content = OTHER;
    }
  }
}


void initQuestion(struct question *p) //add
{

}

int throwDaice(void)
{
  int daice;
  srand((unsigned)time(NULL));
  daice = (rand() % 6) + 1;
  return daice;
}

int answerQuestion(struct question *p)
{
  char answer[10];
  int i;

  printf("answer :");
  scanf("%s", &answer);
  for (i = 0; answer[i] != '\0'; i++) {
    if (answer[i] != p->answer[i]) {
      return FALSE;
    }
  }
  return TRUE;
}

void movePlayer(struct player *p, int num, int torf)
{
  if (torf == TRUE) {
    p->position += num;
    if(p->position >= 50) {
      p->position = 50;
    }
  }
  else {
    p->position -= num;
    if (p->position <= 0) {
      p->position = 0;
    }
  }
}

int length(char answer[])
{
  int i;
  for (i = 0; answer[i] != '\0'; i++);
  return i;
}

void getPoint(struct player *p, int point, int torf)
{
  if (torf == TRUE) {
    p->point += point;
  } else { 
    p->point -= point;
  }
}

void addRankingPoint(struct player *p, int rank)
{
  int point;
  int i;

  point = 10 * PLAYERMAX;
  for (i = 1; i < rank; i++) {
    point /= 2;
  }
  p->point += point;
}

void decideRanking(struct player *p) //add
{

}

void printBoard(struct board *board, int turn, int p_num, struct player **p)
{
  int i, j;
 
  printf("**********TURN %d*************\n", turn);
  for(i = 0; i < 50; i++) {
    printf(" %d :");
    for(j = 0; j < p_num; j++) {
      if(i == p[j]->position) {
	printf("i");
      }
    }
    printf("\n");
  }
}

void printPlayer(struct player **p, int p_num)
{
  int i;
  for(i = 0; i < p_num; i++) {
    printf("--------------------\n");
    printf("%s \n", p[i]->name);
    printf("現在地:%2d 得点:%3d\n\n", p[i]->position, p[i]->point);
    printf("--------------------\n");
  }
}

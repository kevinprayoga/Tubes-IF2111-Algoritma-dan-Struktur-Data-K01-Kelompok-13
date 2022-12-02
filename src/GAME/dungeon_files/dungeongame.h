#ifndef DUNGEON_GAMEPLAY
#define DUNGEON_GAMEPLAY

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* type;
    int damage;
    char effect;
    int mana;
    int count;
} Attack;

typedef struct{
    char* type;
    int shield;
    char effect;
    int mana;
    int count;
} Defense;

typedef struct{
    char* type;
    char* name;
    char* desc;
    int mana;
    Attack skillAtk;
    Defense skillDef;
} Skill;

typedef struct{
    int charID;
    char* name;
    int atkBase;
    int shieldBase;
    int HPBase;
    int mana;
    Skill arr[3];
    char stat;
} Chara;

#define undef -1

void makeChara(Chara *play, int id);

void printChara(Chara play);

void copyChara(Chara *p, Chara play);

void useSkill(Chara* play, Chara* enemy, int skillID);

void recharge(Chara* play);

//void heal(Chara play);

void atk(Chara play, Chara* enemy);

#endif
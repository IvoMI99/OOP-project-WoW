#ifndef __PLAY_H__
#define __PLAY_H__
#include <fstream>
#include "hero.h"
#include "togwaggle.h"
#include "patchwerk.h"
#include "combatant.h"
#include "rager.h"
#include "giant.h"
#include "flamewalker.h"
#include "kobold.h"
#include "furbolg.h"
#include "map.h"
#include "monster.h"
#include "goblin.h"
#include "undead.h"
#include "spider.h"
#include "warrior.h"
#include "paladin.h"
#include "mage.h"
#include "raggnaros.h"
#include "log.h"


void play (Hero*);
void treasureScreen(Hero*);
bool battleScreen(Hero*,bool =false,Map* =nullptr);
Map* mapSelection(Map*);
Monster* enemyEncounter(Map* );

#endif // __PLAY_H__

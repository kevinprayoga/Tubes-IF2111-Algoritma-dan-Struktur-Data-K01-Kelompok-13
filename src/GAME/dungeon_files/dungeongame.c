#include "dungeongame.h"

void makeChara(Chara *play, int id){
    switch(id)
        case 0:
            //the player
            play->charID = id;
            play->name = "Player";
            play->atkBase = 80;
            play->shieldBase = 0;
            play->HPBase = 420;
            play->mana = 300;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Luck";
            play->arr[0].desc = "Having 10%% chance to not die when knocked out.";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = undef;
            play->arr[0].skillAtk.effect = '-';
            play->arr[0].skillAtk.mana = undef;
            play->arr[0].skillAtk.count = undef;
            play->arr[0].skillDef.type = "Player";
            play->arr[0].skillDef.shield = 10;
            play->arr[0].skillDef.effect = 'l';
            play->arr[0].skillDef.mana = 0;
            play->arr[0].skillDef.count = 1;

            play->arr[1].type = "Active";
            play->arr[1].name = "Protect";
            play->arr[1].desc = "All attacks go to you and gain a shield that absorbs 100 damage.";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = undef;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = undef;
            play->arr[1].skillAtk.count = undef;
            play->arr[1].skillDef.type = "Player";
            play->arr[1].skillDef.shield = 100;
            play->arr[1].skillDef.effect = 't';
            play->arr[1].skillDef.mana = 200;
            play->arr[1].skillDef.count = 1;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "Ambush";
            play->arr[2].desc = "Sneak upon your targets and hit 10 times 40 damage.";
            play->arr[2].skillAtk.type = "Player";
            play->arr[2].skillAtk.damage = 40;
            play->arr[2].skillAtk.effect = 'm';
            play->arr[2].skillAtk.mana = 300;
            play->arr[2].skillAtk.count = 10;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 1:
            //character eugen
            play->charID = id;
            play->name = "Eugen";
            play->atkBase = 77;
            play->shieldBase = 0;
            play->HPBase = 479;
            play->mana = 300;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Impervious";
            play->arr[0].desc = "Reduce damage to characters by 10%%";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = undef;
            play->arr[0].skillAtk.effect = '-';
            play->arr[0].skillAtk.mana = undef;
            play->arr[0].skillAtk.count = undef;
            play->arr[0].skillDef.type = "Earth";
            play->arr[0].skillDef.shield = 10;
            play->arr[0].skillDef.effect = 'b';
            play->arr[0].skillDef.mana = 0;
            play->arr[0].skillDef.count = 1;

            play->arr[1].type = "Active";
            play->arr[1].name = "Ice Wall";
            play->arr[1].desc = "Creates an ice wall that absorbs 150 damage for both characters.";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = undef;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = undef;
            play->arr[1].skillAtk.count = undef;
            play->arr[1].skillDef.type = "Water";
            play->arr[1].skillDef.shield = 150;
            play->arr[1].skillDef.effect = 'c';
            play->arr[1].skillDef.mana = 200;
            play->arr[1].skillDef.count = 1;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "Meteor Strike";
            play->arr[2].desc = "Unleash a huge meteor from the air and hit enemies 4 times 100 damage and heals.";
            play->arr[2].skillAtk.type = "Fire";
            play->arr[2].skillAtk.damage = 100;
            play->arr[2].skillAtk.effect = 'h';
            play->arr[2].skillAtk.mana = 300;
            play->arr[2].skillAtk.count = 4;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 2:
            //character littorio
            play->charID = id;
            play->name = "Littorio";
            play->atkBase = 96;
            play->shieldBase = 0;
            play->HPBase = 415;
            play->mana = 200;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Mighty Sword";
            play->arr[0].desc = "Increase both characters base atk by 10%%";
            play->arr[0].skillAtk.type = "Fire";
            play->arr[0].skillAtk.damage = 10;
            play->arr[0].skillAtk.effect = 'b';
            play->arr[0].skillAtk.mana = 0;
            play->arr[0].skillAtk.count = 1;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Divide";
            play->arr[1].desc = "Summons a stone pillar and hits 2 enemy 50 damage.";
            play->arr[1].skillAtk.type = "Earth";
            play->arr[1].skillAtk.damage = 50;
            play->arr[1].skillAtk.effect = 's';
            play->arr[1].skillAtk.mana = 100;
            play->arr[1].skillAtk.count = 2;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "Rejuvenate";
            play->arr[2].desc = "Fully heals both characters and creates a wall that absorbs 100 damage.";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = undef;
            play->arr[2].skillAtk.effect = '-';
            play->arr[2].skillAtk.mana = undef;
            play->arr[2].skillAtk.count = undef;
            play->arr[2].skillDef.type = "Water";
            play->arr[2].skillDef.shield = 100;
            play->arr[2].skillDef.effect = 'h';
            play->arr[2].skillDef.mana = 200;
            play->arr[2].skillDef.count = 1;

            break;
        case 3:
            //character taihou
            play->charID = id;
            play->name = "Taihou";
            play->atkBase = 84;
            play->shieldBase = 0;
            play->HPBase = 391;
            play->mana = 400;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Performer";
            play->arr[0].desc = "Increase both characters skill effect by 10%%";
            play->arr[0].skillAtk.type = "Water";
            play->arr[0].skillAtk.damage = 10;
            play->arr[0].skillAtk.effect = 'b';
            play->arr[0].skillAtk.mana = 0;
            play->arr[0].skillAtk.count = 1;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Flame Dance";
            play->arr[1].desc = "Shoots 3 flame arrows that deal 80 damage each.";
            play->arr[1].skillAtk.type = "Fire";
            play->arr[1].skillAtk.damage = 80;
            play->arr[1].skillAtk.effect = 'f';
            play->arr[1].skillAtk.mana = 200;
            play->arr[1].skillAtk.count = 3;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "Earth Crush";
            play->arr[2].desc = "Roll the ground around your enemy dealing 500 damage and heals.";
            play->arr[2].skillAtk.type = "Earth";
            play->arr[2].skillAtk.damage = 500;
            play->arr[2].skillAtk.effect = 'h';
            play->arr[2].skillAtk.mana = 400;
            play->arr[2].skillAtk.count = 1;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 4:
            //npc skeleton
            play->charID = id;
            play->name = "Skelly";
            play->atkBase = 47;
            play->shieldBase = 0;
            play->HPBase = 260;
            play->mana = 100;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Undead";
            play->arr[0].desc = "-";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = undef;
            play->arr[0].skillAtk.effect = '-';
            play->arr[0].skillAtk.mana = undef;
            play->arr[0].skillAtk.count = undef;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "-";
            play->arr[1].desc = "-";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = undef;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = undef;
            play->arr[1].skillAtk.count = undef;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "-";
            play->arr[2].desc = "-";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = undef;
            play->arr[2].skillAtk.effect = '-';
            play->arr[2].skillAtk.mana = undef;
            play->arr[2].skillAtk.count = undef;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 5:
            //npc goblin
            play->charID = id;
            play->name = "Gobs";
            play->atkBase = 55;
            play->shieldBase = 0;
            play->HPBase = 320;
            play->mana = 100;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Likes Money";
            play->arr[0].desc = "-";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = undef;
            play->arr[0].skillAtk.effect = '-';
            play->arr[0].skillAtk.mana = undef;
            play->arr[0].skillAtk.count = undef;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Goblin Poach";
            play->arr[1].desc = "Deal 50 damage.";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = 50;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = 100;
            play->arr[1].skillAtk.count = 1;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "-";
            play->arr[2].desc = "-";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = undef;
            play->arr[2].skillAtk.effect = '-';
            play->arr[2].skillAtk.mana = undef;
            play->arr[2].skillAtk.count = undef;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 6:
            //npc zombie
            play->charID = id;
            play->name = "Zombs";
            play->atkBase = 64;
            play->shieldBase = 0;
            play->HPBase = 374;
            play->mana = 100;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Undead";
            play->arr[0].desc = "-";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = undef;
            play->arr[0].skillAtk.effect = '-';
            play->arr[0].skillAtk.mana = undef;
            play->arr[0].skillAtk.count = undef;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Zombie Slam";
            play->arr[1].desc = "Deal 80 damage";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = 80;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = 100;
            play->arr[1].skillAtk.count = 1;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "-";
            play->arr[2].desc = "-";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = undef;
            play->arr[2].skillAtk.effect = '-';
            play->arr[2].skillAtk.mana = undef;
            play->arr[2].skillAtk.count = undef;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 7:
            //npc spider
            play->charID = id;
            play->name = "Spida";
            play->atkBase = 78;
            play->shieldBase = 0;
            play->HPBase = 410;
            play->mana = 200;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Climby";
            play->arr[0].desc = "Reduce damage received by 3%%";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = undef;
            play->arr[0].skillAtk.effect = '-';
            play->arr[0].skillAtk.mana = undef;
            play->arr[0].skillAtk.count = undef;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = 3;
            play->arr[0].skillDef.effect = 'b';
            play->arr[0].skillDef.mana = 0;
            play->arr[0].skillDef.count = 1;

            play->arr[1].type = "Active";
            play->arr[1].name = "Spider Sting";
            play->arr[1].desc = "Deal 100 damage";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = 100;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = 100;
            play->arr[1].skillAtk.count = 1;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "-";
            play->arr[2].desc = "-";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = undef;
            play->arr[2].skillAtk.effect = '-';
            play->arr[2].skillAtk.mana = undef;
            play->arr[2].skillAtk.count = undef;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 8:
            //npc witch
            play->charID = id;
            play->name = "Witch";
            play->atkBase = 86;
            play->shieldBase = 0;
            play->HPBase = 512;
            play->mana = 300;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Magic Adept";
            play->arr[0].desc = "Increase spell effect by 5%%";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = 5;
            play->arr[0].skillAtk.effect = 'b';
            play->arr[0].skillAtk.mana = 0;
            play->arr[0].skillAtk.count = 1;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Dead Grasp";
            play->arr[1].desc = "Deal 80 damage to 2 enemies";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = 80;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = 200;
            play->arr[1].skillAtk.count = 2;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "Dark Exorcism";
            play->arr[2].desc = "Deal 110 damage to 2 enemies, heals";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = 110;
            play->arr[2].skillAtk.effect = 'h';
            play->arr[2].skillAtk.mana = 300;
            play->arr[2].skillAtk.count = 2;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 9:
            //npc vampire
            play->charID = id;
            play->name = "Vampire";
            play->atkBase = 99;
            play->shieldBase = 0;
            play->HPBase = 585;
            play->mana = 300;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Bloodlust";
            play->arr[0].desc = "Increase base atk by 5%%";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = 5;
            play->arr[0].skillAtk.effect = 'b';
            play->arr[0].skillAtk.mana = 0;
            play->arr[0].skillAtk.count = 1;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Bloody Feast";
            play->arr[1].desc = "Deal 100 damage to 2 enemies";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = 100;
            play->arr[1].skillAtk.effect = '-';
            play->arr[1].skillAtk.mana = 200;
            play->arr[1].skillAtk.count = 2;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = undef;
            play->arr[1].skillDef.effect = '-';
            play->arr[1].skillDef.mana = undef;
            play->arr[1].skillDef.count = undef;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "Vampire's Wrath";
            play->arr[2].desc = "Deal 150 damage to 2 enemies, heals";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = 150;
            play->arr[2].skillAtk.effect = 'h';
            play->arr[2].skillAtk.mana = 300;
            play->arr[2].skillAtk.count = 2;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
        case 10:
            //npc boss
            play->charID = id;
            play->name = "Void Princess";
            play->atkBase = 120;
            play->shieldBase = 0;
            play->HPBase = 640;
            play->mana = 400;
            play->stat = '-';

            play->arr[0].type = "Passive";
            play->arr[0].name = "Void Incarnate";
            play->arr[0].desc = "Reduce dmg, increase skill, and increase base atk by 5%%";
            play->arr[0].skillAtk.type = "-";
            play->arr[0].skillAtk.damage = 5;
            play->arr[0].skillAtk.effect = 'b';
            play->arr[0].skillAtk.mana = 0;
            play->arr[0].skillAtk.count = 3;
            play->arr[0].skillDef.type = "-";
            play->arr[0].skillDef.shield = undef;
            play->arr[0].skillDef.effect = '-';
            play->arr[0].skillDef.mana = undef;
            play->arr[0].skillDef.count = undef;

            play->arr[1].type = "Active";
            play->arr[1].name = "Into The Void";
            play->arr[1].desc = "Deal 200 damage to 2 enemies, shield absorbs 50 damage";
            play->arr[1].skillAtk.type = "-";
            play->arr[1].skillAtk.damage = 200;
            play->arr[1].skillAtk.effect = 'f';
            play->arr[1].skillAtk.mana = 300;
            play->arr[1].skillAtk.count = 2;
            play->arr[1].skillDef.type = "-";
            play->arr[1].skillDef.shield = 50;
            play->arr[1].skillDef.effect = 'c';
            play->arr[1].skillDef.mana = 0;
            play->arr[1].skillDef.count = 1;

            play->arr[2].type = "Ultimate";
            play->arr[2].name = "World of Nothingness";
            play->arr[2].desc = "Deal 300 damage to 2 enemies, heals";
            play->arr[2].skillAtk.type = "-";
            play->arr[2].skillAtk.damage = 300;
            play->arr[2].skillAtk.effect = 'h';
            play->arr[2].skillAtk.mana = 400;
            play->arr[2].skillAtk.count = 2;
            play->arr[2].skillDef.type = "-";
            play->arr[2].skillDef.shield = undef;
            play->arr[2].skillDef.effect = '-';
            play->arr[2].skillDef.mana = undef;
            play->arr[2].skillDef.count = undef;

            break;
}

void printChara(Chara play){
    printf("\nCharacter Info\n");
    printf("\nNama: %s.", play.name);
    printf("\nBase Atk: %d.", play.atkBase);
    printf("\nBase HP: %d.", play.HPBase);
    printf("\nMana: %d.", play.mana);
    printf("\n");
    printf("\nPassive: %s.", play.arr[0].name);
    printf("\n%s", play.arr[0].desc);
    printf("\nActive: %s.", play.arr[1].name);
    printf("\n%s", play.arr[1].desc);
    printf("\nUltimate: %s.", play.arr[2].name);
    printf("\n%s", play.arr[2].desc);
}

void copyChara(Chara *p, Chara play){
    makeChara(p, play.charID);
}

void useSkill(Chara* play, Chara* enemy, int skillID){
    if(skillID >= 0 && skillID < 3){
        if(play->arr[skillID].skillAtk.mana > play->mana || play->arr[skillID].skillDef.mana > play->mana){
            printf("Skill tidak bisa dipakai. Mana terlalu sedikit.");
        }
        else{
            switch(play->arr[skillID].skillAtk.effect)
                    case 'h':
                        play->HPBase += 200;
                    case 'b':
                        //effects here
                    case 'c':
                        play->shieldBase += 50;
                    case 'f':
                        enemy->HPBase -= 50;
                    case 's':
                        enemy->mana -= 50;
                    case 'l':
                        //luck
                    case 't':
                        play->shieldBase = 0;
                    case 'm':
                        enemy->HPBase -= 100;

            if(play->arr[skillID].skillAtk.damage != undef){
                if(enemy->shieldBase > 0){
                    enemy->shieldBase -= play->arr[skillID].skillAtk.damage*play->arr[skillID].skillAtk.count;
                    if(enemy->shieldBase < 0){
                        enemy->HPBase += enemy->shieldBase;
                        enemy->shieldBase = 0;
                    }
                }
                else{
                    enemy->HPBase -= play->arr[skillID].skillAtk.damage*play->arr[skillID].skillAtk.count;
                }
                play->mana -= play->arr[skillID].skillAtk.mana;
            }
            if(play->arr[skillID].skillDef.shield != undef){
                play->shieldBase += play->arr[skillID].skillDef.shield*play->arr[skillID].skillDef.count;
                play->mana -= play->arr[skillID].skillDef.mana;
            }
            printf("\nSkill berhasil dipakai, mana yang tersisa: %d.\n", play->mana);
        }
    }
}

void recharge(Chara* play){
    play->mana += 100;
    printf("\nPengisian mana selesai.\n");
}

void atk(Chara play, Chara* enemy){
    if(enemy->shieldBase > 0){
        enemy->shieldBase -= play.atkBase;
        if(enemy->shieldBase <= 0){
            enemy->HPBase += enemy->shieldBase;
            enemy->shieldBase = 0;
            printf("\nSerangan menembus shield!\n");
        }
        else{
            printf("\nSerangan mengenai shield!\n");
        }
    }
    else{
        enemy->HPBase -= play.atkBase;
        printf("\nSerangan berhasil!\n");
    }
}
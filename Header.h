//
//  Header.h
//  CGame
//
//  Created by Eric on 16/7/22.
//  Copyright © 2016年 Bakantu Eric. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct science{
    double powdev;
    double lndcstdev;
    double sldfitdev;
    double sldadddev;
    double pdtratdev;
}scc;

typedef struct country {
    char *name;
    double store;
    double sldfight;
    unsigned int power;
    double lndcoast;
    double sldcoast;
    double sldadd;
    double pdtrat;
    int form;
    scc *p_scc;
    struct country *n_cty;
}cty;

typedef struct land {
    int x;
    int y;
    double people;
    double peoadd;
    double product;
    int soldiers;
    cty *belong;
    struct land *n_lnd;
}lnd;

//CONST
int lnd_num;
char *c_str[] = {"汉", "唐","元","明","清","宋","秦"};

/*Function*/

//MAJOR
lnd *initlnd(int num);
cty *initcty(int num, int *form);
int givelnd(cty *p_cty, lnd *p_lnd);
int lndpdt(lnd *p_lnd);
int lndpeo(lnd *p_lnd);
int sldadd(cty *p_cty, lnd *p_lnd, double rat);
int ctycst(lnd *p_lnd);
int conquer(lnd *pf_lnd, lnd *pt_lnd, int g_sld);
int sldmove(lnd *pf_lnd, lnd *pt_lnd, int g_sld);
int anlywin(lnd * p_lnd);
lnd *find_lnd(lnd *p_lnd,int x, int y);
int srhpow(cty *p_cty, lnd *p_lnd);
int mryfree(lnd *p_lnd, cty *p_cty);

//SCC
int fpowdev(cty *p_cty);
int flndcstdev(cty *p_cty);
int fsldfitdev(cty *p_cty);
int fpdtratdev(cty *p_cty);
int fpdtratdev(cty *p_cty);
int fladratdev(cty *p_cty);


//DECRIBE
lnd *initlnd(int num){
    srand((unsigned int)time(NULL));
    lnd *h_lnd = NULL, *pl_lnd = NULL;
    int x = 0, y = 0;
    for (int i = 0; i < num; i++){
        lnd *p_lnd = (lnd *) malloc(sizeof(lnd));
        if (h_lnd == NULL){
            h_lnd = p_lnd;
            pl_lnd = h_lnd;
            p_lnd->n_lnd = NULL;
        }
        else{
            pl_lnd->n_lnd = p_lnd;
            p_lnd->n_lnd = NULL;
            pl_lnd = p_lnd;
        }
        p_lnd->people = rand()%200+500;
        p_lnd->peoadd = (rand()%10+1)*0.001;
        p_lnd->belong = NULL;
        p_lnd->product = rand()%6+3;
        p_lnd->soldiers = 0;
        p_lnd->x = x;
        p_lnd->y = y++;
        if(!(rand()%2)){
            x++;
            y = 0;
        }
    }
    return h_lnd;
}

cty *initcty(int num, int *form){
    cty *h_cty = NULL, *pl_cty = NULL;
    for (int i = 0; i < num; i++){
        cty *p_cty = (cty *) malloc(sizeof(cty));
        p_cty->p_scc = (scc *) malloc(sizeof(scc));
        if (h_cty == NULL){
            h_cty = p_cty;
            pl_cty = p_cty;
            p_cty->n_cty = NULL;
        }
        else{
            pl_cty->n_cty = p_cty;
            p_cty->n_cty = NULL;
            pl_cty = p_cty;
        }
        p_cty->form = form[i];
        p_cty->store = 0.0;
        if (!form[i]){
            p_cty->sldadd = 0.2;
            p_cty->sldcoast = 2.5;
            p_cty->power = 6;
            p_cty->lndcoast = 0.8;
            p_cty->pdtrat = 0.4;
            p_cty->sldfight = 1;
            p_cty->p_scc->lndcstdev = 1100;
            p_cty->p_scc->sldfitdev = 1150;
            p_cty->p_scc->pdtratdev = 1200;
            p_cty->p_scc->powdev = 1000;
            p_cty->p_scc->sldadddev = 1010;
            
        }
        else{
            p_cty->sldadd = 0.1;
            p_cty->sldcoast = 4.5;
            p_cty->power = 3;
            p_cty->lndcoast = 2.6;
            p_cty->pdtrat = 0.7;
            p_cty->sldfight = 2;
            p_cty->p_scc->lndcstdev = 800;
            p_cty->p_scc->sldfitdev = 850;
            p_cty->p_scc->pdtratdev = 850;
            p_cty->p_scc->powdev = 1200;
            p_cty->p_scc->sldadddev = 1010;

        }
        
        p_cty->name = c_str[i];
        
        
    }
    return h_cty;
}

int lndpdt(lnd *p_lnd){
    while (p_lnd != NULL){
        if (p_lnd->belong != NULL){
            p_lnd->belong->store += p_lnd->people * p_lnd->product * p_lnd->belong->pdtrat;
        }
        p_lnd = p_lnd->n_lnd;
    }
    return 0;
}



int givelnd(cty *h_cty, lnd *h_lnd){
    cty *p_cty = h_cty;
    lnd *p_lnd = h_lnd;
    //Give lnad
    while(p_cty != NULL){
        for(int i = 0; i < (rand()%(lnd_num-1))+1;i++) p_lnd = p_lnd->n_lnd;
        p_lnd->belong = p_cty;
        p_cty = p_cty->n_cty;
    }
    return 0;
}

int lndpeo(lnd *p_lnd){
    while (p_lnd != NULL) {
        p_lnd->people += p_lnd->people * p_lnd->peoadd;
        p_lnd = p_lnd->n_lnd;
    }
    return  0;
}

int sldadd(cty *p_cty, lnd *p_lnd, double rat){
    if (p_lnd->belong == p_cty && rat <= p_cty->sldadd){
        p_lnd->soldiers += p_lnd->people * rat;
        p_lnd->people -= p_lnd->people * rat;
    }
    else return -1;
    return 0;
}

int ctycst(lnd *p_lnd){
    while(p_lnd != NULL){
        if (p_lnd->belong != NULL){
            cty *p_cty = p_lnd->belong;
            p_cty->store -= p_cty->lndcoast * p_lnd->people + p_cty->sldcoast * p_lnd->soldiers;
        }
        p_lnd = p_lnd->n_lnd;
    }
    return 0;
}

int conquer(lnd *pf_lnd, lnd *pt_lnd, int g_sld){
    if (pf_lnd ->belong != NULL && g_sld <= pf_lnd->soldiers){
        pf_lnd->soldiers -= g_sld;
        if (pt_lnd->belong == NULL){
            pt_lnd->belong = pf_lnd->belong;
            pt_lnd->soldiers = g_sld;
        }
        else{
            if(g_sld * pf_lnd->belong->sldfight > pt_lnd->soldiers * pt_lnd->belong->sldfight){
                pt_lnd->belong = pf_lnd->belong;
                pt_lnd->soldiers = (g_sld * pf_lnd->belong->sldfight - pt_lnd->soldiers * pt_lnd-> belong->sldfight)
                                    / pf_lnd->belong->sldfight;
            }
            else if (g_sld * pf_lnd->belong->sldfight < pt_lnd->soldiers * pt_lnd->belong->sldfight){
                pt_lnd->soldiers = (pt_lnd->soldiers * pt_lnd->belong->sldfight - g_sld * pf_lnd->belong->sldfight)
                                    / pt_lnd->belong->sldfight;
            }
            else{
                pt_lnd->belong = NULL;
                pt_lnd->soldiers = 0;
            }
        }

    }
    else return -1;
    return  0;
}

int sldmove(lnd *pf_lnd, lnd *pt_lnd, int g_sld){
    if (pf_lnd->belong != NULL && pt_lnd ->belong != NULL && g_sld <= pf_lnd->soldiers){
        
        pf_lnd->soldiers -= g_sld;
        pt_lnd->soldiers += g_sld;
    }
    else return -1;
    return 0;
}

int fpowdev(cty *p_cty){
    double cost = sqrt( 2* p_cty->p_scc->powdev * p_cty->p_scc->powdev);
    if (p_cty->store >= cost){
        p_cty->store -= cost;
        p_cty->power = (double) p_cty->power * 1.5;
        p_cty->p_scc->powdev = cost;
    }
    else return -1;
    return  0;
}

int flndcstdev(cty *p_cty){
    double cost = sqrt( 2* p_cty->p_scc->lndcstdev * p_cty->p_scc->lndcstdev);
    if (p_cty->store >= cost){
        p_cty->store -= cost;
        p_cty->lndcoast = (double) p_cty->lndcoast * 0.85;
        p_cty->p_scc->lndcstdev = cost;
    }
    else return -1;
    return 0;
}

int fsldfitdev(cty *p_cty){
    double cost = sqrt(2 * p_cty->p_scc->sldfitdev * p_cty->p_scc->sldfitdev);
    if (p_cty->store >= cost){
        p_cty->store -= cost;
        p_cty->sldfight = (double) p_cty->sldfight * 1.25;
        p_cty->sldcoast = (double) p_cty->sldcoast * 1.35;
        p_cty->p_scc->sldfitdev = cost;
    }
    else return -1;
    return 0;
}

int fpdtratdev(cty *p_cty){
    double cost = sqrt( 2* p_cty->p_scc->pdtratdev * p_cty->p_scc->pdtratdev);
    if (p_cty->store >= cost){
        p_cty->store -= cost;
        p_cty->pdtrat = (double) p_cty->pdtrat * 1.15;
        p_cty->p_scc->pdtratdev = cost;
    }
    else return -1;
    return 0;
}

int anlywin(lnd * p_lnd){
    
    return 0;
}

lnd *find_lnd(lnd *p_lnd,int x, int y){
    
    while (p_lnd != NULL) {
        if (p_lnd->x == x && p_lnd->y == y) return p_lnd;
        p_lnd = p_lnd->n_lnd;
    }
    return NULL;
}

int fladratdev(cty *p_cty){
    double cost =  sqrt( 2 * p_cty->p_scc->sldadddev * p_cty->p_scc->sldadddev);
    if (p_cty->store >= cost && p_cty->sldadd < 1){
        p_cty->store -= cost;
        p_cty->sldadd = p_cty->sldadd * 1.15;
        p_cty->p_scc->sldadddev = cost;
    }
    else return -1;
    return 0;
}

int srhpow(cty *p_cty, lnd *p_lnd){
    int num = 0;
    while (p_lnd != NULL){
        if (p_lnd->belong == p_cty) num++;
        p_lnd = p_lnd->n_lnd;
    }
    return num;
}

int mryfree(lnd *p_lnd, cty *p_cty){
    while (p_lnd != NULL){
        free(p_lnd);
        p_lnd = p_lnd->n_lnd;
    }
    while (p_cty != NULL){
        free(p_cty);
        p_cty = p_cty->n_cty;
    }
    return 0;
}

#endif /* Header_h */

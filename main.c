//
//  main.c
//  CGame
//
//  Created by Eric on 16/7/22.
//  Copyright © 2016年 Bakantu Eric. All rights reserved.
//

#include "Header.h"
//#include "Opengl.h"
#include "Order.h"
#include "Keyboard.h"



int main(int argc, const char * argv[]) {
    int *form = (int *) malloc(sizeof(int) * 3);
    lnd *p_lnd = initlnd(10);
    form[0] = 0;
    form[1] = 0;
    form[2] = 1;
    cty *p_cty = initcty(3, form);
    char ch;
    givelnd(p_cty, p_lnd);
    init_keyboard();
    while (ch != 'q') {
        ch = ' ';
        system("clear");
        printf("MAP:\n");
        show_map(p_lnd);
        printf("----------------------------------------------\n");
        printf("国家信息：\n");
        printf("国号：%s\n",p_cty->name);
        printf("国库：%lf\n",p_cty->store);
        if (!p_cty->form) printf("国家体制：社会主义\n");
            else printf("国家体制：资本主义\n");
        printf("土地花费:%.2lf\n",p_cty->lndcoast);
        printf("土地升级花费:%.2lf\n",sqrt(2*p_cty->p_scc->lndcstdev*p_cty->p_scc->lndcstdev));
        printf("生产效率:%.2lf\n",p_cty->pdtrat);
        printf("生产效率升级花费:%.2lf\n",sqrt(2*p_cty->p_scc->pdtratdev*p_cty->p_scc->pdtratdev));
        printf("士兵花费:%.2lf\n",p_cty->sldcoast);
        printf("士兵战斗力:%.2lf\n",p_cty->sldfight);
        printf("士兵升级花费:%.2lf\n",sqrt(2*p_cty->p_scc->sldfitdev*p_cty->p_scc->sldfitdev));
        printf("最大征兵百分比:%.2lf\n",p_cty->sldadd);
        printf("最大征兵百分比升级花费:%.2lf\n",sqrt(2*p_cty->p_scc->sldadddev*p_cty->p_scc->sldadddev));
        printf("权力值:%d\n",p_cty->power);
        printf("----------------------------------------------\n");
        printf("领土信息：\n");
        lnd *ps_lnd = p_lnd;
        while(ps_lnd != NULL){
            if(ps_lnd->belong == p_cty){
                printf("----------------------------\n");
                printf("坐标：(%d,%d)\n",ps_lnd->x,ps_lnd->y);
                printf("人口：%.0lf",ps_lnd->people);
                printf("人口增长率： %.3lf ",ps_lnd->peoadd);
                printf("生产力： %.2lf",ps_lnd->product);
                printf("兵力：%d\n",ps_lnd->soldiers);
                printf("\n");
            }
            ps_lnd = ps_lnd->n_lnd;
        }
        if(kbhit()){
            ch = readch();
            switch (ch) {
                case 'c':
                    close_keyboard();
                    fflush(stdin);
                    o_conquer(p_lnd,p_cty);
                    init_keyboard();
                    break;
                case 'm':
                    close_keyboard();
                    fflush(stdin);
                    o_movesld(p_lnd, p_cty);
                    init_keyboard();
                    break;
                case 'a':
                    close_keyboard();
                    fflush(stdin);
                    o_sldadd(p_lnd, p_cty);
                    init_keyboard();
                    break;
                case 'p':
                    fpdtratdev(p_cty);
                    printf("PDT\n");
                    break;
                case 'f':
                    fsldfitdev(p_cty);
                    printf("SLDCST\n");
                    break;
                case 'l':
                    flndcstdev(p_cty);
                    printf("LNDCST\n");
                    break;
                case 'o':
                    fpowdev(p_cty);
                    printf("POWDEV\n");
                    break;
                case 'r':
                    fladratdev(p_cty);
                    printf("SLDADD\n");
                    break;
                default:
                    break;
            }
        }
        lndpdt(p_lnd);
        lndpeo(p_lnd);
        ctycst(p_lnd);
        usleep(1500000);
    }
    free(form);
    mryfree(p_lnd, p_cty);
    return 0;
}


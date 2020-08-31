//
//  Order.h
//  CGame
//
//  Created by Eric on 16/7/23.
//  Copyright © 2016年 Bakantu Eric. All rights reserved.
//

#ifndef Order_h
#define Order_h

int show_map(lnd *p_lnd);
int o_conquer(lnd *p_lnd, cty *p_cty);
int o_sldadd(lnd *p_lnd, cty *p_cty);
int o_movesld(lnd *p_lnd, cty *p_cty);


int show_map(lnd *p_lnd){
    int m_x = p_lnd->x;
    while (p_lnd != NULL){
        if (m_x == p_lnd->x) {
            if (p_lnd->belong != NULL)  printf (" $#$ 人口: %.0f 产能t: %.2f 属于:%s $#$ ",p_lnd->people,p_lnd->product,p_lnd->belong->name);
            else printf (" $#$ 人口: %.0f 产能t: %.2f 属于: 空 $#$ ",p_lnd->people,p_lnd->product);
           
        }
        else{
            m_x = p_lnd->x;
            printf("\n");
            if (p_lnd->belong != NULL)  printf (" $#$ 人口: %.0f 产能t: %.2f 属于:%s $#$ ",p_lnd->people,p_lnd->product,p_lnd->belong->name);
            else printf (" $#$ 人口: %.0f 产能t: %.2f 属于: 空 $#$ ",p_lnd->people,p_lnd->product);        }
        p_lnd = p_lnd->n_lnd;
        }
    printf("\n");
    return 0;
}

int o_conquer(lnd *p_lnd, cty *p_cty){
    int b_x,b_y,d_x,d_y,snum;
    printf("clear");
    printf("-----------------------------------------------------------------\n");
    printf("请输入本土坐标：(x)");
    scanf("%d",&b_x);
    printf("请输入本土坐标：(y)");
    scanf("%d",&b_y);
    printf("请输入敌坐标：(x)");
    scanf("%d",&d_x);
    printf("请输入敌坐标：(y)");
    scanf("%d",&d_y);
    printf("请输入投入兵力：");
    scanf("%d",&snum);
    printf("-----------------------------------------------------------------\n");
    fflush(stdin);
    lnd *b_lnd, *d_lnd;
    b_lnd = find_lnd(p_lnd, b_x, b_y);
    d_lnd = find_lnd(p_lnd, d_x, d_y);
    if (srhpow(p_cty,p_lnd) < p_cty->power)
        if (d_x == b_x+1 || d_x == b_x-1 || d_x == b_x)
            if (d_y == b_y +1 || d_y == b_y-1 || d_y == b_y)
                if (b_lnd != NULL && p_lnd != NULL && snum >= 75){
                    if (!conquer(b_lnd, d_lnd, snum)) printf("占领目标成功\n");
                    getchar();
                }
    
    return 0;
}

int o_sldadd(lnd *p_lnd, cty *p_cty){
    int x, y;
    lnd *ps_lnd;
    double rat = 0;
    printf("------------------------------------------------------------------\n");
    printf("输入征兵土地坐标：(x)");
    scanf("%d",&x);
    printf("输入征兵土地坐标：(y)");
    scanf("%d",&y);
    printf("输入征兵率：");
    scanf("%lf",&rat);
    printf("------------------------------------------------------------------\n");
    fflush(stdin);
    ps_lnd = find_lnd(p_lnd, x, y);
    if (p_cty == ps_lnd->belong) {
        if(!sldadd(ps_lnd->belong, ps_lnd, rat)) printf("征兵成功！\n");
        getchar();
    }
    return 0;
}

int o_movesld(lnd *p_lnd, cty *p_cty){
    int f_x, f_y, d_x, d_y, snum;
    lnd *pf_lnd, *pt_lnd;
    printf("------------------------------------------------------------------\n");
    printf("输入出发土地坐标：(x)");
    scanf("%d",&f_x);
    printf("输入出发土地坐标：(y)");
    scanf("%d",&f_y);
    printf("输入目的土地坐标：(x)");
    scanf("%d",&d_x);
    printf("输入目的土地坐标：(y)");
    scanf("%d",&d_y);
    printf("请输入兵力：");
    scanf("%d",&snum);
    printf("------------------------------------------------------------------\n");
    fflush(stdin);
    pf_lnd = find_lnd(p_lnd, f_x, f_y);
    pt_lnd = find_lnd(p_lnd, d_x, d_y);
    if (p_cty == pf_lnd->belong && p_cty == pt_lnd->belong){
        if (!sldmove(pf_lnd, pt_lnd, snum)) printf("移动兵力成功！\n");
        getchar();
    }
    return 0;
}


#endif /* Order_h */

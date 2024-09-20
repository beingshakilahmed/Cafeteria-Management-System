#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	float data;
	char foodname[50];
	int quantity;
	float price;
    struct node *next;
}node;
typedef struct head
{
    node *start;
}head;
void insertend(head *t, float data, char foodname[25], int quantity, float price)
{
    node *p, *q;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->quantity=quantity;
    p->price=price;
    strcpy(p->foodname, foodname);
    p->next=NULL;
    if(t->start==NULL)
    {
        t->start=p;
    }
    else
    {
        q=t->start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
void foodlist(head *t)
{
	printf("\n\t");
	printf("-------------------------------------------------------");
	printf("\n\t");
	printf("       Food Code          Name          Price          ");
	printf("\n\t");
	printf("-------------------------------------------------------");
	node *p;
    p=t->start;
    while(p!= NULL)
    {
        printf("\n\t");
        printf("  %0.1f   |  %-25s     |    %0.2f   ",p->data,p->foodname,p->price);
		printf("\n\t");
        printf("-------------------------------------------------------");
        p=p->next;
    }
}
void foodlist1(head *t)
{
	printf("\n\t");
	printf("-------------------------------------------------------------------");
	printf("\n\t");
	printf("  Food Code            Name            Quantity            Price   ");
	printf("\n\t");
	printf("-------------------------------------------------------------------");
	node *p;
    p=t->start;
    while(p!= NULL)
    {
		printf("\n\t");
        printf("  %0.1f   |  %-25s      |    %2d      |  %0.2f   ",p->data,p->foodname, p->quantity, p->price);
		printf("\n\t");
		printf("------------------------------------------------------------------");
        p=p->next;
    }
}
float getbill(head *t)
{
    node *p;
    float b=0;
    p=t->start;
    while(p!=NULL)
    {
        b=b+p->price;
        p=p->next;
    }
    return b;
}
void order(head *t, head *l, float fc, int qty)
{
    node *p;
    p=t->start;
    while(p->data!=fc)
    {
        p=p->next;
    }
    insertend(l, fc, p->foodname, qty, (p->price*qty));
    return;
}
void cls()
{
    system("cls");
}
void main()
{
    head x, s, m, d, o;
    x.start=s.start=m.start=d.start=o.start=NULL;
    float fcode;
    int qty, lo;
    insertend(&s, 1.1, "Sub Sandwich", 1, 70);
    insertend(&s, 1.2, "Cheese Sandwich", 1, 100);
    insertend(&s, 1.3, "Sub Burger", 1, 80);
    insertend(&s, 1.4, "Chicken Burger", 1, 120);
    insertend(&s, 1.5, "BBQ Chicken Roll", 1, 150);
    insertend(&m, 2.1, "Chicken Biryani", 1, 100);
    insertend(&m, 2.2, "Mutton Chap", 1, 250);
    insertend(&m, 2.3, "Beef Chap", 1, 200);
    insertend(&m, 2.4, "Chicken Pizza", 1, 250);
    insertend(&m, 2.5, "Mutton Pizza", 1, 300);
    insertend(&d, 3.1, "Chocolate Milk Shake", 1, 120);
    insertend(&d, 3.2, "Oreo Milk Shake", 1, 150);
    insertend(&d, 3.3, "Chocolate Cake", 1, 50);
    insertend(&d, 3.4, "Orange Juice", 1, 80);
    insertend(&d, 3.5, "Cold Coffee", 1, 100);
    char uid[20], pwd[20], uid1[20], pwd1[20], c=' ', k=' ';
    int i=0, ch;
    while(1)
    {
        cls();
mainscr: printf("\n\nEnter Choice: \n 1. Login \n 2. New User \n 3. Exit \n ");
        scanf("%d", &ch);
        if(ch==3)
            break;
        if(ch==2)
        {
            printf(" \n\n                  ENTER USERNAME:-");
            scanf("%s", &uid1);
            printf(" \n\n                  ENTER PASSWORD:-");
            while(i<20)
            {
                pwd1[i]=getch();
                c=pwd1[i];
                if(c=='\r') break;
                else printf("*");
                i++;
            }
            pwd1[i]='\0';
            printf("\n\n            Registered Successfully!!\n");
            Sleep(2000);
        }
        else
        {
            printf("\n  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  ");
            printf(" \n\n                  ENTER USERNAME:-");
            scanf("%s", &uid);
            printf(" \n\n                  ENTER PASSWORD:-");
            c=' '; i=0;
            while(i<20)
            {
                pwd[i]=getch();
                c=pwd[i];
                if(c=='\r') break;
                else printf("*");
                i++;
            }
            pwd[i]='\0';
            if(strcmp(uid,uid1)==0&&strcmp(pwd,pwd1)==0)
            {
                printf("\n\n            LOGIN SUCCESFULL!!");
                Sleep(2000);
                cls();
                int i, ch;
      mainmenu: printf("Enter Choice: \n 1. View Menu \n 2. View Previous Order \n 3. Log Out \n");
                scanf("%d", &ch);
                if(ch==2)
                {
                    if(o.start==NULL)
                    {
                        printf("Previous Order Does Not Exist!!\n");
                        Sleep(2000);
                        cls();
                        goto mainmenu;
                    }
                    else
                    {
                        cls();
                        foodlist1(&o);
                        printf("\nPress 0 To Continue...\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            goto mainmenu;
                        }
                    }
                }
                else if(ch==1)
                {
             order: printf("Enter Choice:\n");
                    printf("1. Snacks \n 2. Main Course \n 3. Dessert \n ");
                    scanf("%d", &ch);
                    while(1){
                    switch(ch)
                    {
                        case 1: foodlist(&s);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity Of Food:\n");
                                scanf("%d", &qty);
                                order(&s, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 2: foodlist(&m);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity Of Food:\n");
                                scanf("%d", &qty);
                                order(&m, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 3: foodlist(&d);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity Of Food:\n");
                                scanf("%d", &qty);
                                order(&d, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        default: printf("Invalid Choice!!\n");
                    }
        afterorder: printf("\n\n");
                    printf("\n\t\tEnter Choice: \n\t\t 1. Hungry For More? \n\t\t 2. View Order \n\t\t 3. Confirm Order? \n");
                    scanf("%d", &ch);
                    if(ch==1)
                    {
                        cls();
                        goto order;
                    }
                    else if(ch==2)
                    {
                        cls();
                        printf("Current Order:\n");
                        foodlist1(&o);
                        goto afterorder;
                    }
                    else if(ch==3)
                    {
                        cls();
                        foodlist1(&o);
                        printf("\nTotal Amount To Pay: %0.2f\n", getbill(&o));
                        printf("\nEnjoy Your Meal!!\n");
                        printf("\nPress 0 To Continue...\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            cls();
                            goto mainmenu;
                        }
                    }
                }
                }
                else if(ch==3)
                {
                    cls();
                    goto mainscr;
                }
                else
                    printf("\nInvalid Choice!!\n");
            }
            else if(strcmp(uid,"user")==0&&strcmp(pwd,"user123")==0)
            {
                printf("\n\n        !! WELCOME USER !!");
                Sleep(3000);
                cls();
                int adch;
        admin:  printf("\n\n           Enter Choice:\n");
                printf("            1. View Menu\n");
                printf("            2. Update Menu\n");
                printf("            3. View Recent Order\n");
                printf("            4. Log Out\n");
                scanf("%d", &adch);
                cls();
                if(adch==4)
                    goto mainscr;
                switch(adch)
                {
                    case 1:cls();
                        printf("\nSNACKS:\n");
                        foodlist(&s);
                        Sleep(3000);
                        printf("\nMAIN COURSE:\n");
                        foodlist(&m);
                        Sleep(3000);
                        printf("\nDESSERT:\n");
                        foodlist(&d);
                        printf("\nPress 0 To Continue...\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                        }
                        break;
                    case 3:
                        cls();
                        printf("Recent Order:\n");
                        foodlist1(&o);
                        printf("\nPress 0 To Continue...\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            goto admin;
                        }
                        break;
                    case 2:
                        cls();
                        float fcu, pu;
                        char fnameu[50];
                        printf("UPDATE MENU\n");
                        printf("What Do You Want To Update?\n");
                        printf("Enter Choice:\n");
                        printf("1. Snacks \n 2. Main Course \n 3. Dessert \n");
                        scanf("%d", &ch);
                        switch(ch)
                        {
                            case 1: printf("\nEnter Food Code:\n");
                                    scanf("%f", &fcu);
                                    printf("\nEnter Food Name:\n");
                                    scanf("%s", &fnameu);
                                    printf("\nEnter Price:\n");
                                    scanf("%f", &pu);
                                    insertend(&s, fcu, fnameu, 1, pu);
                                    printf("\nMENU UPDATED\n");
                                    foodlist(&s);
                                    break;
                            case 2: printf("\nEnter Food Code:\n");
                                    scanf("%f", &fcu);
                                    printf("\nEnter Food Name:\n");
                                    scanf("%s", &fnameu);
                                    printf("\nEnter Price:\n");
                                    scanf("%f", &pu);
                                    insertend(&m, fcu, fnameu, 1, pu);
                                    printf("\nMENU UPDATED\n");
                                    foodlist(&m);
                                    break;
                            case 3: printf("\nEnter Food Code:\n");
                                    scanf("%f", &fcu);
                                    printf("\nEnter Food Name:\n");
                                    scanf("%s", &fnameu);
                                    printf("\nEnter Price:\n");
                                    scanf("%f", &pu);
                                    insertend(&d, fcu, fnameu, 1, pu);
                                    printf("\nMENU UPDATED\n");
                                    foodlist(&d);
                                    break;
                        }
                        goto admin;
                        break;
                default:printf("\nInvalid Choice!!\n");
                }
            }
            else
            {
                printf("\n\n        INCORRECT USERNAME OR PASSWORD!!");
                Sleep(2000);
            }
    }
}
}

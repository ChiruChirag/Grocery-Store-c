#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void viewMenu();
void purchase();
void login();



struct stock
    {
        char name[20];
        int price;
        int code;
        int qty;

    };
struct stock item[50];
int n, i, qty,code1 ;

struct details
    {
        char name[20];
        int price;
        int code;
        int qnty;
    };
    struct details things[50];


int main()
{
	login();
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");	
	printf("\t available products");
	printf("\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	viewMenu();
    purchase();
    return 0;
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="lab";
	   char user2[10]="dan";
	   char pass2[10]="333";
    char pass[10]="123";
    do
	{
	   
    printf("\n  ++++++++++++++++++++++++++++++  LOGIN PORTAL  ++++++++++++++++++++++++++++++  ");
    printf(" \n\n                  ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n\n                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
    pword[i]='\0';
	
    i=0;
	if((strcmp(uname,"lab")==0 && strcmp(pword,"123")==0) || (strcmp(uname,"dan")==0 && strcmp(pword,"333")==0))
	{
 
	printf("  \n\n\n       WELCOME TO ABC MART");
	printf("\n\n\n\t\t\t\tPress any key to continue...\n\n\n\n");
	getch();//holds the screen
	break;
	}
	else if(strcmp(uname,"dan")==0 && strcmp(pword,"333")==0)
	{
 
	printf("  \n\n\n       WELCOME TO PESU MART");
	printf("\n\n\n\t\t\t\tPress any key to continue...\n\n\n\n");
	getch();//holds the screen
	break;
	}

	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
	}	

	}while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");
		
		getch();
		exit(0);
		
	}
	
}

void viewMenu()
{
    strcpy(item[0].name,"apples");
	item[0].price=50;
	item[0].code=0;
	strcpy(item[1].name,"Bananas");
	item[1].price=30;
	item[1].code=1;
	strcpy(item[2].name,"chocolates");
	item[2].price=20;
	item[2].code=2;
	strcpy(item[3].name,"Milkshake");
	item[3].price=30;
	item[3].code=3;
	strcpy(item[4].name,"coffee!");
	item[4].price=20;
	item[4].code=4;
    strcpy(item[5].name,"coke!");
	item[5].price=20;
	item[5].code=5;
	strcpy(item[6].name,"Poato chips");
	item[6].price=30;
	item[6].code=6;
	strcpy(item[7].name,"Ice creams");
	item[7].price=20;
	item[7].code=7;
	int n=8;
	printf("             **  INVENTORY ** \n");
    printf("-------------------------------------------------------------\n");
    printf("S.N.|    NAME             |  PRICE  |   CODE                 \n");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("%d     %-15s        %-d          %d    \n",i + 1,item[i].name,item[i].price,item[i].code);
} 

void purchase()
{
    

    printf("please choose the things you want to add to your shopping list from the above..\n\n\n");
    int a1;
    float total = 0;
	float ftotal=0;
    printf("enter the number of things you want to buy: \n");
    scanf("%d",&a1);
    for(int i=0;i<a1;i++)
    {
        if(i==0)
		{
			printf("please enter the %dst item code and the quantity of the item you want to buy: \n",i+1);
		}
		else if(i==1)
		{
			printf("please enter the %dnd item code and the quantity of the item you want to buy: \n",i+1);
		}
		else if(i==2)
		{
			printf("please enter the %drd item code and the quantity of the item you want to buy: \n",i+1);
		}
		else
		{
			printf("please enter the %dth item code and the quantity of the item you want to buy: \n",i+1);
		}
        scanf("%d %d",&code1,&qty);
		if(code1>7)
		{
			printf("you have entered wrong code of the item please enter the right code\n");
			
			
		}
		
		else
		{
			printf("you have chosen %d amount of  %s which costs %d \n\n",qty,item[code1].name,item[code1].price*qty);
            strcpy(things[i].name,item[code1].name);
         	things[i].price=item[code1].price*qty;
        	things[i].qnty=qty;
        	total=total+(qty*item[code1].price);
			ftotal=total+(total*9)/100;
        	code1=0;
            qty=0;
		}
		
		
    }
    printf("-------------------------------------------------------------\n");

    printf("S.N.|    NAME           | QUANTITY |  PRICE  |  \n");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < a1;i++)
    { 
        printf("%d     %-15s        %-d        %-5d      \n",i + 1,things[i].name,things[i].qnty,things[i].price);
    }
    printf("-------------------------------------------------------------\n");
    printf("Total---------------------------------%.2f----\n\n\n",total);
	printf("the tax percentage is %d (including GST)\n",9);
	printf("the tax amount is %.2f\n\n",(total*9)/100);
    printf("ftotal---------------------------------%.2f----\n\n\n",ftotal);

	
	printf("-------------------please enter the amount you are paying-----------------\n\n\n");
	
	float amount_paid;
	scanf("%f",&amount_paid);
	if(amount_paid>ftotal)
	{
		printf("please collect the change of %.2f\n\n\n",amount_paid-ftotal);
	}
	else if(amount_paid==ftotal)
	{
		printf("");
	}
	else
	{
		
		
	printf("you have paid %.2f rupees less than the ftotal amount please pay the due amount \n\n",ftotal-amount_paid);
	

	}

	printf("------------------thank you for purchasing please visit again and have a nice day--------\n\n");

}

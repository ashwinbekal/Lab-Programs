#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int coef,expox,expoy,expoz;
    struct node *link;
};
typedef struct node *NODE;

NODE createnode(int coef,int ex,int ey,int ez){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coef=coef;
    temp->expox=ex;
    temp->expoy=ey;
    temp->expoz=ez;
    temp->link=NULL;
    return temp;
}

NODE createheadnode(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coef=0;
    temp->expox=-1;
    temp->expoy=-1;
    temp->expoz=-1;
    temp->link=temp;
    return temp;
}

void insertrear(int coef,int ex,int ey,int ez,NODE head){
    NODE temp, cur;
    temp=createnode(coef,ex,ey,ez);
    if(head->link==head){
        head->link=temp;
    }
    else{
        cur=head;
        while(cur->link!=head){
            cur=cur->link;
        }
        cur->link=temp;
    }
    temp->link=head;
    head->coef=(head->coef)+1;
}

void createpoly(NODE poly){
    int i,n,coef,ex,ey,ez;
    printf("Enter the number of terms in the polynomial:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coefficient:\t");
        scanf("%d",&coef);
        printf("Enter the exponents of x, y and z:\t");
        scanf("%d%d%d",&ex,&ey,&ez);
        insertrear(coef,ex,ey,ez,poly);
    }
}

void display(NODE head){
    NODE cur;
    if(head->link==head){
        printf("List is Empty!");
    }
    else{
        cur=head->link;
        while(cur!=head){
            if(cur->coef<0){
                printf("(%d X^%d Y^%d Z^%d)",cur->coef,cur->expox,cur->expoy,cur->expoz);
            }
            else{
                printf("+(%d X^%d Y^%d Z^%d) ",cur->coef,cur->expox,cur->expoy,cur->expoz);
            }
            cur=cur->link;
        }
        printf("\nNumber of terms: %d\t",head->coef);
    }
}

double evaluate(int x,int y,int z,NODE head){
    double result=0;
    NODE cur;
    if(head->link==head){
        printf("The List is Empty!");
    }
    else{
        cur=head->link;
        while(cur!=head){
            result+=cur->coef*pow(x,cur->expox)*pow(y,cur->expoy)*pow(z,cur->expoz);
            cur=cur->link;
        }
    }
    return result;
}

NODE polyadd(NODE a,NODE b){
    NODE c,starta,startb;
    int sum=0;
    starta=a;
    startb=b;
    a=a->link;
    b=b->link;
    c=createheadnode();
    while((a!=starta)&&(b!=startb)){
        if((a->expox==b->expox)&&(a->expoy==b->expoy)&&(a->expoz==b->expoz)){
            sum=a->coef+b->coef;
            insertrear(sum,a->expox,a->expoy,a->expoz,c);
            a=a->link;b=b->link;
        }
        else if((a->expox==b->expox)&&(a->expoy>b->expoy)){
            insertrear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else if((a->expox==b->expox)&&(a->expoy>b->expoy)){
            insertrear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else if((a->expox==b->expox)&&(a->expoy==b->expoy)&&(a->expoz>b->expoz)){
            insertrear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else{
            insertrear(b->coef,b->expox,b->expoy,b->expoz,c);
            b=b->link;
        }
    }
    while(a!=starta){
        insertrear(a->coef,a->expox,a->expoy,a->expoz,c);
        a=a->link;
    }
    while(b!=startb){
        insertrear(b->coef,b->expox,b->expoy,b->expoz,c);
        b=b->link;
    }
    return c;
}

void main(){
    int x,y,z;
    double eval=0;
    NODE poly1=NULL,poly2=NULL,polysum=NULL;
    printf("Evaluation of the Polynomial:\n");
    poly1=createheadnode();
    createpoly(poly1);
    printf("The Polynomial is:\n");
    display(poly1);
    printf("Enter the values for x, y and z:\t");
    scanf("%d%d%d",&x,&y,&z);
    eval=evaluate(x,y,z,poly1);
    printf("Polynomial Evaluation Value = %.2f\n",eval);
    printf("Addition of 2 Polynomials:\n");
    poly1=NULL;
    poly1=createheadnode();
    createpoly(poly1);
    poly2=createheadnode();
    createpoly(poly2);
    printf("Polynomial 1 is:\n");
    display(poly1);
    printf("Polynomial 2 is:\n");
    display(poly2);
    polysum=polyadd(poly1,poly2);
    printf("Polynomial Sum is:\n");
    display(polysum);
}
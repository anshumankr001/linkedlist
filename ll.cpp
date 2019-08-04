#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
struct node { 
    int x;
    int y; 
    node* next; 
}; 
struct node* start = NULL;
int length()
{
    int i=0;
    if(start == NULL) return i;
    else
    {
        struct node* temp = start;
        while(temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
}
void AddFirst(int a, int b)
{
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node)); 
    temp->x = a;
    temp->y=b;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}
void DelFirst()
{
    struct node* temp = start;
    start = temp->next;
    free(temp);
}
void Del(int a, int b)
{
    struct node* temp=start;
    while(temp!= NULL)
    {
        if(temp->x == a && temp->y == b) break;
        temp = temp->next;
    }
    struct node* p = start;
    while(p->next != temp)
    {
        p = p->next;
    }
    p->next = temp->next;
    free(temp);
}
void Search(long d)
{
    struct node* temp = start;
    while(temp!= NULL)
    {
        long a = temp->x;
        long b = temp->y;
        if(sqrt(a*a + b*b <= d)) 
        {
            cout << "(" << a << "," << b << ")" << " ";
        }
    }
}
void Search(long a, long b)
{
    struct node* temp = start;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->x == a && temp->y == b) i++;
    }
    if(i==0) cout << "False";
    else cout << "true";
}
int main()
{
    int t=11;
    
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            int a, b;
            cin >>a>>b;
            AddFirst(a,b);
        }
        if(n==2)
        {
            DelFirst();
        }
        if(n==3)
        {
            int a, b;
            cin >>a>>b;
            Del(a,b);
        }
        if(n==4)
        {
            int d; cin >> d;
            Search(d);
            cout << endl;
        }
        if(n==5)
        {
            int a, b;
            cin >>a>>b;
            Search(a,b); cout << endl;
        }
        if(n==6)
        {
            long l=length();
            cout << l;
        }
    }
}

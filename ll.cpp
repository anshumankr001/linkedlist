#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct node { 
    int x;
    int y; 
    node* next; 
}; 
int length(struct node** start)
{

    int i=0;
    
    node* temp = *start;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
    
}
void AddFirst(int a, int b, struct node** start)
{
    node* temp;
    temp = new node(); 
    temp->x = a;
    temp->y=b;
    temp->next = NULL;
    if(*start == NULL)
    {
        *start = temp;
    }
    else
    {
        temp->next = *start;
        *start = temp;
    }
}
void DelFirst(struct node** start)
{
    node* temp = *start;
    *start = temp->next;
    free(temp);
}
void Del(int a, int b, struct node** start)
{
    node* temp = *start;
	node* prev = NULL; 
	while(temp!=NULL){
		if(temp->x==a && temp->y==b && prev!=NULL){
			prev->next = temp->next;
			free(temp);
		}
		else if(prev==NULL && temp->x==a && temp->y==b){
			DelFirst(start);
		}
		else{
			prev = temp;
			temp = temp->next;

		}
	}
}
void Search(int d, struct node** start)
{
    node* temp = *start;
    while(temp!= NULL)
    {
        int a = temp->x;
        int b = temp->y;
        if(sqrt(a*a + b*b <= d)) 
        {
            cout << "(" << a << "," << b << ")" << " ";
        }
        temp = temp->next;
    }
}
void Search(int a, int b, struct node** start)
{
    node* temp = *start;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->x == a && temp->y == b) i++;
        temp = temp->next;
    }
    if(i==0) cout << "False";
    else cout << "True";
}
int main()
{
    node* start = NULL;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            int a, b;
            cin >>a>>b;
            AddFirst(a,b,&start);
        }
        if(n==2)
        {
            DelFirst(&start);
        }
        if(n==3)
        {
            int a, b;
            cin >>a>>b;
            Del(a,b,&start);
        }
        if(n==4)
        {
            int d; cin >> d;
            Search(d,&start);
            cout << endl;
        }
        if(n==5)
        {
            int a, b;
            cin >>a>>b;
            Search(a,b,&start); cout << endl;
        }
        if(n==6)
        {
            long l=length(&start);
            cout << l << endl;
        }
    }
}

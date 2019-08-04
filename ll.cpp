#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
class node { 
public: 
    pair<long, long> data; 
    node* next; 
}; 
node* start = NULL;
long length()
{
    long i=0;
    if(start == NULL) return i;
    else
    {
        node* temp = start;
        while(temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
}
void AddFirst(long x, long y)
{
    pair<long, long> t = mp(x,y);
    node* temp = new node();
    temp->data = t;
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
    node* temp = start;
    start = temp->next;
    free(temp);
}
void Del(long x, long y)
{
    node* temp=start;
    while(temp!= NULL)
    {
        if(temp->data.f == x && temp->data.s == y) break;
    }
    node* p = start;
    while(p->next != temp)
    {
        p = p->next;
    }
    p->next = temp->next;
    free(temp);
}
void Search(long d)
{
    vector<long, long> a;
    node* temp = start;
    while(temp!= NULL)
    {
        long x = temp->data.f;
        long y = temp->data.s;
        if(sqrt(x*x + y*y <= d)) a.pb(mp(x,y));
    }
    for(int i=0; i<a.size(); i++)
    {
        cout << "(" << a[i].f << "," << a[i].s << ")" << " ";
    }
}
void Search(long x, long y)
{
    node* temp = start;
    int i=0;
    while(temp!=NULL)
    {
        if(temp->data.f == x && temp->data.s == y) i++;
    }
    if(i==0) cout << "False";
    else cout << "true";
}
int main()
{
    int t;
    cin >> t;
    while(t)
    {
        if(t==1)
        {
            long x, y;
            cin >>x>>y;
            AddFirst(x,y);
        }
        if(t==2)
        {
            DelFirst();
        }
        if(t==3)
        {
            long x, y;
            cin >>x>>y;
            Del(x,y);
        }
        if(t==4)
        {
            long d; cin >> d;
            Search(d);
            cout << endl;
        }
        if(t==5)
        {
            long x, y;
            cin >>x>>y;
            Search(x,y); cout << endl;
        }
        if(t==6)
        {
            long l=length();
            cout << l;
        }
    }
}

#include <iostream>
#include <cstdlib>

using namespace std;

struct node{ 			//link list
	int data;
	node* next;
}*start,*newptr,*ptr,*end;


node *createNode(int);
void display(node*);

void addBegin(node*);	//add elements in the beginning
void addEnd(node*);		//add elements at the end of the list
void insertPos(int,node*);	//adds an element at a particular position

void deleteEnd();	//deletes the last element
void deleteStart();	//deletes the first element
void deletePos(int);	//deletes a particular element

int findPos(node*,int,int);

int main()
{	start = NULL;
	end = NULL;
	char choice;
	do{
	cout<<"enter a number"<<endl;
	int num,ch;
	cin>>num;
	
	newptr = createNode(num);
	
	cout<<"where do you want to add this number\n1)Starting of the list\n2)End of the list\n3)Delete from beginning\n4)Delete from the end";
	cout<<"\n5)Insertion at a particular position\n6)Delete an element at a particular position\n7)search"<<endl;
	cin>>ch;

	switch(ch){
		case 1:
			addBegin(newptr);
			display(start);
			break;
		case 2:
			addEnd(newptr);
			display(start);
			break;	
		case 3:
			deleteStart();
			display(start);	
			break;
		case 4:
			deleteEnd();
			display(start);
			break;	
		case 5:
			cout<<"enter the position where you want to add the new node : ";
			int pos;
			cin>>pos;
			insertPos(pos,newptr);
			display(start);
			break;	
		case 6:
			cout<<"enter the position : ";
			cin>>pos;
			deletePos(pos);
			display(start);
			break;	
		case 7:
			cout<<"enter the element that you want to search : ";
			int elem;
			cin>>elem;
			node* find = new node;
			find = start;
			int result = findPos(find,elem,1);
			if(result == 0){
				cout<<"element not found "<<endl;
			}
			else{
				cout<<"element found at "<<result<<" index"<<endl;
			}
			break;
		//case 8:
		//cout<<"enter 2 elements that you want to swap";	
			
	}
	cout<<"do you want to continue? : ";
	cin>>choice;
	system("cls");
	cout<<"current list : ";
	display(start);
	cout<<"-----------------------"<<endl;
	}while(choice=='y');
	
}

node *createNode(int n)
{
	ptr = new node;
	ptr->data = n;
	ptr->next = NULL;
	return ptr;
}

void addBegin(node*np)
{
	if(start == NULL){
		end = start = np;
	}
	else{
		np->next = start;
		start = np;
	}
}
void display(node*np)
{
	while(np !=NULL){
	
	cout<<np->data<<"->";
	np = np->next;
	}
	cout<<endl;
}
void addEnd(node *np)
{
	if(start==NULL){
		start = end = np;
		
	}
	else{
		end->next = np;
		end = np;
		np->next = NULL;
	}
}
void deleteStart()
{
	if(start==NULL)
		cerr<<"No element in the list "<<endl;
	else{
	
	node *delPtr;
	delPtr = start;
	start = start->next;
	delete delPtr;
	}
}

void deleteEnd()
{
	node *current = new node;
	node *previous = new node;
	current = start;
	
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	end = previous;
	previous->next = NULL;
	delete current;
}

void insertPos(int pos,node* np)
{	node* prev = new node;
	node* current = new node;
	
	current = start;
	for(int i=1;i<pos;i++){
		prev = current;
		current = current->next;
	}
	prev->next = np;
	np->next = current;
}

void deletePos(int pos)
{
	node *current = new node;
	node *prev = new node;
	
	current = start;
	for(int i=1;i<pos;i++){
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	delete current;
}

int findPos(node* current,int element,int pos)
{	if(current == NULL){
		return 0;
	}
	if(current->data == element){
		return pos;
	}
	else{
		pos++;
		return findPos(current->next,element,pos);
	}
}

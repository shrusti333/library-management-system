#include <stdio.h>
struct book{
int books_id;
	char b_name[20];
	char a_name[20];
	char s_name[20];
	char add[20];
	int days;
	int yr;
}m;
void welcome(); // to display the welcome screen

void mainmenu(); // to display the main menu
void add_books(); // to display the add books screen

void edit_books(); // to display the edit function
void search_books(); // to display the search function
void view_books();// too display the view books function

void main(){
	
welcome();
	mainmenu();
}
void welcome(){printf("\t\t\t\t\t******welcome******\n\t\t\t\t\t******to the ******\n\t\t\t\t\t**library management**\n\t\t\t\t\t******system******\n");
	printf("\n\t\tPress any key to go to mainmenu.....");
		getch();
}

//main menu//

void mainmenu()
	{
		int choice;
		
		printf("\n\n\t\t\t\tMAIN MENU\n\n");
		
		printf("\t\t\t\t1. Add Books\n");
		
		printf("\t\t\t\t2. Search Books\n");
	
		printf("\t\t\t\t3. View Books\n");
	
		printf("\t\t\t\t4. Edit Book's Record\n");
	
	
		printf("\t\t\t\t5. Close Application\n");

		printf("\t\t\t\t\tPlease Enter a choice:");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
				add_books();
				break;
				case 2:
			    search_books();
				break;
				case 3:
				view_books();
				break;
				case 4:
					edit_books();
				
				default:
					printf("application closed !!");
			}
}
//adding a book//		
void add_books()
{
	int days;
char answer;
	FILE *sfile;
	sfile = fopen("BookRecord.txt","a");
	printf("\n\t*******ADD NEW BOOKS************");
	printf("\n\t ENTER YOUR DETAILS BELOW:");

printf("book id");
scanf("%d",&m.books_id);

		printf("\n\t\tBook Name\t\t:");
	fflush(stdin);
		gets(m.b_name);
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		printf("\n\t\tStudent branch\t\t:");
		fflush(stdin);
		gets(m.add);
		printf("\n\t\tEnter Duration To Take Book");
		printf("\n\t\tMaximum [1-15] Days\t:");
		scanf("%i",&m.days);
	fprintf(sfile,"\n\t%d\t\t%s\t%s\t\t%s\t\t%s\t \t%i",m.books_id, m.b_name, m.a_name, m.s_name,m.add,m.days);
	fclose(sfile);
	printf("\n\t SUCCESFULLY RECORDED.\n");
	getch();
	
		printf("\n\t\tPress any key to go to mainmenu.....");
		mainmenu();
}
//search book//

void search_books()
{char c;
	int found=0;
	int id;
	FILE *sfile;

	sfile=fopen("BookRecord.txt","r");
	
	printf("\n\t\t***************** SEARCH BOOKS LIST*******************");
	
	printf("\nEnter Book id to search:");
	fflush(stdin);
	scanf("%d",&id);
	 
	printf("                                                                                     \n");
	printf("\tbook id     Book Name    Publication    Student Name   Student Address   Due Days");
	while(fscanf(sfile,"%i %s %s %s %s %i\n\n",&m.books_id, m.b_name, m.a_name, m.s_name, m.add, &m.days)!=EOF)
	{
		if(id==m.books_id)
		{
			found=1;
		;
			printf("\n\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t \t%i",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
			break;
		}
	}
		fclose(sfile);
		printf("\t\t\n\n\nPress any key to go to mainmenu.....");
		getch();
		mainmenu();
	
}
// view books function
void view_books()
{char c;
	
	FILE*sfile;
	
	sfile=fopen("BookRecord.txt","r");
	
	printf("\n\t\t\t**************** VIEW ALL BOOK RECORDS *****************");

	if(sfile==NULL)
	{
		printf("\n\n\t\t RECORD EMPTY");
		getch();
	}
	else
	{	
	printf("\n\tbook id   Book Name   Publication  Students Name   Students Address   Due Days\n");
		while((c=getc(sfile))!=EOF)
		{printf("%c",c);
		}
		printf("\n");
	printf("\n\n\t Press any key for main menu........");
	fclose(sfile);
	getch();
	mainmenu();
}}


// edit function
void edit_books()
{
	int i, found,target;
  char ch;
  int books_id;
  FILE *sfile, *modify;
  
  printf("\n\t\t*******Edit Books Details*******************");
 
   sfile=fopen("BookRecord.txt","rb+");
   if(sfile==NULL)
   {
   	
		printf("\n\t Can not open file!! ");
		getch();
		mainmenu();
   }

   printf("\tEnter Book ID NO. for edit:");
   scanf("%i",&target);
  
  
   	while(fscanf(sfile,"%i %s %s %s %s %i\n",&m.books_id,m.b_name,m.a_name,m.s_name,m.add,&m.days)!=EOF)
   	{
   		if(m.books_id==target)
   		{
   		
   			printf("\n\tBook ID NO.\t:%i\n\tBook Name\t:%s\n\tPublication\t:%s\n\tStudent Name\t:%s\n\tStudent Address\t:%s\n\tDue Days\t:%i\n",m.books_id,
			   															m.b_name,m.a_name,m.s_name,m.add,m.days);
			printf("\n\tEdit With New Records!");
   			printf("book id");
scanf("%d",&m.books_id);

		printf("\n\t\tBook Name\t\t:");
	fflush(stdin);
		gets(m.b_name);
		printf("\n\t\tPublication\t\t:");
		fflush(stdin);
		gets(m.a_name);
		printf("\n\t\tStudent Name\t\t:");
		fflush(stdin);
		gets(m.s_name);
		printf("\n\t\tStudent branch\t\t:");
		fflush(stdin);
		gets(m.add);
		printf("\n\t\tEnter Duration To Take Book");
		printf("\n\t\tMaximum [1-15] Days\t:");
		scanf("%i",&m.days);
				
			printf("\nPress 'U' to update and other key to cancel....!");
			ch=getche();
			if(ch=='u')
			{
				fprintf(sfile,"\n\t%d\t\t%s\t%s\t\t%s\t\t%s\t \t%i",m.books_id,m.b_name,m.a_name,m.s_name,m.add,m.days);
				fflush(stdin);
				printf("\n\nBooks has been updated......");}
	
	   fclose(sfile);
	

     	printf("\n\t\tPress any key to go to mainmenu.....");
     	getch();
	    mainmenu();
   
}
}}


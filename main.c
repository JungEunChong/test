#include "lib_members.h"
//#define DEBUG

void create_record();
void read_record();
void update_record();
void delete_record();
void list_record();
void sort_record();
void book_borrow();
void book_return(); 
void search_name();
void search_number();
void load_file();
void save_file();
void debug_records();

int main(){
   
	m_init();
    int menu;
    while(1){
        printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.List 6.Sort 7.borrow 8.return 9.Search(name) 10.Search(number) 11.load 12.save 0.Quit > ");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1: 
                create_record();
                break;
            case 2: 
                read_record();
                break;
            case 3: 
                update_record();
                break;
            case 4: 
                delete_record();
                break;
            case 5: 
                list_record();
                break;
	   	 	case 6:
				sort_record();
				break;
	    	case 7:
				book_borrow();	
				break;
	    	case 8:
				book_return();	
				break;
            case 9: 
                search_name();
                break;
            case 10: 
                search_number();
                break;
            case 11: 
                load_file();
                break;
            case 12: 
                save_file();
                break;
            case 13: 
                debug_records();
                break;
            case 0: 
            default: 
                return 0;
        }
    }
    return 0;
}

void create_record()
{
	if(! m_is_available())
	{
#ifdef DEBUG
		printf("[DEBUG] There is no space!\n ");
		return;
#endif
	}
	char name[20], phone[20], city[20];
	char birthyear[20];

	printf("Enter a new member's info.\n");
	printf("Name : ");
	scanf("%s", name);

	if(m_search_by_name(name))
	{
#ifdef DEBUG
		printf("[DEBUG] Duplicated name!\n");
		return;
#endif
	}

	printf("Birth year : ");
	scanf("%s", birthyear);
	printf("Phone number : ");
	scanf("%s", phone);
	printf("City : ");
	scanf("%s", city);

	m_create(name, phone, birthyear, city);

#ifdef DEBUG
	printf("\nRecord is created!\n");
#endif 
}


void read_record()
{
	char name[20];

    printf("Enter a name : ");
	scanf("%s", name);
	
	T_record* p = m_search_by_name(name);
	if(p)
	{
		 printf("%s's info.\n",m_getname(p));
		 printf("Name : %s\n", m_getname(p));
		 printf("Birth year : %s\n", m_getbirthyear(p));
		 printf("Phone number : %s\n", m_getphone(p));
		 printf("City : %s\n", m_getcity(p));
		 printf("%s's library number is %s\n",m_getname(p), m_getnumber(p));

#ifdef DEBUG
		 printf("\nRecord is read!\n");
#endif		 
	}
    else
	{
		printf("No such member!\n");
	 }
}

void update_record()
{

}

void delete_record()
{

}
void list_record()
{
	int size = m_count();

	T_record* records[MAX_MEMBERS];
	m_get_all(records);
#ifdef DEBUG
		printf("[DEBUG] all records are got\n\n");
#endif
	
	printf("All records.\n");
	for(int i=0; i<size; i++)
	{
		T_record* p = records[i];
		printf("%d. %s\n", i+1, m_to_string(p));
	}
}
void sort_record()
{

}
void book_borrow()
{

}
void book_return()
{

}
void search_name()
{

}
void search_number()
{

}
void load_file()
{
	printf("All data will be deleted and new records will be reloaded.\n");
	printf("1.Yes 0.No > ");
	int yesno;
	scanf("%d", &yesno);
	if (yesno == 0) return;
	m_init();   // delete all records 

	FILE* f = fopen("lib_members.txt", "r");
#ifdef DEBUG
	printf("file is opened\n");
#endif
	char name[20], phone[20], city[20], year[20];  
	while(!feof(f))
	{
		if(!m_is_available()) 
		{
			printf("[Load] There is no space!\n");
			break;
		}
		int n = fscanf(f,"%s %s %s %s", name, phone, year, city);
		if (n<4) break;
		if(m_search_by_name(name))
		{
#ifdef DEBUG			
			printf("[DEBUG] Duplicated name(%s)! loading.\n", name);
			continue;
#endif
		}
		m_create(name, phone, year, city);
#ifdef DEBUG
		printf("[DEBUG] load %s\n", name);
#endif
	}
	printf("%d records are read from file!\n", m_count());    
	fclose(f);
}
void save_file()
{
	// save data file
	FILE* f = fopen("lib_members.txt", "w");
#ifdef DEBUG
		printf("file is opened\n");
#endif
	int size = m_count();
	T_record* records[MAX_MEMBERS];
	m_get_all(records);
	for(int i=0; i<size; i++)
	{
		T_record* p = records[i];
		fprintf(f,"%s\n", m_to_string_save(p));
	}
#ifdef DEBUG
	printf("[DEBUG] All records are written in file\n");
#endif
	fclose(f);
}

void debug_records()
{
	// for debug  
	T_record* records[MAX_MEMBERS]={0};
	m_get_all2(records);
	for(int i=0; i<MAX_MEMBERS; i++)
	{
		printf("%d - %p\n",i, records[i]);
	}
}






#include "lib_members.h"

T_record * lib_members[MAX_MEMBERS];
int count = 0;

int m_is_available()
{
	for (int i = 0 ; i < MAX_MEMBERS; i++)
	{
		if (lib_members[i] == 0x0)
			return 1;
	}

	return 0;
}

int m_first_available()
{
	 for(int i = 0; i < MAX_MEMBERS ; i++)
	 {
		 if(lib_members[i] == 0x0)
			 return i;			   
	 }
			  
	 return -1;
}


int m_count()
{
	return count;
}

void sort(int size)
{
	char tmp[20];

	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1-i; j++)
		{
			if (strcmp(lib_members[j]->name, lib_members[j+1]->name) > 0)
			{
				strcpy(tmp, lib_members[j]->name);
				strcpy(lib_members[j]->name, lib_members[j+1]->name);
				strcpy(lib_members[j+1]->name, tmp);
			}
		
		}
	
	}

	for(int i=0; i<size; i++)
	{
		printf("[%d] %s\n",i+1,lib_members[i]->name);		
	
	}



}

void m_create(char *n, char *p, char *b, char *c)
{
	int index = m_first_available();
	lib_members[index] = (T_record * )malloc(sizeof(T_record));
	T_record *ptr = lib_members[index];

	strcpy(ptr->name, n);
	strcpy(ptr->phone, p);
	strcpy(ptr->birthyear, b);
	strcpy(ptr->city, c);
	
	number_create(ptr);

	e_create(ptr);

	count += 1;

}

void e_create(T_record * p)
{

	time_t timer;
	struct tm *t;

	timer = time(NULL);

	t = localtime(&timer);

	int month = t->tm_mon +1;
	int day = t->tm_mday;
	char s1 [20];
	char s2 [20];

	sprintf(s1, "%d", month);
	sprintf(s2, "%d", day);

	strcat(s1, " ");
	strcat(s1, s2);

	strcpy(p->enrollment_date , s1);
	strcpy(p->recent_visit, s1);

}

void r_create(char * name, char * r_visit)
{
	T_record * p = m_search_by_name(name);

	strcpy(p->recent_visit, r_visit);

	printf("recent visit is updated!\n");
}

char* m_to_string(T_record* p)
{
	static char str[80];
	sprintf(str, "[%s] %s / %s / %s", p->birthyear, p->name, p->phone, p->city);
	return str;
}

T_record * m_search_by_name(char *n)
{
	for (int i = 0; i < count ; i++)
	{
		if(lib_members[i] != 0x0 && strcmp(lib_members[i]->name, n) == 0)
			return lib_members[i];
	}
	
	return 0x0;
}

void number_create(T_record * p)
{
	char *str  = malloc(sizeof(char) * 20);

	strcpy(str , p->birthyear);
	strcat(str, p->phone);
	
	strcpy(p->number, str);

	free(str);
#ifdef DEBUG
	printf("\n*Library number is made*\n");
#endif
}

void m_update(T_record* p, char* ph, char* b, char* c)
{
	strcpy(p->phone, ph);
	strcpy(p->birthyear, b);
	strcpy(p->city, c);
}

void m_delete(T_record* p)
{
	int i, index;
	for(i=0; i<MAX_MEMBERS; i++)
		if(lib_members[i]==p)
		{
			index=i;
			break;
		}
	free(p);
	lib_members[index] = NULL;
	count--;
}


void m_get_all(T_record * a[])
{
	int i;
	for (i = 0; i < MAX_MEMBERS; i++)
	{
		a[i] = lib_members[i];
	}
}

void m_get_all2(T_record* a[])
{
	int i;
	for(i=0; i<MAX_MEMBERS; i++)
	{
		a[i]=lib_members[i];
	}
}


char* m_getname(T_record* p)
{
	return p->name;
}

char* m_getphone(T_record* p)
{
	return p->phone;
}

char* m_getbirthyear(T_record* p)
{
	return p->birthyear;
}

char* m_getcity(T_record* p)
{
	return p->city;
}

char* m_getnumber(T_record* p)
{
	return p->number;
}

int m_get_all_by_name(T_record* a[], char* n)
{
	// 회원이름에 문자열이 포함된 모든 레코드 포인터의 배열 만들기    
	int i, c=0;
	for(i=0; i<MAX_MEMBERS; i++)
	{
		if(lib_members[i]!=NULL && strstr(lib_members[i]->name, n))
		{
			a[c]=lib_members[i];
			c++;
		}
	}
	return c;
} 

int m_get_all_by_number(T_record* a[], char* n){
	// 회원거주도시가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
	int i, c=0;
	for(i=0; i<MAX_MEMBERS; i++){
		if(lib_members[i]!=NULL && (strcmp(lib_members[i]->number, n)==0)){
			a[c]=lib_members[i];
			c++;
		}
	}
	return c;
}
void m_init()
{
	// 모든 레코드 제거    
	int i;
	for(i=0; i<MAX_MEMBERS; i++)
	{
		if(lib_members[i]!=NULL)
		{
			free(lib_members[i]);
		}
		lib_members[i] = NULL;
	}
	count = 0;

}

char* m_to_string_save(T_record* p)
{
	static char str[80];
	sprintf(str, "%s %s %s %s", p->name, p->phone, p->birthyear, p->city);
	return str;
}

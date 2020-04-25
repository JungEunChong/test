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
		printf("[%d] %s/ %s/ %s/ %s/ %s\n",i+1,lib_members[i]->name, lib_members[i]->phone, lib_members[i]->birthyear, lib_members[i]->city, lib_members[i]->enrollment_date);		
	
	}
}

void m_create(char *n, char *p, char *b, char *c, char *e)
{
	int index = m_first_available();
	lib_members[index] = (T_record * )malloc(sizeof(T_record));
	T_record *ptr = lib_members[index];

	strcpy(ptr->name, n);
	strcpy(ptr->phone, p);
	strcpy(ptr->birthyear, b);
	strcpy(ptr->city, c);
	strcpy(ptr->enrollment_date, e);
	strcpy(ptr->recent_visit, e);	

	count += 1;
}

void r_create(char * name, char * r_visit)
{
	T_record * p = m_search_by_name(name);

	strcpy(p->recent_visit, r_visit);

	printf("%s's recent visit is updated!\n",p->name);
}

char* m_to_string(T_record* p)
{
	static char str[80];
	sprintf(str, "[%s] Birth year: %s / Phone number: %s / City: %s/ Enrollment date: %s",p->name, p->birthyear, p->phone, p->city, p->enrollment_date);
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

char* m_getenrollment_date(T_record* p)
{
	return p->enrollment_date;
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
	// 회원의 핸드폰 번호가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
	int i, c=0;
	for(i=0; i<MAX_MEMBERS; i++)
	{
		if(lib_members[i]!=NULL && (strcmp(lib_members[i]->phone, n)==0))
		{
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
